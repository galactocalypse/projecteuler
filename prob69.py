# PE Prob 69
# n is definitely even
# I need to learn how to spot the right formulae(formulas?)!

from math import sqrt
def isp(n):
	if n == 2:
		return True
	if n % 2 == 0:
		return False
	for i in range(3, int(sqrt(n)), 5):
		if n % i == 0:
			return False
	return True

def getprimes(n):
	p = [2,3,5,7]
	prod = 2*3*5*7
	i = 11
	while prod < n:
		while(not isp(i)):
			i = i+2
		prod = prod*i
		p.append(i)
		i += 2
	return p
	
def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a%b)

p = getprimes(1000000)
print p
cm = 0.0
ci = 0
for i in range(2, 1000001, 2):
	tot = 1.0
	for pp in p:
		if i % pp == 0:
			tot /= (1.0-1.0/pp)
	if tot > cm:
		cm = tot
		ci = i
print ci
