#!/usr/bin/env python

import os

class MyFork:
  def __init__ (self):
    self.i = 0;

  def execute (self):
    id = os.fork ()

    if (id == 0):
      if (self.i < 10):
        self.i += 1
        self.execute ()

    else:
      print (os.getpid(), " - " ,str (self.i))

if __name__ == '__main__':
  f = MyFork ()
  f.execute ()
