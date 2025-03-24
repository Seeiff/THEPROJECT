#include <iostream>
#include<string>
#include <fstream>
using namespace std;
bool IsUser = false;
bool IsAdmin = false;
string inputuser, inputpass, storedusername, storedpassword;
struct UserData
{
    string USERNAME;
    string PASSWORD;
    string FeedBack;
}User[100], Admin[100];


void AdminInterface()
{
    cout << "\t-------------------------------\n";
    cout << "\tWelcome to the Admin interface\n";
    cout << "\t-------------------------------\n";
    cout << "1.Manage users \n";
    cout << "2.Delete users\n";

}




void login()
{
    ifstream fin;
    bool found = false;
    do
    {
        cout << "Enter Username: ";
        cin >> inputuser;
        cout << "Enter Password: ";
        cin >> inputpass;
        fin.open("user.txt");
        while (fin >> storedusername >> storedpassword)
        {
            if (inputuser == storedusername && inputpass == storedpassword)
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
            if (inputuser == storedusername && inputpass == storedpassword)
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
    cin >> Admin[0].USERNAME;
    cout << "Enter Password: ";
    cin >> Admin[0].PASSWORD;
    fout.open("admin.txt", ios::app);
    fout << Admin[0].USERNAME << ' ' << Admin[0].PASSWORD << endl;
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
void userinterface()
{
    int ans;
    cout << "\t-------------------------------\n";
    cout << "\t       Welcome back " << inputuser << " !\n";
    cout << "\t-------------------------------\n";
    cout << "1.Submit a Feedback\n";
    cout << "2.Edit an existing Feedback\n";
    cout << "3.Delete Feedback\n";
    cin >> ans;
    switch (ans)
    {
    case '1': /*function el submit*/ break;
    case '2': /*function el edit*/break;
    case '3':/*function el delete*/break;
    default:cout << "Invalid input please enter 1 or 2 or 3\n ";userinterface();break;
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
            ifstream fin;
            bool found = false;
            char choice;
            cout << "Enter Username: ";
            cin >> User[0].USERNAME;
            cout << "Enter Password: ";
            cin >> User[0].PASSWORD;
            fin.open("user.txt");
            while (fin >> storedusername >> storedpassword)
            {
                if (User[0].USERNAME == storedusername && User[0].PASSWORD == storedpassword)
                {   
                 found = true;
                    break;
                }
            }
            fin.close();
            if (found)
            {
                cout << "User already registered. Please login or signup as a diffrent user\n";
                char ans;
                cout << "1.Sign up\n";
                cout << "2.Log in\n";
                cin >> ans;
                switch (ans)
                {
                case '1':signup();break;
                case '2':login();
                    if (IsUser)
                {
                    userinterface();
                }
                        else if (IsAdmin)
                {
                    AdminInterface();
                }
                        break;
                }
            }
            else
            {
                fout.open("user.txt", ios::app);
                fout << User[0].USERNAME << ' ' << User[0].PASSWORD << endl;
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
        userinterface();
    }
    else if (IsAdmin)
    {
        AdminInterface();
    }
    return 0;
}
