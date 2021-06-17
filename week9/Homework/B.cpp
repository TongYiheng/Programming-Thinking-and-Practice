#include <bits/stdc++.h>
using namespace std;

#define pn (cout<<"N\n")
#define py (cout<<"Y\n")


struct file {
    int file_type;
    long long file_size;
    long long all_max,son_max;
    long long all_used,son_used;
    map<string,file*> ch;

    file(int type,long long size=0)
        :file_type(type),file_size(size),all_max(0),son_max(0),all_used(0),son_used(0) {}
    ~file() {
        for(auto &it:ch) delete it.second;
    }
    bool pre_add_size(long long size,bool last=false) {
        if(all_max && all_used+size > all_max) return false;
        if(last && son_max && son_used+size > son_max) return false;
        return true ;
    }
    void add_size(long long size,bool last=false) {
        if(last) son_used+=size;
        all_used+=size;
    }
    long long get_size() {
        if(file_type==0) return file_size;
        return all_used;
    }
    bool set_size(long long all,long long son) {
        if((all && all_used>all) || (son && son_used>son)) return false;
        all_max=all,son_max=son;
        return true;
    }
};

struct fileSystem {
    file *root;
    vector<string> path;
    string filename;
    fileSystem() {
        root=new file(1);
    }
    ~fileSystem() {
        delete root;
    }

    void setPath(string &pa) {
        path.clear();
        string tmp;
        for(auto c:pa) {
            if(c=='/') {
                if(!tmp.empty()) path.emplace_back(tmp),tmp.clear();
            }
            else tmp+=c;
        }
        filename=tmp;
    }
    pair<file*,int> find() {
        file *now=root;
        for(auto &np:path) {
            if(!now->ch.count(np)) return make_pair(nullptr,1);             //路径不完整
            if(now->ch[np]->file_type == 0) return make_pair(nullptr,0);    //路径错误
            now=now->ch[np];
        }
        if(!filename.empty()) {
            if(!now->ch.count(filename)) return make_pair(nullptr,1);
            now=now->ch[filename];
        }
        return make_pair(now,2);                                               //成功找到
    }
    bool create(long long size) {
        file *now=root;
        for(auto &np:path) {
            if(!now->pre_add_size(size)) return false;
            if(!now->ch.count(np)) now->ch[np]=new file(1);     //尝试创建目录
            now=now->ch[np];
        }
        if(!now->pre_add_size(size,true)) return false;     //最后一层

        now=root;
        for(auto &np:path) {
            now->add_size(size);
            now=now->ch[np];
        }
        now->add_size(size,true);
        now->ch[filename]=new file(0,size);
        return true;
    }
    void remove(long long size) {
        file *now=root;
        for(auto &np:path) {
            now->add_size(-size);
            now=now->ch[np];
        }
        if(now->ch[filename]->file_type==1) {
            now->add_size(-size);
        }
        else {
            now->add_size(-size,true);
        }
        delete now->ch[filename];
        now->ch.erase(filename);
    }
}fs;



int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s,path;
    for(int i=0;i<n;i++) {
        cin>>s>>path;
        fs.setPath(path);
        auto ret=fs.find();
        if(s=="C") {
            long long filesize;
            cin>>filesize;
            if(ret.second==2) {
                if(ret.first->file_type==1) pn;
                else {
                    long long old_size=ret.first->get_size();
                    fs.remove(old_size);
                    if(fs.create(filesize)) py;
                    else {
                        fs.create(old_size);
                        pn;
                    }
                }
            }
            else if(ret.second==1) {
                if(fs.create(filesize)) py;
                else pn;
            }
            else {
                pn;
            }
        }
        else if(s=="R") {
            if(ret.second==2) {
                fs.remove(ret.first->get_size());
            }
            py;
        }
        else if(s=="Q") {
            long long all_max,son_max;
            cin>>son_max>>all_max;
            if(ret.second==2 && ret.first->file_type==1) {
                if(ret.first->set_size(all_max,son_max)) py;
                else pn;
            }
            else pn;
        }
    }


    return 0;
}