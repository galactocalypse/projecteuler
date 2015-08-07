# PE Prob 70
# Don't want to do it the Mathblog way since I don't have that insight yet.

from math import *

def getfactors(n):
	f = []
	if n%2 == 0:
		f.append(2)
	while n%2 == 0:
		n = n/2
	for i in range(3, int(sqrt(n)), 2):
		if n%i == 0:
			f.append(i)
		while n%i == 0:
			n = n/i
	if n > 1:
		f.append(n)
	return f

def tot(n):
	p = getfactors(n)
	t = 1
	d = 1
	for a in p:
		if n%a == 0:
			t = t*(a - 1)
			d = d*a
	return (t*n)/d

def getdlist(n):
	a = [0]*10
	if n == 0:
		a[0] = 1
	while n:
		a[int(n%10)] = a[int(n%10)] + 1
		n = n/10
	return a
	
def isperm(a, b):
	return getdlist(a) == getdlist(b)

def calc(n):
	ans = []
	for i in range(2, n+1):
		t = tot(i)
		if log(t, 10) == log(i, 10):
			if isperm(t, i):
				ans.append([n, t])
	return ans

print calc(1000000)
