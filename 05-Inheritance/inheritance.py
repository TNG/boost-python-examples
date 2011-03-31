#!/usr/bin/env python

import inheritance

b = inheritance.Base()
d = inheritance.Derived()

class PythonDerived(inheritance.Base):
	def name(self):
		return "PythonDerived"

inheritance.fb(b)
inheritance.fb(d)

# not possible, fd is only for Derived objects
# inheritance.fd(b)
inheritance.fd(d)

x = inheritance.factory()
inheritance.fb(x)

p = PythonDerived()
inheritance.fb(p)

