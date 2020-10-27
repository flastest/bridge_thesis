// this is just a main file
//should create some stuff and start the game
#include "Call.hh"
//#include "move.hh"
#include "bidding_phase.hh"
#include "player.hh"
#include "bridge_deck.hh"





int main(int argc, char* argv[]) {
	(void) argc;
	(void) argv;
	

	bridge_deck deck;
	deck.shuffle_cards();
	std::vector<std::vector<bridge_card>> all_hands = deck.deal(); 

	std::vector<player> players;
	players.push_back(player(all_hands[0]));
	players.push_back(player(all_hands[1]));
	players.push_back(player(all_hands[2]));
	players.push_back(player(all_hands[3]));


	bidding_phase the_bidding(players);

	//initiate bidding
	auction_t auction = the_bidding.main_bidding_loop();
	//find trump suit
	Call last_bid = the_bidding.get_last_bid();


	if (the_bidding.last_bid.get_call_t() == PASS){
		std::cout<<"ok cool we passed out swagalicious"<<std::endl;
		return 0;
	}


	const char* s = 0;
#define PROCESS_VAL(p) case(p): s = #p; break;
	    switch(last_bid.get_suit()){
	        PROCESS_VAL(SPADES);     
	        PROCESS_VAL(NOTRUMP);     
	        PROCESS_VAL(HEARTS);
	        PROCESS_VAL(DIAMONDS);     
	        PROCESS_VAL(CLUBS); 
	    }
#undef PROCESS_VAL

	std::cout<<"trump_suit is "<<s<<std::endl;

	//then using that auction, we have to start the play of the hand

	

	return 0;
}

