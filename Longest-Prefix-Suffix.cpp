#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

void display(vector<string> &v){
    for(string i: v){
        cout<<i<<" ";
    }
    cout<<endl;
}

void lps(string s){
    vector<string> prefix;
    vector<string> suffix;
    int maxi = INT_MIN;

    for(int i=1; i<=s.length()-1; i++){
        prefix.push_back(s.substr(0,i));
    }

    for (int i = 1; i < s.length(); i++)
    {
        suffix.push_back(s.substr(i, s.length()-i));
    }

    for(int i=0; i<prefix.size(); i++){
        if(find(suffix.begin(), suffix.end(), prefix[i]) != suffix.end()){
            int len = prefix[i].length();
            maxi = max(len, maxi);
        }
    }
    cout<<maxi;
}

int main(){
    lps("aaaa");
    return 0;
}