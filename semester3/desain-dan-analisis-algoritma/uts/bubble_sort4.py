import matplotlib.pyplot as plt

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

# Sizes of the reversed arrays
array_sizes = [10, 50, 100, 200, 500]
basic_operation_count_list = []

# Run Bubble Sort on reversed arrays and track operations
for size in array_sizes:
    # Create an array of 'size' elements in reversed order
    arr = list(range(size, 0, -1))  # reverse array: [size, size-1, ..., 1]
    
    sorted_arr, exec_count = bubble_sort(arr)
    
    basic_operation_count_list.append(exec_count)

# Membuat grafik
plt.figure(figsize=(10, 6))
plt.plot(array_sizes, basic_operation_count_list, label='Basic Operations', marker='o', linestyle='-', color='r')

# Labels and title
plt.xlabel('Array Size')
plt.ylabel('Number of Operations')
plt.title('Bubble Sort Basic Operations')
plt.legend()
plt.grid(True)

plt.show()
