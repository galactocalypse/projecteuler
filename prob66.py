# PE Prob 66
#	This problem has been a mental block for quite a few weeks now. I'll try integrating a solution from the previous problems.
#	Reference: http://www.math.uchicago.edu/~may/VIGRE/VIGRE2008/REUPapers/Yang.pdf
#	So after finally getting the correct answer for the sample input, I realize we need longer numbers. :/
#	I so need to work on that language with dynamic datatype sizes!
#	I have only one thing to say. Fuck yeah!

from math import *
a = []
def getPeriod(n):
	global a
	a = []
	m = []
	d = []
	m.append(0)
	d.append(1)
	a.append(int(sqrt(n)))
	p = 5000
	for i in range(1, 2*p+3):
		m.append(d[i-1]*a[i-1] - m[i-1])
		d.append(int((n - m[i]*m[i])/d[i-1]))
		a.append(int((a[0]+m[i])/d[i]))
		#print m[i], d[i], a[i]
		if a[i] == 2*a[0] and p == 5000:
			p = i
	if p == 5000:
		return -1
	return p

xmax = -1
dd = 0
for d in range(2, 1001):
	if d == int(sqrt(d))**2:
		continue
	l = getPeriod(d)
	p = []
	q = []
	p.append(a[0])
	p.append(a[1]*p[0] + 1)
	q.append(1)
	q.append(a[1]*q[0])
	for j in range(2, 2*l+1):
		p.append(a[j]*p[j-1] + p[j-2])
		q.append(a[j]*q[j-1] + q[j-2])
	if l%2 == 0:
		x = p[l-1]
	else:
		x = p[2*l-1]
	if xmax < x:
		dd = d
		xmax = x

print "D with largest minimal X:", dd

