#!/usr/bin/env python

from overload import Example

e = Example()

e.doit(); print (e)
print (e.doit(2))
e.doit("Hallo"); print (e)

print ("------")

print (e.makeIt("xxx"), e)
print (e.makeIt("abc", 2), e)
print (e.makeIt("xyz", 3, "abc"), e)

