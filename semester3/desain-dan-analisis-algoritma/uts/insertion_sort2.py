def insertion_sort(arr):
    basic_operation_exec_count = 0

    # Traverse through all elements in the list
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        
        # Move elements of arr[0..i-1], that are greater than key, to one position ahead
        while j >= 0 and arr[j] > key:
            # Basic operation
            arr[j + 1] = arr[j]
            j -= 1
            basic_operation_exec_count += 1
            
        
        # Insert the key into its correct position
        arr[j + 1] = key # Also part of basic operation
    
    return arr, basic_operation_exec_count

print("START INSERTION SORT TEST\n")

arr = [4]
sorted_arr, exec_count = insertion_sort(arr)
print("Sorted array:", sorted_arr)
print("Basic operation execution count:", exec_count, "\n")

arr = [4, 3]
sorted_arr, exec_count = insertion_sort(arr)
print("Sorted array:", sorted_arr)
print("Basic operation execution count:", exec_count, "\n")

arr = [4, 3, 2]
sorted_arr, exec_count = insertion_sort(arr)
print("Sorted array:", sorted_arr)
print("Basic operation execution count:", exec_count, "\n")

arr = [4, 3, 2, 1]
sorted_arr, exec_count = insertion_sort(arr)
print("Sorted array:", sorted_arr)
print("Basic operation execution count:", exec_count, "\n")

print("END INSERTION SORT TEST\n")