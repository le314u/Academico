//////////////////////////////////////////////////////////////////////////////
//	Lucas <Mateus Fernandes 
//  0035411
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//////////////////////////////////////////////////////////////////////////////
//  strutura de dados
//////////////////////////////////////////////////////////////////////////////

typedef void (PtrMetodo)(int tamanho, int *array, int *iterations, int *nSwap);//Ponteiro para funcao
struct Data{
    double time;
    int iteration;
    int swap;
};

//////////////////////////////////////////////////////////////////////////////
//  Prototipos
//////////////////////////////////////////////////////////////////////////////

struct Data Analyze(int tamanho, PtrMetodo MetodoSelecao);
int father(int index);                                                       //Interno_Heap
int* GenerateArray(int length);                                              //Analise
void Heapify(int length, int *array, int index, int *iterations, int *nSwap);//Interno_Heap
int HeapSort(int length,int *array, int *iterations, int *nSwap);            //Metodo
int InsertionSort(int length,int *array, int *iterations, int *nSwap);       //Metodo
void maxHeap(int length, int *array ,int *iterations, int *nSwap);           //Interno_Heap
void ReadArray(int tamanho, int *array);                                     //Analise
int sonLeft(int index);                                                      //Interno_Heap
int sonRight(int index);                                                     //Interno_Heap
void Swap(int *valor1, int *valor2);                                         //Interno Metodo
double TimeMS(clock_t start, clock_t pause);                                 //Analise
void Write(struct Data inf);                                                 //Analise
            

//////////////////////////////////////////////////////////////////////////////
//	Funcoes internas
//////////////////////////////////////////////////////////////////////////////
void Swap(int *valor1, int *valor2){
    //Troca posiçoes do vetor (chamada por referencia)
    int aux;
    aux = valor1[0];
    valor1[0] = valor2[0];
    valor2[0] = aux;
}
double TimeMS(clock_t start, clock_t pause){
    //retorna o tempo em mile segundos '%f'
    return ((difftime(pause,(start))/CLOCKS_PER_SEC)*1000);
}
struct Data Analyze(int tamanho, PtrMetodo MetodoSelecao){
    //Inicializa contadores
    int nSwap = 0;
    int iterations = 0;

    //Gera um Array de tamanho especifico com dados aleatorios
    int *array = GenerateArray(tamanho);
    
    //ReadArray(tamanho, array);printf("\n\n");
    //Inicia o timer
    clock_t start = clock();

    //Ordena vetor
    MetodoSelecao(tamanho, array, &iterations, &nSwap);

    //Para o timer
    clock_t pause = clock();

    //ReadArray(tamanho, array);

    //retorna dados da tabela
    struct Data data;
    data.time = TimeMS(start, pause);
    data.iteration = iterations;
    data.swap = nSwap;
    return data;

}
int* GenerateArray(int length){
    //Gera um array com valores aleatorios 

    //Seta uma semente para os numeros aleatorios 
    srand(time(NULL));
    //Cria um vetor e o preenche com numeros inteiros
    int *array = NULL;
    int index = 0;
    array = (int *) malloc(length * sizeof(int));
    for(index = 0; index < length; index++){
        array[index] = (int)floor(rand() % length);
    }
    return array;
}

void ReadArray(int tamanho, int *array){
    //mostra na tela todos os valores do vetor
    int index=0;
    for(index = 0; index < tamanho; index++){
        printf("%d ",array[index]);
    }
    printf("\n");
}
void Write(struct Data inf){
    printf("\nTempo:\t\t%fms",inf.time);
    printf("\nIterações:\t%d",inf.iteration);
    printf("\nTrocas:\t\t%d\n\n",inf.swap);
}


//////////////////////////////////////////////////////////////////////////////
//	Metodos de Ordenação
//////////////////////////////////////////////////////////////////////////////

int InsertionSort(int length,int *array, int *iterations, int *nSwap){
    int index1 = 0;
    //vai do inicio para o final
    for( index1 = 0; index1 < length; index1++){
        int index2 = 0;
        //Vai da etapa atual para o inicio
        for( index2 = index1; index2 > 0; index2--){
            iterations[0]++;
            if(array[index2] < array[index2-1]){
                nSwap[0]++;
                Swap(&(array[index2]), &(array[index2-1]));
            }else{
                //condicao de parada
                break;
            }
        }
    }
}


int HeapSort(int length,int *array, int *iterations, int *nSwap){
    //Cria estrutura Heap
    maxHeap(length, array, iterations, nSwap);
    nSwap[0]++;
    Swap(&(array[0]), &(array[length-1]));

    //Ordena
    for(int size = length; size >= 0;size--){
        Heapify(size, array, 0, iterations, nSwap);
        Swap(&(array[0]), &(array[size]));
    }
}
    //Estrutura Heap
    int father(int index){
        return ((int) ((index-1)/ 2));
    }
    int sonLeft(int index){
        return ((int) (index*2 + 1));
    }
    int sonRight(int index){
        return ((int) (index*2 + 2));
    }
    void maxHeap(int length, int *array ,int *iterations, int *nSwap){
        //Transforma 'de maneira logica' o vetor em uma estrutura maxHeap onde o filho não pode ser maior que o pai.
        for(int i = father(length-1);i>=0;i--){
            Heapify(length, array, i, iterations, nSwap);
        }
    }
    void Heapify(int length, int *array, int index, int *iterations, int *nSwap){
        
        //Obriga o pai a ser maior que o filho
        //Corre até chegar a ultima folha da sub arvore
        length = length-1;
        int larger = index;
        int left = sonLeft(index);
        int right = sonRight(index);
        while(1){
            //Variaveis
            iterations[0]++;
            larger = index;
            left = sonLeft(index);
            right = sonRight(index);
            //Esquerda maior ?
            if( left <= length && left >= 0){
                if(array[index] < array[left]){
                    larger = left;
                }
            }
            //Direita maior?
            if( right <= length && right >= 0){
                if(array[larger] < array[right]){
                    larger = right;
                }
            }
            //Verifica se a regra foi respeitada e teoricamente é uma condiçao de parada
            if(larger != index){
                //Se o pai for menor que o filho troca
                nSwap[0]++;
                Swap(&(array[larger]) ,&(array[index]));
                //Prepara os argumentos para a proxima iteração
                index = larger;
            }else{
                break;
            }
        }
    }


//////////////////////////////////////////////////////////////////////////////
//	Comentario
//////////////////////////////////////////////////////////////////////////////

void main(){
    struct Data inf;
    int tamanho = 10;
    for(int i=0;i<3;i++){
        tamanho = tamanho*10;
        printf("-----------------------------------\n");
        
        printf("HeapSort %d elementos:\n",tamanho);
        inf = Analyze(tamanho,HeapSort);   
        Write(inf); 

        printf("\nInsertion Sort %d elementos:",tamanho);
        inf = Analyze(tamanho,InsertionSort);
        Write(inf); 

    }
}

