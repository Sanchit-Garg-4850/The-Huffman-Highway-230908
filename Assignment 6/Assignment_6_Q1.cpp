#include <bits/stdc++.h>
using namespace std;

void dfs(int start,vector<int> &visitedarr,vector<vector<int>> &adjList,vector <int> &visitedpath,int end){
    visitedarr[start]=1;
    // cout<<"Modified visited arr"<<endl;
    // for(int i=0 ; i<visitedarr.size() ; i++){
    //     cout<<i<<" : "<<visitedarr[i]<<endl;
    // }
    // cout<<"Values of x are"<<endl;

    for(int x : adjList[start]){
        // cout<<x<<endl;
        if(visitedarr[x]==0){
            visitedpath.push_back(x);
            dfs(x,visitedarr,adjList,visitedpath,end);
        }
    }
    if(visitedpath.back() == end){
        cout<<"Path"<<endl;
        for(int node:visitedpath){
            cout<<node<<" ";
        }
        cout<<endl;
    }


    visitedarr[visitedpath.back()]=0;
    visitedpath.pop_back();

}

void path(vector<vector<int>> &edgesList,int numvertices,int start,int end){

    vector<vector<int>> adjList(numvertices);

    for(int i=0 ; i<edgesList.size() ; i++){
        int u=edgesList[i][0];
        int v=edgesList[i][1];
        adjList[u].push_back(v);
    }

    // cout<<"AdjList is"<<endl;
    // for(int i=0 ; i<adjList.size() ; i++){
    //     cout<<i<<" : ";
    //     for(int it : adjList[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }

    vector <int> visitedarr(numvertices,0);

    // cout<<"Initial visitedarr is"<<endl;
    // for(int i=0 ; i<visitedarr.size() ; i++){
    //     cout<<i<<" : "<<visitedarr[i]<<endl;
    // }

    vector <int> visitedpath;
    visitedpath.push_back(start);

    dfs(start,visitedarr,adjList,visitedpath,end);
    // cout<<visitedpath.size();
    return;

}

int main(){
    int numvertices=4;
    int start ,end;
    cout<<"Enter 1 node : ";
    cin>>start;
    cout<<"Enter 2 node : ";
    cin>>end;
    vector <vector<int>> edgeslist = {{0,1},{0,2},{0,3},{2,0},{1,3},{2,1}};
    vector<int> visitedpath;
    path(edgeslist,numvertices,start,end);
    
    return 0;
}
