CC = gcc
CFLAGS = -Wall -std=c99 -ggdb
LDLIBS = -lm

headers = lab13.h

submit = submit.tar

all: processing sorting

processing: ex13q1.c ex13q11.c ex13q12.c ex13q10.c ex13q13.c ex13q14.c ex13q15.c $(headers)
	$(CC) $(CFLAGS) -DPART1 $^ -o $@ $(LDLIBS)

sorting: ex13q1.c ex13q10.c ex13q20.c ex13q21.c $(headers)
	$(CC) $(CFLAGS) -DPART2 $^ -o $@ $(LDLIBS)

tar:
	tar -cvf $(submit) ex13q1.c ex13q11.c ex13q12.c ex13q10.c ex13q13.c ex13q14.c ex13q15.c ex13q20.c ex13q21.c $(headers) makefile gamesales.csv check.sh

clean:
	rm -f *.o a.out processing sorting submit.tar