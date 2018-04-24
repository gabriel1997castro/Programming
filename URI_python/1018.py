#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Wed Apr 18 17:10:48 2018

In this problem you have to read an integer value and calculate the
 smallest possible number of banknotes in which the value may be decomposed.
 The possible banknotes are 100, 50, 20, 10, 5, 2 e 1. Print the read value
 and the list of banknotes.
 
@author: gabriel
"""

value = input()
print value
resto = value % 100
bn100 = (value - resto) / 100

value = resto
resto = value % 50
bn50 = (value - resto) / 50

value = resto
resto = value % 20
bn20 = (value - resto) / 20

value = resto
resto = value % 10
bn10 = (value - resto) / 10

value = resto
resto = value % 5
bn5 = (value - resto) / 5

value = resto
resto = value % 2
bn2 = (value - resto) / 2

bn1 = resto

print ("%d nota(s) de R$ 100,00" % bn100)
print ("%d nota(s) de R$ 50,00" % bn50)
print ("%d nota(s) de R$ 20,00" % bn20)
print ("%d nota(s) de R$ 10,00" % bn10)
print ("%d nota(s) de R$ 5,00" % bn5)
print ("%d nota(s) de R$ 2,00" % bn2)
print ("%d nota(s) de R$ 1,00" % bn1)
