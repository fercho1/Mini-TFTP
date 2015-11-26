CC = mpicc
CFLAGS = -g -Wall

main: tfpt.o cliente.o servidor.o
	$(CC) $(CFLAGS) -o main tfpt.o cliente.o servidor.o

cliente.o: cliente.c cliente.h
	$(CC) $(CFLAGS) -c cliente.c

servidor.o: servidor.c servidor.h
	$(CC) $(CFLAGS) -c servidor.c

tfpt.o: tfpt.c cliente.h servidor.h
	$(CC) $(CFLAGS) -c tfpt.c

clean: 
	rm -rf *.o
