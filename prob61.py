# Sample space: 10^6 -> 299
# List comprehensions make this too easy. This is the first time I'm feeling the much-hyped power of Python.
# Eligible pairs: 726
# Okay, not all that straightforward either.
# List comprehensions <3
# Output:
# 	Total:  726
# 	2.65023303032 seconds to generate
# 	28684
# 	0.000972032546997 seconds to process
# Now, might want to tidy up this code.

import time

g = [set()]*6
arr = set()
ctr = 0
res = [set()]*726
ans = 0
found = False

def initialize():
	global g, arr
	g[0] = set([(x*(x+1)/2) for x in range(150) if x*(x+1)/2 >= 1000 and x*(x+1)/2 <= 9999])
	g[1] = set([(x*x) for x in range(150) if x*x >= 1000 and x*x <= 9999])
	g[2] = set([(x*(3*x - 1)/2) for x in range(150) if (x*(3*x - 1)/2) >= 1000 and (x*(3*x - 1)/2) <= 9999])
	g[3] = set([(x*(2*x - 1)) for x in range(150) if (x*(2*x - 1)) >= 1000 and (x*(2*x - 1)) <= 9999])
	g[4] = set([(x*(5*x - 3)/2) for x in range(150) if x*(5*x - 3)/2 >= 1000 and x*(5*x - 3)/2 <= 9999])
	g[5] = set([(x*(3*x-2)) for x in range(150) if x*(3*x-2) >= 1000 and x*(3*x-2) <= 9999])
	arr = g[0] | g[1] | g[2] | g[3] | g[4] | g[5]
	arr = sorted(arr)

def process(a, s, arr):
	global ctr
	m = (a%100)*100
	s = s+[a]
	if len(s) < 6:
		if len(s) < 5:
			barr = [x for x in arr if x >= m and x < m+100 and x not in s]
		else:
			barr = [x for x in arr if x >= m and x < m+100 and x not in s and x%100 == int(s[0]/100)]
	else:
		res[ctr] = set(s)
		ctr = ctr + 1
		return
	for b in barr:
		process(b, s, arr)

def generate():
	global arr
	for a in arr:
		process(a, [], arr)


def compute(s, sol, i):
	global ans, g, found
	if found:
		return
	if i < 6:
		ar = [x for x in sol if x in g[i] and x not in s]
		for a in ar:
			s = s + [a]
			compute(s, sol, i+1)
	else:
		ans = sum(s)
		found = True

def check():
	global res
	for sol in res:
		compute([], sol, 0)


if __name__ == '__main__':
	start = time.time()
	initialize()
	end = time.time()
	print "Init in", end - start, "s"
	start = time.time()
	generate()
	end = time.time()
	print "Gen in", end - start, "s"
	start = time.time()
	check()
	end = time.time()
	print "Computed in ", end - start, "s"
	print ans
