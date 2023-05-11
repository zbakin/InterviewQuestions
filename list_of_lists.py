# Write a function which is passed an integer, n, and returns a list of n lists such that:
# f(0) returns []
# f(1) returns [[1]]
# f(2) returns [[1], [1,2]]
# f(3) returns [[1], [1,2], [1,2,3]]

def f(n):
    """
    Returns a list of n lists, where the ith list contains the numbers from 1 to i inclusive.
    """
    result = []
    for i in range(1, n+1):
        result.append(list(range(1, i+1)))
    return result


print(f(10))