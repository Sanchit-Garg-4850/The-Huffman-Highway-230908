#include <bits/stdc++.h>
using namespace std;


class TreeNode {
    public:
      int val;
      TreeNode *left;
      TreeNode *right;

      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* Tree(){
    cout<<"Enter breadth wise elements or making tree from top"<<endl;
    string input;
    getline(cin,input);
    stringstream ss(input);
    string val;

    getline(ss,val,' ');

    TreeNode* root = new TreeNode(stoi(val));

    queue <TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (std::getline(ss, val, ' ')) {
            if (val != "null") {
                current->left = new TreeNode(stoi(val));
                q.push(current->left);
            }
        }

        if (std::getline(ss, val, ' ')) {
            if (val != "null") {
                current->right = new TreeNode(stoi(val));
                q.push(current->right);
            }
        }
    }

    return root;

}

bool areIsomorphic(TreeNode* T1, TreeNode* T2) {

    if (T1 == nullptr && T2 == nullptr) return true;
    
    if (T1 == nullptr || T2 == nullptr) return false;

    return (areIsomorphic(T1->left, T2->left) && areIsomorphic(T1->right, T2->right)) ||
           (areIsomorphic(T1->left, T2->right) && areIsomorphic(T1->right, T2->left));
}



int main(){
    TreeNode* root1;
    TreeNode* root2;

    root1=Tree();
    root2=Tree();


    if (areIsomorphic(root1, root2)) {
        cout << "The trees are isomorphic." << endl;
    } else {
        cout << "The trees are not isomorphic." << endl;
    }

    return 0;
}