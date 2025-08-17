#pragma once
#ifndef CARDS_LIB_COMMON_HPP
#define CARDS_LIB_COMMON_HPP

#include <array>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#endif

namespace cards {

// to be able to cout u8string:
std::ostream& operator<<(std::ostream&, const std::u8string&);

enum class Suit : size_t { heart, diamond, spade, club };

std::ostream& operator<<(std::ostream&, const Suit&);

template <typename T, size_t size>
std::ostream& operator<<(std::ostream& os, const std::array<T, size>& arr) {
  os << "[";
  for (size_t i = 0; i < size; ++i) {
    os << arr[i];
    if (i < size - 1) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}

}  // namespace cards

#endif  // CARDS_LIB_COMMON_HPP