all: program

program: build/main.o build/readfile.o build/createfile.o
	gcc -o program build/main.o build/readfile.o build/createfile.o

build/main.o: main.c main.h readfile.h createfile.h | build
	gcc -c main.c -o build/main.o

build/readfile.o: readfile.c readfile.h | build
	gcc -c readfile.c -o build/readfile.o

build/createfile.o: createfile.c createfile.h | build
	gcc -c createfile.c -o build/createfile.o

build:
	mkdir -p build

clean:
	rm -rf build program
	rm -f *.html
	rm -r export/
