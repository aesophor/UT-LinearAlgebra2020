#ifndef MATRICKS_FRACTION_H_
#define MATRICKS_FRACTION_H_

#include <iostream>

class Fraction {
 public:
  Fraction() : n_(0), d_(1) {}
  Fraction(int n) : n_(n), d_(1) {}
  Fraction(int n, int d) : n_(n), d_(d) {}
  virtual ~Fraction() = default;
  
  Fraction operator +(const Fraction& other) { return Add(other); }
  Fraction operator -(const Fraction& other) { return Sub(other); }
  Fraction operator *(const Fraction& other) { return Mul(other); }
  Fraction operator /(const Fraction& other) { return Div(other); }
  Fraction& operator +=(const Fraction& other) { return Add(other); }
  Fraction& operator -=(const Fraction& other) { return Sub(other); }
  Fraction& operator *=(const Fraction& other) { return Mul(other); }
  Fraction& operator /=(const Fraction& other) { return Div(other); }

  bool operator ==(const Fraction& other) const {
    Fraction f1 = Simplify();
    Fraction f2 = other.Simplify();
    return f1.n_ == f2.n_ && f1.d_ == f2.d_;
  }

  bool operator !=(const Fraction& other) const {
    return !(*this == other);
  }

  friend std::ostream& operator <<(std::ostream& os, const Fraction& f) {
    if (f.d_ == 1) {
      return os << f.n_;
    }
    return os << f.n_ << "/" << f.d_;
  }

 private:
  static int Gcd(int a, int b) {
    if (b == 0) {
      return a;
    }
    return Gcd(b, a % b);
  }

  Fraction& Add(Fraction other) {
    int n = n_ * other.d_ + other.n_ * d_;
    int d = d_ * other.d_;
    n_ = n / Gcd(n, d);
    d_ = d / Gcd(n, d);
    return *this;
  }

  Fraction& Sub(Fraction other) {
    int n = n_ * other.d_ - other.n_ * d_;
    int d = d_ * other.d_;
    n_ = n / Gcd(n, d);
    d_ = d / Gcd(n, d);
    return *this;
  }

  Fraction& Mul(Fraction other) {
    int n = n_ * other.n_;
    int d = d_ * other.d_;
    n_ = n / Gcd(n, d);
    d_ = d / Gcd(n, d);
    return *this;
  }

  Fraction& Div(Fraction other) {
    int n = n_ * other.d_;
    int d = d_ * other.n_;
    n_ = n / Gcd(n, d);
    d_ = d / Gcd(n, d);
    return *this;
  }

  Fraction Simplify() const {
    int n = n_;
    int d = d_;
    int gcd = Gcd(n, d);

    if (n >= gcd && d >= gcd) {
      n /= gcd;
      d /= gcd;
    }
    return Fraction(n, d);
  }

  int n_;  // numerator
  int d_;  // denominator
};

#endif  // MATRICKS_FRACTION_H_
