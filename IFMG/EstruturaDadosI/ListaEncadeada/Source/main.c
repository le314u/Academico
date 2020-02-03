/////////////////////////////////////////////
// GitHub	:1ldomal2
// E-mail	:lucasmfccom@gmail.com
// Nome		:Lucas Mateus Fernandes
// RA		:0035411
/////////////////////////////////////////////

#include "tadLista.h"
#include "structAluno.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("\n\nNão deu\n\n");
    //Manipula conforme necessário
    Lista *lista = malloc(sizeof(lista));
    CriaLista(lista);
    Aluno aluno[8];
    aluno[0].nome="Joao das Neves";
    aluno[0].media=10;
    aluno[0].matricula=07;

    aluno[1].nome="Daniela Tagarela";
    aluno[1].media=20;
    aluno[1].matricula=02;

    aluno[2].nome="Jhony Walker";
    aluno[2].media=30;
    aluno[2].matricula=04;

    aluno[3].nome="José Ova";
    aluno[3].media=40;
    aluno[3].matricula=03;

    aluno[4].nome="Jurema do Ceus";
    aluno[4].media=50;
    aluno[4].matricula=07;

    aluno[5].nome="Ibrahmovitch dos santos";
    aluno[5].media=50;
    aluno[5].matricula=05;

    aluno[6].nome="Lucas da silva Sauro";
    aluno[6].media=50;
    aluno[6].matricula=05;

    aluno[7].nome="Roberto de trololo";
    aluno[7].media=50;
    aluno[7].matricula=05;

    for(int i = 0; i < 8; i++)
    {
        InsereNaLista(lista,&aluno[i]);
    }
    
    ConsultaMedia(lista,100);
    
    RetiraAluno(lista,"Lucas da silva Sauro");
    printf("\n------------------\n");

    ConsultaMedia(lista,100);
}

