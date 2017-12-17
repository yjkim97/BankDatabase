# The Dank Bank Database

The Dank Bank Database allows users to create a bank account, deposit/withdraw funds, and transfer funds throughout users.

## Table of Contents

* [Installation and running the application](#install)
* [User Guide](#user)
* [Sample Run](#test)

## Installation and running the application <a name="install"></a>

First, clone or download a copy of the [Dank Bank Database](https://github.com/yjkim97/BankDatabase).

Second, cd to the appropriate folder and run the following lines of code:

```
gcc -c main.c
gcc main.o -o DankBank
./DankBank
```

## User Guide <a name="user"></a>

The Dank Bank Database utilizes the file "save.txt" as a source to store database information. For the best results, ensure that this file is empty.

Once starting the application, the menu will prompt the user to choose between 3 options. 

```
_______          ______         __    __        __    __
|       \        /      \       |  \  |  \      |  \  /  \
| $$$$$$$\      |  $$$$$$\      | $$\ | $$      | $$ /  $$
| $$  | $$      | $$__| $$      | $$$\| $$      | $$/  $$
| $$  | $$      | $$    $$      | $$$$\ $$      | $$  $$
| $$  | $$      | $$$$$$$$      | $$\$$ $$      | $$$$$\
| $$__/ $$      | $$  | $$      | $$ \$$$$      | $$ \$$\
| $$    $$      | $$  | $$      | $$  \$$$      | $$  \$$\
\$$$$$$$        \$$   \$$       \$$   \$$       \$$   \$$

_______          ______         __    __        __    __
|       \        /      \       |  \  |  \      |  \  /  \
| $$$$$$$\      |  $$$$$$\      | $$\ | $$      | $$ /  $$
| $$__/ $$      | $$__| $$      | $$$\| $$      | $$/  $$
| $$    $$      | $$    $$      | $$$$\ $$      | $$  $$
| $$$$$$$\      | $$$$$$$$      | $$\$$ $$      | $$$$$\
| $$__/ $$      | $$  | $$      | $$ \$$$$      | $$ \$$\
| $$    $$      | $$  | $$      | $$  \$$$      | $$  \$$\
\$$$$$$$        \$$   \$$       \$$   \$$       \$$   \$$

Welcome to the Dank Bank Database. Please choose an option.
1. Login to an existing account
2. Make a conversion
3. Exit the program
=>>
```

Option 1 will allow the user to log in to any existing accounts. Enter the number "1" and log in using the following credentials:

**Username:** admin

**Password:** adminpass

This is the administrative account. This account has access to creating and deleting accounts.

Once you have created a few of your own accounts, head back to the main menu and log in with your newly made username and passwords to get started.

## Sample Run <a name="test"></a>
Sample run of the code:

```
_______          ______         __    __        __    __
|       \        /      \       |  \  |  \      |  \  /  \
| $$$$$$$\      |  $$$$$$\      | $$\ | $$      | $$ /  $$
| $$  | $$      | $$__| $$      | $$$\| $$      | $$/  $$
| $$  | $$      | $$    $$      | $$$$\ $$      | $$  $$
| $$  | $$      | $$$$$$$$      | $$\$$ $$      | $$$$$\
| $$__/ $$      | $$  | $$      | $$ \$$$$      | $$ \$$\
| $$    $$      | $$  | $$      | $$  \$$$      | $$  \$$\
\$$$$$$$        \$$   \$$       \$$   \$$       \$$   \$$

_______          ______         __    __        __    __
|       \        /      \       |  \  |  \      |  \  /  \
| $$$$$$$\      |  $$$$$$\      | $$\ | $$      | $$ /  $$
| $$__/ $$      | $$__| $$      | $$$\| $$      | $$/  $$
| $$    $$      | $$    $$      | $$$$\ $$      | $$  $$
| $$$$$$$\      | $$$$$$$$      | $$\$$ $$      | $$$$$\
| $$__/ $$      | $$  | $$      | $$ \$$$$      | $$ \$$\
| $$    $$      | $$  | $$      | $$  \$$$      | $$  \$$\
\$$$$$$$        \$$   \$$       \$$   \$$       \$$   \$$

Welcome to the Dank Bank Database. Please choose an option.
1. Login to an existing account
2. Make a conversion
3. Exit the program
=>> 1
Username: admin
Password: adminpass
Login successful.

Please choose an option.
1. Create an account
2. Delete and existing account
3. Exit
=>> 1
Enter your new username: YuJin
Enter your new password: Kim
Choose your preferred currency type.
1. US Dollars
2. Euros
3. UK Pounds
=>> 1
Your new username is: YuJin
Your new password is: Kim

Please choose an option.
1. Create an account
2. Delete and existing account
3. Exit
=>> 1
Enter your new username: Kevin
Enter your new password: Rivera
Choose your preferred currency type.
1. US Dollars
2. Euros
3. UK Pounds
=>> 1
Your new username is: Kevin
Your new password is: Rivera

Please choose an option.
1. Create an account
2. Delete and existing account
3. Exit
=>> 3
Logging out.

Welcome to the Dank Bank Database. Please choose an option.
1. Login to an existing account
2. Make a conversion
3. Exit the program
=>> 1
Username: YuJin
Password: Kim
Login successful.

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 1
Your balance is: $0.00.

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 2

Choose a type of currency.
1. US Dollar
2. Euro
3. UK Pound
=>> 1

Input the value you want to deposit. Example: 50.25
=>> 2000
Deposited: 2000.00 US Dollars
Total balance: $2000.00

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 1
Your balance is: $2000.00.

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 4
Name of account to transfer to: Kevin
Input the value you want to transfer in dollars. Example: 50.25
=>> R^Hasdf
Transfering $0.00 to user Kevin

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 3

Choose a type of currency.
1. US Dollar
2. Euro
3. UK Pound
=>> 1

Input the value you want to withdraw. Example: 50.25
1000
Withdrew: 1000.00 US Dollars
Total balance: $1000.00

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 1
Your balance is: $1000.00.

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 4
Name of account to transfer to: Kevin
Input the value you want to transfer in dollars. Example: 50.25
=>> 500
Transfering $500.00 to user Kevin

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 1
Your balance is: $500.00.

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 5
Logging out.

Welcome to the Dank Bank Database. Please choose an option.
1. Login to an existing account
2. Make a conversion
3. Exit the program
=>> 1
Username: Kevin
Password: Rivera
Login successful.

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 1
Your balance is: $500.00.

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 4
Name of account to transfer to: YuJin
Input the value you want to transfer in dollars. Example: 50.25
=>> 1000
Insufficient funds

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 1
Your balance is: $500.00.

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 4
Name of account to transfer to: YuJin
Input the value you want to transfer in dollars. Example: 50.25
=>> 500
Transfering $500.00 to user YuJin

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 1
Your balance is: $0.00.

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 5
Logging out.

Welcome to the Dank Bank Database. Please choose an option.
1. Login to an existing account
2. Make a conversion
3. Exit the program
=>> 1
Username: YuJin
Password: Kim
Login successful.

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 1
Your balance is: $1000.00.

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 5
Logging out.

Welcome to the Dank Bank Database. Please choose an option.
1. Login to an existing account
2. Make a conversion
3. Exit the program
=>> 1
Username: admin
Password: adminpass
Login successful.

Please choose an option.
1. Create an account
2. Delete and existing account
3. Exit
=>> 2
Username: YuJin
User deleted.

Please choose an option.
1. Create an account
2. Delete and existing account
3. Exit
=>> 3
Logging out.

Welcome to the Dank Bank Database. Please choose an option.
1. Login to an existing account
2. Make a conversion
3. Exit the program
=>> 1
Username: YuJin
Password: Kim
Invalid username or password

Welcome to the Dank Bank Database. Please choose an option.
1. Login to an existing account
2. Make a conversion
3. Exit the program
=>> 1
Username: Kevin
Password: Rivera
Login successful.

Please choose an option.
1. See balance
2. Make a deposit
3. Withdraw an amount
4. Transfer money to another account
5. Exit
=>> 5
Logging out.

Welcome to the Dank Bank Database. Please choose an option.
1. Login to an existing account
2. Make a conversion
3. Exit the program
=>> 4
Invalid input, please enter a number 1-3.

Welcome to the Dank Bank Database. Please choose an option.
1. Login to an existing account
2. Make a conversion
3. Exit the program
=>> 3
```
