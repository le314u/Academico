all: Matriz.o Thread.o Main.o 
	clear
	gcc Matriz.o Thread.o Main.o -lpthread -o EXE #Compila e criar o EXE
	rm -rf *.o #Apagar os arquivos Objetos
	echo "\n\nFeito por :\n Lucas Mateus Fernandes \n Joao Pedro Mendonça\n\n"


matriz.o:Matriz.c Matriz.h
	gcc -g Matriz.c -o Matriz.o
thread.o:Thread.c Thread.h
	gcc -g Thread.c -lpthread -o Thread.o
main.o:Main.c Matriz.h Thread.h
	gcc -g main.c -lpthread -o main.o
