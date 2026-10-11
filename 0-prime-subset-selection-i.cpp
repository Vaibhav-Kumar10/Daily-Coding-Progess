class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false, isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = 2 * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> primes, selected_primes;
        for (int i = 0; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        int cur_sum = 0, prime_cnt = 0;
        for (int prime : primes) {
            if (prime + cur_sum > s) {
                break;
            }
            cur_sum += prime;
            prime_cnt++;
            selected_primes.push_back(prime);
        }
        cout << prime_cnt;
        return selected_primes;
    }
};