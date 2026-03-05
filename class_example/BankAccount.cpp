#include "BankAccount.h"
// .cpp 文件通常放“定义/实现”：把头文件里声明的函数真正写出来。

#include <iomanip>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <utility>

int BankAccount::liveAccounts_ = 0; // [static成员变量定义]
// 注意：static 成员变量要在某一个 .cpp 里“定义一次”，否则链接会报错。

// [构造函数]：创建对象时保证不变量成立
BankAccount::BankAccount(std::string owner, std::string accountNo, long long initialCents)
    // 成员初始化列表（: ...）：在进入函数体前初始化成员变量（推荐做法）
    : owner_(std::move(owner)), accountNo_(std::move(accountNo)), balanceCents_(initialCents) {
    // std::move：把参数里的字符串“移动”到成员里（避免不必要拷贝，提升效率）
    if (owner_.empty()) {
        throw std::invalid_argument("owner cannot be empty"); // [exception]
    }
    if (accountNo_.empty()) {
        throw std::invalid_argument("account number cannot be empty");
    }
    if (initialCents < 0) {
        throw std::invalid_argument("initial balance cannot be negative");
    }
    ++liveAccounts_; // [static成员变量]：统计当前存活账户数
}

// [析构函数]：对象生命周期结束时做清理/计数
BankAccount::~BankAccount() {
    --liveAccounts_;
}

// [const成员函数]：承诺不修改对象状态
const std::string& BankAccount::owner() const {
    return owner_;
}

const std::string& BankAccount::accountNo() const {
    return accountNo_;
}

long long BankAccount::balanceCents() const {
    return balanceCents_;
}

int BankAccount::liveAccounts() {
    return liveAccounts_;
}

// [成员函数/行为]：存款
void BankAccount::deposit(long long cents) {
    if (cents <= 0) {
        throw std::invalid_argument("deposit amount must be positive");
    }
    balanceCents_ += cents;
}

// [成员函数/行为]：取款（失败抛异常）
void BankAccount::withdraw(long long cents) {
    if (cents <= 0) {
        throw std::invalid_argument("withdraw amount must be positive");
    }
    if (cents > balanceCents_) {
        throw std::runtime_error("insufficient funds");
    }
    balanceCents_ -= cents;
}

// [引用参数]：fromAccount.transferTo(toAccount, amount)
void BankAccount::transferTo(BankAccount& to, long long cents) {
    if (this == &to) {
        // this is a pointer to the current object; &to gets address of `to`
        throw std::invalid_argument("cannot transfer to self");
    }
    // 先扣再加：保持任何时刻余额不为负（不变量）
    withdraw(cents);
    to.deposit(cents);
}

// [业务行为]：月结计息
void BankAccount::settleMonthlyInterest(double rate) {
    if (rate < 0.0) {
        throw std::invalid_argument("interest rate cannot be negative");
    }

    // 以“分”为单位计算，避免浮点累计误差；四舍五入到分
    const double interest = static_cast<double>(balanceCents_) * rate;
    // static_cast<double>(balanceCents_)：显式类型转换（long long -> double）
    const long long interestCents = static_cast<long long>(interest + 0.5);
    balanceCents_ += interestCents;
}

// [const成员函数]：打印账户信息
void BankAccount::print(std::ostream& os) const {
    os << "Account(" << accountNo_ << ") "
       << "Owner=" << owner_ << ", "
       << "Balance=" << formatCents(balanceCents_) << "\n";
}

// [私有工具函数]：类内部复用
std::string BankAccount::formatCents(long long cents) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << (static_cast<double>(cents) / 100.0);
    return oss.str();
}
