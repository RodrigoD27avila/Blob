#/usr/bin/env python
#-*- encoding: utf-8 -*-

import os
from threading import Thread

class C (Thread):

  def __init__ (self, n):
    Thread.__init__ (self)
    self.n = n;

  def run (self):
    print (os.getpid())
    print ("Conta %i Começou!!",self.n)
    2 ** (2 ** 27)
    print ("Conta %i Terminada!!", self.n)

if __name__ == '__main__':
  a =  C (0)
  b =  C (1)
  a.start ()
  b.start ()
