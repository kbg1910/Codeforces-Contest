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

const int N = 2e5 + 1;

vector< vector<int> > adj(N);
vector< vector<int> > adj1(N);
vector< int> order;

void topological(int n)
{
        set<int> s;
        
        vector<int> indeg(n + 1, 0);
        
	for(int i = 1; i <= n; i++)
		for(auto &it : adj[i])
			indeg[it]++;
        
	for(int i = 1; i <= n; i++)
	{
		if(!indeg[i])
			s.insert(i);
	}
        
	while(s.size())
	{
		int u = *s.begin();
		s.erase(s.begin());
		order.push_back(u);
		for(auto &v:adj[u])
		{
			indeg[v]--;
			if(!indeg[v])
				s.insert(v);
		}
	}
}

void solve() {
        int n;
        
        cin >> n;
        
        for(int i = 0; i <= n; ++i)
        {
                adj[i].clear();
                adj1[i].clear();
        }
        
        order.clear();
        
        for(int i = 0; i < n; ++i)
        {
                int k;
                
                cin >> k;
                
                for(int j = 0; j < k; ++j)
                {
                        int x;
                        
                        cin >> x;
                        
                        adj[x].pb(i + 1);
                        adj1[i + 1].pb(x);
                }
        }
        
        topological(n);
        
        if(order.size() != n)
        {
                cout << -1 << endl;
                return;
        }
        
        vector<int> dp(n + 1 , 0);
        int res = 0;
        
        for(auto u : order)
        {
                int mi1 = 0;
                int mi2 = 0;
                
                for(auto v : adj1[u])
                {
                        if(v < u)       dp[u] = max(dp[u] , dp[v]);
                        else            dp[u] = max(dp[u] , dp[v] + 1);
                }
                
                if(dp[u] == 0)  dp[u] = 1;
                
                res = max(res , dp[u]);
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