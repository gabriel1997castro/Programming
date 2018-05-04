#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Wed Apr 18 15:47:11 2018

@author: gabriel
"""
import math

A = [0.0, 0.0]
B = [0.0, 0.0]
inpStr = raw_input().split()
A[0] = float(inpStr[0])
A[1] = float(inpStr[1])
inpStr = raw_input().split()
B[0] = float(inpStr[0])
B[1] = float(inpStr[1])

distance = math.sqrt(((A[0] - B[0])**2) + ((A[1] - B[1])**2))

print("%.4f" % distance)