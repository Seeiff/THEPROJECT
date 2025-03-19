#include <iostream>
#include<string>
#include <fstream>
using namespace std;
bool IsUser = false;
bool IsAdmin = false;
cout << "ana zozbeh";
struct UserData
{
    string USERNAME;
    string PASSWORD;
    string FeedBack;
}User[100], Admin[100];


void AdminInterface()
{
    cout << "\tWelcome to the Admin interface\n";
    cout << "1.Manage users\n";
    cout << "1.Manage feedbacks\n";

}




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
                IsUser = true;
                found = true;
                break;
            }
        }
        
        fin.close();
        fin.open("admin.txt");
        while (fin >> storedusername >> storedpassword)
        {
            if (User->USERNAME == storedusername && User->PASSWORD == storedpassword)
            {
                IsAdmin = true;
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
    cout << "Do you want to login ? (y/n)\n";
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
        cout << "Do you want to sign up as a user or as an admin ?\n";
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


/*The main login UI*/
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
    default: cout << "Invalid input please enter 1 or 2\n ";LoginInterface();break;
    }

}


/*This is the main functions where all other program functions are called and exucted*/

int main()
{
    
    LoginInterface();
    if (IsUser)
    {
        cout << "user\n";
    }
    else if (IsAdmin)
    {
       AdminInterface();
    }
    return 0;
}
