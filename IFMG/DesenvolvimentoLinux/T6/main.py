import tkinter as tk

class Application(tk.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.master = master
        self.master.title("Teste")
        self.master.geometry("600x500")
        f = self.layoutInsertPessoa()
        f.place(x=0,y=0)

    def newFrame(self, master=None):
        """Cria um frame"""
        frame = tk.Frame(master)
        frame.pack(side='bottom')
        return frame

    def insert(self, frame, txtLabel, nameInp):
        """ Cria uma linah com Label + Input"""
        f = self.newFrame(frame)
        #Label
        label = tk.Label(f, text=txtLabel)
        label.pack(side='left', expand=1)
        #Campo Input
        input = tk.Entry(f, textvar=nameInp)
        input.pack(side='left', expand=3)

    def layoutInsertPessoa(self):
        """Cria o Inset da tabela Pessoa"""
        #Cria o Frame
        frame = self.newFrame()
        #Cria N linhas
        self.insert(frame,"Texto1",1)
        self.insert(frame,"Texto1",2)
        #Cria um button
        return frame

    def say_hi(self):
        print("hi there, everyone!")

root = tk.Tk()
app = Application(master=root)
app.mainloop()