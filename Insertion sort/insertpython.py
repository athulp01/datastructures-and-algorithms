import random


def createArray(size):
    array = [random.randint(1, 100) for x in range(1, size)]
    return array


def insertionSort(arr, size):
    for x in range(1, size):
        key = x
        temp=arr[key]
        for y in range(x, 0, -1):
            if key is not 0 and temp < arr[y - 1]:
                arr[key] = arr[y - 1]
                key = y - 1
            else:
                break
        arr[key]=temp


#size = input("Input the size of the array ")
array = createArray(int(50000))
insertionSort(array, len(array))
print("sort complete")
