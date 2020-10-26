CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++2a -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all: bridge

bridge: main.o bidding_phase.o Call.o player.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS) $(BOOSTLIB)

%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o bridge

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./cache_server
	valgrind --leak-check=full --show-leak-kinds=all ./test_cache_client
