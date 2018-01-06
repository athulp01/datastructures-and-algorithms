import random


def mergeSort(x):
    if len(x) == 0 or len(x) == 1:
        return x
    else:
        middle = int(len(x) / 2)
        a = mergeSort(x[:middle])
        b = mergeSort(x[middle:])
        return merge(a, b)



def merge(arr1, arr2):
    resultarr = []
    while len(arr1) != 0 and len(arr2) != 0:
        if arr1[0] < arr2[0]:
            resultarr.append(arr1[0])
            del arr1[0]
        else:
            resultarr.append(arr2[0])
            del arr2[0]
    if(len(arr1) == 0):
        resultarr+=(arr2)
    if(len(arr2) == 0):
        resultarr+=(arr1)
    return resultarr


array = [random.randint(1, 100) for x in range(1, 50000)]
#print(array)
array = mergeSort(array)
#print(array)
