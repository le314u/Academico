//Nome: Lucas Mateus Fernandes
//Ra:   0035411
//Data: 01/07/2019

#include <time.h>
#include "Clock.h"
float start(){
    return (float)clock()/CLOCKS_PER_SEC;
}

float stop(){
    return (float)clock()/CLOCKS_PER_SEC;
}

float delta(float inicio, float fim){
    return (float)fim - (float)inicio;
}