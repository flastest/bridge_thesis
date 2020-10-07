// this should deterine who gets to play next, along with who wins the trick and maybe keeps track of the score
// this calculates all possible moves too, should be helpful when having a player play only legal moves and can help AI decide what moves it can make.


static class move {

	//first include card or deck or whatever contains the cards
	


	//a function to determine what legal bids are
	// if there are no possible bids because there are 3 passes in a row, it should return nothing which will end the bidding

	bool isLegal();

	card::card[] legalMoves();

	//this should add the move to the auction so far
	call makeMove();


	//based off of grandeur, there's a main game loop in move.cpp
	// i guess bid.cc will have a main bidding loop?
	auction_t main_playing_loop();

}






