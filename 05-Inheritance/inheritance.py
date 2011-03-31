#!/usr/bin/env python

import inheritance

b = inheritance.Base()
d = inheritance.Derived()

inheritance.fb(b)
inheritance.fb(d)

# inheritance.fd(b)
inheritance.fd(d)

x = inheritance.factory()
inheritance.fb(x)
