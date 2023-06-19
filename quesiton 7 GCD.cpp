#include <iostream>
using namespace std;

int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd_recursive(b, a % b);
}
int gcd_iterative(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is " << gcd_recursive(a, b) << endl;
    cout << "GCD of " << a << " and " << b << " is " << gcd_iterative(a, b) << endl;
    
    return 0;
}