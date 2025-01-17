#include <bits/stdc++.h>

using ll = long long;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int power(int a, int b, int p){
    int ans = 1 % p;
    for(; b; a = (a * a) % p, b >>= 1){
        if(b & 1){
            ans = (ans * a) % p;
        }
    }
    return ans;
}

//扩展欧几里得算法
using Int = __int128_t;

int exgcd(int a, int b, Int& x, Int& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}
/*
    ax + by = gcd(x, y)

    一组解 x1, y1
    得到通解 x = x1 + k * b;
            y = y1 - k * a;
*/

//floor(a / b)
Int divFloor(Int a, Int b) {
    return a / b - (((a ^ b) < 0 && a % b != 0) ? 1 : 0);
}

// ceil(a / b)
Int divCeil(Int a, Int b) {
    return a / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);
}


int euler_phi(int n){
    int res = n;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            res = res / i * (i - 1);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) res = res / n * (n - 1);
    return res;
}


std::vector<int> minp, primes;
std::vector<int> pi;

bool isprime(int n) {
    return minp[n] == n;
}

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}
//BSGS
int BSGS(int a, int b, int m) {
    std::map <int, int> hs;
    hs.clear();
    int cur = 1, t = std::sqrt(m) + 1;
    for (int B = 1; B <= t; ++B) {
        (cur *= a) %= m;
        hs[b * cur % m] = B; // 哈希表中存B的值
    }
    int now = cur; // 此时cur = a^t
    for (int A = 1; A <= t; ++A) {
        auto it = hs.find(now);
        if (it != hs.end())
            return A * t - it->second;
        (now *= cur) %= m;
    }
    return -1; // 没有找到，无解
}
