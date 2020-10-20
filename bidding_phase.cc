#include "bidding_phase.hh"

//implement the stuff in bid.hh


//write the main loop for the bidding, taking into account three passes are bad

bid::bid bidding_phase::makeBid(player p) {
	return p.bid(last_bid);
}


bool bidding_phase::isLegal(bid::bid bid) {
	//also need to include passes and rdbl and dbl
	return bid > auction[auction.size()];
}

bidding_phase::auction_t bidding_phase::main_bidding_loop(player& players) {

	int passes_in_a_row = -1; //takes into account the first turn where there can be 4 passes in a row

	int pid = 0; //this is the starting player id, shouldn't be 0, should be id of whoever is first

	while(passes_in_a_row < 4)
	{
		bid::bid cur_bid = makeBid(players[pid%4]);
		//here you can do stuff if the bid's type is player_bid or something.
		pid++;

		if(cur_bid) == PASS {
			passes_in_a_row++;
		}
		else {
			last_bid = cur_bid;
		}

		auction.push_back(cur_bid);
	}
	return auction; 
}