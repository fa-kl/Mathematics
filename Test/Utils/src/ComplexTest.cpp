#include "Complex.h"

#include <complex>
#include <gtest/gtest.h>

using namespace Math;

constexpr real_t TEST_EPSILON = 1e-9;

TEST(ComplexTest, DefaultConstructor) {
  const Complex z;
  const std::complex<real_t> std_z;
  EXPECT_DOUBLE_EQ(z.real(), std_z.real());
  EXPECT_DOUBLE_EQ(z.imag(), std_z.imag());
}

TEST(ComplexTest, Constructor) {
  const Complex z1(1, 2);
  const std::complex<real_t> std_z1(1, 2);
  EXPECT_DOUBLE_EQ(z1.real(), std_z1.real());
  EXPECT_DOUBLE_EQ(z1.imag(), std_z1.imag());

  const Complex z2(-1, -2);
  const std::complex<real_t> std_z2(-1, -2);
  EXPECT_DOUBLE_EQ(z2.real(), std_z2.real());
  EXPECT_DOUBLE_EQ(z2.imag(), std_z2.imag());
}

TEST(ComplexTest, CopyConstructor) {
  const Complex z1(1, 2);
  const Complex z2(z1);
  const std::complex<real_t> std_z1(1, 2);
  const std::complex<real_t> std_z2(std_z1);
  EXPECT_DOUBLE_EQ(z2.real(), std_z2.real());
  EXPECT_DOUBLE_EQ(z2.imag(), std_z2.imag());
}

TEST(ComplexTest, CopyOperator) {
  const Complex z1(2, 1);
  const Complex z2 = z1;
  const std::complex<real_t> std_z1(2, 1);
  const std::complex<real_t> std_z2 = std_z1;
  EXPECT_DOUBLE_EQ(z2.real(), std_z2.real());
  EXPECT_DOUBLE_EQ(z2.imag(), std_z2.imag());
}

TEST(ComplexTest, RealFunction) {
  const Complex z(3.5, -2.1);
  const std::complex<real_t> std_z(3.5, -2.1);
  EXPECT_DOUBLE_EQ(real(z), std_z.real());
}

TEST(ComplexTest, ImagFunction) {
  const Complex z(3.5, -2.1);
  const std::complex<real_t> std_z(3.5, -2.1);
  EXPECT_DOUBLE_EQ(imag(z), std_z.imag());
}

TEST(ComplexTest, AbsFunction) {
  const Complex z1(3, 4);
  const std::complex<real_t> std_z1(3, 4);
  EXPECT_DOUBLE_EQ(abs(z1), std::abs(std_z1));

  const Complex z2(-1, -1);
  const std::complex<real_t> std_z2(-1, -1);
  EXPECT_DOUBLE_EQ(abs(z2), std::abs(std_z2));
}

TEST(ComplexTest, Abs2Function) {
  const Complex z1(3, 4);
  const std::complex<real_t> std_z1(3, 4);
  EXPECT_DOUBLE_EQ(abs2(z1), std::norm(std_z1));

  const Complex z2(-1, -1);
  const std::complex<real_t> std_z2(-1, -1);
  EXPECT_DOUBLE_EQ(abs2(z2), std::norm(std_z2));
}

TEST(ComplexTest, ArgFunction) {
  const Complex z1(1, 1);
  const std::complex<real_t> std_z1(1, 1);
  EXPECT_DOUBLE_EQ(arg(z1), std::arg(std_z1));

  const Complex z2(-1, 0);
  const std::complex<real_t> std_z2(-1, 0);
  EXPECT_DOUBLE_EQ(arg(z2), std::arg(std_z2));
}

TEST(ComplexTest, ConjFunction) {
  const Complex z(2, -3);
  const std::complex<real_t> std_z(2, -3);
  const Complex result = conj(z);
  const std::complex<real_t> std_result = std::conj(std_z);
  EXPECT_DOUBLE_EQ(result.real(), std_result.real());
  EXPECT_DOUBLE_EQ(result.imag(), std_result.imag());
}

TEST(ComplexTest, ExpFunction) {
  const Complex z(1, 0.5);
  const std::complex<real_t> std_z(1, 0.5);
  const Complex result = exp(z);
  const std::complex<real_t> std_result = std::exp(std_z);
  EXPECT_NEAR(result.real(), std_result.real(), TEST_EPSILON);
  EXPECT_NEAR(result.imag(), std_result.imag(), TEST_EPSILON);
}

TEST(ComplexTest, LogFunction) {
  const Complex z(2, 1);
  const std::complex<real_t> std_z(2, 1);
  const Complex result = log(z);
  const std::complex<real_t> std_result = std::log(std_z);
  EXPECT_NEAR(result.real(), std_result.real(), TEST_EPSILON);
  EXPECT_NEAR(result.imag(), std_result.imag(), TEST_EPSILON);
}

TEST(ComplexTest, SinFunction) {
  const Complex z(0.5, 0.3);
  const std::complex<real_t> std_z(0.5, 0.3);
  const Complex result = sin(z);
  const std::complex<real_t> std_result = std::sin(std_z);
  EXPECT_NEAR(result.real(), std_result.real(), TEST_EPSILON);
  EXPECT_NEAR(result.imag(), std_result.imag(), TEST_EPSILON);
}

TEST(ComplexTest, CosFunction) {
  const Complex z(0.5, 0.3);
  const std::complex<real_t> std_z(0.5, 0.3);
  const Complex result = cos(z);
  const std::complex<real_t> std_result = std::cos(std_z);
  EXPECT_NEAR(result.real(), std_result.real(), TEST_EPSILON);
  EXPECT_NEAR(result.imag(), std_result.imag(), TEST_EPSILON);
}

TEST(ComplexTest, TanFunction) {
  const Complex z(0.5, 0.3);
  const std::complex<real_t> std_z(0.5, 0.3);
  const Complex result = tan(z);
  const std::complex<real_t> std_result = std::tan(std_z);
  EXPECT_NEAR(result.real(), std_result.real(), TEST_EPSILON);
  EXPECT_NEAR(result.imag(), std_result.imag(), TEST_EPSILON);
}

TEST(ComplexTest, AsinFunction) {
  const Complex z(0.5, 0.3);
  const std::complex<real_t> std_z(0.5, 0.3);
  const Complex result = asin(z);
  const std::complex<real_t> std_result = std::asin(std_z);
  EXPECT_NEAR(result.real(), std_result.real(), TEST_EPSILON);
  EXPECT_NEAR(result.imag(), std_result.imag(), TEST_EPSILON);
}

TEST(ComplexTest, AcosFunction) {
  const Complex z(0.5, 0.3);
  const std::complex<real_t> std_z(0.5, 0.3);
  const Complex result = acos(z);
  const std::complex<real_t> std_result = std::acos(std_z);
  EXPECT_NEAR(result.real(), std_result.real(), TEST_EPSILON);
  EXPECT_NEAR(result.imag(), std_result.imag(), TEST_EPSILON);
}

TEST(ComplexTest, AtanFunction) {
  const Complex z(0.5, 0.3);
  const std::complex<real_t> std_z(0.5, 0.3);
  const Complex result = atan(z);
  const std::complex<real_t> std_result = std::atan(std_z);
  EXPECT_NEAR(result.real(), std_result.real(), TEST_EPSILON);
  EXPECT_NEAR(result.imag(), std_result.imag(), TEST_EPSILON);
}

TEST(ComplexTest, SqrtFunction) {
  const Complex z(4, 3);
  const std::complex<real_t> std_z(4, 3);
  const Complex result = sqrt(z);
  const std::complex<real_t> std_result = std::sqrt(std_z);
  EXPECT_NEAR(result.real(), std_result.real(), TEST_EPSILON);
  EXPECT_NEAR(result.imag(), std_result.imag(), TEST_EPSILON);
}

/*
TEST(ComplexTest, EqualityOperator) {
  const Complex z1(1, 2);
  const Complex z2(1, 2);
  const Complex z3(2, 1);
  EXPECT_TRUE(z1 == z2);
  EXPECT_FALSE(z1 == z3);
}

TEST(ComplexTest, InequalityOperator) {
  const Complex z1(1, 2);
  const Complex z2(2, 1);
  const Complex z3(1, 2);
  EXPECT_TRUE(z1 != z2);
  EXPECT_FALSE(z1 != z3);
}
*/

TEST(ComplexTest, AdditionOperatorComplexComplex) {
  const Complex z1(1, 2);
  const Complex z2(3, 4);
  const std::complex<real_t> std_z1(1, 2);
  const std::complex<real_t> std_z2(3, 4);
  const Complex result = z1 + z2;
  const std::complex<real_t> std_result = std_z1 + std_z2;
  EXPECT_DOUBLE_EQ(result.real(), std_result.real());
  EXPECT_DOUBLE_EQ(result.imag(), std_result.imag());
}

TEST(ComplexTest, AdditionOperatorComplexReal) {
  const Complex z(1, 2);
  const real_t r = 3;
  const std::complex<real_t> std_z(1, 2);
  const Complex result = z + r;
  const std::complex<real_t> std_result = std_z + r;
  EXPECT_DOUBLE_EQ(result.real(), std_result.real());
  EXPECT_DOUBLE_EQ(result.imag(), std_result.imag());
}

TEST(ComplexTest, AdditionOperatorRealComplex) {
  const real_t r = 3;
  const Complex z(1, 2);
  const std::complex<real_t> std_z(1, 2);
  const Complex result = r + z;
  const std::complex<real_t> std_result = r + std_z;
  EXPECT_DOUBLE_EQ(result.real(), std_result.real());
  EXPECT_DOUBLE_EQ(result.imag(), std_result.imag());
}

TEST(ComplexTest, SubtractionOperatorComplexComplex) {
  const Complex z1(5, 6);
  const Complex z2(1, 2);
  const std::complex<real_t> std_z1(5, 6);
  const std::complex<real_t> std_z2(1, 2);
  const Complex result = z1 - z2;
  const std::complex<real_t> std_result = std_z1 - std_z2;
  EXPECT_DOUBLE_EQ(result.real(), std_result.real());
  EXPECT_DOUBLE_EQ(result.imag(), std_result.imag());
}

TEST(ComplexTest, SubtractionOperatorComplexReal) {
  const Complex z(5, 2);
  const real_t r = 3;
  const std::complex<real_t> std_z(5, 2);
  const Complex result = z - r;
  const std::complex<real_t> std_result = std_z - r;
  EXPECT_DOUBLE_EQ(result.real(), std_result.real());
  EXPECT_DOUBLE_EQ(result.imag(), std_result.imag());
}

TEST(ComplexTest, SubtractionOperatorRealComplex) {
  const real_t r = 5;
  const Complex z(1, 2);
  const std::complex<real_t> std_z(1, 2);
  const Complex result = r - z;
  const std::complex<real_t> std_result = r - std_z;
  EXPECT_DOUBLE_EQ(result.real(), std_result.real());
  EXPECT_DOUBLE_EQ(result.imag(), std_result.imag());
}

TEST(ComplexTest, MultiplicationOperatorComplexComplex) {
  const Complex z1(1, 2);
  const Complex z2(3, 4);
  const std::complex<real_t> std_z1(1, 2);
  const std::complex<real_t> std_z2(3, 4);
  const Complex result = z1 * z2;
  print(result);
  const std::complex<real_t> std_result = std_z1 * std_z2;
  std::cout << std_result << '\n';
  EXPECT_DOUBLE_EQ(result.real(), std_result.real());
  EXPECT_DOUBLE_EQ(result.imag(), std_result.imag());
}

TEST(ComplexTest, MultiplicationOperatorComplexReal) {
  const Complex z(1, 2);
  const real_t r = 3;
  const std::complex<real_t> std_z(1, 2);
  const Complex result = z * r;
  const std::complex<real_t> std_result = std_z * r;
  EXPECT_DOUBLE_EQ(result.real(), std_result.real());
  EXPECT_DOUBLE_EQ(result.imag(), std_result.imag());
}

TEST(ComplexTest, MultiplicationOperatorRealComplex) {
  const real_t r = 3;
  const Complex z(1, 2);
  const std::complex<real_t> std_z(1, 2);
  const Complex result = r * z;
  const std::complex<real_t> std_result = r * std_z;
  EXPECT_DOUBLE_EQ(result.real(), std_result.real());
  EXPECT_DOUBLE_EQ(result.imag(), std_result.imag());
}

TEST(ComplexTest, DivisionOperatorComplexComplex) {
  const Complex z1(10, 5);
  const Complex z2(2, 1);
  const std::complex<real_t> std_z1(10, 5);
  const std::complex<real_t> std_z2(2, 1);
  const Complex result = z1 / z2;
  const std::complex<real_t> std_result = std_z1 / std_z2;
  EXPECT_NEAR(result.real(), std_result.real(), TEST_EPSILON);
  EXPECT_NEAR(result.imag(), std_result.imag(), TEST_EPSILON);
}

TEST(ComplexTest, DivisionOperatorComplexReal) {
  const Complex z(6, 4);
  const real_t r = 2;
  const std::complex<real_t> std_z(6, 4);
  const Complex result = z / r;
  const std::complex<real_t> std_result = std_z / r;
  EXPECT_DOUBLE_EQ(result.real(), std_result.real());
  EXPECT_DOUBLE_EQ(result.imag(), std_result.imag());
}

TEST(ComplexTest, DivisionOperatorRealComplex) {
  const real_t r = 6;
  const Complex z(2, 1);
  const std::complex<real_t> std_z(2, 1);
  const Complex result = r / z;
  const std::complex<real_t> std_result = r / std_z;
  EXPECT_NEAR(result.real(), std_result.real(), TEST_EPSILON);
  EXPECT_NEAR(result.imag(), std_result.imag(), TEST_EPSILON);
}