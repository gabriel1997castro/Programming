#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 19 13:38:09 2018
Read an integer value, which is the duration in seconds of a certain 
event in a factory, and inform it expressed in hours:minutes:seconds.
@author: gabriel
"""


total = input()

remainder = total % 3600
hours = (total - remainder) / 3600

total = remainder
remainder = total % 60
minutes = (total - remainder) / 60

seconds = remainder

print("%d:%d:%d" % (hours, minutes, remainder))