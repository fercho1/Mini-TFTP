#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include "servidor.h"

#define SIZE 40

void servidor(){
	FILE *file;
	char filename[SIZE];
	char line[SIZE]; 
	MPI_Recv(&filename, SIZE, MPI_CHAR, 0, 20, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	file = fopen(filename, "r");
	while(fgets(line, sizeof line, file) != NULL){
		MPI_Send(&line, SIZE, MPI_CHAR, 0, 21, MPI_COMM_WORLD);
	}
	fclose(file);
	line[0] = '\0';
	MPI_Send(&line, 1, MPI_INT, 0, 21, MPI_COMM_WORLD);
  	printf("\nFin del paso de mensaje - SERVIDOR \n");
}
