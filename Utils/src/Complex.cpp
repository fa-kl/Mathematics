
#include "Complex.h"

#include <cmath>
#include <iostream>

#include "Error.h"

namespace Math {

/// Default constructor: creates a complex number with 0 real and 0 imaginary part
Complex::Complex() : m_Real(0), m_Imag(0) {}

/// Create a new complex number
/// @param real Real part
/// @param imag Imaginary part
Complex::Complex(const real_t real, const real_t imag) : m_Real(real), m_Imag(imag) {}

/// Create a copy of a complex number
/// @param other Complex number
Complex::Complex(const Complex& other) : m_Real(other.m_Real), m_Imag(other.m_Imag) {}

/// Get the real part of the complex number z
/// @param z Complex number
/// @return Real part of z
real_t real(const Complex& z) {
  return z.m_Real;
}

/// Get the imaginary part of the complex number z
/// @param z Complex number
/// @return Imaginary part of z
real_t imag(const Complex& z) {
  return z.m_Imag;
}

/// Computes the magnitude of a complex number z
/// @param z Complex number
/// @return Magnitude of z
real_t abs(const Complex& z) {
  return std::sqrt(abs2(z));
}

/// Computes the squared magnitude of a complex number z
/// @param z Complex number
/// @return Squared magnitude of z
real_t abs2(const Complex& z) {
  return z.m_Real * z.m_Real + z.m_Imag * z.m_Imag;
}

/// Computes the argument (angle to real axis) of a complex number z
/// @param z Complex number
/// @return Argument of z
real_t arg(const Complex& z) {
  return std::atan2(z.m_Imag, z.m_Real);
}

/// Computes the conjugate of a complex number z
/// @param z Complex number
/// @return Conjugate complex number of z
Complex conj(const Complex& z) {
  return Complex(z.m_Real, -z.m_Imag);
}

/// Computes the exponential map of a complex number z
/// @param z Complex number
/// @return Exponential of z
Complex exp(const Complex& z) {
  return std::exp(z.m_Real) * (std::cos(z.m_Imag) + Complex(0, 1) * std::sin(z.m_Imag));
}

/// Computes the logarithmic map of a complex number z
/// @param z Complex number
/// @return Logarithm of z
Complex log(const Complex& z) {
  return Complex(std::log(abs(z)), arg(z));
}

/// Computes the sine of a complex number z
/// @param z Complex number
/// @return Sine of z
Complex sin(const Complex& z) {
  return Complex(std::sin(z.m_Real) * std::cosh(z.m_Imag), std::cos(z.m_Real) * std::sinh(z.m_Imag));
}

/// Computes the cosine of a complex number z
/// @param z Complex number
/// @return Cosine of z
Complex cos(const Complex& z) {
  return Complex(std::cos(z.m_Real) * std::cosh(z.m_Imag), -std::sin(z.m_Real) * std::sinh(z.m_Imag));
}

/// Computes the tangent of a complex number z
/// @param z Complex number
/// @return Tangent of z
Complex tan(const Complex& z) {
  return sin(z) / cos(z);
}

/// Computes the arc-sine of a complex number z
/// @param z Complex number
/// @return Arc-sine of z
Complex asin(const Complex& z) {
  const Complex i(0, 1);
  return -i * log(i * z + sqrt(static_cast<real_t>(1.0) - z * z));
}

/// Computes the arc-cosine of a complex number z
/// @param z Complex number
/// @return Arc-cosine of z
Complex acos(const Complex& z) {
  return -Complex(0, 1) * log(z + sqrt(z * z - static_cast<real_t>(1.0)));
}

/// Computes the arc-tangent of a complex number z
/// @param z Complex number
/// @return Arc-tangent of z
Complex atan(const Complex& z) {
  const Complex i(0, 1);
  const Complex one(1, 0);
  return (i / Complex(2, 0)) * (log(one - i * z) - log(one + i * z));
}

/// Computes the power of a complex number z with a real exponent w
/// @param z Base, complex number
/// @param w Exponent, real number
/// @return z to the power of w
Complex pow(const Complex& z, const real_t w) {
  return exp(w * log(z));
}

/// Computes the power of a complex number z with a complex exponent w
/// @param z Base, complex number
/// @param w Exponent, complex number
/// @return z to the power of w
Complex pow(const Complex& z, const Complex& w) {
  return exp(w * log(z));
}

/// Computes the square root of a complex number z
/// @param z Complex number
/// @return Square root of z
Complex sqrt(const Complex& z) {const real_t r = abs(z);
  const real_t x = z.m_Real;
  const real_t y = z.m_Imag;
  const real_t u = std::sqrt((r + x) / 2);
  real_t v = std::sqrt((r - x) / 2);
  if (y < 0) v = -v;
  return Complex(u, v);
}

/// @return A copy of the complex number
Complex Complex::operator+() const {
  return Complex(*this);
}

/// Negate a complex number
/// @return A negated copy
Complex Complex::operator-() const {
  return Complex(-this->m_Real, -this->m_Imag);
}

/// Adds two complex numbers and assigns it to the original variable
/// @param rhs Complex number
/// @return The updated complex number
Complex& Complex::operator+=(const Complex& rhs) {
  this->m_Real += rhs.m_Real;
  this->m_Imag += rhs.m_Imag;
  return *this;
}

/// Subtracts two complex numbers and assigns it to the original variable
/// @param rhs The complex number to subtract
/// @return The updated complex number
Complex& Complex::operator-=(const Complex& rhs) {
  this->m_Real -= rhs.m_Real;
  this->m_Imag -= rhs.m_Imag;
  return *this;
}

/// Multiplies two complex numbers and assigns it to the original variable
/// @param rhs Complex number
/// @return The updated complex number
Complex& Complex::operator*=(const Complex& rhs) {
  const real_t real = this->m_Real * rhs.m_Real - this->m_Imag * rhs.m_Imag;
  this->m_Imag = this->m_Imag * rhs.m_Real + this->m_Real * rhs.m_Imag;
  this->m_Real = real;
  return *this;
}

/// Divides two complex numbers and assigns it to the original variable
/// @param rhs Divisor, complex number
/// @return The updated complex number
Complex& Complex::operator/=(const Complex& rhs) {
  const real_t div = abs2(rhs);
  const real_t real = (this->m_Real * rhs.m_Real + this->m_Imag * rhs.m_Imag) / div;
  this->m_Imag = (this->m_Imag * rhs.m_Real - this->m_Real * rhs.m_Imag) / div;
  this->m_Real = real;
  return *this;
}

/// Adds a real number to a complex number and assigns it to the original variable
/// @param rhs Real number
/// @return The updated complex number
Complex& Complex::operator+=(const real_t rhs) {
  this->m_Real += rhs;
  return *this;
}

/// Subtracts a real number from a complex number and assigns it to the original variable
/// @param rhs Real number
/// @return The updated complex number
Complex& Complex::operator-=(const real_t rhs) {
  this->m_Real -= rhs;
  return *this;
}

/// Multiplies a complex number with a real number and assigns it to the original variable
/// @param rhs Real number
/// @return The updated complex number
Complex& Complex::operator*=(const real_t rhs) {
  this->m_Real *= rhs;
  this->m_Imag *= rhs;
  return *this;
}

/// Divides a complex number by a real number  and assigns it to the original variable
/// @param rhs Real number
/// @return The updated complex number
Complex& Complex::operator/=(const real_t rhs) {
  this->m_Real /= rhs;
  this->m_Imag /= rhs;
  return *this;
}

/// Adds two complex numbers
/// @param lhs Complex number
/// @param rhs Complex number
/// @return The addition of the two complex numbers
Complex operator+(Complex lhs, const Complex& rhs) {
  lhs += rhs;
  return lhs;
}

/// Adds a real number to a complex number
/// @param lhs Complex number
/// @param rhs Real Number
/// @return The addition of the complex and real numbers
Complex operator+(Complex lhs, const real_t rhs) {
  lhs += rhs;
  return lhs;
}

/// Adds a real number to a complex number
/// @param lhs Real Number
/// @param rhs Complex number
/// @return The addition of the complex and real numbers
Complex operator+(const real_t lhs, Complex rhs) {
  rhs += lhs;
  return rhs;
}

/// Subtracts two complex numbers
/// @param lhs Complex number
/// @param rhs Complex number
/// @return The difference of the two complex numbers
Complex operator-(Complex lhs, const Complex& rhs) {
  lhs -= rhs;
  return lhs;
}

/// Subtracts a real number from a complex number
/// @param lhs Complex number
/// @param rhs Real number
/// @return The difference of the two complex numbers
Complex operator-(Complex lhs, const real_t rhs) {
  lhs -= rhs;
  return lhs;
}

/// Subtracts a complex number from a real number
/// @param lhs Real number
/// @param rhs Complex number
/// @return The difference of the two complex numbers
Complex operator-(const real_t lhs, const Complex& rhs) {
  Complex tmp = -rhs;
  tmp += lhs;
  return tmp;
}

/// Multiplies two complex numbers
/// @param lhs Complex number
/// @param rhs Complex number
/// @return The multiplication of the two complex numbers
Complex operator*(Complex lhs, const Complex& rhs) {
  lhs *= rhs;
  return lhs;
}

/// Multiplies a real number and a complex number
/// @param lhs Complex number
/// @param rhs Real number
/// @return The multiplication's result
Complex operator*(Complex lhs, const real_t rhs) {
  lhs *= rhs;
  return lhs;
}

/// Multiplies a complex number and a real number
/// @param lhs Real number
/// @param rhs Complex number
/// @return The multiplication's result
Complex operator*(const real_t lhs, Complex rhs) {
  rhs *= lhs;
  return rhs;
}

/// Divides two complex numbers
/// @param lhs Complex number
/// @param rhs Complex number
/// @return The division of the two complex numbers
Complex operator/(Complex lhs, const Complex& rhs) {
  lhs /= rhs;
  return lhs;
}

/// Divides a complex number by a real number
/// @param lhs Real number
/// @param rhs Complex number
/// @return The division's result
Complex operator/(Complex lhs, const real_t rhs) {
  lhs /= rhs;
  return lhs;
}

/// Divides a real number by a complex number
/// @param lhs Real number
/// @param rhs Complex number
/// @return The division's result
Complex operator/(const real_t lhs, const Complex& rhs) {
  return Complex(lhs, 0) / rhs;
}

/// Converts a complex number to a string
/// @param z Complex number
/// @return The complex number as a string
std::string to_string(const Complex& z) {
  const std::string sign = z.imag() > 0 ? " + " : " - ";
  std::string str = std::to_string(z.real());
  if (std::abs(z.imag()) > EPSILON) {
    str += sign + std::to_string(std::abs(z.imag())) + "i";
  }
  return str;
}

/// Serializes a complex number
std::ostream& operator<<(std::ostream& os, const Complex& z) {
  os << to_string(z);
  return os;
}

/// Prints a complex number in the default output stream
void print(const Complex& z) {
  std::cout << z << '\n';
}

}  // namespace Math

namespace std {

/// Overloads the conversion from a complex number to a string
std::string to_string(const Math::Complex& z) {
  return Math::to_string(z);
}

}  // namespace std