#include<iostream>
#include<chrono>
#include <random>
#include<ctime>
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<direct.h>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<string>
using namespace std;
    string fname,lname,password,userid,ap;
    int dd,mm,yy,hh,m;
    void stories();
    void adminpanel();
    int generateOTP() {
   srand(time(NULL)); 
    return rand();
}

class Personal_Diary
{
      public:
    Personal_Diary()
    {
            mkdir("c:/Personal_Diary");
    mkdir("c:/Personal_Diary/Files");
    mkdir("c:/Personal_Diary/Files/Login");
     mkdir("c:/Personal_Diary/Files/Stories");
    char details_of_Project[]="This Project is Developed by Divyansh Upadhyay";
    }

void gotoxy(int a,int b)
{
    COORD c;
    c.X=a;
    c.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void color(int color_num)
{
    int input=color_num;
      HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,input);
}
void delay()
{
    for(int j=1;j<100000000;j++)
    {
        j++;
        j--;
    }
}
void new_user()
{
    system("cls");
    gotoxy(41,0);
    color(8);
    char a[]="WELCOME TO NEW USER SECTION";
    for(int i=0;i<strlen(a);i++)
    {
        for(int j=0;j<7000000;j++)
        {
        j++;j--;
        }
        cout<<a[i];
    }
    gotoxy(41,1);
     for(int i=0;i<strlen(a);i++)
    {
        for(int j=0;j<7000000;j++)
        {
        j++;j--;
        }
        cout<<"-";
    }
    gotoxy(10,3);
    fstream file;
    file.open("c:/Personal_Diary/Files/Login/Login.o",ios::in);
    int found=0,i=0;
    string name1,name2,name3;
    if(file.fail())
    {
        gotoxy(0,4);
        cout<<"This Program is Running for the first time and You are the first user here\n";
        gotoxy(10,5);
        cout<<"Enter Your First Name : ";
        cin.ignore();
        getline(cin,name1);
        gotoxy(10,6);
         cout<<"Enter Your last Name : ";
        getline(cin,name2);
            gotoxy(10,7);
    cout<<"Enter Your UserId : ";
    getline(cin,name3);
    }
    else
    {
         gotoxy(10,5);
        cout<<"Enter Your First Name : ";
        cin.ignore();
        getline(cin,name1);
        gotoxy(10,6);
         cout<<"Enter Your last Name : ";
        getline(cin,name2);
            gotoxy(10,7);
    cout<<"Enter Your UserId : ";
    getline(cin,name3);
        while(1)
        {
            file>>fname>>lname>>userid>>password;
            if(file.eof())
            {
                break;
            }
            int r=name1.compare(fname);
            int d=name2.compare(lname);
            int e=name3.compare(userid);
            if((r==0&&d==0)||(r==0&&d==0&&e==0)||e==0)
            {
                found=1;
                cout<<"This User is Already Exits.\n";
            }
        }
    }
    file.close();
    fstream file1;
    if(found==0)
    {
       /* string a = "\\\"mkdir Personal_Diary/Files/Stories/";
        string b = fname+lname+"\\\"";
        string c = a+b;*/
       
        file1.open("c:/Personal_Diary/Files/Login/Login.o",ios::app);
      fname=name1;
      lname=name2;
      userid=name3;
       string a = "mkdir Personal_Diary\\Files\\Stories\\";
       string e = fname + lname ; 
     string b = e +"\"";
     string c = a+b;
     int votp;
     int otp = generateOTP();
     gotoxy(90,0);
     cout<<"Your OTP is : "<<otp;
     gotoxy(10,8);
     cout<<"Enter Your OTP  : ";
     cin>>votp;
     if(votp==otp)
     {
    file1<<fname<<' '<<lname<<' '<<userid<<' ';
    gotoxy(10,9);
    cout<<"Enter Your Password : ";
    cin.ignore(); 
    getline(cin,password);
    file1<<password<<endl;
    file1.close();

    chdir("C:\\");
    system(c.c_str());
    }
    else 
    {
        gotoxy(10,10);
        cout<<"Wrong OTP try again ";
        exit(0);
    }
    }
     gotoxy(10,10);
    cout<<"Thank You For Registration";
     gotoxy(10,11);
     cout<<"Your Account has been created.";
     gotoxy(40,13);
     cout<<"Please wait while we are saving your details to the system";
     for(int i=0;i<10;i++)
     {
         delay();
         cout<<"*";
     }
}
void edit()
{
    system("cls");
    gotoxy(41,0);
    int found=0;
    color(8);
    cout<<"For this You have to login again ";
    gotoxy(40,5);
    string id,p;
    cout<<"Enter Userid : ";
    cin.ignore();
    getline(cin,id);
    fstream file;
    file.open("c:/Personal_Diary/Files/Login/Login.o",ios::in);
    while(true)
    {
        file>>fname>>lname>>userid>>password;
        if(file.eof())
        {
            break;
        }
        if(userid == id)
        {
            found=1;
        }
    }
    if(found==1)
    {
        gotoxy(40,6);
        cout<<"Enter Password  : ";
        cin.ignore();
        getline(cin,p);
        found=0;
        file.close();
        file.open("c:/Personal_Diary/Files/Login/Login.o",ios::in);
        while(true)
         {
        file>>fname>>lname>>userid>>password;
        if(file.eof())
        {
            break;
        }
        if(password == p)
        {
            found=1;
        }
         }
         if(found==1)
         {
            file.close();
            cout<<"Login Success";
            getch();
         }
         else
         {
            cout<<"\nWrong Password Try again.\n";
         }

    }
}
void diary()
{
    system("cls");

    color(9);
    gotoxy(10,12);
    int found =0,h,mi,found1=0;
    string ddd,folder;
    string am,uid;
    cout<<"Enter Date of incident(dd-mm-yy) : ";
    cin>>ddd;
    gotoxy(10,13);
    cout<<"Enter the time of incident (hh mm am/pm) : ";
    cin>>h>>mi;
    cin.ignore();
    cin>>am;
    gotoxy(10,14);
    cout<<"Enter your fullname(Without space) : ";
    cin.ignore();
    getline(cin,folder);
    gotoxy(10,15);
    cout<<"Enter your user-id again :  ";
    //cin.ignore();
    cin>>uid;
    fstream file,file1;
    file.open("c:/Personal_Diary/Files/Login/Login.o",ios::in);
    while(1)
    {
        file>>fname>>lname>>userid>>password;
        if(file.eof())
        {
            break;
        }
        if(userid == uid)
        {
            found=1;
        }
        if(folder==(fname+lname))
        {
            found1=1;
        }

    }
    file.close();
    if(found==1 && found1 == 1)
    {
          system("cls");
    color(1);
    string a = "c:/Personal_Diary/Files/Stories/";
    string b = a+folder+"/"; 
    file.open(b+ddd+".o",ios::in);
    if(file)
    {
        gotoxy(0,5);
        cout<<"Record already exists";
        gotoxy(10,8);
        cout<<"Do yo want to Edit the Record (Y/N) ........";
        char a;
        cin.ignore();
        cin>>a;
        switch(a)
        {
            case 'Y': edit();
                      break;
            case 'N': break;
            default : cout<<"Check Your Input.";
                        break;
        }

    }
    else
    {
        file.close();
        file.open(b+ddd+".o",ios::app);
        gotoxy(15,6);
        cout<<"Start writting the content : \n\n\n\n";
        string stories;
        cin.ignore();
        getline(cin,stories);
        file<<ddd<<" - "<<stories<<"\n";
        file.close();
    }

    }
    else
    {
        cout<<"User does not exists";
        delay();
    }
}
void login()
{
    system("cls");
    gotoxy(41,0);
    color(8);
    char a[]="WELCOME TO LOGIN SECTION";
    for(int i=0;i<strlen(a);i++)
    {
        for(int j=0;j<7000000;j++)
        {
        j++;j--;
        }
        cout<<a[i];
    }
    gotoxy(41,1);
     for(int i=0;i<strlen(a);i++)
    {
        for(int j=0;j<7000000;j++)
        {
        j++;j--;
        }
        cout<<"-";
    }
    gotoxy(10,4);
    fstream file;
    file.open("c:/Personal_Diary/Files/Login/Login.o",ios::in);
    int found=0,i=0;
    string lid,lpass;
    if(file.fail())
    {
        cout<<"No user is Registered Please Register First And Try again.";
        gotoxy(10,5);
        cout<<"Press any Key to Continue";
        getch();
    }
    else
    {
        cout<<"Enter Your UserID : ";
        cin.ignore();
        getline(cin,lid);
        while(1)
        {
            file>>fname>>lname>>userid>>password;
            if(file.eof())
            {
                break;
            }
            int r = lid.compare(userid);
            if(r==0)
            {
                found=1;
            }
        }
        file.close();
        if(found == 1)
        {
            gotoxy(10,5);
            cout<<"Enter Password : ";
            getline(cin,lpass);
            file.open("c:/Personal_Diary/Files/Login/Login.o",ios::in);
            while(1)
            {
                file>>fname>>lname>>userid>>password;
                if(file.eof())
                {
                    break;
                }
                int s=lpass.compare(password);
                if(s==0)
                {
                    i=1;
                }
            }
            file.close();
            if(i==1)
            {
                gotoxy(10,7);
                cout<<"Login Success ";
                for(int o=0;o<10;o++)
                {
                    for(int w=1;w<9000000;w++)
                    {
                        w++;w--;
                    }
                    cout<<"*";
                }
                fstream time;
                time.open("c:/Personal_Diary/Files/Login/Login_history.o",ios::app);
                auto t = chrono::system_clock::to_time_t(chrono::system_clock::now());
                time<<lid<<" "<<ctime(&t)<<endl;
                diary();
            }

        }
    }
}
void admin()
{
    system("cls");
    color(04);
    gotoxy(60,0);
    string admin;
    int otp = generateOTP();
    int lotp;
    cout<<"Hello & Welcome to Admin Pannel";
    gotoxy(60,1);
    cout<<"--------------------------------";
    auto t = chrono::system_clock::to_time_t(chrono::system_clock::now());
     gotoxy(120,0);
    color(9);
    cout<<ctime(&t);
    gotoxy(100,1);
    cout<<"Your OTP is : "<<otp;
    gotoxy(20,5);
   color(04);
    cout<<"Enter ADMIN ID : ";
     char id[32];//to store password.
    int i = 0;
    char a;//a Temp char
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            id[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            id[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    admin = id;
    if(admin == "Divyansh")
    {
        gotoxy(20,6);
        cout<<"Enter Password  : ";
    char pass[32];//to store password.
    int i = 0;
    char a;//a Temp char
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            ++i;
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    string password = pass;
    if(password=="ReenaUpadhyay")
    {
        gotoxy(20,7);
        cout<<"Enter Otp : ";
        cin>>lotp;
        if(lotp==otp)
        {
        cout<<"Login Success";
        for(int i=0;i<10;i++)
        {
            delay();
            cout<<"*";
        }
        Madminpanel();
        }
        else
        {
            cout<<"Your Otp is wrong";
        }
    }
    else
    {
        cout<<"Wrong password";
        getch();
    }
    }
    else
    {
        cout<<"Wrong Username";
    }
    getch();
}
void Madminpanel()
{
    system("cls");
    color(9);
    gotoxy(60,0);
    cout<<"Welcome to Master Admin Panel";
    gotoxy(60,1);
    cout<<"---------------------------------";
    gotoxy(40,10);
    getch();
}
void RD()
{
    system("cls");
    gotoxy(77,0);
    color(9);
    auto t = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout<<ctime(&t);
    //cout<<"Date and Time : ";printf("%02d/%02d/%d    %02d:%02d ",dd,mm,yy,hh,m,ap);cout<<ap;
    gotoxy(41,1);
    color(07);
    cout<<"Welcome To The Reading Section";
    gotoxy(40,5);
    
    getch();
}
void driver()
{
    int i,j;
    /*gotoxy(10,5);
    system("color 22");
    cout<<"Enter Current time(hh mm(am/pm)): ";
    cin>>hh>>m;
    cin.ignore();
    cin>>ap;
    gotoxy(10,6);
    cout<<"Enter current Date(dd mm yy) : ";
    cin>>dd>>mm>>yy;*/
     while(true)
    {
    system("cls");
    gotoxy(77,0);
    color(9);
    auto t = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout<<ctime(&t);
    //cout<<"Date and Time : ";printf("%02d/%02d/%d    %02d:%02d ",dd,mm,yy,hh,m,ap);cout<<ap;
    gotoxy(41,1);
    color(33);
    char a[]="Welcome to Your Personal Diary";
    cout<<a;
    color(07);
        gotoxy(10,4);
        cout<<"Press 1 to Create a Diary for you";
        gotoxy(10,5);
        cout<<"Press 2 to Write down in a Diary";
        gotoxy(10,6);
        cout<<"Press 3 to Login as Master Admin";
        gotoxy(10,7);
        cout<<"Press 4 to Login as Normal Admin";
        gotoxy(10,8);
        cout<<"Press 5 to Read Diary";
        gotoxy(10,9);
        cout<<"Press 6 to exit";
        gotoxy(10,10);
        cout<<"------------------------------------------";
        gotoxy(10,11);
        cin>>i;
    switch(i)
        {
        case 1 : new_user();
        break;

        case 2: login();
        break;

        case 3: admin();
        break;
        
        case 4: exit(0);
        break;

        case 5: RD();
        break;

        case 6: exit(0);
        break;
        }
    }
}
};
int main()
{
    Personal_Diary t;
    t.driver();
}
