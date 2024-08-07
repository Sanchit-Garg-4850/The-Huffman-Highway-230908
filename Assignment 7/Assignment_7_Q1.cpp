#include <bits/stdc++.h>
using namespace std;

int maxProjectValue(int N, vector<int>& values, vector<vector<string>>& required_languages, set <string>&known_languages) {
    int sum=0;
    for(int i=0 ; i<N ;i++){
        bool flag=true;
        for(auto language : required_languages[i]){
            if(known_languages.find(language) == known_languages.end()){
                flag=false;
                break;
            }
        }
        if(flag){
            sum+=values[i];
        }
    }
    return sum;
}

int main() {
    int N = 10;

    vector<int> values = {50, 30, 70, 20, 90, 10, 60, 40, 80, 100};

    vector<vector<string>> required_languages = {{"Python", "C++"}, {"Java", "Python"}, {"C++", "Java", "Python"},
    {"Python"}, {"Java", "Go"}, {"C++"}, {"Python", "Go"}, {"C++", "Python"}, {"Java", "Python", "Go"}, {"C++", "Java", "Go"}};

    set <string> known_languages = {"Python","C++", "Java"};

    int result = maxProjectValue(N, values, required_languages, known_languages);

    cout << "Maximum Project Value: " << result << endl;

    return 0;
}