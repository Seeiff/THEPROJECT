#include <iostream>
#include <fstream>
using namespace std;
struct UserData
{
    string USERNAME;
    string PASSWORD;
}User[100],Admin[100];
void login()
{
    ifstream fin;
    string storedusername, storedpassword;
    bool found = false;
    do
    {
        cout << "Enter Username: ";
        cin >> User->USERNAME;
        cout << "Enter Password: ";
        cin >> User->PASSWORD;
        fin.open("user.txt");
        while (fin >> storedusername >> storedpassword)
        {
            if (User->USERNAME == storedusername && User->PASSWORD == storedpassword)
            {
                found = true;
                break;
            }
        }
        fin.close();
        if (found)
            cout << "Login Successful!\n";
        else
            cout << "Login Failed. Try again\n";


    } while (!found);
}
void signupasadmin()
{
    ofstream fout;
    char choice;
    cout << "Enter Username: ";
    cin >> Admin->USERNAME;
    cout << "Enter Password: ";
    cin >> Admin->PASSWORD;
    fout.open("admin.txt", ios::app);
    fout << Admin->USERNAME << ' ' << Admin->PASSWORD << endl;
    fout.close();
    cout << "Signup Sucssesful!\n ";
    cout << "Do you want to login ? (y/n)";
    cin >> choice;
    switch (choice)
    {
    case'Y':
    case 'y':login();break;
    case 'N':
    case 'n':cout << "Thank you for using our program :)\n";
    }
}

void signup()
{
    string ans;
    while (true)
    {
        cout << "Do you want to sign up as a user or as an admin\n";
        cin >> ans;
        if (ans == "User" || ans == "user")
        {
            ofstream fout;
            char choice;
            cout << "Enter Username: ";
            cin >> User->USERNAME;
            cout << "Enter Password: ";
            cin >> User->PASSWORD;
            fout.open("user.txt", ios::app);
            fout << User->USERNAME << ' ' << User->PASSWORD << endl;
            fout.close();
            cout << "Signup Sucssesful!\n ";
            cout << "Do you want to login ? (y/n)";
            cin >> choice;
            switch (choice)
            {
            case'Y':
            case 'y':login();break;
            case 'N':
            case 'n':cout << "Thank you for using our program :)"; break;
            }
            break;
        }
        else if (ans == "Admin" || ans == "admin")
        {
            signupasadmin(); break;
        }
        else
            cout << "Invalid input. Please enter 'User' or 'Admin'. Try again.\n";

    }
}
void LoginInterface()
{
    char choice;
    cout << "                                               -------------------------------\n";
    cout << "                                               Login or Signup to your account\n";
    cout << "                                               -------------------------------\n";
    cout << "Choose Number:\n";
    cout << "1--> Signup\n";
    cout << "2--> Login\n";
    cin >> choice;
    switch (choice)
    {
    case '1': signup();break;
    case '2': login();break;
    }

}
int main()
{
    LoginInterface();

    return 0;
}