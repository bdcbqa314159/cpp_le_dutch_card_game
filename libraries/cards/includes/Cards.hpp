#pragma once
#include <cstddef>
#ifndef CARDS_LIB_CARDS_HPP
#define CARDS_LIB_CARDS_HPP
#include <cassert>

#include "cards_common.hpp"  // IWYU pragma: keep

namespace cards {

class Card {
 public:
  Card() = default;
  Card(Suit suit, size_t value);
  Card(size_t);

  Suit get_suit() const;

  size_t get_value() const;

  size_t get_number() const;

  size_t get_points() const;

  bool is_hidden() const;

  friend std::ostream& operator<<(std::ostream& os, const Card& card);
  void turn_card();

 private:
  Suit suit_{0};
  size_t value_{0};
  bool hidden_{true};
};

size_t get_card_number(const Card&);

Card get_card_from_number(size_t);

}  // namespace cards

#endif  // CARDS_LIB_CARDS_HPP