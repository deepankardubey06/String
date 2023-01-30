#include<iostream>
#include<vector>
using namespace std;

void rec(vector<vector<string>> &v, int index, string newSentence){
    if(index == v.size()){
        cout<<newSentence<<endl;
        return;
    }
    for(int i=0; i<v[index].size(); i++){
        rec(v, index + 1, newSentence + v[index][i] + " ");
    }
}

int main(){
    vector<vector<string>> v = {{"you", "we"},
                                {"have", "are"},
                                {"sleep", "eat", "drink"}};
    rec(v, 0, "");
    return 0;
}