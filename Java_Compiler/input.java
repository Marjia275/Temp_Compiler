import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Basic Java keywords, data types, and control flow
        int n = 100;
        float f1 = 1.0f;
        char c1 = 'A';
        boolean flag = true;

        int _123djf = 10; // Valid variable name

        // int 123djf = 10; // Invalid variable name -- illegal in real Java too (identifiers cannot start with a digit); left commented out intentionally.

        String greeting = "Hello";

        final int MAX = 100;
        System.out.println("The constant MAX is: " + MAX);

        System.out.println("Basic Java subset test");

        System.out.print("Enter an integer: ");
        n = sc.nextInt();

        System.out.print("Enter a float: ");
        f1 = sc.nextFloat();

        System.out.print("Enter a character: ");
        c1 = sc.next().charAt(0);

        System.out.println("Your entered integer is: " + n);
        System.out.println("Your entered float is: " + f1);
        System.out.println("Your entered character is: " + c1);
        System.out.println("Your entered bool is: " + flag);
        System.out.println("Your entered string is: " + greeting);

        int n1 = 104;
        System.out.println("The value of n1 is: " + n1);

        int x = 10;
        x += 5;
        System.out.println("x after += 5: " + x);

        x -= 3;
        System.out.println("x after -= 3: " + x);

        x *= 2;
        System.out.println("x after *= 2: " + x);

        x /= 4;
        System.out.println("x after /= 4: " + x);

        System.out.println("Comparison Operators:");

        int p = 10;
        int q = 20;

        System.out.println("p == q: " + (p == q));
        System.out.println("p != q: " + (p != q));
        System.out.println("p > q: " + (p > q));
        System.out.println("p < q: " + (p < q));

        System.out.println("Logical Operators:");

        int r = 1;
        int s = 0;

        System.out.println("r && s: " + ((r != 0) && (s != 0)));
        System.out.println("r || s: " + ((r != 0) || (s != 0)));
        System.out.println("!r: " + (!(r != 0)));

        System.out.println("Bitwise Operators:");

        int t = 5;

        System.out.println("t & 3: " + (t & 3));
        System.out.println("t | 3: " + (t | 3));
        System.out.println("t ^ 3: " + (t ^ 3));
        System.out.println("~t: " + (~t));
        System.out.println("t << 1: " + (t << 1));
        System.out.println("t >> 1: " + (t >> 1));

        System.out.println("String concatenation:");

        System.out.print("Enter first string: ");
        String st1 = sc.next();

        System.out.print("Enter second string: ");
        String st2 = sc.next();

        String st3 = st1 + " " + st2;

        System.out.println("Concatenated string: " + st3);

        int a = 10;
        int b = 20;

        int max = (a > b) ? a : b;

        System.out.println("Max of a and b: " + max);

        System.out.println("Flow control (if/else):");

        int age = 2;

        if (age >= 18) {
            System.out.println("You are an adult.");
        } else if (age >= 13) {
            System.out.println("You are a teenager.");
        } else {
            System.out.println("You are a child.");
        }

        int day = 3;

        switch (day) {
            case 1:
                System.out.println("Monday");
                break;
            case 2:
                System.out.println("Tuesday");
                break;
            case 3:
                System.out.println("Wednesday");
                break;
            case 4:
                System.out.println("Thursday");
                break;
            case 5:
                System.out.println("Friday");
                break;
            default:
                System.out.println("Invalid day");
        }

        System.out.println("For Loop:");

        for (int i = 0; i < 10; i++) {
            System.out.println("i = " + i);
        }

        System.out.println("While Loop:");

        int j = 0;

        while (j < 5) {
            System.out.println("j = " + j);
            j++;
        }

        System.out.println("Do-While Loop:");

        int k = 0;

        do {
            System.out.println("k = " + k);
            k++;
        } while (k < 3);

        System.out.println("Nested If-Else Statements:");

        int num = 15;

        if (num > 0) {
            if (num % 2 == 0) {
                System.out.println("The number is positive and even.");
            } else {
                System.out.println("The number is positive and odd.");
            }
        } else {
            System.out.println("The number is not a positive number.");
        }

        System.out.println("Loop with Break and Continue:");

        for (int i = 0; i < 10; i++) {

            if (i == 5) {
                System.out.println("Breaking the loop at i = " + i);
                break;
            }

            if (i % 2 == 0) {
                System.out.println("Skipping even number i = " + i);
                continue;
            }

            System.out.println("i = " + i);
        }

        System.out.println("Nested If-Else in Loops:");

        for (int i = 0; i < 5; i++) {
            if (i % 2 == 0) {
                System.out.println("i = " + i + " is even");
            } else {
                System.out.println("i = " + i + " is odd");
            }
        }

        System.out.println("Nested Loops:");

        for (int m = 0; m < 3; m++) {
            for (int n2 = 0; n2 < 2; n2++) {
                System.out.println("m = " + m + ", n = " + n2);
            }
        }

        System.out.println("Nested Loops with While and For:");

        int w = 0;

        while (w < 3) {
            for (int i = 0; i < 2; i++) {
                System.out.println("w = " + w + ", i = " + i);
            }
            w++;
        }

        sc.close();
    }
}
