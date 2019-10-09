EXAMPLE=main

# Makefile variables
CC=g++
CFLAGS= -Wextra -O2
OBJ=$(EXAMPLE).o sort.o
DEPS=sort.h

# Build rule for object files ($@ is left hand side of rule, $< is first item from the righthand side of rule)
%.o : %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Make example ($^ is all items from right hand side of the rule)
$(EXAMPLE) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# PHONEY prevents make from doing something with a filename called clean
.PHONEY : clean
clean:
	rm -rf $(EXAMPLE) $(OBJ)