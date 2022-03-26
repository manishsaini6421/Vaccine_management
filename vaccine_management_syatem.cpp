#include <bits/stdc++.h>
#include <fstream>
#include <unistd.h>
using namespace std;

class vaccine
{
private:
    int age;
    char gender;
    string name,
        profession,
        address,
        aadhar,
        mobile,
        bp,
        temp;

public:
    void create();
    void record_byAadhar();
    void record_byName();
    void record_byAge();
    void record_byMobile();
    void record_byGender();
    void record_byAddress();
    void add();
};

void vaccine::create()
{
    // file pointer
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("data.csv", ios::out | ios::app);

    // Read the input
    cout << setw(70) << "Enter the name : ";
    cin >> name;
    cout << setw(72) << "Enter the aadhar : ";
    cin >> aadhar;
    cout << setw(69) << "Enter the age : ";
    cin >> age;
    cout << setw(78) << "Enter the gender (M|F) : ";
    cin >> gender;
    cout << setw(76) << "Enter the profession : ";
    cin >> profession;
    cout << setw(69) << "Enter the B.P : ";
    cin >> bp;
    cout << setw(82) << "Enter the Body temperature : ";
    cin >> temp;
    cout << setw(79) << "Enter the mobile number : ";
    cin >> mobile;
    cout << setw(83) << "Enter the permanent address : ";
    cin >> address;
    cout << endl;
    // Insert the data to file
    fout << name << ","
         << aadhar << ","
         << age << ","
         << gender << ","
         << profession << ","
         << bp << ","
         << temp << ","
         << mobile << ","
         << address
         << endl;
    cout << setw(89) << "DATA HAS BEEN SUCCESFULLY INSERTED\n\n";
    fstream file("count.txt");
    string ct;
    int temp;
    while (getline(file, ct))
    {
        temp = stoi(ct) - 1;
    }
    // Close the file
    file.close();
    fstream file1("count.txt");
    file1 << temp;
    file1.close();
}

void vaccine::record_byAadhar()
{

    // File pointer
    fstream fin;

    // Open an existing file
    fin.open("data.csv", ios::in);

    // Get the aadhar number
    // of which the data is required
    int count = 0;
    string aadhar, aadhar1;
    cout << "Enter the aadhar number : ";

    cin >> aadhar;

    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word, temp;

    while (!fin.eof())
    {

        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ','))
        {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        // convert string to integer for comparision
        aadhar1 = row[1];
        // Compare the aadhar number
        if (aadhar1 == aadhar)
        {

            // Print the found data
            count = 1;
            cout << "Name : " << row[0] << "\n";
            cout << "Aadher : " << row[1] << "\n";
            cout << "Age : " << row[2] << "\n";
            cout << "Gender : " << row[3] << "\n";
            cout << "Profession : " << row[4] << "\n";
            cout << "B.P : " << row[5] << "\n";
            cout << "Temperature : " << row[6] << "\n";
            cout << "Address : " << row[7] << "\n";
            cout << "Mobile No.: " << row[8] << "\n";
            break;
        }
    }
    if (count == 0)
        cout << "Record not found\n";
}

void vaccine::record_byName()
{

    fstream fin;

    fin.open("data.csv", ios::in);

    int count = 0;
    string name, name1;
    cout << "Enter the Name : ";

    cin >> name;

    vector<string> row;
    string line, word, temp;
    cout << setw(10) << " ";
    cout << left << setw(20) << "Name";
    cout << left << setw(20) << "Aadher";
    cout << left << setw(10) << "Age";
    cout << left << setw(10) << "Gender";
    cout << left << setw(15) << "Profession";
    cout << left << setw(10) << "B.P";
    cout << left << setw(15) << "Temperature";
    cout << left << setw(15) << "Mobile No.";
    cout << left << setw(15) << "Address" << endl;
    while (!fin.eof())
    {

        row.clear();

        getline(fin, line);

        stringstream s(line);

        while (getline(s, word, ','))
        {

            row.push_back(word);
        }
        name1 = row[0];

        if (name1 == name)
        {
            count = 1;
            cout << setw(10) << " ";
            cout << left << setw(20) << row[0];
            cout << left << setw(20) << row[1];
            cout << left << setw(10) << row[2];
            cout << left << setw(10) << row[3];
            cout << left << setw(15) << row[4];
            cout << left << setw(10) << row[5];
            cout << left << setw(15) << row[6];
            cout << left << setw(15) << row[7];
            cout << left << setw(15) << row[8] << endl;
        }
    }
    if (count == 0)
        cout << "Record not found\n";
}

void vaccine::record_byAge()
{
    fstream fin;

    fin.open("data.csv", ios::in);

    int age, age1, count = 0;

    cout << setw(64) << "Enter the Age : ";

    cin >> age;

    vector<string> row;
    string line, word, temp;
    cout << setw(10) << " ";
    cout << left << setw(20) << "Name";
    cout << left << setw(20) << "Aadher";
    cout << left << setw(10) << "Age";
    cout << left << setw(10) << "Gender";
    cout << left << setw(15) << "Profession";
    cout << left << setw(10) << "B.P";
    cout << left << setw(15) << "Temperature";
    cout << left << setw(15) << "Mobile No.";
    cout << left << setw(15) << "Address" << endl;
    while (!fin.eof())
    {

        row.clear();

        getline(fin, line);

        stringstream s(line);

        while (getline(s, word, ','))
        {

            row.push_back(word);
        }

        age1 = stoi(row[2]);

        if (age1 == age)
        {

            count = 1;
            cout << setw(10) << " ";
            cout << left << setw(20) << row[0];
            cout << left << setw(20) << row[1];
            cout << left << setw(10) << row[2];
            cout << left << setw(10) << row[3];
            cout << left << setw(15) << row[4];
            cout << left << setw(10) << row[5];
            cout << left << setw(15) << row[6];
            cout << left << setw(15) << row[7];
            cout << left << setw(15) << row[8] << endl;
        }
    }
    if (count == 0)
        cout << "Record not found\n";
}

void vaccine::record_byMobile()
{

    fstream fin;

    fin.open("data.csv", ios::in);

    int count = 0;
    string mobile, mobile1;
    cout << "Enter the Mobile No. : ";

    cin >> mobile;

    vector<string> row;
    string line, word, temp;
    cout << setw(10) << " ";
    cout << left << setw(20) << "Name";
    cout << left << setw(20) << "Aadher";
    cout << left << setw(10) << "Age";
    cout << left << setw(10) << "Gender";
    cout << left << setw(15) << "Profession";
    cout << left << setw(10) << "B.P";
    cout << left << setw(15) << "Temperature";
    cout << left << setw(15) << "Mobile No.";
    cout << left << setw(15) << "Address" << endl;
    while (!fin.eof())
    {

        row.clear();

        getline(fin, line);

        stringstream s(line);

        while (getline(s, word, ','))
        {

            row.push_back(word);
        }

        mobile1 = row[7];

        if (mobile1 == mobile)
        {

            count = 1;
            cout << setw(10) << " ";
            cout << left << setw(20) << row[0];
            cout << left << setw(20) << row[1];
            cout << left << setw(10) << row[2];
            cout << left << setw(10) << row[3];
            cout << left << setw(15) << row[4];
            cout << left << setw(10) << row[5];
            cout << left << setw(15) << row[6];
            cout << left << setw(15) << row[7];
            cout << left << setw(15) << row[8] << endl;
        }
    }
    if (count == 0)
        cout << "Record not found\n";
}

void vaccine::record_byGender()
{

    fstream fin;

    fin.open("data.csv", ios::in);

    int count = 0;
    char gender, gender1;
    cout << "Enter the Gender : ";

    cin >> gender;

    vector<string> row;
    string line, word, temp;
    cout << setw(10) << " ";
    cout << left << setw(20) << "Name";
    cout << left << setw(20) << "Aadher";
    cout << left << setw(10) << "Age";
    cout << left << setw(10) << "Gender";
    cout << left << setw(15) << "Profession";
    cout << left << setw(10) << "B.P";
    cout << left << setw(15) << "Temperature";
    cout << left << setw(15) << "Mobile No.";
    cout << left << setw(15) << "Address" << endl;
    while (!fin.eof())
    {

        row.clear();

        getline(fin, line);

        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        gender1 = row[3][0];
        if (gender1 == gender)
        {

            count = 1;
            cout << setw(10) << " ";
            cout << left << setw(20) << row[0];
            cout << left << setw(20) << row[1];
            cout << left << setw(10) << row[2];
            cout << left << setw(10) << row[3];
            cout << left << setw(15) << row[4];
            cout << left << setw(10) << row[5];
            cout << left << setw(15) << row[6];
            cout << left << setw(15) << row[7];
            cout << left << setw(15) << row[8] << endl;
        }
    }
    if (count == 0)
        cout << "Record not found\n";
}

void vaccine::record_byAddress()
{

    fstream fin;

    fin.open("data.csv", ios::in);

    int count = 0;
    string address, address1;
    cout << "Enter the Address : ";

    cin >> address;

    vector<string> row;
    string line, word, temp;
    cout << setw(10) << " ";
    cout << left << setw(20) << "Name";
    cout << left << setw(20) << "Aadher";
    cout << left << setw(10) << "Age";
    cout << left << setw(10) << "Gender";
    cout << left << setw(15) << "Profession";
    cout << left << setw(10) << "B.P";
    cout << left << setw(15) << "Temperature";
    cout << left << setw(15) << "Mobile No.";
    cout << left << setw(15) << "Address" << endl;
    while (!fin.eof())
    {

        row.clear();

        getline(fin, line);

        stringstream s(line);

        while (getline(s, word, ','))
        {

            row.push_back(word);
        }

        address1 = row[8];

        if (address1 == address)
        {

            count = 1;
            cout << setw(10) << " ";
            cout << left << setw(20) << row[0];
            cout << left << setw(20) << row[1];
            cout << left << setw(10) << row[2];
            cout << left << setw(10) << row[3];
            cout << left << setw(15) << row[4];
            cout << left << setw(10) << row[5];
            cout << left << setw(15) << row[6];
            cout << left << setw(15) << row[7];
            cout << left << setw(15) << row[8] << endl;
        }
    }
    if (count == 0)
        cout << "Record not found\n";
}

void vaccine::add()
{
    cout << setw(99) << "How much new vaccines do you want to add : ";
    int vaccines;
    cin >> vaccines;
    // Create and open a text file
    fstream file("count.txt");
    string ct;
    int temp;
    while (getline(file, ct))
    {
        temp = stoi(ct);
    }

    file.close();
    fstream file1("count.txt");
    file1 << temp + vaccines;
    file1.close();

    cout << endl;
    cout << setw(93) << "VACCINE ADDED SUCESSFULLY\n\n";
}
void user_login()
{
A:
    int k = 3;
B:
    fstream user;

    user.open("doctor.csv", ios::in);

    int count = 0;
    string uname, password;
    cout << setw(100) << "***************************************\n";
    cout << setw(85) << " \t\tENTER USERNAME AND PASSWORD\n";
    cout << setw(101) << "***************************************\n\n";
    while (k >= 1)
    {
        cout << setw(78) << "USERNAME : ";
        cin >> uname;
        cout << setw(78) << "PASSWORD : ";
        cin >> password;

        cout << endl;
        vector<string> row;
        string line, word, temp;
        while (!user.eof())
        {

            row.clear();

            getline(user, line);

            stringstream s(line);

            while (getline(s, word, ','))
            {

                row.push_back(word);
            }

            if (uname == row[0] && password == row[1])
            {
                cout << setw(90) << "LOGIN SUCESSFULLY\n\n";
                count++;
                user.close();
                break;
            }
        }
        if (count == 1)
        {
            break;
        }
        if (count == 0)
        {
            cout << setw(93) << "INVALID USERNAME OR PASSWORD\n\n";
            if (k >= 2)
            {
                cout << setw(80) << "you can try only " << --k << " more time\n\n";
                goto B;
            }

            else
            {
                cout << setw(85) << "try after 30 seconds\n";
                for (int i = 30; i >= 1; i--)
                {
                    cout << setw(65) << i << " seconds left........\n";
                    usleep(1000000);
                }
                goto A;
            }
        }
    }
    vaccine obj;
    int ch;
    do
    {
        cout << setw(98) << "***********************************\n";
        cout << setw(82) << "MENU \n";
        cout << setw(99) << "***********************************\n\n";
        cout << setw(70) << "1. Add New Record" << setw(40) << "2. View Vaccine Data\n"
             << setw(62) << "3. Search" << setw(36) << "4. exit\n\n";

        cout << setw(73) << "Enter your choice : ";

        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            obj.create();
            break;
        case 2:
            int ch1;
            do
            {
                cout << setw(98) << "***********************************\n";
                cout << setw(89) << "VACCINE STATISTICS\n";
                cout << setw(99) << "***********************************\n\n";
                cout << setw(67) << "1. Add more" << setw(40) << "2. View Available\n"
                     << setw(82) << "3 .Back\n\n";
                cout << setw(76) << "Enter your choice : ";
                cin >> ch1;
                cout << endl;
                switch (ch1)
                {
                case 1:
                    obj.add();
                    break;
                case 2:
                {
                    fstream file("count.txt");
                    string ct;
                    int temp;
                    while (getline(file, ct))
                    {
                        temp = stoi(ct);
                    }

                    file.close();
                    cout << setw(90) << "Availabe number of Vaccines are : " << temp << endl
                         << endl;
                    break;
                }
                default:
                    break;
                }
            } while (ch1 != 3);

            break;
        case 3:
            int choice;
            do
            {

                cout << setw(98) << "***********************************\n";
                cout << setw(90) << "SEARCHING STATISTICS\n";
                cout << setw(99) << "***********************************\n\n";
                cout << setw(60) << "1. By Aadhar" << setw(25) << "2. By Name" << setw(30) << "3.By Mobile No.\n"
                     << setw(57) << "4. By Age" << setw(31) << "5. By Address" << setw(24) << "6. By Gender\n"
                     << setw(84) << "0. Back\n\n";

                cout << setw(68) << "Enter your choice : ";
                cin >> choice;
                cout << endl;
                switch (choice)
                {
                case 1:
                    obj.record_byAadhar();
                    break;
                case 2:
                    obj.record_byName();
                    break;
                case 3:
                    obj.record_byMobile();
                    break;
                case 4:
                    obj.record_byAge();
                    break;
                case 5:
                    obj.record_byAddress();
                    break;
                case 6:
                    obj.record_byGender();
                    break;

                default:
                    break;
                }
            } while (choice != 0);

            break;
        default:
            break;
        }
    } while (ch != 4);
}
void admin_login()
{
A:
    int k = 3;
B:
    fstream admin;

    admin.open("admin.csv", ios::in);

    int count = 0;
    string uname, password;
    cout << setw(100) << "***************************************\n";
    cout << setw(85) << " \t\tENTER USERNAME AND PASSWORD\n";
    cout << setw(101) << "***************************************\n\n";
    while (k >= 1)
    {
        cout << setw(78) << "USERNAME : ";
        cin >> uname;
        cout << setw(78) << "PASSWORD : ";
        cin >> password;

        cout << endl;
        vector<string> row;
        string line, word, temp;
      
            row.clear();

            getline(admin, line);

            stringstream s(line);

            while (getline(s, word, ','))
            {

                row.push_back(word);
            }

            if (uname == row[0] && password == row[1])
            {
                cout << setw(90) << "LOGIN SUCESSFULLY\n\n";
                count++;
                admin.close();
                break;
            }
       
        if (count == 0)
        {
            cout << setw(93) << "INVALID USERNAME OR PASSWORD\n\n";
            if (k >= 2)
            {
                cout << setw(80) << "you can try only " << --k << " more time\n\n";
                goto B;
            }

            else
            {
                cout << setw(85) << "try after 30 seconds\n";
                for (int i = 30; i >= 1; i--)
                {
                    cout << setw(65) << i << " seconds left........\n";
                    usleep(1000000);
                }
                goto A;
            }
        }
    }
    vaccine obj;
    int ch;
    do
    {
        cout << setw(98) << "***********************************\n";
        cout << setw(82) << "MENU \n";
        cout << setw(99) << "***********************************\n\n";
        cout << setw(70) << "1. Add New Doctor" << setw(40) << "2. Add New Patient\n"
             << setw(62) << "3. View Vaccine Data" << setw(36) << "4. Search Doctor\n"
             << setw(62) << "5. Search Patient" << setw(36) << "6. Exit\n";

        cout << setw(73) << "Enter your choice : ";

        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            obj.create();
            break;
        case 2:
            int ch1;
            do
            {
                cout << setw(98) << "***********************************\n";
                cout << setw(89) << "VACCINE STATISTICS\n";
                cout << setw(99) << "***********************************\n\n";
                cout << setw(67) << "1. Add more" << setw(40) << "2. View Available\n"
                     << setw(82) << "3 .Back\n\n";
                cout << setw(76) << "Enter your choice : ";
                cin >> ch1;
                cout << endl;
                switch (ch1)
                {
                case 1:
                    obj.add();
                    break;
                case 2:
                {
                    fstream file("count.txt");
                    string ct;
                    int temp;
                    while (getline(file, ct))
                    {
                        temp = stoi(ct);
                    }

                    file.close();
                    cout << setw(90) << "Availabe number of Vaccines are : " << temp << endl
                         << endl;
                    break;
                }
                default:
                    break;
                }
            } while (ch1 != 3);

            break;
        case 3:
            int choice;
            do
            {

                cout << setw(98) << "***********************************\n";
                cout << setw(90) << "SEARCHING STATISTICS\n";
                cout << setw(99) << "***********************************\n\n";
                cout << setw(60) << "1. By Aadhar" << setw(25) << "2. By Name" << setw(30) << "3.By Mobile No.\n"
                     << setw(57) << "4. By Age" << setw(31) << "5. By Address" << setw(24) << "6. By Gender\n"
                     << setw(84) << "0. Back\n\n";

                cout << setw(68) << "Enter your choice : ";
                cin >> choice;
                cout << endl;
                switch (choice)
                {
                case 1:
                    obj.record_byAadhar();
                    break;
                case 2:
                    obj.record_byName();
                    break;
                case 3:
                    obj.record_byMobile();
                    break;
                case 4:
                    obj.record_byAge();
                    break;
                case 5:
                    obj.record_byAddress();
                    break;
                case 6:
                    obj.record_byGender();
                    break;

                default:
                    break;
                }
            } while (choice != 0);

            break;
        default:
            break;
        }
    } while (ch != 4);
}
int main()
{
    // user_login();
    admin_login();

    return 0;
}
