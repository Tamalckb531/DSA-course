# Week 3 :

## Space and Time complexity :

_Complexity Rank_

LOW ::: O(1) -> O(logn) -> O(root(n)) -> O(n) -> O(n) -> O(nlogn) -> O(n^2) -> O(n^3) -> O(2^n) -> O(n!) -> O(n^n) ::: HIGH

## Array 1

**IMP notes :**

1. Array always need continuos memory
2. Empty space of an array initialize with 0. { let an array has 5 space and two number allocated. So the rest 3 numbers will be 0 allocated by default.}
3. fill use to fill an entire array with a single value. fill(startIndex, endIndex, value).
4. arr[i] ---(in machine)--> \*(arr + i) where i is depending on the data_type size
5. Passing array inside a function is basically pass by reference, manipulating it manipulate the original

**Linear Search :**

1. Make a loop for traversing the index of array
2. Make a conditional to match each element of array with target
3. if target found than return the index.
4. if target not found than return -1.

**Find Max number :**

1. Make a variable max with INT_MIN.
2. Traverse and check each value of array and see it's greater than max or not
3. If greater than set it the max.
4. Return the max after the loop

**Total number or Zero and One :**

1. Make two variable name zero and one .
2. Traverse and check each value of array and see it's zero or one
3. Encountering zero or one, make the co-responding variable ++ .
4. Print the total zero and one individually

<h4>Two pointers technique :</h4>
A special technique to solve problems. Here we take two variable and point one on the left most index and other on the right most index. Then heads them towards center. By this we can traverse an array from both direction and solve many important issue.

**ExtremePrint :**

1. Make two pointers left and right and allocate them both left and right most index of the array .
2. Make a while loop with condition left <= right (= for the odd case)
3. Print left elem and increase the left, print right elem and decrease the right.
4. Make a special case to handle left == right and print only one time.

<hr/>
