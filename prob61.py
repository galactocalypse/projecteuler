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
start = time.time()
g3 = set([(x*(x+1)/2) for x in range(150) if x*(x+1)/2 >= 1000 and x*(x+1)/2 <= 9999])
g4 = set([(x*x) for x in range(150) if x*x >= 1000 and x*x <= 9999])
g5 = set([(x*(3*x - 1)/2) for x in range(150) if (x*(3*x - 1)/2) >= 1000 and (x*(3*x - 1)/2) <= 9999])
g6 = set([(x*(2*x - 1)) for x in range(150) if (x*(2*x - 1)) >= 1000 and (x*(2*x - 1)) <= 9999])
g7 = set([(x*(5*x - 3)/2) for x in range(150) if x*(5*x - 3)/2 >= 1000 and x*(5*x - 3)/2 <= 9999])
g8 = set([(x*(3*x-2)) for x in range(150) if x*(3*x-2) >= 1000 and x*(3*x-2) <= 9999])

arr = g3|g4|g5|g6|g7|g8
arr = sorted(arr)

ctr = 0
res = [set()]*726

for a in arr:
	m = (a%100)*100
	barr = [x for x in arr if x >= m and x < m+100 and x != a]
	for b in barr:
		m = (b%100)*100
		carr = [x for x in arr if x >= m and x < m+100 and x != a and x != b]
		for c in carr:
			m = (c%100)*100
			darr = [x for x in arr if x >= m and x < m+100 and x != a and x != b and x != c]
			for d in darr:
				m = (d%100)*100
				earr = [x for x in arr if x >= m and x < m+100 and x != a and x != b and x != c and x != d]
				for e in earr:
					m = (e%100)*100
					a2 = int(a/100)
					farr = [x for x in arr if x >= m and x < m+100 and x != a and x != b and x != c and x != d and x != e and x%100 == a2]
					for f in farr:
						res[ctr] = set([a, b, c, d, e, f])
						ctr = ctr + 1
print "Total: ", ctr	
end = time.time()
print end-start, "seconds to generate"
start = time.time()
found = False
for sol in res:
	if found:
		break
	arr = [x for x in sol if x in g3]
	for a in arr:
		if found:
			break
		brr = [x for x in sol if x in g4 and x != a]
		for b in brr:
			if found:
				break
			crr = [x for x in sol if x in g5 and x != a and x != b]
			for c in crr:
				if found:
					break
				drr = [x for x in sol if x in g6 and x != a and x != b and x != c]
				for d in drr:
					if found:
						break
					err = [x for x in sol if x in g7 and x != a and x != b and x != c and x != d]
					for e in err:
						frr = [x for x in sol if x in g8 and x != a and x != b and x != c and x != d and x != e]
						if frr:
							print sum([a, b, c, d, e, frr[0]])
							found = True
							break

end = time.time()
print end-start, "seconds to process"
