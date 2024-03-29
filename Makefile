CC = gcc
FLAGS = -Wall -g

all: myBankd maind

myBankd: libmyBank.so

maind: main.o libmyBank.so
	$(CC) $(FLAGS) -o maind main.o ./libmyBank.so

libmyBank.so: myBank.o myBank.h 
	$(CC) -shared -o libmyBank.so myBank.o myBank.h

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c myBank.h 
	$(CC) $(FLAGS) -fPIC -c myBank.c 

.PHONY: clean all myBankd

clean:
	rm -f *.o *.a *.so maind
