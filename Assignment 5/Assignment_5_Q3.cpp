#include <bits/stdc++.h>
using namespace std;

void printvec(vector <int> &v){
    cout<<"[";
    for(int i=0 ; i<v.size()-1 ; i++){
        cout<<v[i]<<",";
    }
    cout<<v[v.size()-1];
    cout<<"]";
    cout<<endl;
}

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : data(0),left(nullptr),right(nullptr) {}
    TreeNode(int data) : data(data),left(nullptr),right(nullptr) {}
    TreeNode(int data,TreeNode* left,TreeNode* right) : data(data),left(left),right(right) {}
};

TreeNode* Tree (){
    cout<<"Enter input data of tree as traversing along breadth from top of the tree"<<endl;
    string input;
    getline(cin,input);

    stringstream ss(input);
    string val;
    getline(ss,val,' ');

    TreeNode* root = new TreeNode(stoi(val));
    queue <TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();

        if(getline(ss,val,' ')){
            if(val != "null"){
                current->left = new TreeNode(stoi(val));
                q.push(current->left);
            }
        }
        if(getline(ss,val,' ')){
            if(val != "null"){
                current->right = new TreeNode(stoi(val));
                q.push(current->right);
            }
        }
    }

    return root;
}
 
bool getroottonodepath(TreeNode* node,int val,vector <int> &path){
    if(!node) return false;

    path.push_back(node->data);
    if(node->data == val) return true;

    if(getroottonodepath(node->left,val,path) || getroottonodepath(node->right,val,path)) return true;

    path.pop_back();
    return false;
}

vector <int> getarr(TreeNode* node,int val){
    vector <int> arr;
    if(!node) return arr;
    getroottonodepath(node,val,arr);
    // printvec(arr);
    return arr;
}

vector<int> getpath(vector <int> &v1 , vector <int> &v2){
    vector <int> path;
    int least_common_ansector=0;

    while(v1.size() != 0 && v2.size() != 0){
        if(v1.front()!=v2.front()){
            break;
        }
        least_common_ansector=v1.front();
        v1.erase(v1.begin());
        v2.erase(v2.begin());
    }

    for(int i=0 ; i<v1.size() ; i++){
        path.push_back(v1[v1.size()-(i+1)]);
    }
    path.push_back(least_common_ansector);
    for(auto it : v2){
        path.push_back(it);
    }

    // printvec(path);
    
    return path;

}

int sum_along_path(vector <int> &path){
    int sum=0;
    for(auto it : path){
        sum+=it;
    }
    return sum;
}

int max_along_path(vector <int> &path){
    int max=INT_MIN;
    for(auto it : path){
        if(it>max){
            max=it;
        }
    }
    return max;
}

int min_along_path(vector <int> &path){
    int min=INT_MAX;
    for(auto it : path){
        if(it<min){
            min=it;
        }
    }
    return min;
}

void solvequeries(vector <pair<int,int>> &queries,TreeNode* root){
    vector <int> sum,max,min;
    for(auto it : queries){
        vector <int> arr1,arr2,path;
        arr1=getarr(root,it.first);
        arr2=getarr(root,it.second);

        path=getpath(arr1,arr2);

        sum.push_back(sum_along_path(path));
        max.push_back(max_along_path(path));
        min.push_back(min_along_path(path));
    }

    cout<<"Sum along path is : ";
    printvec(sum);
    cout<<"Max value along path is : ";
    printvec(max);
    cout<<"Min value along path is : ";
    printvec(min);

}

int main(){
    TreeNode* root;
    root=Tree();

    vector <pair<int,int>> Queries = {{2,4},{5,1}};

    solvequeries(Queries,root);
    
    return 0;
}