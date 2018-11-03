#!/usr/bin/env python

f = open('/home/rdapache/numperfpy', 'a')
g = open('/home/rdapache/numperf')
h = str(g.read())
f.write(h)
g.close()
f.close()
