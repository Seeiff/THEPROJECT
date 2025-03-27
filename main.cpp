#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define max_messages 5
#define max_users 100
#define max_admins 5
string input_name, input_password, input_type;
int count_users, user_array_num, admin_array_num;			// count_users is only for sign up(seif abwahed).
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
	cout << "Welcome " << input_name << endl;
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

void user_authentication()						// seif abwahed
{
	//count_users++;
	user_interface();
	admin_interface();
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
