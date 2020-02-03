Linha="\\n____________________________________\\n"
Obj=obj/
Src=src/

init:gcc
	@echo "ok"

gcc: link
	@echo "${Linha}Executar"
	./main.exe

gdb: debug
	@echo "${Linha}Debugando"
	gdb main.exe

debug: abb main
	@echo "${Linha}Linkagem"
	gcc -g -o main.exe ${Obj}main.o ${Obj}tad_abb.o -lm

link: abb main
	@echo "${Linha}Linkagem"
	gcc -o main.exe ${Obj}main.o ${Obj}tad_abb.o -lm

abb:
	@echo "${Linha}TAD_ABB"
	gcc -o ${Obj}tad_abb.o -c ${Src}tad_abb.c -lm

main:
	@echo "${Linha}Main"
	gcc -o ${Obj}main.o -c ${Src}main.c
