import tkinter as tk

class Application(tk.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.master = master
        self.master.title("Teste")
        self.master.geometry("600x500")

        canvas = tk.Canvas(master=master)
        scrollbar = tk.Scrollbar( master , orient = tk.VERTICAL, command = canvas.yview)
        canvas.configure(yscrollcommand=scrollbar.set)
        canvas.pack()

        
        #Insert
        self.line(text='Inserir Tabela Pessoas')
        insertPessoa = self.layoutInsertPessoa(frame=canvas)
        #Select
        self.line(text='Select Tabela Pessoas')
        selectPessoa = self.layoutSelectPessoa(frame=canvas)



    def scroll(self, frame=None):
        scrollbar = tk.Scrollbar(frame)
        scrollbar.pack( side = tk.RIGHT, fill = tk.Y )
        return scrollbar

    def newFrame(self, master=None, side='top'):
        """Cria um frame"""
        frame = tk.Frame(master)
        frame.pack(side=side)
        return frame

    def insert(self, frame=None, txtLabel='', nameInp=''):
        """ Cria uma linah com Label + Input"""
        f = self.newFrame(frame)
        #Label
        label = tk.Label(f, text=txtLabel)
        label.pack(side='left')
        #Campo Input
        input = tk.Entry(f, textvar=nameInp)
        input.pack(side='left')

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
        self.insert(frameL,"Nome\t","nome")
        self.insert(frameL,"Cpf\t","cpf")
        self.insert(frameL,"E-mail\t","email")
        self.insert(frameL,"UF\t","uf")
        #Cria um botão
        bt = tk.Button(frameR,text="Teste", padx=50,bg='green')
        bt.pack(padx=50,pady=50)
        frameG.pack()
        return frameG

    def layoutSelectPessoa(self, frame=None):
        """Cria o Inset da tabela Pessoa"""
        #Cria os Frames
        frameG = self.newFrame(master=frame, side='top')
        frameL = self.newFrame(master=frameG,side='left')
        frameR = self.newFrame(master=frameG,side='left')
        #Cria linha de input 
        self.insert(frameL,"Cpf\t","cpfSelect")
        #Cria um botão
        bt = tk.Button(frameR,text="Teste", padx=50,bg='green')
        bt.pack(padx=50)   
        frameG.pack()
        return frameG

    def say_hi(self):
        print("hi there, everyone!")

root = tk.Tk()
app = Application(master=root)
app.mainloop()