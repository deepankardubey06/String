#include<iostream>
#include<vector>
using namespace std;

vector<char> v;

void binaryString(int n, vector<bool> &v, int index){
    if(index == n){
        for(int c: v){
            cout<<c;
        }
        cout<<endl;
        return;
    }
    v[index] = 0;
    binaryString(n, v, index + 1);
    v[index] = 1;
    binaryString(n, v, index + 1);
}

int main(){
    vector<bool> v(3,0);
    binaryString(3, v, 0);
    return 0;
}