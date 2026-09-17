// Написать программу, которая принимает целое число N на ввод и выводит название месяца с этим номером
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int month_number;
    std::cin >> month_number;
    std::vector<std::string> months {
        "december", "january", "february", "march", "april", "may", "june", "jule", "august", "september", "october", "november"
    };
    std::cout << months[month_number % 12] << std::endl;
}