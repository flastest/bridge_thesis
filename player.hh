#include <string>
#include <cstdlib> //for atoi
#include <iostream>   //cout
#include <vector>
#include <algorithm> //for sort

#include "Call.hh"
#include "bridge_card.hh"



#pragma once
// i guess this should contain AI or a weak gui for the user. by gui for the user i mean an ascii thing, much like most of my high school code.

//ascii art is art too!


using hand_t = std::vector<bridge_card>;


class player{
private:

	hand_t player_hand;

public:	
	player(hand_t new_hand) : player_hand(new_hand){ sort_hand(); }
	//legal bids are ones that are greater than the last bid, and XX after X, and X not after X
	Call make_bid(Call last_bid);
	
	void sort_hand();

	void print_hand();

};