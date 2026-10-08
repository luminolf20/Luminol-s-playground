#include <iostream>
#include <string>


class Shape
{
private:
protected:
    std::string name_;
public:
    virtual const std::string& getName() const;
    virtual double area() const;
    virtual double perimeter() const;

    Shape();
    Shape(std::string name);

    virtual ~Shape();                           // Деструктор
    Shape(const Shape& other);                  // Конструктор копирования
    Shape& operator=(const Shape& other);       // Оператор присваивания копированием
    Shape(Shape&& other) noexcept;              // Конструкто перемещения
    Shape& operator=(Shape&& other) noexcept;   // Оператор присваивания перемещением
};


class Rectangle : public Shape
{
private:
    double width_;
    double length_;
protected:
    Rectangle(std::string name, double width, double length);
public:
    virtual double area() const override;
    virtual double perimeter() const override;

    Rectangle(double width, double length);

    virtual ~Rectangle() override;
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(Rectangle&& other) noexcept;
};


class Circle : public Shape
{
private:
    double radius_;
public:
    virtual double area() const override;
    virtual double perimeter() const override;

    Circle(double radius);

    ~Circle() override;
    Circle(const Circle& other);
    Circle& operator=(const Circle& other);
    Circle(Circle&& other) noexcept;
    Circle& operator=(Circle&& other) noexcept;
};


class Triangle : public Shape
{
private:
    double first_;
    double second_;
    double third_;
public:
    virtual double area() const override;
    virtual double perimeter() const override;

    Triangle(double first, double second, double third);
    
    ~Triangle() override;
    Triangle(const Triangle& other);
    Triangle& operator=(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    Triangle& operator=(Triangle&& other) noexcept;
};


class Square : public Rectangle
{
private:
public:
    // virtual double area() const override;
    // virtual double perimeter() const override;
    /* Функци можно не прописывать, т.к. при обращении к ним
    С++ сам увидит, что их здесь нет, у использует их из родителя,
    т.е. из Rectangle*/

    Square(double side);

    ~Square() override;
    Square(const Square& other);
    Square& operator=(const Square& other);
    Square(Square&& other) noexcept;
    Square& operator=(Square&& other) noexcept;
};

bool operator==(const Shape& lhs, const Shape& rhs);

bool operator^(const Shape& lhs, const Shape& rhs);

std::ostream& operator<<(std::ostream& os, const Shape& shape);