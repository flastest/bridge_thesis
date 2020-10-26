#include "player.hh"

//make this abstract like grandeur


Call player::make_bid (Call last_bid) {
	//player has to choose a bid that's larger than the last bid, or legal.
	
	std::string bid_s;
	

	Call bid_to_play;
	bool legal = false;
	while(!legal) {
		std::cout<<"yo what do u want to bid the last bid was "<<last_bid<<std::endl;
		std::cout<<"bidding is like 'PASS' or 'X' or '3S' or '1N'"<<std::endl;

		std::cin>>bid_s;
		if(bid_s.compare("PASS") == 0 || bid_s.compare("pass") == 0 || bid_s.compare("P") == 0 || bid_s.compare("p") == 0) 
		{
			//std::cout <<"YO THAT'S A PASS!\n";
			bid_to_play.set_call(PASS);
			//std::cout<<"bid_to_play is "<<bid_to_play<<std::endl;
			legal = true;
			break;
		}
		if(bid_s.compare("X") == 0 || bid_s.compare("dbl") == 0 || bid_s.compare("double") == 0) 
		{
			bid_to_play.set_call(X);
			legal = true;
			break;
		}
		if(bid_s.compare("XX") == 0 || bid_s.compare("rdbl") == 0 || bid_s.compare("redouble") == 0) 
		{
			bid_to_play.set_call(X);
			legal = true;
			break;
		}
		//convert bid to numbers and stuff
		if(bid_s.length() == 2) {
			int level = stoi(bid_s.substr(0,1));
			char suit = bid_s.at(1);
			std::cout << "current bid is "<< level << suit <<std::endl;
			if (suit == 's' || suit == 'S' ) {
				bid_to_play.set_call(level, SPADES);
			}
			if (suit == 'h' || suit == 'H' ) {
				bid_to_play.set_call(level, HEARTS);
			}
			if (suit == 'd' || suit == 'D' ) {
				bid_to_play.set_call(level, DIAMONDS);
			}
			if (suit == 'c' || suit == 'C' ) {
				bid_to_play.set_call(level, CLUBS);
			}
			if (suit == 'n' || suit == 'N' ) {
				bid_to_play.set_call(level, NOTRUMP);
			}
			if (bid_to_play > last_bid) {
				std::cout <<"bid to play is [" << bid_to_play<<"] last bid is [" << last_bid<<"]"<<std::endl;
				legal = true;
			}

		}
		if (!legal) std::cout <<"that is not a legal bid! try again\n";

	}
	return bid_to_play;


}