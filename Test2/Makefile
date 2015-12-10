CXX = g++

SDL_LIB = -L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib
SDL_INCLUDE = -I/usr/local/includes

CXXFLAGS = -Wall -c -std=c++0x $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB)
EXE = Test2 

all: $(EXE)

$(EXE): main.o Game.o Video.o
	$(CXX) main.o Game.o Video.o $(LDFLAGS) -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
Game.o: Game.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
Video.o: Video.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)
