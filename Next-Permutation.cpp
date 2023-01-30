#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> v;

void display(vector<int> &v)
{
    for (int i : v)
    {
        cout << i << endl;
    }
}

void permutation(string str, int index, string newstr)
{
    if (index == str.length())
    {
        int ans = stoi(newstr);
        v.push_back(ans);
    }
    for (int i = index; i < str.length(); i++)
    {
        char temp = newstr[index];
        newstr[index] = newstr[i];
        newstr[i] = temp;
        permutation(str, index + 1, newstr);
    }
}

int findNextGreater(int num, vector<int> &v, vector<int> &arr)
{
    for (int i : v)
    {
        if(i > num){
            return i;
        }
    }
    string s = "";
    sort(arr.begin(), arr.end());
    for(int i: arr){
        s += to_string(i);
    }
    return stoi(s);
}

int main()
{
    vector<int> arr = {1, 2, 3, 6, 5, 4};
    string str = "";
    for(int i=0; i<arr.size(); i++){
        str += to_string(arr[i]);
    }
    permutation(str, 0, str);
    sort(v.begin(), v.end());
    int num = findNextGreater(stoi(str), v, arr);
    cout<<num;
    return 0;
}