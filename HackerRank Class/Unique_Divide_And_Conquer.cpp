#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll mod;
vector<ll> fact, ifact;

vector<int> mem;
vector<vector<int>> mem2;
ll solve2(int left, int max);

ll rsolve(int n) {
    if (n <= 5) return n != 2;
    return solve2(n-1, (n-1)/2);
}

ll solve(int n) {
    assert(n > 0);
    int& out = mem[n];
    if (out != -1) return out;
    return out = (int)(rsolve(n) * n % mod);
}

ll solve2(int left, int max) {
    if (left == 0) return 1;
    if (!max) return 0;
    int& out = mem2[left][max];
    if (out != -1) return out;
    ll res = solve2(left, max-1);
    if (max > left) return out = (int)res;
    int lim = left / max;
    ll one = solve(max) * max % mod * ifact[max] % mod;
    ll mult = one * fact[left] % mod;
    for (int i = 1;; i++) {
        ll bin = ifact[i] * ifact[left - i * max] % mod;
        res += solve2(left - i * max, max-1) * mult % mod * bin;
        if (i == lim) break;
        if (i % 4 == 0) res %= mod;
        mult = mult * one % mod;
    }
    res %= mod;
    return out = (int)res;
}

int main() {
    cin.sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int N;
    cin >> N >> mod;
    mem.assign(N+1, -1);
    mem2.assign(N+1, vector<int>(N+1, -1));
    int LIM = N+1;
    ll* inv = new ll[LIM] - 1; inv[1] = 1;
    rep(i,2,LIM) inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    fact.resize(N+1);
    ifact.resize(N+1);
    fact[0] = ifact[0] = 1;
    rep(i,1,N+1) {
        fact[i] = fact[i-1] * i % mod;
        ifact[i] = ifact[i-1] * inv[i] % mod;
    }
    cout << solve(N) << endl;
    exit(0);
}