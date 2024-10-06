/**
 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
 *    const vector<NestedInteger> &getList() const;
 * };
 */

//? As the class return next value as integer and have NestedInteger datatype, we need to flatten the List in integer queue. Then we can simply implement the next and hasNext function.

class NestedIterator
{
public:
    queue<int> flat;

    void flatten(vector<NestedInteger> &nestedList)
    {
        for (auto item : nestedList)
        {
            if (item.isInteger())
            {
                flat.push(item.getInteger());
            }
            flatten(item.getList());
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        flatten(nestedList);
    }

    int next()
    {
        int element = flat.front();
        flat.pop();
        return element;
    }

    bool hasNext()
    {
        if (flat.empty())
            return false;
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */