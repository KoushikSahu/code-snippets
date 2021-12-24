#include <bits/stdc++.h>
using namespace std;

//-----------------<copy>-------------------
template <typename T>
class SegmentTree {
	public:
    SegmentTree(int len, T* arr, function<T(T, T)> func, T init) : n(len), fn(func), init(init) {
      st.resize(2*len);
      for(int i=len; i<2*len; i++) st[i] = arr[i-len];
      build();
    }

    SegmentTree(int len, vector<T> arr, function<T(T, T)> func, T init) : n(len), fn(func), init(init) {
      st.resize(2*len);
      for(int i=len; i<2*len; i++) st[i] = arr[i-len];
      build();
    }

    void update(size_t idx, T val){
      for(st[idx+=n]=val; idx>1; idx>>=1) st[idx>>1] = fn(st[idx], st[idx^1]);
    }

    T query(size_t l, size_t r){
      r++;
      T res = init;
      for(l+=n, r+=n; l<r; l>>=1, r>>=1){
        if(l&1) res = fn(res, st[l++]);
        if(r&1) res = fn(res, st[--r]);
      }
      return res;
    }

  private:
    size_t n;
    T init;
    vector<T> st;
    function<T(T, T)> fn;

    void build(){
      for(int i=n-1; i>0; i--) st[i] = fn(st[i<<1], st[(i<<1)|1]);
    }

};
//-----------------</copy>-------------------

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
	double a[6] = {2.16, 3.14, 2.0, 7.68, 1.55, 6.1};
	auto f = [](double p, double q){return p+q;};
	SegmentTree<double> st(6, a, f, 0);
	cout<<st.query(1, 3)<<"\n";
	st.update(3, 0);
	cout<<st.query(1, 3)<<"\n";
  return 0;
}

