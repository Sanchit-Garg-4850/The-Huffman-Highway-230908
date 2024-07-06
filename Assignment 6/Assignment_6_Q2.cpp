#include<bits/stdc++.h>
using namespace std;

bool flag1=false;
bool flag2=false;

void printadjMatrix(int** adjMatrix,int numvertices){
    for(int i=0 ; i<numvertices ; i++){
        for(int j=0 ; j<numvertices ; j++){
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool Flag1(vector <int> &visitedpath,int** adjMatrix,int numvertices){

    if(visitedpath.size()==numvertices){
        flag1=true;
    }
    return flag1;
}

bool Flag2(vector <int> &visitedpath,int** adjMatrix,int numvertices){

    if(adjMatrix[visitedpath.back()][visitedpath.front()]==1 && visitedpath.size()==numvertices){
        flag2=true;
    }
    return flag2;
}

void dfs(int start,vector<int> &visitedarr,int** adjMatrix,int numvertices,vector <int> &visitedpath){
    visitedarr[start]=1;
    vector <vector<int>> reqpath;
    for(int i=0 ; i<numvertices ; i++){
            if(visitedarr[i]==0 && adjMatrix[start][i]){
            visitedpath.push_back(i);
            dfs(i,visitedarr,adjMatrix,numvertices,visitedpath);
        }
    }

    Flag1(visitedpath,adjMatrix,numvertices);
    Flag2(visitedpath,adjMatrix,numvertices);

    visitedarr[visitedpath.back()]=0;
    visitedpath.pop_back();

}

void check(vector<vector<int>> &edgesList,int numvertices){

    int** adjMatrix = (int**)calloc((numvertices * numvertices),sizeof(int));
    for(int i=0 ; i<numvertices ; i++){
        adjMatrix[i]=(int*)calloc(numvertices,sizeof(int));
    }

    // printadjMatrix(adjMatrix,numvertices);

    for(int i=0 ; i<edgesList.size() ; i++){
        int u=edgesList[i][0];
        int v=edgesList[i][1];
        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;
    }
    printadjMatrix(adjMatrix,numvertices);

    // printadjMatrix(adjMatrix,numvertices);

    vector <int> visitedarr(numvertices,0);
    // cout<<"Initial visitedarr is"<<endl;
    // for(int i=0 ; i<visitedarr.size() ; i++){
    //     cout<<i<<" : "<<visitedarr[i]<<endl;
    // }

    for(int i=0 ; i< numvertices ; i++){
        vector <int> visitedpath;
        visitedpath.push_back(i);

        dfs(i,visitedarr,adjMatrix,numvertices,visitedpath);
    }
    
   if(flag1==true){
        cout<<"Hamiltonian Path exists!"<<endl;
        if(flag2==true){
            cout<<"Graph is a Hamiltonian circuit"<<endl;
        }else{
            cout<<"Graph is not a Hamiltonian circuit"<<endl;
        }
        cout<<endl;
    }else{
    cout<<"Hamiltonian path does not exist!"<<endl;
    }

    return;
}

int main(){
    int numvertices;
    cout<<"Enter number of vertices : ";
    cin>>numvertices;
    vector <vector<int>> edgeslist = {{0,1},{1,2},{2,3},{3,4}};
    check(edgeslist,numvertices);
    return 0;
}