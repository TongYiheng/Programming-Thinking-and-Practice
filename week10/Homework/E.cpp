#include <bits/stdc++.h>
using namespace std;

const int maxn=200010;

#define lch ((x << 1))
#define rch ((x << 1) | 1)
#define m ((l + r) >> 1)
#define tol lch,l,m
#define tor rch,m+1,r

int d[maxn << 2],a[maxn];

void build(int x,int l,int r) {
    if(l==r) {
        d[x]=a[l];
        return ;
    }
    build(tol);
    build(tor);
    d[x]=max(d[lch],d[rch]);
}
int mm,pp,aa;
int p,v;

void upd(int x,int l,int r) {
    if(l==r) {
        d[x]+=v;
        return ;
    }
    if(p<=m) {
        upd(tol);
    }
    else {
        upd(tor);
    }
    d[x]=max(d[lch],d[rch]);
}

int ask(int x,int l,int r,int p1,int p2) {
    if(l==p1 && r==p2) {
        return d[x];
    }
    if(p2<=m) return ask(tol,p1,p2);
    else if(p1>m) return ask(tor,p1,p2);
    else return max(ask(tol,p1,m),ask(tor,m+1,p2));
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>mm>>pp;
    string str;
    for(int i=1;i<=mm;i++) {
        cin>>str;
        if(str=="Q") {
            int L;
            cin>>L;
            aa=ask(1,1,maxn,max(1,p-L+1),p);
            cout<<aa<<"\n";
        }
        else {
            int t;
            cin>>t;
            v=(t+aa)%pp;
            ++p;
            upd(1,1,maxn);
        }
    }



    return 0;
}
