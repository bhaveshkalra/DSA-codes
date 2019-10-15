
# Linear Search

## Problem: 
Given an array arr[] of n elements, write a function to search a given element x in arr[].

## Examples :

## Input : 
arr[] = {10, 20, 80, 30, 60, 50, 
                     110, 100, 130, 170}
          x = 110;
## Output : 
6
Element x is present at index 6

## Input : 
arr[] = {10, 20, 80, 30, 60, 50, 
                     110, 100, 130, 170}
           x = 175;
## Output : 
-1
Element x is not present in arr[].

A simple approach is to do linear search, i.e 

    Start from the leftmost element of arr[] and one by one compare x with each element of arr[]
    If x matches with an element, return the index.
    If x doesn’t match with any of elements, return -1.



The time complexity of above algorithm is O(n).

Linear search is rarely used practically because other search algorithms such as the binary search algorithm and hash tables allow significantly faster searching comparison to Linear search.
