from itertools import combinations
from fractions import Fraction

def rmul(T):
	re = 1;
	for x in T:
		re *= x
	return re

def solvecomb(L, n):
	re = 0;
	for x in combinations(L, r=n):
		re += rmul(x)
	return re;

def poly(X):
	po = []
	for x in range(len(X)+1):
		solv = solvecomb(X, x)
		po.append((x % 2) != 0 and -solv or solv)
	return po

def first(X, Fx, Res, l, s, B):
	if l == 1: return
	else:
		backup = []
		for x in range(1, l):
			r = Fraction(Fx[x]-Fx[x-1], X[(x-1)+s]-X[x-1])
			Fx[x-1] = r; backup.append(r)
			if x == 1: Res.append(r)
		B.append(backup)
		first(X, Fx, Res, l-1, s+1, B)

def formul(X, Re):
	form = []
	for x in range(len(X)):
		po = poly(X[0:x])
		po.reverse()
		form.append((Re[x], po))
	return form

def makeformul(X, Re):
	form = [0]*len(X)
	f = formul(X, Re)
	for c, pol in f:
		for x in range(len(pol)):
			form[x] += pol[x] * c
	form.reverse()
	return form

def maketree(Ba):
	re  = [''] * len(Ba)
	for x in range(len(Ba)):
		for y in range(len(Ba[x])):
			re[y] += '{0}\t'.format(Ba[x][y])
	return re
		

if __name__ == '__main__':
	#X  = [Fraction(x) for x in [1,-2,-3, 4]]
	#Fx = [Fraction(x) for x in [6, 4,-2,-5]]
	
	#X  = [Fraction(x) for x in [1, -2, -3,  4]]
	#Fx = [Fraction(x) for x in [6,  4, -2, -5]]
	
	X  = [Fraction(x) for x in [3, -2, 5,  1, -7]]
	Fx = [Fraction(x) for x in [5,  -3, 4, -8, 12]]
	Xr = 5

	Res = []
	Res.append(Fx[0])
	Backup = []
	Backup.append(X[::])
	Backup.append(Fx[::])

	first(X, Fx, Res, len(Fx), 1, Backup)
	form2 = makeformul(X, Res)

	Re = 0	
	p = len(form2)-1
	finalform = ''
	for x in range(len(form2)):
		finalform += ' {0}*x**{1}'.format(form2[x], p)
		Re += form2[x]*Xr**p; p-=1
	
	for x in maketree(Backup):
		print(x)

	print(finalform)
	print('Result for {0} = {1}'.format(Xr, Re))
