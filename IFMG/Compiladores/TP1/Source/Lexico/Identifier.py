
import re

class Identifier:
    """Identifica se a string é comaptivel com o Afd"""
    def __init__(self):
        self.reserved = ["as","else","function","if","new","return","type","var","while"];
        # self.typesRe = {
        #     "reservado" : re.compile("(as)|(else)|(function)|(if)|(new)|(return)|(type)|(var)|(while)"),
        #     "id" : re.compile("(_|[a-z]|[A-Z])(_|[a-z]|[A-Z]|[0-9])*"),
        #     "number" : re.compile("(-)?([0-9])([0-9])*"),
        #     "string" : re.compile("(\'.*\')|(\".*\")"),
        #     "operadorBoolean" : re.compile("(==)|(~=)|(<=)|(>=)|(<)|(>)|(!)|(&&)|(||)"),
        #     "operadorAritmetico" : re.compile("(\+)|(\-)|(\*)|(/)"),
        #     "operadorTernario" : re.compile("(\?)|(:)"),
        #     "bloco" : re.compile("({)|(})"),
        #     "precedencia" : re.compile("(\()|(\))"),
        #     "acesso" : re.compile("(\[)|(\])|(\.)"),
        #     "atribuicao" : re.compile("="),
        #     "fim" : re.compile(";"),
        #     "outros" : re.compile("@"),
        #     "comentario" : re.compile("#(.*)\\n")
        # }

        self.typesRe = {
            "reservado" : re.compile("(as)|(else)|(function)|(if)|(new)|(return)|(type)|(var)|(while)"),
            "id" : re.compile("(_|[a-z]|[A-Z])(_|[a-z]|[A-Z]|[0-9]){0,31}"),
            "numberHex" : re.compile("(-)?((0x)([0-9]|[A-F]|[a-f])*)"),
            "number" : re.compile("(-)?((([0-9])+(\.)?([0-9])*))"),
            "operadorBoolean" : re.compile("(==)|(~=)|(<=)|(>=)|(<)|(>)|(!)|(\&&)|(\|\|)"),
            "operadorAritmetico" : re.compile("(\+)|(\-)|(\*)|(/)"),
            "operadorTernario" : re.compile("(\?)|(:)"),
            "bloco" : re.compile("({)|(})"),
            "precedencia" : re.compile("(\()|(\))"),
            "acesso" : re.compile("(\[)|(\])|(\.)"),
            "multiplo" : re.compile(","),
            "atribuicao" : re.compile("="),
            "fim" : re.compile(";"),
            "outros" : re.compile("@"),
            "comentario" : re.compile("#(.*)\\n"),
            "erro":re.compile("(~)|(\&)|(\|)") #Gambiarra
        }

    def vetor(self,string):
        """Retorna um vetor informando quais os possiveis tipos para a string"""
        vetRetorno = [];
        for tipo, regex in self.typesRe.items():
            vetRetorno.append( self.match(string,regex) );
        return vetRetorno;
    
    def types(self,string):
        """Retorna um vetor informando quais os possiveis tipos para a string"""
        vetRetorno = [];
        for tipo, regex in self.typesRe.items():
            if(self.match(string,regex)):
                vetRetorno.append(tipo);
        return vetRetorno;

    def match(self, string, regex):
        """Verifica se a string é compativel com o Afd 'regex'"""
        expressao = re.compile(regex);
        return (expressao.fullmatch(string) != None);
    
    def finishToken(self, vetAnterior,vetPosterior):
        """Verifica se o vetor anterior era valido e o posterior é invalido"""
        flagVetAnt = False;
        flagVetPos = False;
        for atual in vetAnterior:
            flagVetAnt = flagVetAnt or atual;
        for atual in vetPosterior:
            flagVetPos = flagVetPos or atual;
        return (flagVetAnt== True) and (flagVetPos==False);
    
    def erroToken(self, vetAnterior,vetPosterior):
        """Verifica se o vetor é invalido"""
        flagVetAnt = False;
        flagVetPos = False;
        for atual in vetAnterior:
            flagVetAnt = flagVetAnt or atual;
        for atual in vetPosterior:
            flagVetPos = flagVetPos or atual;
        return (flagVetAnt== False) and (flagVetPos==False);


