# Declaraciones de macros.

CC = gcc
CFLAGS = -c -g -Wall -pedantic

# Bibliotecas necesarias: command.h game_reader.h graphic_engine.h game.h libscreen.a libscreen.h object.h player.h space.h set.h types.h

# Declaraciones de reglas.

#valgrind --leak-check=full ./

all: antgame clean


#space-testing -> Do "$make space_t"
space_t: space_test clean
space_test: space.o set.o space_test.o
	$(CC) -g -Wall -o space_test $^
space_test.o: space_test.c
	$(CC) $(CFLAGS) $^


#set-testing -> Do "$make set_t"
set_t: set_test clean
set_test: set.o set_test.o
	$(CC) -g -Wall -o set_test $^
set_test.o: set_test.c
	$(CC) $(CFLAGS) $^


#enemy-testing -> Do "$make enemy_t"
enemy_t: enemy_test clean
enemy_test: enemy.o enemy_test.o
	$(CC) -g -Wall -o enemy_test $^
enemy_test.o: enemy_test.c
	$(CC) $(CFLAGS) $^



antgame: game.o game_reader.o command.o graphic_engine.o object.o player.o space.o set.o libscreen.a game_loop.o
	$(CC) -g -Wall -o antgame $^

command.o: command.c
	$(CC) $(CFLAGS) $^

game.o: game.c
	$(CC) $(CFLAGS) $^

game_reader.o: game_reader.c
	$(CC) $(CFLAGS) $^

graphic_engine.o: graphic_engine.c
	$(CC) $(CFLAGS) $^

object.o: object.c
	$(CC) $(CFLAGS) $^

player.o: player.c
	$(CC) $(CFLAGS) $^

space.o: space.c
	$(CC) $(CFLAGS) $^

set.o: set.c
	$(CC) $(CFLAGS) $^

enemy.o: enemy.c
	$(CC) $(CFLAGS) $^

game_loop.o: game_loop.c
	$(CC) $(CFLAGS) $^



clean:
	echo "cleaning..."
	rm -rf *.o

