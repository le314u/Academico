init:gcc
	rm *.o
	rm exec
	
gcc:link
	./exec

gdb:link
	gdb exec

link:hash main
	gcc -g -o exec TabelaHash.o teste.o

hash:
	gcc -g TabelaHash.c -c

main:
	gcc -g teste.c -c