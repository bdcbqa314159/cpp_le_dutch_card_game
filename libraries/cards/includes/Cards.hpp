#pragma once
#ifndef CARDS_LIB_CARDS_HPP
#define CARDS_LIB_CARDS_HPP
#include <cassert>

#include "cards_common.hpp"  // IWYU pragma: keep

namespace cards {

class Card {
 public:
  Card(Suit suit, size_t value);

  Suit get_suit() const;

  size_t get_value() const;

  size_t get_points() const;

  bool is_hidden() const;
  void turn_card();

  friend std::ostream& operator<<(std::ostream& os, const Card& card);

 private:
  Suit suit_;
  size_t value_;
  bool hidden_;
};

size_t get_card_number(const Card&);

Card get_card_from_number(size_t);

}  // namespace cards

#endif  // CARDS_LIB_CARDS_HPP