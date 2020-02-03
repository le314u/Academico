# Indice Remissivo em 'n' estruturas
## Autor  
Lucas Mateus Fernandes  
Ra 0035411  

# Escopo trabalho
Ler um arquivo 'txt' puro.  
Gerar um indice remissivo em 4 estruturas diferentes.  
Analisar o Custo de Implementação em cada estrutura.   

## Estruturas
* Árvore Binária de Busca
* Árvore AVL
* Tabela Hash
* Lista


## Estrutura de Dados
A cada palavra lida do arquivo, é gerado um objeto palavra que possui as seguintes caracteristicas.
* Palavra
* Conjunto que contem as linhas em que a palavra aparece no texto original.
    * Tal estrutura  é uma Árvore Binária de Busca escolhida pela facilidade em inserir um elemento sem duplicidade.

## Observação  
* Será gerado um arquivo de saida para cada estrutura implementada, qualquer divergencia nos arquivos significa que houve uma falha na implementação das etruturas.
* A implementação da palavra na estrutura é logo apos a leitura do arquivo a fim de não viciar a entrada de dados.
* O endereço do arquivo é passado via Linha de Comando pois 'geralmente' bash tem auto-complete, o que facilita na procura do documento.

## Arquivos
| |          |	                                                      |
|-|----------|--------------------------------------------------------|
| |          |	                                                      |

## Funcionamento Top Down 
1. É passado o endereço de um arquivo de texto puro por linha de comando.
2. É lido palavra por palavra.
3. Verifica se a palavra é válida, são palavras validas.  
    * Palavras com mais de 4 letras.
    * Palavras que não começam por numero ou caracteres especiais.
4. Insere a palavra em cada estrutura pre definida.
5. Contabiliza o tempo gasto na inserção.
6. Mostra o Indice remissivo em ordem alfabetica
7. Contabiliza o tempo gasto na leitura
8. Salva a saida em um arquivo 'txt'
9. Gera um relatorio com o tempo gasto


