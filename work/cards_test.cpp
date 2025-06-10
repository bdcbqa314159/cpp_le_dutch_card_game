#include "cards_lib"  // IWYU pragma: keep
#include "utils_lib"  // IWYU pragma: keep
#include <vector>

using namespace cards;

int main() {
  Card card(Suit::heart, 1);
  std::cout << card << std::endl;

  size_t test = static_cast<size_t>(Suit::club);
  std::cout << "Test: " << test << std::endl;

  size_t counter = 13 * test + 12;
  std::cout << "Counter: " << counter << std::endl;

  Card myKing(Suit::club, 13);
  std::cout << "My King: " << myKing << std::endl;
  std::cout << "My King number: " << get_card_number(myKing) << std::endl;

  size_t number = 45;

  size_t suit = number / 13;
  size_t value = 45 - suit * 13 + 1;
  std::cout << "Suit: " << suit << std::endl;
  std::cout << "Value: " << value << std::endl;
  std::cout << "Card: " << Card(static_cast<Suit>(suit), value) << std::endl;

  Card card_from_number = get_card_from_number(number);
  std::cout << "Card from number: " << card_from_number << std::endl;

  std::vector<Card> cards = {get_card_from_number(12), get_card_from_number(25),
                             get_card_from_number(38),
                             get_card_from_number(51)};

  for (const auto& card : cards) {
    std::cout << "Card: " << card << std::endl;
    std::cout << "Card number: " << get_card_number(card) << std::endl;
    std::cout << "Card points: " << card.get_points() << std::endl;
  }

  return 0;
}