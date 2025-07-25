# 💳 ATM System in C++

A console-based ATM simulation built in C++ that supports:

- 🔐 PIN-based user login  
- 👥 Multi-user support  
- 📜 Transaction logging (deposit & withdrawal history saved to a .txt file)

---

## 📁 File Structure


---

## 🧑‍💻 Features

- Secure login with a PIN (default users pre-configured)
- Option to withdraw and deposit money
- Transaction logs saved to a file for tracking
- Easily extendable to add more users

---

## 🚀 How to Run

### 🛠 Prerequisites
- C++ compiler (like g++)
- Terminal or command prompt


⚙ Compile the Code
- g++ ATM.cpp -o atm


▶ Run the Executable
- ./atm


📝 Sample Output
- Welcome to the ATM System!
- Enter your User ID: 101
- Enter your PIN: ****

Login successful!

--- Menu ---
1. Check Balance
2. Deposit Money
3. Withdraw Money
4. Exit

- Enter your choice: 2
- Enter amount to deposit: 5000
- Deposit successful. New balance: 15000


📄 Transaction Log
- [101] Deposited: 5000 | Balance: 15000
- [102] Withdrawn: 2000 | Balance: 8000


🙌 Contributing
Pull requests are welcome! If you'd like to suggest improvements, feel free to fork the repo and submit a PR.


📬 Contact
- Created with ❤ by Shivam
📧 90.shivam.patel.26@gmail.com
