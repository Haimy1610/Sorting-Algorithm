# Implementation of Bubble sort Algorithm

num=[]
# Input list size
print("How many numbers in the list?")
n = input()
n = int(n)
num = list(range(n))

# Input elements
for k in range(n):
    print("Add number " + str(k + 1))
    num[k] = int(input())
    num.append(k)

print("Now the list you wanna sort is: ", end=" ")
for l in range(n):
    print(str(num[l]), end=" ")

def bubbleIncreasing(num):


    # Now implement Bubble sort
    # Traverse through all array elements
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            # Traverse the list from 0 to n-i-1. Swap if the element found
            # is greater than the next element
            if num[j] > num[j + 1]:
                num[j], num[j + 1] = num[j + 1], num[j]
                swapped = True

        # If no two elements were swapped by inner loop, then break
        # It helps stopping the algorithm if the list is already sorted
        if swapped == False:
            break

    print("Sorted array in creasing is: ", end=" ")
    for i in range(n):
        print("%d" % num[i], end=" ")

def bubbleDecreasing (num):

    # Now implement Bubble sort
    # Traverse through all array elements
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            # Traverse the list from 0 to n-i-1. Swap if the element found
            # is smaller than the next element
            if num[j] < num[j + 1]:
                num[j], num[j + 1] = num[j + 1], num[j]
                swapped = True

        # If no two elements were swapped by inner loop, then break
        # It helps stopping the algorithm if the list is already sorted
        if swapped == False:
            break

    print("Sorted array in decreasing is: ", end=" ")
    for i in range(n):
        print("%d" % num[i], end=" ")

m=0
m=int(m)
print(" ")
print("Do you wanna sort the list in increasing or decreasing order?")
print("Type 1 if increasing, type 0 if decreasing")
m=input()
while int(m)!=1 and int(m)!=0:
    print("Please type 1 or 0")
    m = input()
if int(m)==1:
    bubbleIncreasing(num)
if int(m)==0:
        bubbleDecreasing(num)
