#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;

    //! ----------- STEP 1: Create a vector of string with numRows number of string -----------

    vector<string> zigzag(numRows); // zigzag will have three string

    int i = 0, row = 0; // i is for the entire s traversal and row is for the zigzag row traversal.
    bool direction = 1; // Top -> Bottom

    //! ----------- STEP 2: Store the char of s in zigzag pattern -----------

    while (true)
    {
        if (direction)
        {
            // Top -> Bottom print.
            // First is 0-numRows
            // Onwards is 1-numRows
            while (row < numRows && i < s.size())
            {
                zigzag[row++].push_back(s[i++]);
            }
            row = numRows - 2; // row is now last-1
        }
        else
        {
            // Bottom -> Top print : last - 0
            while (row >= 0 && i < s.size())
            {
                zigzag[row--].push_back(s[i++]);
            }
            row = 1; // setting for next Top->Bottom
        }

        if (i >= s.size())
            break;
        direction = !direction; // Shifting direction
    }

    //! ----------- STEP 3: Store all string in a single string -----------

    string ans = "";
    for (int i = 0; i < zigzag.size(); i++)
    {
        ans += zigzag[i]; // all strings concatinating in one string
    }

    return ans;
}
int main()
{
    return 0;
}