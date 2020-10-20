#include <player.hh>


bid::bid player::bid (bid::bid last_bid) {
	//player has to choose a bid that's larger than the last bid, or legal.
	std::cout<<"yo what do u want to bid the last bid was "<<last_bid<<std::endl;
	std::cout<<"bidding is like 'PASS' or 'X' or '3S' or '1N'"<<std::endl;
	std::string bid_s;
	std::cin>>bid_s;

	bid::bid bid_to_play;
	bool legal = false;
	while(!legal) {
		if(bid_s.compare("PASS") == 0 || bid_s.compare("pass") == 0 || bid_s.compare("P") == 0 || bid_s.compare("p") == 0) 
		{
			bid_to_play = bid::bid(bid::type_t(PASS));
			legal = true;
			break;
		}
		if(bid_s.compare("X") == 0 || bid_s.compare("dbl") == 0 || bid_s.compare("double") == 0) 
		{
			bid_to_play = bid::bid(bid::type_t(X));
			legal = true;
			break;
		}
		if(bid_s.compare("XX") == 0 || bid_s.compare("rdbl") == 0 || bid_s.compare("redouble") == 0) 
		{
			bid_to_play = bid::bid(bid::type_t(X));
			legal = true;
			break;
		}
		//convert bid to numbers and stuff
		if(bid_s.length() == 2) {
			int level = atoi(bid_s.at(0));
			char suit = bid_s.at(1);
			if (suit == 's' || suit == 'S' || ) {
				bid_to_play = bid::bid(level, bid::suit_t(s));
			}
			if (suit == 'h' || suit == 'H' || ) {
				bid_to_play = bid::bid(level, bid::suit_t(h));
			}
			if (suit == 'd' || suit == 'D' || ) {
				bid_to_play = bid::bid(level, bid::suit_t(d));
			}
			if (suit == 'c' || suit == 'C' || ) {
				bid_to_play = bid::bid(level, bid::suit_t(s));
			}
			if (suit == 'n' || suit == 'N' || ) {
				bid_to_play = bid::bid(level, bid::suit_t(nt));
			}
			if (bid_to_play > last_bid) {
				legal = true;
			}

		}

	}
	return bid_to_play;


}