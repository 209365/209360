CC = g++
#LIBS = -lm
CFLAGS = -Wall
OBJ =\
	obj/main.o \
	obj/Element.o \
	obj/Benchmark.o \
	obj/Timer.o \
	obj/ArrayImplementation/List.o \
	obj/ArrayImplementation/Queue.o \
	obj/ArrayImplementation/Stack.o \
	obj/ListImplementation/List.o \
	obj/ListImplementation/Queue.o \
	obj/ListImplementation/Stack.o

all: obj main


sam_main:  
	$(CC) $(CFLAGS) src/main.cpp -o program

start: obj main
	rm -f *.o obj/*.o; ./program

obj:
	mkdir obj
clean:
	rm -f *.o program obj/*.o

$(OBJ): obj/%.o : src/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

main: $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o program

kopia:
	rm -f src/*.cpp~ inc/*.cpp~

doxy:
	cd ../dox;  make
