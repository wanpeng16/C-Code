#include <iostream>
#include <iomanip>
using namespace std;

// 1️⃣ 计算圆面积
double area(double r) {
    cout << "[调用：计算圆面积]" << endl;
    return 3.1415926 * r * r;
}

// 2️⃣ 计算矩形面积
double area(double w, double h) {
    cout << "[调用：计算矩形面积]" << endl;
    return w * h;
}

// 3️⃣ 计算三角形面积
double area(int base, int height) {
    cout << "[调用：计算三角形面积]" << endl;
    return 0.5 * base * height;
}

int main() {

    cout << fixed << setprecision(2);

    cout << "area(2.5) = " << area(2.5) << "\n\n";

    cout << "area(4.2, 3.0) = " << area(4.2, 3.0) << "\n\n";

    cout << "area(6, 5) = " << area(6, 5) << "\n\n";


    return 0;
}