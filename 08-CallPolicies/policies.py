#!/usr/bin/env python

from policies import Example

f = Example.factory()
s = Example.singleton()

print "f =",f
print "s =",s

