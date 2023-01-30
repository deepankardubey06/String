#include<iostream>
#include<vector>

using namespace std;

bool func(int r, int c, vector<vector<char>> &mat, string &str, int index){
    if(r < 0 || c < 0 || r >= mat.size() || c > mat[0].size()){
        return false;
    }
    if(index == str.length()){
        return true;
    }
    if(mat[r][c] != str[index] || mat[r][c] == 'X'){
        return false;
    }
    char temp = mat[r][c];
    mat[r][c] = 'X';
    bool t = func(r - 1, c, mat, str, index + 1);
    bool l = func(r, c - 1, mat, str, index + 1);
    bool b = func(r + 1, c, mat, str, index + 1);
    bool ri = func(r, c + 1, mat, str, index + 1);
    mat[r][c] = temp;
    return (t || l || b || ri);

}

void rec(vector<vector<char>> &mat, string str){
    int count = 0;
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[i].size(); j++){
            if(mat[i][j] == str[0]){
                bool val = func(i, j, mat, str, 0);
                if(val){
                    count++;
                }
            }
        }
    }
    cout<<count;
}

int main(){
    vector<vector<char>> mat = {
        {'D', 'D', 'D', 'G', 'D', 'D'},
        {'B', 'B', 'D', 'E', 'B', 'S'},
        {'B', 'S', 'K', 'E', 'B', 'K'},
        {'D', 'D', 'D', 'D', 'D', 'E'},
        {'D', 'D', 'D', 'D', 'D', 'E'},
        {'D', 'D', 'D', 'D', 'D', 'G'}
    };
    string str = "GEEKS";

    cout<<"Test Case 1 --->";
    rec(mat, str);
    cout<<endl;

    mat = {
        {'B', 'B', 'M', 'B', 'B', 'B'},
        {'C', 'B', 'A', 'B', 'B', 'B'},
        {'I', 'B', 'G', 'B', 'B', 'B'},
        {'G', 'B', 'I', 'B', 'B', 'B'},
        {'A', 'B', 'C', 'B', 'B', 'B'},
        {'M', 'C', 'I', 'G', 'A', 'M'}
    };
    str = "MAGIC";

    cout << "Test Case 2 --->";
    rec(mat, str);
    cout << endl;

    return 0;
}