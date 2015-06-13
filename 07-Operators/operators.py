#!/usr/bin/env python

from operators import NumberLike

n = NumberLike(7)
m = n + 2
print (m)

n0 = NumberLike()
m0 = n0 + 1
print (m0)

print (repr(m0))