#include <bits/stdc++.h>
using namespace std;

// warning: doesn't throw error when types that can
// be converted to int are passed into is_prime

// time complexity
// buildSieve(): O(n*log(log(n))
// is_prime: O(1)
// prime_factor: O(log(n))

// ------------------- <copy> ---------------------
class Sieve{
    public:
        Sieve(){
            buildSieve();
        }

        bool is_prime(int num){
            assert(num>=0);
            if(num<2) throw invalid_argument("Neither prime nor composite!");
            return s[num] == 0;
        }

        // returns in descending order
        vector<int> prime_factor(int num){
            assert(num>=0);
            if(num<2) return {num};
            vector<int> pf;
            while(s[num]!=0){
                pf.push_back(s[num]);
                num /= s[num];
            }
            pf.push_back(num);
            return pf;
        }

    private:
        static const int nxM = 1e6+5;
        int s[nxM];

        void buildSieve(){
            fill_n(s, nxM, 0);
            for(int i=2; i*i<nxM; i++){
                if(s[i] == 0){
                    for(int j=i*i; j<nxM; j+=i){
                        s[j] = i;
                    }
                }
            }
        }

};
// ------------------- </copy> ---------------------

int main(){
    // usage
    Sieve s;
    // unit tests
    cout<<s.is_prime(7)<<"\n";
    //cout<<s.is_prime(0)<<"\n"; //must throw invalid argument error
    cout<<s.is_prime(18)<<"\n";
    //cout<<s.is_prime(7.8)<<"\n"; //works but it shouldn't
    for(int i: s.prime_factor(48)) cout<<i<<"\n";
    return 0;
}

