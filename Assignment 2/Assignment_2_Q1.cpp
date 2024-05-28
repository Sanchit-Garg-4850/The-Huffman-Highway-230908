#include<bits/stdc++.h>
using namespace std;

class Account {

    int Account_Number,Funds;
    string Account_Name,Address,Account_Type;

    public:

    multimap <string,int> Past_Loan_History ;
    multimap <string,int> Past_Transaction_History ;

    friend  class JointAccount;
    friend class Loan;
    friend void Transfer_Funds(Account A2 ,int amount);
    
    Account(){}

    Account(int a,string b , string c , string d ){
        Account_Number=a;
        Account_Name=b;
        Address=c;
        Account_Type=d;
        Funds=0;
    }

    void deposit(string date , int amount){
        Funds+=amount;
        Past_Transaction_History.insert({date,amount});
    }

    void withdraw(string date,int amount){
        if(amount>Funds) cout<<"Insufficient Funds"<<endl;
        else {
            Funds-=amount;
            Past_Transaction_History.insert({date,-amount});
        }
    }

    void update(int Account_Number,string Account_Name, string Address, string Account_Type){
        Account_Number=Account_Number;
        Account_Name=Account_Name;
        Address=Address;
        Account_Type=Account_Type;
    }

    void View_Passbook(){
        cout<<"Passbook for "<<Account_Name<<" is : "<<endl;
        for(auto it : Past_Transaction_History){
            cout << it.first<<" : "<< it.second<<endl;
        }   
        cout<<"Funds Balance : "<<Funds<<endl;
    }   

    void GetFunds(){
        cout<<"Funds in "<<Account_Name<<" are "<<Funds<<endl;
    } 

    void Transfer_Funds(string date , Account &A2 , int amount){
        if(amount>Funds) cout<<"Insufficient Funds"<<endl;
        else{
            Funds -= amount;
            A2.Funds += amount;

            Past_Transaction_History.insert({date,-amount});
            A2.Past_Transaction_History.insert({date,amount});
        }   
}

    void Find_Using_Date(string date){
        cout<<"Transactions on "<<date<<" are : "<<endl;

        auto range = Past_Transaction_History.equal_range(date);

        for(auto it =range.first ; it!=range.second ; ++it){
            cout<<it->first<<" : "<<it->second<<endl;
        }
    }

    void Find_Using_Amount(int amount){
        cout<<"Transactions of "<<amount<<" are : "<<endl;

        for(auto it : Past_Transaction_History){
            if(it.second==amount) cout<<it.first<<" : "<<it.second<<endl;
        }
    }

};

class JointAccount : public Account {

    string Joint_Account_Name;

    public :

    JointAccount(int a,string b1,string b2,string c,string d) {
        Account_Number = a;
        Account_Name = b1;
        Joint_Account_Name = b2;
        Address = c;
        Account_Type = d;
        Funds = 0;
    }

};

class Loan : public Account {
    
    int Loan_id ;
    float Recommended_Installment;
    float Duration_in_years;
    float Interest_rate,amount,Principal;
    bool status;

    public :

    Loan(int a,string b , string c , string d ,int Loan_id , int amount , int Interest_rate , int Duration){
        Loan_id=Loan_id;
        amount=amount;
        Interest_rate=Interest_rate;
        Duration_in_years=Duration;
        status=0;
        Account_Number=a;
        Account_Name=b;
        Address=c;
        Account_Type=d;
        Funds=0;
        Principal=amount;

        Recommended_Installment = int((amount*(pow((1+float(Interest_rate/100.0)),Duration_in_years)))/Duration_in_years);

        cout<<"Recommened Installment per year is "<<Recommended_Installment<<endl;
    }

    void Payment(int Installment , int Installment_Number){
        if(Installment_Number>Duration_in_years) cout<<"You are bankrupt"<<endl<<"Your asset would be seized"<<endl;
        float rate=(1+float(Interest_rate/100.0));
        amount=Recommended_Installment-Installment;
        if(amount<=0) cout<<"Hooray! , Lone is repiad"<<endl;
        else cout<<amount<<endl;
    }

};

int main(){

    Account Sanchit (1 ,"Sanchit_Garg","F408","Savings");
    Sanchit.deposit("26 July 2024",2000);
    Sanchit.withdraw("27 July 2024",300);

    Account Kaavya(2,"Kaavya","PEC","Savings");

    JointAccount Yug (3,"Yug","Kushant","IIT Mandi","Savings");

    Sanchit.Transfer_Funds("27 July 2024",Kaavya,300);
    Sanchit.GetFunds();
    Kaavya.GetFunds();
    Yug.GetFunds();

    Sanchit.View_Passbook();

    Sanchit.Find_Using_Date("27 July 2024");
    Sanchit.Find_Using_Amount(-300);

    Loan Yug_Kushant (3,"Yug","IIT Mandi","Savings",23,100000,12,10);
    Yug_Kushant.Payment(20000,1);
    Yug_Kushant.Payment(200000,2);
    return 0;
}