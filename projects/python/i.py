#!/usr/bin/env python

import inspect
try:
  def infos (m):
      for name, data in inspect.getmembers (m):
       if name == '__builtins__':
         continue
       print (name, repr (data))

  def classes (m):
      for name, data in inspect.getmembers (m, inspect.isclass):
        if name == '__builtins__':
          continue
        print (name, repr (data))

  def functions (m):
      for name, data in inspect.getmembers (m, inspect.ismethod):
        if name == '__builtins__':
          continue
        print (name, repr (data))

  def foo():
    raise NotImplementedError("What the Fu**!!")

except (NotImplementedError) as err:
  print ('FUUUEHHH')
  print (err)

finally:
  print ("FUUUEH")
