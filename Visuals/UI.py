import tkinter as tk
win = tk.Tk()
win.title("Vinny the Primate")

e = tk.Label(win, width=20, borderwidth=5)
e.grid(row=0, column=0, padx=10, pady = 10)

num = 1
e.config(text=str(num))

def Click():
    global num
    num += 1
    e.config(text=str(num))

def Clear():
    global num
    e.config(text='1')
    num = 1


yes =   tk.Button(win, text="Yes", width=10, height=1, borderwidth=5, command = Click).grid(row=1, column=0)
prob =  tk.Button(win, text="Probably", width=10, height=1, borderwidth=5, command = Click).grid(row=2, column=0)
IDK =   tk.Button(win, text="I don't know", width=10, height=1, borderwidth=5, command = Clear).grid(row=3, column=0)
Nprob = tk.Button(win, text="Probably not", width=10, height=1, borderwidth=5, command = Click).grid(row=4, column=0)
no =    tk.Button(win, text="No", width=10, height=1, borderwidth=5, command = Click).grid(row=5, column=0)

win.mainloop()
