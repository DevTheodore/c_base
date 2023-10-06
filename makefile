all: compiled/prog

compiled/prog: src/main.c
	 clang src/*.c src/exo/*.c -o compiled/prog -Wall -Werror -fsanitize=address
clean:
	 rm compiled/*
#add `sdl2-config --cflags --libs` with compiler for sdl2