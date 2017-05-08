/*	
	Vitaliy Shkuratov
	Final Project Part II (Vector of pointers to structure)
	ID: 1531565
*/


#include <iostream>
#include <string>
#include <algorithm>    // all_of, sort
#include <regex>
#include <windows.h>	// GetConsoleWindow
#include <iomanip>		// setw
#include <vector>

#define WIDTH_CONSOLE_WINDOW 1344
#define HIGH_CONSOLE_WINDOW 700
#define LEFT_POSITION_CONSOLE_WINDOW 10
#define UPPER_POSITION_CONSOLE_WINDOW 10
#define WIDTH_ONE_CHARACHTER_PIXEL 8

#define LENGTH_COLLUM 12
#define LENGTH_NAME_COLLUM 21
#define LENGTH_PHONE_COLLUM 17
#define LENGTH_COMPANY_NAME_COLLUM 15
#define LENGTH_ADDRESS_COLLUM 28
#define NUMBER_COLLUM 9

using namespace std;
struct Phone
{
	int country_code;
	int city_code;
	int cell_code;

public:
	Phone()   // Empty constructor 
	{
		country_code = 000;
		city_code = 000;
		cell_code = 0000000;
	}
	Phone(	int _country_code,
			int _city_code,
			int _cell_code)
	{
		country_code = _country_code;
		city_code = _city_code;
		cell_code = _cell_code;
	}
	friend ostream& operator<<(ostream& os, const Phone& ph);
	friend ostream& operator<<(ostream& os, const Phone& fx);
};
struct Address
{
	int street_number;
	string street_name;
	string city;
	string province;
	string postal_code;
	string country;

	public:
	Address() 
	{
		street_number = 000;
		street_name = "unknown";
		city = "unknown";
		province = "unknown";
		postal_code = "unknown";
		country = "unknown";
	}
	Address(int _street_number,
			string _street_name,
			string _city,
			string _province,
			string _postal_code,
			string _country)
	{
		street_number = _street_number;
		street_name = _street_name;
		city = _city;
		province = _province;
		postal_code = _postal_code;
		country = _country;
	}
	friend ostream& operator<<(ostream& os, const Address& adr);
};
struct Email
{
	string email_name;
	string email_domaine;
public:
	Email() 
	{
		email_name = "unknown";
		email_domaine = "unknown";
	}
	Email(	string _email_name,
			string _email_domaine)
	{
		email_name = _email_name;
		email_domaine = _email_domaine;
	}
	friend ostream& operator<<(ostream& os, const Email& ml);
};

struct Date
{
	int month;
	int day;
	int year;

	public:
	Date() // Empty constructor 
	{ 
		month = 00; day = 00; year = 0000;
	} 
	Date(int _month, int _day, int _year)
    {
		month = _month; day = _day; year = _year;
    }

    friend ostream& operator<<(ostream& os, const Date& dt);
};

struct Contact
{
	int contact_Id;
	string first_name;
	string last_name;
	string company_name;
	Phone *PhoneNumber = new Phone();
	Phone *FaxNumber = new Phone();
	Address *newAddress = new Address();
	Email *newEmail = new Email();
	Date * MeetingDate = new Date();

public:
	Contact() 
	{

	}
	Contact(string _first_name,
			string _last_name) 
	{
		first_name = _first_name;
		last_name = _last_name;
	}
	friend ostream& operator<<(ostream& os, const Contact& nm);
};

string trim_string_to_cell
	(int length_cell, string old_string);	// Trim string if length of
											//  cell is less than string

ostream& operator <<
			(ostream& os, const Contact& nm)	// Overloading the 
												//"<<" Operator for Name
{

	os	<< trim_string_to_cell(LENGTH_NAME_COLLUM, 
								nm.last_name + ", "
								+ nm.first_name);
	return os;
}

ostream& operator<<(ostream& os, const Date& dt)	// Overloading the
													// "<<" Operator
													// for Date type		
{
	os	<<	to_string(dt.month) + '/' 
			+ to_string(dt.day) + '/'
			+ to_string(dt.year);
	return os;
}

ostream& operator<<(ostream& os, const Phone& ph)	// Overloading the 
													// "<<" Operator
													// for Phone type
{
	os	<< to_string(ph.country_code) + '-'
		+ to_string(ph.city_code) + '-'
		+ to_string(ph.cell_code);
	return os;
}

ostream& operator<<(ostream& os, const Address& adr)	// Overloading the 
														// "<<" Operator
														// for Address type
{
	os 	<< trim_string_to_cell(LENGTH_ADDRESS_COLLUM,
					to_string(adr.street_number) + ' '
					+ adr.street_name + ' '
					+ adr.city + ' '
					+ adr.province + ' '
					+ adr.postal_code + ' '
					+ adr.country);
	return os;
}

ostream& operator<<(ostream& os, const Email& ml)	// Overloading the 
													// "<<" Operator
													// for Email type
{
	os	<< trim_string_to_cell(LENGTH_NAME_COLLUM,
						ml.email_name + '@'
						+ ml.email_domaine);
	return os;
}

void set_console_size();						//Set up size of console

//int create_contact(Contact *, Contact *);		
int create_contact(vector <Contact *> &ContactBook);	// Fill out structure with 										
													// contact information

void display_contact(vector <Contact *> &ContactBook);	// Display structure with 
														// contact information

void display_wrong_imp_mes(bool);				// Display a message 
												// "Wrong format!"

void display_wrong_imp_mes(bool, string, int);	// Overloaded function
												// display a message "Wrong
												// format!"

void sort_contact(vector <Contact *> &ContactBook, int);	// Sort


//void search_contact(Contact *, Contact *, int);	// Search contact

void search_contact(vector <Contact *> &ContactBook);		// Search contact

void display_one_contact(Contact *);			// Display just one contact

void print_double_dashes(int);					// Print double dashes in 
												// table

void print_single_dashes(int);					// Print double dashes in 
												// table

void display_table_head();						// Print head of table

void display_wrong_imp_mes
	(bool, string,	int, int);					// Display message about 
												// wrong input format

void print_table_name();						// Display name of table

bool close_application();						// Ask insure exit
												// application.

bool is_digit(const string &str);				// Check is just digits in 
												// input.

bool is_alpha(const string &str);				// Check is just an 
												// alphabetical character in 
												// input.

bool is_postal_code(string);					// Function checked does
												// string matched to postal
												// code format.

bool is_day(string);							// Checked right day format

bool is_month(string);							// Checked right month format

bool is_name(string&);							// Check alpha in name and
												// whitespace in case of 
												// complex name with a 
												// middle name (such as 
												// Vitaliy Valenty Shkuratov
												// or Michal J. Fox)

int	display_main_menu();						// Ask and return number 
												// of choose.

int display_search_menu();						// Display menu with
												// search option

int display_sort_menu();						// Display menu with
												// sort option

int calculate_total_length();					// Calculate total length
												// of table


string convert_first_letter_to_upper(string &);	// Convert all letter 
												// in name to upper case

string convert_string_to_lower_case(string &);	// Convert all letter
												// in string to lower case

bool sort_by_id(Contact * current_contact, Contact * next_current_contact);		// Determine pattern for sorting
bool sort_by_name(Contact * current_contact, Contact * next_current_contact);	// Determine pattern for sorting
void delete_contact(vector <Contact *> &ContactBook);		// Delete contact


int main()
{
	set_console_size();
	vector <Contact *> ContactBook;				// Declare vector of pointers to structure

	int SortMenu();
	do
	{
		switch (display_main_menu())
		{
		case 1:
			create_contact(ContactBook);
			break;
		case 2:
			display_contact(ContactBook);
			system("pause");
			break;
		case 3:
			search_contact(ContactBook);
			system("pause");
			break;
		case 4:
			switch (display_sort_menu())
			{
			case 1:
				sort_contact(ContactBook, 1);
				break;
			case 2:
				sort_contact(ContactBook, 2);
				break;
			}
			display_contact(ContactBook);
			system("pause");
			break;
		case 5:
			delete_contact(ContactBook);
			break;
		case 6:
			if (close_application())
				return 0;
			else display_main_menu();
			break;
		}
	} while (true);
	return 0;
}
void delete_contact(vector <Contact *> &ContactBook)
{
	bool check_condition = true;
	bool table_head = false;

	string temp_Id = "";

	cin.ignore();
	cout << "\n\tEnter contact number > ";
	getline(cin, temp_Id);
	system("cls");
	temp_Id = convert_string_to_lower_case(temp_Id);

	for (int i = 0; i < ContactBook.size(); i++)
	{

		if (to_string(ContactBook[i]->contact_Id) == temp_Id)
		{
			ContactBook.erase(ContactBook.begin() + i);
			cout << "\n\tThe contact was delited succesfully!" << endl;
			system("pause");
			check_condition = false;
		}
	}
	if (check_condition)
	{
		cout << "\n\tThe contact does not exist!" << endl;
		system("pause");
	}
}



int calculate_total_length()
{
	return NUMBER_COLLUM + LENGTH_NAME_COLLUM * 2 +
		LENGTH_COMPANY_NAME_COLLUM + LENGTH_ADDRESS_COLLUM +
		LENGTH_COLLUM * 2 + LENGTH_PHONE_COLLUM * 2;
}

bool sort_by_id(Contact * current_contact, Contact * next_current_contact)
{
	return (current_contact->contact_Id < next_current_contact->contact_Id);
}

bool sort_by_name(Contact * current_contact, Contact * next_current_contact)
{
	return (current_contact->company_name < next_current_contact->company_name);
}

void search_contact(vector <Contact *> &ContactBook)
{
	bool check_condition = true;
	bool table_head = false;

	string temp_value = "";
	string temp_last_name = "";
	string temp_company_name = "";

	cin.ignore();
	cout << "\n\tEnter contact number or last name or company name > ";
	getline(cin, temp_value);
	system("cls");
	temp_value = convert_string_to_lower_case(temp_value);

	for (vector<Contact * > ::iterator it = ContactBook.begin(); it != ContactBook.end(); ++it)
	{
		
		temp_last_name = (*it)->last_name; 
		temp_company_name = (*it)->company_name;

		if (to_string((*it)->contact_Id) == temp_value || 
			convert_string_to_lower_case(temp_last_name) == temp_value ||
			convert_string_to_lower_case(temp_company_name) == temp_value)
		{
			if (!table_head)
			{
				print_table_name();
				display_table_head();
				table_head = true;
			}
			display_one_contact(*it);
			check_condition = false;
		}
	}
	if (check_condition)
		cout << "\n\tThe contact does not exist!";
		cout << endl;
}

int display_search_menu()
{
	string temp_value = "";
	bool check_condition = true;
	do
	{
		cout << "\n\t1. Search by contact number. ";
		cout << "\n\t2. Search by last name. ";
		cout << "\n\t3. Search by company name. ";
		cout << "\n\n\t> ";
		cin >> temp_value;
		if (temp_value == "2" || temp_value == "1" || temp_value == "3")
			check_condition = true;
		else check_condition = false;
		display_wrong_imp_mes(check_condition);
	} while (!check_condition);
	return  stoi(temp_value);
}

int display_sort_menu() 
{
	string temp_value = "";
	bool check_condition = true;
	do
	{
		cout << "\n\t1. Sort by contact number. ";
		cout << "\n\t2. Sort by company name. ";
		cout << "\n\n\t> ";
		cin >> temp_value;
		if (temp_value == "2" || temp_value == "1")
			check_condition = true;
		else check_condition = false;
		display_wrong_imp_mes(check_condition);
	} while (!check_condition);
	return  stoi(temp_value);
}
void sort_contact(vector <Contact *> &ContactBook, int type_sort)
{
	if (type_sort == 1)
	{
		sort(ContactBook.begin(), ContactBook.end(), sort_by_id);
	}

	else
	{
		sort(ContactBook.begin(), ContactBook.end(), sort_by_name);
	}
}

int create_contact(vector <Contact *> &ContactBook)
{
	string temp_value = "";
	while(true)
	{
		bool check_condition = true;
		system("cls");
		cout << "\n\tEnter general data:";
		cout << endl;

		Contact * newContact;	// declare new structure

		do
		{
			cout << "\n\tContact ID or 'Q' to quit input > ";
			cin >> temp_value;
			if (temp_value == "q" || temp_value == "Q")
			{
				return 0;
			}

			check_condition = is_digit(temp_value);
			display_wrong_imp_mes(check_condition);
		} while (!check_condition);

		newContact = new Contact();				// create new contact
		ContactBook.push_back(newContact);		// push new structure to vector

		newContact->contact_Id = stoi(temp_value);

		check_condition = true;
		do
		{
			cout << "\n\tFirst name > ";
			cin.ignore();
			getline(cin, temp_value);
			check_condition = is_name(temp_value);
			display_wrong_imp_mes(check_condition);
		} while (!check_condition);

		newContact->first_name = convert_first_letter_to_upper(temp_value);
		check_condition = true;
	
		do
		{
			cout << "\n\tLast name > ";
			getline(cin, temp_value);
			check_condition = is_name(temp_value);
			display_wrong_imp_mes(check_condition);
		} while (!check_condition);
		newContact->last_name = convert_first_letter_to_upper(temp_value);

		do
		{
			cout << "\n\tCompany name > ";
			getline(cin, temp_value);
			if (temp_value.length() > 0)
			{
				check_condition = true;
			}
			else check_condition = false;

			display_wrong_imp_mes(check_condition);
		} while (!check_condition);
		newContact->company_name = temp_value;

		cout << "\n\tEnter telephone data:";
		cout << endl;

		do
		{
			cout << "\n\tCountry code (max 3 digits) > ";
			cin >> temp_value;
			check_condition = is_digit(temp_value);
			display_wrong_imp_mes(check_condition, temp_value, 1, 3);
		} while (	!check_condition || 
					temp_value.length() < 1 ||
					temp_value.length() > 3);
		newContact->PhoneNumber->country_code = stoi(temp_value);

		do
		{
			cout << "\n\tCity code (3 digits) > ";
			cin >> temp_value;
			check_condition = is_digit(temp_value);
			display_wrong_imp_mes(check_condition, temp_value, 3);
		} while (!check_condition || temp_value.length() != 3);
		newContact->PhoneNumber->city_code = stoi(temp_value);

		do
		{
			cout << "\n\tCell code (7 digits) > ";
			cin >> temp_value;
			check_condition = is_digit(temp_value);
			display_wrong_imp_mes(check_condition, temp_value, 7);
		} while (!check_condition || temp_value.length() != 7);
		newContact->PhoneNumber->cell_code = stoi(temp_value);
		cout << endl;

		cout << "\n\tEnter fax data:";
		cout << endl;
		
		do
		{
			cout << "\n\tCountry code (max 3 digits) > ";
			cin >> temp_value;
			check_condition = is_digit(temp_value);
			display_wrong_imp_mes(check_condition, temp_value, 1, 3);
		} while (	!check_condition ||
					temp_value.length() < 1 ||
					temp_value.length() > 3);

		newContact->FaxNumber->country_code = stoi(temp_value);

		do
		{
			cout << "\n\tCity code (3 digits) > ";
			cin >> temp_value;
			check_condition = is_digit(temp_value);
			display_wrong_imp_mes(check_condition, temp_value, 3);
		} while (!check_condition || temp_value.length() != 3);
		newContact->FaxNumber->city_code = stoi(temp_value);

		do
		{
			cout << "\n\tCell code (7 digits) > ";
			cin >> temp_value;
			check_condition = is_digit(temp_value);
			display_wrong_imp_mes(check_condition, temp_value, 7);
		} while (!check_condition || temp_value.length() != 7);
		newContact->FaxNumber->cell_code = stoi(temp_value);

		cout << "\n\tEnter address data:";
		cout << endl;
		do
		{
			cout << "\n\tStreet number > ";
			cin >> temp_value;

			check_condition = is_digit(temp_value);

			display_wrong_imp_mes(check_condition);
		} while (!check_condition);
		newContact->newAddress->street_number = stoi(temp_value);
		cin.ignore();

		do
		{
			cout << "\n\tStreet name > ";
			getline(cin, temp_value);
			if (is_name(temp_value) && temp_value.length() > 0)
			{
				check_condition = true;
			}
			else check_condition = false;

			display_wrong_imp_mes(check_condition);
		} while (!check_condition);
		newContact->newAddress->street_name = convert_first_letter_to_upper(temp_value);

		do
		{
			cout << "\n\tCity > ";
			getline(cin, temp_value);
			if(is_alpha(temp_value) && temp_value.length() > 0)
			{
				check_condition = true;
			}
			else check_condition = false;

			display_wrong_imp_mes(check_condition);
		} while (!check_condition);
		newContact->newAddress->city = convert_first_letter_to_upper(temp_value);

		do
		{
			cout << "\n\tProvince > ";
			getline(cin, temp_value);
			if (is_alpha(temp_value) && temp_value.length() > 0)
			{
				check_condition = true;
			}
			else check_condition = false;

			display_wrong_imp_mes(check_condition);
		} while (!check_condition);
		newContact->newAddress->province = convert_first_letter_to_upper(temp_value);

		do
		{
			cout << "\n\tPostal code > ";
			getline(cin, temp_value);
			check_condition = is_postal_code(temp_value);
			display_wrong_imp_mes(check_condition);
		} while (!check_condition);

		newContact->newAddress->postal_code = temp_value;

		do
		{
		cout << "\n\tCountry > ";
		getline(cin, temp_value);
		if (is_alpha(temp_value) && temp_value.length() > 0)
		{
			check_condition = true;
		}
		else check_condition = false;
		display_wrong_imp_mes(check_condition);
		} while (!check_condition);
		newContact->newAddress->country = convert_first_letter_to_upper(temp_value);

		cout << "\n\tEnter email data:";
		do
		{

			cout << "\n\tEmail name > ";
			getline(cin, temp_value);
			if (temp_value.length() > 0)
			{
				check_condition = true;
			}
			else check_condition = false;
			display_wrong_imp_mes(check_condition);
		} while (!check_condition);
		newContact->newEmail->email_name = temp_value;

		do
		{
		cout << "\n\tEmail domain > ";
		getline(cin, temp_value);
		if (temp_value.length() > 0)
		{
			check_condition = true;
		}
		else check_condition = false;
		display_wrong_imp_mes(check_condition);
		} while (!check_condition);

		newContact->newEmail->email_domaine = temp_value;

		cout << "\n\tEnter meeting date:";
		do
		{
			cout << "\n\tMeeting day > ";
			cin >> temp_value;
			if (is_day(temp_value))
			{
				check_condition = true;
			}
			else check_condition = false;

			display_wrong_imp_mes(check_condition);
		} while (!check_condition);
		newContact->MeetingDate->day = stoi(temp_value);

		do
		{
			cout << "\n\tMeeting month > ";
			cin >> temp_value;
			if (is_month(temp_value))
			{
				check_condition = true;
			}
			else check_condition = false;

			display_wrong_imp_mes(check_condition);

		} while (!check_condition);
		newContact->MeetingDate->month = stoi(temp_value);

		do
		{
			cout << "\n\tMeeting year > ";
			cin >> temp_value;
			check_condition = is_digit(temp_value);
			display_wrong_imp_mes(check_condition, temp_value, 4);

		} while ((!check_condition || temp_value.length() != 4));
		newContact->MeetingDate->year = stoi(temp_value);
	}
	return 0;
}

void display_contact(vector <Contact *> &ContactBook)
{
	system("cls");
	if (!ContactBook.empty())
	{
		print_table_name();
		display_table_head();
		for (vector<Contact * > :: iterator it = ContactBook.begin(); it != ContactBook.end(); ++it)
		{
			display_one_contact(*it);
		}
	}
	else
	{
		cout << "\n\tNo contact has not yet been made." << endl;
	}
}

void display_one_contact(Contact *current_contact)
{
	Date dt(	current_contact->MeetingDate->month,
				current_contact->MeetingDate->day,
				current_contact->MeetingDate->year);

	Phone ph(	current_contact->PhoneNumber->country_code,
				current_contact->PhoneNumber->city_code,
				current_contact->PhoneNumber->cell_code);

	Phone fx(	current_contact->FaxNumber->country_code,
				current_contact->FaxNumber->city_code,
				current_contact->FaxNumber->cell_code);

	Address adr(current_contact->newAddress->street_number,
				current_contact->newAddress->street_name,
				current_contact->newAddress->city,
				current_contact->newAddress->province,
				current_contact->newAddress->postal_code,
				current_contact->newAddress->country);

	Email ml(	current_contact->newEmail->email_name,
				current_contact->newEmail->email_domaine);

	Contact nm(	current_contact->last_name,
				current_contact->first_name);

	cout << "\t" << "|" << setw(LENGTH_COLLUM) << right << current_contact->contact_Id;
	cout << "|" << setw(LENGTH_NAME_COLLUM) << left << nm;
	cout << "|" << setw(LENGTH_COMPANY_NAME_COLLUM) << left 
	<< trim_string_to_cell(LENGTH_COMPANY_NAME_COLLUM, current_contact->company_name);

	cout << "|" << setw(LENGTH_PHONE_COLLUM) << right << ph;
	cout << "|" << setw(LENGTH_PHONE_COLLUM) << right << fx;
	cout << "|" << setw(LENGTH_ADDRESS_COLLUM) << left << adr;
	cout << "|" << setw(LENGTH_NAME_COLLUM) << left << ml;
	cout << "|" << setw(LENGTH_COLLUM) << left << dt;
	cout << "|" << endl;

	cout << "\t";
	print_single_dashes(calculate_total_length());
}
string trim_string_to_cell(int length_cell, string old_string)
{

	string new_string;
	if (length_cell >= old_string.length())
		return old_string;
	else
	{
		for (int i = 0; i < (length_cell - 3); i++)
		{
			new_string = new_string + old_string[i];
		}
		return new_string = new_string + "...";
	}
}
void display_table_head()
{
		const string TEXT_1 = "Contact ID";
		const string TEXT_2 = "Contact Name";
		const string TEXT_3 = "Company name";
		const string TEXT_4 = "Telephone number";
		const string TEXT_5 = "Fax number";
		const string TEXT_6 = "Address";
		const string TEXT_7 = "Email";
		const string TEXT_8 = "Meeting date";

		cout << endl << endl << endl << endl;
		cout << "\t";
		print_double_dashes(calculate_total_length());
		cout << "\t"
			<< "|" << setw(LENGTH_COLLUM) << right << TEXT_1
			<< "|" << setw(LENGTH_NAME_COLLUM) << left << TEXT_2
			<< "|" << setw(LENGTH_COMPANY_NAME_COLLUM) << left << TEXT_3
			<< "|" << setw(LENGTH_PHONE_COLLUM) << right << TEXT_4
			<< "|" << setw(LENGTH_PHONE_COLLUM) << right << TEXT_5
			<< "|" << setw(LENGTH_ADDRESS_COLLUM) << left << TEXT_6
			<< "|" << setw(LENGTH_NAME_COLLUM) << left << TEXT_7
			<< "|" << setw(LENGTH_COLLUM) << left << TEXT_8
			<< "|" << endl;
		cout << "\t";
		print_double_dashes(calculate_total_length());
}
void print_double_dashes(int lengthTable)
{
	for (int i = 0; i < lengthTable; i++)
	{
		cout << "=";
	}
	cout << endl << endl;
}
void print_single_dashes(int lengthTable)
{
	for (int i = 0; i < lengthTable; i++)
	{
		cout << "-";
	}
	cout << endl << endl;
}

void set_console_size() //set up size of console
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, LEFT_POSITION_CONSOLE_WINDOW, UPPER_POSITION_CONSOLE_WINDOW, WIDTH_CONSOLE_WINDOW, HIGH_CONSOLE_WINDOW, TRUE);
}

bool is_day(string temp_string)
{
	if (!isalpha(temp_string[0]))
	{
		if (stoi(temp_string) >= 1 && stoi(temp_string) <= 31)
			return true;
	}
	return false;
}

bool is_month(string temp_string)
{
	if (!isalpha(temp_string[0]))
	{
		if (stoi(temp_string) >= 1 && stoi(temp_string) <= 12)
			return true;
	}
	return false;
}

bool is_postal_code(string temp_string) 
{
	regex postal_code("([ABCEGHJKLMNPRSTVXY][0-9][ABCEGHJKLMNPRSTVWXYZ][0-9][ABCEGHJKLMNPRSTVWXYZ][0-9])");
	return regex_match(temp_string, postal_code);
}
void display_wrong_imp_mes(bool check_condition)
{
	if (!check_condition)
	{
		system("cls");
		cout << "\n\tWrong format. Repeat! ";
		cout << endl;
	}
}

void display_wrong_imp_mes(	bool check_condition, 
							string temp_value, 
							int min_length,	
							int max_length)
{
	if (!check_condition || 
		temp_value.length() < min_length ||
		temp_value.length() > max_length)
	{
		system("cls");
		cout << "\n\tWrong format. Repeat! ";
		cout << endl;
	}
}
void display_wrong_imp_mes(bool check_condition, string temp_value, int maxLength)
{
	if (!check_condition || temp_value.length() != maxLength)
	{
		system("cls");
		cout << "\n\tWrong format. Repeat! ";
		cout << endl;
	}
}
bool is_digit(const string &str)						
{
	// begin() Returns an iterator pointing 
	// to the first element in the sequence.
	// end()  Returns an iterator pointing 
	// to the last element in the sequence.
	return all_of(str.begin(), str.end(), isdigit);
}
bool is_alpha(const string &str)
{
	{
		return all_of(str.begin(), str.end(), isalpha);
	}
}
bool close_application()  // Ask insure exit application.
{
	system("cls");
	cout << "\n\n\tAre you sure you want to quit? (Y/N) > ";
	if (cin.get() == 'Y' || cin.get() == 'y')
		return true;
	else
		return false;
}
int display_main_menu() // Ask and return number of choose.
{
	string selected_number = "";
	bool check_condition;
	regex menu_value("[1-6]");
	do
	{
		system("cls");
		cout << "\n\n\tSelect one of the options:";
		cout << "\n\n\t1.	Create a contact.";
		cout << "\n\t2.	Display all the contacts.";
		cout << "\n\t3.	Search for a contact by.";
		cout << "\n\t4.	Sort the contacts by.";
		cout << "\n\t5.	Delete the contact by ID.";
		cout << "\n\t6.	Exit application.";
		cout << "\n\n\t> ";
		cin >> selected_number;
		check_condition = is_alpha(selected_number);
		if (!regex_match(selected_number, menu_value))
		{
			cout << "\n\tWrong chose. Repeat! ";
			system("pause");
		}
	} while (!regex_match(selected_number, menu_value));

	return stoi(selected_number);
}

void print_table_name()
{
	const string TEXT_1 = "LIST OF CONTACTS";
	cout << "\n\n\t\t\t\t\t\t\t\t\t" << TEXT_1;
}

bool is_name(string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]) && !isspace(str[i]) && str[i]!='.')
		{
			return false;
		}
	}
	return true;
}

string convert_first_letter_to_upper(string &name)
{
	string new_string;
	string temp_string;
	bool condition = true;

	for (size_t i = 0; i < name.length(); i++)
	{
		if (condition)
		{
			temp_string = toupper(name[i]);
			new_string = new_string + temp_string;
			condition = false;
			continue;
		}
		if (isspace(name[i]))
		{
			new_string = new_string + (name[i]);
			condition = true;
		}
		else
		{
			temp_string = tolower(name[i]);
			new_string = new_string + temp_string;
		}
	}
	return new_string;
}

string convert_string_to_lower_case(string &str)
{
	string temp_string;
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
		temp_string = temp_string + str[i];
	}
	return temp_string;
}