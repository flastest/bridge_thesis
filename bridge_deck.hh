#include "bridge_constants.hh" //for suit_t
#include <vector>
#include <algorithm> 			//for std::random_shuffle
#include <cstdlib>				//for std::rand
#include <ctime>				//for std::time


#pragma once

class bridge_card {
private:
	suit_t _suit;
	int _rank;

public:
	bridge_card(suit_t suit, int rank) : _suit(suit), _rank(rank){};
	suit_t get_suit() {return _suit;}
	int get_rank() {return _rank;}

};


class bridge_deck {
private:
	std::vector<bridge_card> cards_in_deck;

public:
	//constructor should create a deck
	bridge_deck(){
		for (int s = 0; s < 4; s++){
			for (int r = 2; r <= 14; r++) {
				cards_in_deck.push_back(bridge_card(static_cast<suit_t>(s), r));
			}
		}

	}

	void shuffle_cards() {
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


};