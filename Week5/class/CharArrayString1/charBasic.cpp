#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int getLength(char arr[])
{
    int count = 0;
    int index = 0;

    while (arr[index] != '\0') // until we getting null character, count all character
    {
        count++;
        index++;
    }
    return count;
}

void replaceChar(char arr[], char repChar, char newChar)
{
    int index = 0;

    while (arr[index] != '\0')
    {
        if (arr[index] == repChar)
        {
            arr[index] = newChar;
        }
        index++;
    }
}

void lowerToUpperCase(char arr[])
{
    int index = 0;

    while (arr[index] != '\0')
    {
        char ch = arr[index];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - 'a' + 'A';
            arr[index] = ch;
        }
        index++;
    }
}

void upperToLowerCase(char arr[])
{
    int index = 0;

    while (arr[index] != '\0')
    {
        char ch = arr[index];
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch - 'A' + 'a';
            arr[index] = ch;
        }
        index++;
    }
}

void reverseChar(char arr[])
{
    int len = getLength(arr);

    int i = 0;
    int j = len - 1;

    while (i <= j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

bool checkPalindrome(char arr[])
{
    int len = getLength(arr);

    int i = 0;
    int j = len - 1;

    while (i <= j)
    {
        if (arr[i] != arr[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    //! creation
    // char arr[100];

    // cout << "Enter your name : " << endl;
    // cin >> arr;
    // If will give input like this : "Tamal ckb", It will take Tamal and the space will be consider as tab which will terminate the cin program.

    //? cin.getline(arr, 100) -> to get input with space like : "Tamal ckb"

    // cout << "Your name is : " << arr << endl;
    // cout << arr[0] << "->" << (int)arr[0] << endl;
    // cout << arr[1] << "->" << (int)arr[1] << endl;
    // cout << arr[2] << "->" << (int)arr[2] << endl;
    // cout << arr[3] << "->" << (int)arr[3] << endl;
    // cout << arr[4] << "->" << (int)arr[4] << endl;
    // Input Tama will stop here, so After this is all the null character. It will terminate the program.
    // cout << arr[5] << "->" << (int)arr[5] << endl;
    // cout << arr[6] << "->" << (int)arr[6] << endl;
    // cout << arr[7] << "->" << (int)arr[7] << endl;

    //! Important functions

    // char arr[100];
    // cin >> arr;

    //? Getting the length
    // cout << getLength(arr) << endl;

    //? Replacing Character
    // replaceChar(arr, 'T', 'S');
    // cout << arr << endl;

    //? Lower and Upper Case
    // lowerToUpperCase(arr);
    // cout << arr << endl;

    // upperToLowerCase(arr);
    // cout << arr << endl;

    //? Reverse the array
    // reverseChar(arr);
    // cout << arr << endl;

    //? Palindrome Check
    // bool ans = checkPalindrome(arr);
    // if (ans)
    // {
    //     cout << "Palindrome" << endl;
    // }
    // else
    // {
    //     cout << "Not Palindrome" << endl;
    // }

    //! Built in functions

    // char arr[100];
    // cout << "Enter the input : " << endl;
    // cin >> arr;

    // char arr2[100];
    // cout << "Enter the input : " << endl;
    // cin >> arr2;

    // char arr3[200];
    // arr3 = strcat(arr, arr2);
    // cout << arr3 << endl;

    return 0;
}