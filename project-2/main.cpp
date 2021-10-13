#include <string>
#include <sstream>
#include "bankAccount.cpp"
using namespace std;
void mainWindow(string *account, bankAccount **accounts);

void pressEnter()
{
    // cin.ignore();
    while (cin.get() != '\n')
    {
        cin.ignore();
        cout << "Press enter to go back to the Main Window \n";
    }
}

void initialization(string *account, string *password)
{
    cout << "\nMain Window: \n"
         << "============= \n";
    cout << "Enter Your Account No: ";
    // handle non-number case
    int tmp;
    string str;
    getline(cin, str);
    stringstream(str) >> tmp;
    *account = to_string(tmp);

    cout << "Enter your password: ";
    cin >> *password;
}

bool authentication(string account, string password, bankAccount **accounts, int sizeOfAccounts)
{
    for (int i = 0; i < sizeOfAccounts; i++)
    {
        if (accounts[i]->getAccountNo() == stoi(account))
        {
            if (accounts[i]->getPassword() == password)
            {
                return true;
            }
            cout << "The password is incorrect \n";
            return false;
        }
    }
    cout << "The account does not exist \n";
    return false;
}

void displayBalance(string *account, bankAccount **accounts)
{
    int index = stoi(*account);
    double balance = accounts[index]->getBalance();
    cout << "\nMain Window --> Show Balance \n"
         << "============================================= \n"
         << "Your current balance is: $"
         << balance << "\n"
         << "--------------------------------------------- \n"
         << "Press enter to go back to the Main Window \n";
    cin.ignore();
    pressEnter();
    mainWindow(account, accounts);
}

void handleInputAmount(double *amount)
{
    string str;
    cin.ignore();
    getline(cin, str);
    stringstream(str) >> *amount;
}

void depositWindow(string *account, bankAccount **accounts)
{
    int index = stoi(*account);
    double *amount = new double();
    cout << "\nMain Window --> Deposit (Enter the following information) \n"
         << "=============================================== \n"
         << "The amount you want to deposit: ";
    handleInputAmount(amount);
    cout << "-----------------------------------------------\n";
    if (*amount <= 0)
    {
        cout << "Invalid Deposit.... Press enter to go back to the Main Window \n";
    }
    else
    {
        accounts[index]->deposit(*amount);
        cout << "Well done. This was added to your balance successfully.... Press enter to go back to the Main Window \n";
    }
    pressEnter();
    delete amount;
    mainWindow(account, accounts);
}

void withdrawWindow(string *account, bankAccount **accounts)
{
    int index = stoi(*account);
    double *amount = new double();
    cout << "\nMain Window --> Withdraw (Enter the following information)\n"
         << "===============================================\n"
         << "The amount you want to withdraw: ";
    handleInputAmount(amount);
    cout << "-----------------------------------------------\n";
    if (*amount <= 0)
    {
        cout << "Invalid Withdrawal.... Press enter to go back to the Main Window\n";
    }
    else
    {
        if (accounts[index]->withdraw(*amount))
        {
            cout << "Please take your money then.... Press enter to go back to the Main Window\n";
        }
        else
        {
            cout << "Withdrawal Failed (Insufficient Balance).... Press enter to go back to the Main Window\n";
        }
    }
    pressEnter();
    delete amount;
    mainWindow(account, accounts);
}

void showAllTransactionsWindow(string *account, bankAccount **accounts)
{
    int index = stoi(*account);
    cout << "\nMain Window --> Show All Transactions" << endl;
    cout << "============================================================================" << endl;
    cout << "\n\nAccount no: " << *account << endl;
    cout << "----------------------------------------------------------------\n"
         << "Date                            | Type             | Amount\n"
         << "----------------------------------------------------------------\n";
    accounts[index]->showAllTransactions();
    cout << "----------------------------------------------------------------\n"
         << "Press enter to go back to the Main Window\n";
    cin.ignore();
    pressEnter();
    mainWindow(account, accounts);
}

void mainWindow(string *account, bankAccount **accounts)
{
    cout << "\nMain Window" << endl;
    cout << "==============" << endl;
    cout << "Choose one of the following options:" << endl;
    cout << "(1) Show balance \n"
         << "(2) Deposit \n"
         << "(3) Withdraw \n"
         << "(4) Show All Transactions \n";
    cout << "Enter Your Choice: ";
    string option = "";
    cin >> option;
    if (option == "1")
    {
        displayBalance(account, accounts);
    }
    else if (option == "2")
    {
        depositWindow(account, accounts);
    }
    else if (option == "3")
    {
        withdrawWindow(account, accounts);
    }
    else if (option == "4")
    {
        showAllTransactionsWindow(account, accounts);
    }
    else
    {
        mainWindow(account, accounts);
    }
}

int bankAccount::count = 1;

int main()
{
    // create an array of 10 bankAccounts
    bankAccount **accounts;
    int capacity = 10;
    *accounts = new bankAccount[10];

    // create a new bankaccount with accountNo from 1 to 10, password "1234", and balance 5000
    for (int i = 0; i < 10; i++)
    {
        accounts[i] = new bankAccount("1234", 5000);
    }

    //input account and password
    string *account = new string();
    string *password = new string();

    //login window
    while (true)
    {
        initialization(account, password);
        if (authentication(*account, *password, accounts, capacity))
        {
            // cout << "logged in \n";
            break;
        }
        cin.ignore();
    }

    mainWindow(account, accounts);

    // end of the program
    delete account;
    delete password;
    for (int i = 0; i < 10; i++)
    {
        delete accounts[i];
    }

    return 0;
}

// void trimWhiteSpaces(string *account)
// {
//     if ((*account).substr(0, 1) == " ")
//     {
//         int start = 1;
//         for (int i = 1; i < (*account).length(); i++)
//         {
//             if ((*account).substr(i, i + 1) != " ")
//             {
//                 break;
//             }
//             start++;
//         }
//         *account = (*account).substr(start);
//     }
//     if ((*account).substr((*account).length() - 1) == " ")
//     {
//         int end = (*account).length() - 1;
//         for (int i = end; i > 0; i--)
//         {
//             if ((*account).substr(0, end) != " ")
//             {
//                 break;
//             }
//             end--;
//         }
//         *account = (*account).substr(0, end);
//     }
// }