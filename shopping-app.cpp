/*
	Muhammed Ali Iþýk
	1306190003
*/
#include <iostream>
#include <string>
using namespace std;
class shoplist
{
	public:
		int deletionstatus, productcount, productamount;
		string productname, productstatus = "undone";
};
int main()
{
	int numoflists=0;
	shoplist list[100][100];
	shoplist count[100];
	while(true)
	{
		string tempstr = "", y = "0", markstr = "";
		int x=0,z=0,t=0,edit=0,product=0,check=0, check2=0;
	mainmenu:
		cout<<"---Main Menu---"<<endl<<"1-Create new list"<<endl<<"2-Show and edit lists"<<endl<<"3-Exit"<<endl;
	wronginput:
		if(!(cin>>x) or x > 4)
		{
			cout<<"Please enter a valid input!"<<endl;
			cin.clear();
			cin.ignore();
			goto wronginput;
		}


		switch(x) //Main menu switch case
		{
			case 1:
				while(y == "0")
				{
					cout<<"Enter product name: ";
					cin.ignore();
					getline(cin, list[numoflists][product].productname);
					cout<<"Enter amount: ";
					while(!(cin>>list[numoflists][product].productamount))
					{
						cout<<"Please enter a valid input!"<<endl;
						cin.clear();
						cin.ignore();
					}
					cout<<"Enter 9 to finish list, 0 to continue ";
				m1:
					cin>>y;
					if(y != "0" and y != "9")
					{
						cout<<"Please enter a valid input!"<<endl;
						goto m1;
					}
					product++;
				}
				count[numoflists].productcount=product;
				numoflists++;
				break;
			case 2:
				if(numoflists == 0)
				{
					cout<<"There is no list"<<endl<<"Returning to main menu"<<endl;
					goto mainmenu;
				}
				for(int i=0;i<numoflists;i++)
				{
					cout<<"-----------------"<<endl;
					cout<<"Shopping List "<<i+1<<":"<<endl;
					for(int j=0;j<count[i].productcount;j++)
					{
						if(list[i][j].deletionstatus == 0)
						{
							cout<<"~~~~~~"<<endl;
							cout<<"Product: "<<list[i][j].productname<<endl;
							cout<<"Amount of "<<list[i][j].productname<<": "<<list[i][j].productamount<<endl;
							cout<<"Status of "<<list[i][j].productname<<" is: "<<list[i][j].productstatus<<endl;
							cout<<"~~~~~~"<<endl;
						}
					}
					cout<<"-----------------"<<endl;
				}

				cout<<"Enter shopping list number to edit: "<<endl;
			m2:
				if(!(cin>>t) or t > numoflists)
				{
					cout<<"Please enter a valid input!"<<endl;
					cin.clear();
					cin.ignore();
					goto m2;
				}
				cout<<"~~~Shopping List Menu~~~"<<endl<<"1.Add item"<<endl<<"2-Edit item"<<endl<<"3-Delete item"<<endl<<"4-Mark as done/undone"<<endl;
			m22:
				if(!(cin>>z))
				{
					cout<<"Please enter a valid input!"<<endl;
					cin.clear();
					cin.ignore(20,'\n');
					goto m22;
				}
				switch(z) //Shopping list switch case
				{
					case 1:
						cout<<"Enter new product's name: ";
						cin.ignore();
						getline(cin, list[t-1][(count[t-1].productcount)].productname);
						cout<<"Enter amount: ";
					s1:
						if(!(cin>>list[t-1][(count[t-1].productcount)].productamount))
						{
							cout<<"Please enter a valid input!"<<endl;
							cin.clear();
							cin.ignore();
							goto s1;
						}
						count[t-1].productcount++;
						cout<<"Returning to main menu"<<endl;
						break;
					case 2:
						cout << "Enter product's name to edit: ";
				    wrongproduct:
						tempstr = "";
						check = 0;
						if(!(check2))
							cin.ignore();
						getline(cin, tempstr);
						for(edit=0;edit<count[t-1].productcount;edit++)
						{
							if(list[t-1][edit].productname.compare(tempstr) == 0)
							{
								++check;
								cout<<"Enter another name to change product or enter same name to change amount: ";
								getline(cin, list[t - 1][edit].productname);
								cout<<"Enter amount: ";
							s2:
								if(!(cin>>list[t - 1][edit].productamount))
								{
									cout<<"Please enter a valid amount!" << endl;
									cin.clear();
									cin.ignore();
									goto s2;
								}
							}
						}
						if(check == 0)
						{
							cout<<"Please enter a valid product!\n";
							++check2;
							goto wrongproduct;
						}

						cout<<"Returning to main menu" << endl;
						break;
					case 3:
						cout<<"Enter product's name to delete: ";
					wrongdelete:
						check=0;
						tempstr = "";
						if(!(check2))
							cin.ignore();
						getline(cin, tempstr);
						for(int i=0;i<count[t-1].productcount;i++)
						{
							if(list[t-1][i].productname == tempstr)
							{
								++check;
								list[t-1][i].deletionstatus = 1;
							}
						}
						if(check == 0)
						{
								cout<<"Please enter a valid product!"<<endl;
								++check2;
								goto wrongdelete;
						}
						cout<<"Returning to main menu"<<endl;
						break;
					case 4:
					keepmarking:
						check=0;
						check2=0;
						markstr = "";
						tempstr = "";
						cout<<"Enter product's name to mark: ";
					wrongmark:
						if(!(check2))
							cin.ignore();
						getline(cin, tempstr);
						for(int i=0;i<count[t-1].productcount;i++)
						{
							if(list[t-1][i].productname == tempstr)
							{
								++check;
								cout<<"Type done or undone to mark: ";
							wrongmarkinput:
								cin>>markstr;
								if(markstr == "done")
								{
									list[t-1][i].productstatus = "done";
								}
								else if(markstr == "undone")
								{
									list[t-1][i].productstatus = "undone";
								}
								else
								{
									cout<<"Please enter a valid input!"<<endl;
									goto wrongmarkinput;
								}
							}
						}

						if(check == 0)
						{
							cout<<"Please enter a valid product!"<<endl;
							++check2;
							goto wrongmark;
						}

						tempstr="";
						cout<<"Type yes to keep marking or type no stop marking: ";
					wrongkeepmarking:
						cin>>tempstr;
						if(tempstr == "yes" or tempstr == "Yes")
						{
							goto keepmarking;
						}
						else if(tempstr == "no" or tempstr == "No")
						{
							cout<<"Returning to main menu"<<endl;
							continue;
						}
						else
						{
							cout<<"Please enter a valid input!"<<endl;
							goto wrongkeepmarking;
						}
						break;
					default:
						cout<<"Please enter a valid input!"<<endl;
						goto m22;
						break;
				}

				break;
			case 3:
				goto end;
			default:
				cout<<"Please enter a valid input!"<<endl;
				goto wronginput;
				break;
		}
	}
	end:
	return 0;
}
