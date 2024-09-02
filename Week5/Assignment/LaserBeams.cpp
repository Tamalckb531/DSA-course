#include <iostream>
#include <vector>
using namespace std;

int countDevice(string &binary)
{
    int count = 0;
    for (auto bin : binary)
    {
        count += bin - '0';
    }
    return count;
}

int numberOfBeams(vector<string> &bank)
{
    vector<int> numberOfDevices;

    //? STEP 1: count device in each row
    for (auto device : bank)
    {
        numberOfDevices.push_back(countDevice(device));
    }

    //? STEP 2: count the laser beam. Stop where the next row is not zero

    // numberOfDevices = 3,0,2,1| totalBeam = 8
    int totalBeam = 0;
    for (int i = 0; i < numberOfDevices.size(); i++)
    {
        int j = i + 1;
        while (j < numberOfDevices.size())
        {
            totalBeam += numberOfDevices[i] * numberOfDevices[j];
            if (numberOfDevices[j] == 0)
                j++;
            else
                break;
        }
    }
    return totalBeam;
}
int main()
{
    return 0;
}