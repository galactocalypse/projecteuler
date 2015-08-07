# PE Prob65
# Phew! Didn't expect this to take over an hour!

def gena(l):
	a = []
	a.append(2)
	for i in range(1, l+1, 3):
		a.append(1)
		a.append((int(i/3)+1)*2)
		a.append(1)
	return a

def calc(n, a):
	num = a[n-1]
	deno = 1

	for i in range(n-2, -1, -1):
		t = num
		num = num*a[i] + deno
		deno = t
	return [num, deno]

if __name__ == '__main__':
	n = int(raw_input())
	x = map(int, str(calc(n, gena(n))[0]))
	print "Sum: " + str(sum(x))

