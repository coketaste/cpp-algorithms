# Binary Search

## Introduction
Binary search is a widely used algorithm for finding a specific target value within a sorted sequence or array. It operates by repeatedly dividing the search range in half and comparing the target value with the middle element of the current range. Based on the comparison, it eliminates half of the search space with each iteration until the target value is found or it's determined that the target value is not present in the sequence.

Here's a step-by-step description of the binary search algorithm:

1. Start with the entire sorted sequence or array.

2. Calculate the middle index (or element) of the current search range.

3. Compare the middle element with the target value:
   - If they are equal, the search is successful, and the index (or element) is returned.
   - If the middle element is greater than the target value, narrow the search to the lower half of the current range and repeat the process on that lower half.
   - If the middle element is less than the target value, narrow the search to the upper half of the current range and repeat the process on that upper half.

4. Repeat steps 2 and 3 until the target value is found, or the search range becomes empty (indicating that the target value is not in the sequence).

## Complexity
Binary search is an efficient algorithm with a time complexity of O(log n), where n is the number of elements in the sorted sequence. This is in contrast to linear search, which has a time complexity of O(n) and involves checking each element one by one. Binary search is most effective when working with large datasets, as it dramatically reduces the number of comparisons needed to find the target value.