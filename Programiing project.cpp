#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
void addproduct(string name, string price, string serial); //  mains functions ki prototype
void storedata(string name, string price, string serial);
void readdata(string name, string price, string serial);
void updateprice(string, string, string);
void searchproduct(string namme,string price,string serial);
void totalproducts();
const int range = 10;
string names[range];
string prices[range];
string serials[range];
int productcount = 0;
// Menu
char menu();

// sign in Functions
void signin(string username, string password); // prototype

// sign up Functions
void signup(string username, string password);    // prototype
bool isValidUsername(string username);            // prototype
bool checkuser(string username, string password); // prototype
void add_product();                               // prototype
void admin_page();                                // prototype

// File
void storeInFile(string username, string password);
void readdatafromfile();

const int size = 10;
string usernames[size];
string passwords[size];
int usercount = 0;
char option;

int main()
{
    string price, serial;
    string name;
    readdata(name, price, serial);
    system("cls");
    char choice;
    string username, password;
    readdatafromfile();
    if (choice != '0')
    {
        choice = menu();
        if (choice == '1')
        {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            bool result = isValidUsername(username); // ye function call krwaya hai jo chk krega k koi same usewrname tu ni hai
            if (result == true)
            {
                signup(username, password); // ye signup wala function call kraya hai
                storeInFile(username, password);
                cout << "Signed up succesfully" << endl;
                int c;
                cout << "press 1 for sign in" << endl;
                cin >> c;
                if (c == 1)
                {
                    system("cls");
                    signin(username, password);
                }
                getch();
            }
            else
            {
                cout << "User already exist" << endl;
                getch();
            }
        }
        if (choice == '2')
        {
            system("cls");

            signin(username, password); // ye signin wala function call kraya hai

            getch();
        }
    }
}

char menu()
{

    cout << "\n\n-----------------------------------------------Main Menu----------------------------------------------------------------\n\n\n"
         << endl;
    cout << " 1.  Sign Up";
    cout << "                                       2.  Sign In" << endl;
    cout << "\nEnter option: ";
    cin >> option;
    return option;
}

void signup(string username, string password) // username or password ko array main store krane wala function
{
    // system("cls");

    usernames[usercount] = username;
    passwords[usercount] = password;
    usercount++;
}

void storeInFile(string username, string password) // username or password ko file main save krane wala function
{
    fstream file;
    file.open("Users.txt", ios::app);
    file << username << endl;
    file << password << endl;
    file.close();
}

void signin(string username, string password) // signin wala function hai ye
{
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    bool check = checkuser(username, password);
    if (check == true)
    {
        int a;
        cout << "                                 Signed In succesfully                     " << endl;
        cout << "press 1 to go to admin page" << endl;
        cin >> a;
        system("cls");
        if (a == 1)
        {
            admin_page();
        }
    }
    else
    {
        cout << "Invalid entity" << endl;
        int e;
        cout << "press 1 to again sign in" << endl;
        cin >> e;
        if (e == 1)
        {
            signin(username, password);
        }
    }
}

bool isValidUsername(string username) // ye function chk krega k pehle koi same name se register tu nai hai
{
    bool flag = true;
    for (int i = 0; i < usercount; i++)
    {
        if (username == usernames[i])
        {
            flag = false;
            break;
        }
    }
    return flag;
}

bool checkuser(string username, string password) // ye function chk krega k user ne jo pass or username diya hai wo data main hai k nhi
{
    for (int i = 0; i < usercount; i++)
    {
        if (username == usernames[i] && password == passwords[i])
        {
            return true;
            break;
        }
    }
    return false;
}

void readdatafromfile()
{
    string username, password;
    fstream file;
    file.open("users.txt", ios::in);
    while (getline(file, username) && getline(file, password))
    {

        usernames[usercount] = username;
        passwords[usercount] = password;
        usercount++;
    }
    file.close();
}
void admin_page() //--------------------------------Admin page walA function---------------------------------------------------
{
    system("cls");
    cout << "\n\n\t\t\t\t***************Admin Page***************" << endl;
    cout << "\n1:Add Product" << endl;
    cout << "2:Search Product" << endl;
    cout << "3:Total product" << endl;
    cout << "4:Update price" << endl;

    int b;
    cout << "[Press  1, 2, 3 ,4 for Selection]= ";
    cin >> b; // variable declare for selection of options.
    system("cls");

    if (b == 1)
    {
        string price, serial;
        string name;
        cout << "\n\n\t\t\t\t***************Add product***************" << endl;
        cout << "Enter product name:";
        cin >> name;
        cout << "Enter price:";
        cin >> price;
        cout << "Enter serial number:";
        cin >> serial;
        addproduct(name, price, serial); // function call add product wala

        storedata(name, price, serial);
        int y;
        cout << "Press 1 to go back;";
        cin >> y;
        if (y == 1)
        {
            admin_page();
        }
    }
    else if (b == 2)
    {
    	string price, serial;
        string name;
        string namme;
        cout << "Enter the name of product:";
        cin >> namme;
        searchproduct( namme, price, serial);
        
        
    }
    else if (b == 3)
    {
        cout << "\n\n\t\t\t\t***************Total product***************" << endl;
        totalproducts();
        int w;
		cout<<"Press 1 TO GO BACK"<<endl;
        cin>>w;
        if(w==1)
        {
        	admin_page();
		}
    }
    else if (b == 4)
    {
        string name, price, serial;
        cout << "Enter the name of product you want to update: ";
        cin >> name;
        cout << "Enter new price: ";
        cin >> price;
        cout << "Enter new serial: ";
        cin >> serial;
        updateprice(name, price, serial);
        storedata(name, price, serial);
    }
}
//-----------------------------------------------------Add product wala function-------------------------------------------------------

void addproduct(string name, string price, string serial)
{
    names[productcount] = name;
    prices[productcount] = price;
    serials[productcount] = serial;
    productcount++;
    cout<<"product added successfully"<<endl;
}
void updateprice(string namee, string price, string serial)
{
    int count = 0;
    for (int i = 0; i < productcount; i++)
    {
        if (namee == names[i])
        {
            count = 1;
            prices[i] = price;
            serials[i] = serial;
            break;
        }
        else
        {
            count = 2;
            break;
        }
    }
    if(count == 1)
    {
        cout<<"Price and serial is updated successfully"<<endl;
        getch();
    }
    else if (count == 2)
    {
        cout<<"You enter invalid product"<<endl;
        getch();
    }
}
void searchproduct(string namme,string price,string serial)
{
	int count = 0;
    for (int i = 0; i < productcount; i++)
    {
        if (namme == names[i])
        {
            count = 1;
           cout<<"Product name:"<<names[i]<<endl;
           cout<<"Price:"<<prices[i]<<endl;
           cout<<"Serial Number:"<<serials[i]<<endl;
            break;
        }
        else
        {
            count = 2;
            break;
        }
    }
	if(count == 1)
    {
        cout<<"Display successfully"<<endl;
        getch();
    }
    else if (count == 2)
    {
        cout<<"You enter invalid product name"<<endl;
        getch();
    }
}

void storedata(string name, string price, string serial)
{
    fstream file;
    file.open("products.txt", ios::out);
    for (int i = 0; i < productcount; i++)
    {
        file << names[i] << endl;
        file << prices[i] << endl;
        file << serials[i] << endl;
        // cout << "Product added succesfully" << endl;
    }
    file.close();
}
void totalproducts()
{
    if (productcount == 0)
    {
        cout << "NO product added" << endl;
        cout << "press any key to continue" << endl;
        getch();
    }
    else
    {

        cout << "Product Name"
             << "\t\t"
             << "price"
             << "\t\t"
             << "serial number " << endl
             << endl;
        for (int i = 0; i < productcount; i++)
        {

            cout << names[i] << "\t\t\t" << prices[i] << "\t\t\t" << serials[i] << endl;
        }
    }
}
void readdata(string name, string price, string serial)
{
    fstream file;

    file.open("products.txt", ios::in);

    while (getline(file, name) && getline(file, price) && getline(file, serial))
    {
        names[productcount] = name;
        prices[productcount] = price;
        serials[productcount] = serial;
        productcount++;
    }

    file.close();
}
