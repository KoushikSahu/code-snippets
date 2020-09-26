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

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
    
/*
    Author: Koushik Sahu
    Created: 26 Sep 2020 13:42:26
*/

// finds nCr modulo p where p is prime *******p must be prime*********
// Precomputation time complexity: O(N)
// Query time complexity: O(1)
// Constrainst: n<=1e6 r<=1e6

//-----------------<copy>------------------
const int N=1e6+1;

array<ll, N> factorial, inverse, factorial_inverse;

void precomputeInverse(ll p=MOD){
    inverse[0] = inverse[1] = 1;
    for(int i=2; i<N; i++) inverse[i] = inverse[p%i]*(p - p/i)%p;
}

void precomputeFactorialInverse(ll p=MOD){
    factorial_inverse[0] = factorial_inverse[1] = 1;
    for(int i=2; i<N; i++) factorial_inverse[i] = (factorial_inverse[i-1]*inverse[i])%p;
}

void precomputeFactorial(ll p=MOD){
    factorial[0] = 1;
    for(int i=1; i<N; i++) factorial[i] = (i*factorial[i-1])%p; 
}

ll nCr(ll n, ll r, ll p=MOD){
    if(r>n) return 0;
    ll ans = (((factorial[n]*factorial_inverse[r])%p)*factorial_inverse[n-r])%p;
    return ans;
}
//-----------------</copy>-----------------

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    //-----------------<copy>----------------
    precomputeInverse();
    precomputeFactorialInverse();
    precomputeFactorial();
    //-----------------</copy>---------------
    
    // to get nCr -----> nCr(n, r) or nCr(n, r, p) *******p must be prime**********

    // tests:-
    // cout<<nCr(4, 0)<<"\n";
    // cout<<nCr(4, 1)<<"\n";
    // cout<<nCr(4, 2)<<"\n";
    // cout<<nCr(4, 3)<<"\n";
    // cout<<nCr(4, 4)<<"\n";
    // cout<<nCr(4, 5)<<"\n";
    return 0;
}