import sys

def collatz(n):
	while n > 1:
		if n % 2 == 0:
			n /= 2
			print("/", end='')
		else:
			n *= 3
			n += 1
			print("*", end='')
		print(n)

if __name__ == "__main__":
	collatz(int(sys.argv[1]))
