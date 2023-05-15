#include "Fraction.hpp"   
#include <cmath>
namespace ariel{}
void Fraction::reduce(){
    int gcd = std::__gcd(abs(numerator),abs(denominator));
    numerator /= gcd;
    denominator /= gcd;
}
Fraction Fraction::reduce(int rnumerator,int rdenominator) const{
    int gcd = std::__gcd(abs(rnumerator),abs(rdenominator));
    rnumerator /= gcd;
    rdenominator /= gcd;
    return{rnumerator,rdenominator};
}
int of_plus(int a, int b){
    if ((a > 0 && b > 0 && (a + b) < 0) || (a < 0 && b < 0 && (a + b) > 0))
        throw std::overflow_error ("overflow");
    return (a+b);    
}
int of_min(int a , int b){
    if ((a > 0 && b < 0 && a-b < 0) ||(a < 0 && b > 0 && a-b > 0))
        throw std::overflow_error ("overflow");
    return (a-b);
}
int of_mul(int a, int b){
    if (a !=0 && b!= 0)
        if((a*b)/a != b)
            throw std::overflow_error ("overflow");
    return (a*b);    
}


Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
}
Fraction::~Fraction(){

}
Fraction::Fraction(Fraction& other){
    numerator = other.numerator;
    denominator = other.denominator;
}
Fraction& Fraction::operator=(Fraction& other){
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

Fraction::Fraction(float num){
    int power = 1;
    while (num != std::round(num) && power < 1000)
    {
        num *= 10;
        power *= 10;
    }
    numerator = std::round(num);
    denominator = power;
    reduce();
}

Fraction::Fraction(int n, int d) {
    if (d == 0) {
        throw std::invalid_argument ( "Error: denominator cannot be zero");
        numerator = 0;
        denominator = 1;
    } else if (d < 0) {
        numerator = -n;
        denominator = -d;
    } 
    else {
        numerator = n;
        denominator = d;
    }
    reduce();
}
Fraction::Fraction(const Fraction& other) {
    numerator = other.numerator;
    denominator = other.denominator;
}

//overload +
Fraction Fraction::operator+(const Fraction& other) const{
    int new_numerator = of_plus(of_mul(numerator,other.denominator),of_mul(other.numerator,denominator));
    int new_denominator = of_mul(denominator,other.denominator);
    return reduce(new_numerator,new_denominator);
}
Fraction Fraction::operator+(float num) const{
    return (*this + Fraction(num));
}
Fraction operator+(float num, const Fraction& other){
    return Fraction(num) + other;
}
//overload -
Fraction Fraction::operator-(const Fraction& other) const{
    int new_numerator = of_min(of_mul(numerator,other.denominator),of_mul(other.numerator, denominator));
    int new_denominator = of_mul(denominator,other.denominator);
    return reduce(new_numerator,new_denominator);
}
Fraction Fraction::operator-(float num) const{
    return (*this - Fraction(num));
}

Fraction operator-(float num, const Fraction& other) {
    return Fraction(num) - other;
}
//overload *
Fraction Fraction::operator*(const Fraction& other) const{
    int new_numerator = of_mul(numerator,other.numerator);
    int new_denominator = of_mul(denominator,other.denominator);
    return reduce(new_numerator,new_denominator);
}
Fraction Fraction::operator*(float num) const{
    return (*this * Fraction(num));
}

Fraction operator*(float num, const Fraction& other){
    return Fraction(num) * other;
}
//overload /
Fraction Fraction::operator/(const Fraction& other) const{
    if(other.numerator == 0)
        throw std::runtime_error ("frac canot be 0");
    int new_numerator = of_mul(numerator,other.denominator);
    int new_denominator = of_mul(denominator,other.numerator);
    return reduce(new_numerator,new_denominator);
}
Fraction Fraction::operator/(float num) const{
    return (*this / Fraction(num));
}

Fraction operator/(float num, const Fraction& other) {
    return Fraction(num) / other;
}
//overload ==
bool Fraction::operator==(Fraction other) const{
    int this_gcd = std::__gcd(abs(numerator),abs(denominator));
    int other_gcd = std::__gcd(abs(numerator),abs(denominator));
    return ((numerator/this_gcd == other.numerator/other_gcd) && (denominator/this_gcd == other.denominator/this_gcd));
}
bool Fraction::operator==(float num) const{
    return (*this == Fraction(num));
}
bool operator==(float num, const Fraction& frac){
    return (frac == num);
}

//overload !=
bool Fraction::operator!=(const Fraction& other) const{
    return !(*this == other);
}
bool Fraction::operator!=(float num) const{
    return !(*this == Fraction(num));
}
bool operator!=(float num, const Fraction& frac){
    return !(Fraction(num) == frac);
}


//ovaerload >
bool Fraction::operator>(const Fraction& other) const{
    if(numerator < 0 && other.getNumerator() > 0)
        return false;
    if(numerator > 0 && other.getNumerator() < 0)
        return true;    
    return (( numerator * other.getDenominator()) >  (denominator * other.getNumerator()));
}
bool Fraction::operator>(float num) const{
    return (*this > Fraction(num));
}
bool operator>(float num, const Fraction& frac){
    return (Fraction(num) > frac);
}
//ovaerload <
bool Fraction::operator<(const Fraction& other) const{
    if(numerator < 0 && other.getNumerator() > 0)
        return true;
    if(numerator > 0 && other.getNumerator() < 0)
        return false;
    return ((numerator * other.denominator) < (other.numerator * denominator));
}
bool Fraction::operator<(float num) const{
    return (*this < Fraction(num));
}
bool operator<(float num, const Fraction& frac){
    return (Fraction(num) < frac);
}
//overload >=
bool Fraction::operator>=(const Fraction& other) const{
    return !(*this < other);
}
bool Fraction::operator>=(float num) const{
    return !(*this < Fraction(num));
}
bool operator>=(float num,const Fraction& frac){
    return !(Fraction(num) < frac);
}
//overload <=
bool Fraction::operator<=(const Fraction& other) const{
    return !(*this > other);
}
bool Fraction::operator<=(float num) const{
    return !(*this > Fraction(num));
}
bool operator<=(float num,const Fraction& frac){
    return !(Fraction(num) > frac);
}
//overload prefix and postfix for ++ and --

Fraction Fraction::operator++() {
    numerator += denominator;

    reduce();

    return *this;
}


Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    ++(*this);
    return temp;
}

Fraction Fraction::operator--() {
    numerator -= denominator;

    reduce();

    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    --(*this);
    return temp;
}
//overload =
Fraction& Fraction::operator=(const Fraction& other) {
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}
Fraction& Fraction::operator=(float num){
    *this = Fraction(num);
    return *this;
}
//overload <<
std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}
//overload >>
std::istream& operator>>(std::istream& is, Fraction& frac){
    int n,d = 0;
    is >> n >> d;
    if(d == 0)
        throw std::runtime_error("wrong input");
    frac = Fraction(n,d);
    return is;
}
int Fraction::getNumerator() const{
    return numerator;
}
int Fraction::getDenominator() const{
    return denominator;
}
    
