#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct SparseTable {
    vector<int> t, logg;
    int n;
    
    SparseTable(vector<int>& a) {

    }
};


struct SegTreeDOWN {
    vector<ll> t;
    int n;

    SegTreeDOWN(vector<int>& a) {
        for (n=1; n<=a.size(); n<<=1);
        t.resize(2*n);
        for (int i=0; i<a.size(); i++) t[i] = a[i];
        for (int i=n-1; i>=0; i--) t[i] = t[2*i] + t[2*i+1];
    }

    void upd(int i, int x) {
        t[i+=n] = x;
        for (i>>=1; i>=0; i>>=1) t[i] = t[2*i] + t[2*i+1];
    }

    ll rsq(int l, int r) {
        ll res = 0;
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if (l % 2 == 1) res += t[l++];
            if (r % 2 == 0) res += t[r--];
        }
        return res;
    }
};


struct SegTreeUP {
    vector<ll> t;
    int n;

    SegTreeUP(vector<int>& a) {

    }

    void upd(int i, int x) {

    }

    ll rsq(int l, int r) {

    }
};


struct Fenwick {
    vector<ll> t;
    int n;

    Fenwick(vector<int>& a) {
        n = a.size(); t.resize(n);
        for (int i=0; i<n; i++) upd(i, a[i]);
    }

    void upd(int i, int x) {
        for (; i<n; i=i|(i+1)) t[i] += (ll)x;
    }

    ll rsq(int r) {
        ll res = 0;
        for (int i; i>=0; i=i&(i+1)-1) res += t[i];
        return res;
    }

    ll rsq(int l, int r) {
        return l ? rsq(r) - rsq(l-1) : rsq(r);
    }
};
