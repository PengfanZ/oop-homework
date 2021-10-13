#include <iostream>
#include <ctime>
using namespace std;

class transaction
{
private:
    string date;
    string type;
    double amount;

public:
    // constructor
    transaction(string newType, double newAmount)
    {
        setDate();
        type = newType;
        amount = newAmount;
    }
    transaction()
    {
        setDate();
        type = "";
        amount = 0.0;
    }
    transaction(transaction &anothertransaction)
    {
        // cout << "copy constructor \n";
        date = anothertransaction.date;
        type = anothertransaction.type;
        amount = anothertransaction.amount;
    }
    string getDate()
    {
        return date;
    }
    void setDate()
    {
        time_t now = time(0);
        string dt = ctime(&now);
        dt = dt.substr(0, dt.length() - 1);
        date = dt;
    }
    void setType(string newType)
    {
        type = newType;
    }
    void setAmount(double newAmount)
    {
        amount = newAmount;
    }
    string getType()
    {
        return type;
    }
    double getAmount()
    {
        return amount;
    }
};