CFLAGS = -Wall -pedantic -Werror
LFLAGS = `sdl2-config --libs` -lSDL2 -lSDL2_image
OBJS   = input.o main.o
PROG = tutorial_02
CXX = gcc

# top-level rule to create the program.
all: $(PROG)

# compiling other source files.
%.o: %.c %.h
	$(CXX) $(CFLAGS) -c -s $<

# linking the program.
$(PROG): $(OBJS)
	$(CXX) $(OBJS) -o $(PROG) $(LFLAGS)

# cleaning everything that can be automatically recreated with "make".
.PHONY : clean
clean:
	rm $(PROG) $(OBJS)
