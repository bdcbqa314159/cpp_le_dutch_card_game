#pragma once
#ifndef CARDS_LIB_DECK_HPP
#define CARDS_LIB_DECK_HPP

#include <array>

#include "cards_common.hpp"  // IWYU pragma: keep

namespace cards {

constexpr size_t deck_size = 52;

class InitialDeck {
 private:
  std::array<size_t, deck_size> deck_;

 public:
  InitialDeck();

  size_t operator[](size_t index) const { return deck_[index]; }  // read only

  void shuffle();

  friend std::ostream& operator<<(std::ostream& os, const InitialDeck&);
};

}  // namespace cards

#endif  // CARDS_LIB_DECK_HPP