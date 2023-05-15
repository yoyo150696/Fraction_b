#pragma once
#include <iostream>
#include <sstream>
#include <algorithm>
namespace ariel{}
class Fraction {

    public:
        int numerator;
        int denominator;
        void reduce();
        Fraction reduce(int rnumerator,int rdenominator) const;
        // Constructors
        Fraction();
        Fraction(const Fraction& num);
        Fraction(int numer, int denom);
        Fraction(float numnum);
        ~Fraction();
        Fraction(Fraction& other);
        Fraction& operator=(Fraction& other);

        // Operator overloading

        // + overload
        
        Fraction operator+(const Fraction& other) const;
        Fraction operator+( float num) const;
        friend Fraction operator+(float num, const Fraction& frac);
        // - overload
        Fraction operator-(const Fraction& other) const;
        Fraction operator-(float num)const;
        friend Fraction operator-(float num, const Fraction& frac);
        // * overload
        Fraction operator*(const Fraction& other) const;
        Fraction operator*(float num) const;
        friend Fraction operator*(float num, const Fraction& frac);
        // / overload
        Fraction operator/(const Fraction& other) const;
        Fraction operator/(float num) const;
        friend Fraction operator/(float num, const Fraction& frac);
        // == overload
        bool operator==(Fraction other) const;
        bool operator==(float num) const;
        friend bool operator==(float num, const Fraction& frac);
        // != overload
        bool operator!=(const Fraction& other) const;
        bool operator!=(float num) const;
        friend bool operator!=(float num, const Fraction& frac);
        // > overload
        bool operator>(const Fraction& other) const;
        bool operator>(float num) const;
        friend bool operator>(float num, const Fraction& frac);
        // < overload
        bool operator<(const Fraction& other) const;
        bool operator<(float num) const;
        friend bool operator<(float num, const Fraction& frac);
        // >= overload
        bool operator>=(const Fraction& other) const;
        bool operator>=(float num) const;
        friend bool operator>=(float num, const Fraction& frac);
        // <= overload
        bool operator<=(const Fraction& other) const;
        bool operator<=(float num) const;
        friend bool operator<=(float num, const Fraction& frac);
        //prefix and postfix for ++ and --
        Fraction operator++();
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);
        //overload =
        Fraction& operator=(const Fraction& other);
        Fraction& operator=(float num);
        friend std::ostream& operator<<(std::ostream& COUT, const Fraction& frac);
        friend std::istream& operator>>(std::istream& CIN, Fraction& frac);
        int getNumerator() const;
        int getDenominator() const;
};


