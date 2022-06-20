#include <bits/stdc++.h>
using namespace std;
template<class T>
struct segtree
{
	int n;
	vector<T> tree;
	vector<T> lazy;
	vector<T> a;
	segtree(int len)
	{
		a.resize(len);
		tree.resize(4 * len);
		lazy.resize(4 * len);
		n = len;
	}
	// change combine and push function
	T combine(T x, T y)
	{
		return x + y;
	}
	void push(int at, int l, int r)
	{
		tree[at] += lazy[at] * (r - l + 1);
		if (l != r) lazy[at << 1] += lazy[at];
		if (l != r) lazy[at << 1 | 1] += lazy[at];
		lazy[at] = 0;
	}
	void build(int at, int l, int r)
	{
		if (l == r)
		{
			tree[at] = a[l];
			return ;
		}
		int m = (l + r) >> 1;
		build(at << 1, l, m);
		build(at << 1 | 1, m + 1, r);
		tree[at] = combine(tree[at << 1], tree[at << 1 | 1]);
	}
	void update(int at, int l, int r, int L, int R, int val)
    {
        push(at, l, r);
        if (r < L || R < l) return;
        if (L <= l && r <= R)
        {
            tree[at] = val;
            push(at,l,r);
            return;
        }
        int m = (l + r) >> 1;
        update(at << 1, l, m, L, R, val);
        update(at << 1 | 1, m + 1, r, L, R, val);
        tree[at] = combine(tree[at << 1], tree[at << 1 | 1]);
    }
    T quer(int at,int l,int r,int L,int R) // query function not done..........
    {
        push(at,l,r);
        if(r<L || R<l) return 0;    //    ............not done.......
        if(L<=l && r<=R) return tree[at];
        int m=(l+r)>>1;
        return combine(quer(at<<1,l,m,L,R),quer(at<<1|1,m+1,r,L,R));
    }
};
int main()
{

	return 0;
}
