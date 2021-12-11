#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

// finds nCr modulo p where p is prime *******p must be prime*********
// Precomputation time complexity: O(N)
// Query time complexity: O(1)
// Constrainst: n<=1e6 r<=1e6

//-----------------<copy>------------------
class Combinatorics{
	public:
		Combinatorics(int mod) : mod(mod) {
			precomputeInverse();
			precomputeFactorialInverse();
			precomputeFactorial();
		}

		ll factorial(int x){
			assert(x<N);
			return fact[x];
		}

		ll inverse_factorial(int x){
			assert(x<N);
			return fact_inverse[x];
		}

		ll nCr(ll n, ll r){
			if(r>n) return 0;
			assert(n<N && r<N);
			ll ans = (((fact[n]*fact_inverse[r])%mod)*fact_inverse[n-r])%mod;
			return ans;
		}

		ll nPr(ll n, ll r){
			if(r>n) return 0;
			assert(n<N && r<N);
			ll ans = (fact[n]*fact_inverse[n-r])%mod;
			return ans;
		}

	private:
		int mod;
		static const int N=1e6+5;
		array<ll, N> fact, inverse, fact_inverse;

		void precomputeInverse(){
			inverse[0] = inverse[1] = 1;
			for(int i=2; i<N; i++) inverse[i] = inverse[mod%i]*(mod - mod/i)%mod;
		}

		void precomputeFactorialInverse(){
			fact_inverse[0] = fact_inverse[1] = 1;
			for(int i=2; i<N; i++) fact_inverse[i] = (fact_inverse[i-1]*inverse[i])%mod;
		}

		void precomputeFactorial(){
			fact[0] = 1;
			for(int i=1; i<N; i++) fact[i] = (i*fact[i-1])%mod; 
		}
};

//-----------------</copy>-----------------

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	Combinatorics c(MOD);
	// tests:-
	cout<<c.nCr(4, 0)<<"\n";
	cout<<c.nPr(4, 1)<<"\n";
	cout<<c.nCr(4, 2)<<"\n";
	cout<<c.nPr(4, 3)<<"\n";
	cout<<c.nCr(4, 4)<<"\n";
	cout<<c.nPr(4, 5)<<"\n";
	cout<<c.factorial(100)<<"\n";
	cout<<c.inverse_factorial(100)<<"\n";
	//cout<<c.nPr(1e7+5, 5)<<"\n";
	return 0;
}
