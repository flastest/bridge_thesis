#include <string>
#include <iostream>

#pragma once

enum call_t { player_bid, opening, PASS, X, XX, overcall, response };
enum suit_t { CLUBS, DIAMONDS, HEARTS, SPADES, NOTRUMP };


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
	call_t _type; //in a perfect world, this is only one bit

	call_def_t _def;

	int _HCP;

	distribution _dist;

	int _level;

	suit_t _suit;

public:

	Call() {}

	//adds a Call to the bidding system
	//type defines whether it's an overcall, response, or opening Call
	//def_type defines the type (if this Call is a response, def_type tells you what you're responding to)
	//HCP is self explanatory
	//dist is the sort of distribution you need to make this Call
	//level is the level of the Call, suit is the suit of the Call (level = 7, suit = s for 7S)
	Call(call_t type, call_def_t def_type, int HCP, distribution dist, int level, suit_t suit);

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

	void set_call(call_t call) { _type = call; }
	void set_call(int level, suit_t suit) { _level = level; _suit = suit; }


	//operator overloads 
	friend std::ostream & operator<<(std::ostream &Str, const Call &bid) { 
		// print something from v to str, e.g: Str << v.getX();
		//TODO: cases for pass and doublw
		Str<<bid._level<<" "<<bid._suit;
		return Str;
	}


	friend bool operator==(const Call& lhs, const Call& rhs) 
	{	
		if (lhs._type == rhs._type)
		{
			if (lhs._type != PASS || lhs._type != X || lhs._type != XX){
				return (lhs._suit == rhs._suit && lhs._level == rhs._level);
			}
			return true;
		}
		return false;
	}


	// TODO: the following need cases for XX and X!
	friend bool operator<(const Call& lhs, const Call& rhs) 
	{
		return (lhs._suit < rhs._suit && lhs._level < rhs._level);
	}

	friend bool operator>(const Call& lhs, const Call& rhs) 
	{	
		return (lhs._suit > rhs._suit && lhs._level > rhs._level);
	}

};