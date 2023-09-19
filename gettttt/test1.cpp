#include <bits/stdc++.h>
#include<vector>

#define ll long long
#include<string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    ll sum = (n*(n+1))/2;
    if(sum%2!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    ll left = sum/2;
    vector<int> v1;
    int i =1;
    while(left>0){
        if(left<=n){
            v1.push_back(n);
            --n;
            break;
        }
        v1.push_back(n);
        left = left-n;
        if(left>0){
        v1.push_back(i);
        left = left-i;
        i++;n--;
        } 
    }

    vector<int> v2;
    while(i<=n){
        v2.push_back(i);
        i++;
    }
    
    cout<<v1.size()<<endl;
    for(int i:v1){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<v2.size()<<endl;
    for(int i:v2){
        cout<<i<<" ";
    }
    

   
    return 0;
}