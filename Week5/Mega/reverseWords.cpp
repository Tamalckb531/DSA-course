#include <bits/stdc++.h>

using namespace std;
string reverseWords(string s)
{
    //? Process : Reverse the enitre string -> Remove all leading/internal space -> place the word in the place of space -> re-reverse the word only -> add a space after each word -> do it until the last -> resize the string for valid string.

    //? STEP 1 : Reverse the entire string
    reverse(s.begin(), s.end());

    int size = s.size();
    int start = 0, end = 0;

    for (int i = 0; i < size; i++)
    {

        //? STEP 2 : Remove all leading/internal space
        while (s[i] == ' ' && i < size)
        {
            i++;
        }
        if (i == size)
            break; // there is nothing after this

        //? STEP 3 : Place the word in the place of space
        while (s[i] != ' ' && i < size)
        {
            s[end++] = s[i++];
        }

        //? STEP 4 : Re-reverse the word only
        reverse(s.begin() + start, s.begin() + end);

        //? STEP 4 : Add a space after each word
        s[end++] = ' ';

        start = end; // pointing the start for a new word
    }

    //? STEP 5: Resize the string for valid string
    s.resize(end - 1); // as end already add an extra space so we need to remove that
    return s;
}

int main()
{
    return 0;
}