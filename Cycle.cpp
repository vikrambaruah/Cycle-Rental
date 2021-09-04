#include<bits/stdc++.h>
#include "student.cpp"

using namespace std;

void bookCycle(char s[10])
{
    fstream iofile;
    student pro;
    int a,ch;
    char pass[50];
    char reg[10];
    iofile.open(s,ios::out|ios::in);
    if(!iofile.fail())
    {
        iofile.read((char *) & pro, sizeof(student));
        cout<<"Enter your registration no. ";
        cin>>reg;
        cout<<"Enter the password to continue: ";
        cin>>pass;
        if(strcmp(pass,pro.password)==0)
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
            pro.balance=pro.balance+a;
            cout<<"New Balance is: "<<pro.balance;
            cout<<"Enjoy your ride";
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