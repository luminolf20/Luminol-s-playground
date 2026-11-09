#include <iostream>
#include <memory>
#include <algorithm>
#include <stdexcept>

template<typename T, typename Allocator = std::allocator<T>>
class Vector {
private:
    Allocator alloc; // распределитель памяти (Глава 19)
    int sz;          // размер (количество элементов)
    T* elem;         // указатель на первый элемент (Глава 17)
    int space;       // общий объем памяти (размер + свободные слоты) (Глава 18)

public:
    // 1. Базовый конструктор (Глава 17)
    Vector() : sz{0}, elem{nullptr}, space{0} {}

    // Конструктор с заданным размером (Глава 17)
    explicit Vector(int s) : sz{s}, space{s} {
        elem = alloc.allocate(s); // выделяем сырую память
        for (int i = 0; i < s; ++i) alloc.construct(&elem[i], T()); // инициализируем элементы
    }

    // 2. Конструктор копирования (Глава 18)
    Vector(const Vector& arg) : sz{arg.sz}, space{arg.sz} {
        elem = alloc.allocate(arg.sz);
        for (int i = 0; i < arg.sz; ++i) alloc.construct(&elem[i], arg.elem[i]);
    }

    // Операция копирующего присваивания (Глава 18)
    Vector& operator=(const Vector& a) {
        if (this == &a) return *this; // защита от самоприсваивания

        if (a.sz <= space) { // если места достаточно, переиспользуем его
            for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]);
            for (int i = 0; i < a.sz; ++i) alloc.construct(&elem[i], a.elem[i]);
            sz = a.sz;
            return *this;
        }

        T* p = alloc.allocate(a.sz); // иначе выделяем новую память
        for (int i = 0; i < a.sz; ++i) alloc.construct(&p[i], a.elem[i]);
        
        for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]); // чистим старую
        alloc.deallocate(elem, space);
        
        elem = p;
        sz = a.sz;
        space = a.sz;
        return *this;
    }

    // 3. Конструктор перемещения (Move constructor) (Глава 18)
    Vector(Vector&& a) noexcept : sz{a.sz}, elem{a.elem}, space{a.space} {
        a.sz = 0;
        a.space = 0;
        a.elem = nullptr; // забираем ресурсы, оставляя `a` пустой
    }

    // Операция перемещающего присваивания (Move assignment) (Глава 18)
    Vector& operator=(Vector&& a) noexcept {
        for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]); // очищаем свои ресурсы
        alloc.deallocate(elem, space);

        elem = a.elem; // забираем ресурсы у `a`
        sz = a.sz;
        space = a.space;

        a.sz = 0;
        a.space = 0;
        a.elem = nullptr;
        return *this;
    }

    // 4. Деструктор (Глава 17/18)
    ~Vector() {
        for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]); // уничтожаем объекты
        alloc.deallocate(elem, space);                       // освобождаем память
    }

    // 5. Доступ к элементам (Глава 17/19)
    T& operator[](int n) { return elem[n]; }
    const T& operator[](int n) const { return elem[n]; }

    // Доступ с проверкой границ (Глава 19)
    T& at(int n) {
        if (n < 0 || n >= sz) throw std::out_of_range("Vector::at: out of range");
        return elem[n];
    }
    const T& at(int n) const {
        if (n < 0 || n >= sz) throw std::out_of_range("Vector::at: out of range");
        return elem[n];
    }

    int size() const { return sz; }
    int capacity() const { return space; }

    // 6. Изменение размера и добавление элементов (Глава 19)
    void reserve(int newalloc) {
        if (newalloc <= space) return; // никогда не уменьшаем память

        T* p = alloc.allocate(newalloc); // выделяем новую память
        for (int i = 0; i < sz; ++i) {
            alloc.construct(&p[i], std::move(elem[i])); // перемещаем старые элементы
            alloc.destroy(&elem[i]);
        }
        alloc.deallocate(elem, space); // освобождаем старую память
        elem = p;
        space = newalloc;
    }

    void resize(int newsize, T val = T()) {
        reserve(newsize);
        if (newsize > sz) {
            for (int i = sz; i < newsize; ++i) alloc.construct(&elem[i], val); // конструируем новые
        } else {
            for (int i = newsize; i < sz; ++i) alloc.destroy(&elem[i]); // уничтожаем лишние
        }
        sz = newsize;
    }

    void push_back(const T& val) {
        if (space == 0) reserve(8); // начальный размер
        else if (sz == space) reserve(2 * space); // удваиваем память при нехватке
        alloc.construct(&elem[sz], val);
        ++sz;
    }
};