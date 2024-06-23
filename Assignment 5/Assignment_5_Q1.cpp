#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cout<<"Please enter number of trains : "<<endl;;
    cin>>n;

    priority_queue <int,vector<int>,greater<int>> Arrival[n];
    priority_queue <int,vector<int>,greater<int>> Departure[n];

    for(int i=0;i<n;i++){
        cout<<"Enter train arrival times"<<endl;
        int a;
        cin>>a;
        Arrival->push(a);
    }

    for(int i=0;i<n;i++){
        cout<<"Enter train departure times"<<endl;
        int d;
        cin>>d;
        Departure->push(d);
    }

    int Platform=0;
    int ap=0,dp=0;
    int Max_platform=0;

    while( Arrival->size() >0 && Departure->size()>0){
        if(Arrival->top()<=Departure->top()){
            Platform+=1;
            Arrival->pop();
        }else{
            Platform-=1;
            Departure->pop();
        }
        
        if(Platform>Max_platform){
            Max_platform=Platform;
        }
    }  

    cout<<"Maximum number of platform required are : "<<Max_platform<<endl;

    return 0;
}