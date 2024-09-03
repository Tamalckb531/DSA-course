#include <bits/stdc++.h>

using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> ans;
    vector<string> currentLine;
    int currentLineTotalChars = 0;

    for (int i = 0; i < words.size(); i++)
    {
        string &currentWord = words[i];

        int currentLineMinimumSpaces =
            currentLine.size(); // we need a space after each word

        // full justified case
        if (currentLineTotalChars + currentLineMinimumSpaces + currentWord.size() > maxWidth)
        {
            // means, currentLine without taking
            // currentWord is complete

            int extraSpaces = maxWidth - currentLineTotalChars;
            int spaceGoInBetweenWords =
                extraSpaces / max(1, (int)currentLine.size() - 1);
            int reminder =
                extraSpaces % max(1, (int)currentLine.size() - 1);

            // don't need spaces after last word
            for (int j = 0; j < currentLine.size() - 1; j++)
            {
                // add even spaces
                for (int k = 0; k < spaceGoInBetweenWords; k++)
                {
                    currentLine[j] += " ";
                }
                // for left justification
                if (reminder > 0)
                {
                    currentLine[j] += " ";
                    reminder--;
                }
            }

            if (currentLine.size() == 1)
            {
                // left justified case, becuase only 1 word in the line
                while (extraSpaces--)
                {
                    currentLine[0] += " ";
                }
            }

            // let's prepare our final line
            string finalLine = "";
            for (string wordWithSpaces : currentLine)
            {
                finalLine += wordWithSpaces;
            }

            ans.push_back(finalLine);
            currentLine.clear();
            currentLineTotalChars = 0;
        }

        // currentLine is not complete
        currentLine.push_back(currentWord);
        currentLineTotalChars += currentWord.size();
    }

    // Let's take care of last line
    // add 1 space between words

    string finalLine = "";
    for (auto word : currentLine)
    {
        finalLine += word + " ";
    }
    finalLine.pop_back(); // remove extra space

    // if still maxWidth is not acheived
    int leftSpaces = maxWidth - finalLine.size();
    while (leftSpaces--)
    {
        finalLine += " ";
    }
    ans.push_back(finalLine);
    return ans;
}

int main()
{
    return 0;
}