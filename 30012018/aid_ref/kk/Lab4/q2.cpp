#include <bits/stdc++.h>

using namespace std;

string s;
int loc;
vector<pair<int,int> > res;
map<string,int> mark;
map<string,int> flag;

void init(){
        mark["begin"]=1;
        mark["end"]=2;
        mark["if"]=3;
        mark["else"]=4;
        mark["then"]=5;
        mark["=="]=8;
        mark["!="]=8;
        mark[">="]=8;
        mark["<="]=8;
        mark["<"]=8;
        mark[">"]=8;
        mark["="]=8;
        mark["+"]=8;
        mark["-"]=8;
}

void chk(string a){
        if(mark.find(a)==mark.end()){
                int ok=1;
                for(int i=0;i<a.length();i++){
                        if(a[i]>='0' and a[i]<='9');
                        else{
                                ok=0;
                                break;
                        }
                }
                if(ok){
                        if(flag.find(a)==flag.end()){
                                flag[a]=loc++;
                        }
                        res.push_back(make_pair(7,flag[a]));
                }
                else{
                        if(flag.find(a)==flag.end()){
                                flag[a]=loc++;
                        }
                        res.push_back(make_pair(6,flag[a]));
                }
        }else{
                res.push_back(make_pair(mark[a],loc++));
        }
}

void parse(){
        int n=s.length();
        string a="";
        for(int i=0;i<n;i++){
                if(s[i]==' '){
                        chk(a);
                        a="";
                }else{
                        a+=s[i];
                }
        }
        chk(a);
}

int main(){
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
        init();
        getline(cin,s);
        parse();
        cout<<"Code Value\n";
        for(int i=0;i<(int)res.size();i++){
                cout<<res[i+1].first<<" "<<res[i+1].second<<"\n";
        }
        return 0;
}
