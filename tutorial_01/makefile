CFLAGS = -Wall -pedantic -Werror
LFLAGS = `sdl2-config --libs` -lSDL
OBJS   = input.o main.o
PROG = tutorial_01
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
