#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<string> v;

void display(vector<string> &v){
    for(string i : v){
        cout<<i<<endl;
    }
}

void permutation(string str, int index, string newstr){
    if(index == str.length()){
        v.push_back(newstr);

    }
    for(int i=index ; i<str.length(); i++){
        char temp = newstr[index];
        newstr[index] = newstr[i];
        newstr[i] = temp;
        permutation(str, index + 1, newstr);
    }
}

int main(){
    // string h = "hello";
    // h[0] = 'z';
    // cout<<h;
    permutation("ABSG", 0, "ABSG");
    sort(v.begin(), v.end());
    display(v);
    return 0;
}