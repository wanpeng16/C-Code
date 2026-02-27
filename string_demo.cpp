#include <iostream>
#include <string>
using namespace std;

int main() {
    // 1. 声明和初始化字符串
    string s1 = "Hello";
    string s2("World");
    string s3 = s1 + " " + s2;  // 拼接
    cout << "1. 拼接结果: " << s3 << endl;

    // 2. 输入字符串
    string input;
    cout << "2. 请输入一个字符串: ";
    getline(cin, input);
    cout << "   你输入了: " << input << endl;

    // 3. 字符串长度
    cout << "3. 字符串长度: " << input.length() << endl;

    // 4. 访问字符
    if (!input.empty()) {
        cout << "4. 第一个字符: " << input[0] << endl;
        cout << "   最后一个字符: " << input.back() << endl;
    }

    // 5. 子串
    if (input.length() > 3) {
        string sub = input.substr(0, 3);
        cout << "5. 前3个字符的子串: " << sub << endl;
    }

    // 6. 查找
    size_t pos = input.find("a");
    if (pos != string::npos) {
        cout << "6. 'a' 第一次出现的位置: " << pos << endl;
    } else {
        cout << "6. 字符串中没有 'a'" << endl;
    }

    // 7. 替换
    string replaced = input;
    size_t replace_pos = replaced.find(" ");
    if (replace_pos != string::npos) {
        replaced.replace(replace_pos, 1, "_");
        cout << "7. 替换空格为下划线: " << replaced << endl;
    } else {
        cout << "7. 没有空格可替换" << endl;
    }

    // 8. 比较
    string comp1 = "apple";
    string comp2 = "banana";
    if (comp1 < comp2) {
        cout << "8. " << comp1 << " 字典序小于 " << comp2 << endl;
    }

    // 9. 转换为大写（简单示例，使用循环）
    string upper = input;
    for (char &c : upper) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
    }
    cout << "9. 转换为大写: " << upper << endl;

    // 10. 清空字符串
    string temp = "临时字符串";
    cout << "10. 清空前: " << temp << endl;
    temp.clear();
    cout << "    清空后: 长度=" << temp.length() << endl;

    return 0;
}
