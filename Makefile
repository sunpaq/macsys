CC = cc
DEPS = -I macsys.h
OBJS = \
macsys.o \
example.o

%.o: %.c
	$(CC) -c -o $@ $< $(DEPS)

exec: $(OBJS)
	$(CC) -o exec $(OBJS)

clean:
	rm -f exec *.o