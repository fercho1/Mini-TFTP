#include <mpi.h>
#include "servidor.h"
#include "cliente.h"

int main(int arg, char *argv[]){
	int r, p;
	MPI_Init(&arg, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &r);
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	while(1){
		if(r == 0){
			printf("Copiar un nuevo archivo\n");
			cliente();
		}
		else if (r == 1){
			servidor();
		}
	}
	MPI_Finalize();
	return 0;
}
