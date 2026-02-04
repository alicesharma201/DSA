#include<bits/stdc++.h>
void print1(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void print2(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void print3(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
void print4(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << i << " ";
        }
        cout << endl;
    }
}
void print5(int n){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < (n-i); j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void print6(int n){
    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= (n-i); j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
void print7(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (n-i-1); j++){
            cout << "  ";
        }
        for(int j = 0; j < (2*i)+1; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void print8(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            cout << "  ";
        }
        for(int j = 0; j < 2*(n-i)-1; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void print9(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            cout << "  "; 
        }
        for(int j = 0; j < (2*i)+1; j++){
            cout << "* ";
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            cout << "  ";
        }
        for(int j = 0; j < 2*(n-i)-1; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void print10(int n){
    for(int i = 1; i <= (2*n)-1; i++){
        int lines = i;
        if(i > n) 
            lines = (2*n)-i;
        for(int j = 1; j <= lines; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void print11(int n){
    int thing = 1;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) thing = 1;
        else thing = 0;
        for(int j = 0; j <= i; j++){
            cout << thing;
            thing = 1 - thing;
        }
        cout << endl;
    }
}
void print12(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++) cout << j; 
        for(int j = 1; j <= 2*(n-i); j++) cout << " ";
        for(int j = i; j >= 1; j--) cout << j; 
        cout << endl;
    }
}
void print13(int n){

    int value = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << value << " ";
            value++;
        }
        cout << "\n";
    }
}
void print14(int n){
    for(int i = 0; i < n; i++){
        for(char ch = 'A'; ch <= 'A' + i; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}
void print15(int n){
    for(int i = 0; i < n; i++){
        for(char ch = 'A'; ch < ('A'+n-i); ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}
void print16(int n){
    // for(char char1 = 'A'; char1 < n+'A'; char1++){
    //     for(char char2 = 'A'; char2 <= char1; char2++){
    //         cout << char1 << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 0; i < n; i++){
        char ch = 'A' + i;
        for(int j = 0; j <= i; j++){
            cout << ch;
        }
        cout << endl;
    }
}
void print17(int n){
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < (n-i-1); j++) cout << "  ";
    //     for(char ch = 'A'; ch <= 'A'+i; ch++) cout << ch << " ";
    //     for(char ch = 'A'+i-1; ch >= 'A'; ch--) cout << ch << " ";
    //     cout << endl;
    // }
    for(int i = 0; i < n; i++){
        char ch = 'A';
        for(int j = 0; j < n-i-1; j++){
            cout << ' ';
        }
        for(int j = 0; j < 2*i+1; j++){
            cout << ch;
            if(j < ((2*i)+1)/2) ch++;
            else ch--;
        }
        cout << endl;
    }
}
void print18(int n){
    for(int i = 0; i < n; i++){
        for(char ch = 'E'-i; ch <= 'E'; ch++){
            cout << ch << ' ';
        }
        cout << endl;
    }
}
void print19(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++) cout << "*";
        for(int j = 0; j < 2*i; j++) cout << " ";
        for(int j = 0; j < n-i; j++) cout << "*";
        cout << endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++) cout << "*";
        for(int j = 0; j < 2*(n-i)-2; j++) cout << " ";
        for(int j = 0; j <= i; j++) cout << "*";
        cout << endl;
    }
    // for(int i = 0; i < 2*n; i++){
    //     int stars = n - i;
    //     int space = 2*i;
    //     if(i >= n){
    //         stars = i - n + 1;
    //         space = 2*(2*n - i - 1);
    //     }
    //     for(int j = 0; j < stars; j++) cout << "*";
    //     for(int j = 0; j < space; j++) cout << " ";
    //     for(int j = 0; j < stars; j++) cout << "*";
    //     cout << endl;
    // }
}
void print20(int n){
    for(int i = 1; i < 2*n; i++){
        int stars = i;
        int space = 2*(n - i);
        if(i > n){
            stars = 2*n - i;
            space = 2*(i-n);
        }
        for(int j = 0; j < stars; j++) cout << "*";
        for(int j = 0; j < space; j++) cout << " ";
        for(int j = 0; j < stars; j++) cout << "*";
        cout << endl;
    }
}
void print21(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || i == n-1 || j == 0 || j == n-1) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}
void print22(int n){
    for(int i = 0; i < 2*n-1; i++){
        for(int j = 0; j < 2*n-1; j++){
            int top = i;
            int left = j; 
            int bottom = (2*n-2)-i; // 2(4) - 1 => 7 -1 => [0, 1, 2, 3, 4, 5, 6] - i
            int right = (2*n-2)-j;
            int shortest_distance = min(min(top, bottom), min(left, right));
            cout << n - shortest_distance << " ";
        }
        cout << endl;
    }
}
int main(){
    int t; // number of test cases
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        print22(n);
    }
    return 0;
}