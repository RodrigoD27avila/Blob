#!/usr/bin/python2

# ZetCode PyGTK tutorial 
#
# This code example draws a circle
# using the cairo library
#
# author: jan bodnar
# website: zetcode.com 
# last edited: February 2009


from gi.repository import Gtk
import math

class PyApp(Gtk.Window):

    def __init__(self):
        super(PyApp, self).__init__()

        self.set_title("Simple drawing")
        self.resize(230, 150)
        self.set_position(Gtk.WindowPosition.CENTER)

        self.connect("destroy", Gtk.main_quit)

        darea = Gtk.DrawingArea()
        darea.connect("draw", self.draw)
        self.add(darea)

        self.show_all()

    def draw(self, widget, cairo):
        print ("Drawing....")

PyApp()
Gtk.main()
