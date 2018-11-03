#!/usr/bin/env python
from Tkinter import *
root = Tk ()

c = Canvas (root, width=200, height=100)
c.pack ()
c.create_line (0, 0, 200, 100, fill='red', dash=(4, 4))
c.create_rectangle (50, 25, 150, 75, fill='blue')
for x in xrange(0, 100, 2):
	c.create_line (0, (x + 5), 200, 100, fill='red', dash=(4, 4))
#c.delete (ALL)
root.mainloop ()

