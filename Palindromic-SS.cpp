#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// vector<string> v;

// void countPS(string str, int index, string s1){
//     if(index >= str.length()){
//         string s2 = s1;
//         reverse(s2.begin(), s2.end());
//         if(s1 == s2){
//             v.push_back(s1);
//         }
//         return;
//     }
//     countPS(str, index + 1, s1 + str[index]);
//     countPS(str, index + 1, s1);
// }

void countPS(string str){
    long long int cnt = 0;
    for(int i=0; i<str.length(); i++){
        for(int j=0; j<str.length() - i; j++){
            string temp = str.substr(i, j + 1);
            string temp2 = temp;
            reverse(temp2.begin(), temp2.end());
            if(temp == temp2){
                cnt++;
            }
        }
    }
    cout<<cnt;
}

int main(){
    countPS("aaaaaaaaaaaaaaaaaaaaaaaaaaa");
    return 0;
}