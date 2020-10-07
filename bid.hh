#include <vector>

// this is like move.hh but with bids
using std::vector<call> as auction_t;

//this is a call, can be a pass or something.
struct call {
// maybe represent a call as 4 byte integer (is that a short?)
// depending on what it's divisible by, that will be the suit for the bidding
// idk i can work that out later
}


static class bid {

	// a collection of all the calls so far that make up the auction
	auction_t auction;

	//a function to determine what legal bids are
	// if there are no possible bids because there are 3 passes in a row, it should return nothing which will end the bidding

	bool isLegal();

	call[] legalMoves();

	//this should add the move to the auction so far
	call makeMove();


	//based off of grandeur, there's a main game loop in move.cpp
	// i guess bid.cc will have a main bidding loop?
	auction_t main_bidding_loop();

}

