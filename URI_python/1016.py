#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Wed Apr 18 16:51:47 2018

Two cars (X and Y) leave in the same direction. The car X leaves
 with a constant speed of 60 km/h and the car Y leaves with a constant
 speed of 90 km / h.

In one hour (60 minutes) the car Y can get a distance of 30 kilometers
 from the X car, in other words, it can get away one kilometer for each
 2 minutes.

Read the distance (in km) and calculate how long it takes (in minutes)
 for the car Y to take this distance in relation to the other car.


@author: gabriel
"""

distance = input()

howlong = 2 * distance

print ("%d minutos" % howlong)