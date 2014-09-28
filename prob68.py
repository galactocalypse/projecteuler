# PE Prob68
# Without doubt the worst way of solving this problem.

from itertools import permutations
a = []
for i in range(1, 11):
	a.append(i)
c = 0
g = []
r = []

for p in permutations(a):
	s = [[p[0], p[1], p[2]],
		[p[3], p[2], p[4]],
		[p[5], p[4], p[6]],
		[p[7], p[6], p[8]],
		[p[9], p[8], p[1]]]
	if sum(s[0]) == sum(s[1]) == sum(s[2]) == sum(s[3]) == sum(s[4]):
		m = min([s[x][0] for x in range(len(s))])
		i = [x for x in range(len(s)) if s[x][0] == m][0]
		s = s[i:] + s[:i]
		x = s[0] + s[1] + s[2] + s[3] + s[4]
		g.append(x)
	c = c + 1

for x in g:
	if x.count(10) == 1:
		r.append(x)
	g = [m for m in g if m != x]
ss = []
for rr in r:
	ss.append(''.join(str(x) for x in rr))
ss.sort()
print ss[-1]
