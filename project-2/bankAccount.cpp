#include <iostream>
#include "transaction.cpp"
using namespace std;

class bankAccount
{
private:
    int accountNo;
    string password;
    double balance;
    // dynamic array needs to be expanded if necessary
    transaction *transactions;
    int capacity;
    int actual_size;

public:
    static int count;
    bankAccount()
    {
        capacity = 5;
        actual_size = 0;
        transactions = new transaction[capacity];
        password = "";
        balance = 0.0;
    }
    bankAccount(string newPassword, double newBalance)
    {
        capacity = 5;
        actual_size = 0;
        accountNo = count++;
        password = newPassword;
        balance = newBalance;
        transactions = new transaction[capacity];
    }
    bankAccount(bankAccount &anotherBankAccount)
    {
        capacity = anotherBankAccount.capacity;
        actual_size = anotherBankAccount.actual_size;
        accountNo = anotherBankAccount.accountNo;
        password = anotherBankAccount.password;
        balance = anotherBankAccount.balance;
        transactions = new transaction[capacity];
        *transactions = *(anotherBankAccount.transactions);
    }
    ~bankAccount()
    {
        delete[] transactions;
        // cout << "account deleted \n";
    }
    int getAccountNo()
    {
        return accountNo;
    }
    string getPassword()
    {
        return password;
    }
    double getBalance()
    {
        return balance;
    }
    void deposit(double amount)
    {
        balance += amount;
        addTransaction("deposit", amount);
    }
    // true: successfully withdrawal
    bool withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance = balance - amount;
            addTransaction("withdraw", amount);
            return true;
        }
        else
        {
            return false;
        }
    }
    void addTransaction(string type, double amount)
    {
        if (actual_size == capacity)
        {
            capacity *= 2;
            transaction *tmp = new transaction[capacity];
            for (int i = 0; i < actual_size; i++)
            {
                tmp[i] = transactions[i];
            }
            delete[] transactions;
            transactions = tmp;
        }
        transactions[actual_size] = transaction(type, amount);
        actual_size++;
    }
    void showAllTransactions()
    {
        for (int i = 0; i < actual_size; i++)
        {
            transaction tmp = transactions[i];
            string date = tmp.getDate();
            string type = tmp.getType();
            double amount = tmp.getAmount();
            cout << date << "        | " << type << "          | " << amount << "\n";
        }
    }
};

// int bankAccount::count = 1;

// int main()
// {
//     // bankAccount *b1 = new bankAccount("1", "1234", 5000);
//     // bankAccount *b2 = new bankAccount("2", "1234", 5000);
//     bankAccount *b5;
//     b5 = new bankAccount("1234", 5000);
//     cout << b5->getAccountNo() << "\n";
//     b5->withdraw(200);
//     cout << b5->getAccountNo() << "\n";
//     bankAccount *b6;
//     b6 = new bankAccount("1234", 5000);
//     cout << b6->getAccountNo() << "\n";
//     b5->withdraw(200);
//     cout << b6->getAccountNo() << "\n";
//     // delete b1;
//     // delete b2;
//     delete b5;
// }