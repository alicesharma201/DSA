// List: gives front operations as well compared to vectors
#include<bits/stdc++.h>
int main(){
    list<int> ls;
    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2, 4}

    // push_front() and emplace_front() are cheaper than insert() in vector
    ls.push_front(5); // {5, 2, 4} 
    ls.emplace_front(1); // {1, 5, 2, 4}
    return 0;
}
// rest of the functions are same as vector:
// begin, end, rbegin, rend, clear, insert, size, swap