#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
    double a, b, c;
public:
    Triangle(double s1, double s2, double s3) {
        if (s1 <= 0 || s2 <= 0 || s3 <= 0)
            throw "Invalid side length(s)! Sides must be greater than 0.";
        if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1)
            throw "Invalid side lengths! Sum of any two sides must be greater than the third side.";
        a = s1;
        b = s2;
        c = s3;
    }

    double getPerimeter() const {
        return a + b + c;
    }

    double getArea() const {
        double s = getPerimeter() / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double getArea(double base, double height) const {
        if (base <= 0 || height <= 0)
            throw "Invalid base or height! Base and height must be greater than 0.";
        return 0.5 * base * height;
    }
};

int main() {
    try {
        Triangle t1(3, 4, 5);
        cout << "Perimeter: " << t1.getPerimeter() << endl;
        cout << "Area using Heron's formula: " << t1.getArea() << endl;
        cout << "Area of right-angled triangle: " << t1.getArea(3, 4) << endl;

        Triangle t2(-2, 5, 7); // Invalid side length(s)!
        //Triangle t2(1, 1, 10); // Invalid side lengths! Sum of any two sides must be greater than the third side.
    }
    catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }
    return 0;
}
