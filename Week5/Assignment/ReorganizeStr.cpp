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

string reorganizeString(string s)
{
    //! FLOW : get all the occurrence of each char -> Find the max freq and the char -> place it in s 2 index afterward each occ and see if it goes in one go -> place other char

    //? Get all the occurrence of each char
    int occ[26] = {0}; // 0 for a and a-z occ
    for (int i = 0; i < s.size(); i++)
    {
        int stringIntMapIndex = s[i] - 'a';
        occ[stringIntMapIndex]++;
    }

    //? Find max freq and max freq char
    int max_freq = INT_MIN;
    char max_freq_char;
    for (int i = 0; i < 26; i++)
    {
        if (occ[i] > max_freq)
        {
            max_freq = occ[i];
            max_freq_char = i + 'a'; // type casted to character
        }
    }

    //? Place max freq in s -> see if it goes in one go
    int index = 0;
    while (index < s.size() && max_freq > 0)
    {
        s[index] = max_freq_char;
        max_freq--;
        index += 2;
    }

    if (max_freq != 0)
        return "";

    //? Place other character
    occ[max_freq_char - 'a'] = 0; // making max freq occ 0 as we already placed it

    for (int i = 0; i < 26; i++)
    {
        while (occ[i] > 0)
        {
            index = index >= s.size() ? 1 : index;
            s[index] = i + 'a';
            occ[i]--;
            index += 2;
        }
    }

    return s;
}

int main()
{
}