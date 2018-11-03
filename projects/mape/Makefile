CFLAGS  = -Wall -I/usr/include/SDL -I../stktool
LDFLAGS = -lSDL -L../stktool -lstktool

LIB = libmape.a
OBJS= mapespritebox.o mapeworkarea.o
MAIN= main.c

all: $(LIB) main

.c.o:
	$(CC) -c $< $(CFLAGS) $(LDFLAGS) -ggdb

$(LIB): $(OBJS)
	$(AR) rcs $(LIB) $(OBJS)

main:
	$(CC) -o mape $(MAIN) $(CFLAGS) -I. $(LDFLAGS) -L. -lmape

clean:
	rm *.o libmape.a mape
