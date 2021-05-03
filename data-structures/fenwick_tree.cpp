#include <bits/stdc++.h>
using namespace std;

template <typename T>
class FenwickTree {
	public:
		FenwickTree
		(int size, T* array, function<T(T, T)> func, int default_val) : len(size), fn(func), d(default_val) {
			build(array);
		}

		T query(int idx){
			T ans = d;
			for(int i=idx+1; i>0; i=get_parent(i)){
				ans = fn(ans, bit[i]);
			}
			return ans;
		}

		T query(int left_idx, int right_idx, function<T(T, T)> func){
			return func(query(right_idx), query(left_idx-1));
		}

	private:
		T *bit, d;
		int bit_len, len;
		function<T(T, T)> fn;

		int get_parent(int idx){
			return idx - (idx & -idx);
		}

		int get_next(int idx){
			return idx + (idx & -idx);
		}

		void build(T* a){
			bit_len = len+1;
			bit = new T[bit_len];
			fill_n(bit, bit_len, d);
			for(int i=0; i<len; i++){
				for(int j=i+1; j<bit_len; j=get_next(j)){
					bit[j] = fn(bit[j], a[i]);
				}
			}
		}
};

int main(){
	double a[] = {4.69, 3.80, 1.91, 11.37, 5.5};
	int n = 5;
	auto add = [&](double p, double q){return p+q;};
	auto sub = [&](double p, double q){return p-q;};
	FenwickTree<double> ft(n, a, add, 0);
	cout<<ft.query(2)<<"\n";
	cout<<ft.query(1, 3, sub)<<"\n";
    return 0;
}

