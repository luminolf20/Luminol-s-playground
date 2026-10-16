#include <iostream>
#include <string>
#include <vector>


class Student
{
private:
    std::string name_;
    std::string group_;
    std::vector<int> marks_;
    double averageScore_ = 0.0;
protected:
public:
    void addMark(int mark);
    const std::vector<int>& getMarks() const;
    const double getAverageScore() const;

    Student();
    Student(std::string name);
    Student(std::string name, std::string group);
    Student(std::string name, std::string group, std::vector<int> marks);
    

    ~Student();
    Student(const Student& other);
    Student(Student&& other) noexcept;
    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    friend bool operator<(const Student& lhs, const Student& rhs);
};

std::ostream& operator<<(std::ostream& os, const Student& student);
bool operator<(const Student& lhs, const Student& rhs);