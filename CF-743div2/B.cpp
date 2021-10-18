#include<bits/stdc++.h>

using namespace std;
using   ll = long long;
using   ld = long double;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define pb                  push_back
#define type                make_pair
#define F                   first
#define S                   second
#define int                 long long int
#define endl                "\n"

#define ALL(v)              v.begin(),v.end()
#define ALLR(v)             v.rbegin(),v.rend()
#define pii                 3.14159265358979323
#define inf                 LLONG_MAX
#define ones(x)             __builtin_popcount(x)
#define fill(a,b)           memset(a,b,sizeof(a))
#define mod1                1000000007
#define mod2                998244353

ll mod_pow(ll a,ll b,ll m)
{
    ll res = 1;
    while(b)
    {
        if(b&1)
        {
                res=(res*a) % m;
        }
        a=(a*a) % m;
        b>>=1;
    }
    return res;
}

ll mod_inverse(int a , int m)
{
        return mod_pow(a , m - 2 , m);
}

void solve() {
        int n;
        
        cin >> n;
        
        map<int , int> odd , even;
        
        int a[n];
        int b[n];
        
        for(int i = 0; i < n; ++i)
        {
                cin >> a[i];
                odd[ a[i] ] = i;
        }
        
        for(int i = 0; i < n; ++i)
        {
                cin >> b[i];
                even[ b[i] ] = i;
        }
        
        int mi = odd[1];
        int res = inf;
        
        for(int i = 2; i <= 2 * n; i += 2)
        {
                res = min(res , even[i] + mi);
                mi = min(mi , odd[i + 1]);
        }
        
        cout << res << endl;
}

signed main() {
        fast;
   
        int t = 1;
        
        cin >> t;

        while(t--) {
                solve();
        }
        
        return 0;
}