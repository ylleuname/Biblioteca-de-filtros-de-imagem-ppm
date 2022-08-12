all : main.o

main: main.o
	gcc -o main.c main.o -o main

main.o: estrutura.o filtros.o
	gcc main.c estrutura.o filtros.o -o main

estrutura.o: estrutura.c estrutura.h
	gcc -o estrutura.o -c estrutura.c

filtros.o: filtros.c filtros.h
	gcc -o filtros.o -c filtros.c

clean: 
	rm ./main
	rm ./*.o

