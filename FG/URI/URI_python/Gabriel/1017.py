#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Wed Apr 18 17:01:17 2018

Little John wants to calculate and show the amount of spent 
fuel liters on a trip, using a car that does 12 Km/L. For this,
 he would like you to help him through a simple program. To
 perform the calculation, you have to read spent time (in hours)
 and the same average speed (km/h). In this way, you can get distance
 and then, calculate how many liters would be needed. Show the value
 with three decimal places after the point.

@author: gabriel
"""

hours = input()
velocity = float(input())
distance = hours * velocity
spent = distance / 12

print("%.3f"% spent)