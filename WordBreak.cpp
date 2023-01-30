#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

map<string, bool> m;

int wordBreak(string A, vector<string> &B){
    if(A.length() == 0){
        return 1;
    }
    if(m.find(A) != m.end()){
        return 1;
    }
    for(int i=0; i<A.length(); i++){
        string temp = A.substr(0, i + 1);
        bool tempExists = find(B.begin(), B.end(), temp) != B.end();
        string rem = A.substr(i + 1, A.length() - (i + 1));
        if(tempExists && wordBreak(rem, B)){
            m[rem] = true;
            return 1;
        }
    }
    m[A] = false;
    return 0;
}

int main(){
    string A = "CODE";
    vector<string> B = {"C", "OD","E","X"};
    A = "idonotlike";
    B = {"i", "like", "sam",
         "sung", "samsung", "mobile",
         "ice", "cream", "icecream",
         "man", "go", "mango"};
    cout<< wordBreak(A, B);
    return 0;
}