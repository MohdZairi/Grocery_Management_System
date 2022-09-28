#include<iostream>
#include <iomanip>
#include<string>
#include<conio.h>
#include<mysql.h>


using namespace std;

// Global Variable
int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res; //result data


string AdminID, StaffID,StockID;//user season
//global Variable End


//Database Connection
class db_response
{
public:
    static void ConnectionFunction()
    {
        conn = mysql_init(0);
        if (conn)
        {
            cout << "Database Connected" << endl;
            cout << "Press any key to continue..." << endl;
            (void)getchar();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
        conn = mysql_real_connect(conn, "localhost", "root", "", "workshopzairi", 3306, NULL, 0);
        if (conn)
        {
            cout << "Database Connected To MySql" << conn << endl;
            cout << "Press any key to continue..." << endl;
            _getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
    }
};
//End Database Connection

//Function Declaration

void LoginAdmin();
void Adminmenu();
void ManageStaff();
void ViewStaff();
void AddStaff();
void DeleteStaff();
void EditStaff();
void SearchStaff();
void Managestock();
void StockInShop();
void Viewstockshop();
void Stockinshop();
void Stockoutshop();
void Deletestockshop();
void EditStockshop();
void SearchStockshop();
void StockInStore();
void Viewstockstore();
void Stockinstore();
void Stockoutstore();
void Deletestockstore();
void Editstockstore();
void Searchstockstore(); 
void GenerateReport();
void ReportStaff();
void ReportStock();
void LoginStaff();
void Staffmenu();
void ProfileStaff();
void ManageStock();
void StockShopStaff();
void ViewShopStaff();
void StockInStaff();
void StockOutStaff();
void StockSearchStaff();
void StockEditStaff();
void StockStoreStaff();
void ViewStoreStaff();
void InStoretaff();
void OutStoreStaff();
void EditStoreStaff();
void SearchStoreStaff();
void Color(unsigned short color);
void Graph();
int validateInputInt(string label);
int validateQuantity(string label);
double validatePrice(string label);
//End Function Declaration





void main()
{
   
    system("cls");
    system("title Stocks and Inventories System for Nasita Grocery Shop");
    system("color E");
    db_response::ConnectionFunction();
    
   
    int Option;
    char ExitSecurity;
START:
    system("cls");
    cout << "\t\t\t\t\t***********************************" << endl;
    cout << "\t\t\t\t\t* Welcome To A Grocery Management *" << endl;
    cout << "\t\t\t\t\t***********************************" << endl;
    cout << "\t\t\t\t\tPLEASE ENTER YOUR OPTION\n" << endl;
    cout << "\t\t\t\t\t1. LOGIN AS ADMIN\n\n";
    cout << "\t\t\t\t\t2. LOGIN AS STAFF\n\n";
    cout << "\t\t\t\t\t3. EXIT SYSTEM\n\n";
    cout << "\t\t\t\t\tNote: Choose Carefully :)\n";

    //cout << "\t\t\t\t\tChoose Your Option [By Number] : ";
    //cin >> Option;
    Option = validateInputInt("\t\t\t\t\tChoose Your Option [By Number] : ");

  
    switch (Option)
    {
    case 1:
        LoginAdmin();
        break;
    case 2:
        LoginStaff();
        break;
    case 3:
    ExitProgram:
        cout << "\n\n\t\t\t\t\tProgram terminating. Are you sure? Y/N): ";
        cin >> ExitSecurity;
        if (ExitSecurity == 'y' || ExitSecurity == 'Y') {
            exit(0);
        }
        else if (ExitSecurity == 'n' || ExitSecurity == 'N') {
            system("cls");
            main();
        }
        else {
            cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
            _getch();
            goto ExitProgram;
        }
        break;
    default:
        cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
        _getch();
        goto START;
        break;

    }
}

//Admin Fucntions
void LoginAdmin() 
{
    system("cls");
    string username, password;
    printf("\t\t\t\t\t-------Login Admin-------\n\n");
    cout << "\t\t\t\t\tUsername : ";
    cin.ignore(1, '\n'); // ignore space as next line
    getline(cin, username);
    cout << "\t\t\t\t\tPassword : ";
    char ch;
    while ((ch = _getch()) != 13)
    {
        password += ch;
        cout << '*';
    }

    cout << "\n";

    //check username & password ygg dimasukkan
    string checkUser_query = "select * from admin where Name = '" + username + "' and Password = '" + password + "'";
    const char* cu = checkUser_query.c_str();//convert
    qstate = mysql_query(conn, cu);//executee

    if (!qstate) //query boleh jalan
    {
        res = mysql_store_result(conn); //store result
        if (res->row_count == 1) //jumpa user
        {
            while (row = mysql_fetch_row(res)) //loop each of row dalam result
                AdminID = row[0]; //store Admin ID in variable

           Adminmenu();
        }
        else //tak jumpa user //username & password salah
        {
            char c;
            cout << "\n\n\t\t\t\t\tInvalid username or password. Want to try again (Y/N): ";
            cin >> c;
            if (c == 'y' || c == 'Y')
                LoginAdmin();
            else
                main();
        }
    }
}
void Adminmenu()
{
    int Option; char ExitSecurity;
    system("cls");
START:
    system("cls");
    cout << "\n\t\t\t\t\tAdmin >> Grocery Menu " << endl;
    cout << "\n\t\t\t\t\t1. Manage Staff";
    cout << "\n\t\t\t\t\t2. Manage Stock";
    cout << "\n\t\t\t\t\t3. Generate Report";
    cout << "\n\t\t\t\t\t4. Exit";
   // cout << "\t\t\t\t\t\tChoose Your Option [By Number] : ";
    Option = validateInputInt("\n\t\t\t\t\tChoose Your Option[By Number] :");

    switch (Option)
    {
    case 1:
        ManageStaff();
        break;
    case 2:
        Managestock();
        break;
    case 3:
        GenerateReport();
        break;
    case 4:
    ExitProgram:
        cout << "\n\t\t\t\t\tProgram terminating. Are you sure? (Y/N): ";
        cin >> ExitSecurity;
        if (ExitSecurity == 'y' || ExitSecurity == 'Y') {
            exit(0);
        }
        else if (ExitSecurity == 'n' || ExitSecurity == 'N') {
            system("cls");
            Adminmenu();
        }
        else {
            cout << "\n\t\t\t\t\tNext time choose after read the corresponding line ";
            _getch();
            goto ExitProgram;
        }
        break;
    default:
        cout << "\n\t\t\t\t\tNext time choose after read the corresponding line ";
        _getch();
        goto START;
        break;

    }
}
//Manage Staff Functions
void ManageStaff()
{
    int Option;
    char ExitSurity;
    system("cls"); 

START:
    system("cls");
    cout << "\n\t\t\t\t\tAdmin>>Manage Staff\n";
    cout << "\t\t\t\t\t1. View staff\n";
    cout << "\t\t\t\t\t2. Add New Staff\n";
    cout << "\t\t\t\t\t3. Delete Staff\n";
    cout << "\t\t\t\t\t4. Edit staff\n";
    cout << "\t\t\t\t\t5. Search staff\n";
    cout << "\t\t\t\t\t6. Back To Main Menu\n";
    cout << "\t\t\t\t\t7. Exit\n";
    //cout << "\n\t\t\t\t\t\tChoose Your Option [By Number] : ";
    Option=validateInputInt("\n\t\t\t\t\tChoose Your Option [By Number] : ");

    switch (Option)
    {
    case 1:
        ViewStaff();
        break;
    case 2:
        AddStaff();
        break;
    case 3:
        DeleteStaff();
        break;
    case 4:
        EditStaff();
        break;
    case 5:
        SearchStaff();
    case 6:
        Adminmenu();
        break;
    case 7:
    ExitProgram:
        cout << "\n\t\t\t\t\tProgram terminating. Are you sure (Y/N): ";
        cin >> ExitSurity;
        if (ExitSurity == 'y' || ExitSurity == 'Y') {
            return;
        }
        else if (ExitSurity == 'n' || ExitSurity == 'N') {
            system("cls");
            ManageStaff();
        }
        else {
            cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
            _getch();
            goto ExitProgram;
        }
        break;
    default:
        cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
        _getch();
        goto START;
        break;
    }
}
void ViewStaff()
{
    system("cls");
    char choose,ch;
    cout << "\n\t\t\t\t\tAdmin>>Manage Staff>>View Staff\n";

    qstate = mysql_query(conn, "select StaffID,Name,IC,Age,Gender,Address,Phone,Category,Password,Salary from staff");
    if (!qstate)
    {
        //create header
        printf("\t\t-----------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t|%-8s | %-20s | %-13s | %-8s | %-10s|%-28s | %-15s|%-10s| %-10s|", "STAFF ID", "STAFF NAME", "IC", "AGE", "GENDER", "ADDRESS", "PHONE", "CATEGORY","SALARY(RM)");
        printf("\n\t\t-----------------------------------------------------------------------------------------------------------------------------------------------\n");

        //body table
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
           
            printf("\t\t|%-8s | %-20s | %-13s | %-8s | %-10s|%-28s | %-15s|%-10s| %-10s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7],row[9]);
            cout << endl;

        }
        printf("\t\t-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    do
    {
        cout << "\n\t\t\t\t\tPress 'M' to menu : " ;
        cin >> choose;
        if (choose == 'M' || choose == 'm')
        {
            ManageStaff();
        }
    } while (choose != 'M' && choose != 'm');

}
void AddStaff()
{
    system("cls");
    char choose;
    cout << "\t\t\t\t\tAdmin>>Manage Staff>>Add New Staff\n\n";
    string Name, IC, Age, Gender, Address, Phone, Category, Password,Salary;
    int Year;

    cout << "\t\t\t\t\tEnter Name : ";
    cin.ignore(1,'\n');
    getline(cin, Name);
    cout << "\t\t\t\t\tEnter IC Numbers : ";
    getline(cin, IC);
    Year=validateInputInt("\t\t\t\t\tYear of Born : ");
    Age = to_string(2021 - Year);
    cout << "\t\t\t\t\tEnter Gender [F/M] : ";
    cin.ignore(1, '\n');
    getline(cin, Gender);
    cout << "\t\t\t\t\tEnter Your Address : ";
    getline(cin, Address);
    cout << "\t\t\t\t\tEnter Your Phone Number : ";
    getline(cin, Phone);
    cout << "\t\t\t\t\tEnter Category [FULL/PART -TIME]: ";
    getline(cin, Category);
    cout << "\t\t\t\t\tEnter Salary [RM]:";
    getline(cin, Salary);
    cout << "\t\t\t\t\tEnter Password : ";
    char ch;
    while ((ch = _getch()) != 13)
    {
        Password += ch;
        cout << '*';
    }

    cout << "\n";


    string insert_query = "insert into staff(Name,IC,Age,Gender,Address,Phone,Category,Salary,Password,AdminID) values ('" + Name + "','" + IC + "','" + Age + "','" + Gender + "','"+Address +"','" +Phone +"','" + Category +"','" + Salary + "','" +Password+ "','" +AdminID+ "')";
    const char* q = insert_query.c_str();
    qstate = mysql_query(conn, q);

    if (!qstate) //query boleh jalan
    {
        cout << endl << "\n\t\t\t\t\tStaff is successful added in database." << endl;
    }
    else
    {
        cout << "\n\t\t\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
    }

    do
    {
        cout << "\n\t\t\t\t\tPress 'M' to menu and 'E' for add staff again : ";
        cin >> choose;
        if (choose == 'M' || choose == 'm')
        {
            ManageStaff();
        }
        else if (choose == 'E' || choose == 'e')
        {
            AddStaff();
        }
    } while (choose != 'M' && choose != 'm' && choose != 'E' && choose != 'e');


}
void DeleteStaff()
{

    system("cls");
    int calc = 0;
    char Option,Option2;
    cout << "\t\t\t\t\tAdmin>>Manage Staff>>Delete Staff\n\n ";
    cin.ignore(1, '\n');
    cout <<"\t\t\t\t\tEnter Staff ID : ";
    getline(cin, StaffID);
    
    string search_query = "select StaffID,Name,IC,Age,Gender,Address,Phone,Category,Salary,Password from staff where StaffID = '" + StaffID + "'";
    const char* q = search_query.c_str();
    qstate = mysql_query(conn, q);
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //looping to retreive the data
    {
        cout << "\n\n\t\t\t\t\t--- Current Details of Staff ---" << endl;
        cout << "\t\t\t\t\tStaff ID: " << row[0]
            << "\n\n\t\t\t\t\t1. Name: " << row[1]
            << "\n\t\t\t\t\t2. IC : " << row[2]
            << "\n\t\t\t\t\t3. Age :  " << row[3]
            << "\n\t\t\t\t\t4. Gender : " << row[4]
            << "\n\t\t\t\t\t5. Address : " << row[5]
            << "\n\t\t\t\t\t6. Phone : " << row[6]
            << "\n\t\t\t\t\t7. Category : " << row[7]
            << "\n\t\t\t\t\t8. Salary : RM" << row[8];
           
        calc++;
    }

    if (calc > 0)
    {
       

        do
        {
            cout << "\n\n\t\t\t\t\tAre You Sure Want To Remove This Staff [Y/N] : ";
            cin >> Option;

            if (Option == 'y' || Option == 'Y')
            {
                string delete_query = "delete from  staff where StaffID = '" + StaffID + "'";
                const char* q = delete_query.c_str();
                qstate = mysql_query(conn, q);
                if (!qstate)
                {
                    cout << "\n\t\t\t\t\tThe Staff has been removed. Press Enter to Continue...";
                    _getch();
                    ViewStaff();
                }
                else
                {
                    cout << "\n\t\t\t\t\tQuery Execution Problem!" << mysql_errno(conn) << endl;
                }
            }
            else if (Option == 'n' || Option == 'N')
            {
                cout << "\n\n\t\t\t\t\tPress (D) For Delete Another Staff Or (M) Back To Menu : ";
                cin >> Option2;
                if (Option2 == 'D' || Option2 == 'd')
                    DeleteStaff();
                else if (Option2 == 'M' || Option2 == 'm')
                    ManageStaff();
            }
        } while (Option != 'Y' && Option != 'y' && Option != 'N' && Option != 'n');
    }
    else
    {
        cout << "\n\n\t\t\t\t\tStaff Is Not Exist";
        
        do
        {
            cout << "\n\n\t\t\t\t\tPress (D) For Delete Another Staff Or (M) Back To Menu : ";
            cin >> Option2;
            if (Option2 == 'D' || Option2 == 'd')
                DeleteStaff();
            else if (Option2 == 'M' || Option2 == 'm')
                ManageStaff();
        } while (Option2 != 'D' && Option2 != 'd' && Option2 != 'M' && Option2 != 'm');
    }
}
//display detail staff//
void EditStaff() 
{
    system("cls");

    string Name, IC, Age, Gender, Address, Phone, Category, Password,Salary;
    char Option,Option2;
    int Choose,calc=0;
    
    cout << "\t\t\t\t\tAdmin>>Manage Staff>>Edit Staff\n";
    cout << "\t\t\t\t\tEnter Staff ID: ";
    cin.ignore(1, '\n');
    getline(cin, StaffID);

    string search_query = "select StaffID,Name,IC,Age,Gender,Address,Phone,Category,Salary,Password from staff where StaffID = '" + StaffID + "'";
    const char* q = search_query.c_str();
    qstate = mysql_query(conn, q);
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //looping to retreive the data
    {
         cout << "\n\n\t\t\t\t\t--- Current Details of Staff ---" << endl;
        cout<< "\t\t\t\t\tStaff ID: " << row[0] << " (Uneditable)"
            << "\n\t\t\t\t\tGender : " << row[4] << " (Uneditable)"
            << "\n\n\t\t\t\t\t1. Name: " << row[1]
            << "\n\t\t\t\t\t2. IC : " << row[2]
            << "\n\t\t\t\t\t3. Age :  " << row[3]
            << "\n\t\t\t\t\t4. Address : " << row[5]
            << "\n\t\t\t\t\t5. Phone : " << row[6]
            << "\n\t\t\t\t\t6. Category : " << row[7]
            << "\n\t\t\t\t\t7. Salary : RM"<<row[8]
            << "\n\t\t\t\t\t8. Back To Menu";
        calc++;
    }
START:
    if (calc > 0)
    {
        // cout << "\n\nChoose Your Option [By Number] : ";
        Choose = validateInputInt("\n\n\t\t\t\t\tChoose Your Option [By Number] : ");

        cin.ignore(1, '\n');
        if (Choose == 1)
        {
            cout << "\n\t\t\t\t\tInsert New Name: ";
            getline(cin, Name);
            string update_query = "update staff set Name = '" + Name + "' where StaffID = '" + StaffID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }
        else if (Choose == 2)
        {
            cout << "\n\t\t\t\t\tInsert New IC Number: ";
            getline(cin, IC);
            string update_query = "update staff set IC = '" + IC + "' where StaffID = '" + StaffID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }
        else if (Choose == 3)
        {
            int age = 0;
            AGE:
            cout << "\n\t\t\t\t\tInsert New Age: ";
            getline(cin, Age);
            age = stoi(Age);
            if (age >= 17)
            {
                string update_query = "update staff set Age = '" + Age + "' where StaffID = '" + StaffID + "'";
                const char* q = update_query.c_str();
                qstate = mysql_query(conn, q);
            }
            else
            {
                cout << "\n\t\t\t\t\tInvalid Age..";
                _getch();
                goto AGE;
            }
        }
        else if (Choose == 4)
        {
            cout << "\n\t\t\t\t\tInsert New Address: ";
            getline(cin, Address);
            string update_query = "update staff set Address = '" + Address + "' where StaffID = '" + StaffID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }
        else if (Choose == 5)
        {
            cout << "\n\t\t\t\t\tInsert New Phone Number : ";
            getline(cin, Phone);
            string update_query = "update staff set Phone = '" + Phone + "' where StaffID = '" + StaffID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }
        else if (Choose == 6)
        {
            cout << "\n\t\t\t\t\tInsert New Category: ";
            getline(cin, Category);
            string update_query = "update staff set Category = '" + Category + "' where StaffID = '" + StaffID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }
        else  if (Choose == 7)
        {
            double salary = 0;
            //cout << "\n\t\t\t\t\tInsert New Salary:RM ";
            //getline(cin, Salary);
            salary = validatePrice("\n\t\t\t\t\tInsert New Salary:RM ");
            Salary = to_string(salary);
            string update_query = "update staff set Salary = '" + Salary + "' where StaffID = '" + StaffID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }
       
        else if (Choose == 8)
        {
            do
            {
                cout << "\n\t\t\t\t\tAre sure Want To Back Menu [Y/N].";
                cin >> Option;

                if (Option == 'N' || Option == 'n')
                {
                    EditStaff();
                }
                else if (Option == 'Y' || Option == 'y')
                {
                    ManageStaff();
                }
            } while (Option != 'Y' && Option != 'y' && Option != 'N' && Option != 'n');
        }
        else
        {
            cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
            _getch();
            goto START;
        }
    }
    else
    {
        cout << "\n\n\t\t\t\t\tStaf Is Never Exist\n\n";
    }

    do
    {
        cout << "\n\t\t\t\t\tPress (E) For Edit Another Staff Or (M) Back To Menu :";
        cin >> Option2;

        if (Option2 == 'E' || Option2 == 'e')
        {
            EditStaff();
        }
        else if (Option2 == 'M' || Option2 == 'm')
        {
            ManageStaff();
        }

    } while (Option2 != 'E' && Option2 != 'e' && Option2 != 'm' && Option2 != 'M');

}
void SearchStaff()
{
    int option;
    char Option;
    string name;
    system("cls");
    cout << "\t\t\t\t\tAdmin>>Manage Staff>>Search Staff\n";
    cout << "\n\t\t\t\t\tSearch By : ";
    cout << "\n\t\t\t\t\t1. Staff ID ";
    cout << "\n\t\t\t\t\t2. Name ";

    option = validateInputInt("\n\t\t\t\t\tChoose Your Option[By Number] :");
    if (option == 1)
    {
        cout << "\n\t\t\t\t\tEnter Staff ID: ";
        cin.ignore(1, '\n');
        getline(cin, StaffID);


        string search_query = "select StaffID,Name,IC,Age,Gender,Address,Phone,Category,Password,Salary from staff where StaffID = '" + StaffID + "'";
        const char* q = search_query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            //create header
            //create header
            printf("\n\t-----------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t|%-8s | %-20s | %-13s | %-8s | %-10s|%-28s | %-15s|%-10s| %-10s|", "STAFF ID", "STAFF NAME", "IC", "AGE", "GENDER", "ADDRESS", "PHONE", "CATEGORY", "SALARY(RM)");
            printf("\n\t-----------------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("\t|%-8s | %-20s | %-13s | %-8s | %-10s|%-28s | %-15s|%-10s| %-10s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[9]);
                cout << endl;

            }
            printf("\t-----------------------------------------------------------------------------------------------------------------------------------------------\n");
        }

        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if(option==2)
    {
        cout << "\n\t\t\t\t\tEnter Staff Name: ";
        cin.ignore(1, '\n');
        getline(cin, name);


        string search_query = "select StaffID,Name,IC,Age,Gender,Address,Phone,Category,Password,Salary from staff where Name like '%" + name + "%'";
        const char* q = search_query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            //create header
            printf("\n\t-----------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t|%-8s | %-20s | %-13s | %-8s | %-10s|%-28s | %-15s|%-10s| %-10s|", "STAFF ID", "STAFF NAME", "IC", "AGE", "GENDER", "ADDRESS", "PHONE", "CATEGORY", "SALARY(RM)");
            printf("\n\t-----------------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("\t|%-8s | %-20s | %-13s | %-8s | %-10s|%-28s | %-15s|%-10s| %-10s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[9]);
                cout << endl;

            }
            printf("\t-----------------------------------------------------------------------------------------------------------------------------------------------\n");
        }
    }
    else
    {
        cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
        _getch();
        SearchStaff();
    }
    do
    {
        cout << "\n\t\t\t\t\tPress (S) For Search Another Staff Or (M) Back To Menu : ";
        cin >> Option;

        if (Option == 'S' || Option == 's')
        {
            SearchStaff();
        }
        else if (Option == 'M' || Option == 'm')
        {
            ManageStaff();
        }

    } while (Option != 'S' && Option != 's' && Option != 'M' && Option != 'm');
}
//End Manage Staff Fucntion

//Stock Functions
void Managestock()
{
    char ExitSecurity;
    int Option;
    system("cls");

    cout << "\n\t\t\t\t\tAdmin>>Manage Stock";
    cout << "\n\t\t\t\t\t1. Manage Stock In Shop";
    cout << "\n\t\t\t\t\t2. Manage Stock In Store";
    cout << "\n\t\t\t\t\t3. Back to Main Menu";
    cout << "\n\t\t\t\t\t4. Exit\n";
    START:
   // cout << "\n\t\t\t\t\t\t\t\tChoose Your Option [By Number] : ";
    Option=validateInputInt("\n\t\t\t\t\tChoose Your Option [By Number] : ");
    switch (Option)
    {
    case 1:
        
       StockInShop();
        break;
    case 2:
        StockInStore();
        break;
    case 3:
        Adminmenu();
        break;
    case 4:
    ExitProgram:
        cout << "\n\t\t\t\t\tProgram terminating. Are you sure  [Y/N]: ";
        cin >> ExitSecurity;
        if (ExitSecurity == 'y' || ExitSecurity == 'Y') {
            exit(0);
        }
        else if (ExitSecurity == 'n' || ExitSecurity == 'N') {
            system("cls");
            Managestock();
        }
        else {
            cout << "\n\t\t\t\t\tNext time choose after read the corresponding line  ";
            _getch();
            goto ExitProgram;
        }
        break;
    default:
        cout << "\n\t\t\t\t\tNext time choose after read the corresponding line  ";
        _getch();
        goto START;
        break;
    }
    
}
void StockInShop() 
{
    int Option;
    char ExitSecurity;
    system("cls");
    cout << "\t\t\t\t\tAdmin>>Manage Stock>>Stock In Shop\n";
    cout << "\t\t\t\t\t1. View Stock\n";
    cout << "\t\t\t\t\t2. Stock In\n";
    cout << "\t\t\t\t\t3. Stock Out\n";
    cout << "\t\t\t\t\t4. Delete Stock\n";
    cout << "\t\t\t\t\t5. Edit Stock\n";
    cout << "\t\t\t\t\t6. Search Stock\n";
    cout << "\t\t\t\t\t7. Back To Stock Menu\n";
    cout << "\t\t\t\t\t8. Exit";
   // cout << "\t\t\t\t\tChoose Your Option [By Number] : ";
    START:
    Option=validateInputInt("\n\t\t\t\t\tChoose Your Option [By Number] : ");

    switch (Option)
    {
    case 1:
        Viewstockshop();
        break;
    case 2:
        Stockinshop();
        break;
    case 3:
        Stockoutshop();
        break;
    case 4:
        Deletestockshop();
        break;
    case 5:
        EditStockshop();
        break;
    case 6:
        SearchStockshop();
        break;
    case 7:
        Managestock();
    case 8:
    ExitProgram:
        cout << "\t\t\t\t\tProgram terminating. Are you sure (Y/N): ";
        cin >> ExitSecurity;
        if (ExitSecurity == 'y' || ExitSecurity == 'Y') {
            exit(0);
        }
        else if (ExitSecurity == 'n' || ExitSecurity == 'N') {
            system("cls");
            StockInShop();
        }
        else {
            cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
            _getch();

            goto ExitProgram;
        }
        break;
    default:
        cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
        _getch();
        goto START;
        break;

    }
}
void Viewstockshop() 
{
    char choose;

    system("cls");
    cout << "\t\t\t\t\tAdmin>>Manage Stock>>Stock In Shop>>View Stock\n\n";
    qstate = mysql_query(conn, "select StockID, Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop");

    //create header
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
    printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

    //body table
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //fetch every row until the end of data
    {
        printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
        cout << endl;
        
    }
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");

    cout << "\n\t\t\t\t\tPress 'M' to menu " << endl;
    cin >> choose;
    if (choose == 'M' || choose == 'm')
    {
        StockInShop();
    }
}
void Stockinshop() 
{
    string Name,Quantity,Buy,Selling,Category,Date,Value, Profit = "0";
    int calc,quan;
    char Option;
    double sell, buy;
    system("cls");
    cout << "\t\t\t\t\tAdmin>>Manage Stock>>Stock In Shop>>Add New Stock In Shop\n"; //add stock in shop
    cin.ignore(1, '\n');
    cout << "\t\t\t\t\tStock Name : ";
    getline(cin, Name);
    // cout<<"\t\t\t\t\tStock Quantity : ";

    quan = validateQuantity("\t\t\t\t\tStock Quantity : ");
    cin.ignore(1, '\n');
    Quantity = to_string(quan);
    //cout << "\t\t\t\t\tStock Price : RM";
    buy = validatePrice("\t\t\t\t\tStock Price : RM");
    cin.ignore(1, '\n');
    Buy = to_string(buy);
    //cout << "\t\t\t\t\tSelling Price : RM";
    sell = validatePrice("\t\t\t\t\tSelling Price : RM");
    cin.ignore(1, '\n');
    Selling = to_string(sell);
    cout << "\t\t\t\t\tCategory : ";
    getline(cin, Category);
    cout << "\t\t\t\t\tStock ExpireDate (dd-mm-yyyy) : ";            //YYYY-MM-DD //default date format - MySQL
    getline(cin, Date);

    double selling = stod(Selling);
    double quantity = stod(Quantity);
    Value = to_string(selling * quantity);

    string insert_query = "insert into stock_in_shop(AdminID,Name, Quantity, Stock_Price, Selling_Price, Category,Value,Profit,Exp_Date) values ('"+AdminID + "','" + Name + "','" + Quantity + "','" + Buy + "','" + Selling + "','" +Category + "','" + Value + "','" + Profit +"', STR_TO_DATE('" + Date + "', '%d/%m/%Y'))";
    const char* q = insert_query.c_str();
    qstate = mysql_query(conn, q);

    if (!qstate) //query boleh jalan
    {
        cout << endl << "\n\t\t\t\t\tStock is successful added in database." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }


    do
    {
        cout << "\n\n\t\t\t\t\tPress 'A' For Add Stock Again Or 'M' To Menu ";
        cin >> Option;
        if (Option == 'M' || Option == 'm')
        {
            StockInShop();
        }
        else if (Option == 'A' || Option == 'a')
        {
            Stockinshop();
        }
    } while (Option != 'M' && Option != 'm' && Option != 'A' && Option != 'a');
}
void Stockoutshop() 
{
    string Name, Quantity,Price,Profit;
    int stock=0,newQuantity,calc=0;
    double price=0,sale=0,profit;
    char Option,option2;
    system("cls");
    cout << "\t\t\t\t\tAdmin>>Manage Stock>>Stock In Shop>>Stock Out In Shop\n\n";
    cout << "\t\t\t\t\tEnter Stock ID : ";
    cin.ignore(1, '\n');
    getline(cin, StockID);
    string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category,Profit, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where StockID = '" + StockID + "'";
    const char* t = search_query2.c_str();
    qstate = mysql_query(conn, t);
    
    if (!qstate)
    {
        //create header
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

        //body table
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[7]);
            cout << endl;
            profit = stod(row[6]);
            calc++;

        }
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    

    //Update Quantity in menu
    string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where StockID = '" + StockID + "'";
    const char* q = search_query.c_str();
    qstate = mysql_query(conn, q);
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //looping to retreive the data
    {
        stock = stoi(row[2]); // stoi = convert string to integer
        price = stod(row[4]); //stod = convert string to double
        sale = stod(row[3]);
    }
    if (calc > 0)
    {
        // cout << "\n\t\t\t\t\tInsert Quantity For Stock Out : ";
        newQuantity = validateQuantity("\n\t\t\t\t\tInsert Quantity For Stock Out : ");
        if (newQuantity <= stock)
        {
            do
            {
                cout << "\n\t\t\t\t\tConfirm [Y/N] : ";
                cin >> option2;
                if (option2 == 'Y' || option2 == 'y')
                {
                    //Calculate Subtotal
                    Quantity = to_string(stock - newQuantity); //calculate
                    string update_query = "update stock_in_shop set Quantity = '" + Quantity + "' where StockID = '" + StockID + "'";
                    const char* r = update_query.c_str();
                    qstate = mysql_query(conn, r);


                    double quantity = stod(Quantity);
                    Price = to_string(quantity * price);
                    string update_query1 = "update stock_in_shop set Value = '" + Price + "' where StockID = '" + StockID + "'";
                    const char* s = update_query1.c_str();
                    qstate = mysql_query(conn, s);


                    Profit = to_string((((double)newQuantity) * (price - sale)) + profit);
                    string update_query3 = "update stock_in_shop set Profit = '" + Profit + "' where StockID = '" + StockID + "'";
                    const char* u = update_query3.c_str();
                    qstate = mysql_query(conn, u);

                    if (!qstate) //query boleh jalan
                    {
                        cout << endl << "\n\t\t\t\t\tStock is successful added in database." << endl;
                    }
                    else
                    {
                        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                    }
                }
                else if (option2 == 'N' || option2 == 'n')
                {
                    cout << "\n\t\t\t\t\tStock Out is Cancel\n";
                }
            } while (option2 != 'Y' && option2 != 'y' && option2 != 'N' && option2 != 'n');

        }
        else
        {
            cout << "\n\t\t\t\t\tQuantity Out Of Stock\n\n";
        }
    }
    else
    {
        cout << "\n\t\t\t\t\tStock Doesnt Exist\n\n";
    }

    do
    {
        cout << "\n\t\t\t\t\tPress 'A' For Add Stock Out Again Or 'M' To Menu." << endl;
        cin >> Option;
        if (Option == 'M' || Option == 'm')
        {
            StockInShop();
        }
        else if (Option == 'A' || Option == 'a')
        {
            Stockoutshop();
        }
    } while (Option != 'M' && Option != 'm' && Option != 'A' && Option != 'a');

}
void Deletestockshop() 
{
    system("cls");
    char Option,Option2;
    cout << "\t\t\t\t\tAdmin>Manage Stock>>Stock In Shop>Delete Stock\n";
    cout << "\t\t\t\t\tEnter Stock ID : ";
    cin >> StockID;
    string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where StockID = '" + StockID + "'";
    const char* t = search_query2.c_str();
    qstate = mysql_query(conn, t);

    if (!qstate)
    {
        //create header
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

        //body table
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
            cout << endl;

        }
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    }


    cout << "\n\n\t\t\t\t\tAre You Sure Want To Remove This Item? [Y/N] : ";
    cin >> Option;

    do
    {
        if (Option == 'y' || Option == 'Y')
        {
            string delete_query = "delete from  stock_in_shop where StockID = '" + StockID + "'";
            const char* q = delete_query.c_str();
            qstate = mysql_query(conn, q);
            if (!qstate)
            {
                cout << "\n\t\t\t\t\tThe Stock has been removed. Press Enter to Continue...";
                _getch();
                Viewstockshop();
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }
        }
        else if(Option == 'N' || Option == 'n')
        {
            cout << "\n\n\t\t\t\t\tPress (D) For Delete Another Item Or (M) Back To Menu\n";
            cin >> Option2;
            if (Option2 == 'D' || Option2 == 'd')
                Deletestockshop();
            else if (Option2 == 'M' || Option2 == 'm')
                StockInShop();
            
        }
    } while (Option != 'Y' && Option != 'y' && Option != 'N' && Option != 'n');

   
}
void EditStockshop() 
{
    string Name,Quantity, Buy, Selling, Category, Date,Price;
    int stock=0,Option,Newquantity,count=0;
    char Option2;
    double price = 0,sell,buy;
    system("cls");
    cout << "\t\t\t\t\tAdmin>>Manage Stock>>Stock In Shop>>Edit Stock\n";
    cout << "\t\t\t\t\tEnter Stock ID: ";
    cin.ignore(1, '\n');
    getline(cin, StockID);

    
    string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where StockID = '" + StockID + "'";
    const char* q = search_query.c_str();
    qstate = mysql_query(conn, q);
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //looping to retreive the data
    {
        cout << "\t\t\t\t\t--- Current Details of Stock ---" << endl;
        cout << "\t\t\t\t\tStock ID: " << row[0] << " (Uneditable)"
            << "\n\n\t\t\t\t\t1. Name: " << row[1]
            << "\n\t\t\t\t\t2. Quantity: " << row[2]
            << "\n\t\t\t\t\t3. Stock Price: RM " << row[3]
            << "\n\t\t\t\t\t4. Selling Price: RM " << row[4]
            << "\n\t\t\t\t\t5. Category: " << row[5]
            << "\n\t\t\t\t\t6. Expired Date: " << row[6]
            << "\n\t\t\t\t\t7. Save.";
        stock = stoi(row[2]); // stoi = convert string to integer
        price = stod(row[4]);
        count++;

    }
    START:
    if (count > 0)
    {
        //cout << "\n\n\t\t\t\t\tChoose Your Option [By Number] : ";
        Option=validateInputInt("\n\n\t\t\t\t\tChoose Your Option [By Number] : ");

        cin.ignore(1, '\n');
        if (Option == 1)
        {
            cout << "\t\t\t\t\tInsert New Name: ";
            getline(cin, Name);
            string update_query = "update stock_in_shop set Name = '" + Name + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }


        else if (Option == 2)
        {
            //cout << "\t\t\t\t\tInsert New Quantity: ";
            Newquantity=validateQuantity("\t\t\t\t\tInsert New Quantity: ");
            Quantity = to_string(stock + Newquantity); //calculate
            string update_query = "update stock_in_shop set Quantity = '" + Quantity + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);

            double quantity = stod(Quantity);
            Price = to_string(quantity * price);
            string update_query1 = "update stock_in_shop set Value = '" + Price + "' where StockID = '" + StockID + "'";
            const char* s = update_query1.c_str();
            qstate = mysql_query(conn, s);

        }
        else if (Option == 3)
        {
           
            buy = validatePrice("\n\n\t\t\t\t\tInsert New Stock Price: RM ");
            Buy = to_string(buy);
            //getline(cin, Buy);
            string update_query = "update stock_in_shop set Stock_Price = '" + Buy + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);

        }
        else if (Option == 4)
        {
     
            sell = validatePrice("\n\n\t\t\t\t\tInsert New Selling Price: RM ");
            Selling = to_string(sell);
            string update_query = "update stock_in_shop set Selling_Price = '" + Selling + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);

            double selling = stod(Selling);
            Price = to_string(selling * ((double)stock));
            string update_query1 = "update stock_in_shop set Value = '" + Price + "' where StockID = '" + StockID + "'";
            const char* s = update_query1.c_str();
            qstate = mysql_query(conn, s);
        }
        else if (Option == 5)
        {
            cout << "Insert New Category :";
            getline(cin, Category);
            string update_query = "update stock_in_shop set Category = '" + Category + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }
        else if (Option == 6)
        {
            cout << "Insert New Exp Date (dd/mm/yyyy): ";
            getline(cin, Date);
            string update_query = "update Stock_in_shop set Exp_Date = STR_TO_DATE('" + Date + "', '%d/%m/%Y') where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }
        else if (Option == 7)
        {
            cout << "\nThe Stock  has been saved. Press Enter to Continue...";
            _getch();
        }
        else
        {
            cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
            _getch();
            goto START;
        }
    }
    else
    {
        cout << "\nStock Not Found!!.Press Enter To Continue\n";
        _getch();
    }
   
    
    do
    {
        cout << "\n\t\t\t\t\tPress (E) For Edit Another Item Or (M) Back To Menu : ";
        cin >> Option2;

        if (Option2 == 'E' || Option2 == 'e')
        {
            EditStockshop();
        }
        else if (Option2 == 'M' || Option2 == 'm')
        {
            StockInShop();
        }

    } while (Option2 != 'E' && Option2 != 'e' && Option2 != 'm' && Option2 != 'M');

}
void SearchStockshop() 
{
    char Option;
    int choose;
    string Name,Category,Date;
    system("cls");
    cout << "\t\t\t\t\tAdmin>>Manage Stock>>Stock In Shop>>Search Stock\n";
    cout << "\t\t\t\t\tSearch by : ";
    cout << "\n\t\t\t\t\t1. Stock Name ";
    cout << "\n\t\t\t\t\t2. Stock ID ";
    cout << "\n\t\t\t\t\t3. Stock Category ";
    cout << "\n\t\t\t\t\t4. Stock Date ";
START:
    choose = validateInputInt("\n\n\t\t\t\t\tChoose Your Option [By Number] : ");

    if (choose == 1)
    {
        cout << "\t\t\t\t\tEnter Stock Name : ";
        cin.ignore(1, '\n');
        getline(cin, Name);
        string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where Name like '%" + Name + "%'";
        const char* t = search_query2.c_str();
        qstate = mysql_query(conn, t);

        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if (choose == 2)
    {
        cout << "\t\t\t\t\tEnter Stock ID : ";
        cin.ignore(1, '\n');
        getline(cin, StockID);
        string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where StockID = '" + StockID + "'";
        const char* t = search_query2.c_str();
        qstate = mysql_query(conn, t);

        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if (choose == 3)
    {
        cout << "\t\t\t\t\tEnter Stock Category : ";
        cin.ignore(1, '\n');
        getline(cin, Category);
        string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where Category = '" + Category + "'";
        const char* t = search_query2.c_str();
        qstate = mysql_query(conn, t);

        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if (choose == 4)
    {
        cout << "\t\t\t\t\tEnter Stock Date : ";
        cin.ignore(1, '\n');
        getline(cin, Date);
        string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where Exp_Date =STR_TO_DATE('" + Date + "','%d/%m/%Y')";
        const char* t = search_query2.c_str();
        qstate = mysql_query(conn, t);

        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
   
    else
    {
        cout << "\t\t\t\t\tNext time choose after read the corresponding line : ";
        _getch();
        goto START;

    }
    do
    {
        cout << "\n\t\t\t\t\tPress (S) For Search Another Item Or (M) Back To Menu : ";
        cin >> Option;

        if (Option == 'S' || Option == 's')
        {
            SearchStockshop();
        }
        else if (Option == 'M' || Option == 'm')
        {
            StockInShop();
        }

    } while (Option != 'S' && Option != 's' && Option != 'M' && Option != 'm');
}
void StockInStore() 
{
    int Option;
    char ExitSecurity;
    system("cls");
    cout << "\n\t\t\t\t\tAdmin>>Manage Stock>>Stock In Store\n";
    cout << "\t\t\t\t\t1. View Stock\n";
    cout << "\t\t\t\t\t2. Stock In\n";
    cout << "\t\t\t\t\t3. Stock Out\n";
    cout << "\t\t\t\t\t4. Delete Stock\n";
    cout << "\t\t\t\t\t5. Edit Stock\n";
    cout << "\t\t\t\t\t6. Search Stock\n";
    cout << "\t\t\t\t\t7. Back To Stock Menu\n";
    cout << "\t\t\t\t\t8. Exit\n";
    //cout << "\n\t\t\t\t\tChoose Your Option [By Number] : ";
    START: 
    Option=validateInputInt("\n\t\t\t\t\tChoose Your Option [By Number] : ");

    switch (Option)
    {
    case 1:
        Viewstockstore();
        break;
    case 2:
        Stockinstore();
        break;
    case 3:
        Stockoutstore();
        break;
    case 4:
        Deletestockstore();
        break;
    case 5:
        Editstockstore();
        break;
    case 6:
        Searchstockstore();
        break;
    case 7:
        Managestock();
    case 8:
    ExitProgram:
        cout << "\n\t\t\t\t\tProgram terminating. Are you sure? (Y/N): ";
        cin >> ExitSecurity;
        if (ExitSecurity == 'y' || ExitSecurity == 'Y') {
            exit(0);
        }
        else if (ExitSecurity == 'n' || ExitSecurity == 'N') {
            system("cls");
            StockInStore();
        }
        else {
            cout << "\n\t\t\t\t\tNext time choose after read the corresponding line ";
            goto ExitProgram;
        }
        break;
    default:
        cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
        _getch();
        goto START;
        break;
    }
}
void Viewstockstore()
{
    char choose;

    system("cls");
    cout << "\t\t\t\t\tAdmin>>Manage Stock>>Stock In Store>>View Stock\n\n";
    qstate = mysql_query(conn, "select  StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store");

    //create header
    printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|%-10s|%-25s | %-15s | %-16s | %-15s | %-16s|%-20s |","STOCK ID","STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
    printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");

    //body table
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //fetch every row until the end of data
    {
        printf("|%-10s|%-25s | %-15s | %-16s | %-15s | %-16s|%-20s |", row[0], row[1], row[2], row[3], row[4], row[5],row[6]);
        cout << endl;

    }
    printf("--------------------------------------------------------------------------------------------------------------------------------------\n");

    cout << "\n\t\t\t\t\tPress 'M' to menu : ";
    cin >> choose;
    if (choose == 'M' || choose == 'm')
    {
        StockInStore();
    }
}
void Stockinstore()
{
    string Name, Quantity, Buy, Selling, Category, Date,Value;
    int ID;
    char Option;
    system("cls");
    cout << "Admin>>Manage Stock>>Stock In Store>>Add New Stock In Store\n\n"; //add stock in shop
    cin.ignore(1, '\n');
    cout << "Stock Name : ";
    getline(cin, Name);
    cout << "Stock Quantity : ";
    getline(cin, Quantity);
    cout << "Stock Price : RM";
    getline(cin, Buy);
    cout << "Selling Price : RM";
    getline(cin, Selling);
    cout << "Category : ";
    getline(cin, Category);
    cout << "Stock ExpireDate (dd-mm-yyyy) : ";            //YYYY-MM-DD //default date format - MySQL
    getline(cin, Date);

    //FIND STOCKID IN SHOP
    string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where Name like '%" + Name + "%'";
    const char* q = search_query.c_str();
    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            ID = stoi(row[0]);
        }
        StockID = to_string(ID);
    }
    //END SEARCHING

    double selling = stod(Selling);
    double quantity = stod(Quantity);
    Value = to_string(selling * quantity);


    //Insert Data about stock in store
    string insert_query = "insert into stock_in_store(StockID,Name, Quantity, Stock_Price, Selling_Price, Category,Value,Exp_Date) values ('"+StockID+ "','" + Name + "','" + Quantity + "','" + Buy + "','" + Selling + "','" + Category + "','" + Value + "', STR_TO_DATE('" + Date + "', '%d/%m/%Y'))";
    const char* r = insert_query.c_str();
    qstate = mysql_query(conn, r);

    if (!qstate) //query boleh jalan
    {
        cout << endl << "Stock is successful added in database." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    //end Insert



    do
    {
        cout << "Press 'A' For Add Stock Again Or 'M' To Menu." << endl;
        cin >> Option;
        if (Option == 'M' || Option == 'm')
        {
            StockInStore();
        }
        else if (Option == 'A' || Option == 'a')
        {
            Stockinstore();
        }
    } while (Option != 'M' && Option != 'm' && Option != 'A' && Option != 'a');
}
void Stockoutstore()
{
    string Name, Quantity,Price;
    int stock = 0, newQuantity,calc=0;
    char Option,Option2;
    double price=0;
    system("cls");
    cout << "\n\t\t\t\t\tAdmin>>Manage Stock>>Stock In Shop>>Stock Out In Store\n";
    cout << "\n\t\t\t\t\tEnter Stock ID : ";
    cin.ignore(1, '\n');
    getline(cin, StockID);

    string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where StockID = '" + StockID + "'";
    const char* t = search_query2.c_str();
    qstate = mysql_query(conn, t);

    if (!qstate)
    {
        //create header
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

        //body table
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
            cout << endl;
            calc++;
        }
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    //Update Quantity in menu
    string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where StockID = '" + StockID + "'";
    const char* q = search_query.c_str();
    qstate = mysql_query(conn, q);
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //looping to retreive the data
    {
        stock = stoi(row[2]); // stoi = convert string to integer
        price = stod(row[4]); //stod = convert string to double
       
    }

    if (calc > 0)
    {
        //cout << "\n\n\t\t\t\t\tInsert Quantity For Stock Out: ";
        newQuantity = validateQuantity("\n\n\t\t\t\t\tInsert Quantity For Stock Out: ");

        if (newQuantity <= stock)
        {
            do
            {
                cout << "\n\n\t\t\t\t\tConfirm [Y/N] : ";
                cin >> Option2;
                if (Option2 == 'Y' || Option2 == 'y')
                {
                    //Calculate New Quantity
                    Quantity = to_string(stock - newQuantity); //calculate
                    string update_query = "update stock_in_store set Quantity = '" + Quantity + "' where StockID = '" + StockID + "'";
                    const char* r = update_query.c_str();
                    qstate = mysql_query(conn, r);

                    double quantity = stod(Quantity);
                    Price = to_string(quantity * price);
                    string update_query1 = "update stock_in_store set Value = '" + Price + "' where StockID = '" + StockID + "'";
                    const char* s = update_query1.c_str();
                    qstate = mysql_query(conn, s);


                    if (!qstate) //query boleh jalan
                    {
                        cout << endl << "\n\n\t\t\t\t\tStock is successful out in database." << endl;
                    }
                    else
                    {
                        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                    }
                }
                else if (Option2 == 'N' || Option2 == 'n')
                {
                    cout << "\n\n\t\t\t\t\tStock Out Cancel..\n";
                    _getch();
                }
            } while (Option2 != 'Y' && Option2 != 'y' && Option2 != 'N' && Option2 != 'n');
        }

        else
        {
            cout << "\n\n\t\t\t\t\tStock is Out Of Range\n";
        }
    }
    else
    {
        cout << "\n\n\t\t\t\t\tStock Doesnt Exist\n";
    }
    do
    {
        cout << "\n\n\t\t\t\t\tPress 'A' For Add Stock Out Again Or 'M' To Menu : ";
        cin >> Option;
        if (Option == 'M' || Option == 'm')
        {
            StockInStore();
        }
        else if (Option == 'A' || Option == 'a')
        {
            Stockoutstore();
        }
    } while (Option != 'M' && Option != 'm' && Option != 'A' && Option != 'a');

}
void Deletestockstore()
{
    system("cls");
    char Option,Option2;
    cout << "\t\t\t\t\tAdmin>Manage Stock>>Stock In Store>Delete Stock\n";
    cout << "\t\t\t\t\tEnter Stock ID : ";
    cin >> StockID;
    string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where StockID = '" + StockID + "'";
    const char* q = search_query.c_str();
    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        //create header
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

        //body table
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
            cout << endl;

        }
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    }
   

    do
    {
        cout << "\n\n\t\t\t\t\tAre You Sure Want To Remove This Item [Y/N] : ";
        cin >> Option;
        if (Option == 'y' || Option == 'Y')
        {
            string delete_query = "delete from  stock_in_store where StockID = '" + StockID + "'";
            const char* q = delete_query.c_str();
            qstate = mysql_query(conn, q);
            if (!qstate)
            {
                cout << "\n\n\t\t\t\t\tThe Stock has been removed. Press Enter to Continue...\n\n";
                _getch();
                Viewstockstore();
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }
        }
        else if (Option == 'N' || Option == 'n')
        {
            cout << "\n\n\t\t\t\t\tPress (D) For Delete Another Item Or (M) Back To Menu\n";
            cin >> Option2;
            if (Option2 == 'D' || Option2 == 'd')
                Deletestockstore();
            else if (Option2 == 'M' || Option2 == 'm')
                StockInStore();
        }
    } while (Option != 'Y' && Option != 'y' && Option != 'N' && Option != 'n');

}
void Editstockstore()
{
    string Name, Quantity, Buy, Selling, Category, Date,Price;
    int stock = 0, Option, Newquantity,count=0;
    char Option2;
    double price = 0,buy,sell;
    system("cls");
    cout << "\n\n\t\t\t\t\tAdmin>>Manage Stock>>Stock In Store>>Edit Stock\n";
    cout << "\t\t\t\t\tEnter Stock ID: ";
    cin.ignore(1, '\n');
    getline(cin, StockID);

    //Update Quantity in menu
    string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where StockID = '" + StockID + "'";
    const char* q = search_query.c_str();
    qstate = mysql_query(conn, q);

        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //looping to retreive the data
        {

            cout << "\t\t\t\t\t--- Current Details of Stock ---" << endl;
            cout << "\t\t\t\t\tStock ID: " << row[0] << " (Uneditable)"
                << "\n\n\t\t\t\t\t1. Name: " << row[1]
                << "\n\t\t\t\t\t2. Quantity: " << row[2]
                << "\n\t\t\t\t\t3. Stock Price: RM " << row[3]
                << "\n\t\t\t\t\t4. Selling Price: RM " << row[4]
                << "\n\t\t\t\t\t5. Category: " << row[5]
                << "\n\t\t\t\t\t6. Expired Date: " << row[6]
                << "\n\t\t\t\t\t7. Save";
            stock = stoi(row[2]); // stoi = convert string to integer
            price = stod(row[4]);
            count++;
        }
        START:
        if (count > 0)
        {
            //cout << "\n\n\t\t\t\t\tChoose Your Option [By Number] : ";
            Option=validateInputInt("\n\n\t\t\t\t\tChoose Your Option [By Number] : ");

            cin.ignore(1, '\n');
            if (Option == 1)
            {
                cout << "\n\t\t\t\t\tInsert New Name: ";
                getline(cin, Name);
                string update_query = "update stock_in_store set Name = '" + Name + "' where StockID = '" + StockID + "'";
                const char* q = update_query.c_str();
                qstate = mysql_query(conn, q);
            }


            else if (Option == 2)
            {
                //cout << "\n\t\t\t\t\tInsert New Quantity: ";
                Newquantity=validateQuantity("\n\t\t\t\t\tInsert New Quantity: ");
                Quantity = to_string(stock + Newquantity); //calculate
                string update_query = "update stock_in_store set Quantity = '" + Quantity + "' where StockID = '" + StockID + "'";
                const char* q = update_query.c_str();
                qstate = mysql_query(conn, q);

                double quantity = stod(Quantity);
                Price = to_string(quantity * price);
                string update_query1 = "update stock_in_store set Value = '" + Price + "' where StockID = '" + StockID + "'";
                const char* s = update_query1.c_str();
                qstate = mysql_query(conn, s);
            }
            else if (Option == 3)
            {
               // cout << "\n\t\t\t\t\tInsert New Stock Price: RM ";
                buy = validatePrice("\n\t\t\t\t\tInsert New Stock Price: RM ");
                Buy = to_string(buy);
                string update_query = "update stock_in_store set Stock_Price = '" + Buy + "' where StockID = '" + StockID + "'";
                const char* q = update_query.c_str();
                qstate = mysql_query(conn, q);

            }
            else if (Option == 4)
            {
               // cout << "Insert New Selling Price: RM ";
                sell = validatePrice("\n\t\t\t\t\tInsert New Selling Price : RM ");
                Selling = to_string(sell);
                //getline(cin, Selling);
                string update_query = "update stock_in_store set Selling_Price = '" + Selling + "' where StockID = '" + StockID + "'";
                const char* q = update_query.c_str();
                qstate = mysql_query(conn, q);

                double selling = stod(Selling);
                Price = to_string(selling * ((double)stock));
                string update_query1 = "update stock_in_store set Value = '" + Price + "' where StockID = '" + StockID + "'";
                const char* s = update_query1.c_str();
                qstate = mysql_query(conn, s);
            }
            else if (Option == 5)
            {
                cout << "\n\t\t\t\t\tInsert New Category :";
                getline(cin, Category);
                string update_query = "update stock_in_store set Category = '" + Category + "' where StockID = '" + StockID + "'";
                const char* q = update_query.c_str();
                qstate = mysql_query(conn, q);
            }
            else if (Option == 6)
            {
                cout << "\n\t\t\t\t\tInsert New Exp Date (dd/mm/yyyy): ";
                getline(cin, Date);
                string update_query = "update stock_in_store set Exp_Date = STR_TO_DATE('" + Date + "', '%d/%m/%Y') where StockID = '" + StockID + "'";
                const char* q = update_query.c_str();
                qstate = mysql_query(conn, q);
            }
            else if (Option == 7)
            {
                cout << "\n\t\t\t\t\tThe Stock  has been saved. Press Enter to Continue...";
                _getch();
            }
            else
            {
                cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
                _getch();
                goto START;
            }
        }

        else
        {
            cout << "\n\t\t\t\t\tStock Not Found!!.Press Enter To Continue\n";
            _getch();
        }
        
        do
        {
            cout << "\n\t\t\t\t\tPress (E) For Edit Another Item Or (M) Back To Menu.\n";
            cin >> Option2;

            if (Option2 == 'E' || Option2 == 'e')
            {
                Editstockstore();
            }
            else if (Option2 == 'M' || Option2 == 'm')
            {
                StockInStore();
            }

        } while (Option2 != 'E' && Option2 != 'e' && Option2 != 'm' && Option2 != 'M');

}
void Searchstockstore()
{
    char Option;
    int choose;
    string name,Category,Date;
    system("cls");
    cout << "\t\t\t\t\tAdmin>>Manage Stock>>Stock In Store>>Search Stock\n";
    cout << "\t\t\t\t\tSearch By : \n";
    cout << "\t\t\t\t\t1. Stock ID \n";
    cout << "\t\t\t\t\t2. Stock Name\n";
    cout << "\t\t\t\t\t3. Stock Category\n";
    cout << "\t\t\t\t\t4. Stock Date\n";
    

START:
    choose = validateInputInt("\n\t\t\t\t\tChoose Your Option[By Number] : ");

    if (choose == 1)
    {
        cout << "\n\t\t\t\t\tEnter Stock ID: ";
        cin.ignore(1, '\n');
        getline(cin, StockID);
        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where StockID = '" + StockID + "'";
        const char* q = search_query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if (choose == 2)
    {
        cout << "\n\t\t\t\t\tEnter Stock Name: ";
        cin.ignore(1, '\n');
        getline(cin, name);
        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where Name like '%" + name + "%'";
        const char* q = search_query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if (choose == 3)
    {
        cout << "\t\t\t\t\tEnter Stock Category : ";
        cin.ignore(1, '\n');
        getline(cin, Category);
        string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where Category = '" + Category + "'";
        const char* t = search_query2.c_str();
        qstate = mysql_query(conn, t);

        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if (choose == 4)
    {
        cout << "\t\t\t\t\tEnter Stock Date : ";
        cin.ignore(1, '\n');
        getline(cin, Date);
        string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where Exp_Date =STR_TO_DATE('" + Date + "','%d/%m/%Y')";
        const char* t = search_query2.c_str();
        qstate = mysql_query(conn, t);

        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }

    else
    {
        cout << "\t\t\t\t\tNext time choose after read the corresponding line : ";
        _getch();
        goto START;
    }
    do
    {
        cout << "\n\t\t\t\t\tPress (S) For Search Another Item Or (M) Back To Menu.\n";
        cin >> Option;

        if (Option == 'S' || Option == 's')
        {
            Searchstockstore();
        }
        else if (Option == 'M' || Option == 'm')
        {
            StockInStore();
        }

    } while (Option != 'S' && Option != 's' && Option != 'M' && Option != 'm');
}
//End Stock Functions
//Generate report
void GenerateReport()
{
    
    system("cls");
    int Option;
START:
    system("cls");
    system("cls");
    cout << "\t\t\t\t\tAdmin>>Generate Report\n\n";
    cout << "\t\t\t\t\t1. Report Staff\n";
    cout << "\t\t\t\t\t2. Report Stock\n";
    cout << "\t\t\t\t\t3. Graph\n";
    cout << "\t\t\t\t\t4. Back To Menu\n";
    //cout << "\n\t\t\t\t\tChoose Your Option[By Number] : ";
    Option=validateInputInt("\n\t\t\t\t\tChoose Your Option[By Number] : ");

    switch (Option)
    {
    case 1:
        ReportStaff();
        break;
    case 2:
        ReportStock();
        break;
    case 3:
        Graph();
        break;
    case 4:
        Adminmenu();
        break;
    default:
        cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
        _getch();
        goto START;
        break;
    }
    


}
void ReportStaff() 
{
    system("cls");
    cout << "\t\t\t\t\t-----Summary Staff-----\n\n";

    //Find value for each gender
    //search gender female
    int calc = 0,calc2=0;
    int calc3 = 0, calc4 = 0,calc5=0;
    string GenderF = "F", GenderM = "M";
    string CategoryF = "FULL-TIME", CategoryP = "PART-TIME";

    string search_query = "select StaffID,Name,IC,Age,Gender,Address,Phone,Category,Password from staff where Gender like '%" + GenderM + "%'";
    const char* q = search_query.c_str();
    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            calc++;
        }
    }
    cout << "\t\t\t\t\tTotal Of Staff [Male] : ";
    cout <<calc;
    
    
    string search_query2 = "select StaffID,Name,IC,Age,Gender,Address,Phone,Category,Password from staff where Gender like '%" + GenderF + "%'";
    const char* r = search_query2.c_str();
    qstate = mysql_query(conn, r);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            calc2++;
        }
    }
    cout << "\n\t\t\t\t\tTotal Of Staff [Female] : ";
    cout << calc2;

    string search_query3 = "select StaffID,Name,IC,Age,Gender,Address,Phone,Category,Password from staff where Category like '%" + CategoryF + "%'";
    const char* s = search_query3.c_str();
    qstate = mysql_query(conn, s);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            calc3++;
        }
    }
    cout << "\n\t\t\t\t\tTotal Of Staff [FULL-TIME] : ";
    cout << calc3;

    string search_query4 = "select StaffID,Name,IC,Age,Gender,Address,Phone,Category,Password from staff where Category like '%" + CategoryP + "%'";
    const char* t = search_query4.c_str();
    qstate = mysql_query(conn, t);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            calc4++;
        }
    }
    cout << "\n\t\t\t\t\tTotal Of Staff [PART-TIME] : ";
    cout << calc4;
   
    qstate = mysql_query(conn, "select StaffID,Name,IC,Age,Gender,Address,Phone,Category,Password,Salary from staff");
    if (!qstate)
    {  
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            calc5+=stoi(row[9]);
        }
    }
    cout << "\n\t\t\t\t\tTotal Of Salary For All Workers :RM";
    cout << calc5;


    cout <<"\n"<<endl;
    char Option;
    do
    {
        cout << "\t\t\t\t\tPress (M) Back To Menu ";
        cin >> Option;
        if (Option == 'M' || Option == 'm')
            GenerateReport();
    } while (Option != 'M' && Option != 'm');
   

}
void ReportStock()
{
    system("cls");
    cout << "\t\t\t\t\t-----Summary Stock In Shop-----\n";
    int total = 0,total1=0;
    string Category = "PERISHABLE",Category1="NON-PERISHABLE",Category2="STATIONERY";
    int count = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
    double calc = 0,calc1=0,calc2=0;

    qstate = mysql_query(conn, "select  StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop");
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //fetch every row until the end of data
    {
        total1++;
    }

    if (total1 != 0)
    {
        cout << "\n\t\t\t\t\tTotal Stock In Shop : ";
        cout << total1;
    }
   
   
    string search_query1 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where Category like '%" + Category1 + "%'";
    const char* r = search_query1.c_str();
    qstate = mysql_query(conn, r);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            count1++;
        }
    }

    if (count1 != 0)
    {
        cout << "\n\t\t\t\t\tCategory of stock [Non-Perishable] : ";
        cout << count1;
    }

    string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where Category like '%" + Category + "%'";
    const char* q = search_query.c_str();
    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            count++;
        }
    }

    if (count != 0)
    {
        cout << "\n\t\t\t\t\tCategory of stock [Perishable] : ";
        cout << count-count1;
    }

    string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where Category like '%" + Category2 + "%'";
    const char* s = search_query2.c_str();
    qstate = mysql_query(conn, s);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            count2++;
        }
    }

    if (count2 != 0)
    {
        cout << "\n\t\t\t\t\tCategory of stock [Stationery] : ";
        cout << count2;
    }

    qstate = mysql_query(conn, "select  StockID,Name, Quantity, Stock_Price, Selling_Price, Category,Value,Profit, date_format(Exp_Date, '%d %M %Y') from stock_in_shop");
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //fetch every row until the end of data
    {
        calc += stod(row[6]);
        calc1 += stod(row[7]);

    }
    cout << "\n\t\t\t\t\tTotal Value (Price) In Shop is :RM ";
    cout << calc;

    cout << "\n\t\t\t\t\tTotal Profit In Shop is :RM ";
    cout << calc1;


    cout << "\n\n\t\t\t\t\t-----Summary Stock In Store-----\n";
    qstate = mysql_query(conn, "select  StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store");
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //fetch every row until the end of data
    {
        total++;
    }
    
    if (total != 0)
    {
        cout << "\n\t\t\t\t\tTotal Stock In Store : ";
        cout << total;
    }
   
    string search_query4 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where Category like '%" + Category1 + "%'";
    const char* t = search_query4.c_str();
    qstate = mysql_query(conn, t);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            count5++;
        }
    }
    if (count5 != 0)
    {
        cout << "\n\t\t\t\t\tCategory of stock [Non-Perishable] : ";
        cout << count5;
    }

    string search_query3 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where Category like '%" + Category + "%'";
    const char* u = search_query3.c_str();
    qstate = mysql_query(conn, u);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            count4++;
        }
    }

    if (count4 != 0)
    {
        cout << "\n\t\t\t\t\tCategory of stock [Perishable] : ";
        cout << count4-count5;
    }

    string search_query5 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where Category like '%" + Category2 + "%'";
    const char* v = search_query5.c_str();
    qstate = mysql_query(conn, v);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            count3++;
        }
    }
    if (count3 != 0)
    {
        cout << "\n\t\t\t\t\tCategory of stock [Stationery] : ";
        cout << count3;
    }


    qstate = mysql_query(conn, "select  StockID,Name, Quantity, Stock_Price, Selling_Price, Category,Value,date_format(Exp_Date, '%d %M %Y') from stock_in_store");
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //fetch every row until the end of data
    {
        calc2 += stod(row[6]);
    }
   
    cout << "\n\t\t\t\t\tTotal Value (Price) In Store :RM";
    cout << calc2;
    cout << "\n" << endl;
    char Option;
    do
    {
        cout << "\t\t\t\t\tPress (M) Back To Menu ";
        cin >> Option;
        if (Option == 'M' || Option == 'm')
            GenerateReport();
    } while (Option != 'M' && Option != 'm');

}
void Color(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
}
void Graph()
{
    system("cls");
    
    qstate = mysql_query(conn, "select date_format( Exp_Date, '%M %Y'), sum(Value) from stock_in_shop group by year(Exp_Date), month( Exp_Date) order by  Exp_Date desc");
    if (!qstate)
    {
        cout << setw(30) << "\t\t\t\t\tTotal Value Of Item In Shop By Expired Date\n\n";

        Color(7);
        printf("%-15s %-25s %-30s ", " ", "MONTH", "TOTAL VALUE");
        cout << endl << endl;
        int c = 170;
        int b = 10;
        int a = 0;
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            if (a == 6)
            {
                c = 170;
                b = 10;
                a = 0;
            }
            for (int h = 1; h < 2; h++)
            {
                if (h == 1)
                {
                    Color(b);
                    cout << setw(25) << row[0] << setw(10) << " ";
                    Color(c);
                    for (int i = 0; i < stoi(row[1]); i += 100)
                        cout << "XX";
                    Color(b);
                    cout << " RM " << row[1] << endl;
                }
            }
            cout << endl;
            c += 17;
            b++;
            a++;
        }
    }

    Color(9);
    printf("-----------------------------------------------------------------------------------------------------------------------\n\n");



    qstate = mysql_query(conn, "select date_format( Exp_Date, '%M %Y'), sum(Value) from stock_in_store group by year(Exp_Date), month( Exp_Date) order by  Exp_Date desc");
    if (!qstate)
    {
        cout << setw(30) << "\t\t\t\t\tTotal Value Of Item In Store By Expired Date\n\n";

        Color(7);
        printf("%-15s %-25s %-30s ", " ", "MONTH", "TOTAL VALUE");
        cout << endl << endl;
        int c = 170;
        int b = 10;
        int a = 0;
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            if (a == 6)
            {
                c = 170;
                b = 10;
                a = 0;
            }
            for (int h = 1; h < 2; h++)
            {
                if (h == 1)
                {
                    Color(b);
                    cout << setw(25) << row[0] << setw(10) << " ";
                    Color(c);
                    for (int i = 0; i < stoi(row[1]); i += 100)
                        cout << "XX";
                    Color(b);
                    cout << "  RM " << row[1] << endl;
                }
            }
            cout << endl;
            c += 17;
            b++;
            a++;
        }
    }

    Color(11);
    printf("-----------------------------------------------------------------------------------------------------------------------\n\n");


    Color(9);
    cout << "\t\t\t\t\tPress Enter To Go Back...";
    _getch();
    GenerateReport();
    
       
    
}
//LINK - /*https://sielearning.tafensw.edu.au/toolboxes/KitchenOps/tools/store/perso/classify.html#perishable*/
//End Reports
//End Admin Functions

//Staff Functions
void LoginStaff()
{
    system("cls");
    string username, password;
    printf("\t\t\t\t\t-------Login Staff-------\n\n");
    cout << "\t\t\t\t\tUsername : ";
    cin.ignore(1, '\n');
    getline(cin, username);
    cout << "\t\t\t\t\tPassword : ";
    char ch;
    while ((ch = _getch()) != 13)
    {
        password += ch;
        cout << '*';
    }

    cout << "\n";
    //check username & password ygg dimasukkan
    string checkUser_query = "select * from staff where Name = '" + username + "' and Password = '" + password + "'";
    const char* cu = checkUser_query.c_str();//convert
    qstate = mysql_query(conn, cu);//executee

    if (!qstate) //query boleh jalan
    {
        res = mysql_store_result(conn); //store result
        if (res->row_count == 1) //jumpa user
        {
            while (row = mysql_fetch_row(res)) //loop each of row dalam result
                StaffID = row[0]; //store Staff ID in variable

           Staffmenu();
        }
        else //tak jumpa user //username & password salah
        {
            char c;
            cout << "\t\t\t\t\tInvalid username or password. Want to try again (y/n): ";//Re-ask user
            cin >> c;
            if (c == 'y' || c == 'Y')
                LoginStaff();
            else
                main();
        }
    }
}
void Staffmenu()
{
    int Choose;
    char ExitSecurity;
    system("cls");
START:
    system("cls");
    cout << "\t\t\t\t\tStaff>>Staff Menu\n\n";
    cout << "\t\t\t\t\t1.Profile\n";
    cout << "\t\t\t\t\t2.Manage Stock\n";
    cout << "\t\t\t\t\t3.Exit\n";

    //cout << "Choose Your Option [By Number] : ";
    Choose=validateInputInt("\t\t\t\t\tChoose Your Option [By Number] : ");

    switch (Choose)
    {
    case 1:
        ProfileStaff();
        break;
    case 2:
        ManageStock();
        break;
    case 3:
    ExitProgram:
        cout << "\t\t\t\t\tProgram terminating. Are you sure (Y/N): ";
        cin >> ExitSecurity;
        if (ExitSecurity == 'y' || ExitSecurity == 'Y') {
            exit(0);
        }
        else if (ExitSecurity == 'n' || ExitSecurity == 'N') {
            system("cls");
            Staffmenu();
        }
        else {
            cout << "\t\t\t\t\tNext time choose after read the corresponding line : ";
            _getch();
            goto ExitProgram;
        }
        break;
    default:
        cout << "\t\t\t\t\tNext time choose after read the corresponding line : ";
        _getch();
        goto START;
        break;
    }

}
void ProfileStaff()
{
    system("cls");
    char Option;
    cout << "\t\t\t\t\tStaff>>Profile Staff\n";

    string search_query = "select StaffID,Name,IC,Age,Gender,Address,Phone,Category,Password,Salary from staff where StaffID = '" + StaffID + "'";
    const char* q = search_query.c_str();
    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        //create header
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|%-8s | %-20s | %-13s | %-8s | %-10s|%-28s | %-15s|%-10s|%-13s| %-10s|", "STAFF ID", "STAFF NAME", "IC", "AGE", "GENDER", "ADDRESS", "PHONE", "CATEGORY", "PASSWORD", "SALARY(RM)");
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

        //body table
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            printf("|%-8s | %-20s | %-13s | %-8s | %-10s|%-28s | %-15s|%-10s|%-13s| %-10s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9]);
            cout << endl;

        }
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    do
    {
        cout << "\n\t\t\t\t\tPress (M) Back To Menu ";
        cin >> Option;

        if (Option == 'M' || Option == 'm')
        {
            Staffmenu();
        }

    } while ( Option != 'M' && Option != 'm');
}
void ManageStock()
{
    char ExitSecurity;
    int Option;
    system("cls");
START:
    system("cls");
    cout << "\t\t\t\t\tStaff>>Manage Stock\n";
    cout << "\t\t\t\t\t1. Manage Stock In Shop\n";
    cout << "\t\t\t\t\t2. Manage Stock In Store\n";
    cout << "\t\t\t\t\t3. Back to Main Menu\n";
    cout << "\t\t\t\t\t4. Exit\n";
    //cout << "\n\t\t\t\t\tChoose Your Option [By Number] : ";
    Option=validateInputInt("\n\t\t\t\t\tChoose Your Option [By Number] : ");
    switch (Option)
    {
    case 1:

        StockShopStaff();
        break;
    case 2:
        StockStoreStaff();
        break;
    case 3:
        Staffmenu();
        break;
    case 4:
    ExitProgram:
        cout << "\t\t\t\t\tProgram terminating. Are you sure? (Y/N): ";
        cin >> ExitSecurity;
        if (ExitSecurity == 'y' || ExitSecurity == 'Y') {
            exit(0);
        }
        else if (ExitSecurity == 'n' || ExitSecurity == 'N') {
            system("cls");
            ManageStock();
        }
        else {
            cout << "\t\t\t\t\tNext time choose after read the corresponding line : ";
            _getch();
            goto ExitProgram;
        }
        break;
    default:
        cout << "\t\t\t\t\tNext time choose after read the corresponding line : ";
        _getch();
        goto START;
        break;


    }
}
void StockShopStaff()
{
    system("cls");
    int Option;
    char ExitSecurity;
START:
    system("cls");
    cout <<"\t\t\t\t\tStaff>>Manage Stock>>Stock In Shop\n";
    cout << "\t\t\t\t\t1. View Stock\n";
    cout << "\t\t\t\t\t2. Stock In\n";
    cout << "\t\t\t\t\t3. Stock Out\n";
    cout << "\t\t\t\t\t4. Edit Stock\n";
    cout << "\t\t\t\t\t5. Search Stock\n";
    cout << "\t\t\t\t\t6. Back To Main Menu\n";
    cout << "\t\t\t\t\t7. Exit\n";
    //cout << "\t\t\t\t\tChoose Your Option [By Number] : ";
    Option=validateInputInt("\t\t\t\t\tChoose Your Option [By Number] : ");


    switch (Option)
    {
    case 1:
        ViewShopStaff();
        break;
    case 2:
        StockInStaff();
        break;
    case 3:
        StockOutStaff();
        break;
    case 4:
        StockEditStaff();
        break;
    case 5:
        StockSearchStaff();
        break;
    case 6:
        ManageStock();
        break;
    case 7:
    ExitProgram:
        cout << "\t\t\t\t\tProgram terminating. Are you sure (Y/N): ";
        cin >> ExitSecurity;
        if (ExitSecurity == 'y' || ExitSecurity == 'Y') {
            exit(0);
        }
        else if (ExitSecurity == 'n' || ExitSecurity == 'N') {
            system("cls");
            StockShopStaff();
        }
        else {
            cout << "\t\t\t\t\tNext time choose after read the corresponding line : ";
            _getch();
            goto ExitProgram;
        }
        break;
    default:
        cout << "\t\t\t\t\tNext time choose after read the corresponding line : ";
        _getch();
        goto START;
        break;
    }


}
void ViewShopStaff()
{
    char choose;

    system("cls");
    cout << "\t\t\t\t\tStaff>>Manage Stock>>Stock In Shop>>View Stock\n\n";
    qstate = mysql_query(conn, "select StockID, Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop");

    //create header
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
    printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

    //body table
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //fetch every row until the end of data
    {
        printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
        cout << endl;

    }
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");

    cout << "\t\t\t\t\tPress 'M' to menu : ";
    cin >> choose;
    if (choose == 'M' || choose == 'm')
    {
        StockShopStaff();
    }
}
//view stock shop for staff
void StockInStaff() 
{
    string Name, Quantity, Buy, Selling, Category, Date,Value,Profit="0";
    int quan;
    double buy, sell;
    char Option;
    int ID=0;
    system("cls");
    cout << "\t\t\t\t\tStaff>>Manage Stock>>Stock In Shop>>Add New Stock In Shop\n\n"; //add stock in shop
    cin.ignore(1, '\n');
    cout << "\t\t\t\t\tStock Name : ";
    getline(cin, Name);
   // cout<<"\t\t\t\t\tStock Quantity : ";
    
    quan = validateQuantity("\t\t\t\t\tStock Quantity : ");
    cin.ignore(1, '\n');
    Quantity = to_string(quan);
    //cout << "\t\t\t\t\tStock Price : RM";
    buy = validatePrice("\t\t\t\t\tStock Price : RM");
    cin.ignore(1, '\n');
    Buy = to_string(buy);
    //cout << "\t\t\t\t\tSelling Price : RM";
    sell = validatePrice("\t\t\t\t\tSelling Price : RM");
    cin.ignore(1, '\n');
    Selling = to_string(sell);
    cout << "\t\t\t\t\tCategory : ";
    getline(cin, Category);
    cout << "\t\t\t\t\tStock ExpireDate (dd-mm-yyyy) : ";            //YYYY-MM-DD //default date format - MySQL
    getline(cin, Date);

    double selling = stod(Selling);
    double quantity = stod(Quantity);
    Value = to_string(selling * quantity);
    string insert_query = "insert into stock_in_shop(Name, Quantity, Stock_Price, Selling_Price, Category,Value,Profit,Exp_Date) values ('" + Name + "','" + Quantity + "','" + Buy + "','" + Selling + "','" + Category + "','" + Value + "','" + Profit + "', STR_TO_DATE('" + Date + "', '%d/%m/%Y'))";
    const char* q = insert_query.c_str();
    qstate = mysql_query(conn, q);

    if (!qstate) //query boleh jalan
    {
        cout << endl << "\t\t\t\t\tStock is successful added in database." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }


    do
    {
        cout << "\t\t\t\t\tPress 'A' For Add Stock Again Or 'M' To Menu." << endl;
        cin >> Option;
        if (Option == 'M' || Option == 'm')
        {
            StockShopStaff();
        }
        else if (Option == 'A' || Option == 'a')
        {
            StockInStaff();
        }
    } while (Option != 'M' && Option != 'm' && Option != 'A' && Option != 'a');
}
void StockOutStaff() 
{
    string Name, Quantity, Price, Profit;
    int stock = 0, newQuantity,calc=0;
    double price = 0, sale = 0,pro=0;
    char Option,Option2;
    system("cls");
    cout << "\t\t\t\t\tStaff>>Manage Stock>>Stock In Shop>>Stock Out In Shop\n\n";
    cout << "\t\t\t\t\tEnter Stock ID : ";
    cin.ignore(1, '\n');
    getline(cin, StockID);
    string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category,Profit, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where StockID = '" + StockID + "'";
    const char* t = search_query2.c_str();
    qstate = mysql_query(conn, t);

    if (!qstate)
    {
        //create header
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

        //body table
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[7]);
            cout << endl;
            pro = stod(row[6]);
            calc++;
        }
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    }


    if (calc > 0)
    {
        //Update Quantity in menu
        string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category,date_format(Exp_Date, '%d %M %Y') from stock_in_shop where StockID = '" + StockID + "'";
        const char* q = search_query.c_str();
        qstate = mysql_query(conn, q);
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //looping to retreive the data
        {
            stock = stoi(row[2]); // stoi = convert string to integer
            price = stod(row[4]); //stod = convert string to double
            sale = stod(row[3]);

        }

        newQuantity = validateQuantity("\n\t\t\t\t\tInsert Quantity : ");
        //Calculate Subtotal
        if (newQuantity <= stock)
        {
            do
            {
                cout << "\n\t\t\t\t\tConfirm [Y/N] : ";
                cin >> Option2;

                if (Option2 == 'Y' || Option2 == 'y')
                {
                    Quantity = to_string(stock - newQuantity); //calculate
                    string update_query = "update stock_in_shop set Quantity = '" + Quantity + "' where StockID = '" + StockID + "'";
                    const char* r = update_query.c_str();
                    qstate = mysql_query(conn, r);


                    double quantity = stod(Quantity);
                    Price = to_string(quantity * price);
                    string update_query1 = "update stock_in_shop set Value = '" + Price + "' where StockID = '" + StockID + "'";
                    const char* s = update_query1.c_str();
                    qstate = mysql_query(conn, s);


                    Profit = to_string((((double)newQuantity) * (price - sale)) + pro);
                    string update_query3 = "update stock_in_shop set Profit = '" + Profit + "' where StockID = '" + StockID + "'";
                    const char* u = update_query3.c_str();
                    qstate = mysql_query(conn, u);

                    if (!qstate) //query boleh jalan
                    {
                        cout << endl << "\t\t\t\t\tStock is successful Stock Out" << endl;
                    }
                    else
                    {
                        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                    }
                }
                else if (Option2 == 'N' || Option2 == 'n')
                {
                    cout << "\n\n\t\t\t\t\tStock Out Cancel..\n";
                    _getch();
                }
            } while (Option2 != 'Y' && Option2 != 'y' && Option2 != 'N' && Option2 != 'n');
        }
        else
        {
            cout << "\n\t\t\t\t\tQuantity Out Of Stock\n\n";
        }
    }
    else
    {
        cout << "\n\t\t\t\t\tStock doesnt Exist\n\n";
    }
    do
    {
        cout << "\n\t\t\t\t\tPress 'A' For Add Stock Out Again Or 'M' To Menu : ";
        cin >> Option;
        if (Option == 'M' || Option == 'm')
        {
            StockShopStaff();
        }
        else if (Option == 'A' || Option == 'a')
        {
            StockOutStaff();
        }
    } while (Option != 'M' && Option != 'm' && Option != 'A' && Option != 'a');
}
void StockSearchStaff() 
{
    int choose;
    char Option;
    string Name,Category,Date;
    system("cls");
    cout << "\t\t\t\t\tStaff>>Manage Stock>>Stock In Shop>>Search Stock\n\n";

    cout << "\t\t\t\t\tSearch by : ";
    cout << "\n\t\t\t\t\t1. Stock Name ";
    cout << "\n\t\t\t\t\t2. Stock ID ";
    cout << "\n\t\t\t\t\t3. Stock Category ";
    cout << "\n\t\t\t\t\t4. Stock Date ";
    START: 
    choose=validateInputInt("\n\n\t\t\t\t\tChoose Your Option [By Number] : ");

    if (choose == 1)
    {
        cout << "\t\t\t\t\tEnter Stock Name : ";
        cin.ignore(1, '\n');
        getline(cin, Name);
        string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where Name like '%" + Name + "%'";
        const char* t = search_query2.c_str();
        qstate = mysql_query(conn, t);

        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if (choose == 2)
    {
        cout << "\t\t\t\t\tEnter Stock ID : ";
        cin.ignore(1, '\n');
        getline(cin, StockID);
        string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where StockID = '" + StockID + "'";
        const char* t = search_query2.c_str();
        qstate = mysql_query(conn, t);

        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if (choose == 3)
    {
        cout << "\t\t\t\t\tEnter Stock Category : ";
        cin.ignore(1, '\n');
        getline(cin, Category);
        string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where Category = '" + Category + "'";
        const char* t = search_query2.c_str();
        qstate = mysql_query(conn, t);

        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if (choose == 4)
    {
        cout << "\t\t\t\t\tEnter Stock Date : ";
        cin.ignore(1, '\n');
        getline(cin, Date);
        string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where Exp_Date =STR_TO_DATE('" + Date + "','%d/%m/%Y')";
        const char* t = search_query2.c_str();
        qstate = mysql_query(conn, t);

        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }

    else
    {
        cout << "\t\t\t\t\tNext time choose after read the corresponding line : ";
        _getch();
        goto START;

    }
    do
    {
        cout << "\n\t\t\t\t\tPress (S) For Search Another Item Or (M) Back To Menu.\n";
        cin >> Option;

        if (Option == 'S' || Option == 's')
        {
            StockSearchStaff();
        }
        else if (Option == 'M' || Option == 'm')
        {
            StockShopStaff();
        }

    } while (Option != 'S' && Option != 's' && Option != 'M' && Option != 'm');
}
void StockEditStaff() 
{
    string Name, Quantity, Buy, Selling, Category, Date, Price;
    int stock = 0, Option, Newquantity,count=0;
    char Option2;
    double price = 0,buy,sell;
    system("cls");
    cout << "\t\t\t\t\tStaff>>Manage Stock>>Stock In Shop>>Edit Stock\n";
    cout << "\t\t\t\t\tEnter Stock ID: ";
    cin.ignore(1, '\n');
    getline(cin, StockID);

    string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where StockID = '" + StockID + "'";
    const char* q = search_query.c_str();
    qstate = mysql_query(conn, q);
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //looping to retreive the data
    {
        cout << "\t\t\t\t\t--- Current Details of Stock ---" << endl;
        cout << "\t\t\t\t\tStock ID: " << row[0] << " (Uneditable)"
            << "\n\n\t\t\t\t\t1. Name: " << row[1]
            << "\n\t\t\t\t\t2. Quantity: " << row[2]
            << "\n\t\t\t\t\t3. Stock Price: RM " << row[3]
            << "\n\t\t\t\t\t4. Selling Price: RM " << row[4]
            << "\n\t\t\t\t\t5. Category: " << row[5]
            << "\n\t\t\t\t\t6. Expired Date: " << row[6]
            << "\n\t\t\t\t\t7. Save.";
        stock = stoi(row[2]); // stoi = convert string to integer
        price = stod(row[4]);
        count++;

    }
    START: 
    if (count > 0)
    {
        Option = validateInputInt("\n\n\t\t\t\t\tChoose Your Option [By Number] : ");

        cin.ignore(1, '\n');
        if (Option == 1)
        {
            cout << "\t\t\t\t\tInsert New Name: ";
            getline(cin, Name);
            string update_query = "update stock_in_shop set Name = '" + Name + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }


        else if (Option == 2)
        {
            Newquantity=validateQuantity("\t\t\t\t\tInsert New Quantity: ");
            Quantity = to_string(stock + Newquantity); //calculate
            string update_query = "update stock_in_shop set Quantity = '" + Quantity + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);

            double quantity = stod(Quantity);
            Price = to_string(quantity * price);
            string update_query1 = "update stock_in_shop set Value = '" + Price + "' where StockID = '" + StockID + "'";
            const char* s = update_query1.c_str();
            qstate = mysql_query(conn, s);

        }
        else if (Option == 3)
        {
          
            buy = validatePrice("\t\t\t\t\tInsert New Stock Price: RM ");
            Buy = to_string(buy);
            string update_query = "update stock_in_shop set Stock_Price = '" + Buy + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);

        }
        else if (Option == 4)
        {
            sell = validatePrice("\t\t\t\t\tInsert New Selling Price: RM ");
            Selling = to_string(sell);
            string update_query = "update stock_in_shop set Selling_Price = '" + Selling + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);

            double selling = stod(Selling);
            Price = to_string(selling * ((double)stock));
            string update_query1 = "update stock_in_shop set Value = '" + Price + "' where StockID = '" + StockID + "'";
            const char* s = update_query1.c_str();
            qstate = mysql_query(conn, s);
        }
        else if (Option == 5)
        {
            cout << "\t\t\t\t\tInsert New Category :";
            getline(cin, Category);
            string update_query = "update stock_in_shop set Category = '" + Category + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }
        else if (Option == 6)
        {
            cout << "\t\t\t\t\tInsert New Exp Date (dd/mm/yyyy): ";
            getline(cin, Date);
            string update_query = "update Stock_in_shop set Exp_Date = STR_TO_DATE('" + Date + "', '%d/%m/%Y') where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }
        else if (Option == 7)
        {
            cout << "\n\t\t\t\t\tThe Stock  has been saved. Press Enter to Continue...";
            _getch();
        }
        else
        {
            cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
            _getch();
            goto START;
        }
    }
    else
    {
        cout << "\n\t\t\t\t\tStock Not Found!!.Press Enter To Continue\n";
        _getch();
    }


    do
    {
        cout << "\n\t\t\t\t\tPress (E) For Edit Another Item Or (M) Back To Menu : ";
        cin >> Option2;

        if (Option2 == 'E' || Option2 == 'e')
        {
            StockEditStaff();
        }
        else if (Option2 == 'M' || Option2 == 'm')
        {
            StockShopStaff();
        }

    } while (Option2 != 'E' && Option2 != 'e' && Option2 != 'm' && Option2 != 'M');
}
void StockStoreStaff() 
{
    system("cls");
    int Option;
    char ExitSecurity;
    cout << "\t\t\t\t\tStaff>Manage Stock>> Stock In Store\n\n";
    cout << "\t\t\t\t\t1. View Stock\n";
    cout << "\t\t\t\t\t2. Stock In\n";
    cout << "\t\t\t\t\t3. Stock Out\n";
    cout << "\t\t\t\t\t4. Edit Stock\n";
    cout << "\t\t\t\t\t5. Search Stock\n";
    cout << "\t\t\t\t\t6. Back To Menu\n";
    cout << "\t\t\t\t\t7. Exit\n";

    Option = validateInputInt("\n\t\t\t\t\tChoose Your Option [By Number] : ");

    switch (Option)
    {
    case 1:
        ViewStoreStaff();
        break;
    case 2:
        InStoretaff();
        break;
    case 3:
        OutStoreStaff();
        break;
    case 4:
        EditStoreStaff();
        break;
    case 5:
        SearchStoreStaff();
        break;
    case 6:
        ManageStock();
        break;
    case 7:
    ExitProgram:
        cout << "Program terminating. Are you sure (Y/N): ";
        cin >> ExitSecurity;
        if (ExitSecurity == 'y' || ExitSecurity == 'Y') {
            exit(0);
        }
        else if (ExitSecurity == 'n' || ExitSecurity == 'N') {
            system("cls");
            StockStoreStaff();
        }
        else {
            cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
            _getch();
            goto ExitProgram;
        }
        break;
    default:
        cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
        _getch();
        StockStoreStaff();
        break;

      
    }

}
void ViewStoreStaff()
{
    char choose;

    system("cls");
    cout << "\t\t\t\t\tStaff>>Manage Stock>>Stock In Store>>View Stock\n\n";
    qstate = mysql_query(conn, "select  StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store");

    //create header
    printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|%-10s|%-25s | %-15s | %-16s | %-15s | %-16s|%-20s |", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
    printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");

    //body table
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //fetch every row until the end of data
    {
        printf("|%-10s|%-25s | %-15s | %-16s | %-15s | %-16s|%-20s |", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
        cout << endl;

    }
    printf("--------------------------------------------------------------------------------------------------------------------------------------\n");

    cout << "\n\t\t\t\t\tPress 'M' to menu : ";
    cin >> choose;
    if (choose == 'M' || choose == 'm')
    {
        StockStoreStaff();
    }
}
void InStoretaff() 
{
    string Name, Quantity, Buy, Selling, Category, Date, Value;
    int ID,quan;
    double sell, buy;
    char Option;
    system("cls");
    cout << "\t\t\t\t\tStaff>>Manage Stock>>Stock In Store>>Add New Stock In Store\n\n"; //add stock in shop
    cin.ignore(1, '\n');
    cout << "\t\t\t\t\tStock Name : ";
    getline(cin, Name);
    // cout<<"\t\t\t\t\tStock Quantity : ";

    quan = validateQuantity("\t\t\t\t\tStock Quantity : ");
    cin.ignore(1, '\n');
    Quantity = to_string(quan);
    //cout << "\t\t\t\t\tStock Price : RM";
    buy = validatePrice("\t\t\t\t\tStock Price : RM");
    cin.ignore(1, '\n');
    Buy = to_string(buy);
    //cout << "\t\t\t\t\tSelling Price : RM";
    sell = validatePrice("\t\t\t\t\tSelling Price : RM");
    cin.ignore(1, '\n');
    Selling = to_string(sell);
    cout << "\t\t\t\t\tCategory : ";
    getline(cin, Category);
    cout << "\t\t\t\t\tStock ExpireDate (dd-mm-yyyy) : ";            //YYYY-MM-DD //default date format - MySQL
    getline(cin, Date);

    //FIND STOCKID IN SHOP
    string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_shop where Name like '%" + Name + "%'";
    const char* q = search_query.c_str();
    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            ID = stoi(row[0]);
        }
        StockID = to_string(ID);
    }
    //END SEARCHING

    double selling = stod(Selling);
    double quantity = stod(Quantity);
    Value = to_string(selling * quantity);


    //Insert Data about stock in store
    string insert_query = "insert into stock_in_store(StockID,Name, Quantity, Stock_Price, Selling_Price, Category,Value,Exp_Date) values ('" + StockID + "','" + Name + "','" + Quantity + "','" + Buy + "','" + Selling + "','" + Category + "','" + Value + "', STR_TO_DATE('" + Date + "', '%d/%m/%Y'))";
    const char* r = insert_query.c_str();
    qstate = mysql_query(conn, r);

    if (!qstate) //query boleh jalan
    {
        cout << endl << "\n\t\t\t\t\tStock is successful added in database." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    //end Insert



    do
    {
        cout << "\n\n\t\t\t\t\tPress 'A' For Add Stock Again Or 'M' To Menu : ";
        cin >> Option;
        if (Option == 'M' || Option == 'm')
        {
            StockStoreStaff();
        }
        else if (Option == 'A' || Option == 'a')
        {
            InStoretaff();
        }
    } while (Option != 'M' && Option != 'm' && Option != 'A' && Option != 'a');
}
void OutStoreStaff() 
{
    string Name, Quantity, Price;
    int stock = 0, newQuantity,calc=0,quan;
    char Option,Option2;
    double price = 0;
    system("cls");
    cout << "\t\t\t\t\tStaff>>Manage Stock>>Stock In Shop>>Stock Out In Store\n";
    cout << "\t\t\t\t\tEnter Stock ID : ";
    cin.ignore(1, '\n');
    getline(cin, StockID);

    string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where StockID = '" + StockID + "'";
    const char* t = search_query2.c_str();
    qstate = mysql_query(conn, t);

    if (!qstate)
    {
        //create header
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

        //body table
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //fetch every row until the end of data
        {
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
            cout << endl;
            quan = stoi(row[2]);
            calc++;
        }
        printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    }
    if (calc > 0)
    {
        //Update Quantity in menu
        string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where StockID = '" + StockID + "'";
        const char* q = search_query.c_str();
        qstate = mysql_query(conn, q);
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) //looping to retreive the data
        {
            stock = stoi(row[2]); // stoi = convert string to integer
            price = stod(row[4]); //stod = convert string to double

        }

        newQuantity = validateQuantity("\n\n\t\t\t\t\tInsert Quantity : ");
        if (newQuantity <= quan)
        {
            do
            {
                cout << "\n\t\t\t\t\tConfirm [Y/N] : ";
                cin >> Option2;
                if (Option2 == 'Y' || Option2 == 'y')
                {
                    //Calculate New Quantity
                    Quantity = to_string(stock - newQuantity); //calculate
                    string update_query = "update stock_in_store set Quantity = '" + Quantity + "' where StockID = '" + StockID + "'";
                    const char* r = update_query.c_str();
                    qstate = mysql_query(conn, r);

                    double quantity = stod(Quantity);
                    Price = to_string(quantity * price);
                    string update_query1 = "update stock_in_store set Value = '" + Price + "' where StockID = '" + StockID + "'";
                    const char* s = update_query1.c_str();
                    qstate = mysql_query(conn, s);


                    if (!qstate) //query boleh jalan
                    {
                        cout << endl << "\n\t\t\t\t\tStock is successful Stock Out in database." << endl;
                    }
                    else
                    {
                        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                    }
                }
                else if (Option2 == 'N' || Option2 == 'n')
                {
                    cout << "\n\n\t\t\t\t\tStock Out Cancel..\n";
                    _getch();
                }
            } while (Option2 != 'Y' && Option2 != 'y' && Option2 != 'N' && Option2 != 'n');
        }
        else
        {
            cout << "\n\n\t\t\t\t\tOut of Stock";
        }
    }
    else
    {
        cout << "\n\n\t\t\t\t\tStock Not Found";
    }
    {
        cout << "\n\t\t\t\t\tPress 'A' For Add Stock Out Again Or 'M' To Menu : ";
        cin >> Option;
        if (Option == 'M' || Option == 'm')
        {
            StockStoreStaff();
        }
        else if (Option == 'A' || Option == 'a')
        {
            OutStoreStaff();
        }
    } while (Option != 'M' && Option != 'm' && Option != 'A' && Option != 'a');
}
void EditStoreStaff()
{
   
    string Name, Quantity, Buy, Selling, Category, Date, Price;
    int stock = 0, Option, Newquantity,count=0;
    char Option2;
    double price = 0,buy,sell;
    system("cls");
    cout << "\t\t\t\t\tStaff>>Manage Stock>>Stock In Store>>Edit Stock\n";
    cout << "\t\t\t\t\tEnter Stock ID: ";
    cin.ignore(1, '\n');
    getline(cin, StockID);

    //Update Quantity in menu
    string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where StockID = '" + StockID + "'";
    const char* q = search_query.c_str();
    qstate = mysql_query(conn, q);

    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) //looping to retreive the data
    {

        cout << "\t\t\t\t\t--- Current Details of Stock ---" << endl;
        cout << "\t\t\t\t\tStock ID: " << row[0] << " (Uneditable)"
            << "\n\n\t\t\t\t\t1. Name: " << row[1]
            << "\n\t\t\t\t\t2. Quantity: " << row[2]
            << "\n\t\t\t\t\t3. Stock Price: RM " << row[3]
            << "\n\t\t\t\t\t4. Selling Price: RM " << row[4]
            << "\n\t\t\t\t\t5. Category: " << row[5]
            << "\n\t\t\t\t\t6. Expired Date: " << row[6]
            << "\n\t\t\t\t\t7. Save";
        stock = stoi(row[2]); // stoi = convert string to integer
        price = stod(row[4]);
        count++;
    }
    START:
    if (count > 0)
    {
        //cout << "\n\n\t\t\t\t\tChoose Your Option [By Number] : ";
        Option=validateInputInt("\n\n\t\t\t\t\tChoose Your Option [By Number] : ");

        cin.ignore(1, '\n');
        if (Option == 1)
        {
            cout << "\n\t\t\t\t\tInsert New Name: ";
            getline(cin, Name);
            string update_query = "update stock_in_store set Name = '" + Name + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }


        else if (Option == 2)
        {
            //cout << "Insert New Quantity: ";
            Newquantity = validateQuantity("\n\t\t\t\t\tInsert New Quantity: ");
            Quantity = to_string(stock + Newquantity); //calculate
            string update_query = "update stock_in_store set Quantity = '" + Quantity + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);

            double quantity = stod(Quantity);
            Price = to_string(quantity * price);
            string update_query1 = "update stock_in_store set Value = '" + Price + "' where StockID = '" + StockID + "'";
            const char* s = update_query1.c_str();
            qstate = mysql_query(conn, s);
        }
        else if (Option == 3)
        {
            //cout << "\t\t\t\t\tInsert New Stock Price: RM ";
            buy = validatePrice("\t\t\t\t\tInsert New Stock Price: RM ");
            Buy = to_string(buy);
            //getline(cin, Buy);
            string update_query = "update stock_in_store set Stock_Price = '" + Buy + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);

        }
        else if (Option == 4)
        {
           // cout << "\n\t\t\t\t\tInsert New Selling Price: RM ";
            sell = validatePrice("\n\t\t\t\t\tInsert New Selling Price: RM ");
            Selling = to_string(sell);
           // getline(cin, Selling);
            string update_query = "update stock_in_store set Selling_Price = '" + Selling + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);

            double selling = stod(Selling);
            Price = to_string(selling * ((double)stock));
            string update_query1 = "update stock_in_store set Value = '" + Price + "' where StockID = '" + StockID + "'";
            const char* s = update_query1.c_str();
            qstate = mysql_query(conn, s);
        }
        else if (Option == 5)
        {
            cout << "\n\t\t\t\t\tInsert New Category :";
            getline(cin, Category);
            string update_query = "update stock_in_store set Category = '" + Category + "' where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }
        else if (Option == 6)
        {
            cout << "Insert New Exp Date (dd/mm/yyyy): ";
            getline(cin, Date);
            string update_query = "update stock_in_store set Exp_Date = STR_TO_DATE('" + Date + "', '%d/%m/%Y') where StockID = '" + StockID + "'";
            const char* q = update_query.c_str();
            qstate = mysql_query(conn, q);
        }
        else if (Option == 7)
        {
            cout << "\n\t\t\t\t\tThe Stock  has been saved. Press Enter to Continue...";
            _getch();
        }
        else
        {
            cout << "\n\n\t\t\t\t\tNext time choose after read the corresponding line ";
            _getch();
            goto START;

        }

    }
    else
    {
        cout << "\n\t\t\t\t\tStock Not Found!!.Press Enter To Continue\n";
        _getch();
    }
    do
    {
        cout << "\n\t\t\t\t\tPress (E) For Edit Another Item Or (M) Back To Menu : ";
        cin >> Option2;

        if (Option2 == 'E' || Option2 == 'e')
        {
            EditStoreStaff();
        }
        else if (Option2 == 'M' || Option2 == 'm')
        {
            StockStoreStaff();
        }

    } while (Option2 != 'E' && Option2 != 'e' && Option2 != 'm' && Option2 != 'M');

}
void SearchStoreStaff() 
{
    char Option;
    string name,Category,Date;
    int choose;
    system("cls");
    cout << "\t\t\t\t\tStaff>>Manage Stock>>Stock In Store>>Search Stock\n\n";

    cout << "\t\t\t\t\tSearch By : \n";
    cout << "\t\t\t\t\t1. Stock ID \n";
    cout << "\t\t\t\t\t2. Stock Name\n";
    cout << "\t\t\t\t\t3. Stock Category\n";
    cout << "\t\t\t\t\t4. Stock Date\n";

    START:
    choose = validateInputInt("\n\t\t\t\t\tChoose Your Option[By Number] : ");

    if (choose == 1)
    {
        cout << "\n\t\t\t\t\tEnter Stock ID: ";
        cin.ignore(1, '\n');
        getline(cin, StockID);
        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where StockID = '" + StockID + "'";
        const char* q = search_query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if (choose == 2)
    {
        cout << "\n\t\t\t\t\tEnter Stock Name: ";
        cin.ignore(1, '\n');
        getline(cin, name);
        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        string search_query = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where Name like '%" + name + "%'";
        const char* q = search_query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if (choose == 3)
    {
        cout << "\t\t\t\t\tEnter Stock Category : ";
        cin.ignore(1, '\n');
        getline(cin, Category);
        string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where Category = '" + Category + "'";
        const char* t = search_query2.c_str();
        qstate = mysql_query(conn, t);

        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if (choose == 4)
    {
        cout << "\t\t\t\t\tEnter Stock Date : ";
        cin.ignore(1, '\n');
        getline(cin, Date);
        string search_query2 = "select StockID,Name, Quantity, Stock_Price, Selling_Price, Category, date_format(Exp_Date, '%d %M %Y') from stock_in_store where Exp_Date =STR_TO_DATE('" + Date + "','%d/%m/%Y')";
        const char* t = search_query2.c_str();
        qstate = mysql_query(conn, t);

        cout << "\t\t\t\t\t\t\t-------List of searched-------\n\n";
        if (!qstate)
        {
            //create header
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", "STOCK ID", "STOCK NAME", "QUANTITY", "STOCK PRICE", "SELLING PRICE", "CATEGORY", "EXPIRED DATE");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

            //body table
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res)) //fetch every row until the end of data
            {
                printf("|%-10s | %-25s | %-16s | %-15s | %-16s|%-15s | %-18s|", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                cout << endl;

            }
            printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }

    else
    {
        cout << "\t\t\t\t\tNext time choose after read the corresponding line : ";
        _getch();
        goto START;
    }
    do
    {
        cout << "\n\t\t\t\t\tPress (S) For Search Another Item Or (M) Back To Menu.\n";
        cin >> Option;

        if (Option == 'S' || Option == 's')
        {
            SearchStoreStaff();
        }
        else if (Option == 'M' || Option == 'm')
        {
            StockStoreStaff();
        }

    } while (Option != 'S' && Option != 's' && Option != 'M' && Option != 'm');
    

}
int validateInputInt(string label) { //label is the thing to cout (form label
    int num = 0;

    while ((cout << label) && !(cin >> num)) {
        cout << "\n\t\t\t\t\tPlease make sure you have entered a valid number!" << endl;
        cin.clear(); //clear cin input flag (for bad input)
        cin.ignore(((std::numeric_limits<std::streamsize>::max)()), '\n'); //ignore input
    }

    return num;
}
int validateQuantity(string label)
{
    int quan = 0;
    REPEAT:
    while ((cout << label) && !(cin >> quan)) {
        
            cout << "\n\t\t\t\t\tPlease make sure you have entered a valid Quantity!" << endl;
            cin.clear(); //clear cin input flag (for bad input)
            cin.ignore(((std::numeric_limits<std::streamsize>::max)()), '\n'); //ignore input
        
    }
    if (quan <= 0)
    {
        cout << "\n\t\t\t\t\tQuantity Cant Be Negative Or Zero!" << endl;
        cin.clear(); //clear cin input flag (for bad input)
        cin.ignore(((std::numeric_limits<std::streamsize>::max)()), '\n'); //ignore input
        goto REPEAT;
    }

    return quan;
}
double validatePrice(string label)
{
    double price = 0;
REPEAT:
    while ((cout << label) && !(cin >> price)) {

        cout << "\n\t\t\t\t\tPlease make sure you have entered a valid Price!" << endl;
        cin.clear(); //clear cin input flag (for bad input)
        cin.ignore(((std::numeric_limits<std::streamsize>::max)()), '\n'); //ignore input

    }
    if (price <= 0)
    {
        cout << "\n\t\t\t\t\tPrice Cant Be Negative Or Zero!" << endl;
        cin.clear(); //clear cin input flag (for bad input)
        cin.ignore(((std::numeric_limits<std::streamsize>::max)()), '\n'); //ignore input
        goto REPEAT;
    }
    return price;
}
//End Staff Function