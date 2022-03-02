CC = gcc
CFLAGS=
OBJS = calc.o add.o sub.o mul.o
EXE=calc.exe
LIBS=

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS) $(LIBS)
calc.o: calc.c
	$(CC) $(CFLAGS) -c calc.c
add.o: add.c
	$(CC) $(CFLAGS) -c add.c
sub.o: sub.c
	$(CC) $(CFLAGS) -c sub.c
mul.o: mul.c
	$(CC) $(CFLAGS) -c mul.c
clean:
	rm -rf $(OBJS) $(EXE) core


