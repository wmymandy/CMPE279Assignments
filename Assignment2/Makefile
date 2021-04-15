CC=gcc

makerun:
	make clean
	$(CC) server.c -o server
	$(CC) server2.c -o server2
	$(CC) client.c -o client

clean:
	rm -f server
	rm -f client
	rm -f server2
