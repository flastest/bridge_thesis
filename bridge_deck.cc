#include "bridge_deck.hh"

void bridge_deck::shuffle_cards() {
	std::random_shuffle ( cards_in_deck.begin(), cards_in_deck.end() );
}

std::vector<std::vector<bridge_card>> deal()
{
	std::vector<bridge_card> hand1;
	std::vector<bridge_card> hand2;
	std::vector<bridge_card> hand3;
	std::vector<bridge_card> hand4;

	std::vector<std::vector<bridge_card>> all_hands;
	all_hands.push_back(hand1);
	all_hands.push_back(hand2);
	all_hands.push_back(hand3);
	all_hands.push_back(hand4);


	for(int c = 0; c < 52; c++) {
		all_hands[c%4].push_back(cards_in_deck[c]);
	}

	return all_hands;
}
