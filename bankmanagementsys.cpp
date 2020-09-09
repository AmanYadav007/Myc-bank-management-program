#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include<iomanip> 
using namespace std;
class BankAccount
{
    int acno, deposit;
    char name[50];
    char type;

public:		//aman is an loser
    void create_account();      //this function will create user
    void show_account();        //this fuction show the created user information
    void modify();              //this funcion will modify the user data
    void dep(int a);            //this funcion will deposite money in account
    void draw(int b);           //this function will widraw money from account
    void report() const;        //this funcion will generate report for user
    void returnacno() const;    //this function will just return account number
    void returndeposit() const; //this function will show the balance on account.
    void returntype() const;     //this function will account type whether its saving and current
};

void BankAccont::create_account()
{
    cout << "Enter Account Number : ";
    cin >> acno;
    cout << "Enter the account holder name : ";
    cin.ignore();          //The cin. ignore() function is used which is used to ignore or clear one or more characters from the input buffer.
    cin.getline(name, 50); //The C++ getline() is a standard library function that is used to read a string.
    cout << "Enter type of account(C/S) : ";
    cin >> type;
    type = toupper(type); //convert to uppercase
    cout << "Enter the amount of deposit(500 minimum for saving and 1000 minimum for current) : " cin >> deposit;
    cout << "\n\n\nAccount Created....."; //just some fancy stufff
}
void BankAccount::show_account()
{
    cout << "\nYour Account Number : " << acno;
    cout << "\nYour Account Holder Name Is : " << name;
    cout << "\nThe Type Of Your Account Is : " << type;
    cout << "\nThe Account Balance Is : " << deposit;
    cout << "\nIt's better to tale screenshot of this ... sir/mam";
}
void BankAccount::modify()
{
    cout << "Account Number :" << acno;
    cout << "Update Account Holder Name : ";
    cin >> name;
    cout << "Update Account Type : ";
    cin >> type;
    type = toupper(type);
    cout << "Upadte Account Balance : ";
    cin >> deposite;
}
void BankAccount::dep(int x)
{
    deposite += x; //this means x = x +y;
}
void BankAccount::draw(int x)
{
    deposite -= x;
}
void BankAccount::report()
{
    cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(7) << " " << deposite << endl;	//aman do u think youcan do anything aman="YES I CAN"
}
void BankAccount::returnacno()
{
    return acno;
}
void BankAccount::returndeposit()
{
    return deposit;
}
void BankAccount::returntype()
{
    return type;
}

//creating some function
void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void intro();

int main()
{
    char ch;
    int num;
    intro();
    do
    {

        system('cls');
        cout << "\n\n\n\n\tMAIN MENU";
        cout << "\n\n\n\t01. NEW ACCOUNT";
        cout << "\n\n\n\t02. DEPOSIT AMOUNT";
        cout << "\n\n\n\t03. WITHDRAW AMOUNT";
        cout << "\n\n\n\t04. BALANCE ENQUIRY";
        cout << "\n\n\n\t05. ALL ACCOUNT HOLDER LIST";
        cout << "\n\n\n\t06. CLOSE AN ACCOUNT";
        cout << "\n\n\n\t07. MODIFY AN ACCOUNT";
        cout << "\n\n\n\t08. EXIT";
        cout << "\n\n\tSelect Your Option (1-8) ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            write_account();
            break;
        case '2':
            cout << "\n\n\tEnter The account no. :";
            cin >> num;
            deposit_withdraw(num, 1);
            break;
        case '3':
            cout << "\n\n\tEnter The account no. : ";
            cin >> num;
            deposit_withdraw(num, 2);
            break;
        case '4':
            cout << "\n\n\tEnter The account no. : ";
            cin >> num;
            display_sp(num);
            break;

        case '5':
            display_all();
            break;

        case '6':
            cout << "\n\n\tEnter The account no. : ";
            cin >> num;
            delete_account(num);
            break;
        case '7':
            cout << "\n\n\tEnter The account no. : ";
            cin >> num;
            modify_account(num);
            break;
        case '8':
            cout << "\n\n\tThanks for using bank... ";
            break;
        default:
            cout << "\a";
        }
        cin.ignore();
        cin.get();
    } while (ch != '8');
    return 0;
}


//FUNCTION TO WRITE IN FILE

void write_account(){
    BankAccont ba;
    ofstream outFile;
    outFile.open("account.dat",ios::binary|ios::app);
    ba.create_account();
    outFile.write(reinterpret_cast<char *> (&ba), sizeof(BankAccont));
    outFile.close();
}

void display_sp(int n){
    BankAccont ba;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ba.returnacno()==n)
		{
			ba.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
}

void modify_account(int n)
{
	bool found=false;
	BankAccont ba;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ba), sizeof(BankAccont));
		if(ba.returnacno()==n)
		{
			ba.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ba.modify();
			int pos=(-1)*static_cast<int>(sizeof(BankAccont));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ba), sizeof(BankAccont));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}
void delete_account(int n)
{
	BankAccont ba;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ba), sizeof(BankAccont)))
	{
		if(ba.returnacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ba), sizeof(BankAccont));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}
void display_all()
{
	BankAccont ba;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ba), sizeof(BankAccont)))
	{
		ba.report();
	}
	inFile.close();
}

void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	BankAccount ba;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ba), sizeof(BankAccont));
		if(ba.returnacno()==n)
		{
			ba.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ba.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=ba.returndeposit()-amt;
				if((bal<500 && ba.returntype()=='S') || (bal<1000 && ba.returntype()=='C'))
					cout<<"Insufficience balance";
				else
					ba.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ba));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ba), sizeof(BankAccont));
			cout<<"\n\n\t Record Updated";
			found=true;
	       }
         }
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}
void intro()
{
	cout<<"\n\n\n\t  BANK";
	cout<<"\n\n\tMANAGEMENT";
	cout<<"\n\n\t  SYSTEM";
	cout<<"\n\n\n\nMADE BY : your name";
	cout<<"\n\nSCHOOL : your school name";
	cin.get();

}
