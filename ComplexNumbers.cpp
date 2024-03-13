#include <iostream>
#include <cassert>

using namespace std;

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
    friend ostream& operator<<(std::ostream& out, const Complex& c) {
        out << c.real << " + " << c.imaginary << "i";
        return out;
    }
};

void runUnitTests() {
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3(0, 4);
    Complex c4(3, 0);
    Complex c5(0, 0);

    // Addition
    assert((c1 + c2).getReal() == 4 && (c1 + c2).getImaginary() == 6);
    assert((c1 + c3).getReal() == 1 && (c1 + c3).getImaginary() == 6);
    assert((c1 + c4).getReal() == 4 && (c1 + c4).getImaginary() == 2);
    assert((c1 + c5).getReal() == 1 && (c1 + c5).getImaginary() == 2);
    assert((c2 + c2).getReal() == 6 && (c2 + c2).getImaginary() == 8);

    // Subtraction
    assert((c2 - c1).getReal() == 2 && (c2 - c1).getImaginary() == 2);
    assert((c2 - c5).getReal() == 3 && (c2 - c5).getImaginary() == 4);
    assert((c1 - c2).getReal() == -2 && (c1 - c2).getImaginary() == -2);
    assert((c1 - c3).getReal() == 1 && (c1 - c3).getImaginary() == -2);
    assert((c2 - c4).getReal() == 0 && (c2 - c4).getImaginary() == 4);
    assert((c2 - c2).getReal() == 0 && (c2 - c2).getImaginary() == 0);

    // Multiplication
    assert((c1 * c2).getReal() == -5 && (c1 * c2).getImaginary() == 10);
    assert((c1 * c3).getReal() == -8 && (c1 * c3).getImaginary() == 4);
    assert((c1 * c4).getReal() == 3 && (c1 * c4).getImaginary() == 6);
    assert((c1 * c5).getReal() == 0 && (c1 * c5).getImaginary() == 0);
    assert((c1 * c1).getReal() == -3 && (c1 * c1).getImaginary() == 4);

    // Division
    Complex div = c2 / c1;
    assert((c1 / c2).getReal() == 0.44 && (c1 / c2).getImaginary() == 0.08);
    assert((c1 / c3).getReal() == 0.5 && (c1 / c3).getImaginary() == -0.25);
    assert((c5 / c1).getReal() == 0 && (c5 / c1).getImaginary() == 0);
    assert((c1 / c1).getReal() == 1 && (c1 / c1).getImaginary() == 0);

    // Comparison
    assert(c1 != c2);
    assert(!(c1 == c2));
    assert(c1 != 1);
    assert(!(c1 == 1));
    assert((c5 == 0));
    assert((c1 == c1));

    // Power
    assert((c1 ^ 2).getReal() == -3 && (c1 ^ 2).getImaginary() == 4);
    assert((c5 ^ 2).getReal() == 0 && (c5 ^ 2).getImaginary() == 0);
    assert((c1 ^ 3).getReal() == -11 && (c1 ^ 3).getImaginary() == -2);
    assert((c3 ^ 2).getReal() == -16 && (c3 ^ 2).getImaginary() == 0);
    assert((c4 ^ 3).getReal() == 27 && (c4 ^ 3).getImaginary() == 0);

    // Modulus
    assert(c1.modulus() == sqrt(5.0));
    assert(c2.modulus() == 5);
    assert(c3.modulus() == 4);
    assert(c4.modulus() == 3);
    assert(c5.modulus() == 0);

    cout << "All tests passed successfully!";
}

int main() {
    runUnitTests();

    return 0;
}


