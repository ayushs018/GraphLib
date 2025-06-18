#pragma once
#define ll long long
#include <bits/stdc++.h>
using namespace std;

namespace graphlib::utils {

const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

vector<ll> fact(MAXN), invfact(MAXN);

// Binary exponentiation: a^b % mod
ll binexp(ll a, ll b, ll mod = MOD) {
    a %= mod;
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Modular inverse using Fermat's little theorem
ll modinv(ll a, ll mod = MOD) {
    return binexp(a, mod - 2, mod);
}

// Precompute factorials and inverse factorials
void precompute_factorials(ll mod = MOD) {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = modinv(fact[i], mod);
    }
}

// nCr % mod
ll nCr(int n, int r, ll mod = MOD) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}

// nPr % mod
ll nPr(int n, int r, ll mod = MOD) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[n - r] % mod;
}

// N-th Fibonacci using matrix exponentiation
ll nth_fib(ll n, ll mod = MOD) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    array<array<ll, 2>, 2> res = {{{1, 0}, {0, 1}}};
    array<array<ll, 2>, 2> fib = {{{1, 1}, {1, 0}}};

    while (n > 0) {
        if (n & 1) {
            array<array<ll, 2>, 2> tmp = {{{0, 0}, {0, 0}}};
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    for (int k = 0; k < 2; k++)
                        tmp[i][j] = (tmp[i][j] + res[i][k] * fib[k][j]) % mod;
            res = tmp;
        }

        array<array<ll, 2>, 2> tmp = {{{0, 0}, {0, 0}}};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    tmp[i][j] = (tmp[i][j] + fib[i][k] * fib[k][j]) % mod;
        fib = tmp;
        n >>= 1;
    }

    return res[0][1];
}


vector<bool> is_prime;
vector<int> primes;
void sieve(int n = 1e6) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
        if (is_prime[i])
            primes.push_back(i);
}

// Modular inverse for all numbers [1...n]
vector<ll> modinv_arr;
void precompute_modinv_array(int n = 1e6, ll mod = MOD) {
    modinv_arr.resize(n + 1);
    modinv_arr[1] = 1;
    for (int i = 2; i <= n; ++i)
        modinv_arr[i] = mod - mod / i * modinv_arr[mod % i] % mod;
}


// Matrix Exponentiation (2x2 matrix)
struct Matrix {
    ll m[2][2];
    Matrix(ll a = 1, ll b = 0, ll c = 0, ll d = 1) {
        m[0][0] = a; m[0][1] = b;
        m[1][0] = c; m[1][1] = d;
    }

    Matrix operator*(const Matrix &o) const {
        Matrix res(0, 0, 0, 0);
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    res.m[i][j] = (res.m[i][j] + m[i][k] * o.m[k][j]) % MOD;
        return res;
    }
};

Matrix mat_pow(Matrix base, ll exp) {
    Matrix res; // identity
    while (exp > 0) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

// nth Fibonacci using Matrix Expo
ll fib_matrix(ll n) {
    if (n == 0) return 0;
    Matrix F(1, 1, 1, 0);
    return mat_pow(F, n - 1).m[0][0];
}


// SPF (Smallest Prime Factor) for factorization in O(log n)
vector<int> spf;
void compute_spf(int N = 1e6) {
    spf.resize(N + 1);
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i <= N; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> get_prime_factors(int n) {
    vector<int> factors;
    while (n != 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}


} 
