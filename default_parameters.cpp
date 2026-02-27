#include <iostream>
using namespace std;

// 函数原型（带默认参数）
void displayStars(int cols = 10, int rows = 1);

int main()
{
    displayStars();        // 使用两个默认值
    displayStars(5);       // cols = 5, rows 使用默认值 1
    displayStars(7, 3);    // 两个参数都指定

    return 0;
}

// 函数定义（不能再写默认值）
void displayStars(int cols, int rows)
{
    for (int down = 0; down < rows; down++) 
    {
        for (int across = 0; across < cols; across++)
        {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
}