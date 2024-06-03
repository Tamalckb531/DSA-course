# Week 3 (class) :

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

## Array 2

**LeetCode 136 - singleNumber :**

<i>Intuition :</i>

we need to cancel out those numbers which comes more than one time. Doing XOR with same elements give 0. So, XOR can solve the issue.

<i>Approach: </i>

1. Traverse the array with a for loop.
2. Take a variable with init value 0
3. Do XOR each element of the array with the ans .
4. At the end it will cover only one times element.

<i>TC and SC</i>

1. Linear Loop so TC : O(n)
2. Only one variable created so SC : O(1)

**sort0and1 :**

<i>Intuition :</i>

We just need to count all the occurrence of 0 and 1 and then re-insert the two values in array according to their occurrence.

<i>Approach: </i>

1. Traverse the array with a for loop and count the zero and one.
2. 0-zeroCount insert 0
3. zeroCount-size insert 1

<i>TC and SC</i>

1. 3 Linear Loop so TC : O(n)+ O(n)+ O(n) = O(n)
2. Only two variable created so SC : O(1)

**pairPrint :**

Here we learn about the nested loop pattern and how they behave. Look at the notebook for more details

**TwoSum :**

<i>Question :</i>

We need to find the pair of numbers in an array whose sum is equal to the target given

<i>Approach :</i>

Just like the pairPrint, we create two nested loop and on the inner loop we check the condition, arr[i] + arr[j] == target. We print the matched number.

**Print All Triplets :**

<i>Question :</i>

We need to print all combination of any three element in one array

<i>Approach :</i>

Create three nested loop and print for each index in inner most loop.
We can also track how many combination printed by using a count variable and increasing it on the each inner most loop iteration. The time complexity will be O(n^3) and space complexity will be O(1).

**LeetCode 1 - twoSum :**

Same as the twoSum problem but we aren't using the inner loop from 0 rather than using from outer loop index+1. It will only work with the upper left triangle so no redundant value there.

**LeetCode 15 - ThreeSum :**

Just creating three nested loop for upper left triangle (starting inner index from outer index+1), then checking three value matching the target or not. If matched then printing it.

**shiftArray :**

<i>Intuition :</i>

We need cut the last elements according to the place mentioned and save it on something else. Then shift the other elements and than we need to place the cut element on the top indexes.

<i>Approach: </i>

1. Copy the shifted element in a temp array
   1. If shift == arraySize than it will be same as previous after that it will start from 1. So shift % size is the finalShift. Ex: size = 6, shift = 7, 6 of the shift will make the same array so 7%6=1 is the finalShift.
   2. Create a temp array and store shifted element there. temp index range : 0-finalShift, main array iteration : size - finalShift to size. As we need to move the shifted element.
2. Shift array elements by finalShift places
   1. Iterate array backward, from size-1.
   2. Place finalShift's index before element in each index(i = i-finalShift) until in i-finalShift>=0
3. Copy the elements into original array (arr = temp)

<i>TC and SC</i>

1. 3 Linear Loop so TC : O(size)+ O(size)+ O(finalShift) = O(size) -> size > finalShift
2. Fixed array created so SC : O(1)
<hr/>

## Array 3

**Basic :**

1. 2D array formula : NumOfCol\*rowIndex + colIndex
2. Row Wise Traversal : upper loop will be for row.
3. Column Wise Traversal : upper loop will be for column.
4. Diagonal Traversal : Print whenever rowIndex = colIndex .
5. Diagonal Traversal : Here's a catch that the summation of both of the index in anti-diagonal element is always equal to the size-1. So we will check here rowIndex+colIndex == rowSize-1 or colSize -1. Then print it.

**SearchIn2D :**

1. Use the nested loop for linear search. Do mention the column number in the function as per the 2D array formula, we need to know the column number to traverse via nested loop.

2. 2D vector creation process :
   vector<vector<int>> vec_name (rows, vector<int>(cols, init value))

3. Vector is pass by value. So we need to pass it with & sign in a function.

**MinIn2D:**

Init INT_MAX in minValue -> compare each value of array with minValue with min() function -> re-init the min() return in minValue and return it.

**Transpose of Matrix:**

1. newArray[i][j] = oldArray[j][i]

2. If you can't use newArray than make the upper right triangle nested loop pattern and swap(arr[i][j], arr[j][i]) .

# Week3 (Assignments) :

<hr/>
