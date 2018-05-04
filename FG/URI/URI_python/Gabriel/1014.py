#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Wed Apr 18 15:40:55 2018

Calculate a car's average consumption being provided the total distance 
traveled (in Km) and the spent fuel total (in liters).

@author: gabriel
"""

kms = input()
l = input()

consumption = kms/l

print ("%.3f km/l" % consumption)