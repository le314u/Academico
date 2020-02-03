# Simulador de Porto

## Autor  
Lucas Mateus Fernandes  
Ra 0035411  



## Modulos
+ Log em Arquivo
+ ~~Tratamento de Log~~ **(implementação futura)**
+ Gerar Documentacao em Markdown
+ ~~Fluxo em thread~~ **(Não é possivel garantir a ordem de execução o que atrapalharia na contagem de tempo)**



# Escopo trabalho

## Estrutura Projeto
+ Um porto possui '4' Areas de Atracamento com uma grua cada
+ A Grua é responsavel por desempilhar um container no navio e empilha-lo na travessa e a realização dos dois procedimentos consecutivos tem um custo de uma unidade de tempo
+ Em todo o porto existem 5 travessas que podem ser acessadas por qualquer grua
+ Cada Travessa tem am capacidade maxima de 5 containers empilhados
+ Cada Area de atracamento possui seu proprio 'straddle carries' responsavel por retirar uma travessa Cheia e retornar com uma travessa vazia e tal operação gasta uma unidade de tempo
+ Apenas um navio pode se posicionar em uma area de Atracamento
+ Cada Area de Atracamento possui uma fila de espera com os navios a serem atracados nela
+ Log armazena o que ocorre a cada unidade de tempo.
	+ o ID dos navios que estão na fila;
	+ o tempo médio de espera para cada área de atracamento;
	+ a situação das áreas de atracamento (quantidade de contêiners em cada travessa);
	+ a movimentação dos veículos que transportaram as travessas para o pátio de armazenamento, ou seja, quantas vezes eles executaram o transporte das travessas do atracamento para o pátio..



### Estrutura de Dados
+ Pilha Estatica para representar os containers na travessa
+ Pilha Estatica representar o containers no Navio
+ Fila Dinamica para representar os barcos que estão esperando para atracarem
+ Fila Dinamica para realizar o processo de Escalonamento dos Barcos que chegam ao porto
+ O porto é representado por uma Unica Struct
+ Area de Atracamento é representada por uma unica Struct
+ Travessa é representada por uma unica Struct
+ Os straddle carries NÃO são representados por structs porem há processos que simulam o seu funcionamento
+ Navio é representado por uma unica struct
+ Containers são representados atraves de uma pilha de numeros inteiros
+ As filas de barcos são representados por um TAD de fila dinamica sendo o elemento/item o proprio barco

## Observação
+ Dado a informação "Cada navio tem a capacidade máxima de carregar até 16 contêiners, que
podem ser distribuídos em até 4 pilhas." estou considerando que a capacidade de cada pilha de containers dentro do barco pode ter empilhado no maximo 4 containers e que os containers tem que ser divididos uniformemente entre as pilhas ("isso evitaria que o peso do barco se concentrasse em um unico hemisferio do navio")

+ Dado a informação "O seu controle não deverá permitir que as travessas fiquem cheias por mais de uma unidade de tempo pois assim os navios ficarão esperando muito tempo na fila de espera para o atracamento." estou considerando que quando uma travessa fica cheia o transporte da travessa junto com a volta do carrinho com uma travessa vazia custa uma unidade de tempo

+ Mesmo com a informação "A cada unidade de tempo, de 0 a 3
navios podem chegar em uma das 4 (quatro) filas para atracamento, que deverão manter uma
uniformidade de tamanho" que da a entender que todos os navios chegaram em uma fila e logo em seguida da a entender que deve ser distribuidos uniformemente, como decisao de projeto, foi definido que os barcos chegam em uma unica fila denominada 'fila de espera ' e os barcos nesta fila são distribuidos nas filas locais de cada Area de atracamento afim de evitar que alguma area tenha grua ociosa;

+ Mesmo que em nivel de programação seja sequencial assumisse que todas gruas e 'straddle carries' estão  atuando de forma paralela.



## Arquivos
| |          |	                                                      |
|-|----------|--------------------------------------------------------|
| |[makefile](makefile)												|Compila os arquivos na sequência correta respeitando todas as dependências|
| |[Objects](Objects/)												|Pasta onde vão todos os codigos objetos '.o'|
| |[estruturaAreaAtracamento.c](Source/estruturaAreaAtracamento.c)	|Representaçao da Area de Atracamento|
| |[estruturaNavio.c](Source/estruturaNavio.c)						|Representacao de um Navio|
| |[estruturaPorto.c](Source/estruturaPorto.c)						|Representacao de um Porto|
| |[estruturaTravessa.c](Source/estruturaTravessa.c)				|Representacao de um Travessa|
| |[filaDinamica.c](Source/filaDinamica.c)							|TAD Fila de Navios Encadeada|
| |[main.c](Source/main.c)											|Possui o Fluxo Procedural mais Externo do programa|
| |[pilhaEstatica.c](Source/pilhaEstatica.c)						|TAD Pilha de inteiros estática|
| |[view.c](Source/view.c)											|Exibição do que esta acontecendo no porto em cada unidade de tempo |
| |[log.c](Source/log.c)											|Log em Json |

##Diagrama de Classe / dependencias das entidades
![](Diagrama.png)






pilha.topo = -1 significa que ela esta indisponivel
