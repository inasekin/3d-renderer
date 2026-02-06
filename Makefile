all: app

app:
	gcc -Wall -std=c99 ./src/*.c -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 -o app

run:
	./app

clean:
	rm ./app
