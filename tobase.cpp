#include<bits/stdc++.h>
using namespace std;
string to_base(long long num,int k)
{
  string res="";
  while(num!=0)
  {
      res+=(char)((num)%k+'0');
      num=num/k;
  }
  return res;
}
bool chekpall(int num)
{
    long long rev=0;
    long long dupnum=num;
    while(num!=0)
    {
        rev=(rev*10)+(num%10);
        num=num/10;
    }
    return rev==dupnum;
}
bool ispal(string s)
{
    // s.insert(1,"");
    int i=0;
    int j=s.size()-1;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    string res=to_base(15,2);
    cout<<ispal(res);
    cout<<endl;
    cout<<chekpall(91);
    return 0;
}