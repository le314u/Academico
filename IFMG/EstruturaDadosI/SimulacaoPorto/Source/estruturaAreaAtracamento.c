#include "estruturaAreaAtracamento.h"
#include "pilhaEstatica.h"
#include "estruturaNavio.h"

#define ERRO 0
#define OK 1

// VariavelGlobal
int idAreaAtracamento = 0;

// Prototipos metodos internos
int _VerificaNavioAtracadoPossuiContainers(AreaAtracamento *Instancia);
int _VerificaMaiorPilhaContainerNavioAtracado(AreaAtracamento *Instancia);

//Instancia uma Area de Atracamento respeitando a regra de Negocio pre estabelecida
void GeraAreaAtracamento(AreaAtracamento *Instancia)
{
    //Seta Id
    Instancia->id = ++idAreaAtracamento;
    //Estabelece que a Area começa sem um Navio atracado a ela
    Instancia->navio = NULL;

    //Gera uma fila de espera para os barcos que iram atracar neste porto em específico
    GeraFila(&(Instancia->filaLocal));
    //instancia uma variave de controle do 'custo' da fila
    Instancia->nContainersFila = 0;
}

//Coloca um Navio na Fila de espera da Area de Atracamento
void AddNavioAreaAtracamento(AreaAtracamento *InstanciaAreaAtracamento, Navio *InstanciaNavio)
{
    //Coloca o Navio na fila de espera
    Enfileira(&(InstanciaAreaAtracamento->filaLocal), InstanciaNavio);
    //Atualiza variavel de controle da fila informando o custo que o barco adicionou a fila

    InstanciaAreaAtracamento->nContainersFila += (int)NumeroContainersNavio(InstanciaNavio);

    //Inicializa o tempo de espera do Navio
    InstanciaNavio->tempoEntrada++;
}

//Atraca um barco respeitando a regra de negocio
void AtracaNavio(AreaAtracamento *Instancia)
{
    //So se atraca um navio caso não tenha outro ja atracado
    if (Instancia->navio == NULL)
    {
        //So é possivel atracar um navio se existir um navio para ser atracado
        if (Instancia->filaLocal.tamanho != 0)
        {
            //Atraca o primeiro navio da fila
            Instancia->navio = Desenfileira(&(Instancia->filaLocal));
            
            //Diminui a quantidade de Containers na fila
            int numeroContainersNavio = NumeroContainersNavio(Instancia->navio);
            Instancia->nContainersFila -= numeroContainersNavio;

            //PERIGO NÃO LEMBRO O PORQUE DISSO
            if(!NavioValido(*(Instancia->navio))){
                free(Instancia->navio);
                Instancia->navio = NULL;
            }
        }
    }
}
//Desempilha um barco atracado e empilha uma travessa
int TransferenciaNavioParaTravessa(AreaAtracamento *InstanciaAreaAtracamento, Travessa *InstanciaTravessa)
{
    //So se pode desempihlar um navio caso ele esteja atracado
    if (InstanciaAreaAtracamento->navio != NULL)
    {

        //So se pode desempilhar container do barco se o barco tiver um container
        if (_VerificaNavioAtracadoPossuiContainers(InstanciaAreaAtracamento))
        {
            //So se pode empilhar em uma   travessa se ela estiver disponivel
            if (TravessaDisponivel(InstanciaTravessa))
            {
                //Procura a Maior Pilha e desempilha dela
                int indiceMaiorPilha = _VerificaMaiorPilhaContainerNavioAtracado(InstanciaAreaAtracamento);
                //Tenta Desempilhar no Navio
                if(Desempilha(&(InstanciaAreaAtracamento->navio->pilhaContainers[indiceMaiorPilha]))){
                    //Empilha Na Travessa
                    int retorno = Empilha(&(InstanciaTravessa->containers),1);
                    return retorno;
                }
                return 0;
            }
        }
    }
    return ERRO;
}

//Tem navio mas nao tem containers
Navio *DespachaNavioAreaAtracamento(AreaAtracamento *Instancia)
{
    //So se despacha um Navio caso haja um Navio
    if (Instancia->navio != NULL)
    {
        //So se Despacha o Navio caso ele não tenha mais Container
        if (!_VerificaNavioAtracadoPossuiContainers(Instancia))
        {   
            Navio *aux = Instancia->navio;
            Instancia->navio = NULL;
            return aux;
            //DeletaNavio(Instancia->navio);
        }
    }
    return NULL;
}

//Verifica se há Navio Atracado
int NavioAtracado(AreaAtracamento *Instancia)
{
    //Verifica se tem navio
    if (Instancia->navio != NULL)
    {
        return OK;
    }
    else
    { //Não tem navio
        return ERRO;
    }
}
//Metodos Internos
//Verifica se o navio atracado possui containers
int _VerificaNavioAtracadoPossuiContainers(AreaAtracamento *Instancia)
{
    //So se Verifica um Navio caso haja um Navio
    if (Instancia->navio != NULL)
    {
        Navio navio = *(Instancia->navio);
        //Verifica se há containers em cada pilha do navio
        int flagNavioVazio = 1;
        for (int numeroPilha = 0; numeroPilha < NumeroPilhasContainersNavio; numeroPilha++)
        {
            if (navio.pilhaContainers[numeroPilha].topo != 0)
            {
                flagNavioVazio = 0;
                break;
            }
        }
        return !flagNavioVazio;
    }
    return ERRO;
}

//retorna o indice da pilha do barco atracado que possui mais containers
int _VerificaMaiorPilhaContainerNavioAtracado(AreaAtracamento *Instancia)
{
    int indiceMaiorPilha = -1;
    //So se Verifica um Navio caso haja um Navio
    if (Instancia->navio != NULL)
    {
        Navio navio = *(Instancia->navio);
        //Procura a Maior Pilha de containers
        int tamanhoMaiorPilha = 0;
        for (int numeroPilha = 0; numeroPilha < NumeroPilhasContainersNavio; numeroPilha++)
        {
            int tamanhoPilha = navio.pilhaContainers[numeroPilha].topo;
            if (tamanhoMaiorPilha < tamanhoPilha)
            {
                tamanhoMaiorPilha = tamanhoPilha;
                indiceMaiorPilha = numeroPilha;
            }
        }
    }
    return indiceMaiorPilha;
}