#include <iostream>
#include <string>
#include <climits>
using namespace std;

string reorganizeString(string s)
{
    int hash[26] = {0}; // a-z mapping for 26 letter. 0 for a and 25 for z

    // first : get the occurrence of each character

    for (int i = 0; i < s.size(); i++)
    {
        int stringIndexMap = s[i] - 'a';
        hash[stringIndexMap]++;
    }

    // second : find the most frequent char

    char most_freq_char;
    int max_freq = INT_MIN;

    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max_freq)
        {
            max_freq = hash[i];
            most_freq_char = i + 'a'; // type casting to char
        }
    }

    // third : place the most frequent character and check if it's placed in one go.

    int index = 0;
    while (max_freq > 0 && index < s.size())
    {
        s[index] = most_freq_char;
        max_freq--;
        index += 2;
    }

    //? check in one go
    if (max_freq != 0)
        return "";

    //? making the most frequency character occurrence to 0 to count the other character
    hash[most_freq_char - 'a'] = 0;

    // fourth: place the rest of the character

    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            index = index >= s.size() ? 1 : index;
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }

    return s;
}

int main()
{
}