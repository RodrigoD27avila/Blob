#!/usr/bin/env python

from gi.repository import Gtk
from gi.repository import WebKit

class Browser (Gtk.ScrolledWindow):
  def __init__ (self, url):

    Gtk.ScrolledWindow.__init__ (self)
    self.webview = WebKit.WebView()
    self.add (self.webview)
    self.webview.open (url)

if __name__ == '__main__':

  win = Gtk.Window()
  bro = Browser('http://google.com.br')
  win.add (bro)
  win.connect('destroy', Gtk.main_quit)
  win.show_all()
  Gtk.main()
