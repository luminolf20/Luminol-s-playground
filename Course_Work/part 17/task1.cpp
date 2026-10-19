#include <iostream>
#include <vector>

void print_array10(std::ostream &os, int *a) // Функция для вывода массива
{
    for (int i = 0; i < 10; ++i) // Цикл вывода 10 элементов
    {
        os << a[i] << " ";
    }
    os << std::endl; // Очищение буфера и перенос строки
}

void print_array(std::ostream &os, int *a, int n)
{
    for (int i = 0; i < n; ++i) // Цикл вывода n элементов
    {
        os << a[i] << " ";
    }
    os << std::endl;
}

void print_vector(std::ostream &os, const std::vector<int> &v)
{
    for (int x : v) // Эквивалент 'for x in v' из Python
    {
        os << x << " ";
    }
    os << std::endl;
}

int main()
{
    int length = 10;                      // Длина массива
    int *array_10_0 = new int[length];    // Выделяем память для будущего массива в количестве 'length' значений
    print_array10(std::cout, array_10_0); // Вызов функции для вывода массива
    delete[] array_10_0;                  // Полное удаление массива

    int *array_10_100 = new int[length];
    for (int i = 0; i < length; ++i) // Цикл для внесения данных в массив
    {
        array_10_100[i] = 100 + i;
    }
    print_array10(std::cout, array_10_100);
    delete[] array_10_100;

    int *array_11_100 = new int[length + 1];
    for (int i = 0; i < length + 1; ++i)
    {
        array_11_100[i] = 100 + i;
    }
    print_array(std::cout, array_11_100, length + 1);
    delete[] array_11_100;

    int *array_20_100 = new int[2 * length];
    for (int i = 0; i < 2 * length; ++i)
    {
        array_20_100[i] = 100 + i;
    }
    print_array(std::cout, array_20_100, 2 * length);
    delete[] array_20_100;

    std::vector<int> vector_10_100(length);
    for (int i = 0; i < length; ++i)
    {
        vector_10_100[i] = 100 + i;
    }
    print_vector(std::cout, vector_10_100);

    std::vector<int> vector_11_100(length + 1);
    for (int i = 0; i < length + 1; ++i)
    {
        vector_11_100[i] = 100 + i;
    }
    print_vector(std::cout, vector_11_100);

    std::vector<int> vector_20_100(2 * length);
    for (int i = 0; i < 2 * length; ++i)
    {
        vector_20_100[i] = 100 + i;
    }
    print_vector(std::cout, vector_20_100);

    return 0;
}