CC=gcc
CFLAGS=-g -Wall

dijkstras_algorithm:dijkstras_algorithm.c adjacency_list.c
	$(CC) $(CFLAGS) dijkstras_algorithm.c -o dijkstras_algorithm
	$(CC) $(CFLAGS) adjacency_list.c -o adjacency_list

clean : 
	rm -f dijkstras_algorithm adjacency_list
