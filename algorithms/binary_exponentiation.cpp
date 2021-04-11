#include <bits/stdc++.h>
using namespace std;

//-------------------------<copy>-----------------------
template <typename T>
T pow_binexpo(T x, int y){
    T ans = 1; 
    while(y){
        if(y%2) ans *= x;
        x *= x;
        y /= 2;
    }
    return ans;
}

template <typename T>
T pow_matexpo(T x, int y){
    assert(x.n == x.m);
    T ans = T(x.n, x.m, true);
    while(y){
        if(y%2) ans = ans*x;
        x = x*x;
        y /= 2;
    }
    return ans;
}
//-------------------------</copy>-----------------------

int main(){

    return 0;
}

