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


std::vector<int> primes;
std::vector<bool> vis;
void init(int n){
    vis.resize(n + 1, false);
    for(int i = 2; i <= n; i++){
        if(vis[i] == false) primes.push_back(i);
        for(int j = 0; j < (int)primes.size() && i * primes[j] <= n; j++) {
            vis[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
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
