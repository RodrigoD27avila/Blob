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

def comb(X):
	re = []
	for x in range(len(X)):
		Xi = X[::]; del Xi[x]
		c = []
		for y in range(len(X)):
			solv = solvecomb(Xi, y)
			#if (y % 2) != 0:
			#	solv *= -1
			c.append((y % 2) != 0 and -solv or solv)
		re.append(c)
	return re

def divcom(L, X):
	re = 0; p=len(L)-1
	for x in range(len(L)):
		re += L[x] * X**p
		p -= 1
	return re

def lagrange(X, Y):
	lagr = []
	co = comb(X)
	for x in range(len(Y)):
		re = 0
		for y in range(len(Y)):
			re += Y[y] * (Fraction(co[y][x], divcom(co[y], X[y])))
		lagr.append(re)
	return lagr	

if __name__ == '__main__':
	X = [1, 2, 3,  4, 5, 6, 7]
	Y = [1, 4, 8, 16, 32, 64, 128]

	Xr = Fraction(7,1)
	Re = 0
	
	la = lagrange(X, Y)
	p = len(la)-1
	finalform = ''
	for x in range(len(la)):
		finalform += " {0}*x**{1}".format(la[x], p)
		Re += la[x] * Xr ** p; p -= 1
	print(finalform)
	print ("Result for {0} = {1}".format(Xr, Re))
