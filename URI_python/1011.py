#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 17 16:35:05 2018

Make a program that calculates and shows the volume of a sphere
 being provided the value of its radius (R) . The formula to calculate
 the volume is: (4/3) * pi * R3. Consider (assign) for pi the value 3.14159.

Tip: Use (4/3.0) or (4.0/3) in your formula, because some languages (including C++)
 assume that the division's result between two integers is another integer. :)

@author: gabriel
"""
r = 0.0
pi = 3.14159

r = input()
volume = (4/3.0)*pi*r**3

print ("VOLUME = %.3f" % volume)