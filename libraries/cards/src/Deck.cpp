#include "Deck.hpp"  // IWYU pragma: keep

#include <random>

// using namespace utils;
namespace cards {

InitialDeck::InitialDeck() {
  for (size_t i = 0; i < deck_size; ++i) {
    deck_[i] = i;
  }
}

void InitialDeck::shuffle() {
  std::random_device rd;
  std::mt19937 rng(rd());
  std::shuffle(deck_.begin(), deck_.end(), rng);
}

std::ostream& operator<<(std::ostream& os, const InitialDeck& deck) {
  os << "deck: \n";
  os << deck.deck_;
  return os;
}

}  // namespace cards