#include "bridge_constants.hh"

#pragma once

class bridge_card {
private:
	suit_t _suit;
	int _rank;

public:
	bridge_card(suit_t suit, int rank) : _suit(suit), _rank(rank){};
	suit_t get_suit() {return _suit;}
	int get_rank() {return _rank;}



	friend std::ostream & operator<<(std::ostream &Str, const bridge_card &card);

};







inline std::ostream & operator<<(std::ostream &Str, const bridge_card &card) { 
	
	const char* s = 0;
#define PROCESS_VAL(p) case(p): s = #p; break;
    switch(card._suit){
        PROCESS_VAL(SPADES);     
        PROCESS_VAL(NOTRUMP);     
        PROCESS_VAL(HEARTS);
        PROCESS_VAL(DIAMONDS);     
        PROCESS_VAL(CLUBS); 
    }
#undef PROCESS_VAL
	return Str<<card._rank<<" "<<s;
	
}
