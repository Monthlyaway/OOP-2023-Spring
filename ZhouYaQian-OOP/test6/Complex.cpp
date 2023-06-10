#include "Complex.h"
using namespace std;

//Complex::Complex(void) : _real(0), _image(0) {}

Complex::Complex(double r, double i) : _real(r), _image(i) {}

Complex::Complex(double r) : _real(r), _image(0) {}

Complex& Complex::operator+=(const Complex& rhs) {
    _real += rhs._real;
    _image += rhs._image;
    return *this;
}

Complex Complex::operator+(const Complex& rhs) {
    Complex temp(_real + rhs._real, _image + rhs._image);
    return temp;
}

Complex operator+(int lhs, const Complex& rhs) {
    Complex result(lhs + rhs._real, rhs._image);
    return result;
}

istream& operator>>(istream& is, Complex& rhs) {
    string line;
    if (!getline(is, line)) {
        cerr << "Error: Failed to read input line." << endl;
        return is;
    }

    line.erase(remove_if(line.begin(), line.end(), [](char c) {
        return isspace(c);
        }), line.end());

    auto plusPos = line.find('+');
    if (plusPos == string::npos) {
        cerr << "Error: Invalid format. Expected '+' between real and imaginary parts." << endl;
        return is;
    }

    string realPart = line.substr(0, plusPos);
    string imagPart = line.substr(plusPos + 1);

    if (imagPart.back() != 'i') {
        cerr << "Error: Invalid format. Expected 'i' at the end of the imaginary part." << endl;
        return is;
    }

    imagPart.pop_back();

    try {
        rhs._real = stod(realPart);
        rhs._image = stod(imagPart);
    }
    catch (const exception& e) {
        cerr << "Error: Failed to parse real or imaginary part of the complex number." << endl;
        return is;
    }
    return is;
}

ostream& operator<<(ostream& os, const Complex& rhs) {
    os << rhs._real << "+" << rhs._image << "i";
    return os;
}

