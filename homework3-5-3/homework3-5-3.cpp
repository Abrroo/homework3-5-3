﻿#include <iostream>
#include <cstring>
#include <string>

class Figure
{
protected:
    const int count_side = 0;
    int a = 0, b = 0, c = 0, d = 0;
    int A = 0, B = 0, C = 0, D = 0;
public:
    Figure() {}
    Figure(int a, int b, int c, int A, int B, int C)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    Figure(int a, int b, int c, int d, int A, int B, int C, int D)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    virtual std::string get_name_figure()
    {
        return "Фигура:";
    }
    virtual int get_sides_angles(int i)
    {
        return 1;
    }
    virtual int get_count_sides()
    {
        return count_side;
    }
    virtual bool validation()
    {
        if (get_count_sides() == 0) { return true; }
        else { return false; }
    }
    void print()
    {
        std::cout << get_name_figure() << std::endl;
        if (validation() == true) { std::cout << "Правильная" << std::endl; }
        else { std::cout << "Неправильная" << std::endl; }

        std::cout << "Количество сторон: " << get_count_sides() << std::endl;

        if (get_count_sides() != 0)
        {
            std::string result1 = "Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c);
            if (d > 0)
            {
                result1 = result1 + " d=" + std::to_string(d);
            }
            std::string result2 = "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C);
            if (D > 0)
            {
                result2 = result2 + " D=" + std::to_string(D);
            }
            std::cout << result1 << std::endl;
            std::cout << result2 << std::endl << std::endl;
        }
        else { std::cout << std::endl; }


    }
};

class Triangle : public Figure
{
protected:
    int a, b, c;
    int A, B, C;
    int count_side = 3;
public:
    Triangle() {}
    Triangle(int a, int b, int c, int A, int B, int C): Figure(a, b, c, A, B, C) 
    {

        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    std::string get_name_figure()
    {
        return "Треугольник:";
    }
    int get_sides_angles(int i) override
    {
        int arr[8]{ a,b,c,0,A,B,C,0 };
        int x = arr[i];
        return x;
    }
    int get_count_sides() override
    {
        return this->count_side;
    }
    
    bool validation() override
    {
        if (get_count_sides() == 3 && (A + B + C) == 180) { return true; }
        else { return false; }
    }

};

class Right_triangle : public Triangle
{
public:
    Right_triangle() {}
    Right_triangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    std::string get_name_figure()
    {
        return "Прямоугольный треугольник:";
    }
    int get_sides_angles(int i) override
    {
        int arr[8]{ a,b,c,0,A,B,C,0 };
        int x = arr[i];
        return x;
    }
    bool validation()
    {
        if (C == 90 && Triangle::validation() == true) { return true; }
        else { return false; }
    }

};

class Iso_triangle : public Triangle
{
public:
    Iso_triangle() {}
    Iso_triangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    std::string get_name_figure()
    {
        return "Равнобедренный треугольник:";
    }
    int get_sides_angles(int i) override
    {
        int arr[8]{ a,b,c,0,A,B,C,0 };
        int x = arr[i];
        return x;
    }
    bool validation()
    {
        if ((a == c && A == C) && (Triangle::validation() == true)) { return true; }
        else { return false; }
    }

};

class Equil_triangle : public Triangle
{
public:
    Equil_triangle() {}
    Equil_triangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    std::string get_name_figure()
    {
        return "Равносторонний треугольник::";
    }
    int get_sides_angles(int i) override
    {
        int arr[8]{ a,b,c,0,A,B,C,0 };
        int x = arr[i];
        return x;
    }
    bool validation()
    {
        if ((a == c && c == b) && 
            ((A == C) && (C == B) && (B == 60)) && 
            Triangle::validation() == true) { return true; }
        else { return false; }
    }

};

class Quadrangle : public Figure
{
protected:
    int a, b, c, d;
    int A, B, C, D;
    int count_side = 4;
public:
    Quadrangle() {}
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(a, b, c, d, A, B, C, D)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    std::string get_name_figure() override
    {
        return "Четырёхугольник:";
    }
    int get_sides_angles(int i) override
    {
        int arr[8]{ a,b,c,d,A,B,C,D };
        int x = arr[i];
        return x;
    }
    int get_count_sides() override
    {
        return count_side;
    }
    bool validation() override
    {
        if (( (A + C + B + D) == 360) && get_count_sides() == 4) { return true; }
        else { return false; }
    }

};

class Rectangle : public Quadrangle
{
public:
    Rectangle() {}
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    std::string get_name_figure() override
    {
        return "Прямоуголник:";
    }
    int get_sides_angles(int i) override
    {
        int arr[8]{ a,b,c,d,A,B,C,D };
        int x = arr[i];
        return x;

    }
    bool validation()
    {
        if ((a == c && b == d) && 
            ((A == B) && (B == C) && (C == D) && (D == 90)) && 
            Quadrangle::validation() == true) { return true; }
        else { return false; }
    }
};

class Square : public Quadrangle
{
public:
    Square() {}
    Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    std::string get_name_figure() override
    {
        return "Квадрат:";
    }
    int get_sides_angles(int i) override
    {
        int arr[8]{ a,b,c,d,A,B,C,D };
        int x = arr[i];
        return x;

    }
    bool validation() override
    {
        if (((a == c) && (c == b) && (b == d)) && 
            ((A == B) && (B == C) && (C == D) && (D == 90)) && 
            Quadrangle::validation() == true) { return true; }
        else { return false; }
    }

};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram() {}
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    std::string get_name_figure() override
    {
        return "Параллелограмм:";
    }
    int get_sides_angles(int i) override
    {
        int arr[8]{ a,b,c,d,A,B,C,D };
        int x = arr[i];
        return x;
    }
    bool validation()
    {
        if (((a == c && b == d) && (A == C && B == D)) && Quadrangle::validation() == true) { return true; }
        else { return false; }
    }

};

class Rhombus : public Quadrangle
{
public:
    Rhombus() {}
    Rhombus(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    std::string get_name_figure() override
    {
        return "Ромб:";
    }
    int get_sides_angles(int i) override
    {
        int arr[8]{ a,b,c,d,A,B,C,D };
        int x = arr[i];
        return x;
    }
    bool validation()
    {
        if ((a == c) && (c == b) && (b == d) && (A == C) && (B == D) && Quadrangle::validation() == true) { return true; }
        else { return false; }
    }

};

void get_info(Figure* figure)
{
    figure->print();
}

int main()
{
    setlocale(LC_ALL, "Russian");

    //                              (    Стороны    |    Углы       )
    //                                _____________   ____________
    //                                |   |   |   |   |  |   |   |
    //                                V   V   V   V   V  V   V   V
    Figure figure;
    Triangle triangle               (10, 20, 30,     50, 60, 70);       // |
    Right_triangle right_triangle   (10, 20, 30,     50, 40, 90);       // | Треугольники
    Iso_triangle iso_triangle       (10, 20, 10,     50, 60, 50);       // |
    Equil_triangle equil_triangle   (30, 30, 30,     60, 60, 60);       // |

    Quadrangle quadrangle           (10, 20, 30, 40, 50, 60, 70, 80);   // |
    Rectangle rectangle             (10, 20, 10, 20, 90, 90, 90, 90);   // |
    Square square                   (20, 20, 20, 20, 90, 90, 90, 90);   // | Четырехуголники
    Parallelogram parallelogram     (20, 30, 20, 30, 30, 40, 30, 40);   // |
    Rhombus rhombus                 (30, 30, 30, 30, 30, 40, 30, 40);   // |

    get_info(&figure);
    get_info(&triangle);
    get_info(&right_triangle);
    get_info(&iso_triangle);
    get_info(&equil_triangle);
    get_info(&quadrangle);
    get_info(&rectangle);
    get_info(&square);
    get_info(&parallelogram);
    get_info(&rhombus);
    

}
