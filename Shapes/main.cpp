// Код для проверки был (main.cpp) написан ИИ, остальное писал сам.


#include <iostream>
#include <vector>
#include <stdexcept>
#include "class_shapes.h"

int main() {
    // Настраиваем вывод консоли для красивого отображения true/false
    std::cout << std::boolalpha;

    std::cout << "===========================================" << std::endl;
    std::cout << "1. ДЕМОНСТРАЦИЯ ОПЕРАТОРА ВЫВОДА И ПОЛИМОРФИЗМА" << std::endl;
    std::cout << "===========================================" << std::endl;

    // Создаем вектор указателей на базовый класс для проверки полиморфизма
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle(4.0, 5.0)); // Площадь = 20, Периметр = 18
    shapes.push_back(new Circle(3.0));         // Площадь ≈ 28.27, Периметр ≈ 18.85
    shapes.push_back(new Triangle(3.0, 4.0, 5.0)); // Площадь = 6, Периметр = 12
    shapes.push_back(new Square(4.472136));    // Сторона ≈ sqrt(20). Площадь ≈ 20, Периметр ≈ 17.89

    // Проверяем работу полиморфизма и нашего нового operator<<
    for (const auto* shape : shapes) {
        std::cout << *shape << "-------------------------------------------" << std::endl;
    }

    std::cout << "\n===========================================" << std::endl;
    std::cout << "2. ПРОВЕРКА ОПЕРАТОРОВ СРАВНЕНИЯ (== и ^)" << std::endl;
    std::cout << "===========================================" << std::endl;

    // Сравниваем Rectangle (shapes[0]) и Square (shapes[3]) — у них площади равны 20
    std::cout << "Площадь " << shapes[0]->getName() << " == Площадь " << shapes[3]->getName() << "? " 
              << (*shapes[0] == *shapes[3]) << " (Ожидается: true с учетом погрешности 1e-6)" << std::endl;

    // Сравниваем площади Круга и Треугольника
    std::cout << "Площадь " << shapes[1]->getName() << " == Площадь " << shapes[2]->getName() << "? " 
              << (*shapes[1] == *shapes[2]) << " (Ожидается: false)" << std::endl;

    // Сравниваем периметры Круга и Прямоугольника через оператор ^
    std::cout << "Периметр " << shapes[0]->getName() << " ^ Периметр " << shapes[1]->getName() << "? " 
              << (*shapes[0] ^ *shapes[1]) << " (Ожидается: false)" << std::endl;


    std::cout << "\n===========================================" << std::endl;
    std::cout << "3. ПРОВЕРКА ВАЛИДАЦИИ И ИСКЛЮЧЕНИЙ (try-catch)" << std::endl;
    std::cout << "===========================================" << std::endl;

    // Пробуем создать невозможный треугольник
    try {
        std::cout << "Пытаемся создать Triangle(1.0, 2.0, 10.0)..." << std::endl;
        Triangle badTriangle(1.0, 2.0, 10.0);
    } catch (const std::invalid_argument& e) {
        std::cout << "Успешно перехвачено исключение: " << e.what() << std::endl;
    }

    // Пробуем создать квадрат с некорректной стороной
    try {
        std::cout << "Пытаемся создать Square(-5.0)..." << std::endl;
        Square badSquare(-5.0);
    } catch (const std::invalid_argument& e) {
        std::cout << "Успешно перехвачено исключение для Квадрата: " << e.what() << std::endl;
    }


    std::cout << "\n===========================================" << std::endl;
    std::cout << "4. ТЕСТИРОВАНИЕ КОРРЕКТНОСТИ ПРАВИЛА ПЯТИ" << std::endl;
    std::cout << "===========================================" << std::endl;

    // Проверка конструктора копирования
    Square originalSquare(5.0);
    Square copySquare = originalSquare;
    std::cout << "Оригинал: " << originalSquare.getName() << " (Площадь: " << originalSquare.area() << ")" << std::endl;
    std::cout << "Копия: " << copySquare.getName() << " (Площадь: " << copySquare.area() << ")" << std::endl;

    // Проверка оператора перемещения (move assignment)
    Circle circleForMoving(10.0);
    Circle targetCircle(1.0);
    
    std::cout << "Target до перемещения: " << targetCircle.getName() << " (Площадь: " << targetCircle.area() << ")" << std::endl;
    targetCircle = std::move(circleForMoving);
    std::cout << "Target после перемещения: " << targetCircle.getName() << " (Площадь: " << targetCircle.area() << ")" << std::endl;


    std::cout << "\n===========================================" << std::endl;
    std::cout << "5. ОСВОБОЖДЕНИЕ ДИНАМИЧЕСКОЙ ПАМЯТИ" << std::endl;
    std::cout << "===========================================" << std::endl;

    for (auto* shape : shapes) {
        delete shape; // Виртуальные деструкторы гарантируют полную очистку!
    }
    shapes.clear();

    std::cout << "Вся память успешно очищена. Программа завершена!" << std::endl;
    return 0;
}