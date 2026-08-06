#include<stdio.h>
#include<math.h>

int main()
{
    // ---------------- Data types ----------------
    const int MAX = 100;
    const float PI = 3.14;
    const char GRADE = 'A';

    int n = 100;
    float f1 = 1.0;
    double d1 = 2.0;
    char c1 = 'A';
    long long ll1 = 1000000000000;

    printf("MAX=%d PI=%f GRADE=%c\n", MAX, PI, GRADE);
    printf("n=%d f1=%f d1=%lf c1=%c ll1=%lld\n", n, f1, d1, c1, ll1);

    // ------------------error checking----------------
    //int 1nm = 10; // Invalid variable name, cannot start with a digit
    int nm = 'a';
   

    // ---------------- scanf ----------------
    int age;
    printf("Enter an integer: ");
    scanf("%d", &age);
    printf("Your entered integer is: %d\n", age);
    float f2;
    printf("Enter a float: ");
    scanf("%f", &f2);
    printf("Your entered float is: %f\n", f2);
    double d2;
    printf("Enter a double: ");
    scanf("%lf", &d2);
    printf("Your entered double is: %lf\n", d2);
    char c2;
    printf("Enter a character: ");
    scanf(" %c", &c2);
    printf("Your entered character is: %c\n", c2);  
    long long ll2;
    printf("Enter a long long: ");
    scanf("%lld", &ll2);
    printf("Your entered long long is: %lld\n", ll2);

    // ---------------- sizeof ----------------
    printf("Size of int: %d\n", sizeof(int));
    printf("Size of float: %d\n", sizeof(float));
    printf("Size of double: %d\n", sizeof(double));
    printf("Size of char: %d\n", sizeof(char));
    printf("Size of long long: %d\n", sizeof(long long));
    int szvar;
    printf("Size of szvar: %d\n", sizeof(szvar));

    // ---------------- multiple variable declaration ----------------
    int a, b, c;
    a = 1; b = 2; c = 3;
    printf("a=%d b=%d c=%d\n", a, b, c);

    int x = 1, y = 2, z = 3;
    printf("x=%d y=%d z=%d\n", x, y, z);

    float p = 1.2, q = 3.4;
    printf("p=%f q=%f\n", p, q);

    // ---------------- assignment operators ----------------
    x += 5; printf("x after += 5: %d\n", x);
    x -= 3; printf("x after -= 3: %d\n", x);
    x *= 2; printf("x after *= 2: %d\n", x);
    x /= 4; printf("x after /= 4: %d\n", x);
    x%= 3; printf("x after %= 3: %d\n", x);

    // ---------------- comparison operators ----------------
    int pcmp = 10, qcmp = 20;
    printf("p == q: %d\n", pcmp == qcmp);
    printf("p != q: %d\n", pcmp != qcmp);
    printf("p > q: %d\n", pcmp > qcmp);
    printf("p < q: %d\n", pcmp < qcmp);

    // ---------------- logical operators ----------------
    int r = 1, s = 0;
    printf("r && s: %d\n", r && s);
    printf("r || s: %d\n", r || s);
    printf("!r: %d\n", !r);

    // ---------------- bitwise operators ----------------
    int t = 5, u = 3;
    printf("t & u: %d\n", t & u);
    printf("t | u: %d\n", t | u);
    printf("t ^ u: %d\n", t ^ u);
    printf("~t: %d\n", ~t);
    printf("t << 1: %d\n", t << 1);
    printf("t >> 1: %d\n", t >> 1);

    // ---------------- ternary operator ----------------
    int v = 10, w = 20;
    int max = (v > w) ? v : w;
    printf("Max of v and w: %d\n", max);

    // ---------------- if / nested if-else ----------------
    int age2 = 15;
    if (age2 >= 18) {
        printf("You are an adult.\n");
    } else {
        if (age2 >= 13) {
            printf("You are a teenager.\n");
        } else {
            printf("You are a child.\n");
        }
    }

    // ---------------- switch ----------------
    int day = 3;
    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        default:
            printf("Invalid day\n");
    }

    // switch with fallthrough + nested switch
    int outer = 1;
    switch (outer) {
        case 1:
            printf("outer case 1\n");
            switch (day) {
                case 3:
                    printf("nested case 3\n");
                    break;
                default:
                    printf("nested default\n");
            }
            break;
        default:
            printf("outer default\n");
    }

    // ---------------- for loop with break/continue ----------------
    printf("For Loop:\n");
    for (int i = 0; i < 10; i++) {
        if (i == 5) { break; }
        if (i % 2 == 0) { continue; }
        printf("i = %d\n", i);
    }

    // ---------------- while loop with break/continue ----------------
    printf("While Loop:\n");
    int j = 0;
    while (j < 10) {
        j++;
        if (j == 7) { break; }
        if (j % 2 == 0) { continue; }
        printf("j = %d\n", j);
    }

    // ---------------- do-while loop ----------------
    printf("Do-While Loop:\n");
    int k = 0;
    do {
        printf("k = %d\n", k);
        k++;
    } while (k < 5);

    // do-while with break/continue
    printf("Do-While with break/continue:\n");
    int m = 0;
    do {
        m++;
        if (m == 4) { continue; }
        if (m == 8) { break; }
        printf("m = %d\n", m);
    } while (m < 10);

    // ---------------- nested loops ----------------
    printf("Nested Loops:\n");
    for (int mi = 0; mi < 3; mi++) {
        for (int ni = 0; ni < 2; ni++) {
            printf("m = %d, n = %d\n", mi, ni);
        }
    }

    // ---------------- math functions ----------------
    printf("sqrt(25) = %d\n", sqrt(25));
    printf("pow(2,3) = %d\n", pow(2, 3));
    printf("abs(-10) = %d\n", abs(-10));
    printf("ceil(4.2) = %d\n", ceil(4.2));
    printf("floor(4.8) = %d\n", floor(4.8));
   


    return 0;
}
