#include <iostream>
#include <string>
#include <fstream>
#include<cstdlib>
using namespace std;
#define max_messages 5
#define max_users 100
#define max_admins 5
string input_name, input_password, input_type, input_email;
int count_users, user_array_num, admin_array_num, user_attempts = 3, admin_attempts = 3;			// count_users is only for sign up(seif abwahed).
struct feedback_messages
{
	int count_messages;							// count for every type for every user.
	string message[max_messages];				// every type(3) for every user has 5 messages at most.
};

struct user_data
{
	string name;
	string password;
	string email;
	feedback_messages type[3];							 // (bug report, feature request or general feedback)
}user[max_users];

struct admin_data
{
	string name;
	string password;
}admin[max_admins];

void reading_data_from_file()							// ziad tarek
{


}

void saving_data_to_file()								// ziad tarek
{


}

void feedback_submission()								// omar aly
{
	string submit_again;
	cout << "\n						Welcome to feedback submission\n";
	do
	{
		cout << "Please choose the type of feedback you want to submit\n";
		cout << "1 for bug report\n";
		cout << "2 for feature request\n";
		cout << "3 for general feedback\n";
		do
		{
			cin >> input_type;

			if (input_type == "1")
			{
				// do something
				user[user_array_num].type[0].count_messages++;
				break;
			}
			else if (input_type == "2")
			{
				// do something
				user[user_array_num].type[1].count_messages++;
				break;
			}
			else if (input_type == "3")
			{
				// do something
				user[user_array_num].type[2].count_messages++;
				break;
			}
			else cout << "Invalid choice!! please enter a valid choice: ";

		} while (input_type != "1" && input_type != "2" && input_type != "3");
		cout << "Do you want to submit a feedback again?(type yes if you want): ";
		cin >> submit_again;
	} while (submit_again == "yes" || submit_again == "Yes");
}

void edit_submission()								// salem or fawzy
{


}

void delete_submission()							// salem or fawzy
{

	// count_messages--;
}

void feedback_prioritization()								// ramez amr
{


}

void user_interface()									// ziad tarek
{
	string choice;
	cout << "----------------------\n";
	cout << "Welcome back " << input_name << " !" << endl;
	cout << "----------------------\n";
	cout << "Press 1 to submit a feedback\n";
	cout << "Press 2 to edit your feedback(s)\n";
	cout << "Press 3 to delete your feedback(s)\n";
	cout << "Press 4 to see the most feedback submitted\n";
	do
	{
		cin >> choice;
		if (choice == "1")
		{
			feedback_submission();
			break;
		}
		else if (choice == "2")
		{
			edit_submission();
			break;
		}
		else if (choice == "3")
		{
			delete_submission();
			break;
		}
		else if (choice == "4")
		{
			feedback_prioritization();
			break;
		}
		else cout << "Invalid choice!! please enter a valid choice: ";

	} while (choice != "1" && choice != "2" && choice != "3" && choice != "4");
}

void admin_interface()							// seif tamer
{


}
void Login()
{
	string ans;
	cout << "Do you want to login as an Admin or User ?\n";
	cin >> ans;
	if (ans == "user" || ans == "User")
	{
		bool found = false;
		cout << "Enter Username: ";
		cin >> input_name;
		cout << "Enter Password: ";
		cin >> input_password;

		for (int i = 0; i < count_users; i++)
		{
			if (user[i].name == input_name && user[i].password == input_password)
			{
				user_array_num = i;
				found = true;
				break;
			}
		}

		if (found)
		{
			user_interface();
		}
		else
		{
			cout << "Invalid Username or Password.\n";
			user_attempts--;
			cout << "Attempts left = " << user_attempts << '\n';
			if (user_attempts != 0)
				Login();
			else
			{
				cout << "No attempts left";exit(1);
			}
		}
	}
	else if (ans == "Admin" || ans == "admin")
	{
		bool found = false;
		cout << "Enter Username: ";
		cin >> input_name;
		cout << "Enter Password: ";
		cin >> input_password;

		for (int i = 0; i < max_admins; i++)
		{
			if (admin[i].name == input_name && admin[i].password == input_password)
			{
				admin_array_num = i;
				found = true;
				break;
			}
		}

		if (found)
		{
			admin_interface();
		}
		else
		{
			cout << "Invalid Username or Password.\n";
			admin_attempts--;
			cout << "Attempts left = " << admin_attempts;
			if (admin_attempts != 0)
				Login();
			else
			{
				cout << "No attempts left";exit(1);
			}
		}
	}
	else
	{
		cout << "Invalid input. Try again\n";Login();
	}
}
void Signup()
{
	cout << "Enter Email: ";
	cin >> input_email;
	cout << "Enter Username: ";
	cin >> input_name;
	cout << "Enter Password: ";
	cin >> input_password;
	user[count_users].email = input_email;
	user[count_users].name = input_name;
	user[count_users].password = input_password;
	cout << "Signup Successful!\n";
	user_interface();
	count_users++;
}
void user_authentication()						// seif abwahed
{
	string ans;
	cout << "---------------------------------\n";
	cout << "Log in or Sign up to your account\n";
	cout << "---------------------------------\n";
	cout << "1.Login\n"<<"2.Signup\n";
	cin >> ans;

	if (ans == "1")
	{
		Login();
	}
	else if (ans == "2")
	{
		Signup();
	}
	else 
	{
		cout << "Invalid Choice! Try Again\n";
		user_authentication();
	}
}

int main()										// ziad tarek
{
	fstream file;
	file.open("data.txt");
	if (file.is_open())
		reading_data_from_file();
	else
	{
		cout << "						ERROR OPENING THE FILE!!\n\n";
		return 0;
	}
	cout << "						 WELCOME TO OUR PROJECT\n";
	cout << "						 ______________________\n\n";
	user_authentication();
	cout << "\n\n						THANK YOU FOR YOUR TIME\n\n";
	saving_data_to_file();
	return 0;
}
