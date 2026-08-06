#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Basic C++ keywords, data types, and control flow
    int n = 100;
    float f1 = 1.0;
    char c1 = 'A';
    bool flag = true;
    
    int _123djf = 10; // Valid variable name, can start with an underscore
    
 
   
    string greeting = "Hello";
    const int MAX = 100; // constant variable   
    cout << "The constant MAX is: " << MAX << endl;

    cout << "Basic C++ subset test" << endl;

    cout << "Enter an integer: ";
    cin >> n; // Uncomment if you want to test input handling

    cout << "Enter a float: ";
    cin >> f1;

    cout << "Enter a character: ";
    cin >> c1;

    cout << "Your entered integer is: " << n << endl;
    cout << "Your entered float is: " << f1 << endl;
    cout << "Your entered character is: " << c1 << endl;
    cout << "Your entered bool is: " << flag << endl;
    cout << "Your entered string is: " << greeting << endl;

    int n1 = 104;
    cout << "The value of n1 is: " << n1 << endl;

    int x = 10;
    x += 5;
    cout << "x after += 5: " << x << endl;
    x -= 3;
    cout << "x after -= 3: " << x << endl;
    x *= 2;
    cout << "x after *= 2: " << x << endl;
    x /= 4;
    cout << "x after /= 4: " << x << endl;
    x=x%3;
    cout << "x after %= 3: " << x << endl;

    cout << "Comparison Operators:" << endl;
    int p = 10;
    int q = 20;
    cout << "p == q: " << (p == q) << endl;
    cout << "p != q: " << (p != q) << endl;
    cout << "p > q: " << (p > q) << endl;
    cout << "p < q: " << (p < q) << endl;

    cout << "Logical Operators:" << endl;
    int r = 1;
    int s = 0;
    cout << "r && s: " << (r && s) << endl;
    cout << "r || s: " << (r || s) << endl;
    cout << "!r: " << (!r) << endl;

    //checking bitwise operators in C++
    int t = 5; // binary: 0101
    cout << "Bitwise Operators:" << endl;
    cout << "t & 3: " << (t & 3) << endl;    
    cout << "t | 3: " << (t | 3) << endl; 
    cout << "t ^ 3: " << (t ^ 3) << endl; 
    cout << "~t: " << (~t) << endl;         
    cout << "t << 1: " << (t << 1) << endl; 
    cout << "t >> 1: " << (t >> 1) << endl; 


    cout << "String concatenation:" << endl;
    string st1, st2;
    cout << "Enter first string: ";
    cin >> st1;
    cout << "Enter second string: ";
    cin >> st2;
    string st3 = st1 + " " + st2;
    cout << "Concatenated string: " << st3 << endl;
    
    //checking ternary operator
    int a = 10; int b = 20;
    int max = (a > b) ? a : b;
    cout << "Max of a and b: " << max << endl;
   

    cout << "Flow control (if/else):" << endl;
    int age = 2;
    if (age >= 18) {
        cout << "You are an adult." << endl;
    } else if (age >= 13) {
        cout << "You are a teenager." << endl;
    } else {
        cout << "You are a child." << endl;
    }
    
    //switch statement
    int day = 3;
    switch (day) {
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        default:
            cout << "Invalid day" << endl;
    }

    cout << "For Loop:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "i = " << i << endl;
    }

    cout << "While Loop:" << endl;
    int j = 0;
    while (j < 5) {
        cout << "j = " << j << endl;
        j++;
    }

    cout << "Do-While Loop:" << endl;
    int k = 0;
    do {
        cout << "k = " << k << endl;
        k++;
    } while (k < 3);

    cout << "Nested If-Else Statements:" << endl;
    int num = 15;
    if (num > 0) {
        if (num % 2 == 0) {
            cout << "The number is positive and even." << endl;
        } else {
            cout << "The number is positive and odd." << endl;
        }
    } else {
        cout << "The number is not a positive number." << endl;
    }

    //checking loops with break and continue statements
    cout << "Loop with Break and Continue:" << endl;
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            cout << "Breaking the loop at i = " << i << endl;
            break;
        }
        if (i % 2 == 0) {
            cout << "Skipping even number i = " << i << endl;
            continue;
        }
        cout << "i = " << i << endl;
    }    
    cout << "Nested If-Else in Loops:" << endl;
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            cout << "i = " << i << " is even" << endl;
        } else {
            cout << "i = " << i << " is odd" << endl;
        }
    }

    cout << "Nested Loops:" << endl;
    for (int m = 0; m < 3; m++) {
        for (int n2 = 0; n2 < 2; n2++) {
            cout << "m = " << m << ", n = " << n2 << endl;
        }
    }

    cout << "Nested Loops with While and For:" << endl;
    int w = 0;
    while (w < 3) {
        for (int i = 0; i < 2; i++) {
            cout << "w = " << w << ", i = " << i << endl;
        }
        w++;
    }

    return 0;
}
