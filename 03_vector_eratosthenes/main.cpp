#include "../std_lib_facilities.h"

int main(void)
{
    // The 0 is prime number.
    // The 1 is not prime number.

    const int   kSize{100};
    const int   kStartPrimeNum{2};
    vector<int> sieve(kSize); // vector of kSize ints, each initialized to 0
    vector<int> primes;

    for (int i = kStartPrimeNum; i < kSize; ++i) {
        if (sieve[i] == 0) {
            primes.push_back(i);

            for (int j = i*i; j < kSize; j += i) {
                sieve[j] = 1; 
            }
        }
    }
    for (int n : primes) {
        cout << n << '\n';
    }

    return 0;
}
