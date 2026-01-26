// vectors: dynamic array

/*

.push_back()      = Adds an element at the end of the vector (by copying)
.emplace_back()   = Adds an element at the end by constructing it directly
.at()             = Accesses element safely (checks index bounds)
.back()           = Returns the last element of the vector

push_back({})     = Inserts a pair using initializer list
.emplace_back()   = Directly constructs and inserts a pair

vector(n, val)    = Creates vector with n elements all set to val
vector(og_vec)    = Creates a copy of another vector

.begin()          = Returns iterator to first element
.end()            = Returns iterator to position after last element
.rbegin()         = Returns reverse iterator to last element
.rend()           = Returns reverse iterator before first element

erase(pos)        = Deletes single element at given position
erase(start,end)  = Deletes elements in range [start, end)

insert(pos,val)   = Inserts value at given position
insert(pos,n,val) = Inserts n copies of value at position
insert(pos,first,last) = Inserts a range of elements from another vector

.size()           = Returns number of elements in vector
.pop_back()       = Removes last element
.swap(v)          = Swaps contents of two vectors
.empty()          = Checks if vector is empty (true/false)
.clear()          = Deletes all elements from vector

*/

#include<bits/stdc++.h>
int main(){

    cout << "____________________________________________________________________________________\n";

    vector<int> v;
    v.push_back(5);
    v.emplace_back(6);
    cout << "Push back and emplace back: " << v[0] << v[1] << endl;
    cout << "Using .at(): " << v.at(0) << endl; // safer than v[]
    cout << "Last element = back(): " << v.back();

    cout << "\n____________________________________________________________________________________\n";

    // push_back and emplace_back: push_back inserts a copy or move of an existing object, while emplace_back constructs the object directly inside the vector, potentially avoiding extra copies.
    vector<pair<int,int>> v2;
    v2.push_back({1,2}); // here we use {} for push_back to store it as a 'pair'
    v2.emplace_back(3,4); // emplace_back automatically assumes it as a 'pair'
    cout << "Pairs in vectors: ";
    cout << v2[0].first << v2[0].second << " ";
    cout << v2[1].first << v2[1].second;

    cout << "\n____________________________________________________________________________________\n";

    vector<int>v3(5, 100); // {100, 100, 100, 100, 100}
    cout << "Original vector: ";
    for(int i = 0; i < v3.size(); i++) cout << v3[i] << " "; 
    cout << endl;
    
    vector<int>v4(v3); // copy container of vec1
    cout << "Copied vector: ";
    for(int i = 0; i < v4.size(); i++) cout << v4[i] << " ";

    cout << "\n____________________________________________________________________________________\n";

    cout << "Iterator in vector: ";
    vector<int> v5 = {10, 20, 30, 40};
    vector<int>::iterator it = v5.begin(); // points to the beginning memory address of the vector
    vector<int>::iterator it2 = v5.end(); // points to the address right after the last element 
    vector<int>::reverse_iterator rit = v5.rend(); // reverses the vector and points right after the last element 
    vector<int>::reverse_iterator rit2 = v5.rbegin(); // reverses the vector and points at the first element 
    cout << "Before inc/dec: " << *it << " " << *it2 << " " << *rit << " " << *rit2 << endl; 
    it++; it2--; rit--; rit2++;
    cout << "After inc/dec: " << *it << " " << *it2 << " " << *rit << " " << *rit2 << endl;

    cout << "Iterator in loop: ";
    vector<int> v6 = {4, 8, 12, 16};
    for(auto it = v6.begin(); it != v6.end(); it++){ // auto = vector<int>::iterator (automatically defines the datatype)
        cout << *it << " ";
    }
    cout << "\nfor each loop: ";
    for(auto it : v6){ // here auto is assigned as int
        cout << it << " ";
    }

    cout << "\n____________________________________________________________________________________\n";

    cout << "Deletion of a vector:";
    vector<int> v7 = {7, 14, 21, 28, 35};
    cout << "\nBefore deletion: ";
    for(auto it = v7.begin(); it != v7.end(); it++) cout << *it << " ";
    cout << "\nSingle deletion: ";
    v7.erase(v7.begin()+2);
    for(auto it = v7.begin(); it != v7.end(); it++) cout << *it << " ";
    cout << "\nMultiple deletion: ";
    // [start, end)
    v7.erase(v7.begin(), v7.begin()+3); 
    for(auto it = v7.begin(); it != v7.end(); it++) cout << *it << " ";

    cout << "\n____________________________________________________________________________________\n";

    cout << "Insert function:\n";
    vector<int> v8(4, 20); // vector of 4 elements of '20'
    for(auto it : v8) cout << it << " ";
    cout << endl;
    v8.insert(v8.begin(), 5); // inserting '5' at begin
    for(auto it : v8) cout << it << " ";
    cout << endl;
    v8.insert(v8.begin(), 2, 1); // inserting 2 elements of '1' at begin
    for(auto it : v8) cout << it << " ";
    cout << endl;
    vector<int> v9(2, 50);
    v8.insert(v8.begin(), v9.begin(), v9.end()); // inserting an entire vector
    for(auto it : v8) cout << it << " ";

    cout << "\n____________________________________________________________________________________\n";

    vector<int> v10(4, 10);
    cout << "vector10: ";
    for(vector<int>::iterator it = v10.begin(); it != v10.end(); it++) cout << *it << " ";
    cout << endl;

    cout << "size of v10: " << v10.size() << endl; // size of vector

    v10.pop_back(); // removes last element
    cout << "v10 after pop_back(): ";
    for(auto it = v10.begin(); it != v10.end(); it++) cout << *it << " ";

    vector<int> v11(2, 11);
    v10.swap(v11);
    cout << "\nv10 after swap(): ";
    for(auto it : v10) cout << it << " ";
    cout << "\nv11 after swap(): ";
    for(auto it : v11) cout << it << " ";

    cout << "\nIs v11 empty? " << v11.empty(); // 0 = false
    v11.clear(); // erases entire vector;
    cout << "\nIs v11 empty? " << v11.empty(); // 1 = true

    return 0;
}