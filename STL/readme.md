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
