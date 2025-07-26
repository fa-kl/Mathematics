#include "Tensor.h"

namespace Math {

Tensor<1> create1DTensor(const size_t rows, const Tensor<1>::value_t& initValue) {
  return Tensor<1>(std::array<size_t, 1>({rows}), initValue);
}

Tensor<2> create2DTensor(const size_t rows, const size_t cols, const Tensor<2>::value_t& initValue) {
  return Tensor<2>(std::array<size_t, 2>({rows, cols}), initValue);
}

Tensor<3> create3DTensor(const size_t first, const size_t second, const size_t third,
                         const Tensor<3>::value_t& initValue) {
  return Tensor<3>(std::array<size_t, 3>({first, second, third}), initValue);
}

Tensor<4> create4DTensor(const size_t first, const size_t second, const size_t third, const size_t fourth,
                         const Tensor<4>::value_t& initValue) {
  return Tensor<4>(std::array<size_t, 4>({first, second, third, fourth}), initValue);
}

}  // namespace Math
