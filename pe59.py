# ProjectEuler: 59 - XOR Encryption
# I really should have used some other language for this
# No! Correct answer at the first go!
import collections
f = open("cipher1.txt", "r")
s = f.read().split(",")
# 1. make separate lists
# 2. find maxchar of each list
# 3. find keychar by maxchar^space
# 4. decrypt

def get_max(s):
	return int(collections.Counter(s).most_common(1)[0][0])
def get_chars_mod(s, off, m):
	res = []
	for i in range(off, len(s), m):
		res.insert(-1, s[i])
	return res
def process(s, off, m):
	a = get_chars_mod(s, off, m)
	c = int(get_max(a))^32
	for i in range(len(a)):
		a[i] = int(a[i])^c
	return a
a = process(s, 0, 3)
b = process(s, 1, 3)
c = process(s, 2, 3)
x = sum(a) + sum(b) + sum(c)
print x
