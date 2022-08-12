#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estrutura.h"
#include "filtros.h"

//REDIMENSIONA - AMPLIA
void amplia_imagem(char arq_entrada[15], char arq_saida[15], char qtd_red[2]){
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

	pixel **imagem_ampliada = NULL;
	int fator = atoi(qtd_red);
	imagem_ampliada = aloca_matriz(imagem_ampliada, n*fator, m*fator);

	for(int i =0; i<n*fator; i++){
		for(int j= 0; j< m*fator; j++){
			imagem_ampliada[i][j] = imagem_original[i/fator][j/fator]; 
		}
	}
	imprime_matriz(imagem_ampliada, magic_n, m, n , cores, arq_saida);

	//liberando as matrizes
	for(int i=0; i<n*fator; i++){
		free(imagem_ampliada[i]);
	}
	free(imagem_ampliada);


	for(int i=0; i<n; i++){
		free(imagem_original[i]);
	}
	free(imagem_original);	
}

// PRETO E BRANCO
int escala_cinza(unsigned char r, unsigned char g, unsigned char b){
	int media = (r + g + b) / 3;
	int menor_diferenca = 255, diferenca, posicao = 0;
	int escala_cinza[10] = {0, 28, 54, 79, 105, 129, 169, 192, 211, 220};
	for(int k = 9; k>= 0; k--){
		diferenca = escala_cinza[k] - media;
		if(diferenca < 0){
			diferenca = diferenca * (-1);
		}
		if(diferenca < menor_diferenca){
			menor_diferenca = diferenca;
			posicao = k;
		}
	}	

	return escala_cinza[posicao];
}

//	NEGATIVO
void inverte_cores(char arq_entrada[15], char arq_saida[15]){
	//leio os pixels da imagem
		FILE *imagem;
		imagem = fopen (arq_entrada, "rb");

		int m, n;
		char magic_n[3];
		int cores;

		fscanf(imagem, "%s\n", magic_n);
		fscanf(imagem, "%d %d\n", &m, &n);
		fscanf(imagem, "%d\n", &cores);

		pixel **imagem_original = NULL;
		imagem_original = aloca_matriz(imagem_original, n, m);

		for(int i =0; i<n; i++){
	        for(int j = 0; j<m; j++){
	            fscanf(imagem,"%c",&imagem_original [i][j].r);
	            fscanf(imagem,"%c",&imagem_original [i][j].g);
	            fscanf(imagem,"%c",&imagem_original[i][j].b);
	        }
   		}
   		pixel **matriz = NULL;
   		matriz = aloca_matriz(matriz, n, m);
    	
		for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){
	            matriz[i][j].r = (255 - imagem_original[i][j].r);
	            matriz[i][j].g = (255 - imagem_original[i][j].g);
	            matriz[i][j].b = (255 - imagem_original[i][j].b);
	        }
	    }
	    fclose(imagem);
	    imprime_matriz(matriz, magic_n, m, n , cores, arq_saida);

	    //liberando o espaço da matriz
	    for(int i=0; i<n; i++){
			free(imagem_original[i]);
		}
		free(imagem_original);

}

// REMOVE COR
void remove_cor(char arq_entrada[15], char arq_saida[15], char cor[3]){
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

	for(int i=0; i<n; i++){
		free(imagem_original[i]);
	}
	free(imagem_original);
}

// FILTRO ESPELHAR
void filtro(char arq_entrada[15], char arq_saida[15]){
	FILE *imagem;
		imagem = fopen (arq_entrada, "rb");

		int m, n;
		char magic_n[3];
		int cores;

		fscanf(imagem, "%s\n", magic_n);
		fscanf(imagem, "%d %d\n", &m, &n);
		fscanf(imagem, "%d\n", &cores);

		//copiando a imagem original
		pixel **matriz = NULL;
		matriz = aloca_matriz(matriz, n, m);
		for(int i =0; i<n; i++){
	        for(int j = 0; j<m; j++){
	            fscanf(imagem,"%c",&matriz [i][j].r);
	            fscanf(imagem,"%c",&matriz [i][j].g);
	            fscanf(imagem,"%c",&matriz[i][j].b);
	        }
    	}
    	fclose(imagem);

    	pixel **matriz_temp = NULL;
    	matriz_temp = aloca_matriz(matriz_temp, n, m);
	
	FILE *saida;
    	saida = fopen(arq_saida,"wb");
    	fprintf(saida, "%s\n%d %d\n%d\n", magic_n, m, n, cores);
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){

	            matriz_temp[i][j].r = matriz[i][n-j].r;
	            matriz_temp[i][j].g = matriz[i][n-j].g;
	            matriz_temp[i][j].b = matriz[i][n-j].b;

            	fprintf(saida,"%c%c%c",matriz_temp[i][j].r,matriz_temp[i][j].g,matriz_temp[i][j].b);
            }
        }    	
    	fclose(saida);

    	for(int i=0; i<n; i++){
			free(matriz_temp[i]);
		}
		free(matriz_temp);

		for(int i=0; i<n; i++){
			free(matriz[i]);
		}
		free(matriz);
}

//REDIMENSIONA - REDUZ 
void reduz_imagem(char arq_entrada[15], char arq_saida[15],char qtd_red[2]){

	//leio os pixels da imagem
	FILE *imagem;
	imagem = fopen (arq_entrada, "rb");

	int m, n;
	char magic_n[3];
	int cores;

	fscanf(imagem, "%s\n", magic_n);
	fscanf(imagem, "%d %d\n", &m, &n);
	fscanf(imagem, "%d\n", &cores);

	int fator = atoi(qtd_red);

	//copiando a imagem original
	pixel **imagem_original = NULL;
	imagem_original = aloca_matriz(imagem_original, n*fator, m*fator);
	for(int i=0;i<n; i++){
		for(int j=0; j<m; j++){
			fscanf(imagem, "%c", &imagem_original[i+fator][j+fator].r);
			fscanf(imagem, "%c", &imagem_original[i+fator][j+fator].g);
			fscanf(imagem, "%c", &imagem_original[i+fator][j+fator].b);
		}
	}
	pixel **imagem_reduzida = NULL;
	imagem_reduzida = aloca_matriz(imagem_reduzida, n/fator, m/fator);

	for(int i =0; i<n/fator; i++){
		for(int j= 0; j< m/fator; j++){
			imagem_reduzida[i][j] = imagem_original[i+fator][j+fator];
			 
		}
	}
	imprime_matriz(imagem_reduzida, magic_n, m/fator, n/fator , cores, arq_saida);

	for(int i=0; i<n/fator; i++){
		free(imagem_reduzida[i]);
	}
	free(imagem_reduzida);


	for(int i=0; i<n; i++){
		free(imagem_original[i]);
	}
	free(imagem_original);
}

void rotaciona(char arq_entrada[15], char arq_saida[15], char angulo[3]){
	int m,n;
    char magic_n[3];
    int cores;
	FILE *imagem;
    int x;
    x = atoi(angulo);

	//receber o arquivo
    imagem = fopen(arq_entrada,"rb");

    fscanf(imagem, "%s\n",magic_n);
    fscanf(imagem, "%d %d\n",&m,&n);
    fscanf(imagem,"%d\n",&cores);

    pixel **matriz = NULL;
    matriz = aloca_matriz(matriz,n,m );
    imagem = fopen(arq_entrada,"rb");

    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            fscanf(imagem,"%c",&matriz [i][j].r);
            fscanf(imagem,"%c",&matriz [i][j].g);
            fscanf(imagem,"%c",&matriz[i][j].b);
        }
    }

    //criamos a matriz temporaria que vai servir de base para as rotações
    pixel **matriz_tmp;
    matriz_tmp = aloca_matriz(matriz_tmp, m,n);

    //gira a imagem em 90°
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
              
            matriz_tmp[i][j].r =  matriz[j][n-1-i].r;
            matriz_tmp[i][j].g =  matriz[j][n-1-i].g;
            matriz_tmp[i][j].b =  matriz[j][n-1-i].b;
        }
     }
    fclose(imagem);
    if(x == 90){
    	FILE *saida1;
    	saida1 = fopen(arq_saida,"wb");
    	fprintf(saida1, "%s\n%d %d\n%d\n", magic_n, n, m, cores);
    	for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){		       	
            	fprintf(saida1,"%c%c%c", matriz[n-1-j][i].r , matriz[n-1-j][i].g , matriz[n-1-j][i].b );
       		}
    	}
    	fclose(saida1);
    }

    else if(x == 270){
    	FILE *saida2;
    	saida2 = fopen(arq_saida,"wb");
    	fprintf(saida2, "%s\n%d %d\n%d\n", magic_n, n, m, cores);
    	for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){        
            	fprintf(saida2,"%c%c%c", matriz_tmp[i][j].r , matriz_tmp[i][j].g , matriz_tmp[i][j].b );        
        	}
    	}
    	fclose(saida2);
    }

    else if(x == 180){
    	pixel **matriz2;
    	matriz2 = aloca_matriz(matriz2, m, n);
    	FILE *saida3;
    	saida3 = fopen(arq_saida,"wb");

	    fprintf(saida3, "%s\n%d %d\n%d\n", magic_n, n, m, cores);
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){	    
	            matriz2[i][j].r = matriz_tmp[j][m-1-i].r;
	            matriz2[i][j].g = matriz_tmp[j][m-1-i].g;
	            matriz2[i][j].b = matriz_tmp[j][m-1-i].b;

	            fprintf(saida3,"%c%c%c", matriz2[i][j].r, matriz2[i][j].g, matriz2[i][j].b);
	        }
    	}
    fclose(saida3);
    }

}

