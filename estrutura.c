#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estrutura.h"

pixel** aloca_matriz(pixel **matriz, int n, int m){
	matriz = (pixel **) calloc(n, sizeof(unsigned char*));
	int i;
	for(i= 0; i<n; i++){
		matriz[i] = (pixel *) calloc(m, sizeof(pixel));
	}
	return matriz;	
}

void imprime_matriz(pixel **matriz, char magic_n[3], int m, int  n, int cores, char arq_saida[15]){
	FILE *saida;
	saida = fopen(arq_saida, "wb");

	//cabeçalho
	fprintf(saida, "%s\n%d %d\n%d\n", magic_n, m, n, cores);
	for(int i=0;i<n; i++){
		for(int j=0; j<m; j++){
			fprintf(saida, "%c%c%c", matriz[i][j].r, matriz[i][j].g, matriz[i][j].b);
		}
	}
	fclose(saida);
}