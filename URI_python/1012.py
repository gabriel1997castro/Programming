#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 17 16:44:29 2018

Make a program that reads three floating point values: A, B and C. Then, calculate and show:
a) the area of the rectangled triangle that has base A and height C.
b) the area of the radius's circle C. (pi = 3.14159) 
c) the area of the trapezium which has A and B by base, and C by height.
d) the area of ​​the square that has side B.
e) the area of the rectangle that has sides A and B.

@author: gabriel
"""

def areaTri(A, C):
    area = (A*C)/2
    return area

def areaCir(C):
    pi = 3.14159
    area = pi * C**2
    return area

def areaTra(A,B,C):
    if A > B:
        maior = A
        menor = B
    else:
        maior = B
        menor = A
    area = areaTri((maior - menor), C) + ((menor)*C)
    return area

def areaSqu(B):
    area = B**2
    return area

def areaRet(A, B):
    area = A * B
    return area
    
def main():
    inputStr = raw_input()
    x = inputStr.split()
    A = float(x[0])
    B = float(x[1])
    C = float(x[2])
    print ("TRIANGULO: %.3f" % areaTri(A,C))
    print ("CIRCULO: %.3f" % areaCir(C))
    print ("TRAPEZIO: %.3f" % areaTra(A, B, C))
    print ("QUADRADO: %.3f" % areaSqu(B))
    print ("RETANGULO: %.3f" % areaRet(A, B))
    
main()