class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int balance = 0;
        int deficit = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            //? count the balance first
            balance = balance + (gas[i] - cost[i]);

            //? check if deficit
            if (balance < 0)
            {
                deficit += abs(balance);
                start = i + 1; // start can't be in deficit index
                balance = 0;   // as the balance counted as deficit
            }
        }

        if (balance - deficit >= 0)
            return start;
        return -1;
    }
};