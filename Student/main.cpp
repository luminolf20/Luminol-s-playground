#include <iostream>
#include <vector>
#include <algorithm>
#include "class_student.h"

int main() {
    std::vector<Student> students;

    Student s1("Иван Петров", "ИУ7-31Б");
    s1.addMark(5);
    s1.addMark(4);
    s1.addMark(5);  // Ср. балл 4.67

    Student s2("Анна Сидорова", "ИУ7-31Б", std::vector<int> {3, 4});  // Ср. балл 3.5

    Student s3("Елена Козлова", "ИУ7-33Б");
    s3.addMark(5);
    s3.addMark(5);  // Ср. балл 5.0

    students.push_back(std::move(s1));
    students.push_back(std::move(s2));
    students.push_back(std::move(s3));

    std::cout << "Список до сортировки:" << std::endl;
    for (const auto& student : students) {
        std::cout << student << "\n";
    }

    std::sort(students.begin(), students.end(), [](const Student& lhs, const Student& rhs) {  return !(lhs < rhs);  });

    std::cout << "Список после сортировки (по убыванию ср. балла):" << std::endl;
    for (const Student& student : students) {
        std::cout << student << "\n";
    }

    return 0;
}
