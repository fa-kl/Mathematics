#ifndef MATH_TENSOR_H
#define MATH_TENSOR_H

#include "Complex.h"

#include <array>
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

#include "Error.h"

namespace Math {

template <size_t N, class T = real_t>
class Tensor {
public:
  using value_t = T;
  using pointer_t = value_t*;
  using reference_t = value_t&;
  using dimension_t = std::array<size_t, N>;

protected:
  // Array holding the number of rows, columns and other dimensions
  dimension_t m_Dimensions;
  // Unique pointer to an array holding the tensor's data
  std::unique_ptr<value_t[]> m_Data;
  // Array holding the offsets for linear index computations
  dimension_t m_Offsets;
  // Total number of elements
  size_t m_TotalNumberOfElements;

  [[nodiscard]] size_t getLinearIndex(const dimension_t& indices) const {
    if constexpr (N == 0) {
      throw Error("Cannot access an empty object");
    }
    size_t linearIndex = 0;
    for (uint i = 0; i < N; ++i) {
      linearIndex += indices[i] * m_Offsets[i];
    }
    return linearIndex;
  }

public:
  explicit Tensor(std::array<size_t, N> dims, value_t initValue = value_t()) : m_Dimensions(dims) {
    // compute total number of elements
    m_TotalNumberOfElements = m_Dimensions[0];
    for (size_t i = 1; i < N; ++i) {
      m_TotalNumberOfElements *= m_Dimensions[i];
    }
    if (m_TotalNumberOfElements > MAX_ELEMENT_COUNT) {
      throw Error("Maximum element count exceeded");
    }
    // fill data with indices for now
    m_Data = std::make_unique<value_t[]>(m_TotalNumberOfElements);
    for (size_t i = 0; i < m_TotalNumberOfElements; ++i) {
      m_Data[i] = i;  // TODO: m_Data[i] = initValue;
    }
    // compute offsets
    if constexpr (N > 0) {
      m_Offsets[0] = 1;
    }
    for (size_t i = 1; i < N; ++i) {
      m_Offsets[i] = m_Offsets[i - 1] * m_Dimensions[i - 1];
    }
  }

  size_t rows() const { return m_Dimensions[0]; }

  size_t cols() const { return m_Dimensions[1]; }

  size_t dim(size_t i) const {
    if (0 < i && i <= N) {
      return m_Dimensions[i - 1];
    }
    throw Error("Invalid dimension.\nNote: This function expects a 1-based index.");
  }

  std::array<size_t, N> dims() const { return m_Dimensions; }

  size_t numel() const { return m_TotalNumberOfElements; }

  template <typename... Args>
  reference_t operator()(Args... indices)
    requires(sizeof...(indices) == N)
  {
    std::array<size_t, N> indexArray{static_cast<size_t>(indices)...};
    return m_Data[getLinearIndex(indexArray)];
  }

  template <typename... Args>
  const reference_t operator()(Args... indices) const
    requires(sizeof...(indices) == N)
  {
    std::array<size_t, N> indexArray{static_cast<size_t>(indices)...};
    return m_Data[getLinearIndex(indexArray)];
  }

  template <size_t M>
  friend void print(const Tensor<M>& tensor);
};

Tensor<1> create1DTensor(size_t rows, const Tensor<1>::value_t& initValue = Tensor<1>::value_t());

Tensor<2> create2DTensor(size_t rows, size_t cols, const Tensor<2>::value_t& initValue = Tensor<2>::value_t());

Tensor<3> create3DTensor(size_t first, size_t second, size_t third,
                         const Tensor<3>::value_t& initValue = Tensor<3>::value_t());

Tensor<4> create4DTensor(size_t first, size_t second, size_t third, size_t fourth,
                         const Tensor<4>::value_t& initValue = Tensor<4>::value_t());

template <size_t N>
void print(const Tensor<N>& tensor) {
  std::cout << N << "D-Tensor (" << tensor.numel() << " elements)""\n\n";
  if constexpr (N == 1) {
    for (size_t row = 0; row < tensor.numel(); ++row) {
      std::cout << tensor(row) << "\n";
    }
  }
  if constexpr (N == 2) {
    for (size_t row = 0; row < tensor.rows(); ++row) {
      for (size_t col = 0; col < tensor.cols(); ++col) {
        std::cout << tensor(row, col) << " ";
      }
      std::cout << "\n";
    }
  }
  if constexpr (N >= 3) {

  }
  std::cout << "\n";
}

}  // namespace Math

#endif  // MATH_TENSOR_H
