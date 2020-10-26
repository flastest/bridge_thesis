#include <string>
#include <cstdlib> //for atoi
//#include <iostream>   //cout
#include "Call.hh"


#pragma once
// i guess this should contain AI or a weak gui for the user. by gui for the user i mean an ascii thing, much like most of my high school code.

//ascii art is art too!



class player{
public:	
	player(){}
	//legal bids are ones that are greater than the last bid, and XX after X, and X not after X
	Call make_bid(Call last_bid);
	

};