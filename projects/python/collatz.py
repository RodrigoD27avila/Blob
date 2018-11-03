class Collatz:

    def collatz (self, n):
        while (n > 1):
            print (" %i " % n),
            if ((n % 2) != 0):
                 n = ((3 * n) + 1)
            else:
                 n = (n / 2)
        print (n)
	  
if __name__ == '__main__':

    c = Collatz ()
    c.collatz (50)
