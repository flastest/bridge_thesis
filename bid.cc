#include "bid.hh"

//implement the stuff in bid.hh


//write the main loop for the bidding, taking into account three passes are bad




bid::auction_t bid::main_bidding_loop() {
	auction_t auction;
	while(!three_passes_in_a_row)
	{
		//calculate bid and or recieve it as input from user and add to auction
		auction.push_back(makeMove());
	}
	return auction; 
}