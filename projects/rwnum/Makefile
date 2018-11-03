CFLAGS=-Wall -O2
LDFLAGS=

OBJS= rwnum.o main.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) -ggdb 

rwnum: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm rwnum *.o
