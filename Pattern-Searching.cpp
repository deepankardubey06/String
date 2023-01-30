#include<iostream>
#include<string>
using namespace std;

// Approach-1 | Naive | Brute Force
void patternSearch(string text, string patt){
    int n = text.length() - patt.length();
    for(int i=0; i<=n; i++){
        string s = text.substr(i,patt.length());
        if(s == patt){
            cout<<"found at index : "<<i<<endl;
        }
    }
}

// Approach-2 | Rabin Karp Algorithm


int main(){
    patternSearch("AABAACAADAABAABA", "AABA");
    return 0;
}