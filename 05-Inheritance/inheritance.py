#!/usr/bin/env python

import inheritance

b = inheritance.Base()
d = inheritance.Derived()

inheritance.fb(b)
inheritance.fb(d)

# not possible, fd is only for Derived objects
# inheritance.fd(b)
inheritance.fd(d)

x = inheritance.factory()
inheritance.fb(x)

