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
    Created: 28 Sep 2020 09:05:09
*/

// Space complexity: O(N)
// Time complexity: Almost O(1) for each operation (Amortized complexity)
// Path compression and union by size implemented

//---------------<copy>---------------
const int nxM = 1e6+1;
array<int, nxM> dsu;

int findSet(int v){
    if(dsu[v]<0) return v;
    return dsu[v] = findSet(dsu[v]);
}

bool unionSet(int v1, int v2){
    int p1 = findSet(v1);
    int p2 = findSet(v2);
    if(p1==p2) return false;
    else{
        if(abs(p1)>=abs(p2)){
            dsu[p1] += dsu[p2];
            dsu[p2] = p1;
        }else{
            dsu[p2] += dsu[p1];
            dsu[p1] = p2;
        }
    }
    return true;
}
//---------------</cop>---------------

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    //--------------<copy>---------------
    dsu.fill(-1);
    //--------------</copy>--------------
    return 0;
}