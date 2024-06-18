# Week 4 (class):

## Searching Sorting 1:

**Binary Search [LeetCode 704](https://leetcode.com/problems/binary-search/) :**

1. We will be given a sorted array and a target, we need to find the target from the array.
2. We can find the mid of sorted array and decide if the target is on the left or right easily. This is called the binary search.
3. Like two pointer approach, we will put a start index in index 0 and end index in n-1.
4. average of those is the mid of index.
   1. Direct average can cause error if one of the start or end in INT_MAX.
   2. So we will do this : s + (e-s)/2
   3. Eq : s + e/2 - s/2 = s/2 + e/2 = (s+e)/2 [same as the prev method]
5. Now we check if the target in the mid element than return the mid index.
6. If target is less than mid element than it must be in left as it is in increasing order. So we put the end index before mid to cut the right.
7. If target is greater than mid element than it must be in right as it is in increasing order. So we put the start index after mid to cut the left.
8. After every cutting part, we calculate the new mid.
   <br/>
   _TC :_ O(logn)
9. There is a STL algorithm call binary_search(startPos, endPos, target) to do the binary search operation without writing code from scratch.

**First Occurrence:**

<i>Question :</i>

We need to give the first index of a repetitive element in an sorted array using binary search.

<i>Intuition :</i>

1. we can find the element using binary search.
   2.Instead of returning the index, we will store the index in a by reference Integer variable.
2. But it may not be the first occurrence, so we will search in the left.
3. Rest will be same process until start is greater than end.
4. After all of that, the first occurrence will be stored inside the by reference variable.

<i>Approach: (store and compute) </i>

1. Store the mid in the by reference variable and make the end before mid after finding the target.
2. On target >/< arr[mid] do the binary search approach.
3. Do not forget to upgrade the mid.

<i>TC and SC</i>

1. Linear Loop so TC : O(n)
2. Only one variable created so SC : O(1)

**Last Occurrence:**

Same as First, just search in the right or make the start after mid.

**LeetCode 34. Find First and Last Position of Element in Sorted Array. [problem]:(https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)**

Just like previous both, call two function and get the first and last position. Then push them in a vector and return them.

## Mega Array:

**unordered_map :**
Just watch the code for basic syntax

**2's Compliment :**

<i>Question :</i>

We will be given an array of 0 & 1 which represents a binary number and need to find out the 2's compliment of that binary number.

<i>Intuition :</i>

1. First flip the bit in array. (1's compliment)
2. Add one in the last index and adjust the other element with carry.
   (2's compliment)

<i>Approach: (store and compute) </i>

1. We will take an array with extra space to show the twos complement. One extra space to show the carry at top if we left one. Also gonna traverse both input and output array from the last index to get proper mapping.
2. First we will traverse a loop in both input and output array(twos complement) and store the flip bit in output array. We will use ternary operator to check the bit and store flip bit.
3. We will take a carry initially 1 then traverse the output array again. But this time :
   1. we get the sum of carry and last index element.
   2. %2 will be the bit to store.
   3. /2 will be the new carry.
4. If carry left than we will store it in the first index. (the reason to make the output array InputSize+1)

<i>TC and SC</i>

1. Linear Loop so TC : O(n)
2. Output array created so SC : O(n+1)

**LeetCode 48. Rotate Image. [problem]:(https://leetcode.com/problems/rotate-image/)**

<i>Question :</i>

Given 2D array should be rotate clockwise.

<i>Intuition :</i>

1. Transpose the matrix first.
2. Reverse the matrix row-wise.

<i>Approach:</i>

1. See the transpose code on note.
2. Reverse with .reverse method.

<i>TC and SC</i>

1. row and col traversal so TC : O(n\*m)
2. SC : O(1)
