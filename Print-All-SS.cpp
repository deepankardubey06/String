#include<iostream>
using namespace std;

void printSubSequences(string str, int start, int end, string subSeq){
    if(start > end){
        cout<<subSeq<<" ";
        return;
    }
    printSubSequences(str, start + 1, end, subSeq + str[start]);
    printSubSequences(str, start + 1, end, subSeq);
}

int main(){
    printSubSequences("abc", 0, 2, "");
    return 0;
}