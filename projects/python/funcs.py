#!/usr/bin/env python

import time
from threading import Thread

class D(Thread):
  def __init__(self):
    Thread.__init__ (self)

  def run(self):
    self.update(None)

  def update(self,func):
    self.func = func

    if not self.func:
      while True:
          try:
            self.func()
          except:
            continue
          finally:
            #print ("sleep")
            time.sleep (0.100)

if __name__ == '__main__':
  d = D()
  d.start()

  def foo():
    d.update(foo)

  d.update (foo)
