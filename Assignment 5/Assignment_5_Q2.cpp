#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue <int,vector<int>,greater<int>> minh;
    
    int n;
    cin>>n;
    
    int sizes[n];
    for(int i=0 ; i<n ; i++){
        cin>>sizes[i];
    }

    for(int i=0 ; i<n ; i++){
        minh.push(sizes[i]);
    }

    int cost=0;

    while(minh.size()>=2){
        int file1=minh.top();
        minh.pop();
        int file2=minh.top(); 
        minh.pop();

        cost+=(file1+file2);
        minh.push(file1+file2);
    }

    cout<<"Minimum Cost : "<<cost<<endl;

    return 0;
}