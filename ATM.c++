#include <iostream>
#include <fstream>
#include <ctime>
#include <map>
using namespace std;

struct User {
    int pin;
    int balance;
};

map<int, User> users = {
    {101, {1234, 100000}},
    {102, {4321, 50000}},
    {103, {1111, 70000}}
};

int currentUserID;

string getCurrentDateTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    string formattedTime = string(dt);
    formattedTime.pop_back();
    return formattedTime;
}

void logTransaction(const string& message) {
    string filename = to_string(currentUserID) + "_transactions.txt";
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "[" << getCurrentDateTime() << "] " << message << endl;
        file.close();
    } else {
        cout << "Unable to log transaction!" << endl;
    }
}

void showTransactionHistory() {
    string filename = to_string(currentUserID) + "_transactions.txt";
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        cout << "\n--- Transaction History for User ID " << currentUserID << " ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
        cout << "--------------------------------------------\n";
    } else {
        cout << "No transaction history found.\n";
    }
}

void withdrawMoney(User &user) {
    int withdraw;
    cout << "Enter money to be withdrawn: ";
    cin >> withdraw;

    if (user.balance >= withdraw) {
        user.balance -= withdraw;
        cout << "Please collect your money\n";
        logTransaction("Withdrawn Rs." + to_string(withdraw));
    } else {
        cout << "Insufficient Balance\n";
    }
}

void depositMoney(User &user) {
    int deposit;
    cout << "Enter money to be deposited: ";
    cin >> deposit;

    user.balance += deposit;
    cout << "Your Money has been successfully deposited\n";
    logTransaction("Deposited Rs." + to_string(deposit));
}

void checkBalance(User &user) {
    cout << "Current Balance: Rs." << user.balance << endl;
    logTransaction("Checked Balance");
}

void displayMenu() {
    cout << "\n===== ATM Menu =====" << endl;
    cout << "1. Withdraw\n2. Deposit\n3. Check Balance\n4. Show Transaction History\n5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int userID, enteredPIN, attempts = 0, maxAttempts = 3;

    cout << "Welcome to Shivam's Smart ATM \n\n";
    cout << "Enter User ID: ";
    cin >> userID;

    if (users.find(userID) == users.end()) {
        cout << "User not found.\n";
        return 0;
    }

    currentUserID = userID;
    User &current = users[userID];

    while (attempts < maxAttempts) {
        cout << "Enter 4-digit PIN: ";
        cin >> enteredPIN;

        if (enteredPIN == current.pin) {
            cout << "\nLogin successful. Welcome, User ID " << userID << "!\n";
            logTransaction("User logged in");
            break;
        } else {
            attempts++;
            cout << "Incorrect PIN. Attempts left: " << maxAttempts - attempts << "\n";
        }
    }

    if (attempts == maxAttempts) {
        cout << "Too many failed attempts. Access blocked.\n";
        return 0;
    }

    int choice;
    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                withdrawMoney(current);
                break;
            case 2:
                depositMoney(current);
                break;
            case 3:
                checkBalance(current);
                break;
            case 4:
                showTransactionHistory();
                break;
            case 5:
                logTransaction("User logged out");
                cout << "Thank you for using our ATM. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}