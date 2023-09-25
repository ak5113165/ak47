#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;
bool issubset(int arr1[],int n,int arr2[],int m)
{
    unordered_set<int> hash;
    for(int i=0;i<n;i++)
    {
      hash.insert(arr1[i]);
    }
    for(int i=0;i<m;i++)
    {
        if(hash.find(arr2[i])==hash.end())
        {
            return false;
        }
    }
    return true;
}
vector<int>removedup(int*a,int size)
{
    vector<int> w;
    unordered_map<int,bool> seen;
    for(int i=0;i<size;i++)
    {
        if(seen.count(a[i])>0)
        {
            continue;
        }
    seen[a[i]]=1;
    w.push_back(a[i]);
    }
    return w;
}
int main()
{
    int arr1[]={11,1,13,21,3,7};
    int arr2[]={11,3,9,7,1,};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int m=sizeof(arr2)/sizeof(arr2[0]);
    if(issubset(arr1,n,arr2,m))
    {
        cout<<" arr2 is subset of arr1";
    }
    else
    cout<<" arr2 is not subset of arr1";
   /* unordered_map<string,int> p;
    pair<string,int> q("def",2);
    p.insert(q);
    p["abc"]=3;
    cout<<p["def"]; 
    cout<<endl;
    cout<<p["abc"]; 
    cout<<endl;
    cout<<p.size();  
    p.erase("def");
    cout<<endl;
    cout<<p.size();
    p.insert(pair<string,int>("KLM",9));
    p.insert(pair<string,int>("trw",5));
    p.insert(pair<string,int>("opl",8));
    p.insert(pair<string,int>("nmb",7));
    p.insert(pair<string,int>("tas",6));
    if(p.count("abc")>0)
    {
        cout<<"\n ghi is present";
    }
    else
    cout<<"\n not present";
    cout<<p["KLM"];*/
   // unordered_map<string,int>::iterator it;
   /*
    for(it=p.begin();it!=p.end();it++)
    {
        cout<<endl;
        cout<<it->first<<"  "<<it->second;
    }
    unordered_map<string,int>::iterator it2=p.find("abc");
    cout<<endl;
    cout<<it2->first<<"  "<<it2->second;
    cout<<endl<<p.size();
    cout<<endl;
    int a[]={1,2,3,3,2,4,3,6,5,5};
    int n=sizeof(a)/sizeof(a[0]);
    vector<int> output=removedup(a,n);
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }*/
   /* string str="flszye";
    string patt="azcd";
    int min=INT_MAX;
    string c="$";
    unordered_map<char,int> m;
    for(int i=0;i<str.size();i++)
        {
            m[str[i]]=i;
        }
    for(int i=0;i<patt.size();i++)
    {
        if(m.find(patt[i])!=m.end()&&min>m[patt[i]])
        {
           min=m[patt[i]];
        }
    }
    if(min!=INT_MAX)
    {
        cout<<str[min];
        cout<<min;
    }
    else
    cout<<c;*/

    /*for(int i=0;i<str.size();i++)
    {
       cout<<m[str[i]];cout<<endl;
    }*/

}