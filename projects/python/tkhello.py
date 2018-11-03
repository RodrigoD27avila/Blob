#!/usr/bin/python

from Tkinter import *
root = Tk ()
mycontainer1 = Frame (root)
mycontainer1.pack ()

button1 = Button (mycontainer1)
button1["text"] = "Hello World"
button1["background"] = "red"
button1.pack ()

label1 = Label (mycontainer1)
label1["text"] = "Rodrigo D'avila"
label1.pack ()

root.mainloop ()
