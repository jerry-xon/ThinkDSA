#include <bits/stdc++.h>
#include <iterator>
using namespace std;
int main() {
    long long t; cin>>t;
    while(t--) {
        long long n,m; cin>>n>>m; 
        long long *a = new long long[1+n];   a[0] = 0;
        long long maxim = -1;
        set<long long> s;
        for(long long i=1;i<=n;i++) {
            cin>>a[i];
            a[i] = ( a[i-1]+a[i] )%m;
            s.insert(a[i]);
            set<long long> :: iterator it = s.find(a[i]);
            it++;            
            if(it != s.end()) {
                long long val = (m + a[i] - *it)%m;
                maxim = max(val,maxim);
            } 
            else {
                maxim = max(a[i]%m,maxim);
            }
        }
        cout<<maxim<<endl;
    }
}
