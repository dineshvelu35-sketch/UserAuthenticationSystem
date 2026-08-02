#include<bits/stdc++.h>
#include<fstream>
using namespace std;
class DateOfBirth
{
	public:
	bool IsValid(string DOB)
	{
		if(DOB.size()==10)
		{
			for(int i=0;i<10;i++)
			{
				if(DOB[2] || DOB[5])
				{
					continue;
				}
				if(!isdigit(DOB[i]))
				{
					cout<<"The Entered Date Of Birth is Invalid. So Enter the valid Date of Birth Again"<<endl;
					return false;
				}
			}
			int Date=0,Month=0,Year=0,temp=0;
			while(temp<2)
			{
				Date=Date*10+(DOB[temp++]-'0');
			}
			if(!DOB[temp]=='/')
			{
				return false;
			}
			temp++;
			while(temp<5)
			{
				Month=Month*10+(DOB[temp++]-'0');
			}
			if(!DOB[temp]=='/')
			{
				return false;
			}
			temp++;
			while(temp<10)
			{
				Year=Year*10+(DOB[temp++]-'0');
			}	
			if(Date>0 && Date<=31 && Month>0 && Month<=12 && Year>1900 && Year<2025)
			{
				return true;
			}
		}
		cout<<"The Entered Date Of Birth is Invalid. So Enter the valid Date of Birth Again"<<endl;
		return false;
	}
};
class Gender
{
	public:
	bool IsValid(char Gend)
	{
		Gend=toupper(Gend);
		if(Gend=='F' || Gend=='M')
		{
			return true;
		}
		cout<<"You are allowed to enter only M-Male or F-Female, Again Enter the valid Information"<<endl;
		return false;
	}
};
class Number
{
	public:
	bool IsValid(string Num)
	{
		bool  ChCheck=false;
		if(Num.size()==10)
		{
			for(int i=0;i<Num.size();i++)
			{
				if(!isdigit(Num[i]))
				{
					ChCheck=true;
					break;
				}
				
			}
			if(!ChCheck)
			{
				return true;
			}
		}
		cout<<"Invalid Number. Enter The Valid Number"<<endl;
		return false;
	}
};
class Email
{
	public:
	bool IsValid(string Id)
	{
		if(Id.size() >= 12 && Id.substr(Id.size() - 10) == "@gmail.com")
    	{
    		string namePart=Id.substr(0,Id.size()-10);
    		for(int i=0;i<namePart.size();i++)
			{
				char c=namePart[i];
    			if(!(islower(c) || isdigit(c)))
    			{
    				cout << "Entered Email is Invalid. Re-enter Valid Email ID."<<endl;
        			return false;
    			}
			}
			return true;
    	}
    	cout << "Entered Email is Invalid. Re-enter Valid Email ID."<<endl;
		return false;
	}
};
class Password
{
	public:
	bool IsValid(string Pswrd)
	{
		if(Pswrd.size()<8 || Pswrd.size()>15)
		{
        	return false;
        }
		bool upper = false;
    	bool lower = false;
    	bool digit = false;
    	bool special = false;
    	for(int i=0;i<Pswrd.size();i++)
    	{
    		char ch=Pswrd[i];
        	if(ch>='A' && ch<='Z')
        	{
            	upper=true;
            }
        	else if (ch>='a' && ch<='z')
        	{
            	lower=true;
            }
        	else if(ch>='0' && ch<='9')
        	{
            	digit=true;
            }
        	else if(ch==' ')
        	{
            	return false;
            }
        	else
        	{
            	special=true;
            }
   		}
    	return upper && lower && digit && special;
	}
	bool PassConfirmation(string PassCnfm,string OrgnlPassWrd)
	{
		if(PassCnfm==OrgnlPassWrd)
		{
			return true;
		}
		cout<<"Doesn't Match!"<<endl;
		return false;
	}
};
class USER{
	public:
	void ShowMenu()
		{
			cout<<"1. Registration."<<endl;
			cout<<"2. Login."<<endl;
			cout<<"3. Exit. "<<endl;
			cout<<"Enter a Choice: ";
		}
		void RegisterMenu()
		{
			string Name,DOB,Numb,Email_Id,PassWord,PassConfirm;
			char Gend;
			int Age;
			cout<<endl;
			cout<<"--------------------------------"<<endl;
			cout<<"Registration Portal"<<endl;
			cout<<"--------------------------------"<<endl;
			cout<<endl;
			cout<<"Enter Your Name: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin,Name);
			cout<<"Enter Your Age: ";
			cin>>Age;
			DateOfBirth Birth;
			while(true)
			{	
				cout<<"Enter Your Birth Date(DD/MM/YYYY): ";
				cin>>DOB;
				if(Birth.IsValid(DOB))
				{
					break;
				}					
			}
			Gender Gen;
			while(true)
			{
				cout<<"Enter Your Gender (M/F): ";
				cin>>Gend;
				if(Gen.IsValid(Gend))
				{
					break;
				}	
			}
			Number Num;
			while(true)
			{
				cout<<"Enter Your Contact Number: ";
				cin>>Numb;
				if(Num.IsValid(Numb))
				{
					break;
				}
			}
			Email Id;
			while(true)
			{
				cout<<"Enter Your Email ID(xxxxx@gmail.com): ";
				cin>>Email_Id;
				if(Id.IsValid(Email_Id))
				{
					break;
				}	
			}
			start:
			Password Pass;
			cout << "Password must:"<<endl;
			cout << "1. Be at least 8 characters long."<<endl;
			cout << "2. Contain at least one uppercase letter."<<endl;
			cout << "3. Contain at least one lowercase letter."<<endl;
			cout << "4. Contain at least one digit."<<endl;
			cout << "5. Contain at least one special character."<<endl;
			cout << "6. Not contain spaces."<<endl;
			while(true)
			{
				cout<<"Enter Your Password: ";
				cin>>PassWord;
				if(Pass.IsValid(PassWord))
				{
					break;
				}
				cout<<"Invalid PassWord."<<endl;
				cout<<"ReEnter The PassWord According to the Condition."<<endl;	
			}
			while(true)
			{
				cout<<"PassWord Confirmation: ";
				cin>>PassConfirm;
				if(Pass.PassConfirmation(PassConfirm,PassWord))
				{
					break;
				}
				cout<<"If You Want ReEnter the Password press '1' or press '0' for ReEnter the password."<<endl;
				int option;
				cout<<"Enter: ";
				cin>>option;
				if(option)
				{
					goto start;
				}
			}
			ofstream file("User.txt",ios::app);
			file<<Name<<"|"<<Age<<"|"<<DOB<<"|"<<Gend<<"|"<<Numb<<"|"<<Email_Id<<"|"<<PassWord<<endl;
			file.close();
			cout<<endl;
			cout<<"Registered Successfully!!!"<<endl;
			cout<<"--------------------------------"<<endl;
			cout<<endl;
		}
		void LoginMenu()
		{
			Email Em;
			string Ch_Email,Ch_PassWord;
			while(true)
			{
				cout<<"Enter Your Email ID(xxxxx@gmail.com): ";
				cin>>Ch_Email;
				if(Em.IsValid(Ch_Email))
    			{
        			break;
    			}
				cout << "Entered Email is Invalid. Re-enter Valid Email ID."<<endl;
			}
			cout<<"Enter Your Password: ";
			cin>>Ch_PassWord;
			ifstream file("User.txt");			
			if(!file)
			{
				cout<<"No Registered Users Found."<<endl;
    			cout<<"Retry"<<endl;
			}
			else
			{
				string Name, DOB, Numb, Email_Id, PassWord;
				string Age;
				char Gend;

				string line;
				while(getline(file, line))
				{
    				stringstream ss(line);

				    getline(ss, Name, '|');
    				getline(ss, Age, '|');
    				getline(ss, DOB, '|');

    				string gender;
    				getline(ss, gender, '|');
    				Gend = gender[0];
	
				    getline(ss, Numb, '|');
    				getline(ss, Email_Id, '|');
    				getline(ss, PassWord, '|');

    				if(Email_Id == Ch_Email && PassWord == Ch_PassWord)
    				{
    					cout<<endl;
        				cout << "Logged in Successfully!" << endl;
        				cout<<"--------------------------------"<<endl;
        				cout<<endl;
       	 				return;
    				}
				}
				cout<<"The Given Email or Password is InCorrect"<<endl;
				cout<<"Retry"<<endl;
			}
		}
	};
int main()
{
	int Choice;
	while(true)
	{
		USER User;
		start:
		User.ShowMenu();
		cin>>Choice;
		switch(Choice)
		{
			case 1:
				User.RegisterMenu();
				break;
			case 2:
				User.LoginMenu();
				break;
			case 3:
				cout<<endl;
				cout<<"--------------------------------"<<endl;
				cout<<"Exited SuccessFully!!!"<<endl;
				return 0;
			default:
				cout<<"Enter a Valid Choice"<<endl;
				goto start;
		}
	}
	return 0;	
}
