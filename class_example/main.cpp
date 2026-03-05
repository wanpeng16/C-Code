#include <iostream>
#include <stdexcept>
#include <locale>
#ifdef _WIN32
#include <windows.h>
#endif

// "BankAccount.h" 是我们自己的头文件（双引号表示先在当前工程目录找）

#include "BankAccount.h"

int main() {
    // enable UTF-8 console I/O on Windows and set global locale
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    std::ios::sync_with_stdio(false);
    std::locale::global(std::locale(""));

    // try/catch：捕获运行时异常，避免程序直接崩溃
    try {
        // 创建对象（类的实例）：调用构造函数
        BankAccount a("Zhang San", "A-0001", 10000); // 100.00
        BankAccount b("Li Si", "B-0002", 5000);  // 50.00

        // 通过 类名::函数名 调用 static 成员函数（不依赖某个对象）
        std::cout << "Current live accounts" << BankAccount::liveAccounts() << "\n\n";

        // 1) 存款
        a.deposit(2'500); // +25.00
        std::cout << "[After deposit]\n";
        a.print(std::cout);
        b.print(std::cout);
        std::cout << "\n";

        // 2) 取款失败（演示异常）
        // 这里再套一层 try/catch：只处理“取款失败”这一段的异常，让程序继续往下运行
        try {
            b.withdraw(100'00); // 取100.00，余额不足
        } catch (const std::exception& e) {
            std::cout << "[Withdraw failed] " << e.what() << "\n\n";
        }

        // 3) 转账
        a.transferTo(b, 3'000); // a -> b 转30.00
        std::cout << "[After transfer]\n";
        a.print(std::cout);
        b.print(std::cout);
        std::cout << "\n";

        // 4) 月结计息
        const double monthlyRate = 0.003; // 0.3%
        a.settleMonthlyInterest(monthlyRate);
        b.settleMonthlyInterest(monthlyRate);
        std::cout << "[After monthly interest]\n";
        a.print(std::cout);
        b.print(std::cout);

        std::cout << "\n" << "Live accounts before exit=" << BankAccount::liveAccounts() << "\n";
    } catch (const std::exception& e) {
        // 统一捕获：任何没被处理的异常都会到这里
        std::cerr << "Fatal error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
