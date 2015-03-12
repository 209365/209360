CC = g++
#LIBS = -lm
CFLAGS = -Wall 
#-std=c99
OBJ =\
	obj/doubleNumbers.o \
	obj/timer.o \
	obj/main.o

all: main

clean:
	rm -f *.o program obj/*.o

$(OBJ): obj/%.o : src/%.cpp 
	$(CC) -c $(CFLAGS) $< -o $@

main: $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o program

kopia:
	rm -f src/*.cpp~ inc/*.cpp~
