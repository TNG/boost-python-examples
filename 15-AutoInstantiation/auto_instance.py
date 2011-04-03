#!/usr/bin/env python

from mymodule import Base

class PythonDerivedOne(Base):
	def __init__(self):
		Base.__init__(self, "PythonDerivedOne")

class PythonDerivedTwo(Base):
	def __init__(self):
		Base.__init__(self, "PythonDerivedTwo")

# will be redone in C++
p1 = PythonDerivedOne()
p2 = PythonDerivedTwo()
print p1, p2

