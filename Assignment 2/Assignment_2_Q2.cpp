#include<bits/stdc++.h>
using namespace std;


int m,n;

class Matrix {

    int rows,columns;
    float **arr;

    public : 
    friend class Matrix operator *(class Matrix &matA , class Matrix &matB);

    Matrix(int a, int b){
        rows=a;
        columns=b;

        arr = new float*[rows];
        for (int i = 0; i < rows; ++i) {
            arr[i] = new float[columns];
        }
    }

    void input(){
        cout<<"Enter values for ";
        cout<<rows<<"*"<<columns<<" array"<<endl;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cin>>arr[i][j];
            }
        }
    }

    void print(){
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
};

class Matrix operator *(class Matrix &matA , class Matrix &matB){

    // if(matA.columns!=matB.rows){
    //     cout<<"Invalid input"<<endl;
    //     return ;
    // }

    class Matrix ans(matA.rows,matA.rows);

    for(int r=1 ; r<=matA.rows ; r++) {

        for(int c=1 ; c<=matA.columns ; c++){
            for(int k=1 ; k<=matA.columns ; k++){
                ans.arr[r-1][c-1]+=matA.arr[r-1][k-1]*matB.arr[k-1][c-1];
            }
        }
    }

    return ans;
}


int main(){
    int m,n;
    cout<<"Enter Number of rows : ";
    cin>>m;
    cout<<"Enter Number of columns : ";
    cin>>n;
    
    Matrix matA(m,n);
    Matrix matB(n,m); 
    Matrix matC(m,m);
    
    matA.input();
    matB.input();
    
    matC=matA*matB;
    
    matA.print();
    matB.print();
    matC.print();

}