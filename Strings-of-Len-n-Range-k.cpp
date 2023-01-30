#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

void display(vector<int> &v){
    for (int j : v)
    {
        cout << j;
    }
    cout << endl;
}

void generateStr(int n, int k){
    if(v.size() == n){
        display(v);
        return;
    }
    for(int i=0; i<k; i++){
        v.push_back(i);
        generateStr(n, k);
        v.pop_back();
    }
}

int main(){
    generateStr(2,3);
    return 0;
}