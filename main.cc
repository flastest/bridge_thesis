// this is just a main file
//should create some stuff and start the game
#include "bid.hh"
#include "move.hh"
#include "bidding_phase.hh"





int main(int argc, char** argv) {
	// shuffle the deck
	//deal


	//initiate bidding
	bidding_phase::auction_t auction = bidding_phase.main_bidding_loop();
	//find trump suit
	bid::suit_t trump_suit = bidding_phase.get_last_bid().get_suit(); 

	//then using that auction, we have to start the play of the hand

	

	return 0;
}

