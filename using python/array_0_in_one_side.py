# -*- coding: utf-8 -*-
"""
Created on Mon Aug 15 00:50:14 2022

@author: Padmanav
"""
def charge(arr,n):
    count = 0
    for i in range(0,n):
        if arr[i] != 0:
            arr[count] = arr[i]
            count += 1
    while count < n:
        arr[count] = 0
        count +=1
    
arr = []
arr = [2,0,5,0,0,8,0,10]
n = len(arr)
charge(arr,n)
for i in arr:
    print(i)