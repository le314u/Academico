#ifndef THREAD_H
#define THREAD_H

	#include <stdlib.h>
	#include <stdio.h>
	#include <pthread.h>
	#include "StructDados.h"
	#include "Matriz.h"

	void *celula(void *argumento);
	int Threads(Matrix *m);
#endif