#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ipair;
typedef pair<ll, ll> llpair;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
    
/*
    Author: Koushik Sahu
    Created: 19 Oct 2020 19:43:52
*/

const int MAXN = 1e6+1, K = 25;
int n, a[MAXN], st[MAXN][K + 1];

// change definition accordingly
int func(int x, int y){
    return min(x, y);
}

void buildSparseTable(){
    for (int i = 0; i < n; i++)
        st[i][0] = a[i]; // change accordingly

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = func(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int slowQuery(int l, int r){
    int ans = INT_MAX; // change accordingly
    for (int j = K; j >= 0; j--) {
        if ((1 << j) <= r - l + 1) {
            ans = func(ans, st[l][j]);
            l += 1 << j;
        }
    }
    return ans;
}

int fastQuery(int l, int r){
    int j = log2(r - l + 1);
    return func(st[l][j], st[r - (1 << j) + 1][j]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    n = 5;
    buildSparseTable();
    cout<<slowQuery(1, 3)<<"\n";
    cout<<fastQuery(1, 3)<<"\n";
    return 0;
}