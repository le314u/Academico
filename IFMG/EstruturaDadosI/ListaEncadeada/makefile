SRC=Source/
OBJ=Object/

all:tad main
	gcc -o $(OBJ)main.exe $(OBJ)main.o $(OBJ)tadLista.o
	./$(OBJ)main.exe

debug:
	gcc -g -o $(OBJ)debug.exe $(OBJ)main.o $(OBJ)tadLista.o
	gdb $(OBJ)debug.exe

tad:
	gcc -o $(OBJ)tadLista.o -c $(SRC)tadLista.c 

main:
	gcc -o $(OBJ)main.o -c $(SRC)main.c