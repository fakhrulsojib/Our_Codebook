These are to be checked again:
1. sos dp
2. fastio
3. LCS (Faster)
4. MO



#include <bits/stdc++.h>
#include <string>
typedef long long int ll;
typedef unsigned long long int ull;
#define scn1(a)         scanf("%d", &a);
#define scn2(a, b)      scanf("%d %d", &a, &b);
#define scn3(a, b, c)   scanf("%d %d %d", &a, &b, &c);
#define lscn1(a)        scanf("%I64d", &a);
#define lscn2(a, b)     scanf("%I64d %I64d", &a, &b);
#define lscn3(a, b, c)  scanf("%lli %lli %lli", &a, &b, &c);
#define prnt(a)         printf("%d\n", a);
#define lprnt(a)        printf("%I64d\n", a);
#define forr(i, a, n)   for(int i=a;i<n;i++)
#define pll             pair<ll, ll>
#define pii             pair<int, int>
#define vi              vector<int>
#define vl              vector<ll>
#define mset(a, b)      memset((a), (b), sizeof(a))
#define PB              push_back
#define all(a)          a.begin(), a.end()
#define F               first
#define S               second
#define enl             cout << "\n";
#define tsttxt          cout << "\nHeyYou!\n";
#define CHK(a)          cout << (#a) << " = " << (a) << endl;
#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MX5             100005
#define MX6             1000006
#define MOD             1000000007
#define MIN             INT_MIN
#define MAX             INT_MAX
#define FI              freopen("input.txt", "r", stdin);
#define FO              freopen("output.txt", "w", stdout);
using namespace std;
void arraychk(int a[],int n) {for(int i=0;i<n;i++)cout<<a[i]<<" ";enl;}
#define LOOPCHK(a, n)   arraychk(a, n);

const int N = 200009;

int n, k, a[N], cnt[MX6];
ll ans[N], sum;

struct qry
{
	int idx, l, r;
} q[N];

bool cmp(qry a, qry b)
{
	ll x=a.l/k, y = b.l/k;
	if(y==x) return a.r<b.r;
	return a.l<b.l;
}

void add(int i)
{
	ll x = cnt[a[i]];
	sum -= x*x*a[i];
	cnt[a[i]]++, x++;
	sum += x*x*a[i];
}

void remove(int i)
{
	ll x = cnt[a[i]];
	sum -= x*x*a[i];
	cnt[a[i]]--, x--;
	sum += x*x*a[i];
}

int main()
{
    // fast;

    ll tt=1;
    // cin >> tt;
    for(int cse=1; cse<=tt; cse++)
    {
    	int m, x, y;
        scn2(n, m);
        sum = 0;
        forr(i, 0, n) scn1(a[i]);

        // memset(cnt, 0, sizeof cnt);

        forr(i, 0, m)
        {
        	scn2(x, y);
        	q[i].l = --x;
        	q[i].r = --y;
        	q[i].idx = i;
        }
        k = 555;
        // if(k*k!=n) k++;

        sort(q, q+m, cmp);

        int L = 0, R = -1;
        forr(i, 0, m)
        {
        	while(L<q[i].l) remove(L++);
        	while(L>q[i].l) add(--L);
        	while(R<q[i].r) add(++R);
        	while(R>q[i].r) remove(R--);
        	ans[q[i].idx] = sum;
        }
        forr(i, 0, m) lprnt(ans[i]);

        // cout << "Case " << cse <<  ": ";
        // cout << ans << endl;
    }
    return 0;
}
