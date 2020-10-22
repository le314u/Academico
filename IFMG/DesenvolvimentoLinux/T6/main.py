import bd
import view

# Intancia a tela
app = view.Application(master=view.tk.Tk())

# Prepara o bd
db = bd.DB()
tabelaP = bd.Pessoa(db)

#funçoes BD

def inserir():
    #Alias
    element = app.dicLayout['insert']
    tabelaP.insert(
        str( element['nome'].get() ),
        str( element['cpf'].get() ),
        str( element['email'].get() ),
        str( element['uf'].get( ))
    ) 

def selecionar():
    #Alias
    element = app.dicLayout['select']
    lista = app.dicLayout['lista']['lista']
    elementosBD = tabelaP.select( str( element['cpf'].get() ) )
    lista.delete(0, view.tk.END)
    for e in elementosBD:
        id = str( e[0] )
        name = str( e[1] )
        cpf = str( e[2] )
        email = str( e[3] )
        uf = str( e[4] )
        newString = "id:"+id+"    name:"+name+"    cpf:"+cpf+"    email:"+email+"    uf:"+uf
        lista.insert(view.tk.END, newString)

def deletar():
    #Alias
    element = app.dicLayout['delete']
    tabelaP.delete( str( element['id'].get() ) )

def atualizar():
    element = app.dicLayout['update']
    tabelaP.update(
        str( element['id'].get() ), 
        str( element['nome'].get() ), 
        str( element['cpf'].get() ), 
        str( element['email'].get() ), 
        str( element['uf'].get() ) 
    )

#Linka o view com o bd
app.dicLayout['insert']['bt']['command'] = inserir
app.dicLayout['select']['bt']['command'] = selecionar
app.dicLayout['delete']['bt']['command'] = deletar
app.dicLayout['update']['bt']['command'] = atualizar

app.mainloop()
