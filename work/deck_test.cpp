#include <cstddef>
#include <iostream>
#include <stack>  // IWYU pragma: keep

#include "cards_lib"  // IWYU pragma: keep
#include "utils_lib"  // IWYU pragma: keep

using namespace cards;

int main() {
  InitialDeck deck;
  // std::cout << "before shuffle: " << deck << std::endl;
  deck.shuffle();
  // std::cout << "after shuffle: " << deck << std::endl;

  std::stack<Card> deck_stack_hidden;
  std::stack<Card> deck_stack_visible;

  for (size_t i = 0; i < deck_size; ++i) {
    deck_stack_hidden.push(deck[i]);
  }

  Card card = deck_stack_hidden.top();
  deck_stack_hidden.pop();
  card.turn_card();
  deck_stack_visible.push(std::move(card));

  std::cout << deck_stack_visible.top() << " >" << std::endl;

  //"table: < " << deck_stack_hidden.top() << " "
  return 0;
}