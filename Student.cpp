#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class student
{
   public:
    char name[50];
    char regno[10];
    char password[50];
    int balance;

};
class cycle
{
    public:
    char cyclereg[10];
    int lock;
};


void newStudent()
{
    fstream iofile;
    student pro;
    cout<<"Enter the name of the student: ";
    cin>>pro.name;
    cout<<"Enter the registration number: ";
    cin>>pro.regno;
    cout<<"Enter the password: ";
    cin>>pro.password;
    cout<<"Enter the balance: ";
    cin>>pro.balance;
    iofile.open(pro.regno,ios::out);
    iofile.write((char *) & pro, sizeof(student));
    iofile.close();

}

void addBalance(char s[10])
{
    fstream iofile;
    student pro;
    int a;
    char pass[50];
    iofile.open(s,ios::out|ios::in);
    if(!iofile.fail())
    {
        iofile.read((char *) & pro, sizeof(student));

        cout<<"Enter the amount to be added: ";
        cin>>a;

        cout<<"Enter the password to continue: ";
        cin>>pass;
        if(strcmp(pass,pro.password)==0)
        {
            pro.balance=pro.balance+a;
            cout<<"Balance updated successfully!!"<<endl<<"New Balance is: "<<pro.balance;
            iofile.seekg(0);
            iofile.write((char *) & pro, sizeof(student));
        }
        else
            cout<<"Enter a valid password!!";

        iofile.close();
    }
    else
        cout<<"Enter a registered Registration Number";

}
void addCycle()
{
    fstream iofile;
    cycle cy;
    cout<<"Enter the cycle registration number: ";
    cin>>cy.cyclereg;
    cout<<"Enter the cycle lock number: ";
    cin>>cy.lock;
    iofile.open(cy.cyclereg,ios::out);
    iofile.write((char *) & cy, sizeof(cycle));
    iofile.close();
    cout<<"Cycle added SUCCESSFULLY!!";
}
void bookCycle(char s[10])
{
    fstream iofile;
    fstream infile;
    cycle cy;
    student pro;
    int a,ch;
    int pass;
    char pass2[100];
    char reg[10];
    cout<<"Enter your registration no. ";
    cin>>reg;
    iofile.open(s,ios::out|ios::in);
    infile.open(reg,ios::out|ios::in);
    if(!iofile.fail())
    {
        iofile.read((char *) & cy, sizeof(cycle));
        infile.read((char *) & pro, sizeof(student));
        cout<<"Enter the cycle password: ";
        cin>>pass;
        cout<<"Enter your password to continue: ";
        cin>>pass2;
        if(pass==cy.lock&&strcmp(reg,pro.regno)==0&&strcmp(pass2,pro.password)==0)
        {
            cout<<"Choose your option"<<endl<<"1. MH to SJT"<<endl<<"2. MH to TT"<<endl<<"3. MH to MB"
                <<endl<<"4. TT to SJT"<<endl<<"5. TT to SMV"<<endl<<"6. MB to SJT\n"<<"7. SMV to SJT\n";
            cin>>ch;
            switch (ch){
                case 1: a=15;
                        break;
                case 2: a=10;
                        break;
                case 3: a=5;
                        break;
                case 4: a=5;
                        break;
                case 5: a=5;
                        break;
                case 6: a=10;
                        break;
                case 7: a=7;
                        break;
            }
            if (pro.balance<a){
                cout<<"Not enough balance";
            }
            else {
                pro.balance=pro.balance-a;
                cout<<"New Balance is: "<<pro.balance<<endl;
                cout<<"Enjoy your ride";
            }
            iofile.seekg(0);
            iofile.write((char *) & pro, sizeof(student));
        }
        else
            cout<<"Enter a valid password!!";

        iofile.close();
    }
    else
        cout<<"Enter a registered Registration Number";

}