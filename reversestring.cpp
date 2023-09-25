#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include<vector>
using namespace std;
int main()
{
    string s = "hello world";
    vector<string>v;
    string ans="";
    int i=0;
    while(i<s.size())
    {
        if(s[i]!=' ')
        {
            while(i<s.size()&&s[i]!=' ')
            {
            ans.push_back(s[i]);
            i++;
            }
        }
        else
        {
            while(i<s.size()&&s[i]==' ')
            {
                i++;
            }
        }
        if(ans.length()!=0)
        {
            v.push_back(ans);
            ans="";
        }
    }

   for(int i=v.size()-1;i>=0;i--)
   {
       ans+=v[i];
       if(i!=0)
       {
           ans+=" ";
       }
   }
   for(int i=0;i<ans.size();i++)
   {
       cout<<ans[i];
   }
    return 0;
}