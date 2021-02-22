main: interface.o
	gcc -o test interface.o

interface.o: interface.c tokenizer.h
	gcc -c interface.c

clean:
	rm *~ *# *.o
