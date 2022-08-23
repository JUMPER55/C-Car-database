#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

using namespace std;

void crlist(struct car*);
void crdelete(struct car*);
void cradd(struct car*);
void crsearchid(struct car* );
void crregistrationyear(struct car* );
void crupdate(struct car* );
void crsortid(struct car* );
void carsortownerName(struct car* );
void carsearchownerName(struct car* );

struct date
       {
       int day, month, year;
       };
struct car
       {
       int ID;
       string ownerName;
       string ownerSurname;
       string make;
       string model;
       struct date reg_date, ns_date;
   
       } ;
    struct date kkk[20];
    struct car cr[20];
  
int main() {
    int exit=0;
    int i=0;
    int j;
    int key;
    string alp;
  

    while(exit<=1)
    {
      
        cout<<"\n PLEASE SELECT A CAR DIRECTORY FROM 1-8 ";
        cout<<"\n 1. Add new car ";
        cout<<"\n 2. Delete an car ";
        cout<<"\n 3. list available car ";
        cout<<"\n 4. Search ";
        cout<<"\n\ta) Search according to car id \n\tb)Search according to Owner Name";
        cout<<"\n 5. Update ";
        cout<<"\n 6. Sort  according to Car Name";
        cout<<"\n 7. Sort according to Owner name ";
        cout<<"\n 8. Quit \n";
        cout<<"\n\n\t ENTER A MENU CHOICE: ";
        cin>>key;
        if(key==1)
        {
            cradd(cr);
        }
        else if(key==2)
        {
            crlist(cr);
            crdelete(cr);
            
            cout << "\n User Successfully Deleted";
          
            system("cls");
        }
        else if(key==3)
        {
            crlist(cr);
            system("PAUSE");
            system("cls");
        }
        else if(key==4)
        {
            cout<<" 			  A - Search according to car id ";
             cout<<"\n			  B - Search according to OwnerName";
             cout<<"\n ENTER YOUR CHOICE: ";
             cin>>alp;
            if( alp=="A" || alp=="a" )
            {
             crsearchid(cr);
             system("PAUSE");
            system("cls");
            }
            else if(alp=="B" || alp=="b" )
            {
                carsearchownerName(cr);
                system("PAUSE");
                system("cls");
            }
            else
            {
                cout<<"incorrect value please try again  Redirecting"<<endl;
                 system("PAUSE");
                system("cls");
                return main();
            }
        }
        else if(key==5)
        {
            crlist(cr);
            crupdate(cr);
        }
        else if(key==6)
        {
           
            crsortid(cr );
            crlist(cr);
             system("PAUSE");
            system("cls");
            
        }
  
 		else if (key == 7){
 			
 		carsortownerName(cr);
        system("PAUSE");
        system("cls");	
 			
 			
		 } 
  
        else if(key==8)
        {
            exit=3;
        }
        else{
            cout<<"incorrect value please try again Redirecting "<<endl;
            system("PAUSE");
            system("cls");
            return main();          
        }
      
    }
    return 0;
}
void crlist(struct car* cr)
{
    int i=0;
    cout<<endl<<endl;
    	cout<<"ID"<<" OWNERNAME"<<"  "<<"OWNERSURNAME"<<" MAKER"<<  "  MODEL"<< "    REG_DATE"<<"  ns_date"<<endl;
  
    while(i<20)
    {
            if(cr[i].ownerName=="")
            {
                break;
            }
      
        cout<<cr[i].ID<<"   "<<cr[i].ownerName<<"   "<< cr[i].ownerSurname<<"    "<< cr[i].make<< "    "<<cr[i].model<<"    " <<cr[i].reg_date.day<<"/"<<cr[i].reg_date.month<<"/"<<cr[i].reg_date.year<<"               "<<cr[i].ns_date.day<<"/"<<cr[i].ns_date.month<<"/"<<cr[i].ns_date.year<<endl;
      
        i++;
    }

}
void crdelete(struct car* cr )
{
  
    int key=0;
    int id;
    int k=0;
    int begin=0;
    cout<<"Please enter car ID for delete=> ";
    cin>>id;
        for( k=0;k<20;k++)
        {  
            if(id !=0)
            {
                 if(cr[k].ID==id)
                {
                    key=1;
                    begin=k;
                    break;
                }
              
              
            }
            else
            {
                return;
              
            }
  
        }
        if(key==1)
        {
            for(int i =begin; i<21;i++)
            {
                    cr[i].ID=cr[i+1].ID;
                    cr[i].ownerName=cr[i+1].ownerName;
                    cr[i].ownerSurname=cr[i+1].ownerSurname;
                    cr[i].reg_date.day=cr[i+1].reg_date.day;
                    cr[i].reg_date.month=cr[i+1].reg_date.month;
                    cr[i].reg_date.year=cr[i+1].reg_date.year;
                    cr[i].ns_date.day=cr[i+1].ns_date.day;
                    cr[i].ns_date.day=cr[i+1].ns_date.day;
                    cr[i].ns_date.day=cr[i+1].ns_date.day;
                if(cr[i].ownerName=="")
                {
                    break;
                }
            }
        }
  

    system("cls");
}
void cradd(struct car* cr)
{
    string ownerName;
    string ownerSurname;
    string make;
    string model;
    int id;
    int reg_day;
    int reg_month;
    int reg_year;
    int exp_day;
    int exp_month;
    int exp_year;
    int control=1;      
            cout<<"Please enter car new ID => ";
            cin>>id;
            cout<<"Please enter car new Owner Name => ";
            cin>>ownerName;
  			cout<<"Please enter car new Owner Surname => ";
            cin>>ownerSurname;    
			cout<<"Please enter car new Car Maker => ";  
			cin>>make;  
			cout<<"Please enter car new  Car Model => ";
			cin >> model;  
            cout<<endl;
          
            cout<<"Please enter respectively car new reg_DAY => ";
            cin>>reg_day;
      
            cout<<"Please enter respectively car new reg_MONTH => ";
            cin>>reg_month;
          
            cout<<"Please enter respectively car new reg_YEAR => ";
            cin>>reg_year;
            cout<<endl;
            cout<<"Please enter respectively car  Next Service_DAY => ";
            cin>>exp_day;
      
            cout<<"Please enter respectively car Next Service_MONTH => ";
            cin>>exp_month;
  
            cout<<"Please enter respectively car Next Service_YEAR => ";
            cin>>exp_year;
      
        for(int k=0;k<20;k++)
        {  
            if(cr[k].ID==id)
            {
            control=0;      
            }      
        }
            if(id!=0 && id>0)
            {
          
            if( control==1)
            {
                for(int i=0;i<20;i++)
                {
              
                    if(cr[i].ownerName =="")
                    {
                        cr[i].ID=id;
                        cr[i].ownerName=ownerName;
                        cr[i].ownerSurname=ownerSurname;
                        cr[i].make=make;
                        cr[i].model=model;
                        cr[i].reg_date.day=reg_day;
                        cr[i].reg_date.month=reg_month;
                        cr[i].reg_date.year=reg_year;
                        cr[i].ns_date.day=exp_day;
                        cr[i].ns_date.month=exp_month;
                        cr[i].ns_date.year=exp_year;
                        cout<<"Data were successfully saved Redirecting";
                      
                        getchar();                      
                           system("cls");
                           return;
                    }

                }
            }
            else{
                cout<<"this id in use"<<endl;
                 system("PAUSE");
                system("cls");
            }
            }
            else{
                cout<<"this id should not be less than 1 ";
                cout<<"this id in use"<<endl;
                 system("PAUSE");
                system("cls");
            }
}

void crsearchid(struct car* cr)
{
    int id;
    int i=-1;
    int control=1;
    cout<<"Please enter car ID => ";
    cin>>id;
        for(int k=0;k<20;k++)
        {  
            if(cr[k].ID==id)
            {
            control=0;
            i=k;
            break;  
            }      
        }
      
        if(control==0)
        {
  		cout<<"ID"<<" OWNERNAME"<<"  "<<"OWNERSURNAME"<<" MAKER"<<  "  MODEL"<< "    REG_DATE"<<"  ns_date"<<endl;
  		cout<<cr[i].ID<<"   "<<cr[i].ownerName<<"   "<< cr[i].ownerSurname<<"    "<< cr[i].make<< "    "<<cr[i].model<<"    " <<cr[i].reg_date.day<<"/"<<cr[i].reg_date.month<<"/"<<cr[i].reg_date.year<<"               "<<cr[i].ns_date.day<<"/"<<cr[i].ns_date.month<<"/"<<cr[i].ns_date.year<<endl;
        
        }
        else{
            cout<<"This ID has not been Used => "<<endl;

        }

}
void crregistrationyear(struct car*)
{
    int id_year;
    int i=-1;
    int control=1;
    cout<<"Please enter car year => ";
    cin>>id_year ;
        for(int k=0;k<20;k++)
        {  
            if(cr[k].reg_date.year==id_year)
            {
            control=0;
            i=k;
            break;  
            }      
        }
      
        if(i>=0)
        {
  		cout<<"ID"<<" OWNERNAME"<<"  "<<"OWNERSURNAME"<<" MAKER"<<  "  MODEL"<< "    REG_DATE"<<"  ns_date"<<endl;
  		cout<<cr[i].ID<<"   "<<cr[i].ownerName<<"   "<< cr[i].ownerSurname<<"    "<< cr[i].make<< "    "<<cr[i].model<<"    " <<cr[i].reg_date.day<<"/"<<cr[i].reg_date.month<<"/"<<cr[i].reg_date.year<<"               "<<cr[i].ns_date.day<<"/"<<cr[i].ns_date.month<<"/"<<cr[i].ns_date.year<<endl;
        }
        else{
            cout<<"This Name has not been Used => "<<endl;
        }

  
}
void crupdate(struct car* )
{
    string ownerName;
    string ownerSurname;
    string make;
    string model;
    int id;
    int reg_day;
    int reg_month;
    int reg_year;
    int exp_day;
    int exp_month;
    int exp_year;
    int i=-1;
    int control=1;
    cout<<"Please enter employee ID => ";
    cin>>id;
        for(int k=0;k<20;k++)
        {  
            if(cr[k].ID==id)
            {
            control=0;
            i=k;
            break;  
            }      
        }
    if(i>=0)
        {
            cout<<"Please enter car new ID => ";
            cin>>id;
            cout<<"Please enter car new Owner NAME => ";
            cin>>ownerName;
            cout<<"Please enter car new Owner SurNAME => ";
            cin>>ownerSurname;
            cout<<"Please enter car new Car Maker => ";  
			cin>>make;  
			cout<<"Please enter car new  Car Model => ";
			cin >> model; 
            
            cout<<endl;
          
            cout<<"Please enter respectively car new reg_DAY => ";
            cin>>reg_day;
      
            cout<<"Please enter respectively car new reg_MONTH => ";
            cin>>reg_month;
          
            cout<<"Please enter respectively car new reg_YEAR => ";
            cin>>reg_year;
            cout<<endl;
            cout<<"Please enter respectively car new exp_DAY => ";
            cin>>exp_day;
      
            cout<<"Please enter respectively car new exp_MONTH => ";
            cin>>exp_month;
  
            cout<<"Please enter respectively car new exp_YEAR => ";
            cin>>exp_year;
              
                        cr[i].ID=id;
                        cr[i].ownerName=ownerName;
                        cr[i].ownerSurname=ownerSurname;
                        cr[i].make=make;
                        cr[i].model=model;
                        cr[i].reg_date.day=reg_day;
                        cr[i].reg_date.month=reg_month;
                        cr[i].reg_date.year=reg_year;
                        cr[i].ns_date.day=exp_day;
                        cr[i].ns_date.month=exp_month;
                        cr[i].ns_date.year=exp_year;
                        cout<<"Data were successfully updated";
                  
        }
  
}
void crsortid(struct car* cr)
{
     int i,j,tcr,flag,tcrexp,tcrreg;
     string tcrStd;
     for (i=0;i<20-1;i++)
     {
         flag=0;

         for(j=0;j<20-1-i;j++)
         {

            if (cr[j].ID > cr[j+1].ID)
            {
                if(cr[j+1].ownerName=="")
                {
                    break;
                }
                else
                {
                    tcr = cr[j].ID;
                    cr[j].ID = cr[j+1].ID;
                    cr[j+1].ID = tcr;
                  
                    tcrStd = cr[j].ownerName;
                    cr[j].ownerName = cr[j+1].ownerName;
                    cr[j+1].ownerName = tcr;
                  
                    tcrreg = cr[j].reg_date.day;
                    cr[j].reg_date.day = cr[j+1].reg_date.day;
                    cr[j+1].reg_date.day = tcrreg;
                  
                    tcrreg = cr[j].reg_date.month;
                    cr[j].reg_date.month = cr[j+1].reg_date.month;
                    cr[j+1].reg_date.month = tcrreg;
                  
                    tcrreg = cr[j].reg_date.year;
                    cr[j].reg_date.year = cr[j+1].reg_date.year;
                    cr[j+1].reg_date.year = tcrreg;
                  
                    tcrexp = cr[j].ns_date.day;
                    cr[j].ns_date.day = cr[j+1].reg_date.day;
                    cr[j+1].ns_date.day = tcrexp;
                  
                    tcrexp = cr[j].ns_date.month;
                    cr[j].ns_date.month = cr[j+1].reg_date.month;
                    cr[j+1].ns_date.month = tcrexp;
                  
                    tcrexp = cr[j].ns_date.year;
                    cr[j].ns_date.year = cr[j+1].reg_date.year;
                    cr[j+1].ns_date.year = tcrexp;
                  
                  
                        flag=1;
                }


            }
         }
        if (flag==0) break;
     }
                 

}

void carsortownerName(struct car* cr)
{
	int i,j,tcr,flag,tcrexp,tcrreg;
	 string tcrStd;
     for (i=0;i<20-1;i++)
     {
         flag=0;

         for(j=0;j<20-1-i;j++)
         {

            if (cr[j].ownerName > cr[j+1].ownerName)
            {
            	if(cr[j+1].ownerName=="")
            	{
            		break;
				}
				else
				{
				
                	cr[j].ownerName = cr[j+1].ownerName;
                	cr[j+1].ownerName = tcr;  
                	
                	tcrStd = cr[j].ID;  
                	cr[j].ID = cr[j+1].ID;
                	cr[j+1].ID = tcr;
                	
					tcrreg = cr[j].reg_date.day; 
                	cr[j].reg_date.day = cr[j+1].reg_date.day;
                	cr[j+1].reg_date.day = tcrreg;
                	
                	tcrreg = cr[j].reg_date.month;  
                	cr[j].reg_date.month = cr[j+1].reg_date.month;
                	cr[j+1].reg_date.month = tcrreg;
                	
                	tcrreg = cr[j].reg_date.year; 
                	cr[j].reg_date.year = cr[j+1].reg_date.year;
                	cr[j+1].reg_date.year = tcrreg;
                	
                	tcrexp = cr[j].ns_date.day;  
                	cr[j].ns_date.day = cr[j+1].reg_date.day;
                	cr[j+1].ns_date.day = tcrexp;
                	
                	tcrexp = cr[j].ns_date.month;  
                	cr[j].ns_date.month = cr[j+1].reg_date.month;
                	cr[j+1].ns_date.month = tcrexp;
                	
                	tcrexp = cr[j].ns_date.year;  
                	cr[j].ns_date.year = cr[j+1].reg_date.year;
                	cr[j+1].ns_date.year = tcrexp;
                	
                	
              		  flag=1;
				}


            }
         }
        if (flag==0) break;
     }
                   

}


void carsearchownerName(struct car* )
{
	string ownerName;
	int i=-1;
	int control=1;
	cout<<"Please enter car ownerName => ";
	cin>>ownerName;
		for(int k=0;k<20;k++)
		{	
			if(cr[k].ownerName==ownerName)
			{
			control=0;
			i=k;
			break;	
			}		
		}
		
		if(i>=0)
		{
	
		cout<<"                        "<<cr[i].ID<<"    "<<cr[i].ownerName<<"       "<<cr[i].reg_date.day<<"/"<<cr[i].reg_date.month<<"/"<<cr[i].reg_date.year<<"    "<<cr[i].ns_date.day<<"/"<<cr[i].ns_date.month<<"/"<<cr[i].ns_date.year<<endl;
			
		}
		else{
			cout<<"This ownerName has not been Used => "<<endl;
		}

	
}
