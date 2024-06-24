#include <bits/stdc++.h>

struct StringHash {
    int n;
    std::vector<uint64_t> pw1, h1;
    std::vector<uint64_t> pw2, h2;

    static const uint64_t mod1 = 911935319;
    static const uint64_t mod2 = 955078661;
    static const uint64_t b1 = 311;
    static const uint64_t b2 = 359;
    StringHash() {}
    
    StringHash(const std::string& s) : n(s.size()) {
        pw1.resize(n + 1);
        h1.resize(n + 1);
        pw2.resize(n + 1);
        h2.resize(n + 1);
        pw1[0] = 1;
        pw2[0] = 1;
        for (int i = 0; i < n; i++) {
            pw1[i + 1] = pw1[i] * b1 % mod1;
            pw2[i + 1] = pw2[i] * b2 % mod2;
            h1[i + 1] = (h1[i] * b1 + int(s[i])) % mod1;
            h2[i + 1] = (h2[i] * b2 + int(s[i])) % mod2;
        }
    }

    uint64_t get(int l, int r) const {
        uint64_t v1 = (h1[r] - h1[l] * pw1[r - l] % mod1 + mod1) % mod1;
        uint64_t v2 = (h2[r] - h2[l] * pw2[r - l] % mod2 + mod2) % mod2;
        return v1 * mod2 + v2;
    }
};
