#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 17 10:37:36 2018

@author: gabriel
"""
# Program: Lê nome, salário fixo e imprime o salário
# salário = 15% das vendas mais salário fixo
nome = raw_input()
salFixo = input()
vendas = input()
sal = vendas * 0.15 + salFixo
print ("TOTAL = R$ %.2f" % (sal))