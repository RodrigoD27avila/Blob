#!/usr/bin/env python

import time
from threading import Thread

class D(Thread):
  def __init__(self):
    Thread.__init__ (self)
    self.i = 0

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
            print (self.i)
            self.i += 1
            time.sleep (1.010)

def main():
  d = D()
  d.start()

  def foo():
    d.update(foo)

  d.update (foo)
if __name__ == '__main__':
  main()
