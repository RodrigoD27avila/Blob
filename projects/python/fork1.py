#!/usr/bin/env python

import os

def myfork ():
  id = os.fork ()
  if (id == 0):
    myfork ()
  else:
    print (os.getpid ())

if __name__ == '__main__':
  myfork ()
