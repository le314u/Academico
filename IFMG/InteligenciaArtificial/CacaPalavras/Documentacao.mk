# Escopo

O trabalho aqui expresso tem como finalidade gerar um caça palavras por meio de algoritimo genetico

#### Requisitos
* Python3
* Distribuição Linux

#### Parametros de entrada
* Arquivo com as palavras (não pode ter palavras repetidas)
* Caracter delimitador de palavras

#### Saidas
* Arquivo .html com o caça palavras
* Arquivo .html com gabarito do caça palavras
* ~~Arquivo json com meta dados  referente ao processo de criação~~(implementação futura)
  
# Estrutura de Dados

#### Representação Cromossomo
* Possui Palavra
* Linha de inicio
* Coluna de inicio
* Sentido (horizontal,vertical,diagonal)

#### Representação Individuo
* Possui uma lista de cromossomos(denominado genes)
* idade
* Fitness
* Para evitar colisões e palavras coladas, foi considerado que o espaço que ela ocupa é igual (tamanho * tamanho) para peças na diagonal (tamanho * tamanho/2) para peças na horizontal ou vertical

#### Representação Fitness
* O problema foi tratado como sendo uma permutação 
* Sempre que um individuo é criado é reposicionada todas as palavras e é calculado o fitnes
* Quanto maior o numero de palavras inseridas na Matriz maior o fitness
* Quanto maior a variabilidade de sentido (Vertical, Horizontal, Diagonal) das palavras ja implementadas maior o fitness
* Formula do Fitnes (variabilidadeSentido * (TamanhoDeCadaPalavra * 0.1 + QuantidadePalavrasValdias))

#### Critérios de Parada
* Encerrar evolução após n gerações

#### Critérios da População
* Ao exceder a uma idade 'x' os individuos são descartados exceto o melhor individuo que sempre é adicionado a populaçaão

#### Operações de mutação
* Não existe Mutação

#### Seleção dos Pais
* Metodo da Roleta (deu-se a preferencial pelo fato de evitar uma elitização de individuos tendo convergencia previa para um otimo local)
