#include <string>
#include <iostream>
#include "bridge_constants.hh" //for suit_t

#pragma once

enum call_t { PLAYER_BID, OPENING, PASS, X, XX, OVERCALL, RESPONSE };


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
};

//this defines a Call
//each Call should have a meaning, regardless to who played it


class Call {
	//this defines the call further... will implement later
	enum call_def_t { NT, stayman, jacoby_transfer };
	


	//type of Call- this should be opening response or overcall
	call_t _call_type; //in a perfect world, this is only one bit

	call_def_t _def;

	int _HCP;

	distribution _dist;

	int _level;

	suit_t _suit;

public:

	Call() {}

	//adds a Call to the bidding system
	//type defines whether it's an overcall, response, or opening Call
	//def_call_type defines the type (if this Call is a response, def_call_type tells you what you're responding to)
	//HCP is self explanatory
	//dist is the sort of distribution you need to make this Call
	//level is the level of the Call, suit is the suit of the Call (level = 7, suit = s for 7S)
	Call(call_t type, call_def_t def_call_type, int HCP, distribution dist, int level, suit_t suit);

	Call(call_t type);

	// this constructs a Call from a suit type, and a level.
	// used for when a player makes a call, this constructor automatically
	// assumes that this is a player's bid
	Call(int level, suit_t suit);

	//this writes itself somewhere. should compress the Call. can figure out how to do that later.
	void write_Call();

	//from some input, converts it into a Call
	void initialize(std::string input);

	suit_t get_suit();

	call_t get_call_t();

	void set_call(call_t call) { _call_type = call; }
	void set_call(int level, suit_t suit) { _level = level; _suit = suit; }

	friend std::ostream & operator<<(std::ostream &Str, const Call &bid);
	friend bool operator==(const Call& lhs, const Call& rhs);
	friend bool operator<(const Call& lhs, const Call& rhs);
	friend bool operator>(const Call& lhs, const Call& rhs); 
};

//operator overloads 
inline std::ostream & operator<<(std::ostream &Str, const Call &bid) { 
	//TODO: cases for pass and doublw
	if(bid._call_type == X || bid._call_type == XX || bid._call_type == PASS) 
	{ 
		const char* s = 0;
#define PROCESS_VAL(p) case(p): s = #p; break;
	    switch(bid._call_type){
	        PROCESS_VAL(X);     
	        PROCESS_VAL(XX);     
	        PROCESS_VAL(PASS);
	        PROCESS_VAL(PLAYER_BID);     
	        PROCESS_VAL(OVERCALL);     
	        PROCESS_VAL(RESPONSE);
	        PROCESS_VAL(OPENING);
	    }
#undef PROCESS_VAL
    	return Str << s;
		//Str<<bid._call_type;
	}
	else 
	{
		const char* s = 0;
#define PROCESS_VAL(p) case(p): s = #p; break;
	    switch(bid._suit){
	        PROCESS_VAL(SPADES);     
	        PROCESS_VAL(NOTRUMP);     
	        PROCESS_VAL(HEARTS);
	        PROCESS_VAL(DIAMONDS);     
	        PROCESS_VAL(CLUBS); 
	    }
#undef PROCESS_VAL
		return Str<<bid._level<<" "<<s;
	}
	return Str;
}

inline bool operator==(const Call& lhs, const Call& rhs) 
{	
	if (lhs._call_type == rhs._call_type)
	{
		if (lhs._call_type != PASS || lhs._call_type != X || lhs._call_type != XX){
			return (lhs._suit == rhs._suit && lhs._level == rhs._level);
		}
		return true;
	}
	return false;
}


// TODO: the following need cases for XX and X!
inline bool operator<(const Call& lhs, const Call& rhs) 
{
	if (rhs._call_type == XX) return lhs._call_type == X; 
	if (rhs._call_type == X) return lhs._call_type != X || lhs._call_type != PASS || lhs._call_type != XX;
	if (rhs._call_type == PASS) return true;
	if (lhs._call_type == PASS) return true;

	if (lhs._level < rhs._level) return true;
	if (lhs._level == rhs._level) return lhs._suit < rhs._suit;
	return false;
}

inline bool operator>(const Call& lhs, const Call& rhs) 
{	
	if (lhs._call_type == XX) return rhs._call_type == X; 
	if (lhs._call_type == X) return rhs._call_type != X || rhs._call_type != PASS || rhs._call_type != XX;
	if (lhs._call_type == PASS) return true;
	if (rhs._call_type == PASS) return true;

	if (lhs._level > rhs._level) return true;
	if (lhs._level == rhs._level) return lhs._suit > rhs._suit;
	return false;
}
