#include "Cards.hpp"  // IWYU pragma: keep

namespace cards {

Card::Card(Suit suit, size_t value) : suit_(suit), value_(value) {
  assert(value >= 1 && value <= 13);
  hidden_ = true;
}

bool Card::is_hidden() const { return hidden_; }

void Card::turn_card() { hidden_ = !hidden_; }

Suit Card::get_suit() const { return suit_; }

size_t Card::get_value() const { return value_; }

size_t Card::get_points() const {
  if (value_ == 13 && (suit_ == Suit::heart || suit_ == Suit::diamond)) {
    return 0;
  }
  return get_value();
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
  std::string value_str;

  if (card.is_hidden()) {
    os << "??";
    return os;
  }

  if (card.value_ == 1) {
    value_str = "A";
  } else if (card.value_ == 11) {
    value_str = "J";
  } else if (card.value_ == 12) {
    value_str = "Q";
  } else if (card.value_ == 13) {
    value_str = "K";
  } else {
    value_str = std::to_string(card.value_);
  }
  os << value_str << card.suit_;
  return os;
}

size_t get_card_number(const Card& card) {
  size_t suit = static_cast<size_t>(card.get_suit());
  size_t value = card.get_value();
  return suit * 13 + value - 1;
}

// careful with this as it will create a full copy of the card
Card get_card_from_number(size_t number) {
  assert(number >= 0 && number < 52);
  size_t suit = number / 13;
  size_t value = number - suit * 13 + 1;
  return Card(static_cast<Suit>(suit), value);
}
}  // namespace cards