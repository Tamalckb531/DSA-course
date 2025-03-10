#include <iostream>
#include <numeric>
#include <vector>
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

bool isPossibleToAllocatePractice(vector<int> &arr, int minPage, int totalStudent, int totalBooks)
{
    int pageSum = 0;
    int studentCount = 1; //? 1st student to allocate books

    for (int i = 0; i < totalBooks; i++)
    {
        if (arr[i] > minPage)
            return false;

        if (pageSum + arr[i] > minPage)
        {
            //? can't allocate to the current student -> shift to next student
            studentCount++;
            pageSum = arr[i]; //? new book allocated for the next student

            if (studentCount > totalStudent)
                return false; //? page still left after allocating to all studnets
        }
        else
        {
            pageSum += arr[i]; //? book pages allocation
        }
    }

    return true; //? pages allocated to all the students
}

int findPagesPractice(vector<int> &arr, int k)
{
    int totalStudent = k;
    int totalBooks = arr.size();

    if (totalStudent > totalBooks)
        return -1;

    //? search space for the books
    int start = 0;
    int end = accumulate(arr.begin(), arr.end(), 0); //? sum up books array numbers | total pages
    int mid = start + (end - start) / 2;             //? atmost page allocated to a student
    int ans = 0;

    while (start <= end)
    {
        if (isPossibleToAllocatePractice(arr, mid, totalStudent, totalBooks))
        {
            ans = mid;
            end = mid - 1; //? as per question, we need the minimum value
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