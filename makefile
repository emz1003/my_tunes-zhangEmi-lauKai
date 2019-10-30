ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.c song_node.o my_tunes.o
	gcc -o program main.o song_node
main.o: main.c song_node.h my_tunes.h
	gcc -c main.c
my_tunes.o: my_tunes.c my_tunes.h song_node.h
	gcc -c my_tunes.c
song_node.o: song_node.c song_node.h
	gcc -c song_node.c
run:
	./program
clean:
	rm *.o
	rm program