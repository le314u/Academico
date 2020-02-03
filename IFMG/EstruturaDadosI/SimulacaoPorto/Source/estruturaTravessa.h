#ifndef estruturaTravessa_h
#define estruturaTravessa_h

#define MaximoContainersTravessa 5

// Includes
#include "pilhaEstatica.h"

// Structs
typedef struct Travessa_s
{
   int id;           //id travessa
   Pilha containers; //Pilha
} Travessa;

// Prototipos
void GeraTravessa(Travessa *Instancia);
void EmpilhaTravessa(Travessa *Instancia, int Data);
int EmulaStradleCar(Travessa *Instancia);
int TravessaDisponivel(Travessa *Instancia);

#endif