#ifndef MATH_COMPLEX_H
#define MATH_COMPLEX_H

#include <iosfwd>
#include <string>

#include "Types.h"

namespace Math {

class Complex {
protected:
  real_t m_Real;
  real_t m_Imag;

public:
  Complex();
  Complex(real_t real, real_t imag);
  Complex(const Complex& other);

  Complex& operator=(const Complex& other) = default;

  /// Get the real part of the complex number
  /// @return Real part
  real_t real() const { return m_Real; }

  /// Get the imaginary part of the complex number
  /// @return Imaginary part
  real_t imag() const { return m_Imag; }

  friend real_t real(const Complex& z);
  friend real_t imag(const Complex& z);
  friend real_t abs(const Complex& z);
  friend real_t abs2(const Complex& z);
  friend real_t arg(const Complex& z);
  friend Complex conj(const Complex& z);
  friend Complex exp(const Complex& z);
  friend Complex log(const Complex& z);
  friend Complex sin(const Complex& z);
  friend Complex cos(const Complex& z);
  friend Complex tan(const Complex& z);
  friend Complex asin(const Complex& z);
  friend Complex acos(const Complex& z);
  friend Complex atan(const Complex& z);
  friend Complex pow(const Complex& z, real_t w);
  friend Complex pow(const Complex& z, const Complex& w);
  friend Complex sqrt(const Complex& z);

  Complex operator+() const;
  Complex operator-() const;
  Complex& operator+=(const Complex& rhs);
  Complex& operator-=(const Complex& rhs);
  Complex& operator*=(const Complex& rhs);
  Complex& operator/=(const Complex& rhs);
  Complex& operator+=(real_t rhs);
  Complex& operator-=(real_t rhs);
  Complex& operator*=(real_t rhs);
  Complex& operator/=(real_t rhs);
};

Complex operator+(Complex lhs, const Complex& rhs);
Complex operator+(Complex lhs, real_t rhs);
Complex operator+(real_t lhs, Complex rhs);
Complex operator-(Complex lhs, const Complex& rhs);
Complex operator-(Complex lhs, real_t rhs);
Complex operator-(real_t lhs, const Complex& rhs);
Complex operator*(Complex lhs, const Complex& rhs);
Complex operator*(Complex lhs, real_t rhs);
Complex operator*(real_t lhs, Complex rhs);
Complex operator/(Complex lhs, const Complex& rhs);
Complex operator/(Complex lhs, real_t rhs);
Complex operator/(real_t lhs, const Complex& rhs);

std::string to_string(const Complex& z);
std::ostream& operator<<(std::ostream& os, const Complex& z);
void print(const Complex& z);

}  // namespace Math

namespace std {

std::string to_string(const Math::Complex& z);

}  // namespace std

#endif  // MATH_COMPLEX_H
