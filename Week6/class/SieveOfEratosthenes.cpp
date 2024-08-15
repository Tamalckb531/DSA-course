#include <iostream>
#include <vector>
using namespace std;

int SieveEratosthenes(int n)
{
    if (n == 0)
        return 0;

    //? STEP 1 -> create a vector for prime number mapping
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false; // 1,0 are not prime number

    // STEP 2 -> mark false for all the table of prime number and count the prime
    int primeCount = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            primeCount++;

            // table marking:
            int j = i + i;
            while (j < n)
            {
                prime[j] = false;
                j += i;
            }
        }
    }

    return primeCount;
}

int countPrimes(int n)
{
    return SieveEratosthenes(n);
}

int main()
{
    return 0;
}