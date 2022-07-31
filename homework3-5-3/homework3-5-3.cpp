#include <iostream>
#include <cstring>
#include <string>

class Figure
{
protected:
    const int count_side_quadrangle = 4;
    const int count_side_triangle = 3;
    const int count_side_figure = 0;
public:
    virtual std::string get_name_figure()
    {
        return "Фигура:";
    }
    virtual int get_sides_angles(int i)
    {
        return 1;
    }
    int get_count_sides()
    {
        return count_side_figure;
    }
    virtual std::string validation()
    {
        if (get_count_sides() == 0) { return "Правильная"; }
        else { return "Неправильная"; }
    }
};

class Triangle : public Figure
{
private:
    int a, b, c;
    int A, B, C;
public:
    Triangle() {}
    Triangle(int a, int b, int c, int A, int B, int C)
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
    int get_count_sides()
    {
        return count_side_triangle;
    }

    std::string validation() override
    {
        if (get_count_sides() == 3 && A+B+C == 180) { return "Правильная"; }
        else { return "Неправильная"; }
    }

};

class Right_triangle : public Triangle
{
private:
    int a, b, c;
    int A, B, C;
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
    std::string validation()
    {
        if (C == 90 && Triangle::validation() == "Правильная") { return "Правильная"; }
        else { return "Неправильная"; }
    }

};

class Iso_triangle : public Triangle
{
private:
    int a, b, c;
    int A, B, C;
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
    std::string validation()
    {
        if ((a == c && A == C) && Triangle::validation() == "Правильная") { return "Правильная"; }
        else { return "Неправильная"; }
    }

};

class Equil_triangle : public Triangle
{
private:
    int a, b, c;
    int A, B, C;
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
    std::string validation()
    {
        if ((a == c == b && A == C == B == 60) && Triangle::validation() == "Правильная") { return "Правильная"; }
        else { return "Неправильная"; }
    }

};

class Quadrangle : public Figure
{
private:
    int a, b, c, d;
    int A, B, C, D;
    int count_side_quadrangle = 4;
public:
    Quadrangle() {}
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
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
    int get_count_sides()
    {
        return count_side_quadrangle;
    }
    std::string validation() override
    {
        if (( A + C + B + D == 360) && get_count_sides() == 4) { return "Правильная"; }
        else { return "Неправильная"; }
    }

};

class Rectangle : public Quadrangle
{
private:
    int a, b, c, d;
    int A, B, C, D;
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
    std::string validation()
    {
        if (((a == c && b == d) && (A == B == C == D == 90)) && Quadrangle::validation() == "Правильная") { return "Правильная"; }
        else { return "Неправильная"; }
    }
};

class Square : public Quadrangle
{
private:
    int a, b, c, d;
    int A, B, C, D;
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
    std::string validation() override
    {
        if (((a == c == b == d) && (A == B == C == D == 90)) && Quadrangle::validation() == "Правильная") { return "Правильная"; }
        else { return "Неправильная"; }
    }

};

class Parallelogram : public Quadrangle
{
private:
    int a, b, c, d;
    int A, B, C, D;
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
    std::string validation()
    {
        if (((a == c && b == d) && (A == C && B == D)) && Quadrangle::validation() == "Правильная") { return "Правильная"; }
        else { return "Неправильная"; }
    }

};

class Rhombus : public Quadrangle
{
private:
    int a, b, c, d;
    int A, B, C, D;
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
    std::string validation()
    {
        if (((a == c == b == d) && (A == C && B == D)) && Quadrangle::validation() == "Правильная") { return "Правильная"; }
        else { return "Неправильная"; }
    }

};

void get_info(Figure* figure)
{
    std::cout << figure->get_name_figure() << std::endl;
    std::cout << figure->validation() << std::endl;
    std::cout << "Стороны: a=" << figure->get_sides_angles(0) << " b=" << figure->get_sides_angles(1) << " c=" << figure->get_sides_angles(2);
    if (figure->get_sides_angles(3) != 0 && figure->get_sides_angles(7) != 0)
    {
        std::cout << " d=" << figure->get_sides_angles(3);
    }
    std::cout << std::endl;
    std::cout << "Углы: A=" << figure->get_sides_angles(4) << " B=" << figure->get_sides_angles(5) << " C=" << figure->get_sides_angles(6);
    if (figure->get_sides_angles(3) != 0 && figure->get_sides_angles(7) != 0)
    {
        std::cout << " D=" << figure->get_sides_angles(7);
    }
    std::cout << std::endl << std::endl;
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

    Quadrangle quadrangle           (10, 20, 30, 40, 90, 90, 90, 90);   // |
    Rectangle rectangle             (10, 20, 10, 20, 90, 90, 90, 90);   // |
    Square square                   (20, 20, 20, 20, 90, 90, 90, 90);   // | Четырехуголники
    Parallelogram parallelogram     (20, 30, 20, 30, 30, 40, 30, 40);   // |
    Rhombus rhombus                 (30, 30, 30, 30, 30, 40, 30, 40);   // |

    
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
