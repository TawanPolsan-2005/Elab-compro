#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef struct _point {
    double xPosition;
    double yPosition;
} point;

class Circle {
public:
    point center;
    double radius;

    Circle(point c, double r) {
        center = c;
        radius = r;
    }

    double area() {
        return M_PI * radius * radius;
    }

    double distanceFromCenter(point pt) {
        return sqrt(pow((pt.xPosition - center.xPosition), 2) + pow((pt.yPosition - center.yPosition), 2));
    }

    int contains(point pt) {
        double distance = sqrt(pow((pt.xPosition - center.xPosition), 2) + pow((pt.yPosition - center.yPosition), 2));
        return (distance <= radius) ? 1 : 0;
    }
};

int main() {
        point center, toCheck;
    double radius;

    cout << "Center of Circle: "; cin >> center.xPosition >> center.yPosition;
    cout << "Radius of Circle: "; cin >> radius;
    cout << "Point to Check: "; cin >> toCheck.xPosition >> toCheck.yPosition;

    Circle wongkom(center, radius);

    cout << "Area of Circle is " << wongkom.area() << endl;
    cout << "Distance from Center to Point (" << toCheck.xPosition << ", " << toCheck.yPosition << ") is " << wongkom.distanceFromCenter(toCheck) << endl;
    wongkom.contains(toCheck) ? cout << "This circle contains this point." : cout << "This point is not in this circle.";
}