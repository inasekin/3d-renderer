all: app

app:
	gcc -Wall -std=c99 ./src/*.c -o app

run:
	./app

clean:
	rm ./app