#include <bits/stdc++.h>
using namespace std;

class HuffmanNode {
public:
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
    //HuffmanNode('a',100);'
};

class compare{
    public:
    bool operator()(HuffmanNode* left,HuffmanNode* right){
        return (left->freq > right ->freq);
    }
};

class Huffmandecoding{
    HuffmanNode* root;
    unordered_map<char,string> code;

    void BuildHuffmanTree(unordered_map<char,int> &freqmap);
    void GenerateCode(HuffmanNode* root,const string &str);
    public:
    Huffmandecoding() : root(nullptr){}
    void decompress(string &inputFileName, string &outputFileName, unordered_map<char,int> &freqmap);
};

void Huffmandecoding :: BuildHuffmanTree(unordered_map<char,int> &freqmap){
    priority_queue<HuffmanNode* , vector<HuffmanNode*>,compare> minHeap;

    for(auto ch:freqmap){
        minHeap.push(new HuffmanNode(ch.first,ch.second));
    }

    while(minHeap.size() != 1){
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        int sum = left->freq+right->freq;
        HuffmanNode* node = new HuffmanNode('\0',sum);
        node->left=left;
        node->right=right;

        minHeap.push(node);
    }

    root=minHeap.top();

}

void Huffmandecoding :: GenerateCode(HuffmanNode* node,const string &str){
    if(!node) return;

    if(node->data != '\0'){
        code[node->data]= str;
    }

    GenerateCode(node->left,str+'0');
    GenerateCode(node->right,str+'1');
}

void Huffmandecoding :: decompress(string &inputFileName , string & outputFileName , unordered_map<char,int> &freqmap){
    ifstream inputFile(inputFileName, ios::in);
    
    if (!inputFile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return;
    }

    string data((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    BuildHuffmanTree(freqmap);
    GenerateCode(root,"");

    string decodedstr;
    HuffmanNode* current=root;

    for( char ch : data){
        if(ch == '0'){
            current=current->left;
        }else{
            current=current->right;
        }

        if(current->left == NULL && current->right == NULL){
            decodedstr+=current->data;
            current=root;
        }
    }

    
    ofstream outputFile(outputFileName, ios::out);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file!" << endl;
        return;
    }

    outputFile<<decodedstr;
    outputFile.close();

}

int main() {
    string inputFileName = "compressed.txt";
    string outputFileName = "decompressed.txt";

    unordered_map<char,int> freqmap = { {'k',2} , {'j',1} , {'p',8} , {'x',1 } , {'K',1} , {'.',3 } , {'h',7} , {'c',4} ,
    {'e',17} , {'d',7} , {'y',2} , {'C',1} , {'o',16} , {'n',8} , {'a',6} , {'w',1} , {' ',29} , {'g',6} , {'t',14} , {'r',7} ,
    {'u' ,6} , {'l' ,4 } ,{'i' ,5 }, {'s' ,5} , {'I' ,1}  ,{'f' ,2 } ,{',' ,1 } };

    Huffmandecoding huffman;
    huffman.decompress(inputFileName,outputFileName,freqmap);

    return 0;
}
