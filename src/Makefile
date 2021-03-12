main: interface.o
	gcc -o test interface.o

interface.o: interface.c tokenizer.h history.h
	gcc -c interface.c

clean:
	rm *~ *# *.o
