#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 19 13:51:11 2018

Read an integer value corresponding to a person's age (in days) and
 print it in years, months and days, followed by its respective message
 “ano(s)”, “mes(es)”, “dia(s)”.

Note: only to facilitate the calculation, consider the whole year with 
365 days and 30 days every month. In the cases of test there will never
 a situation that allows 12 months and some days, like 360, 363 or 364.
 This is just an exercise for the purpose of testing simple mathematical
 reasoning.
 
@author: gabriel
"""

total = input()

remainder = total % 365
years = (total - remainder) / 365

total = remainder
remainder = total % 30
months = (total - remainder) / 30

total = remainder
days = remainder

print ("%d ano(s)" % years)
print ("%d mes(es)" % months)
print ("%d dia(s)" % days)