#pragma once
#include <iostream>
#include <string>
#include <algorithm> // для std::all_of
#include <cctype>    // для std::isdigit

bool is_digit(std::string input) {
    
    if (input.empty()) return false; // 1

    size_t start_index = (input[0] == '-' || input[0] == '+') ? 1 : 0; // 2

    if (start_index == 1 && input.length() == 1) return false; // 3

    return std::all_of(input.begin() + start_index, input.end(), [](unsigned char c) {
        return std::isdigit(c);
    }); // 4
}

// КОММЕНТАРИИ

// 1
/* Если строка пустая — это точно не число */

// 2
/*  Определяем, откуда начинать проверку цифр.
    Если первый символ '-' или '+', то цифры должны идти со 2-го символа (индекс 1).
    Если знака нет, то проверяем с самого начала (индекс 0).  */

// 3
/*  Защита от одиночного знака: если строка состоит ТОЛЬКО из одного минуса или плюса  */

// 4
/*  Посимвольная проверка оставшейся части строки.
    std::all_of проверяет, что ВСЕ символы от start_index до конца являются цифрами  */