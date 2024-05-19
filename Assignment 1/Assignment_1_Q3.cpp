#include<iostream>
using namespace std;



void in_array(int* arr){
    for(int i=0  ; i<10 ; i++){
        cin>>arr[i];
    }
}

float average(int* arr){
    int sum=0;
    for(int i=0 ; i<10 ; i++){
        sum+=arr[i];
    }
    
    float avg=float(sum)/10.0;

    cout << "Average scoe is : "<< avg <<endl;

    return avg;
}

void large_small(int* arr){
    int lar=arr[0];
    int small=arr[0];
    for(int i=0  ; i<10 ; i++){
        if(arr[i]>lar) lar=arr[i];
        if(arr[i]<small) small=arr[i];   
    }
cout<<"Largest score is : "<<lar<<endl;
cout<<"Smallest score is : "<<small<<endl;
}

void count(int* arr , int avg){
    int aavg=0;
    int bavg=0;

    for(int i=0  ; i<10 ; i++){
        if (arr[i]>avg) aavg++;
        if(arr[i]<avg) bavg++;
    }

    cout<<"Number of scores above than average average : "<<aavg<<endl;
    cout<<"Number of scores below the average are : "<<bavg<<endl;
}

int main(){
    int examScores[10];
    
    in_array(examScores);

    int avg=average(examScores);

    large_small(examScores);

    count(examScores , avg);

}