#include <iostream>
#include <numeric>
using namespace std;

bool isPossibleForAllocation(int arr[], int totalStudent, int totalBook, int minimumPage)
{
    int pageSum = 0;
    int studentCount = 1;

    for (int i = 0; i < totalBook; i++)
    {

        // first edge case for page in a book larger than minimum page
        if (arr[i] > minimumPage)
            return false;

        // second edge case for totalPageCount exeding minimum page
        if (pageSum + arr[i] > minimumPage)
        {
            // need new student to allocate that book
            studentCount++;
            pageSum = arr[i];

            // main break point for need more student than given to allocate all the books
            if (studentCount > totalStudent)
                return false;
        }

        else
        {
            pageSum += arr[i];
        }
    }

    return true;
}

// Function to find minimum number of pages.
long long findPages(int n, int arr[], int m)
{
    // number of students can't be bigger than number of book
    int totalStudent = m;
    int totalBook = n;

    if (totalStudent > totalBook)
        return -1;

    int start = 0;
    int end = accumulate(arr, arr + n, 0); // total book page
    int mid = start + (end - start) / 2;
    int ans = 0;

    while (start <= end)
    {
        if (isPossibleForAllocation(arr, totalStudent, totalBook, mid))
        {
            ans = mid;
            end = mid - 1; // finding minimum solution
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    std::cout << "Hello World!\n";
    int n = 4;
    int arr[] = {12, 34, 67, 90};
    int m = 2;

    int ans = findPages(n, arr, m);
    cout << ans << endl;
}