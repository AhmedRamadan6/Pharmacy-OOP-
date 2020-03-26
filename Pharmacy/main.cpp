#include <iostream>
#include<fstream>
#include<string>
#include <conio.h>
using namespace std;
ifstream Infile;
ofstream Outfile;

int i=0;
int j=0;
class Person
{
    public :
    int ID;
    string Name;
     virtual void SetV()
    {
         Infile>>ID>>Name;
    }
    virtual void Display()
    {
        cout<<ID <<" "<<Name<< " ";
    }
};
class Medicine : public Person
{
    public :
    float Price;
    void SetV()
    {
        Person::SetV();
        Infile>>Price;
    }
    void Display()
    {
        Person::Display();
        cout<<Price<<endl;
    }
};
class Customer : public Medicine
{
    public :
    float AccountValue;
    void SetV()
    {
        Person::SetV();
        Infile>>AccountValue;

    }
    void Display()
    {
        Person::Display();
        cout<<AccountValue<<endl;
    }
    friend float Cal(float price,float Accountvalue);
};
float Cal(float account,float price)
{
    return account-price;

}
void OrderSet(Person &p)
{
    p.SetV();
}
void OrderDisplay(Person &p)
{
    p.Display();
}


int main()
{
    Customer C[100];
    Infile.open("Customer.txt");
    while(!Infile.eof())
    {
        OrderSet(C[i]);
        i++;

    }
    Infile.close();
    Medicine M[100];
    Infile.open("Medicine.txt");
    while(!Infile.eof())
    {
        OrderSet(M[j]);
        j++;

    }
    Infile.close();
    float sum=0;
    int num;
    int ID;
    char ChCheck;


        for(int i=0;i< j;i++)
        {
        OrderDisplay(M[i]);
        }
        cout << endl;

        while(1)
        {
            cout << "Enter number for a medicine you want : ";
            cin >> num;
            for(int i=0;i< j;i++)
            {
                if(num==M[i].ID)
                {
                    sum+=M[i].Price;
                }
            }
            cout << "any medicine else type 'y' for yes and 'n' for no : ";
            cin >> ChCheck;
            while(ChCheck!='y'&&ChCheck!='n')
            {
                cout << "type again : ";
                cin >>ChCheck;
            }
            if(ChCheck=='n')
                break;
        }
        cout << endl;
        cout << "if you have an Account press 'y' else press 'n' : ";
        cin >>ChCheck;
        while(ChCheck!='y'&&ChCheck!='n')
            {
                cout << "type again : ";
                cin >>ChCheck;
            }
        if(ChCheck=='y')
        {
            cout << "Enter your ID account : ";
            cin >> ID;
            for(int i=0;i< ::i;i++)
            {
                if(ID == C[i].ID)
                {
                    cout << "The  price of your medicines :  " << sum << endl;
                    C[i].AccountValue=Cal(C[i].AccountValue,sum);
                    if (C[i].AccountValue>=0)
                        cout << "the Remaining in your account " << C[i].Name << " : "  << C[i].AccountValue;
                    else
                        cout << "you should pay : " << -(C[i].AccountValue);
                    break;
                }

            }
         }
        else
            cout << "you should pay : " << sum;
            Outfile.open("Customer.txt");
            for(int i=0;i< ::i-1;i++)
            {

                Outfile<<C[i].ID <<" "<< C[i].Name << " " <<C[i].AccountValue << endl;

            }
        Outfile.close();
        return 0;
}







