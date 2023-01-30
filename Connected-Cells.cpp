#include<iostream>
#include<vector>
using namespace std;

void maximumArea(vector<vector<int>> &connected, int r, int c, vector<vector<bool>> &visited, vector<pair<int, int>> &v1)
{
    if(r >= 0 && r < connected.size() && c >= 0 && c < connected[0].size() && visited[r][c] == false && connected[r][c] != 0){
        visited[r][c] = true;

        pair<int,int> pr;
        pr.first = r;
        pr.second = c;
        v1.push_back(pr);

        maximumArea(connected, r, c - 1, visited ,v1);
        maximumArea(connected, r - 1, c, visited, v1);
        maximumArea(connected, r, c + 1, visited, v1);
        maximumArea(connected, r + 1, c, visited, v1);
        maximumArea(connected, r + 1, c + 1, visited, v1);
        maximumArea(connected, r - 1, c - 1, visited, v1);
        maximumArea(connected, r - 1, c + 1, visited, v1);
        maximumArea(connected, r + 1, c - 1, visited, v1);
    }
}

int main(){
    int maxi = INT_MIN;
    vector<vector<int>> connected = {
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 1, 1}
    };
    vector<vector<bool>> visited = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
    };

    for(int i=0; i<connected.size(); i++){
        for(int j=0; j<connected[i].size(); j++){
            if(connected[i][j] == 1 && visited[i][j] == 0){
                vector<pair<int, int>> v1;
                maximumArea(connected, i, j, visited, v1);
                int res= v1.size();
                maxi = max(maxi, res);
            }
        }
    }
    // for(int i=0; i<visited.size(); i++){
    //     for(int j=0; j<visited[i].size(); j++){
    //         cout<<visited[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<maxi<<endl;
    return 0;
}