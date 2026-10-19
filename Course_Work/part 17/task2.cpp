#include <iostream>
#include <cmath>
#include <vector>

void print_array(std::ostream &os, int *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        os << a[i] << " ";
    }
    os << std::endl;
}

void print_vector(std::ostream &os, const std::vector<int> &v)
{
    for (int x : v)
    {
        os << x << " ";
    }
    os << std::endl;
}


int main()
{
    int value_1 = 7;
    int *p1 = &value_1;
    std::cout << "p1 (adress): " << p1 << ", poinnts to value: " << *p1 << std::endl;

    int *p2 = new int[7];
    for (int i = 0; i < 7; ++i)
    {
        p2[i] = pow(2.0, static_cast<double>(i));
    }
    std::cout << "p2 (address): " << p2 << std::endl;
    std::cout << "p2 array elements: ";
    print_array(std::cout, p2, 7);

    int* p3 = p2;
    p1 = p2;
    p2 = p3;
    std::cout << "p1: " << p1 << "(points to " << *p1 << ")" << std::endl;
    std::cout << "p2: " << p2 << "(points to " << *p2 << ")" << std::endl;
    delete[] p1;

    p1 = new int[10];
    for (int i = 0; i < 10; ++i)
    {
        p1[i] = pow(2.0, static_cast<double>(i));
    }

    p2 = new int[10];
    for (int i = 0; i < 10; ++i)
    {
        p2[i] = p1[i];
    }
    std::cout << "p2 array after manual copy: ";
    print_array(std::cout, p2, 10);
    delete[] p1;
    delete[] p2;

    std::vector<int> vector_1(10);
    for (int i = 0; i < 10; ++i)
    {
        vector_1[i] = pow(2.0, static_cast<double>(i));
    }

    std::vector<int> vector_2(10);
    vector_2 = vector_1;
    print_vector(std::cout, vector_2);

    return 0;
}