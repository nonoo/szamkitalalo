all: main.c
	gcc main.c -o szamkitalalo

clean:
	rm -f szamkitalalo
