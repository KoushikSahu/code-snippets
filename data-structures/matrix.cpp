#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()

// ----------------- <copy> ---------------
template <typename T>
class Row{
    public:
        Row(){ }
        
        Row(int len) : n(len){
            assert(len>0);
            n = len;
            a = new int[len];
            for(int i=0; i<len; i++) a[i] = 0;
        }

        T& operator[](int idx){
            assert(idx>=0 && idx<n);
            return a[idx];
        }

        int size(){
          return n;
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

        int size(){
          return n;
        }

    private:
        Row<T>* a;

};
//------------------ </copy> ------------------

int main(){
    Matrix<int> m(3, 3, true), mm(3, 3, false);
    cout<<"m matrix: \n";
    m.show();
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            mm[i][j] = i+j;
        }
    }
    cout<<"mm matrix: \n";
    mm.show();
    Matrix<int> ans = m*mm;
    cout<<"ans matrix: \n";
    ans.show();
    cout<<"ans size: \n";
    cout<<sz(ans)<<'x'<<sz(ans[0])<<'\n';
    return 0;
}

