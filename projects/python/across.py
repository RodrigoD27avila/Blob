#!/usr/bin/python

class Across:

	def __init__ (self, lista):
		self.lista = lista
	
	def perm (self):
		l = self.lista[1:]
		l.append (self.lista[0])
		self.lista = l
	
	def ssum (self):
		a = self.lista
		b = self.lista[:]
		b.reverse ()
		print a
		print b
		print '============='
		self.normal([sum (a) for a in zip (*[a,b])])
		print
	
	def normal (self, l):
		for x in xrange (len (l)):
			if (l[x] > 255):
				l[x] = (l[x] - 256)

		print l

if __name__ == '__main__':
	a = Across ([a for x in xrange (256)])
	for x in xrange (256):
		a.ssum ()
		a.perm ()
	
