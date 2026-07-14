CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g
TARGETS = server client

all: $(TARGETS)

server: server.c
	$(CC) $(CFLAGS) -o server server.c

client: client.c
	$(CC) $(CFLAGS) -o client client.c

clean:
	rm -f $(TARGETS)

re: clean all
