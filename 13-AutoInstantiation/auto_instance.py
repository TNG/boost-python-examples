#!/usr/bin/env python

from myextension import Base

class PythonDerivedOne(Base):
    def __init__(self):
        Base.__init__(self, "PythonDerivedOne")

class PythonDerivedTwo(Base):
    def __init__(self):
        Base.__init__(self, "PythonDerivedTwo")


