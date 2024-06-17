#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findComplement(vector<int> binary)
{
    int binarySize = binary.size();
    vector<int> twosComp(binarySize + 1, 0);

    // flip the bit and store in twosComp
    int twosCompSize = twosComp.size() - 1;
    for (int i = binarySize - 1; i >= 0; i--)
    {
        twosComp[twosCompSize] = binary[i] == 0 ? 1 : 0;
        twosCompSize--;
    }

    // Now twosComplement with carry
    int carry = 1;
    for (int i = twosComp.size() - 1; i >= 0; i--)
    {
        int sum = twosComp[i] + carry;
        twosComp[i] = sum % 2;
        carry = sum / 2;
    }

    // Edge case: carry remain :
    if (carry)
    {
        twosComp[0] = carry;
    }

    return twosComp;
}

int main()
{

    // vector<int> binary = {1, 1, 1, 0, 1, 0, 1, 1, 0};
    vector<int> binary = {0, 0, 0, 0};
    vector<int> twosComp = findComplement(binary);

    int n = twosComp.size();
    for (int i = 0; i < n; i++)
    {
        cout << twosComp[i] << " ";
    }

    cout << endl;
    return 0;
}