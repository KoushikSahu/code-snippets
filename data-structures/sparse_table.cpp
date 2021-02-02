#include <bits/stdc++.h>
using namespace std;

// Time complexity:
// Building O(Nlog(N))
// Query O(1)
// Space Complexity O(Nlog(N)) ~ O(25*N) 

//-----------------<copy>------------------

template<class T>
class sparse_table{
	public:
		sparse_table(T* arr, size_t length, T (*func)(T, T)){
			n = length;
			f = func;
			for(int i=0; i<n; i++){
				a[i] = arr[i];
			}
			st = new T*[(int)(length+5)];
			for(int i=0; i<(int)(length+5); i++) st[i] = new T[K];
			build();
		}


		T query(int l, int r){
			if(r<l) return 0; // change as per need
			int j = log2(r-l+1);
			return f(st[l][j], st[r-(1<<j)+1][j]);
		}

	private:
		static const int MAXN = 1e6+5, K = 26;
		T a[MAXN];
		T** st;
		int n;
		T (*f)(T, T);

		void build(){
			for(int i=0; i<n; i++) st[i][0] = a[i];
			for(int j=1; j<=K; j++){
				for(int i=0; i+(1<<j)<=n; i++){
					st[i][j] = f(st[i][j-1], st[i+(1<<(j-1))][j-1]);
				}
			}
		}
};

//--------------</copy>---------------

int main(){

	return 0;
}
