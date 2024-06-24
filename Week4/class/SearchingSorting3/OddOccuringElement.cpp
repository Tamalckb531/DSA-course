#include <iostream>
#include <vector>
using namespace std;

//? Question : Odd Occurring Element :
// All element occurs even number of times except one.
// ELement repeats itself in pairs.
// no pair repeats itself, no number can occur more than 2 times in a single stretch.
// find element that occur odd times.
int findOddOccurringElement(vector<int> &nums, int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        // single element
        if (start == end)
        {
            return start;
        }

        // index validated left and right value
        int leftValue = -1;
        int rightValue = -1;
        int currentValue = nums[mid];

        if (mid - 1 >= 0)
        {
            leftValue = nums[mid - 1];
        }
        if (mid + 1 < size)
        {
            rightValue = nums[mid + 1];
        }

        // non duplicate value
        if (currentValue != leftValue && currentValue != rightValue)
        {
            return mid;
        }

        // duplicate value -> on left
        if (mid - 1 >= 0 && currentValue == leftValue)
        {
            int startingIndex = mid - 1;
            // odd or even
            if (startingIndex & 1)
            {
                // odd means element in right
                end = mid - 1;
            }
            else
            {
                // even means element in left
                start = mid + 1;
            }
        }

        // duplicate value -> on right
        if (mid + 1 < size && currentValue == rightValue)
        {
            int startingIndex = mid;
            // odd or even
            if (startingIndex & 1)
            {
                // odd means element in right
                end = mid - 1;
            }
            else
            {
                // even means element in left
                start = mid + 1;
            }
        }

        mid = start + (end - start) / 2;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 2, 3, 3, 4, 4, 5, 5, 3, 3};
    int size = 11;

    int ans = findOddOccurringElement(arr, size);
    cout << "ans index : " << ans << endl;
    cout << "ans element : " << arr[ans] << endl;

    return 0;
}