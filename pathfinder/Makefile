all: install clean

install:
		@make -C ./libmx
		@clang -std=c11 -Wall -Wextra -Werror -Wpedantic -I inc src/*.c -L ./libmx -lmx -o pathfinder

uninstall: clean
		@rm -rf libmx.a
		@rm -rf obj
		@rm -rf pathfinder
		@make uninstall -C ./libmx

clean:
		@rm -rf obj

reinstall: all
