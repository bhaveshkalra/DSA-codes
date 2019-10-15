# Sublist Search (Search a linked list in another list)

Given two linked lists, the task is to check whether the first list is present in 2nd list or not.
## Examples:

### Input  : 
list1 =  10->20
         list2  = 5->10->20
### Output : 
LIST FOUND

### Input  : 
list1 =  1->2->3->4
         list2  = 1->2->1->2->3->4
### Output : 
LIST FOUND

### Input  : 
list1 =  1->2->3->4
         list2  = 1->2->2->1->2->3
### Output : 
LIST NOT FOUND

## Algorithm:
1- Take first node of second list.
2- Start matching the first list from this first node.
3- If whole lists match return true.
4- Else break and take first list to the first node again.
5- And take second list to its second node.
6- Repeat these steps until any of linked lists becomes empty.
7- If first list becomes empty then list found else not.

## Time Complexity : 
O(m*n) where m is the number of nodes in second list and n in first.

## Optimization :
Above code can be optimized by using extra space i.e. stores the list into two strings and apply KMP algorithm.
