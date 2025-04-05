# Week 4 (class):

## Searching Sorting 1:

/_Revision done_/

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

**LeetCode 34. Find First and Last Position of Element in Sorted Array. [problem](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)**

Just like previous both, call two function and get the first and last position. Then push them in a vector and return them.

## Mega Array:

/_Revision done_/

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

**LeetCode 53. Maximum Subarray. [problem]:(https://leetcode.com/problems/maximum-subarray/)**

<i>Question :</i>

Find out the sub-array(A sub-array is a contiguous non-empty sequence of elements within an array) that have maximum sum.

<i>Intuition (Kadane's Algo) :</i>

1. Sub array is contiguous and the array mixed with -ve and +ve value.
2. We can add one by one value in a sum variable but drop the sum to one whenever the sum terms to 0. The reason is if we add something with a -ve than sum < something. So better to thing add the something with 0.
3. Now we will have a max variable which will store the maximum sum.
4. After the entire loop traverse the max will end up having the maximum sub-array sum. (as it is the largest contiguous non-drop sum)

<i>Approach (Kadane's Algo):</i>

1. Traverse the whole array.
2. Add element into sum.
3. compare ans with sum using max().
4. set sum to 0 if sum<0.

<i>TC and SC</i>

1. TC : O(n)
2. SC : O(1)

## Searching Sorting 2:

**LeetCode 852. Peak Index in a Mountain Array [problem]:(https://leetcode.com/problems/peak-index-in-a-mountain-array/)**

<i>Question :</i>

Given array has a peak value then it goes to decreasing order. Ex : [0,10,5,2]. This are called mountain array. We need to return the index of the peak value.

<i>Intuition :</i>

1. We will think 2 line here. Will include peak in the second line.
2. Will shrink both of the line by searching peak position from mid.
3. Gonna store every mid of Line B as the mid will once end up in peak index.

<i>Approach (Binary_search, store and compute):</i>

1. Line A will be the line before peak and Line B will be the line after peak including peak.
2. On Line A element < nextELement and on line B element > nextELement.
3. While on Line A the peak can be in the right, and left on line B. So we will modify the index and search peak according to that.
4. Peak is in the line B, so we will store the mid index while it will be on the line B until the loop breaks. That's how, after the loop breaks, we will have the peak index.

<i>TC and SC</i>

1. TC : O(logn)
2. SC : O(1)

**LeetCode 33. Search in Rotated Sorted Array [problem]:(https://leetcode.com/problems/search-in-rotated-sorted-array/)**

<i>Question :</i>

Have to search an element in sorted rotated array with logn TC.

sorted rotated : [9,10,11,0,1,2,3,4,5,6,7,8]

<i>Intuition :</i>

1. First step is to find out the pivot where the array rotated:
   1. Here before and after pivot, both line are in increasing order. So we can't use the mountain array method. We need to identify which line is in left and which in right.
   2. We will do binary search where mid could have three condition : mid is the pivot, mid is on right, mid is on left.
   3. Mid will be pivot if mid is larger than it's next element.
   4. Mid is on right can be determine if the element in starting index is larger than mid. Can all element on left including pivot is larger than each element in right. Also start index in binarySearch won't cross the pivot and go in right. We need to take left elements of mid in count.
   5. If nothing matched then the mid is in left. We need to take right elements of mid in count.
2. Next step is to find out the target :
   1. target could be within the range of 0 and pivotIndex.
   2. or it would be in range of pivotIndex+1 and size-1.
   3. Both are increasingly sorted array so we can use binary search on that.

<i>Approach :</i>

1. Getting pivot index :

   1. First handle the edge case of only one element : start == end -> return start.
   2. If mid is pivot:
      1. handle the edge case of mid + 1 < n.
      2. return mid,
   3. If mid in right -> end = mid - 1,
   4. If mid in left -> start = mid + 1,
   5. Update the mid.

2. Getting the target Index :
   1. If 0th index <= target <= pivot index -> binary search and get the targetIndex.
   2. If pivot index + 1 <= target <= size - 1 index
      1. handle edge case of pivotIndex + 1 < size.
      2. binary search and get the targetIndex.

<i>TC and SC</i>

1. TC : O(logn)
2. SC : O(1)

**LeetCode 69. Sqrt(x) [problem]:(https://leetcode.com/problems/sqrtx)**

<i>Question :</i>

Need to find out the square root of the given number x.

<i>Intuition (search space pattern):</i>

1. Gonna binary search on 0 to x space.
2. Will get each element and check their square is equal to the x.
3. If less than x than we will store and compute so that if any square root comes in float than we can store it's lower bound decimal and return it.

<i>Approach :</i>

1. Simple binary search pattern where mid and ans(for store and compute) should be long long.
2. On mid\*mid < x -> do store and compute (store mid in ans)

<i>TC and SC</i>

1. TC : O(logn)
2. SC : O(1)

**LeetCode 74. Search a 2D Matrix [problem]:(https://leetcode.com/problems/search-a-2d-matrix/)**

<i>Question :</i>

Need to search a target in a 2D array.

<i>Approach :</i>

1. Get the row and column of matrix.
2. Start binary search.
3. To find mid element :
   1. rowIndex = mid/col.
   2. colIndex = mid%col.

<i>TC and SC</i>

1. TC : O(logn)
2. SC : O(1)

## Searching Sorting 3:

**Find Quotient without division**

<i>Intuition (search space pattern):</i>

1. As we can't use the division, then we will use this mathematical formula :
   _divisor \* quotient + reminder = dividend_
2. We could have two type of answer here:
   1. On this formula, reminder could be 0 -> _divisor \* quotient = dividend_. In this case the quotient is the definite ans.
   2. reminder could be +ve -> _divisor \* quotient < dividend_. In that case we will consider the nearest quotient the ans.
3. We will use binary search space technique to choose the quotient. This search space will be 0 to dividend (considering the both divisor and dividend are +ve). The mid is always the quotient.

<i>Approach :</i>

1. Just do as usual binary search. Start = 0 to end = dividend.
2. Use mid = (s + (e-s)>>1). Here >> 1 means /2.
3. Check both the condition mentioned in Intuition 2. Return mid in first and store and compute in the second (so that we can find more closer value)

<i>TC and SC</i>

1. TC : O(log(dividend))
2. SC : O(1)

**Searching in nearly sorted array**

<i>Question :</i>

There given an array that is nearly sorted. Which means an element supposed to be in ith index, can be in i+1th or i-1th index. We need to search target with log(n) time complexity.

<i>Intuition and approach:</i>

1. Every time we find the target with mid with binary search, we can also search mid+1 and mid-1 also as the target element maybe in those index and return the index.
2. As we are searching left and right element of mid so we don't need to set the next search for exact left or exact right. We will do :
   1. start = mid+2 for right, as we already searched in mid+1.
   2. end = mid-2 for left, as we already searched in mid-1.

<i>TC and SC</i>

1. TC : O(log(n))
2. SC : O(1)

**LeetCode 540. Single Element in a Sorted Array [problem]:(https://leetcode.com/problems/single-element-in-a-sorted-array/)**

<i>Question :</i>

Each element of given array has occurrence 2 times in a single stretch except one. We need to find that one.

<i>Intuition :</i>

1. Before single element, occurrence start from odd index.
2. After single element, occurrence start from even index.
3. We need to find out the first element of the occurrence and than we can use binary search after finding it's position in left or right by startingPoint odd or even.
4. If an element has no matched value in left or right, that wil be the single element.

<i>Approach (Binary_search, store and compute):</i>

1. First handle the single element condition.
2. For first element, there is no mid-1 and for last, there is no mid+1. So we need to validate the index.
3. Handle the condition of single value where it has no left or right value. Return the mid.
4. Now check the condition if currentValue has matched value in left or right :
   1. For left -> starting point is mid-1 -> if it's odd then currentValue is in right side -> if even than left side.
   1. For right -> starting point is mid -> if it's odd then currentValue is in right side -> if even than left side.
5. Apply binary search -> update mid.

<i>TC and SC</i>

1. TC : O(logn)
2. SC : O(1)

## Mega Class: Searching and Sorting:

**Square root with precision**

<i>Intuition :</i>

1. We already know how to find integer square root. So first we will find that.
2. We need to square the ans for each precision with increasing step (0.1-0.9 and so on) until in over the number to root. Will use store and compute on that.
3. After the root square exceeding input number, we will increase the step (0.1 - 0.01). Also decrease the precision.
4. In the end we will get the ans.

<i>Approach (Binary_search, store and compute):</i>

1. Get the integer sqrt, set precision, set step with 0.1.
2. Start a while loop until precision and init the integer sqrt in a double value.
3. Again start a while loop until { (double value)^2 <=n } .
4. Every time store and compute -> store the double value in sqrt and add step into that double value.
5. Every time loop exceed, divide step / 10 to make it more precision and decrease the precision count.

<i>TC and SC</i>

1. TC : O(logn + precision) -> log(n) for integer sqrt and precision for with precision sqrt.
2. SC : O(1)

**LeetCode 875. Koko Eating Bananas [problem](https://leetcode.com/problems/koko-eating-bananas/description/)**

<i>Question :</i>

Read the question from LeetCode with details.

<i>Intuition and approach (search space , store and computing) :</i>

1. Get the max element first, so that we can create the search space as search space can't go beyond max element.
2. We get the mid element as speed and validated the speed.
   1. For validate we calculate all the hours need to clear the each stack of banana in piles. (hour = element/speed)
   2. Check the total hour is less than or equal to hour given. Return true for that or else false.
3. If speed validate than store it in ans and update the end to search for lesser element as we need to get the minimum speed.
4. Or else to update the start to get the .

<i>TC and SC</i>

1. TC : O(pileSize\*log(maxPile))
2. SC : O(1)

**1482. Minimum Number of Days to Make m Bouquets [problem](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)**

<i>Question :</i>

Read the question from LeetCode with details.

<i>Intuition and approach (search space , store and computing) :</i>

1. First check check totalFlower given in array is sufficient to required bouquets.
2. Minimum day in the array should be starting point for search space as less day can't produce a single flower. Max will be the end.
3. We need to make sure if we can make a bouquet after getting the day as mid.
   1. If any element bloomDay is less than day than it is bloomed and can be used in bouquet. Should account it.
   2. If we count enough flower to make a bouquet than we wil make on bouquet less and count from start.
   3. As per question, we need adjacent flower so, if any flower bloomDay is greater than our day then we will count from start for the next flower.
   4. When we get all bouquet done, we will stop the counting (loop).
4. Bouquet == 0 means it can be a possible ans so we will store it and compute for lesser search space as we need the minimum.

<i>TC and SC</i>

1. TC : O(bloomDaySize\*log(maxDay))
2. SC : O(1)

## Sorting Algo:

**Bubble Sort:**

<i>Intuition and approach :</i>

1. Bubble sort has two main loop
2. Outer loop represents the displacement of a single element towards it's most right. Which means the much the value is the much it will go towards right. So, this loop runs to (0 -> endIndex-1). endIndex-1 cause it is already in it's own index. So -1 is subtracting it's own index traversal.
3. Inner loop is the swap adjacent elements if left is larger than the right one. Every time the first loop run , largest element goes to the top right. So, every time we needs to travel one less than the previous one in the inner loop. That's why it runs to (0 -> endIndex - 1 - outerLoopVal).
4. Every time inside the inner loop we getting an element larger than the right one, we swap it.

<i>TC and SC</i>

1. TC : O(n^2)
2. SC : O(1)

**Selection Sort:**

<i>Intuition and approach :</i>

1. Selection sort has two main loop
2. Outer loop target from the left and make the index the minIndex
3. Inner loop compare all the right most elements with the element in minIndex and swap the smaller one with it's place. That's how it place the smallest element in right in the minIndex.
4. The outer loop run 1 less time then the endIndex. For example: if there is 5 element and we place the smallest 4 from left to right then the 5th one will automatically place itself.
5. The inner loop run from the (target index by outer loop + 1)th index to endIndex. As it needs to compare the right most element of that index with it to find the smallest one.

<i>TC and SC</i>

1. TC : O(n^2)
2. SC : O(1)

**Insertion Sort:**

<i>Intuition and approach :</i>

1. Selection sort has two main loop
2. Outer loop select the right element for compare the with the left sorted once.
   So it starts from 1 as we need a space in left to compare.
3. Inner loop start from i-1 and goes to 0.
   1. It first select the ith element as key and then compare with it's immediate left element > key.
   2. If so then it shift the immediate one in the right and select the next immediate one to compare.
   3. Now it goes until inner loop goes beyond 0 or next immediate is not less then the key.
   4. Then it place the key in the previous immediate place. (j+1).
   5. **The intuition behind the prev 3 and 4 logic is, if the next immediate is not greater than key then the other left most won't be, as they are already sorted in previous step**

<i>TC and SC</i>

4. TC : O(n^2)
5. SC : O(1)

**Custom Comparator:**

Watch the code where we learn about sorting 1D and 2D matrix both increasing and decreasing order.

# Week 4 (Assignments):

**532. K-diff Pairs in an Array [problem](https://leetcode.com/problems/k-diff-pairs-in-an-array/)**

<i>Question :</i>
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k

<i>Intuition :</i>

Basically we will target a single element in this array and find the difference of all other elements in the array. If the difference is equal than we will store it uniquely.

<i>Approach 1 (two pointers approach) :</i>

1. First we need to sort the array to make the task easy.
2. We will get the difference of first and second pointer (init i=0, j=1) and every time it is equal to k, we will store it (Remember to use set to store the unique pair.)
3. If diff > k, that means we need larger first pointer so i++;
4. If diff < k, that means we need larger second pointer so j--;
5. What if k = 0 ? Then all after at a time, both pointers will get in one place and store the single number in a pair. But constrain says i!=j. So we will j++ in i==j.

<i>Approach 2 (Binary Search approach) :</i>

1. Sort the array.
2. We know the difference is k = a[j] - a[i] or a[j] = k + a[i] .
3. Do binary search in the right side to find the a[j] = k + a[i] .
4. If found than store the value.
5. return the size.

<i>TC and SC</i>

1. TC : O(nlogn)
2. SC : O(1)

**658. Find K Closest Elements [problem](https://leetcode.com/problems/find-k-closest-elements/)**

<i>Question :</i>
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

<i>Intuition :</i>

1. We need to first find out the all the difference between elements of the array and x. Remember, there will be a point where difference is 0, so the difference in left and right point should be find out accordingly.
2. Then we need find out the closest k difference element with respect to the element with 0 diff.
3. Then we need to return all.

<i>Approach (two pointers approach) :</i>

1. We will point two pointers, one in the start(low) and one in end(high).
2. Will check if the left difference is larger than right difference.
   1. If so, that means we need closer left. So low++ .
   2. If not, that means we need closer high. So high-- .
3. We found the low and high bound. So now we can return the sub-array like this : vector<int>(arr.begin() + low, arr.begin() + high + 1);

<i>TC and SC</i>

1. TC : O(logn)
2. SC : O(1)

**Exponential Search**

<i>Intuition & Approach:</i>

1. Take an index with i=1, and multiply it with 2 over and over til (i < size && arr[i] <= target).
2. So now instead of doing linear or binary search, you're doing exponential search. Like in 1,2,4,8,16,32... index.
3. That means you'll get the optimized index real quick. Ex: you're searching 21. Which is not in the 1-16 range -> arr[16] <= target.
   But in 16-32 range -> arr[32] > target (breaking condition for loop).
4. After loop break, select the start and end index.
   start = i/2; (as after 16 the loop run one more time)
   end = min(i, size-1); (as the 'i' could go beyond size).
5. Now apply binary search on this optimized index.

<i>TC and SC</i>

1. TC : O(log(2^(log(m)-1)))
   [ The loop run from 1 to 32 like this : 1-2-4-8-16-32, total 5 times. Which means log(32) times.
   The binary search run from 16 to 32. Which means log(32-16) = log(16) = 4 times.
   So the entire Loop TC is log(2^4) = log(2^(5-1)) = log(2^(log(32)-1)). ]
2. SC : O(1)

**GFG. Allocate minimum number of pages [problem](https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)**

**Similar in LeetCode 1011. Capacity To Ship Packages Within D Days [problem](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)**

<i>Question :</i>
Given array is sorted book pages array. We need to distribute this book to m students contiguously and find the minimum number of Maximum pages allocated to a student.

Input: n(array size) = 4, arr[] = {12,34,67,90}, m(total student) = 2
Output: 113
Explanation: Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113.

<i>Intuition :</i>

1. We can count all the pages of that array and create a search space for that.
2. Than we can find the mid and start finding minimum number of pages to allocate.
3. If the mid pages allocated to all student end up having more pages left or need more student to allocate pages, it can't be a solution. So we will update the start for bigger mid.
4. If mid end up allocate all the pages, it could be a potential solution. As we are finding the minimum number of pages to allocate.So we will store and compute(update the end).

<i>Approach (Search Space, store and compute) :</i>

1. First we should check if student is more than book. Return -1 than.
2. Get the endIndex with accumulate function.
3. Do binary search -> For checking the allocation validation we create a function called isPossibleSolution.
   1. Here we will have a pageSum = 0 and studentCount = 1.
   2. Will run a loop for all the book elements.
      1. First edge case -> any book page bigger than the mid -> return false
      2. Second edge case -> new book page added in pageSum bigger than the mid -> new student, add the new page to his pageSum -> newStudent is bigger than the actual student -> return false ( Intuition 3 )
      3. Add the page to the pageSum for a student.
   3. Return true in the end as it could be a possible solution.
4. If possible than we store and compute also update the end for minimum page.
5. If not possible -> we update the start.

<i>TC and SC</i>

1. TC : O(n\*log(sumOfArray))
2. SC : O(1)

**GFG. The Painter's Partition Problem-II [problem](https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1)**

Same as the previous

**GFG. Aggressive Cows [problem](https://www.geeksforgeeks.org/problems/aggressive-cows/0)**

**Similar in LeetCode 1552. Magnetic Force Between Two Balls [problem](https://leetcode.com/problems/magnetic-force-between-two-balls/)**

<i>Question :</i>
Given array is stall position where we need place some aggressive cows. We need to place them such that, they don't fight with each other. So minimum distance between them should be maximum.

Input:
n=5
k=3
stalls = [1 2 4 8 9]
Output:
3
Explanation:
The first cow can be placed at stalls[0],
the second cow can be placed at stalls[2] and
the third cow can be placed at stalls[3].
The minimum distance between cows, in this case, is 3.

<i>Intuition & Approach (Search Space, store and compute) : :</i>

1. We will make a search space for stalls and find out each distance is maximum or not.
2. As per binary search method, if the position/distance can place all cows we will store and compute for greater distance to find the maximum.
3. If not then we will make the search space less.
4. Placement possible or not logic :
   1. first place one cow and define it's position.
   2. Run a loop for the stalls -> get each stall position and find out the distance between prev position and this is less the minimum distance that was found by the binary search.
   3. If so then increase the cowCount and make that position to be cowPos for new cow.
   4. At last check if cowCount reached the totalCow. If so then return true. -> will proceed 2
   5. Or else, all cow wasn't able to placed with the minimum distance. Return false -> will proceed 3.

<i>TC and SC</i>

1. TC : O(n\*log(end-start of array))
2. SC : O(1)

**SPOJ. EKO [problem](https://www.spoj.com/problem/EKO/)**

<i>Question :</i>
An array of tree length will be given. There is a saw machine which is eco friendly. It will cut down tree only for the given total length of cut down part of all trees. So we need to find out minimum height the blade will raise from ground to cut down only these length of tree branches.

Input:
4 7(total length of cut down part of all trees)
20 15 10 17

Output:
15

<i>Intuition & Approach (Search Space, store and compute) : :</i>

1. Just like previous, we will do binary operation. Will store and compute the less number of branch and find for more optimal(start = mid + 1) and will shrink the search space if the branch length exceed minimum branch length given.
2. Branch length calculation logic :
   1. Will get a woodCollected variable and run a loop for whole tree vector.
   2. If a tree is bigger than the mid(or height of blade from ground), then we will store the tree - height of blade in woodCollected.
   3. After this, we will return true if woodCollected is bigger or equal than minimum wood needed.

<i>TC and SC</i>

1. TC : O(n\*log(maxElem))
2. SC : O(1)
