#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int sherlockAndAnagrams(string s)
{

    //? Get all anagram -> sort them -> store in a map -> count the unique pair with nCr formula

    int uniqueAnagramCount = 0;
    unordered_map<string, int> anagram_map;

    //* Loop for listing sorted anagram strings frequency
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            //? STEP 1 : Get all anagram
            // i to j-i+1 formula to get all the anagram for second loop
            string subStr = s.substr(i, j - i + 1); // Step 1 done

            //? STEP 2: sort them -> for getting the count
            sort(subStr.begin(), subStr.end());

            //? STEP 3: store in a map
            anagram_map[subStr]++;
        }
    }

    //? STEP 4: count the unique pair with nCr formula
    for (auto eachAnagram : anagram_map)
    {
        int count = eachAnagram.second;
        int uniquePairCombination = (count * (count - 1)) / 2;
        uniqueAnagramCount += uniquePairCombination;
    }

    return uniqueAnagramCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
