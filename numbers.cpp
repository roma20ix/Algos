#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = __int128;


// Prime numbers
vector<int> primes(int n) {
    vector<int> p, mini(n + 1);
    for (int i=2; i<=n; ++i) {
        if (mini[i] == 0) {
            mini[i] = i;
            p.push_back(i);
        }
        for (const int& y : p) {
            if (y*i > n || mini[i] < y) break;
            mini[y*i] = y;
        }
    }
    return p;
}


// Sieve of Eratosthenes
vector<bool> primes_sieve(int n) {
    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;
    for (int i=2; i*i<=n; ++i) {
        if (p[i]) {
            for (int j=i*i; j<=n; j+=i) p[j] = false;
        }
    }
    return p;
}


// Multiplication modulo
ll mod_mul(ll a, ll b, ll mod) {
    return (ull(a) % mod * ull(b) % mod) % mod;
}


// Addition modulo
ll mod_add(ll a, ll b, ll mod) {
    return (a % mod + b % mod + mod) % mod;
}


// Multiplication modulo
ll mod_sub(ll a, ll b, ll mod) {
    return (a % mod - b % mod + mod) % mod;
}


// Fast exponentiation (a^n)
ll bp(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res*a;
        a = a*a;
        n >>= 1;
    }
    return res;
}


// Fast exponentiation (a^n mod (mod))
ll mod_pow(ll a, ll n, ll mod) {
    ll res = 1;
    a %= mod;
    while (n) {
        if (n & 1) res = mod_mul(res, a, mod);
        a = mod_mul(a, a, mod);
        n >>= 1;
    }
    return res;
}


// Division modulo (mod is prime)
ll mod_div(ll a, ll b, ll mod) {
    return mod_mul(a, mod_pow(b, mod - 2, mod), mod);
}


// Greatest common divisor (GCD)
ll gcd(ll a, ll b) {
    return __gcd(a, b);
}


// Least common multiple (LCM)
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}


// Checking if a number is prime (Normal)
bool is_prime(ll n) {
    if (n == 2 || n == 3 || n == 5) return true;
    if (n == 1 || n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;

    for (ll i=5; i*i<=n; i+=6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}


// Checking if a number is prime (Miller-Rabin)
bool miller_rabin(ll n) {
    if (n == 2 || n == 3) return true;
    if (n == 1 || n % 2 == 0 || n % 3 == 0) return false;

    vector<ll> bases = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    ll d = n - 1, s = 0;
    while (d % 2 == 0) {
        d >>= 1; s++;
    }

    for (const ll& a : bases) {
        if (a % n == 0) continue;

        ll x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1) continue;

        bool comp = true;
        for (int i=0; i<s-1; ++i) {
            x = mod_mul(x, x, n);
            if (x == n - 1) {
                comp = false;
                break;
            }
        }
        if (comp) return false;
    }
    return true;
}


// Finding divisors of a number
vector<ll> divs(ll n) {
    vector<ll> d;
    for (ll i=2; i*i<=n; ++i) {
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i) d.push_back(n / i);
        }
    }
    return d;
}


// Sum of digits of a number
int s(ll n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}


// Factorization
vector<ll> fact(ll n) {
    vector<ll> d;
    for (ll p=2; n>1; p++) {
        if (p*p > n) p = n;
        while (n % p == 0) {
            d.push_back(p);
            n /= p;
        }
    }
    return d;
}
