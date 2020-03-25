#ifndef MATRICKS_FRACTION_H_
#define MATRICKS_FRACTION_H_

#include <iostream>
#include <algorithm>

namespace matricks {

// A class which encapsulates the numerator and denominator of a fraction
// where both the numerator and denominator are of the type `int`.
//
// This class also provides basic arithmetic operations on fractions
// via operator overloading (e.g., +, -, *, /), and the results will be
// automatically simplified.
class Fraction {
 public:
  Fraction() : n_(0), d_(1) {}
  Fraction(int n) : n_(n), d_(1) {}
  Fraction(int n, int d) : n_(n), d_(d) {}
  Fraction(const Fraction& other) : n_(other.n_), d_(other.d_) {}
  virtual ~Fraction() = default;


  Fraction operator +(const Fraction& other) const {
    return Fraction(n_ * other.d_ + other.n_ * d_, d_ * other.d_).Simplify();
  }

  Fraction operator -(const Fraction& other) const {
    return Fraction(n_ * other.d_ - other.n_ * d_, d_ * other.d_).Simplify();
  }

  Fraction operator *(const Fraction& other) const {
    return Fraction(n_ * other.n_, d_ * other.d_).Simplify();
  }

  Fraction operator /(const Fraction& other) const {
    return Fraction(n_ * other.d_, d_ * other.n_).Simplify();
  }


  Fraction& operator =(const Fraction& other) {
    n_ = other.n_;
    d_ = other.d_;
    return *this;
  }

  Fraction& operator +=(const Fraction& other) {
    return *this = *this + other;
  }

  Fraction& operator -=(const Fraction& other) {
    return *this = *this - other;
  }

  Fraction& operator *=(const Fraction& other) {
    return *this = *this * other;
  }

  Fraction& operator /=(const Fraction& other) {
    return *this = *this / other;
  }

  bool operator ==(const Fraction& other) const {
    const Fraction f1 = this->Simplify();
    const Fraction f2 = other.Simplify();
    return f1.n_ == f2.n_ && f1.d_ == f2.d_;
  }

  bool operator !=(const Fraction& other) const {
    return !(*this == other);
  }


  friend std::ostream& operator <<(std::ostream& os, const Fraction& f) {
    return (f.d_ == 1) ? (os << f.n_) : (os << f.n_ << "/" << f.d_);
  }

 private:
  Fraction Simplify() const {
    const int gcd = std::__gcd(n_, d_);
    return Fraction(n_ / gcd, d_ / gcd);
  }

  int n_;  // numerator
  int d_;  // denominator
};

}  // namespace matricks

#endif  // MATRICKS_FRACTION_H_
