LIB = libdattool.a
OBJS=datfile.o dattool.o daterror.o

all: $(LIB)

.c.o:
	$(CC) -c $< -ggdb -DDAT_DEBUG

$(LIB): $(OBJS)
	$(AR) rcs $(LIB) $(OBJS)

clean:
	rm *.o libdattool.a
