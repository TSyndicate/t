#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

void find(vector<int>& a, int& minn, int& maxx, int&summ, float& avgg){
    #pragma omp parallel for reduction(min:maxx) reduction(max:maxx) reduction(+:summ)
    for(int i=1;i<a.size();i++){
        minn = min(minn,a[i]);
        maxx = max(maxx,a[i]);
        summ += a[i];
    }
    avgg = (float)summ/a.size();
}

int main() {
    vector<int> a;
    a = {0,1,2,3,4,5,6,7,8,9};
    int minn = a[0], maxx = a[0], summ = a[0];
    float avgg;
    find(a,minn,maxx,summ,avgg);
    cout<<minn<<endl;
    cout<<maxx<<endl;
    cout<<summ<<endl;
    cout<<avgg<<endl;
    return 0;
}
