# Prob 63
# Python is lovely.

def checkdigit(d):
	lima = 10**(d-1)
	limb = 10**d - 1
	count = 0
	a = int(pow(lima, 1.0/d))
	b = int(pow(limb, 1.0/d))
	for i in range(a, b+1):
		if i**d <= limb and i**d >= lima:
			count += 1
	return count

def check(lim):
	count = 0
	for i in range(1, lim+1):
		c = checkdigit(i)
		print i, ":", c
		count += c
	return count

if __name__ == '__main__':
	print check(int(raw_input()))
	# 100 works
