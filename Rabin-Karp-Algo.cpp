#include<iostream>
#include<string>
#include<math.h>
#define ll long long int;
#define prime 119
using namespace std;

long long int createHashValue(string str, int n){
    long long int res = 0;
    for(int i=0; i<n; i++){
        res += (long long int)(str[i] * pow(prime, i));
    }
    return res;
}

long long int reCalculateHash(string str, int oldIndex, int newIndex, long long int oldHash, int pattLength){
    long long int newHash = oldHash - str[oldIndex];
    newHash = newHash / prime;
    newHash += (long long int)(str[newIndex] * (long long int)(pow(prime, pattLength - 1)));
    return newHash;
}

bool checkEqual(string str1, string str2, int start1, int start2, int end1, int end2){
    while(start1 <= end1 && start2 <= end2){
        if(str1[start1] != str2[start2]){
            return false;
        }
        start1++;
        start2++;
    }
    return true;
}

int main(){
    string s = "THIS IS A TEST TEXT";
    string p = "TEST";

    long long int pattHash = createHashValue(p, p.length());
    long long int strHash = createHashValue(s, p.length());
    
    for(int i=0; i<=s.length() - p.length(); i++){
        if(pattHash == strHash && checkEqual(s, p, i, 0, i+p.length()-1, p.length()-1)){
            cout<<i<<endl;
        }
        if(i <s.length() - p.length()){
            strHash = reCalculateHash(s, i , i + p.length() , strHash, p.length());
        }
    }
    return 0;
}