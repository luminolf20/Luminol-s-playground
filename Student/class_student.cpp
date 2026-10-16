#include "class_student.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>


Student::Student() : name_("Empty"), group_("Unsigned"), marks_{} {}

// Student::Student(std::string name) : name_(name), group_("Unsigned"), marks_{} {}

Student::Student(std::string name, std::string group)
    : name_(name), group_(group), marks_{} {}

Student::Student(std::string name, std::string group, std::vector<int> marks)
    : name_(name), group_(group), marks_(marks)
{
    if (!marks_.empty())  // Функция .empty() возращает булево значение пустоты вектора
    {
        int marks_sum = 0;

        for (int mark : marks_)  // эквивалет 'for mark in marks_' из Python
        {  marks_sum += mark;  }

        averageScore_ = static_cast<double>(marks_sum) / marks_.size();
    }  // Конструкция static_cast позволяет менять тип переменной на месте. Здесь эквивалент float()
}

Student::~Student() {}

Student::Student(const Student &other)
    : name_(other.name_), group_(other.group_), 
    marks_(other.marks_), averageScore_(other.averageScore_) {}

Student::Student(Student &&other) noexcept
    : name_(std::move(other.name_)), group_(std::move(other.group_)),
    marks_(std::move(other.marks_)), averageScore_(other.averageScore_) {}

Student &Student::operator=(const Student &other)
{
    if(this != &other)
    {
        Student blank(other);
        std::swap(name_, blank.name_);
        std::swap(group_, blank.group_);
        std::swap(marks_, blank.marks_);
        std::swap(averageScore_, blank.averageScore_);
    }

    return *this;
}

Student &Student::operator=(Student &&other) noexcept
{
    std::swap(name_, other.name_);
    std::swap(group_, other.group_);
    std::swap(marks_, other.marks_);
    std::swap(averageScore_, other.averageScore_);

    return *this;
}

void Student::addMark(int mark)
{
    int min_mark = 1;
    int max_mark = 10;
    int marks_sum = 0;

    if (mark < min_mark || max_mark < mark)
    {  throw std::invalid_argument("Entered mark is out of range");  }

    marks_.push_back(mark);  // Функция push_back() добавляет элемент в конец вектора, увелиичивая длину вектора на 1

    for (int exitsing_mark : marks_)
    {  marks_sum += exitsing_mark;  }

    averageScore_ = static_cast<double>(marks_sum) / marks_.size();
}

const std::vector<int> &Student::getMarks() const
{  return marks_;  }

const double Student::getAverageScore() const
{  return averageScore_;  }

std::ostream &operator<<(std::ostream &os, const Student &student)
{
    os << "Student's name: " << student.name_ << std::endl;

    os << "Student's group: " << student.group_ << std::endl;

    os << "Student's marks: ";
    for (int mark : student.marks_)
    {  os << mark << ", ";  }
    os << std::endl;

    os << "Student's average score: " << student.averageScore_ << std::endl;

    return os;
}

bool operator<(const Student &lhs, const Student &rhs)
{  return lhs.getAverageScore() < rhs.getAverageScore();  }
