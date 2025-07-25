
#include "Complex.h"

#include <cmath>
#include <iostream>

#include "Error.h"

namespace Math {

Complex::Complex() : m_Real(0), m_Imag(0) {}

Complex::Complex(const real_t real, const real_t imag) : m_Real(real), m_Imag(imag) {}

Complex::Complex(const Complex& other) : m_Real(other.m_Real), m_Imag(other.m_Imag) {}

real_t real(const Complex& z) {
  return z.m_Real;
}

real_t imag(const Complex& z) {
  return z.m_Imag;
}

real_t abs(const Complex& z) {
  return std::sqrt(abs2(z));
}

real_t abs2(const Complex& z) {
  return z.m_Real * z.m_Real + z.m_Imag * z.m_Imag;
}

real_t arg(const Complex& z) {
  return std::atan2(z.m_Imag, z.m_Real);
}

Complex conj(const Complex& z) {
  return Complex(z.m_Real, -z.m_Imag);
}

Complex exp(const Complex& z) {
  return std::exp(z.m_Real) * (std::cos(z.m_Imag) + Complex(0, 1) * std::sin(z.m_Imag));
}

Complex log(const Complex& z) {
  return Complex(std::log(abs(z)), arg(z));
}

Complex sin(const Complex& z) {
  return Complex(std::sin(z.m_Real) * std::cosh(z.m_Imag), std::cos(z.m_Real) * std::sinh(z.m_Imag));
}

Complex cos(const Complex& z) {
  return Complex(std::cos(z.m_Real) * std::cosh(z.m_Imag), -std::sin(z.m_Real) * std::sinh(z.m_Imag));
}

Complex tan(const Complex& z) {
  return sin(z) / cos(z);
}

Complex asin(const Complex& z) {
  const Complex i(0, 1);
  return -i * log(i * z + sqrt(static_cast<real_t>(1.0) - z * z));
}

Complex acos(const Complex& z) {
  return -Complex(0, 1) * log(z + sqrt(z * z - static_cast<real_t>(1.0)));
}

Complex atan(const Complex& z) {
  const Complex i(0, 1);
  const Complex one(1, 0);
  return (i / Complex(2, 0)) * (log(one - i * z) - log(one + i * z));
}

Complex pow(const Complex& z, const real_t w) {
  return exp(w * log(z));
}

Complex pow(const Complex& z, const Complex& w) {
  return exp(w * log(z));
}

Complex sqrt(const Complex& z) {const real_t r = abs(z);
  const real_t x = z.m_Real;
  const real_t y = z.m_Imag;
  const real_t u = std::sqrt((r + x) / 2);
  real_t v = std::sqrt((r - x) / 2);
  if (y < 0) v = -v;
  return Complex(u, v);
}

Complex Complex::operator+() const {
  return Complex(*this);
}

Complex Complex::operator-() const {
  return Complex(-this->m_Real, -this->m_Imag);
}

Complex& Complex::operator+=(const Complex& rhs) {
  this->m_Real += rhs.m_Real;
  this->m_Imag += rhs.m_Imag;
  return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
  this->m_Real -= rhs.m_Real;
  this->m_Imag -= rhs.m_Imag;
  return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
  const real_t real = this->m_Real * rhs.m_Real - this->m_Imag * rhs.m_Imag;
  this->m_Imag = this->m_Imag * rhs.m_Real + this->m_Real * rhs.m_Imag;
  this->m_Real = real;
  return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
  const real_t div = abs2(rhs);
  const real_t real = (this->m_Real * rhs.m_Real + this->m_Imag * rhs.m_Imag) / div;
  this->m_Imag = (this->m_Imag * rhs.m_Real - this->m_Real * rhs.m_Imag) / div;
  this->m_Real = real;
  return *this;
}

Complex& Complex::operator+=(const real_t rhs) {
  this->m_Real += rhs;
  return *this;
}

Complex& Complex::operator-=(const real_t rhs) {
  this->m_Real -= rhs;
  return *this;
}

Complex& Complex::operator*=(const real_t rhs) {
  this->m_Real *= rhs;
  this->m_Imag *= rhs;
  return *this;
}

Complex& Complex::operator/=(const real_t rhs) {
  this->m_Real /= rhs;
  this->m_Imag /= rhs;
  return *this;
}

Complex operator+(Complex lhs, const Complex& rhs) {
  lhs += rhs;
  return lhs;
}

Complex operator+(Complex lhs, const real_t rhs) {
  lhs += rhs;
  return lhs;
}

Complex operator+(const real_t lhs, Complex rhs) {
  rhs += lhs;
  return rhs;
}

Complex operator-(Complex lhs, const Complex& rhs) {
  lhs -= rhs;
  return lhs;
}

Complex operator-(Complex lhs, const real_t rhs) {
  lhs -= rhs;
  return lhs;
}

Complex operator-(const real_t lhs, const Complex& rhs) {
  Complex tmp = -rhs;
  tmp += lhs;
  return tmp;
}

Complex operator*(Complex lhs, const Complex& rhs) {
  lhs *= rhs;
  return lhs;
}

Complex operator*(Complex lhs, const real_t rhs) {
  lhs *= rhs;
  return lhs;
}

Complex operator*(const real_t lhs, Complex rhs) {
  rhs *= lhs;
  return rhs;
}

Complex operator/(Complex lhs, const Complex& rhs) {
  lhs /= rhs;
  return lhs;
}

Complex operator/(Complex lhs, const real_t rhs) {
  lhs /= rhs;
  return lhs;
}

Complex operator/(const real_t lhs, const Complex& rhs) {
  return Complex(lhs, 0) / rhs;
}

std::string to_string(const Complex& z) {
  const std::string sign = z.imag() > 0 ? " + " : " - ";
  std::string str = std::to_string(z.real());
  if (std::abs(z.imag()) > EPSILON) {
    str += sign + std::to_string(std::abs(z.imag())) + "i";
  }
  return str;
}

std::ostream& operator<<(std::ostream& os, const Complex& z) {
  os << to_string(z);
  return os;
}

void print(const Complex& z) {
  std::cout << z << '\n';
}

}  // namespace Math

namespace std {

std::string to_string(const Math::Complex& z) {
  return Math::to_string(z);
}

}  // namespace std