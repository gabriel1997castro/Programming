#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 17 15:39:59 2018

In this problem, the task is to read a code of a product 1,
the number of units of product 1, the price for one unit of
 product 1, the code of a product 2, the number of units of
 product 2 and the price for one unit of product 2. After 
 this, calculate and show the amount to be paid.

@author: gabriel
"""
#input 1
total = 0

for x in range(0, 2):
    string = raw_input()
    l = string.split()
    code = int(l[0])
    units = int(l[1])
    price = float(l[2])
    total += units*price

print ("VALOR A PAGAR: R$ %.2f" % total)

