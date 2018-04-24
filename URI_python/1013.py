#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 17 17:25:20 2018

Make a program that reads 3 integer values and present the greatest one followed
 by the message "eh o maior"

@author: gabriel
"""

def greatestAB(A, B):
    greatest = (A + B + abs(A - B)) / 2
    return greatest
    
def main():
    inpStr = raw_input()
    l = inpStr.split()
    A = int(l[0])
    B = int(l[1])
    C = int(l[2])
    D = greatestAB(A, B)
    maior = greatestAB(C, D)
    print ("%i eh o maior" % maior)

main()