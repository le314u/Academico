def Input():
    """Recebe os dados do Usuario"""
    # C é o custo para comprar
    # N é numero de dias que foi acompanhada as ações
    N, C = map(int, input().split(" "))
    cotacoes = list(map(int, input().split(" ")))
    return (N,C,cotacoes)

def Solve(): # O()
    N,C,cotacoes = Input()
    cotacoes = cotacoes[0:N]
    #N, C = 6,10
    #cotacoes = [40,100,50,90,40,100]
    print(lucroMax(cotacoes, N, C))

def lucroMax(historico, dias, taxa):
    momentoCompra = historico[0]
    momentoVenda = historico[0]
    lucroTotal = 0
    pseudoLucro = 0 #Ultimo
    trade = True # Confirma que  a ação foi comprada e vendida
    for i in range(len(historico)):
        #valor trabalhado
        valorReferencia = historico[int(i)]

        #print("A:",valorReferencia,"\tC:",momentoCompra,"\tV:",momentoVenda,"=",lucroTotal)

        #Verifica Momento de Compra
        if( (valorReferencia < momentoCompra) or ( (valorReferencia + taxa) < momentoVenda )):
            #Verifica se ocorreu a Compra e Venda
            pseudoLucro = momentoVenda - momentoCompra - taxa
            if(pseudoLucro > 0 and valorReferencia < momentoVenda):
                lucroTotal = lucroTotal + pseudoLucro
                pseudoLucro = 0
            #Att a Compra
            momentoCompra = valorReferencia
            momentoVenda = valorReferencia
        
        #Verifica Momento da Venda
        if(momentoVenda < valorReferencia):
            #Att a Venda
            momentoVenda = valorReferencia

    pseudoLucro = momentoVenda - momentoCompra - taxa   
    if(pseudoLucro > 0):
        lucroTotal = lucroTotal + pseudoLucro
        pseudoLucro = 0
    return lucroTotal

Solve()