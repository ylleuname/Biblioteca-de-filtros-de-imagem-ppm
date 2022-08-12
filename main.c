#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filtros.h"
#include "estrutura.h"

int main(int argc, char *argv[]){

	//pegar o nome do arquivo de entrada e de saida
	char arq_entrada[15];
	strcpy(arq_entrada, argv[1]);
	char arq_saida[15];
	strcpy(arq_saida, argv[argc-1]);

	//para verificar qualquer função foi chamada pelo terminal
	char reduz[] = "red";
	char amplia[] = "amp";
	char rotacao[] = "rot";
	char cinza[] = "cinza";
	char negativo[] = "inverte";
	char remove[] = "remove";
	char filtro1[]= "filtro";

	if((strcmp(argv[2], reduz)) == 0){
		char qtd_red[2];
		strcpy(qtd_red, argv[3]);
		reduz_imagem(arq_entrada, arq_saida, qtd_red);
	}

	else if((strcmp(argv[2], amplia)) == 0){
		char qtd_red[2];
		strcpy(qtd_red, argv[3]);

		amplia_imagem(arq_entrada, arq_saida, qtd_red);
	}

	else if((strcmp(argv[2], rotacao)) == 0){
		char angulo[3];
		strcpy(angulo, argv[3]);

		rotaciona(arq_entrada, arq_saida, angulo);
	}

	else if((strcmp(argv[2], cinza)) == 0){
    //leio os pixels da imagem
    unsigned char r, g, b;
    FILE *imagem;
    imagem = fopen (arq_entrada, "rb");

    int m, n;
    char magic_n[3];
    int cores;

    fscanf(imagem, "%s\n", magic_n);
	fscanf(imagem, "%d %d\n", &m, &n);
	fscanf(imagem, "%d\n", &cores);

    pixel **matriz = NULL;
	matriz = aloca_matriz(matriz, n, m);

    for(int i=0; i<n; i++){
    	for(int j = 0; j<m; j++){
			fscanf(imagem, "%c%c%c", &r, &g, &b);
			matriz[i][j].r = escala_cinza(r, g, b);
			matriz[i][j].g = escala_cinza(r, g, b);
			matriz[i][j].b = escala_cinza(r, g, b);
     	}
    }
	fclose(imagem);
	
	imprime_matriz(matriz, magic_n, m, n , cores, arq_saida);

	for(int i=0; i<n; i++){
		free(matriz[i]);
	}
	free(matriz);
   
	}

	else if((strcmp(argv[2], negativo)) == 0){
		 inverte_cores(arq_entrada,arq_saida);
	}

	else if((strcmp(argv[2], remove)) == 0){
		char cor[3];
		strcpy(cor, argv[3]);
		int qtd_cores = strlen(cor);
	
		//leio os pixels da imagem
		FILE *imagem;
		imagem = fopen (arq_entrada, "rb");

		int m, n;
		char magic_n[3];
		int cores;

		fscanf(imagem, "%s\n", magic_n);
		fscanf(imagem, "%d %d\n", &m, &n);
		fscanf(imagem, "%d\n", &cores);

		//copiando a imagem original
		pixel **imagem_original = NULL;
		imagem_original = aloca_matriz(imagem_original, n, m);
		for(int i=0;i<n; i++){
			for(int j=0; j<m; j++){
				fscanf(imagem, "%c", &imagem_original[i][j].r);
				fscanf(imagem, "%c", &imagem_original[i][j].g);
				fscanf(imagem, "%c", &imagem_original[i][j].b);
			}
		}

		//modifico a imagem original removendo as cores escolhidas
		for(int i = 0; i<qtd_cores; i++){
			for(int j= 0; j<n; j++){
				for(int k=0; k<m; k++){
					if(cor[i] == 'r'){
						imagem_original[j][k].r = 0;						
					}
					else if(cor[i] == 'g'){
						imagem_original[j][k].g = 0;
					}
					else if(cor[i] == 'b'){
						imagem_original[j][k].b = 0;
					}
				}
			}
		}

		fclose(imagem);
		//imprimir a imagem modificada
		imprime_matriz(imagem_original, magic_n, m, n , cores, arq_saida);

	}

	else if((strcmp(argv[2], filtro1)) == 0){
		filtro(arq_entrada, arq_saida);
	}

}