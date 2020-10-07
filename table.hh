// this is like "board" in grandeur in that it keeps track of all the players


//should keep track of player order and stuff
// probably does what my main for my 2017 bridge code does. yeah. for sure. 


//i feel bad, but I think I'd have to copy eitan's move status thing from grandeur. but i kind wanna come up with something myself.

using short as score_t;

class table{


	void shuffle_deck();

	void deal();

	// idk what this would do, but I'm sure the players will need to be initialized somehow
	void initialize_players();

	bid::call format_bidding_box(); // probably needs to interface with the user/ai what the possible bids are

	void format_cards(card::card[]);

	//ambitious: 
	void initialize_convention_card();

	//even more ambitious:
	void decorate_convention_card_holder();

	bid::auction_t start_bidding();
	// this will call "main bidding loop" in bid.hh

	// this will have to change, I'm not sure what it would do. I am so unsure of myself!!!
	score_t start_the_play(); //i think this is a good place to keep track of things
	// this will call "main_playing_loop" in move.hh

	//what else should this do...
}


