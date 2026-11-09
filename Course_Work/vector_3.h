#include <algorithm>
#include <memory>


template <typename T, typename A = std::allocator<T>>
class vector // Создание класса с  названием 'vector'
{
    // Задаём переменные для вектора
    A alloc;
    int sz;    // Размер вектора (количество элементов в нём)
    T *elem;   // Указатель на первый элемент массива указанным пользователем типа (элементы в памяти храняться последовательно)
    int space; // Количество элементов + свободное место для новых элементов (выделенный размер)

public:
    vector(); // Конструкторы создания
    explicit vector(int s);
    ~vector();                         // Деструктор
    vector(const vector &);            // Конструктор копирования
    vector(vector &&a);                // Конструктор перемещения
    vector &operator=(const vector &); // Оператор присваивания копированием
    vector &operator=(vector &&);      // Оператор присваивания перемещением

    T &operator[](int n) { return elem[n]; }             // Оператор для неконстантных векторов
    const T &operator[](int n) const { return elem[n]; } // Оператор для константных векторов

    int size() const;     // Функция, позволяющая узнать размер (количество элементов) вектора
    int capacity() const; // Функция, возвращающая резерв памяти вектора

    void reserve(int newalloc); // Функция, создающая(резервирующая) память для новых элементов
    void resize(int newsize);   // Функция, меняющая размер вектора
    void push_back(const T& d); // Функция, запихивающая данные в вектор
};