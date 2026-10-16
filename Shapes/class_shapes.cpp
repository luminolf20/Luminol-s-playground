#include "class_shapes.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <cmath>


const double PI = 3.141592653589793;  // Создаём константу числа Пи

/* Далее реализация будем идти парами:
конструктор(-ы)-деструктор, копирование и оператор,
перемещение и опереатор. Функции разделены.*/

/*------------
Базовый класс
------------*/
Shape::Shape(std::string name) : name_(name) {}
Shape::~Shape() {}

Shape::Shape(const Shape &other) : name_(other.name_) {}
Shape &Shape::operator=(const Shape &other)  // Оператору не нужен список инициализации
{
    if (this != &other)  // Проверка на самоприсваинвание
    {
        Shape shape(other);  // Создаём временную копию "правого" объекта other
        std::swap(name_, shape.name_);  // меняем местами данные в объектах
    }  // shape будет удалён автоматически
    return *this;  // Возвращаем ссылку на текущий "левый" объект
}

Shape::Shape(Shape &&other) noexcept : name_(std::move(other.name_)) {}
Shape &Shape::operator=(Shape &&other) noexcept
{
    std::swap(name_, other.name_);  // Меняем местами данные other и this
    return *this;  // Возвращаем ссылку на текущий элемент this
                   // Теперь other уничтожен вместе с ненужными данными
}

const std::string &Shape::getName() const
{
    return name_;  // Возвращаем имя фигуры через ссылку на него
}

double Shape::area() const
{
    return 0.0;  // Заглушка
}

double Shape::perimeter() const
{
    return 0.0;  // Заглушка
}

/*------------
Подкласс Прямоугольник
------------*/
Rectangle::Rectangle(double width, double length) : Shape("Rectangle"), width_(width), length_(length)
{
    if (width <= 0.0 || length <= 0.0)  // Проверка на возможность создания фигуры
    {
        throw std::invalid_argument("Sides should be greater than 0.0");
    }
}
Rectangle::Rectangle(std::string name, double width, double length) : Shape(name), width_(width), length_(length)
{
    if (width <= 0.0 || length <= 0.0)  // Проверка на возможность создания фигуры
    {
        throw std::invalid_argument("Sides should be greater than 0.0");
    }
}
Rectangle::~Rectangle() {}

Rectangle::Rectangle(const Rectangle &other) : Shape(other), width_(other.width_), length_(other.length_) {}
Rectangle &Rectangle::operator=(const Rectangle &other)
{
    if (this != &other)
    {
        Shape::operator=(other);

        Rectangle rectangle(other);
        std::swap(width_, rectangle.width_);
        std::swap(length_, rectangle.length_);
    }
    return *this;
}

Rectangle::Rectangle(Rectangle &&other) noexcept : Shape(std::move(other)), width_(other.width_), length_(other.length_) {}
Rectangle &Rectangle::operator=(Rectangle &&other) noexcept
{
    if (this != &other)
    /* В опраторах перемещения необходимо проводить проверку на само присваивание,
    т.к. может произойти утечка данных.
    Если мы получим на обе стороны оператора перемещения один и тот же объект,
    то нам не важно, какие числа указаны в размерах фигуры, т.к. числовые типы
    данных храняться раздельно, т.е. объекты 'a' и 'b' со значениями
    [name = "name", num = 0.5] и [name = "name", num = 0.5] имеют разные указатели
    name с одинокавым значением "name", хранящемся в одной ячейке памяти,а указатели
    num - это разные разные с одинаковыми значениями 0.5 в разных ячейках памяти.
    Так вот, при использовании оператора перемещения мы хоть и меняем местами
    указатели на объект в памяти, но указатели показывают на один и тот же объект,
    из-за чего при удалении объекта other мы удалим и имя фигуры внутри объекта this. */
    {
        Shape::operator=(std::move(other));

        std::swap(width_, other.width_);
        std::swap(length_, other.length_);
    }
    return *this;
}

double Rectangle::area() const
{
    return width_ * length_;
}

double Rectangle::perimeter() const
{
    return 2.0 * (width_ + length_);
}

/*------------
Подкласс Круг
------------*/
Circle::Circle(double radius) : Shape("Circle"), radius_(radius)
{
    if (radius <= 0.0)  // Проверка на возможность создания фигуры
    {
        throw std::invalid_argument("Radius should be greater than 0.0");
    }
}
Circle::~Circle() {}

Circle::Circle(const Circle &other) : Shape(other), radius_(other.radius_) {}
Circle &Circle::operator=(const Circle &other)
{
    if (this != &other)
    {
        Shape::operator=(other);

        Circle circle(other);
        std::swap(radius_, circle.radius_);
    }
    return *this;
}

Circle::Circle(Circle &&other) noexcept : Shape(std::move(other)), radius_(other.radius_) {}
Circle &Circle::operator=(Circle &&other) noexcept
{
    if (this != &other)
    {
        Shape::operator=(std::move(other));

        std::swap(radius_, other.radius_);
    }
    return *this;
}

double Circle::area() const
{
    return PI * radius_ * radius_;
}

double Circle::perimeter() const
{
    return PI * radius_ * 2.0;
}

/*------------
Подкласс Треуголник
------------*/
Triangle::Triangle(double first, double second, double third) : Shape("Triangle"), first_(first), second_(second), third_(third)
{
    if (first <= 0.0 || second <= 0.0 || third <= 0.0)  // Проверка на возможность создания фигуры
    {
        throw std::invalid_argument("Sides should be greater than 0.0");
    }
    else if (first + second < third + 1e-6 || second + third < first + 1e-6 || third + first < second + 1e-6)  // Проверка на выполнение наревантсва для треугольника
    {
        throw std::invalid_argument("Sum of any two sides should be greater than the third");
    }
}
Triangle::~Triangle() {}

Triangle::Triangle(const Triangle &other) : Shape(other), first_(other.first_), second_(other.second_), third_(other.third_) {}
Triangle &Triangle::operator=(const Triangle &other)
{
    if (this != &other)
    {
        Shape::operator=(other);

        Triangle triangle(other);
        std::swap(first_, triangle.first_);
        std::swap(second_, triangle.second_);
        std::swap(third_, triangle.third_);
    }
    return *this;
}

Triangle::Triangle(Triangle &&other) noexcept : Shape(std::move(other)), first_(other.first_), second_(other.second_), third_(other.third_) {}
Triangle &Triangle::operator=(Triangle &&other) noexcept
{
    if (this != &other)
    {
        Shape::operator=(std::move(other));

        std::swap(first_, other.first_);
        std::swap(second_, other.second_);
        std::swap(third_, other.third_);
    }
    return *this;
}

double Triangle::perimeter() const
{
    return first_ + second_ + third_;
}

double Triangle::area() const
{
    double p = Triangle::perimeter() / 2.0;
    return std::sqrt(p * (p - first_) * (p - second_) * (p - third_));
}

/*------------
Подкласс Квадрат
(наследник Прямоугольника)
------------*/
Square::Square(double side) : Rectangle("Square", side, side) {}
Square::~Square() {}

Square::Square(const Square &other) : Rectangle(other) {}
Square &Square::operator=(const Square &other)
{
    if (this != &other)
    {
        Rectangle::operator=(other);
    }
    return *this;
}

Square::Square(Square &&other) noexcept : Rectangle(std::move(other)) {}
Square &Square::operator=(Square &&other) noexcept
{
    if (this != &other)
    {
        Rectangle::operator=(std::move(other));
    }
    return *this;
}

// double Square::area() const
// {
//     return Rectangle::area();
// }

// double Square::perimeter() const
// {
//     return Rectangle::perimeter();
// }
    /* Функци можно не прописывать, т.к. при обращении к ним
    С++ сам увидит, что их здесь нет, у использует их из родителя,
    т.е. из Rectangle*/

/*------------
Операторы класса
------------*/
bool operator==(const Shape& lhs, const Shape& rhs)
{
    return std::abs(lhs.area() - rhs.area()) < 1e-6;
}

bool operator^(const Shape& lhs, const Shape& rhs)
{
    return std::abs(lhs.perimeter() - rhs.perimeter()) < 1e-6;
}

std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
    os << "Shape:" << shape.getName() << "\n";
    os << "Shapes's square:" << shape.area() << "\n";
    os << "Shape's perimeter:" << shape.perimeter() << "\n";

    return os;
}