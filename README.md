<h1 align = "center"> Biblioteca de imagens PPM</h1>

<p align="center">O formato de arquivo ppm (Portable Pixel Map) é utilizado para armazenar imagens. Sua especificação é bastante simples, porém ineficiente e altamente redundante, contendo diversas informações que um ser humano não notaria em uma imagem. Por sua simplicidade, este formato pode ser usado para escrever e analisar programas de manipulação de imagem de forma simples e prática. 
</p>



Modo de compilação:
Abra o diretório onde o arquivo Makefile se encontra. Em seguida, abra o terminal e  digite "make all" para que todos os arquivos possam ser compilados. 

Para executar o programa (aplicar os filtros a uma imagem escolhida) temos os seguintes comandos que devem ser inseridos na linha de comando do terminal.

Considere:
	* X: o fator de redução, ex.: X = 2, X = 3...
	* entrada.ppm : o nome da imagem ppm a ser inserida, ex.: gatinho.ppm
	* A: o angulo da rotação desejada, ex.: A = 90, A = 180 e A = 270

Funcionalidades e comandos:
  reduzir : ./main <entrada.ppm> red <X> saida.ppm 
	
  amplia : ./main <entrada.ppm> amp <X> saida.ppm

  rotação : ./main <entrada.ppm> rot <A> saida.ppm

  escala cinza : ./main <entrada.ppm> cinza saida.ppm

  negativo : ./main <entrada.ppm> inverte saída.ppm

  remove cor : ./main <entrada.ppm> remove [r|g|b|rg|rb|gb] saida.ppm
	*escolha r para remover a cor vermelha; g para remover a cor verde e b para remover a cor azul

  espelhar imagem : ./main <entrada.ppm> filtro saída.ppm



Módulos:

- Módulo principal(main.c):  
  É feito um menu de opções para que o usuário possa escolher o que fazer na biblioteca de imagens.  Reduz ,amplia, rotação,cinza; negativo(inverte), remover cor, filtro(espelhamento de imagem).

- Módulo Filtro(filtro.c):
  Contendo todos as funções para a utilização das biblioteca.

- Módulo estrutura(estrutura.c):
  Contém ás estruturas exigidas para poder fazer a alocação das matrizes contida nas imagens.

  

  ###Tecnologias 

  As seguintes ferramentas foram usadas na construção do projeto 

  -[MinGW](https://sourceforge.net/projects/mingw/) : Para a compilação do GNU (GCC) no Windows;

  -[Gimp](https://www.gimp.org) : Para a visualização dos arquivos PPM no Windows;

  -[Valgrind](https://valgrind.org) : Para a depuração dos codigos;

  -[Linux](https://www.linux.org/pages/download/) 

  -[Windows](https://www.microsoft.com/pt-br/windows/) 

  -[C](https://devdocs.io/c/)
