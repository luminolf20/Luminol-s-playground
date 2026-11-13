#pragma once
#include "vector_3.h"

/* Констукторы создания */
template <typename T, typename A>
vector<T, A>::vector() : sz{0}, elem{nullptr}, space{0} {} // Конструктор создания полностью пустого вектора

template <typename T, typename A>
vector<T, A>::vector(int s) : sz{s}, elem{new T[s]}, space{s} // Констуктор создания с размером| создаёт 'пустой' вектор с размером вектора, равному введённому пользователем занчению 's', предварительно резервируя 's' ячеек памяти
{                                                             // Цикл для заполнения элемментов вектора 'пустыми значениями', нулями
    for (int i = 0; i < s; ++i)
    {
        alloc.construct(&elem[i], T());
    }
}

/* Деструктор (конструктор разрушения) */
template <typename T, typename A>
vector<T, A>::~vector()
{
    for (int i = 0; i < sz; ++i)
    {
        alloc.destroy(&elem[i]);
    }
    alloc.deallocate(elem, space);
} // Особождает динмическую память (кучу/heap) от вектора

/* Констуктор копирования */
template <typename T, typename A>
vector<T, A>::vector(const vector &a) : sz{a.sz}, elem{new double[a.sz]} // Выделение нового блока памяти под копию
{
    elem = alloc.allocate(a.sz);
    for (int i = 0; i < a.sz; ++i)
    {
        alloc.construct(&elem[i], a.elem[i])
    } // Поэлементное копирование значений в новый вектор
}

/* Оператор присваивания копированием */
template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(const vector &a)
{
    if (this == &a)
    {
        return *this;
    } // Проверка на самоприсваивание

    if (a.sz <= space) // Памяти достаточно, новая не нужна
    {
        for (int i = 0; i < sz; ++i)
        {
            alloc.deallocate(&elem[i]);
        }
        for (int i = 0; i < a.sz; ++i)
        {
            alloc.construct(&elem[i]);
        }
        sz = a.sz;
        return *this;
    }

    double *p = new double[a.sz]; // Выделение новой памяти
    for (int i = 0; i < a.sz; i++)
    {
        p[i] = a.elem[i]; // Копирование значений
    }
    delete[] elem;     // Удаление старых значений
    space = sz = a.sz; // Утсановка нового размера вектора
    elem = p;          // Меняем указатель | Указывал на старые данные, будет на новые

    return *this;
};
// Получаем вектор с такими же значениями, но находящимися под другим указателем

/* Конструктор перемещения */
template <typename T, typename A>
vector<T, A>::vector(vector &&a) : sz{a.sz}, space{a.space}, elem{a.elem}
{
    a.sz = 0;
    a.space = 0;
    a.elem = nullptr;
} // Обнуление старого вектора

/* Оператор присваивания перемещением */
template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(vector &&a) noexcept
{
    for (int i = 0; i < sz; ++i)
    {
        alloc.deallocate(&elem[i]);
    }
    alloc.deallocate(elem, space);

    sz = a.sz;        // Делаем новому вектору такой же размер
    elem = a.elem;
    space = a.space;

    a.sz = 0;         // Обнуляем старый размер
    a.elem = nullptr; // Обнуляем старый указатель
    a.space = 0;
    return *this;
}
// Старый вектор опустошён, а новый имеет его данные

/* Функции */

template <typename T, typename A>
int vector<T, A>::size() const { return sz; } // Функция, позволяющая узнать размер (количество элементов) вектора

template <typename T, typename A>
void vector<T, A>::reserve(int newalloc) // Функция, создающая(резервирующая) память для новых элементов
{
    if (newalloc <= this->space) // проверка на неувеличение размера
    {
        return;
    }
    vector_base<T, A> b(this->alloc, newalloc);
    double *p = new double[newalloc]; // Выделение новой памяти
    for (int i = 0; i < sz; ++i)
    {
        p[i] = elem[i];
    } // Цикл копирования элементов
    delete[] elem; // Освобождение старой памяти
    elem = p;
    space = newalloc;
}

template <typename T, typename A>
int vector<T, A>::capacity() const { return space; } // Функция, возвращающая резерв памяти вектора

template <typename T, typename A>
void vector<T, A>::resize(int newsize)
{
    reserve(newsize);
    for (int i = sz; i < newsize; ++i)
    {
        elem[i] = 0;
    }
    sz = newsize;
}

template <typename T, typename A>
void vector<T, A>::push_back(const T &d)
{
    if (space == 0)
    {
        reserve(8);
    }
    else if (sz == space)
    {
        reserve(2 * space);
    }
    elem[sz] = d;
    ++sz;
}