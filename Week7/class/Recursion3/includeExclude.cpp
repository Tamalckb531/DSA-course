#include <iostream>
#include <vector>
using namespace std;

void printSubSequences(string str, int index, string output, vector<string> &ans)
{
    //? base case
    if (index == str.size())
    {
        ans.push_back(output);
        return;
    }

    //? processing
    char ch = str[index];

    //? recursive call
    // include call
    printSubSequences(str, index + 1, output + ch, ans);
    // exclude call
    printSubSequences(str, index + 1, output, ans);
}

int main()
{
    string str = "ab";
    string output = "";
    int index = 0;
    vector<string> ans;

    printSubSequences(str, index, output, ans);

    for (auto i : ans)
    {
        cout << i << " " << endl;
    }

    cout << ans.size() << endl;
    return 0;
}