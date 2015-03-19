CC = g++
#LIBS = -lm
CFLAGS = -Wall
OBJ =\
	obj/main.o \
	obj/Element.o \
	obj/List.o \
	obj/Queue.o \
	obj/Stash.o \
	obj/Timer.o

INC = \
	inc/Element.h \
	inc/List.h \
	inc/Queue.h \
	inc/Stash.h 


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
