# Write a function which is passed an integer, n, and returns a list of n lists such that:
# f(0) returns []
# f(1) returns [[1]]
# f(2) returns [[1], [1,2]]
# f(3) returns [[1], [1,2], [1,2,3]]

def f(n):
    final_list = []
    curr_list = []
    for i in range(1, n+1):
        curr_list.append(i) # created a sublist
        final_list.append(curr_list[:]) # appends sublist
    return final_list
