#include <iostream>
using namespace std;

class Solution
{
public:
    //! STEPS :
    //? 1. Divide the before and after of *
    //? 2. Check both inside string and find the starting index from left adn right side
    //? 3. Starting Index of both shouldn't be npos and shouldn't overlap each other

    bool hasMatch(string s, string p)
    {
        int starPos = p.find('*');

        // Dividing before and after of *
        string p1 = p.substr(0, starPos);
        string p2 = p.substr(starPos + 1);

        // find positions of p1 and p2 in s
        int idx1 = (p1.empty()) ? 0 : s.find(p1);         // in case of "*x"
        int idx2 = (p2.empty()) ? s.size() : s.rfind(p2); // in case of "x*"

        // npos and overlap check
        if ((idx1 != string::npos) && (idx2 != string::npos))
        {
            if (idx1 + p1.size() <= idx2)
            {
                return true;
            }
        }

        return false;
    }
};