TARGET = main
SRC = main.o

CC = g++
CFLAGS = -Wall -g

.PHONY: clean tags

$(TARGET) : $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) -c $@ $<

clean:
	rm *.o
	rm main

tags:
	rm tags
	ctags -R
