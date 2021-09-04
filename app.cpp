#include "main.cpp"
#include <bits/stdc++.h>
using namespace std;
int main()

{
    int ch;
    string ID,pass;
    profile user;
    cout<<"Enter your choice: "<<endl<<"1.  Create new account "<<endl<<"2.  Book a cycle"<<endl<<"3. Recharge your account"<<endl<<"4. Balance Enquiry"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:
            new_profile();
            break;
        case 2:
            cout<<"Enter your reg. number: ";
            cin>>ID;
            user=search(ID);
            cout<<"Enter your Password: ";
            cin>>pass;
            if(verify_password(user,pass))
                {
                    book_cycle(user);
                }
            else
                {
                    cout<<"Access Denied";
                }
            break;

        case 3:
            cout<<"RECHARGE!"<<endl;
            cout<<"Enter the regno: ";
            cin>>ID;
            add_balance(ID);
            break;
        case 4:
            cout<<"BALANCE ENQUIRY! ";
            cout<<"Enter the regno: ";
            cin>>ID;
            user=search(ID);
            cout<<"Balance: "<<user.balance;
            break;
        default:
            cout<<"Put a valid option";
    }
return 0;
}
