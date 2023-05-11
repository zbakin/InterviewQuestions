# Define a generator which generates the positive integers up to and including a supplied value
# which are divisible by another supplied positive integer and use it to calculate the sum of all
# positive integers less than 102030 which are divisible by 3
def generator(num, divisor):
    mylist = []
    it = divisor
    while it < num:
        mylist.append(it)
        # all the numbers that are divisible by divisor can be found just by summing them up
        it += divisor
    return mylist


values = generator(102030, 3)
sum = 0
for n in values:
    sum += n

print(sum)