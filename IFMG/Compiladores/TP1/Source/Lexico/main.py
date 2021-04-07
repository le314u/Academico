import sys
import argparse
import Scan


def argumentos():
    parser = argparse.ArgumentParser(description='Analizador Lexico apresentado à disciplina de Compiladores, como requisito parcial de conclusão da matéria. Implementado por Lucas Mateus Fernandes RA:0035411')
    parser.add_argument(action = 'store', type=str, dest = 'path_Source', help = 'Caminho para o arquivo que vai ser analisado')
    parser.add_argument('-t','--table', action = 'store', type=str, dest = 'path_Out', required = False, help = 'Caminho para armazenar a tabela de simbolos')
    parser.add_argument('-s','--size', action = 'store', type=int, dest = 'sizeBuffer', default=1024, required = False, help = 'tamanho do Buffer de leitura')
    parser.add_argument('-p','--pretty', action = 'store_true', help = 'Printa a saida na tela')
    args = parser.parse_args()
    return args

def main():
    #Trata os argumentos
    args = argumentos()
    
    #Roda o analizador Lexico    
    lexico = Scan.Scan(args.path_Source, args.sizeBuffer)

    #Persistencia
    if not (args.path_Out is None):
        fileOut = open(args.path_Out, "w")
        for token in lexico.tokens:
            fileOut.write(token)
        fileOut.close()
    
    #Saida Agradavel
    if(args.pretty):
        for token in lexico.tokens:
            print(token)
            
    return 0
 
if __name__ == '__main__':
    sys.exit(main())