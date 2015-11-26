#include <stdio.h>
#include <mpi.h>
#include "cliente.h"

#define SIZE 40

void cliente(){
	FILE *file;
	char path[SIZE]; 
	char path_save[SIZE]; 
	char line[SIZE]; 
	line[0] = '-';

	printf("Archivo a descargar\n");
	scanf("%s", path);
	printf("Archivo a guardar\n");
	scanf("%s", path_save);

	file = fopen(path_save, "w");
	MPI_Send(&path, SIZE, MPI_CHAR, 1, 20, MPI_COMM_WORLD);
	while(line[0] != '\0'){
		MPI_Recv(&line, SIZE, MPI_CHAR, 1, 21, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		fprintf(file, "%s", line);
	}
	fclose(file);
	printf("\nFin del paso de mensaje - CLIENTE\n");
}
