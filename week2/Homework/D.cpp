#include <bits/stdc++.h>
using namespace std;


int main()
{
    int m,op;
    string s;
    map<string,bool> note;

    cin>>m;
    while(m--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>s;
            auto it=note.find(s);
            if(it!=note.end())
                cout<<"found"<<endl;
            else
            {
                note.insert(make_pair(s,true));
                cout<<"write"<<endl;
            }
        }
        else if(op==2)
        {
            cin>>s;
            auto it=note.find(s);
            if(it!=note.end())
            {
                note.erase(it);
                cout<<"erased"<<endl;
            }
            else
            {
                cout<<"not found"<<endl;
            }
        }
        else
        {
            for(auto &x:note)
                cout<<x.first<<" ";
            cout<<endl;
        }
    }

    return 0;
}