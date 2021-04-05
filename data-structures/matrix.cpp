#include <bits/stdc++.h>
using namespace std;

// ----------------- <copy> ---------------
template <typename T>
class Row{
    public:
        Row(){ }
        
        Row(int len) : n(len){
            assert(len>0);
            a = new int[len];
            for(int i=0; i<len; i++) a[i] = 0;
        }

        T& operator[](int idx){
            assert(idx>=0 && idx<n);
            return a[idx];
        }
        
    private:
        T* a;
        int n;

};

template <typename T>
class Matrix{
    public:
        int n, m;

        Matrix(int row, int col, bool identity=false) : n(row), m(col){
            if(identity) assert(row == col);
            a = new Row<T>[row];
            for(int i=0; i<row; i++) a[i] = Row<T>(col);
            if(identity) for(int i=0; i<row; i++) a[i][i] = 1;
        }

        Row<T>& operator[](int idx){
            return a[idx];
        }

        Matrix operator*(Matrix b){
            assert(m == b.n);
            Matrix<T> product(n, b.m);
            for(int i=0; i<n; i++){
                for(int j=0; j<b.m; j++){
                    for(int k=0; k<m; k++){
                        product[i][j] += (a[i][k]*b[k][j]);
                    }
                }
            }
            return product;
        }

        void show(){
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    cout<<a[i][j]<<" ";
                }
                cout<<"\n";
            }
        }

    private:
        Row<T>* a;

};
//------------------ </copy> ------------------

int main(){
    Matrix<int> m(3, 3, true), mm(3, 3, false);
    m.show();
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            mm[i][j] = i+j;
        }
    }
    mm.show();
    Matrix<int> ans = m*mm;
    ans.show();
	return 0;
}

