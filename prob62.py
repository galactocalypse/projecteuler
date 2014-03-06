# ProjectEuler Problem 62: CubicPermtations
# Whoa! This took far less time than I had expected.

from time import *
from math import *

def getdigitcounts(n):
	count = [0]*10
	while n:
		count[n%10] += 1
		n /= 10
	return count

def checkrange(digs, perms):
	a = int(pow(10**(digs-1), 0.33))
	b = int(pow(10**digs-1, 0.33))
	d = [0]*(b - a + 1)
	ind = 0
	found = 0
	for i in range(a, b+1):
		d[i-a] = getdigitcounts(i**3)
	for i in d:
		if d.count(i) == perms:
			found = 1
			break
		else:
			ind += 1
	if found:
		return (a+ind)**3
	else:
		return -1

if __name__ == '__main__':
	print checkrange(12, 5)
