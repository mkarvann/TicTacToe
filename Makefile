# this is partly from CS330
# and I stole your idea to compile and run with 'make run', nice!

CC = g++
CFLAGS = -Wall -g
DEPS = 
OBJS = main_test.o TicTacToe.o TTT_AI.o
EXEC = main_test

all: $(EXEC)

%.o: %.cpp $(DEPS)
	# next line works for c files
	$(CC) $(CFLAGS) -c -o $@ $<
	#$(CC) $(CFLAGS) *.cpp -o $@ $<

$(EXEC): $(OBJS)
	# next line compiles with all warnings on, debug info, and links math lib
	# $(CC) $(CFLAGS) -o $@ $^ -lm -fno-pie -no-pie
	$(CC) $(CFLAGS) -o $@ $^ -lm

.PHONY: db

db:
	gdb -tui $(EXEC)

run: all
	./$(EXEC)

clean:
	rm -i *.o $(EXEC)
