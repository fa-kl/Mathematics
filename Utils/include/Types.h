#ifndef MATH_TYPES_H
#define MATH_TYPES_H

#include <cstdint>

namespace Math {

// #define MATH_DOUBLE_PRECISION

using size_t = uint32_t;
using index_t = int64_t;
using real_t = double;

constexpr size_t MAX_ELEMENT_COUNT = 10'000'000;
constexpr real_t EPSILON = 1e-9;

/*
using complex_t = std::complex<float>;
template <typename T>
concept scalar = std::is_same_v<T, real_t> || std::is_same_v<T, complex_t>;
*/


}  // namespace Math

#endif  // MATH_TYPES_H
