import random


def bubble_sort(arr):
    n = len(arr)
    basic_operation_exec_count = 0

    # Traverse through all elements in the list
    for i in range(n):
        # Last i elements are already in place, so we can ignore them
        for j in range(0, n - i - 1):
            # Swap if the element found is greater than the next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j] # Basic operation
                basic_operation_exec_count += 1

    return arr, basic_operation_exec_count

print("START BUBBLE SORT TEST\n")

arr = [4]
sorted_arr_1, exec_count_1 = bubble_sort(arr)
print("Sorted array:", sorted_arr_1)
print("Basic operation execution count:", exec_count_1, "\n")

# Array berisi 10 integer random dari 1-1000
arr = [4, 3]
sorted_arr_2, exec_count_2 = bubble_sort(arr)
print("Sorted array:", sorted_arr_2)
print("Basic operation execution count:", exec_count_2, "\n")

# Array berisi 10 integer random dari 1-1000
arr = [4, 3, 2]
sorted_arr_3, exec_count_3 = bubble_sort(arr)
print("Sorted array:", sorted_arr_3)
print("Basic operation execution count:", exec_count_3, "\n")

# Array berisi 10 integer random dari 1-1000
arr = [4, 3, 2, 1]
sorted_arr_4, exec_count_4 = bubble_sort(arr)
print("Sorted array:", sorted_arr_4)
print("Basic operation execution count:", exec_count_4, "\n")

print("END BUBBLE SORT TEST\n")