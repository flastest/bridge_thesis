#include "Call.hh"

Call::Call(call_t type, call_def_t def_type, int HCP, distribution dist, int level, suit_t suit) :
	_type(type), _def(def_type), _HCP(HCP), _dist(dist), _level(level), _suit(suit) {}

Call::Call(call_t type) {
	_type = type;
}

Call::Call(int level, suit_t suit)
{
	_type = player_bid;
	_level = level;
	_suit = suit;
}

suit_t Call::get_suit() {
	return _suit;
}

call_t Call::get_call_t() {
	return _type;
}