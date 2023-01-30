// Convert a sentence into its equivalent mobile numeric keypad sequence
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

void createKeypad(map<string,int> &m){
    m["ABC"] = 2;
    m["DEF"] = 3;
    m["GHI"] = 4;
    m["JKL"] = 5;
    m["MNO"] = 6;
    m["PQRS"] = 7;
    m["TUV"] = 8;
    m["WXYZ"] = 9;
    m[" "] = 0;
}

void generateSequence(map<string,int> &m, string str){
    string ans = "";
    for(int i=0; i<str.length(); i++){
        int pos = -1;   //1
        int index = -1; //4
        for (auto itr = m.begin(); itr != m.end(); itr++)
        {
            string s = itr->first;
            if( s.find(str[i]) != string::npos){
                index = itr->second;
                pos = s.find(str[i]) + 1;
                break;
            }
        }
        for(int j=1; j<=pos; j++){
            ans += to_string(index);
        }
    }
    cout<<ans;
}

int main(){
    map<string, int> keyPad;
    createKeypad(keyPad);
    generateSequence(keyPad, "HEY U");
    return 0;
}