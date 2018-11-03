#/usr/bin/env python
# -*- coding: utf-8 -*-

class T:
    
    def __init__ (self):
        self.a = 10
        self.b = 11

class Y (T):
    pass

if __name__ == '__main__':
    y = Y()
    print (y.a)
    print (y.b)