#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    char name1[50], name2[50];
    int age1, age2;
    double salary1, salary2;

    // ===== 第一组输入 =====
    cout << "请输入第1组：年龄 月薪 姓名(可含空格)\n";
    cin >> age1 >> salary1;
    cin.ignore(1000, '\n');     // 清除换行
    cin.getline(name1, 50);

    // ===== 第二组输入 =====
    cout << "请输入第2组：年龄 月薪 姓名(可含空格)\n";
    cin >> age2 >> salary2;
    cin.ignore(1000, '\n');     // 清除换行
    cin.getline(name2, 50);

    // ===== 表格输出 =====
    cout << "\n================ 输出结果 ================\n";

    cout << left
         << setw(20) << "姓名"
         << right
         << setw(15) << "年龄"
         << setw(15) << "月薪"
         << "\n";

    cout << fixed << setprecision(2);

    cout << left
         << setw(20) << name1
         << right
         << setw(10) << age1
         << setw(15) << salary1
         << endl;

    cout << left
         << setw(20) << name2
         << right
         << setw(10) << age2
         << setw(15) << salary2
         << endl;

    // ===== 精度对比演示 =====
    cout << "\n===== 精度对比 =====\n";

    cout << "默认有效数字(4位): "
         << setprecision(4) << salary1 << endl;

    cout << "fixed 小数2位: "
         << fixed << setprecision(2) << salary1 << endl;

    cout << "scientific 科学计数法: "
         << scientific << setprecision(3) << salary1 << endl;

    return 0;
}