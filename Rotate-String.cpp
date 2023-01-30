#include<iostream>
#include<string>
using namespace std;

void allRotations(string str){
    for(int i = 0; i < str.length() - 1; i++){
        string part1 = str.substr(0, i+1);
        string part2 = str.substr(i+1, str.length() - (i + 1));
        cout<<part2 + part1<<endl;
    }
}

int main(){
    allRotations("ABACD");
    return 0;
}