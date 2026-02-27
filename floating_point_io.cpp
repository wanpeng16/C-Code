#include <iostream>
using namespace std;

int main()
{
    double length, width, area;

    cout << "请输入矩形的长度：";
    cin >> length;
    cout << "请输入矩形的宽度：";
    cin >> width;
    area = length * width;
    cout << "面积是 " << area << endl;
    return 0;
}
