namespace array_helpers {
  template <size_t N, size_t...Elements>
  struct generateNumArray {
    constexpr static auto values = generateNumArray<N - 1, N, Elements...>::values;
  };
  template <size_t...Elements>
  struct generateNumArray<0, Elements...> {
    constexpr static auto values = std::make_tuple(0, Elements...);
  };
  template <typename Array, size_t Index = 0>
  auto printArr(Array const& arr)->void {
    if constexpr (Index < std::tuple_size_v<Array>) {
      std::cout << std::get<Index>(arr) << std::endl;
      printArr<Array, Index + 1>(arr);
    }
  }
}
int main() {
  array_helpers::printArr(array_helpers::generateNumArray<10>::values);
  size_t exitCode{};
  while (exitCode != 1)
    std::cin >> exitCode;
}