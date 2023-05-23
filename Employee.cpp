#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include<bits/stdc++.h>
using namespace std;
struct emp
{

    string name, id, address;

    long long salary, contact;
};
int total = 0;
emp e[100];
void empdata()
{

    int user = 0;

    cout << "How many employees data do you want to enter??" << endl;

    cin >> user;

    for (int i = total; i < total + user; i++)
    {

        cout << "Enter data of employee " << i + 1 << endl
             << endl;

        cout << "Enter employee name: ";

        cin >> e[i].name;

        cout << "Enter id: ";

        cin >> e[i].id;

        cout << "Enter address: ";

        cin >> e[i].address;

        cout << "Enter contact: ";

        cin >> e[i].contact;

        cout << "Enter salary: ";

        cin >> e[i].salary;
    }

    total = total + user;
}

void show()
{

    if (total != 0)
    {
        cout << "| ----------------  \t  ----- \t  -- \t\t ------- \t\t ------- \t\t  ------|" << endl;
        cout << "| Data of employee  \t  Name: \t  ID \t\t Address \t\t Contact \t\t  Salary|" << endl;
        for (int i = 0; i < total; i++)
        {

            cout << "|\t" << i + 1 << "\t |  ";

            cout << "\t" << e[i].name << "\t | ";

            cout << "\t" << e[i].id << "\t | ";

            cout << e[i].address << "\t | ";

            cout << e[i].contact << "\t | ";

            cout << "\t" << e[i].salary << "\t | ";
            cout << endl;
        }
        cout << "| ----------------  \t  ----- \t  -- \t\t ------- \t\t ------- \t\t  ------|" << endl;
    }

    else
    {

        cout << "No data is entered" << endl;
    }
}

void search()
{

    if (total != 0)
    {

        string id;

        cout << "Enter id of employee which you want to search" << endl;

        cin >> id;

        for (int i = 0; i < total; i++)
        {

            if (e[i].id == id)
            {

                cout << "Data of employee " << i + 1 << endl;

                cout << "Name: " << e[i].name << endl;

                cout << "ID: " << e[i].id << endl;

                cout << "Address: " << e[i].address << endl;

                cout << "Contact: " << e[i].contact << endl;

                cout << "Salary: " << e[i].salary << endl;

                break;
            }

            if (i == total - 1)
            {

                cout << "No such record found" << endl;
            }
        }
    }
    else
    {

        cout << "No data is entered" << endl;
    }
}

void update()
{

    if (total != 0)
    {

        string id;

        cout << "Enter id of employee which you want to update" << endl;

        cin >> id;

        for (int i = 0; i < total; i++)
        {

            if (e[i].id == id)
            {

                cout << "Old data of employee " << i + 1 << endl;

                cout << "Name: " << e[i].name << endl;

                cout << "ID: " << e[i].id << endl;

                cout << "Address: " << e[i].address << endl;

                cout << "Contact: " << e[i].contact << endl;

                cout << "Salary: " << e[i].salary << endl;

                cout << "\nEnter new data" << endl;

                cout << "Enter employee name: ";

                cin >> e[i].name;

                cout << "Enter id: ";

                cin >> e[i].id;

                cout << "Enter address: ";

                cin >> e[i].address;

                cout << "Enter contact: ";

                cin >> e[i].contact;

                cout << "Enter salary: ";

                cin >> e[i].salary;

                break;
            }

            if (i == total - 1)
            {

                cout << "No such record found" << endl;
            }
        }
    }
    else
    {

        cout << "No data is entered" << endl;
    }
}

void del()
{

    if (total != 0)
    {

        int press;

        cout << "Press 1 to delete specific record" << endl;

        cout << "Press 2 to delete full record" << endl;

        cin >> press;

        if (press == 1)
        {

            string id;

            cout << "Enter id of employee which you want to delete" << endl;

            cin >> id;

            for (int i = 0; i < total; i++)
            {

                if (e[i].id == id)
                {

                    e[i].name = e[i + 1].name;

                    e[i].id = e[i + 1].id;

                    e[i].address = e[i + 1].address;

                    e[i].contact = e[i + 1].contact;

                    e[i].salary = e[i + 1].salary;

                    total--;

                    cout << "Your required record is deleted" << endl;

                    break;
                }

                if (i == total - 1)
                {

                    cout << "No such record found" << endl;
                }
            }
        }

        else if (press == 2)
        {

            total = 0;

            cout << "All record is deleted" << endl;
        }

        else
        {

            cout << "Invalid Input" << endl;
        }
    }
    else
    {

        cout << "No data is entered" << endl;
    }
}

int main()
{

    system("color 0A");
    cout << "\n\n\t\tEmployee Management System" << endl;

  
    cout << "\n\n\t Press 1 for Login \n Press any Button for Signup" << endl;

    unordered_map<string, string> oldData;
    fstream f;
    f.open("password.txt", ios::app);
    if (!f)
        cout << "No such file found";
    else
    {
        string line;
        ifstream myfile("password.txt");

        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {

                string u = "", p = "", temp = "";
                for (int i = 0; i < line.size(); i++)
                {
                    if (line[i] == '$')
                    {
                        if (u == "")
                        {
                            u = temp;
                            temp = "";
                        }
                        else
                        {
                            p = temp;
                            oldData[u] = p;
                        }
                    }
                    else
                    {
                        temp += line[i];
                    }
                }
            }
            cout << "\n\n";
            myfile.close();
        }
        else

            cout << "Unable to open file\n\n";
    }

    int loginSignUp;
    cin >> loginSignUp;

//  for(auto x:oldData){
//     cout<<x.first<<" "<<x.second<<endl;
//  }

    if (loginSignUp == 1)
    {
        string usrn, pswd;

while (true)
{
            cout << "\n\n\n\t\t   LOGIN" << endl;

            cout << "\t\tEnter username: ";

            cin >> usrn;

            cout << "\t\tEnter password: ";
            cin >> pswd;
            if (oldData.find(usrn) == oldData.end())
            {
                cout << "USER NAME NOT FOUND" << endl;
            }
            else if (oldData.find(usrn) != oldData.end() and oldData[usrn]!=pswd){
        
                cout<<"PASSWORD INCORRECT"<<endl;
            }
            else{
                cout<<"LOGIN SUCCESSFULLY"<<endl;
                break;
            }
}

        

    }
    else
    {
string username, password;
cout << "\n\n\n\t\t******Signup******" << endl;

cout << "\t\tEnter new username: ";

cin >> username;

cout << "\t\tEnter new password: ";

cin >> password;
fstream f;
f.open("password.txt", ios::app);
// ofstream fout("password.txt", ios::out);
if (!f)
            cout << "No such file found";
        else
        {

            f << username << "$" << password<<"$" << "\n";
            f.close();
        }
        cout << "\t\tYour new id is creating please wait";

        for (int i = 0; i < 6; i++)

        {

            cout << ".";

            Sleep(500);
        }

        cout << "\n\t\tYour id created successfully";

        Sleep(2000);
    }

        system("CLS");

        char ch;

        while (1)
        {
      

        cout << "\n\nPress 1 to enter data" << endl;

        cout << "Press 2 to show data" << endl;

        cout << "Press 3 to search data" << endl;

        cout << "Press 4 to update data" << endl;

        cout << "Press 5 to delete data" << endl;

        cout << "Press 6 to logout" << endl;

        cout << "Press 7 to exit" << endl;

        ch = getch();

        system("CLS");

        switch (ch)
        {

        case '1':

            empdata();

            break;

        case '2':

            show();

            break;

        case '3':

            search();

            break;

        case '4':

            update();

            break;

        case '5':

            del();

            break;

        case '6':

                exit(0);
            break;

        case '7':

            exit(0);

            break;

        default:

            cout << "\aInvalid Input" << endl;

            break;
            }
        }
    return 0;
}


