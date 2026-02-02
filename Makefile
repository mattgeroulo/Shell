CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC = src/main.c src/readLine.c src/ls.c src/parseInput.c src/echo.c
OUT = shell

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
