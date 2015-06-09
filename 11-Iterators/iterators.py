#!/usr/bin/env python

from sys import stdout
from iterators import Example

e = Example()

e.add("a")
e.add("b")
e.add("c")

print ([ s for s in e.strings() ])

