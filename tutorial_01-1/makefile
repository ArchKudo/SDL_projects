CFLAGS = -Wall -pedantic -Werror
LFLAGS = `sdl2-config --libs` -lSDL2
PROG = tutorial_01-1
CXX = gcc

# top-level rule to create the program.
all: $(PROG)


# linking the program.
$(PROG):
	$(CXX) main.c -o $(PROG) $(LFLAGS)

# cleaning everything that can be automatically recreated with "make".
.PHONY : clean
clean:
	rm $(PROG)
