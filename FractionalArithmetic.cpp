#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

class FractionArithmetic {

    int numerator;
    int denominator;

public:

    FractionArithmetic() : numerator(0), denominator(0) {
    }

    FractionArithmetic(int numOne, int numTwo) {
        this->numerator = numOne;
        this->denominator = numTwo;
    }

    void SetValues(int numOne, int numTwo) {
        this->numerator = numOne;
        this->denominator = numTwo;
    }

    FractionArithmetic operator+(const FractionArithmetic& other) const {
        int lcm_res = lcm(denominator, other.denominator);
        int num_res = lcm_res / denominator * numerator + lcm_res / other.denominator * other.numerator;
        int gcd_res = gcd(num_res, lcm_res);
        return FractionArithmetic(num_res / gcd_res, lcm_res / gcd_res);
    }

    FractionArithmetic operator-(const FractionArithmetic& other) const {
        int lcm_res = lcm(denominator, other.denominator);
        int num_res = lcm_res / denominator * numerator - lcm_res / other.denominator * other.numerator;
        int gcd_res = gcd(num_res, lcm_res);
        return FractionArithmetic(num_res / gcd_res, lcm_res / gcd_res);
    }

    FractionArithmetic operator*(const FractionArithmetic& other) const {
        int num_res = numerator * other.numerator;
        int denom_res = denominator * other.denominator;
        int gcd_res = gcd(num_res, denom_res);
        return FractionArithmetic(num_res / gcd_res, denom_res / gcd_res);
    }

    FractionArithmetic operator/(const FractionArithmetic& other) const {
        int num_res = numerator * other.denominator;
        int denom_res = denominator * other.numerator;
        int gcd_res = gcd(num_res, denom_res);
        return FractionArithmetic(num_res / gcd_res, denom_res / gcd_res);
    }

    void Print() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {

    int numOne, numTwo;
    char slash;
    FractionArithmetic A, B, C;

    cout << "enter the fraction A: ";
    cin >> numOne >> slash >> numTwo;
    A.SetValues(numOne, numTwo);

    cout << "enter the fraction B: ";
    cin >> numOne >> slash >> numTwo;
    B.SetValues(numOne, numTwo);

    int number;
    cout << "Select operation:\n1) +\n2) -\n3) *\n4) / \n-> ";
    cin >> number;

    switch (number) {

        case 1:

            C = A + B;
            C.Print();
            break;

        case 2:

            C = A - B;
            C.Print();
            break;

        case 3:

            C = A * B;
            C.Print();
            break;

        case 4:

            C = A / B;
            C.Print();
            break;

        default:
            break;
    }

    return 0;
}