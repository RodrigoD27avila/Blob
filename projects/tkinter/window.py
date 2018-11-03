#!/usr/bin/env python3

from tkinter import *

class MainWindow:

    def __init__(self, master):

        # Button OK
        self.ok = Button(name='ok', text='Ok')
        self.ok.pack(side=LEFT)

        # Button Cancel
        self.cancel = Button(name='cancel', text='Cancel')
        self.cancel.pack(side=RIGHT)

if __name__ == '__main__':
    root = Tk()
    MainWindow(root)
    root.mainloop()
