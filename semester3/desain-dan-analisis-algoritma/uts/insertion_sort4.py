import matplotlib.pyplot as plt

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

# Sizes of the reversed arrays
array_sizes = [10, 50, 100, 200, 500]
basic_operation_count_list = []

# Run Insertion Sort on reversed arrays and track operations
for size in array_sizes:
    # Create an array of 'size' elements in reversed order
    arr = list(range(size, 0, -1))  # reverse array: [size, size-1, ..., 1]
    
    sorted_arr, exec_count = insertion_sort(arr)
    
    basic_operation_count_list.append(exec_count)

# Membuat grafik
plt.figure(figsize=(10, 6))
plt.plot(array_sizes, basic_operation_count_list, label='Shifts', marker='o', linestyle='-', color='r')

# Labels and title
plt.xlabel('Array Size')
plt.ylabel('Number of Operations')
plt.title('Insertion Sort Basic Operations')
plt.legend()
plt.grid(True)

plt.show()
