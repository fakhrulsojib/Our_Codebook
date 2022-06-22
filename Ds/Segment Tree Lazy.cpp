template<class T>
struct segtree
{
	int n;
	vector<T> tree;
	vector<T> lazy;
	vector<T> a;
	segtree(int len)
	{
		tree.resize(4 * len, 0);
		lazy.resize(4 * len, 0);
		n = len;
	}
	segtree(vector<int> z)
	{
		a = z;
		n = a.size();
		tree.resize(4 * n, 0);
		lazy.resize(4 * n, 0);
	}
	// change combine and push function
	T combine(T x, T y)
	{
		return x + y;
	}
	void push(int at, int l, int r)
	{
		if (lazy[at] == 0) return;
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
	void Build(){ build(1, 0, n - 1); } // Use this 

	void update(int at, int l, int r, int L, int R, int val)
    {
        push(at, l, r);
        if (r < L || R < l) return;
        if (L <= l && r <= R)
        {
            lazy[at] = val;
            push(at,l,r);
            return;
        }
        int m = (l + r) >> 1;
        update(at << 1, l, m, L, R, val);
        update(at << 1 | 1, m + 1, r, L, R, val);
        tree[at] = combine(tree[at << 1], tree[at << 1 | 1]);
    }
    void Update(int l, int r, int val) { update(1, 0, n - 1, l, r, val); } // Use this

    T quer(int at, int l, int r, int L, int R)
    {
        push(at, l, r);
        if (L <= l && r <= R) return tree[at];
        int m = (l + r) >> 1;
        if (R <= m) return quer(at << 1, l, m, L, R);
        if (m < L) return quer(at << 1 | 1, m + 1, r, L, R); 
        return combine(quer(at << 1, l, m, L, R), quer(at << 1 | 1, m + 1, r, L, R));
    }
    T Quer(int l, int r) { return quer(1, 0, n - 1, l, r); } // Use this
};
