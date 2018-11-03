#!/usr/bin/env python

import os

class MyFork:
  def __init__ (self, funcs):
    self.funcs = funcs;

  def execute (self):
    try:
      # get the functions to execute
      f = funcs.pop()
      id = os.fork ()

      if (id == 0):
          self.execute ()

      else:
        print (os.getpid(), " initializing....")
        f[0] (f[1])
        print (os.getpid(), " finalizing....")
        
    except (IndexError) as e:
      print ("All executions are starting!!")

if __name__ == '__main__':

  def print_sum (t):
    s = 27
    t.reverse()
    for x in t:
      s = (x ** s)
    return s

  funcs = [
    [print_sum, [2,2]],
    [print_sum, [2,2]],
    [print_sum, [2,2]],
    [print_sum, [2,2]],
    [print_sum, [2,2]]
    ]

  f = MyFork (funcs)
  f.execute ()
