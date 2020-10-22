import tkinter as tk

class Application(tk.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.master = master
        self.master.title("Teste")
        self.master.geometry("600x800")
        self.dicLayout = {}
        self.layoutMain()

    def layoutMain(self):
        frameGlobal = self.newFrame(master=self.master, side='top')
        #Insert
        self.line(frame=frameGlobal, text='Inserir Tabela Pessoas')
        insertPessoa = self.layoutInsertPessoa(frame=frameGlobal)
        #Select
        self.line(frame=frameGlobal, text='Selecione Tabela Pessoas')
        selectPessoa = self.layoutSelectPessoa(frame=frameGlobal)
        #Delete
        self.line(frame=frameGlobal, text='Delete Tabela Pessoas')
        deletePessoa = self.layoutDeletePessoa(frame=frameGlobal)
        #Update
        self.line(frame=frameGlobal, text='Atualiza Tabela Pessoas')
        updatePessoa = self.layoutUpdatePessoa(frame=frameGlobal)
        #Lista
        self.line(frame=frameGlobal, text='-'*28)
        lista = self.insertLayoutList(frame=frameGlobal)



    def newFrame(self, master=None, side='top'):
        """Cria um frame"""
        frame = tk.Frame(master)
        frame.pack(side=side)
        return frame

    def insertInput(self, frame=None, txtLabel='', nameInp=''):
        """ Cria uma linah com Label + Input"""
        f = self.newFrame(frame)
        #Label
        label = tk.Label(f, text=txtLabel)
        label.pack(side='left')
        #Campo Input
        input = tk.Entry(f, textvar=nameInp)
        input.pack(side='left')
        return input

    def titulo(self, frame=None, text=''):
        #Cria um titulo
        label = tk.Label( frame, text=text)
        label.pack(side='top')
    
    def line(self, frame=None, text=''):
        #Cria um titulo
        content = str( str('-'*40)+ text+ str('-'*40) )
        label = tk.Label(frame, text=content)
        label.pack(side='top')

    def layoutInsertPessoa(self, frame=None):
        """Cria o Inset da tabela Pessoa"""
        #Cria os Frames
        frameG = self.newFrame(master=frame, side='top')
        frameL = self.newFrame(master=frameG,side='left')
        frameR = self.newFrame(master=frameG,side='left')
        #Cria N linha
        nome = self.insertInput(frameL,"Nome\t","nome1")
        cpf = self.insertInput(frameL,"Cpf\t","cpf1")
        email = self.insertInput(frameL,"E-mail\t","email1")
        uf = self.insertInput(frameL,"UF\t","uf1")
        #Cria um botão
        bt = tk.Button(frameR,text="Inserir", padx=50,bg='green')
        bt.pack(padx=50,pady=50)
        frameG.pack()

        #Persiste um ponteiro em escopo da classe para um elemento dentro do layout
        self.dicLayout['insert']={
            "bt":bt,
            "nome":nome,
            "cpf":cpf,
            "email":email,
            "uf":uf
        }
        return frameG

    def layoutSelectPessoa(self, frame=None):
        """Cria o Inset da tabela Pessoa"""
        #Cria os Frames
        frameG = self.newFrame(master=frame, side='top')
        frameL = self.newFrame(master=frameG,side='left')
        frameR = self.newFrame(master=frameG,side='left')
        #Cria linha de input 
        cpf = self.insertInput(frameL,"Cpf\t","cpfSelect1")
        #Cria um botão
        bt = tk.Button(frameR,text="Selecionar", padx=50,bg='green')
        bt.pack(padx=50)   
        frameG.pack()
        #Persiste um ponteiro em escopo da classe para um elemento dentro do layout
        #Persiste um ponteiro em escopo da classe para um elemento dentro do layout
        self.dicLayout['select']={
            "bt":bt,
            "cpf":cpf
        }
        return frameG
    
    def layoutDeletePessoa(self, frame=None):
        """Cria o Inset da tabela Pessoa"""
        #Cria os Frames
        frameG = self.newFrame(master=frame, side='top')
        frameL = self.newFrame(master=frameG,side='left')
        frameR = self.newFrame(master=frameG,side='left')
        #Cria linha de input 
        id = self.insertInput(frameL,"Id\t","id1")
        #Cria um botão
        bt = tk.Button(frameR,text="Deletar", padx=50,bg='green')
        bt.pack(padx=50)   
        frameG.pack()
        #Persiste um ponteiro em escopo da classe para um elemento dentro do layout
        #Persiste um ponteiro em escopo da classe para um elemento dentro do layout
        self.dicLayout['delete']={
            "bt":bt,
            "id":id
        }
        return frameG

    def layoutUpdatePessoa(self, frame=None):
        """Cria o Inset da tabela Pessoa"""
        #Cria os Frames
        frameG = self.newFrame(master=frame, side='top')
        frameL = self.newFrame(master=frameG,side='left')
        frameR = self.newFrame(master=frameG,side='left')
        #Cria N linha
        id = self.insertInput(frameL,"Id\t","id2")
        nome = self.insertInput(frameL,"Nome\t","nome2")
        cpf = self.insertInput(frameL,"Cpf\t","cpf2")
        email = self.insertInput(frameL,"E-mail\t","email2")
        uf = self.insertInput(frameL,"UF\t","uf2")
        #Cria um botão
        bt = tk.Button(frameR,text="Atualizar", padx=50,bg='green')
        bt.pack(padx=50,pady=50)
        frameG.pack()
        #Persiste um ponteiro em escopo da classe para um elemento dentro do layout
        self.dicLayout['update']={
            "bt":bt,
            "id":id,
            "nome":nome,
            "cpf":cpf,
            "email":email,
            "uf":uf
        }
        return frameG
    
    def insertLayoutList(self, frame=None):
        """Cria o Inset da tabela Pessoa"""
        #Cria os Frames
        frameG = self.newFrame(master=frame, side='top')
        frameL = self.newFrame(master=frameG,side='left')
        frameR = self.newFrame(master=frameG,side='left')
        #Cria um botão
        listB = tk.Listbox(frameR, height=50, width=90)
        listB.pack(padx=50,pady=50)
        frameG.pack()
        #Persiste um ponteiro em escopo da classe para um elemento dentro do layout
        self.dicLayout['lista']={
            "lista":listB
        }
        return frameG
        
"""
root = tk.Tk()
app = Application(master=root)
app.mainloop()
"""