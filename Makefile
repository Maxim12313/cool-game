CC= g++
FLAGS = -Wall -Wextra -Wshadow -Wconversion -Wno-sign-conversion -Wno-sign-compare -Wfloat-equal -fsanitize=undefined -std=c++23


EXE = game_engine.exe

.PHONY: run all clean

run: $(EXE)
	./$(EXE)

all: $(EXE)

$(EXE): main.o
	$(CC) $(FLAGS) main.o -o $(EXE)

clean:
	rm -f *.o
	rm -f *.exe
