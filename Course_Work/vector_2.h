#include <algorithm>
#include <initializer_list>

class vector // Создание класса с  названием 'vector'
{
    // Задаём переменные для вектора
    int sz;       // Размер вектора (количество элементов в нём)
    double *elem; // Указатель на первый элемент массива типа 'double' (элементы в памяти храняться последовательно)

public:
    vector(int s);                     // Конструктор создания
    ~vector();                         // Деструктор
    vector(const vector &);            // Конструктор копирования
    vector(vector &&a);                // Конструктор перемещения
    vector &operator=(const vector &); // Оператор присваивания копированием
    vector &operator=(vector &&);      // Оператор присваивания перемещением

    double &operator[](int n) { return elem[n]; }             // Оператор для неконстантных векторов
    const double &operator[](int n) const { return elem[n]; } // Оператор для константных векторов

    int size() const; // Функция, позволяющая узнать размер (количество элементов) вектора
};