#include <iostream>
using namespace std;

void make_matrix(int x , char ** matrix){
    for(int i=0; i<x ; i++){
        for(int j=0 ; j<x*x ; j++){
            matrix[i][j]=' ';
            
        }
    }
}

void print_matrix(int x,char** matrix){

    for(int i=0 ; i<x ; i++){
        for(int j=0 ; j<x*x ; j++){
            cout << matrix[i][j];
        }
        cout<<'\n';
    }
}

int main(){
    int x;
    cin >> x;
    
    char ** matrix = (char **)malloc(sizeof(char) * x * x * x);
    for (int i = 0; i < x; i++) matrix[i] = (char *)malloc(sizeof(char) * x * x);

    make_matrix(x,matrix);

    for(int i=1 ; i<=x ; i++){
        
        int triangle =1;

            int j=1;
            while(triangle<=x && j<=(x*x)){
                int itr=0;
            
                while(itr<x){

                    if((triangle%2)!=0){
                        int a=(j%x)+48;
                        if((j%x) <= i && ((j%x)!=0)) matrix[i-1][j-1]=char(a);
                        else if((j%x) <= i && ((j%x)==0) && i==x) matrix [i-1] [j-1] = char(x+48);
                        else matrix[i-1][j-1]  =  ' ';

                        j++;
                    }

                    else {
                        int a=(j%x)+48;
                        if((j%x) <= i && ((j%x)!=0)) matrix [i-1] [(triangle*x)-((j%x)-1)-1] = char(a);
                        else if((j%x) <= i && ((j%x)==0) && i==x) matrix [i-1] [((triangle-1)*x)] = char(x+48);
                        else matrix [i-1]  [(triangle*x)-((j%x)-1)-1]  =  ' ';

                        j++;
                    }

                    itr++;
                }
                
                triangle++;
            }
        }     

    print_matrix(x,matrix);
}