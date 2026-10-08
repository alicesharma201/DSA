#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int>& a){ // asteroids
    // TC: O(n)
    // SC: O(n)
    vector<int> s; // survivors
    for(int i = 0; i < a.size(); i++){
        if(a[i] > 0) s.push_back(a[i]);
        else{
            while(!s.empty() && s.back() > 0 && s.back() < abs(a[i])) s.pop_back();
            if(!s.empty() && s.back() == abs(a[i])) s.pop_back();
            else if(s.empty() || s.back() < 0) s.push_back(a[i]);
        }
    }
    return s;
}
int main(){
    vector<int> asteroids = {5, 6, -7, 2, 8, -4, 10, -11, 7};
    for(int i : asteroidCollision(asteroids)){
        cout << i << ' ';
    }
    return 0;
}