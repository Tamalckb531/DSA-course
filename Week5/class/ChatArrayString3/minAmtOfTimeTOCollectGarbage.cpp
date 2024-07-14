#include <iostream>
#include <vector>
using namespace std;

int garbageCollection(vector<string> &garbage, vector<int> &travel)
{
    // Metal garbage truck
    int pickM = 0;
    int travelM = 0;
    int lastHouseM = 0;

    // Glass garbage truck
    int pickG = 0;
    int travelG = 0;
    int lastHouseG = 0;

    // Pepar garbage truck
    int pickP = 0;
    int travelP = 0;
    int lastHouseP = 0;

    // Targetting each house and getting the total garbage -> we get All pickTime and last visited House index from here
    for (int i = 0; i < garbage.size(); i++)
    {
        string currHouseGarbage = garbage[i];

        // Getting individual garbage from each targetted house
        for (int j = 0; j < currHouseGarbage.length(); j++)
        {
            char garbageType = currHouseGarbage[j];

            if (garbageType == 'G')
            {
                pickG++;
                lastHouseG = i;
            }
            if (garbageType == 'M')
            {
                pickM++;
                lastHouseM = i;
            }
            if (garbageType == 'P')
            {
                pickP++;
                lastHouseP = i;
            }
        }
    }

    int totalPickTime = pickG + pickM + pickP;

    // Getting total Travel Time

    for (int i = 0; i < lastHouseG; i++)
    {
        travelG = travelG + travel[i];
    }

    for (int i = 0; i < lastHouseM; i++)
    {
        travelM += travel[i];
    }

    for (int i = 0; i < lastHouseP; i++)
    {
        travelP += travel[i];
    }

    int totalTravelTime = travelG + travelM + travelP;

    return totalPickTime + totalTravelTime;
}
int main()
{
    return 0;
}