


struct distribution {
	int s_start = 0;
	int s_end = 0;
	int h_start = 0;
	int h_end = 0;
	int d_start = 0;
	int d_end = 0;
	int c_start = 0;
	int c_end = 0;


	//tells you if a hand is within range of this distribution
	//this will be super hard for something like NT
	bool iswithinrange(int s_count, int h_count, int d_count, int c_count);
}

//this defines a bid
//each bid should have a meaning, regardless to who played it

class bid {
	enum type_t { playerr_bid, opening, PASS, X, XX, overcall, response };
	enum type_def_t { 1NT, stayman, jacoby_transfer };
	enum suit_t {c,d,h,s,nt};


	//type of bid- this should be opening response or overcall
	type_t _type; //in a perfect world, this is only one bit

	type_def_t _def;

	int _HCP;

	distribution _dist;

	int _level;

	suit_t _suit;


	//adds a bid to the bidding system
	//type defines whether it's an overcall, response, or opening bid
	//def_type defines the type (if this bid is a response, def_type tells you what you're responding to)
	//HCP is self explanatory
	//dist is the sort of distribution you need to make this bid
	//level is the level of the bid, suit is the suit of the bid (level = 7, suit = s for 7S)
	bid(type_t type, type_def_t def_type, int HCP, distribution dist, int level, suit_t suit);

	bid(type_t type);

	// this constructs a bid from a suit type, and a level.
	bid(int level, suit_t suit);

	//this writes itself somewhere. should compress the bid. can figure out how to do that later.
	void write_bid();

	//from some input, converts it into a bid
	void initialize(std::string input);

	suit_t get_suit();





}

//operator overloads 
inline std::ostream & operator<<(std::ostream &Str, Object const &bid) { 
	// print something from v to str, e.g: Str << v.getX();
	Str<<bid._level<<" "<<bid._suit;
	return Str;
}


inline bool bid::operator==(const bid& lhs, const bid& rhs) 
{	
	if (lhs.type == rhs.type)
	{
		if (lhs.type != PASS || lhs.type != X || lhs.type != XX){
			return (lhs._suit == rhs._suit && lhs._level == rhs._level);
		}
		return true;
	}
	return false;
}


// TODO: the following need cases for XX and X!
inline bool bid::operator<(const bid& lhs, const bid& rhs) 
{
	return (lhs._suit < rhs._suit && lhs._level < rhs._level);
}

inline bool bid::operator>(const bid& lhs, const bid& rhs) 
{	
	return (lhs._suit > rhs._suit && lhs._level > rhs._level);
}