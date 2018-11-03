def factors(n):
    """Calculate all the factors of n."""
    for i in xrange(2,n / 2):
       if n % i == 0:
           return [i] + factors(n / i)
    return [n]
 
def main(argv):
    n = int(argv[1])
    print "factors of", n, "are", factors(n)
 
if __name__ == "__main__":
    import sys
    main(sys.argv)
