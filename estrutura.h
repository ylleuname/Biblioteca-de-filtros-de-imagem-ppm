#ifndef estrutura_h
#define estrutura_h

typedef struct pixel{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}pixel;

pixel** aloca_matriz(pixel **matriz, int n, int m);
void imprime_matriz(pixel **matriz, char magic_n[3], int m, int  n, int cores, char arq_saida[15]);

#endif