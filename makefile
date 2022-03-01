# Declaraciones de macros.

CC = gcc
CFLAGS = -c -g -Wall -ansi -pedantic

# Bibliotecas necesarias: command.h game_reader.h graphic_engine.h game.h libscreen.a libscreen.h object.h player.h space.h set.h types.h

# Declaraciones de reglas.

all: antgame clean

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

game_loop.o: game_loop.c
	$(CC) $(CFLAGS) $^

clean:
	echo "cleaning..."
	rm -rf *.o
