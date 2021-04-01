# Implementation of Quick sort Algorithm

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


def partition(num, low, up):
    i = (low - 1)
    pivot = num[up]

    for j in range(low, up):

        if num[j] <= pivot:
            i = i + 1
            num[i], num[j] = num[j], num[i]

    num[i + 1], num[up] = num[up], num[i + 1]
    return (i + 1)


def quickSort(num, low, up):
    if low < up:
        pi = partition(num, low, up)

        quickSort(num, low, pi - 1)
        quickSort(num, pi + 1, up)

print("Now the list you wanna sort is: ", end=" ")
for l in range(n):
    print(str(num[l]), end=" ")

quickSort(num, 0, n-1)
print (" ")
print("Sorted array is:", end=" ")
for i in range(n):
    print("%d" % num[i], end=" ")