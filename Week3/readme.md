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

**Key pair GFG (<a href="https://www.geeksforgeeks.org/problems/key-pair5616/1?ref=gcse">Problem</a>)**

<i>Approach 1(two sum approach) :</i>

1. Find out all the pair and sum of all.

<i>Method 1 :</i>

1. Nested Loop i=0 and j=i+1. Sum each element with other elements and check if the sum is equal to target or not. If yes than return true.

```diff
- TC: O(n^2) -> not useful for the question constrains
```

<i>Approach 2(two pointer approach) :</i>

1. Make the array sorted in increasing order.
2. Take two pointer index low and high.
3. Each time sum of both is lower than target than low++. -> lower means need a high value -> low++ means adding high value in sum as it is arranged in increasing order.
4. Vice-versa sum of both is higher than target than high--.
5. Return true when sum is equal to target.

<i>Method 1 :</i>

1. To sort : sort(arr, arr+n);
2. For low and high traversal make a while loop for low<high condition.

```diff
+ TC: O(n) -> ok for the question constrains
```

**724. Find Pivot Index LeetCode (<a href="https://leetcode.com/problems/find-pivot-index/">Problem</a>)**

<i>Question understand :</i>
There is an array where we need to return the pivot index. The pivot index is the index which leftSum = rightSum.

<i>Approach 1(Brute Force) :</i>

1. Get the sum of both left and right side and check if they are same or not.
2. Do not include the potential pivot element in the sum.

<i>Method 1 :</i>

1. Nested loop needed. internal Loop :
   1. For left sum : j -> 0---i
   2. For left sum : j -> i+1---n
   3. Not including the ith element as it could be the pivot.
2. If left sum = right sum then return the i which is the pivot.

```diff
- TC: O(n^2) -> not useful for the question constrains
```

<i>Approach 2(prefix sum approach) :</i>

1. Watch the note for dry run.
2. Take two array leftSum and rightSum and store all the index wise sum into them. Like 2nd index will store 0+1 index sum in leftSum and 3+4+5(assuming n=6) in the rightSum.
3. Check if any index of both them has same value. If so then return.

<i>Method 1 :</i>

1. First loop for lsum will be 1---nums.size(). (as first sum will be 0).
2. Second loop for rsum will be nums.size()-2---0. (as last sum will be 0).
3. Third loop will be 0---nums.size(). Here we will check for the same index for both array and it will be the pivot.

```diff
+ TC: O(n) -> ok for the question constrains
+ SC: O(n) -> ok for the question constrains
```

**268. Missing Number (<a href="https://leetcode.com/problems/missing-number/">Problem</a>)**

<i>Question understand :</i>
Need to find out the missing number in a range. Like if the range is 3 then we need to see from 0,1,2,3 which number is missing in the given array.

<i>Approach 1(Brute Force) :</i>

1. Sorting the array will make the elem and index map clear. Like for 2 index the element will be two.
2. So if we sort the array and traverse it, and while traversing if we see any index is not matching with the element, then that index will be the missing element. (as the array sorted so element should be in 0-X order just like the index)

<i>Method 1 :</i>

1. sort the array with sort(arr.begin(), arr.end()) method.
2. Run a loop from 0 to n size and check if index!=arr[index]. Return index on condition match.
3. Edge case : If all element is matched with the index than last size n will be the missing number. Like [0,1] arr.size = 2 so missing number is 2.
4. return arr.size() after the end.

```diff
- TC: O(nlogn) -> for the sort method. Not useful.
+ SC: O(1) -> Ok.
```

<i>Approach 2(Bitwise approach) :</i>

1. We know that A^A = 0, 0^A=A and A^A^B^B^C = 0.
2. So we will XOR all array value and range value. Than we will get the Missing element.

<i>Method 1 :</i>

1. Get a ans variable with value 0. (as A^0 = A law).
2. Run a loop to XOR all elements of array. 0---array.size() - 1.
3. Run a loop to XOR all range value. 0---array.size().
4. Return the ans.

```diff
+ TC: O(n) -> ok for the question constrains
+ SC: O(1) -> ok for the question constrains
```

**26. Remove Duplicate from Sorted Array (<a href="https://leetcode.com/problems/remove-duplicates-from-sorted-array/">Problem</a>)**

<i>Question understand :</i>
There is a sorted array with duplicate elements and we need to return how many unique elements are there which will be k and re-arrange the array with all the unique element placed in the 0-k index position. Doesn't matter what element after the kth index in the array.

<i>Approach (Two pointers approach) :</i>

1. Keep a checker which will check each element of the array.
2. Keep a unique which will set all the unique element of the array one after another.
3. As unique is the index so k will be unique+1.

<i>Method :</i>

1. Start checker index from 1 and unique from 0. As the first element don't need to change it's place.
2. Increase the checker whenever checker index element = unique index element. (which means this is duplicate so we need check the next one.)
3. If not equal than increase the unique element (to place to unique side by side) -> set the element in checker in unique index -> increase the checker(as the element already checked and we need to check the next one.)
4. The traverse should be in a while loop where the loop will continue until checker < array.size().

```diff
+ TC: O(n) -> n is the array size.
+ SC: O(1) -> We create only two variable.
```

**643. Maximum Average Subarray (<a href="https://leetcode.com/problems/maximum-average-subarray-i/">Problem</a>)**

<i>Question understand :</i>
There is a array given and we need to find the sub-array of this with k element which will have the maximum average(sum/k) .

<i>Approach (sliding window approach) :</i>

1. To maximize the average we need to maximize the sum.
2. We will create a window starting from 0 index and ending in k-1 index. So that we can slide the window by increasing starting and ending point by one.
3. Will sum up all the element in that window than compare them with other sum to see if it is the max.
4. After finding the max we will find the avg in double and return it.

<i>Method :</i>

1. Sliding window starting point i=0 and j=k-1.
2. A loop will run until j < array.size().
3. will store all the value of one window in sum variable by a for loop running form i to j.
4. Compare the sum by the max() function with maxSum which is init INT_MIN.
5. return maxAvg = maxSum /(double) k; -> explicit typecasting for making the output double.

```diff
- TC: O(n^2) -> Not suitable.
+ SC: O(1) -> We create only two variable.
```

<i>Approach (sliding window approach without loop nesting) :</i>

1.We can just set one loop to sum the initial i to k window
2.Then make an outer loop where we just adding next elem after last index and removing the 1st element. 3. Then comparing it with the previous one and storing the bigger one in a maxSum variable. 4. Then doing the rest like the previous.

<i>Method :</i>

1. Make first for loop to do the initial sum. Make it the maxSum.
2. Increase the j or last index of window as we need to work with next element.
3. Make the next while loop until last index exceeding the size.
   1. Remove the first element.
   2. Add the next element.
   3. Increase the first and last index.
4. Get the maxAvg and return it.

```diff
+ TC: O(n) -> Ok.
+ SC: O(1) -> Ok.
```

**75. Sort Color (<a href="https://leetcode.com/problems/sort-colors/">Problem</a>)**

<i>Question understand :</i>
There is an array with 0,1,2 multiple times. Sort them in increasing order.

<i>Approach (counting element approach) :</i>

1. Count 0,1,2 appearance.
2. Add those element by loop while maintaining the hierarchy 0-1-2.

<i>Method :</i>

1. Make three variable zero, one and two to count the appearance.
2. Traverse the whole array with a for loop and check each element, increasing the counting var number according to the element.
3. Make an outer index init 0 and three while loop where it will first include all the 0 then 1 then 2 also on each loop the index will rise and the counting will decrease to zero (which will be the condition of the loop)

```diff
+ TC: O(n) -> Ok.
+ SC: O(1) -> ok.
# But the code do not sort in place.
```

<i>Approach (three pointer approach) :</i>

1. See the dry run in note.
2. Make three pointer low, medium (both pointing in first index) and high (pointing in last index).
3. Medium is the key factor. Value on it's index will change the direction.
4. When medium index has 0 -> medium should send the value to low -> swap with low index value and increase both of the point to check next.
5. When medium index has 1 -> It is on the right index -> increase the medium point to check the next.
6. When medium index has 2 -> medium should send it to high -> swap with high index value and decrease the high index to check the next.
7. All work should done in a while loop where medium <= high.

<i>Method :</i>

1. Make first for loop to do the initial sum. Make it the maxSum.
2. Increase the j or last index of window as we need to work with next element.
3. Make the next while loop until last index exceeding the size.
   1. Remove the first element.
   2. Add the next element.
   3. Increase the first and last index.
4. Get the maxAvg and return it.

```diff
+ TC: O(n) -> Ok.
+ SC: O(1) -> Ok.
```

**Move Negative Number in Left :**

<i>Question understand :</i>
There's an array with negative and positive number unsorted, we just need to set the negative numbers in the left. No sort needed.

<i>Approach (Dutch National Flag Algo) :</i>

1. Keep two pointers one on first index (left) and other on last index (right).
2. left index should store the negative number so we will check if num[left]<0, if ok then check next -> left++.
3. right index should store the positive number so we will check if num[left]>0, if ok then check next -> right--.
4. If no condition matched that means left has positive number and right has negative number. So we will swap them

```diff
+ TC: O(n) -> Ok.
+ SC: O(1) -> ok.
```

**LeetCode 287. Find The Duplicate Number ((<a href="https://leetcode.com/problems/find-the-duplicate-number/">Problem</a>)) :**

<i>Question understand :</i>
An array given has one integer more than one time. We need to find that without modifying the array. The element here in the array is within the range of index.

<i>Approach :</i>

Sent the first element on it's equal index (like if the first element is 3 than sent it on 3rd index). If the first element already exist in it's equal index that that number is duplicate.

<i>Method :</i>

1. Make the while loop condition -> until firstElement is not equal to it's equal index.
2. swap the the equal index and firstElement inside the loop so the other element is the firstElement now.
3. Return the firstElement when the loop break as it has now the element that is duplicate existing in it's own index and first index both.

```diff
+ TC: O(n) -> Ok.
+ SC: O(1) -> ok.
```

**Missing Element from and Array with Duplicates :**

<i>Question understand :</i>
An array given has one integer more than one time and some element's are missing. We need to find that missing element . The element here in the array is within the range of index.

<i>Approach (visiting array approach) :</i>

1. Lets call the index : arrayIndex and elements : elementIndex.
2. Traverse the array normally and take each element by arrayIndex.
3. Use the element as elementIndex and make the element on those elementIndex -ve.
4. So the element that don't exist on array, the equivalent index element of those missing elements will be positive number.
5. Print them to show.

<i>Method :</i>

1. Traverse Array with arrayIndex.
2. Take each element as elementIndex or the whole array.
3. See if that element is positive -> if so then make it negative.
4. Now all elements that are missing their equivalent index element are positive so print them.

```diff
+ TC: O(n) -> Ok.
+ SC: O(1) -> ok.
```

**GFG. First Repeating Element (<a href="https://www.geeksforgeeks.org/problems/first-repeating-element4018/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article">problem</a>):**

<i>Question understand :</i>
An array is given with multiple element repeating themselves. Now we need to return the index of leftMost repeated element.

<i>Approach (hashing) :</i>

1. Map all the element(key) with their count(value) by traversing the array.
2. Traverse the map and see if any key/element has value/count more than one. return the index. (we traversing from the left 0-n so returned index will be the leftMost)

<i>Method :</i>

1. Make hashmap with unordered_map< int, int >.
2. Use arr[i] as key in the first traversal.
3. Second traversal check the count with hash[arr[i]].

```diff
+ TC: O(n) -> Ok.
+ SC: O(n) -> ok.
```

**GFG. Common elements (<a href="https://www.geeksforgeeks.org/problems/common-elements1132/1">problem</a>):**

<i>Question understand :</i>
Three sorted array are given where three have some common elements. We need to find out all of them and return them as a vector. Repeated common element should return as one element.

<i>Approach (Three pointers) :</i>

1. Get three pointer for three of the array and check if all the pointer pointing elements that are equal or not:

   1. If equal than :

      1. Store them in an set to avoid the repetition and later store those in vector.
      2. increase all the pointers to check the next.

   2. If not than :

      1. Check first array value is shorter than the second array value. If so then increase first pointer. (as both sorted array so closer or greater value to second array will be the next value of first array)
      2. Check for the second and third like same and do increase the second pointer if the condition match.
      3. If none of them match that third has the smallest value so increase the third pointer.

2. Do this entire thing in a while loop until one pointer crossing the range.

<i>Method :</i>

1. use set to store the common value
2. After that use for(auto elem:set) to store all element of set in vector.

```diff
+ TC: O(n1+n2+n3) -> Ok.
+ SC: O(n) -> ok.
```

**LeetCode 54. Spiral Matrix (<a href="https://leetcode.com/problems/spiral-matrix/">Problem</a>) :**

<i>Question understand :</i>
Given 2D matrix should printed spirally.

<i>Approach :</i>

1. Set 4 index for startingCol, StartingRow, endingCol, endingRow.
2. Print in this order startingRow -> endingCol -> endingRow -> startingCol.
3. Each time printing one, shrink them by increasing or decreasing one.
4. All this will happen in a loop which will run until count of print is less than row\*col (add this condition also in all 4 printing condition in for loop)

<i>Method :</i>

1. Watch the code. It is in good format already.

```diff
+ TC: O(row*col) -> Ok.
+ SC: O(row*col) -> ok.
```

**GFG. Factorials of large numbers (<a href="https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1">problem</a>):**

<i>Question understand :</i>
We need to store the big number factorial in an array cause int can't store really big number.

<i>Approach & Method :</i>

1. Traverse For each number from 2 to N. (push 1 at ans in beginning). Set a carry 0.
2. Inside traverse the ans array:
   1. multiply the number of factorial with number inside array. Add the carry with them.
   2. modulus the 1 with 10 and store it in ans with co-current index.
   3. Get the carry.
3. We can get carry more than one digit so we need to break the carry into one digit and push it over and over.
4. reverse the ans to get backward to forward number.

```diff
+ TC: O(n^2) -> Ok.
+ SC: O(n) -> ok.
```

<hr/>
