all: program 

program: main.o readfile.o createfile.o
	gcc -o program main.o readfile.o createfile.o

main.o: main.c main.h readfile.h createfile.h
	gcc -c main.c

readfile.o: readfile.c readfile.h
	gcc -c readfile.c

createfile.o: createfile.c createfile.h
	gcc -c createfile.c

clean: 
	rm -f main.o readfile.o createfile.o program 
	rm -f *.html 

