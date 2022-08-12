#ifndef filtros_h
#define filtros_h

void amplia_imagem(char arq_entrada[15], char arq_saida[15], char qtd_red[2]);
void reduz_imagem(char arq_entrada[15], char arq_saida[15], char qtd_red[2]);
void rotaciona(char arq_entrada[15], char arq_saida[15], char angulo[3]);
int escala_cinza(unsigned char r, unsigned char g, unsigned char b);
void remove_cor(char arq_entrada[15], char arq_saida[15], char cor[2]);
void inverte_cores(char arq_entrada[15], char arq_saida[15]);
void filtro(char arq_entrada[15], char arq_saida[15]);


#endif
