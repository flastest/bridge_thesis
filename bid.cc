#include "bid.hh"

bid::bid(type_t type, type_def_t def_type, int HCP, distribution dist, int level, suit_t suit) :
	_type(type), _def(def_type), _HCP(HCP), _dist(dist), _level(level), _suit(suit) {}

bid::bid(type_t type) {
	_type = type;
}

bit::bid(int level, suit_t suit)
{
	_type = player_bid;
	_level = level;
	_suit = suit;
}

bid::get_suit() {
	return _suit;
}