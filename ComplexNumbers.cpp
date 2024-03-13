#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r, double i) : real(r), imaginary(i) {}

    // getters and setters
    double getReal() const { return real; }
    void setReal(double r) { real = r; }

    double getImaginary() const { return imaginary; }
    void setImaginary(double i) { imaginary = i; }

    // arithmetic operations
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        return Complex((real * other.real + imaginary * other.imaginary) / denominator,
            (imaginary * other.real - real * other.imaginary) / denominator);
    }

    // comparison operations
    bool operator==(const Complex& other) const {
        return real == other.real && imaginary == other.imaginary;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    bool operator==(double scalar) const {
        return real == scalar && imaginary == 0.0;
    }

    bool operator!=(double scalar) const {
        return !(*this == scalar);
    }

    // other operations
    Complex operator^(int power) const {
        Complex result = *this;
        for (int i = 1; i < power; i++) {
            result = result * (*this);
        }
        return result;
    }

    double modulus() const {
        return sqrt(real * real + imaginary * imaginary);
    }

    // console output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imaginary << "i";
        return out;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
