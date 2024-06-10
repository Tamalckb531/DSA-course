# Containers

## vector :

1. Dynamic array that can grow or shrink in size.
2. Declaration : vector<data_type> vecName(size, default).
3. .begin() : point the starting location of a vector.
4. .end() : point the last location of a vector.
5. .push_back() : insert element.
6. .pop_back() : remove element.
7. .size() : get the size.
8. .front() : get the first data.
9. .back() : get the last data.
10. .empty() : check if vector empty. return 0 or 1.
11. .at(index) : to get and manipulate data in an index.
12. .capacity() : to see how many capacity the vector can store. (as it is dynamic so it can increase it capacity to double whenever we put more than it has already.)
13. .reserve(num) : to allocate a minimum capacity.
14. .max_size() : maximum how many size can a vector take in a machine.
15. .clear() : to clear all the element.
16. .insert(position, value) : to insert a particular value in an index.
17. .erase(initialIndex, endIndex) : to erase a range of element.
18. swap(vector& x) : To swap elements of a vector with another vector.
19. Iterator : it iterate the vector using .begin() and .end(). Watch the code for use-case.

_2D Array:_

1.  Declaration: vector<vector<data_type>> arr(row, whatToPutInRow);

## LinkedList :

1. Store data in non-contiguous location.
2. node -> has 3 blocks :
   1. first block -> store the memory location of previous data.
   2. middle block -> store data.
   3. last block -> store the memory location of next data.
3. creation : list<int> myList;
4. .push_back() : to add data.
5. .push_front() : to add data from 1st index.
6. .pop_front() : to remove data from 1st index.
7. .pop_back() : to remove data from last data.
8. .size() : to check the size.
9. .empty() : return 1 if the list is empty.
10. .front() : to get the 1st data.
11. .back() : to get the last data.
12. .begin() : first node memory location.
13. .end() : last node memory location.
    **We can iterate the entire list with the help of iterator and begin(),end() (watch the code for that)**
14. .remove(value) : will remove the value from the list. (no matter how times it is there in the list)
15. toBeSwap.swap(valueProvider) : to swap a list with other list value.
16. .insert(position , value) : to add a value in a particular position
17. erase(startPosition, endPosition) : to erase a range of data.

## Queue :

1. Fist in First Out system.
2. Add in the rear and remove from the front.
3. Creation : queue<int> q;
4. .push(value): to add element.
5. .pop(): to remove element.
6. .size(): to check the size.
7. .front(): to get the first data.
8. .backs(): to get the last data.
9. .empty(): return true if q is empty.
10. toBeSwap.swap(valueProvider) : to swap a queue with other queue value.

## Stack :

1. Last in First out.
2. .push() : to add an element.
3. .pop() : to remove an element.
4. .top() : to see an element from the top.
5. .size() : to see the size of the stack.
6. .empty() : return true if the stack is empty.

## Deque :

1. Creation : deque<int> dq;
2. .push_back/front() : to add data from back/front.
3. .pop_back/front() : to remove data from back/front.
4. .front()/.back() : to get data from front/back.
5. .begin()/ .end() : to get the memory location of begin or end.
6. Iterator : watch the code for this. Use to iterate all the value of a deque.
7. .at(index) : to get the value in an index.
8. clear() : to remove all the element.
9. insert(position, value) : to insert a value in a specific location.
10. .erase(startIndex, endIndex) : to erase range of value.

## priority_queue (Max heap) :

1. Store the element according to it's priority. Like highest value.
2. Creation : priority_queue<int> pq;
3. .push() : to add the value;
4. .push() : to add the value;
5. .pop() : to remove the highest priority value.
6. .size() : to get the size.
7. .empty() : return 1 if pq is empty.

**MIN HEAP :**

1. It gives highest priority to the min value.
2. Creation : priority_queue<int, vector<int>, greater<int>> pq;

## map :

1. Store data in key-value pair.
2. Key should be unique.
3. Here we discussed about unordered_map and ordered_map(store data in a sorted order).
4. Declaration : unordered_map<key_D_T, Value_D_T> table;
5. Insertion : table[key] = value;
   table.insert(make_pair(key, value));
6. .size() : to check size.
7. .clear() : to clear whole map.
8. .empty() : return 1 if map is empty.
9. .at(key) : to get a value at specific key.
10. Can create Iterator with it. Watch the code for details.
11. .erase(startPosition, endPosition) : to erase value of a range.
12. .find(key) : return the iterator/position of the key.
13. .count(key) : Return 1 if key found and 0 if key not found.

## set :

1. Store only unique data.
2. Set has two type : ordered and unordered.
3. .insert() : to insert a value.
4. can iterate values with Iterator, give value in sorted way.
5. .clear() : to remove all element.
6. .size() : to get the size.
7. .empty() : return 1 if the set is empty.
8. .erase(startPosition, endPosition) : to remove a range of value.
9. .find(value) : return the starting location of the value. If the value is not available then it gives the ending location of the set.
10. .count(value) : Return 1 if value found and 0 if value not found.

# Containers

## Iterators :

1.  for_each(arr.begin(), arr.end(), func) : use to apply a
    function into a range of array element.
2.  find(arr.begin(), arr.end(), target) : return the
    iterator of the target it found.
3.  find_if(arr.begin(), arr.end(), function) : return
    value iterator according to the function.
4.  count(arr.begin(), arr.end(), target) : return the
    occurrence of the target in the array.
5.  sort(arr.begin(), arr.end()) : to sort array in
    ascending order.
6.  reverse(arr.begin(), arr.end()) : to reverse ab array.
7.  rotate(arr.begin(), arr.begin() + n, arr.end());
    : to rotate a range of array.
8.  unique(arr.begin(), arr.end()): will set an unique
    element array while not modifying the main array. It provides an iterator by which we can access the unique elements.
9.  partition(arr.begin(), arr.end(), func) : it will
    divide array in two parts according to the func condition.

## Numerics :

1. accumulate(arr.begin(), arr.end(), initValue) : to sum
   all element of arr.
2. inner_product(arr1.begin(), arr1.end(), arr2.begin(), 0):
   to get the inner product of two array.
3. partial_sum(arr.begin(), arr.end(), result.begin()) :
   return an array where the elements of it will be arr[i] + sumOfPrev.
4. iota(first.begin(), first.end(), initValue) : Will fill
   the value incrementally for first array.

## Searching and finding :

1. binary_search(arr.begin(), arr.end(), target) : return
   1 if value found.
2. lower_bound(arr.begin(), arr.end(), target) : return the
   target if target exist of return the greater value of it in the array.
3. upper_bound(arr.begin(), arr.end(), target): return the
   greater value of it in the array even if the target exist.

## Min and Max :

1. min(a,b)/max(a,b) : to find the min/max between two
   element.
2. max/min_element(arr.begin(), arr.end()) : to find the
   min/max element of an array.

## Heap :

1. make_heap(arr.begin(), arr.end()) : make an vector
   heap.
2. push_heap(arr.begin(), arr.end()) : after push_back() in
   vector we need to run this.
3. pop_heap(arr.begin(), arr.end()) : before pop_back() in
   vector we need to run this.
4. sort_heap(arr.begin(), arr.end()) : to make the heap
   sorted.

## set:

1. set_union(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), inserter(result, result.begin())) : to get the union of set.
2. set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), inserter(result, result.begin())) : to get the intersection of set.
3. set_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), inserter(result, result.begin())) : to get arr1-arr2.
4. set_symmetric_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), inserter(result, result.begin())) : to get arr1-arr2 (union) arr2-arr1.
