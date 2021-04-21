#include <bits/stdc++.h>
using namespace std;

//-----------------<copy>-------------------
template <typename T>
class SegmentTree {
	public:
		SegmentTree(int len, T* arr, T (*func)(T, T), T default_val){
			n = len;
			f = func;
			d = default_val;
			a = new T[2*n+5];
			construct_segment_tree(arr, 0, 0, n-1);
		}


		T query(int l, int r, int low, int high, int root){
			if(r<low || l>high) return d; 
			else if(l<=low && r>=high) return a[root];
			int mid = low + (high - low) / 2;
			T left_val = query(l, r, low, mid, 2*root+1);
			T right_val = query(l, r, mid+1, high, 2*root+2);
			return f(left_val, right_val);
		}

		void update(int idx, T new_val, int low, int high, int root){
			assert(idx>=0 && idx<n);
			if(low==high){
				a[root] = new_val;
				return;
			}
			int mid = low + (high - low) / 2;
			if(idx<=mid) update(idx, new_val, low, mid, 2*root+1);
			else update(idx, new_val, mid+1, high, 2*root+2);
			a[root] = f(a[2*root+1], a[2*root+2]);
		}

	private:
		int n;
		T *a, d;
		T (*f)(T, T);

		void construct_segment_tree(T* arr, int root, int low, int high){
			if(low == high){
				a[root] = arr[low];
				return;
			}
			int mid = low + (high - low) / 2;
			construct_segment_tree(arr, 2*root+1, low, mid);
			construct_segment_tree(arr, 2*root+2, mid+1, high);
			a[root] = f(a[2*root+1], a[2*root+2]);
		}

};
//-----------------</copy>-------------------

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
	double a[6] = {2.16, 3.14, 2.0, 7.68, 1.55, 6.1};
	auto f = [](double p, double q){return p+q;};
	SegmentTree<double> st(6, a, f, 0.0);
	cout<<st.query(1, 3, 0, 5, 0)<<"\n";
	st.update(3, 0, 0, 5, 0);
	cout<<st.query(1, 3, 0, 5, 0)<<"\n";
    return 0;
}

