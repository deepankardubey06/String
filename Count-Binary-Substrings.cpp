#include<iostream>
#include<string>
#include<vector>
using namespace std;

int numOfPairs;

// Approach - 1
// void countBinarySubstrings(string s){
//     for(int i=0; i<s.length(); i++){
//         if(s[i] == '0'){
//             int numberOfZero = 0;
//             int ptr = i;
//             while(s[ptr] == '0' && ptr < s.length()){
//                 numberOfZero++;
//                 ptr++;
//             }
//             int numberOfOne = 0;
//             while(s[ptr] == '1' && ptr < s.length() && numberOfOne < numberOfZero){
//                 numberOfOne++;
//                 ptr++;
//             }
//             if (numberOfOne == numberOfZero)
//             {
//                 numOfPairs += 1;
//             }
//         }
//         else{
//             int numberOfOne = 0;
//             int ptr = i;
//             while (s[ptr] == '1' && ptr < s.length() )
//             {
                
//                 numberOfOne++;
//                 ptr++;
//             }
//             int numberOfZero = 0;
//             while (s[ptr] == '0' && ptr < s.length() && numberOfZero < numberOfOne)
//             {
                
//                 numberOfZero++;
//                 ptr++;
//             }
//             if(numberOfOne == numberOfZero){
//                 numOfPairs += 1;
//             }
//         }
//     }
// }

//Approach - 2
void countBinarySubstrings(string s){
    vector<int> grp(s.size());
    int index = 0;
    grp[0] = 1;
    for(int i=1; i<s.length(); i++){
        if(s[i-1] != s[i]){
            index++;
            grp[index] = 1;
        }
        else{
            grp[index] += 1;
        }
    }
    int ans = 0;
    for(int i=1; i<grp.size(); i++){
        ans += min(grp[i-1], grp[i]);
    }
    cout<<ans<<endl;
}

int main(){
    numOfPairs = 0;
    countBinarySubstrings("00110011");
    // cout<<numOfPairs;
    return 0;
}