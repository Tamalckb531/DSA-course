class Solution
{
public:
    //? First create two queue to store Radiant and Dire senete position
    //? Then create a voting simulation until of the queue is empty
    //? check which one is non empty and declare it as winner

    string predictPartyVictory(string senate)
    {
        queue<int> radiantQ, direQ;
        int position = 0; // This will help to store the index also help to re-position the senetors in circular voting

        //? Step1: position storing
        while (position < senate.size())
        {
            char senator = senate[position];
            if (senator == 'R')
                radiantQ.push(position);
            if (senator == 'D')
                direQ.push(position);
            position++;
        }

        //? Step2: voting simulation
        while (!radiantQ.empty() && !direQ.empty())
        {
            int rIndex = radiantQ.front();
            radiantQ.pop();

            int dIndex = direQ.front();
            direQ.pop();

            if (rIndex < dIndex)
                radiantQ.push(position++);
            else
                direQ.push(position++);
        }

        //? Step3: declare winner
        if (!radiantQ.empty())
            return "Radiant";
        return "Dire";
    }
};