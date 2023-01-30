#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> grid = {
        { 0, 1, 0, 0 }, 
        { 1, 1, 1, 0 }, 
        { 0, 1, 0, 0 }, 
        { 1, 1, 0, 0 }};
    int island = 0, neighbor = 0;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            if(grid[i][j] == 1){
                island++;
                if(j + 1 < grid[0].size() && grid[i][j+1] == 1){
                    neighbor++;
                }
                if(i + 1 < grid.size() && grid[i+1][j] == 1){
                    neighbor++;
                }
            }
        }
    }
    cout<< 4 * island - 2 * neighbor<<endl;
    return 0;
}