# Variables
CC = gcc
CFLAGS = -Wall -Wextra
HEADERS = dataStruct.h declarations.h hashTable.h headers.h msgHandler.h udp.h utils.h
OBJECTS0 = node0.o
OBJECTS1 = node1.o
OBJECTS2 = node2.o

# Default target
all: node0 node1 node2

# Individual targets
node0: $(OBJECTS0)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS0)

node1: $(OBJECTS1)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS1)

node2: $(OBJECTS2)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS2)

# Object files
node0.o: node0.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

node1.o: node1.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

node2.o: node2.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f *.o node0 node1 node2
