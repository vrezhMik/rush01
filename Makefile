CC = cc
CFLAGS = -Wall -Wextra -Werror
rush-01: rush-01.o
	$(CC) $(CFLAGS) -o rush-01 rush-01.o
rush-01.o: rush-01.c
	$(CC) $(CFLAGS) -c rush-01.c
clean: 
	rm -f *.o 
	rm -f *.gch
