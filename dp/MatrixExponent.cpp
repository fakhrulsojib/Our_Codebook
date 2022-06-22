const int mod = 1e9 + 7;
int add(int x,int y) {	return (x+y)%mod;  		}
int mul(int x,int y) {	return (x*1ll*y)%mod;	}
vector<vector<int> >  matmal(vector<vector<int> > a,vector<vector<int> > b)
{
    int r1=a.size(),c1=a[0].size(),r2=b.size(),c2=b[0].size();
    assert(c1==r2);
    vector<vector<int> > ret(r1,vector<int> (c2,0));
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            for(int k=0;k<c1;k++)
            {
                ret[i][j]=add(ret[i][j],mul(a[i][k],b[k][j]));
            }
        }
    }
    return ret;
}
vector<vector<int> > identity(int n)
{
    vector<vector<int> > ret(n,vector<int>(n,0));
    for(int i=0;i<n;i++) ret[i][i]=1;
    return ret;
}
vector<vector<int> >  bigpow(vector<vector<int> > a,int b)
{
    if(b==0) return identity(a.size());
    auto ret=bigpow(a,b>>1);
    ret=matmal(ret,ret);
    if(b&1) ret=matmal(ret,a);
    return ret;
}
