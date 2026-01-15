<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 40px;
            background-color: #f9f9f9;
            color: #333;
        }
        h1, h2 {
            color: #2c3e50;
        }
        pre {
            background-color: #1e1e1e;
            color: #dcdcdc;
            padding: 20px;
            overflow-x: auto;
            border-radius: 8px;
        }
        code {
            font-family: Consolas, monospace;
            font-size: 14px;
        }
        .section {
            margin-bottom: 30px;
        }
    </style>
</head>
<body>

<h1>ATM Management System (C++)</h1>

<div class="section">
    <h2>📌 Description</h2>
    <p>
        This project is a simple <strong>ATM Management System</strong> implemented in 
        <strong>C++</strong> using <strong>Object-Oriented Programming (OOP)</strong> concepts.
        It demonstrates the use of <em>abstraction, inheritance, encapsulation, and polymorphism</em>.
    </p>
</div>

<div class="section">
    <h2>⚙️ Features</h2>
    <ul>
        <li>Check account balance</li>
        <li>Deposit money</li>
        <li>Withdraw money</li>
        <li>Menu-driven console interface</li>
        <li>Uses abstract class and virtual functions</li>
    </ul>
</div>

<div class="section">
    <h2>🛠️ Technologies Used</h2>
    <ul>
        <li>Language: C++</li>
        <li>Concepts: OOP, Abstraction, Inheritance</li>
        <li>Compiler: GCC / Any C++ Compiler</li>
    </ul>
</div>

<div class="section">
    <h2>📄 Source Code</h2>
    <pre><code>
#include &lt;iostream&gt;
using namespace std;

// Abstract Class
class ATMInterface {
public:
    virtual void checkBalance() = 0;
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual ~ATMInterface() {}
};

class BankAccount : public ATMInterface {
private:
    double balance;

public:
    BankAccount(double initialBalance = 0) {
        balance = initialBalance;
    }

    void checkBalance() override {
        cout << "Current Balance: rs " << balance << endl;
    }

    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "rs " << amount << " deposited successfully." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) override {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            balance -= amount;
            cout << "rs " << amount << " withdrawn successfully." << endl;
        }
    }
};

int main() {
    BankAccount userAccount(2000);
    int choice;
    double amount;

    do {
        cout << "\n========== ATM MENU ==========\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Balance\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            userAccount.checkBalance();
            break;
        case 2:
            cout << "Enter amount to deposit: rs ";
            cin >> amount;
            userAccount.deposit(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: rs ";
            cin >> amount;
            userAccount.withdraw(amount);
            break;
        case 4:
            cout << "Thank you for using the ATM!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
    </code></pre>
</div>

<div class="section">
    <h2>▶️ How to Run</h2>
    <ol>
        <li>Copy the code into a file named <strong>atm.cpp</strong></li>
        <li>Compile using: <code>g++ atm.cpp -o atm</code></li
