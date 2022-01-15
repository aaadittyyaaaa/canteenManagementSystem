#include <iostream>
#include <fstream>
#include <string>
#include<string.h>
#include <iostream>
using namespace std ;
class Canteen {
public :
    int id_no ;
    char itemName[50] ;
    int qty ;
    int price ;

    void getData()
    {
        cout<<"Enter item name " ;
        cin.ignore() ;
        cin.getline(itemName , 50) ;
        cout<<"Enter id " ;
        cin>>id_no ;
        cout<<"Enter qty " ;
        cin>>qty ;
        cout<<"Enter price" ;
        cin>>price ;
    }
    void show()
    {
        ifstream myfile ;
           myfile.open("CanteenAll.dat" , ios::in | ios ::binary) ;
           if(!myfile)
           {
               cout<< "file not found " ;
           }
           else
           {
                myfile.read((char*)this , sizeof(*this)) ;
                while(!myfile.eof())
                {
                    cout << itemName << "\t" << id_no << "\t" << qty  << "\t" << price<< endl ;
                    myfile.read((char*)this , sizeof(*this)) ;
                }
                myfile.close() ;
           }
    }
    void allItems()
    {
        ifstream myfile ;
           myfile.open("CanteenAll.dat" , ios::in | ios ::binary) ;
           if(!myfile)
           {
               cout<< "file not found " ;
           }
           else
           {
                myfile.read((char*)this , sizeof(*this)) ;
                while(!myfile.eof())
                {
                    cout << itemName << endl ;
                    myfile.read((char*)this , sizeof(*this)) ;
                }
                myfile.close() ;
           }
    }
    void soldItems()
    {
        int counter = 0 ;
         ifstream myfile ;
            myfile.open("CanteenAll.dat" , ios::in|ios::binary) ;
            if(!myfile)
            {
                cout<<"file not found " ;
                return ;
            }
            else
            {
                myfile.read((char*)this ,  sizeof(*this)) ;
                while(!myfile.eof())
                {
                    if((qty==0))
                    {
                        counter = counter+1 ;
                        cout << itemName << "\t" << id_no << "\t" << qty<<"\t" << price  << endl ;
                    }
                    myfile.read((char*)this ,  sizeof(*this)) ;
                }
            }
            if(counter == 0 )
            {
                cout<<"No such item Exists" ;
            }
            myfile.close();
    }
    void AddNewItem()
    {
        cout << "Name of prod : " ;
            cout<<itemName ;
            cout<< endl ;
            cout << "Entered ID number : " ;
            cout << id_no ;
            cout<< endl ;
            cout << "Entered quantity of product : " ;
            cout <<qty ;
            cout<<endl ;
            cout<<"Entered the price " ;
            cout<<price ;
            cout<< endl ;
            if(strcmp(itemName , NULL))
               {
                   return ;
               }
            ofstream myfile("CanteenAll.dat" , ios :: app | ios :: binary) ;
            myfile.write((char*)this , sizeof(*this)) ;
            myfile.close();
    }
    void editItem(char *t)
    {
       fstream myfile ;
       myfile.open("CanteenAll.dat" , ios::in|ios::out|ios::ate|ios::binary);
       myfile.seekg(0);
       myfile.read((char*)this  , sizeof(*this));
       while(!myfile.eof())
       {
           if(!strcmp(t,itemName))
           {
               getData() ;
               myfile.seekp(myfile.tellp()-sizeof(*this));
               myfile.write((char*)this ,sizeof(*this));

           }
           myfile.read((char*)this  , sizeof(*this));
       }
    }
    void deleteItem(char *t)
     {
            ifstream fin ;
            ofstream fout ;
            fin.open("CanteenAll.dat" , ios:: in | ios ::binary) ;
            if(!fin)
            {
                cout<<"file not found " ;
            }
            else
            {
                fout.open("tempfile.dat" , ios::out | ios::app |ios::binary) ;
                fin.read((char*)this , sizeof(*this));
                while(!fin.eof())
                {
                    if(!strcmp(t , itemName))
                    {
                        fout.write((char*)this , sizeof(*this)) ;
                    }
                    fin.read((char*)this , sizeof(*this));
                }
                fin.close();
                fout.close();
                remove("CanteenAll.dat");
                rename("tempfile.dat" , "CanteenAll.dat") ;
            }
     }
    void searchById(int *t)
    {
        int counter = 0 ;
         ifstream myfile ;
            myfile.open("CanteenAll.dat" , ios::in|ios::binary) ;
            if(!myfile)
            {
                cout<<"file not found " ;
                return ;
            }
            else
            {
                myfile.read((char*)this ,  sizeof(*this)) ;
                while(!myfile.eof())
                {
                    if((*t==id_no))
                    {
                        counter = counter+1 ;
                        cout << itemName << "\t" << id_no << "\t" << qty<<"\t" << price  << endl ;
                    }
                    myfile.read((char*)this ,  sizeof(*this)) ;
                }
            }
            if(counter == 0 )
            {
                cout<<"No such item Exists" ;
            }
            myfile.close();
    }
    void searchByName(char* t)
    {
       int counter = 0 ;
         ifstream myfile ;
            myfile.open("CanteenAll.dat" , ios::in|ios::binary) ;
            if(!myfile)
            {
                cout<<"file not found " ;
                return ;
            }
            else
            {
                myfile.read((char*)this ,  sizeof(*this)) ;
                while(!myfile.eof())
                {
                    if((!
                        strcmp(t,itemName)))
                    {
                        counter = counter+1 ;
                        cout << itemName << "\t" << id_no << "\t" << qty<<"\t"<<price  << endl ;
                    }
                    myfile.read((char*)this ,  sizeof(*this)) ;
                }
            }
            if(counter == 0 )
            {
                cout<<"No such item Exists" ;
            }
            myfile.close();
    }
    //void addNewSale();
};
int main()
{
    Canteen c1 ;
    cout<< "Welcome User" << endl ;
    char num ;
    cout<< " Enter a no.  according to the service you want " ;


        system("cls") ;
        cout<<"\n\n\t\t\t\t======================\n";
	cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t\t======================\n";

		cout<<"\t\t\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t\t\t1. Show items";
		cout<<"\n\t\t\t\t2. Sold items";
		cout<<"\n\t\t\t\t3. Add New Item";
		cout<<"\n\t\t\t\t4. Edit Item";
		cout<<"\n\t\t\t\t5. Delete Item";
		cout<<"\n\t\t\t\t6. Search By id ";
		cout<<"\n\t\t\t\t7. Search By Name ";
		cout<<"\n\t\t\t\t8. All Items ";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-8): ";
		cin>>num ;


          switch(num)
		{
        case '1' :
            {
                system("cls");

                c1.show();
                break ;
            }
        case '2' :
            {
                system("cls");
                c1.soldItems();
                break ;
            }

         case '3' :
            {
                system("cls");
                c1.getData() ;
                c1.AddNewItem();
                break ;
            }
         case '4' :
            {
                system("cls");
                char s[50] ;
                cout<<"enter item name : " ;
                cin.getline(s,50) ;
                c1.editItem(s);
                break ;
            }
         case '5' :
            {
                system("cls");
                char s[50] ;
                cout<<"enter item name : " ;
                cin.getline(s,50) ;
                c1.deleteItem(s);
                break ;
            }
        case '6' :
            {
                system("cls");
                int n ;
                cout<<"enter id number : " ;
                cin>> n  ;
                c1.searchById(&n);
                break ;
            }
        case '7' :
            {
                system("cls");
                char s[50] ;
                cout<<"enter item name : " ;
                cin.getline(s,50) ;
                c1.searchByName(s);
                break ;
            }
        case '8' :
            {
                system("cls");
                c1.allItems();
                break ;
            }
        case '9' :
            {
                return 0 ;
                break ;
            }
         default :
            {
                cout<< " \a" ;
                cout<< "Enter valid input" ;
            }

		}



		return 0 ;


}


