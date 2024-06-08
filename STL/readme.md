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
