CC = gcc
CFLAGS = -g -Wall
TARGET = P1
OBJ = P1.o scanner.o testScanner.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

P1.o: P1.c testScanner.h scanner.h
testScanner.o: testScanner.c scanner.h token.h testScanner.h
scanner.o: scanner.c token.h character.h scanner.h

clean:
	rm -f $(TARGET) $(OBJ) 
