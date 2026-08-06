#include <iostream>
using namespace std;

int main() {
    int i;
    int sum;
    sum = 0;
    for (i = 1; i <= 5; i++) {
        sum = sum + i;
    }
    cout << sum << endl;
    return 0;
}