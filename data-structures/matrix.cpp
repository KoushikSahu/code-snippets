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

// ----------------- <copy> ---------------
// constructor takes in number of row, columns and if the matrix is identity matrix
struct Matrix{
    int n, m, a[101][101];

    Matrix(int n, int m, bool identity=false) : n(n), m(m){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a[i][j] = 0;
            }
        }
        if(identity){
            for(int i=0; i<n; i++) a[i][i] = 1;
        }
    }

    Matrix operator*(Matrix b){
        Matrix product(n, b.m);
        assert(m==b.n);
        for(int i=0; i<n; i++){
            for(int j=0; j<b.m; j++){
                for(int k=0; k<m; k++){
                    product.a[i][j] += (a[i][k]*b.a[k][j]);
                }
            }
        }
        return product;
    }
};
//------------------ </copy> ------------------

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	return 0;
}

