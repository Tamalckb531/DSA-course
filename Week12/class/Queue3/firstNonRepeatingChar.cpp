class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        unordered_map<char, int> freq;
        string ans = "";
        queue<char> q;

        for (int i = 0; i < A.length(); i++)
        {
            char ch = A[i];
            freq[ch]++;
            q.push(ch);
            while (!q.empty())
            {
                char frontElement = q.front();
                if (freq[frontElement] == 1)
                {
                    ans.push_back(frontElement);
                    break;
                }
                else
                {
                    q.pop();
                }
            }
            if (q.empty())
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};