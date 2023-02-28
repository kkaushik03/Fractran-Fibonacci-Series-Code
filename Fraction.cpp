#include <iostream>
using namespace std; 
#include <cmath>

class Fraction {
//g++ main.cpp -o main

public:
    Fraction(int num, int den) : numerator(num), denominator(den) {}

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    void setNumerator(int num) {
        numerator = num;
    }

    void setDenominator(int den) {
        denominator = den;
    }
//simplifies the num and den
    void simplify() {
        int gcf = 1;
        int smaller = numerator < denominator ? numerator : denominator;
        for (int i = 2; i <= smaller; i++) {
            if (numerator % i == 0 && denominator % i == 0) {
                gcf = i;
            }
        }
        numerator /= gcf;
        denominator /= gcf;
    }
//if something is a decimal this converts it to a fraction 
    static Fraction convertToFraction(double decimal) {
        int exponent = 0;
        while (decimal != floor(decimal)) {
            decimal *= 10;
            exponent++;
        }
        return Fraction(decimal, pow(10, exponent));
    }
//to check if something is simplified
    bool isSimplified()  {

        int originalNumerator = numerator;

        int originalDenominator = denominator;
        int gcf = 1;
        int smaller = numerator < denominator ? numerator : denominator;
        for (int i = 2; i <= smaller; i++) {
            if (numerator % i == 0 && denominator % i == 0) {
                gcf = i;
            }
        }
        numerator = numerator/ gcf;
        denominator /= gcf;
        if (numerator * denominator == originalNumerator * originalDenominator) {
            return true;
        } else {
            return false;
        }
    }
//to check if something has a common factor
    bool hasCommonFactor(const Fraction &f) const {
        int numerator1 = numerator;
        int denominator1 = denominator;
        int numerator2 = f.numerator;
        int denominator2 = f.denominator;
        int gcf = 1;
        int smaller = numerator1 < denominator1 ? numerator1 : denominator1;
        for (int i = 2; i <= smaller; i++) {
            if (numerator1 % i == 0 && denominator1 % i == 0 && numerator2 % i == 0 && denominator2 % i == 0) {
                gcf = i;
            }
        }
        if (gcf > 1) {
            return true;
        } else {
            return false;
        }
    }

//better approach to the previous problem 
    bool hasCommonFactor2(int num1, int num2) {
    if(gcd2(num1,num2)!=1) return true; 
    return false;
}

bool hasCom(Fraction f1, Fraction f2)
{
    if(hasCommonFactor2(f1.getDenominator(),f2.getNumerator()) || hasCommonFactor2(f2.getDenominator(),f1.getNumerator()))
        return true;

    return false; 
}



//trust this works
int gcd2(int a, int b) {
  int r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}




    private:
    int numerator;
    int denominator;
};
