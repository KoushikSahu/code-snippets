#include <bits/stdc++.h>
using namespace std;

// Space complexity: O(N)
// Time complexity: Almost O(1) for each operation (Amortized complexity)
// Path compression and union by size implemented

//---------------<copy>---------------
const int nxM = 1e6+1;
array<int, nxM> dsu;

int findSet(int v){
    if(dsu[v]<0) return v;
    return dsu[v] = findSet(dsu[v]);
}

bool unionSet(int v1, int v2){
    int p1 = findSet(v1);
    int p2 = findSet(v2);
    if(p1==p2) return false;
    else{
        if(abs(p1)>=abs(p2)){
            dsu[p1] += dsu[p2];
            dsu[p2] = p1;
        }else{
            dsu[p2] += dsu[p1];
            dsu[p1] = p2;
        }
    }
    return true;
}
//---------------</cop>---------------

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    //--------------<copy>---------------
    dsu.fill(-1);
    //--------------</copy>--------------
    return 0;
}
