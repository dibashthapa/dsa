CC := gcc
CFLAGS := -Wall -Wextra -std=c99
LDFLAGS := -lraylib -lm -lpthread -ldl -lrt -lX11

SRC := tree.c
OBJ := $(SRC:.c=.o)
EXECUTABLE :=  tree

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJ)

