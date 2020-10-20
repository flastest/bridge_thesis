#include <vector>
#include "bid.hh"

// this is like move.hh but with bids
using std::vector<bid::bid> as auction_t;

//this is a call, can be a pass or something.
struct call {
// maybe represent a call as 4 byte integer (is that a short?)
// depending on what it's divisible by, that will be the suit for the bidding
// idk i can work that out later
}


static class bidding_phase {
	const bid::bid PASS = bid::bid(bid::type_t(PASS));


	// a collection of all the calls so far that make up the auction
	auction_t auction;

	bid::bid last_bid;

	//a function to determine what legal bids are
	// if there are no possible bids because there are 3 passes in a row, it should return nothing which will end the bidding
	bool isLegal(bid::bid bid);


	//this should add the move to the auction so far
	bid::bid makeBid(player p);


	//based off of grandeur, there's a main game loop in move.cpp
	// i guess bid.cc will have a main bidding loop?
	//returns an auction_t so that an AI player knows how to play
	auction_t main_bidding_loop(player& players);

	bid::bid get_last_bid() { return last_bid; }

}

