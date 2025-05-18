#include <array>
#include <cstddef>
#include <iostream>
#include <random>
#include <stack>  // IWYU pragma: keep

#include "cards_lib"  // IWYU pragma: keep
#include "utils_lib"  // IWYU pragma: keep

using namespace cards;

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

int main() {
  constexpr size_t deck_size = 52;
  std::array<int, deck_size> deck;

  for (size_t i = 0; i < deck_size; ++i) {
    deck[i] = i;
  }

  std::cout << "Deck before shuffle: " << deck << std::endl;

  std::random_device rd;
  std::mt19937 rng(rd());
  std::shuffle(deck.begin(), deck.end(), rng);

  std::cout << "Deck after shuffle: " << deck << std::endl;

  std::stack<size_t> deck_stack_hidden;
  std::stack<size_t> deck_stack_visible;

  for (size_t i = 0; i < deck_size; ++i) {
    deck_stack_hidden.push(deck[i]);
  }

  size_t element = deck_stack_hidden.top();
  deck_stack_hidden.pop();

  std::cout << "Top element: " << element << std::endl;
  Card card = get_card_from_number(element);

  std::cout << "Card: " << card << std::endl;
  card.turn_card();
  std::cout << "Card after turn: " << card << std::endl;

  return 0;
}