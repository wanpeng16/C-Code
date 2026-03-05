#pragma once
// 头文件（.h）通常放“声明”：让其它.cpp知道类长什么样、有哪些函数可以用。
// #pragma once 表示该头文件在一次编译中只会被包含一次，避免重复定义错误。

#include <iosfwd>
#include <string>

// class 声明：描述一个“账户”类型（对象=类的实例）。
class BankAccount {
public:
    // public 区域：对外公开的接口（别人能调用的函数）。
    // [构造函数]：创建对象时保证不变量成立
    BankAccount(std::string owner, std::string accountNo, long long initialCents = 0);

    // [析构函数]：对象生命周期结束时做清理/计数
    ~BankAccount();

    // 禁止拷贝：演示一种常见做法——有些类不希望被“复制”出两个账户对象。
    // = delete 的含义是：如果代码尝试拷贝/赋值，编译器直接报错。
    BankAccount(const BankAccount&) = delete;
    BankAccount& operator=(const BankAccount&) = delete;

    // [const成员函数]：承诺不修改对象状态
    const std::string& owner() const;
    const std::string& accountNo() const;
    long long balanceCents() const;

    // static 成员函数：不依赖某一个具体对象，也可以通过 BankAccount::liveAccounts() 调用。
    static int liveAccounts(); // [static成员函数]

    // [成员函数/行为]：存款
    void deposit(long long cents);

    // [成员函数/行为]：取款（失败抛异常）
    void withdraw(long long cents);

    // 引用参数 BankAccount&：传入“同一个对象本身”，避免拷贝，也能直接修改对方账户。
    // [引用参数]：fromAccount.transferTo(toAccount, amount)
    void transferTo(BankAccount& to, long long cents);

    // [业务行为]：月结计息
    // rate 如 0.003 表示月利率0.3%
    void settleMonthlyInterest(double rate);

    // [const成员函数]：打印账户信息
    void print(std::ostream& os) const;

private:
    // private 区域：类的内部实现细节（外部不能直接访问这些数据），体现“封装”。
    // [封装/属性]：用private隐藏数据，只允许通过public行为修改
    std::string owner_;
    std::string accountNo_;
    long long balanceCents_ = 0; // 余额（分）

    // [static成员变量]：所有对象共享
    static int liveAccounts_;

    // [私有工具函数]：类内部复用
    static std::string formatCents(long long cents);
};
