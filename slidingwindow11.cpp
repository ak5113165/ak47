#include<bits/stdc++.h>
using namespace std;
//count sustring or subarray with exactly k distinct character
int atmostK(string A,int n,int k){
    int count = 0;
    int left = 0;
    int right = 0;
    
    unordered_map<char,int> mp;
    
    while(right < n){
        
        //add current element in the map
         mp[A[right]]++;
        
        
        while(mp.size() > k){
            mp[A[left]]--;
            if(mp[A[left]] == 0){
                mp.erase(A[left]);
            }
            left++;
        }
        
        count += right-left+1;
        right++;
    }
        return count;
    }
int main()
{
    string arr="abcabdabbcfa";
    int k=3;
    int n=arr.size();
    cout<<atmostK(arr,n,k)<<" "<<atmostK(arr,n,k-1);
    return 0;
}