#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<ctime>
#include<stdbool.h>
#include <iomanip>
#include<fstream>
#include<conio.h>
using namespace std;

void intro() {
	cout<<"\n\n\t            ";
	cout<<"\t\t      Project On Hotel Management System";
	cout<<"\n\n\t\t\t\t\t\t  MADE BY";
	cout<<"\n\n\t\t\t\t\t\t Shakeel Khan";
	cout<<"\n\t\t같같같같같같같같같같같같같같같같같같같같같";
	cout<<"같같같같같같같같같같같같같같같같같같같";
	cout<<"\t\t\t\t\t      ";

	cout<<"\t\t\t\t\tGroup No 11";
	

	cout<<"\t\t\t\t\t\t";
	cout<<"\t\t\t\t\t같같같같같같같같같같같같같같같같같같같같같";
	cout<<"같같같같같같같같같같같같같같같같같같같\n\n";
}

class Exception;
class Customer;
class RoomCustomer;
class Employee;
class Dish;
class RestaurantCustomer;
class Restaurant;
class Hotel;
class Room;
class RoomService;


class Exception
{
	public:
		int errNo;
		string msg;
		
	public:
		Exception(int errNo,string msg)
		{
			this->errNo=errNo;
			this->msg=msg;
		}
		
		void what()
		{
			cout<<"\t\t"<< errNo<<" :: "<< msg<<endl;
		}
};


class Room
{
	public:
		string roomType;
		int noOfBeds;
		double rent;
		int roomNo;
		int status;
		
	public:
		Room(string roomType,int noOfBeds,double rent,int roomNo )
		{
			this->roomType=roomType;
			this->noOfBeds=noOfBeds;
			this->rent=rent;
			this->roomNo=roomNo;
			this->status=0;
						
		}
		void setRoom()
		{
			cout<<"\t\t\tEnter Room Type, No of beds, Rent, RoomNo\n";
			cin>>this->roomType;
			cin>>this->noOfBeds;
			cin>>this->rent;
			cin>>this->roomNo;
			status=0;
			
		}
		
		Room()
		{
		}

		
		
		
		bool isVacant(Room r)
		{
			if(r.status==1)
			return false;
			else 
			return true;
		}
		
		void displayDetail()
		{
			
			cout<<"\t\t\tRoom Type :: "<<this->roomType<<endl;
			cout<<"\t\t\tNumber of Beds :: "<<this->noOfBeds<<endl;
			cout<<"\t\t\tRent :: "<<this->rent<<endl;
			cout<<"\t\t\tRoom Number ::"<<this->roomNo<<endl;
			if(status==1)
			cout<<"\t\t\t Occupied \n";
			else
			cout<<"\t\t\tVacant \n";
		}
		
		void vacateRoom(int rno)
		{
			int i;
			for(i=0;i<6;i++)
			{
				if(this->roomNo==rno)
			this->status=0;
		}
		}
		
		void displayAvailable(Room r[6])
		{
			int i;
			for(i=0;i<6;i++)
			{
				if(r[i].status==0)
				r[i].displayDetail();
			}
		}
		
};

class Dish
{
	public:
		string dishName;
		double price;
		string dishType;
		
	public:
		Dish(string dishName,double price,string dishType)
		{
			this->dishName=dishName;
			this->price=price;
			this->dishType=dishType;
		}
		Dish()
		{
		    
		}
};



class Customer
{
	public:
		string custName;
		string custAddress;
		string custID;
		long int custPhone;
		string custEmail;
		string checkInTime;
		int status;
		
	public:
		Customer()
		{
			time_t c=time(0);
	        string dt = ctime(&c);
			this->custName=" ";
			this->custAddress =" ";
			this->custID =" ";
			this->custPhone = 0L;
			this->custEmail =" ";
			this->checkInTime = dt;
			status=0;
		}
		
		void setData()
		{
			time_t now=time(0);
			string dt = ctime(&now);
			this->checkInTime = dt;
			ofstream customer;
			customer.open("Customer.txt",ios::ate);
			cout<<"\t\t\tEnter your Name :\n";
			cin>>this->custName;
			customer << "Name ::"<< this->custName<<"\n";
			
			cout<<"\t\t\tEnter your Address :\n";
			cin>>this->custAddress;
   			customer<< "\t\t\tAddress ::"<< this->custAddress<<"\n";
			
			cout<<"\t\t\tEnter your Phone number :\n";
			cin>>this->custPhone;
			customer << "Phone ::"<< this->custPhone<<"\n";
			
			cout<<"\t\t\tEnter your Email :\n";
			cin>>this->custEmail;
			customer << "\t\t\tEmail ::"<< this->custEmail<<"\n\n";
			customer.close();
			
		}
		
		int selectChoice()
		{
			int ch;
			cout<<" \t\t\tHello!\n";
			cout<<"\t\t\tEnter \n1. Room Booking \n 2. Dine\n ";
			cin>>ch;
			return ch;
		}
		
	
		
		virtual void printCustomer()
		{
			cout<<"\t\t\tName :: "<<this->custName<<endl;
			cout<<"\t\t\tAddress :: "<< this->custAddress<<endl;
			cout<<"\t\t\tID :: " <<custID<<endl;
			cout<<"\t\t\tPhone Number :: "<< custPhone<<endl;
			cout<<"\t\t\tEmail :: "<<custEmail<<endl;
			cout<<"\t\t\tCheck-In Time ::"<<this->checkInTime<<endl;
			
 		} 
		virtual void viewTotalBill(){
		}
		virtual void allocateRoom(Room r1){
		}
		virtual void allocateDish(Dish d1){
		}
		virtual void checkout(){
		}
};

class RoomCustomer : public Customer
{
	public:
		double rbill;
		Room r;
		int bookStatus;
	public:
		
		void viewTotalbill()
		{
			cout<<"\t\t\tBill ="<<rbill;
		}
		
		void allocateRoom(Room r1)
		{
			this->r=r1;
		}
		
		void printCustomer()
		{		
				
				Customer :: printCustomer();
				if(r.status==1 && bookStatus==1)
				
				{
				cout<<"\t\t\tCheck-In Time :: "<< checkInTime<<endl;
				cout<<"\t\t\tRoom type :: "<<r.roomType<<endl;
				cout<<"\t\t\tRoom Number :: "<<r.roomNo<<endl;
				
		}}
		void viewTotalBill()
		{
			this->rbill=r.rent;
			cout<<"\t\t\tBill :: "<<this->rbill<<endl;
		}
		void checkOut()
		{
			cout<<"\t\t\tYour bill is "<<this->rbill<<"/-"<<endl;
			this->rbill=0;
			this->r.status=0;
			cout<<"\t\t\tThank You! Visit Again.\n"<<endl;
		}
		
			
};


class RestaurantCustomer:public Customer
{
	public:
		double dbill;
		Dish d;
		int orderStatus;
	public:
		
		void viewTotalbill()
		{
			cout<<"\t\t\tBill ="<<dbill;
		}
		
		 void allocateDish(Dish d1)
		 {
		 	this->d=d1;
		 }
		void printCustomer()
		{		
				
				Customer :: printCustomer();
				if(orderStatus )
				{
				cout<<"\t\t\tDish Name :: "<<d.dishName<<endl;
				cout<<"\t\t\tDish Type :: "<<d.dishType<<endl;
				
				}}
		void viewTotalBill()
		{
			this->dbill=d.price;
			cout<<"\t\t\tBill :: "<<this->dbill<<endl;
		}
			
};


class Employee
{
	
	public:
		
	
		virtual void performDuty()=0;
		virtual ~Employee(){
		}
};


class RoomService:public Employee
{
	public:
		void performDuty()
		{
		cout<<"\t\t\tEmployee Assistant Manager arriving at your doorstep...\n\n";
		}
		
		virtual ~RoomService(){
		}

};

class Waiter:public Employee
{
	public:
		void performDuty()
		{
			
			cout<<"\n\n\t\t\tEmployee waiter arriving at your table to take your Order\n\n";
			
		}
		virtual ~Waiter(){
		}
};

class SelectEmployee{
	//protected:
	Employee *e;
	
	public:
		SelectEmployee(Employee *e1)
		{
			e=e1;
		}
		
		void performDuty()
		{
			e->performDuty();
		}
	
};

class Restaurant
{
	public:
		Dish dish[8];
	
	public:
		void addDishes()
		{
			ofstream menu;
			menu.open("Menu.txt",ios::ate);
			int i;
			for(i=0;i<8;i++)
			{
				cout<<i+1<<"\t\t\t Enter Dish Name Price and Type\n";
				cin>>dish[i].dishName>>dish[i].price>>dish[i].dishType;
				menu<< dish[i].dishName<<"\t"<<dish[i].price<<"\t"<<dish[i].dishType<<"\n";
			}
			menu.close();
		}
		
		
			Dish getDish(string dnam)
		{
			int i;
			for(i=0;i<8;i++)
			{
				
				if(dish[i].dishName==dnam)	
						
				{
					return dish[i];
				}
		}
	}
		


			void displayDish(Dish d)
		{
			cout<<" \t\t\tDish Name :: "<<d.dishName<<endl;
			cout<<"\t\t\t Price :: "<<d.price<<endl;
			cout<<" \t\t\tDish Type :: "<<d.dishType;
			
		}
		
		void displayMenu()
		{
			int i;
			for(i=0;i<8;i++)
			{
				displayDish(dish[i]);
			}
			
		}
	
};



class Hotel
{
	private:
		static Hotel *instanceHotel;
		string hotelName;
		string hotelAddress;
	public:
		Employee *employee[5];
		Restaurant restuarant;
		
		Room room[6];
		Customer *customer[5];
		
	private: 
			
		
		Hotel(string hname,string add)
		{
			this->hotelName=hname;
			this->hotelAddress=add;
		}
	public:
		static Hotel* getHotel()
		{
			if(!instanceHotel)
			instanceHotel=new Hotel("Khan","Abbottabad");
			return instanceHotel;
		}
		
		void setHotel(Restaurant r,Room rs[6])
		{
			int i;
			
			for(i=0;i<6;i++)
			{
				this->room[i]=rs[i];
			}
			for( i=0;i<8;i++)
			this->restuarant.dish[i]=r.dish[i];
			
		}
		void generateID(Customer *c)
		{
			time_t t;
			static const char m[]="abcdefghijklmnopqrstuvwxyz";
			int i;
			
			for(i=0;i<6;i++)
			{
				c->custID=c->custID+ m[rand() % (sizeof(m)- 1)];
			}
			
		}
		
		Room getRoom(int rno)
		{
			int i;
			for(i=0;i<6;i++)
			{
				if(room[i].roomNo==rno)
				return room[i];
			}
		}
	 void displayAvailble(){
	 	int i;
	 	cout<<"\n\n----------------------------------------------Room Details----------------------------------------------\n\n";
	 	cout<<setw(25)<<"Room Type"<<setw(25)<<"Number of Beds"<<setw(25)<<"Rent"<<setw(25)<<"Room Number\n";
			for(i=0;i<6;i++)
			{
				if(room[i].status==0)
				{
					cout<<setw(25)<<room[i].roomType;
					cout<<setw(25)<<room[i].noOfBeds;
					cout<<setw(25)<<room[i].rent;
					cout<<setw(25)<<room[i].roomNo<<"\n";
				}
			}
			cout<<"\n\n";
	 }
	 
	 void displayMenu()
	 {
	 	cout<<"\n\n-----------------------------------------------Menu-------------------------------------------------\n\n ";
	 		int i;
	 		const int width=8;
	 		cout<<setw(25)<<" Dish Name"<<setw(25)<<"Price"<<setw(25)<<"Dish Type"<<endl;
			for(i=0;i<8;i++)
			{
			
			cout<<setw(25)<<restuarant.dish[i].dishName;
			cout<<setw(25)<<restuarant.dish[i].price;
			cout<<setw(25)<<restuarant.dish[i].dishType<<"\n";
			}
	 	cout<<"\n\n";
	}
	
		void bookRoom(int r)
		{
			int i;
			for(i=0;i<6;i++)
			{
			if(room[i].roomNo==r)
		room[i].status=1;}
		}

		
		void askFeedback()
		{
			int f;
			string cname;
			ofstream feedback;
  			feedback.open ("feedback.txt",ios::app);
  			feedback <<"\t\t\tCustomer Name\t : ";
			cout<<"\t\t\tEnter your Name\n";
			cin>>cname;
			feedback<<cname<<"\t\t\t";
			cout<<" \t\t\tThanks for your time! \n How likely are you to recommend Khan Hotel to a Friend or Colleague? \n \t\t\tRate on a scale of 1-10\n";
			cin>>f;
			feedback<<"\t\t\tFeedback\t: ";
			feedback<<f<<"\n";
			feedback.close();
				cout<<" \t\t\tThanks for your valuable feedback!"<<endl;
		}
		
		void getCustomerData(Customer *c)
		{
			cout<<" \t\t\tName :: "<<c->custName<<endl;
			cout<<" \t\t\tAddress :: "<<c->custAddress<<endl;
			cout<<" \t\t\tPhone :: "<<c->custPhone <<endl;
			cout<<" \t\t\tEmail :: "<<c->custEmail <<endl;
			cout<<" \t\t\tCheck-In Time:: "<<c->checkInTime <<endl;
		}
		
		 void vacateRoom(int rno)
		{
			int i,j=0;
			for(i=0;i<6;i++)
			{
				
				if(room[i].roomNo==rno)
			{
				j=1;
			room[i].status=0;
			cout<<"\t\t\tThank You! Visit Again.\n"<<endl;}
			}
				if(j==0)
				throw Exception(8,"\t\t\tSorry! Room Not Found, or occupied at the moment\n");
		
		}
		void takeOrder(string dnm)
		{
			int i,j=0;;
			for(i=0;i<8;i++)
			{
			if(	restuarant.dish[i].dishName== dnm)
			{ 
			j=1;
			cout<<"\t\t\tOrder Successful\n"<<endl;
			}
			}
			if(j==0)
			throw Exception(9, "\t\t\tSorry! Dish Not Found, Enter a valid entry");
		}
			 
};
Hotel *Hotel :: instanceHotel=0;
int main()
{
	system("color 70");
	system("cls");
	intro();
	char id[5],pass[7];
	cout<<"\n\n\t\t\t\tusername => ";
	cin>>id;
	cout<<"\n\t\t\t\tpassword => ";
	cin>>pass;
	cout<<"\n\n\t";
//	time();
	cout<<"\t";
	if(strcmp(id,"khan")==0&&strcmp(pass,"0000")==0)
		cout<<"\n\n\t\t\t  !!!Login Successfull!!!";
	else {
		cout<<"\n\n\t\t\t!!!INVALID CREDENTIALS!!!";
		getch();
		exit(-1);
	}
	system("cls");
	
		
		ifstream file("Description.txt");
		if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
        printf("%s", line.c_str());
    }
    file.close();
}

cout<<"\n";
	int ch,i,o,ch1,ch2,r,rno,rcount=0,dcount=0;
	Room r2;
	string dname;
	Dish d2;
	Hotel *Rennaisance=Rennaisance->getHotel();
	
	Dish d[8]={
		Dish("Rice",140,"Pulao"),
		Dish("Corn Soup",110,"Soup"),
		Dish("Roast",220,"Main"),
		Dish("Green Tea",100,"Tea"),
		Dish("Salad",180,"Salad"),
		Dish("Custer",170,"Sweet"),
		Dish("Soft Drink",210,"Drink"),
		Dish("Chocolate",120,"Ice Cream")
			};
			
	Customer *c[5];
	Restaurant res;
	for(i=0;i<8;i++)
	{
		res.dish[i]=d[i];
	}
	Rennaisance->restuarant=res;
	
	 Room rm[6] = {
		Room("Deluxe",2,3500,1),
 		Room("AC",1,5500,2),
 		Room("Non AC",2,2500,3),
		Room("AC",2,3500,4),
		Room("Deluxe",2,3500,5),
	 	Room("Deluxe",3,4500,6)
		 };
		 SelectEmployee *e;
	Rennaisance->setHotel(res,rm);
	while(1)
	{
		for(i=0;i<5;i++)
		{
			try{
			
	level2:	cout<<"Enter \n\t\t\t\t1. Room Booking\n\t\t\t\t2. Restaurant\n\t\t\t\t3. Exit\n";
		cin>>ch;
		if(ch==1)
		{
		 Rennaisance->customer[i]=new RoomCustomer;
		 Rennaisance->generateID(Rennaisance->customer[i]);
		 cout<<"\t\t\tEnter Your details\n";
		 Rennaisance->customer[i]->setData();
		level1:	cout<<"Enter \n\t\t\t\t1. To Display Rooms \n\t\t\t\t2. To Book a Room \n\t\t\t\t3. To Vacate Room \n\t\t\t\t4. To Get Invoice  \n\t\t\t\t5. Not Satisfied? \n\t\t\t\t6. Cancel Booking \n\t\t\t\t7. Give Feedback \n\t\t\t\t8. Back\n\n";
			cin>>ch1;
			switch(ch1)
			{
				case 1: Rennaisance->displayAvailble();
				goto level1;
				case 2: 
				if(Rennaisance->customer[i]->status)
				{
				cout<<"\n\n-----------------------------------------------------------------------------------------\n\n";
				throw Exception(1,"\t\t\tSorry! You Cannot Book more than one room!\n");
				cout<<"\n\n-----------------------------------------------------------------\n\n";}
				else
				{
				Rennaisance->customer[i]->status=1;
				Rennaisance->displayAvailble();
				cout<<"\t\t\tEnter Room No\n";
				cin>>rno;
				Rennaisance->bookRoom(rno);
				r2=Rennaisance->getRoom(rno);
				Rennaisance->customer[i]->allocateRoom(r2);
				}
				
				goto level1;
				case 3: 
				if(!Rennaisance->customer[i]->status)
				{
				cout<<"\n\n-----------------------------------------------------------------------------------------\n\n";
				throw Exception(3,"\t\t\tCannot vacate a book unless booked\n");
				cout<<"\n\n-----------------------------------------------------------------\n\n";}
				
				else
				{
				Rennaisance->customer[i]->status=0;
				cout<<"\t\t\tEnter Room No\n";
				cin>>rno;
				Rennaisance->vacateRoom(rno);
				cout<<"\t\t\toom vacated\n";
			
				}
				goto level1;
				case 4: if(!Rennaisance->customer[i]->status)
			{
				cout<<"\n\n------------------------------------------------------------------------------------------\n\n";
				throw Exception(2,"\t\t\tCannot get Invoice Details unless you book a Room\n");
				cout<<"\n\n-----------------------------------------------------------------\n\n";}
				
				else 
				{
				cout<<"\n\n-----------------------------------------------------------------\n\n";
				Rennaisance->customer[i]->printCustomer();
				Rennaisance->customer[i]->viewTotalBill();
					cout<<"\n\n-----------------------------------------------------------------\n\n";
				goto level1;}
				case 5: 
				if(!Rennaisance->customer[i]->status)
				
			{
			cout<<"\n\n--------------------------------------------------------------------------------------------\n\n";
				throw Exception(2,"\t\t\tCannot call Room Service Unless you book a Room\n");
				cout<<"\n\n-----------------------------------------------------------------\n\n";}
				
				else
				{
					e=new SelectEmployee(new RoomService);
					e->performDuty();
				//Rennaisance->employee->performDuty()
			}
					goto level1;
				case 6: 	if(!Rennaisance->customer[i]->status)
			 {
				 	cout<<"\n\n-----------------------------------------------------------------------------------\n\n";
				throw Exception(2,"\t\t\tNo Room Booked\n");
				}
				
				else
				{
					
					Rennaisance->customer[i]->status=0;
					cout<<"\t\t\tEnter Room No\n";
				cin>>rno;
				Rennaisance->vacateRoom(rno);
					cout<<"\t\t\tCancellation Successful!\n";
					
				}
				goto level1;
				case 7: if(!Rennaisance->customer[i]->status)
			 {
				 	cout<<"\n\n-----------------------------------------------------------------------------------\n\n";
				throw Exception(2,"\t\t\tCannot give feedback unless you order a Dish\n");
				}
				else

				Rennaisance->askFeedback();
				goto level1;
				case 8: goto level2;
			}
			
		}
		
		
		else if(ch==2)
		{
	 	Rennaisance->customer[i]=new RestaurantCustomer;
		 Rennaisance->generateID(Rennaisance->customer[i]);
		 cout<<"\t\t\tEnter Your details\n";
		 Rennaisance->customer[i]->setData();
	level3:	cout<<"Enter \n\t\t\t\t1. To display Menu \n\t\t\t\t2. To order a Dish \n\t\t\t\t3. To Get Invoice \n\t\t\t\t4. To Cancel Order\n\t\t\t\t5. Give FeedBack \n\t\t\t\t6. Go back\n\n";
		cin>>ch2;
		switch(ch2)
		{
			case 1:
				Rennaisance->displayMenu();
				goto level3;
			case 2:
				if(Rennaisance->customer[i]->status)
			{
				cout<<"\n\n-----------------------------------------------------------------------------------\n\n";
				throw Exception(4,"\t\t\tYou cannot order more than one dish\n");
				cout<<"\n\n-----------------------------------------------------------------\n\n";}
				else
				{
					o=1;
					Rennaisance->customer[i]->status=1;
			 Rennaisance->displayMenu();
			 e=new SelectEmployee(new Waiter);
			 e->performDuty();
			 cout<<"\t\t\tEnter Dish Name you want to Order(Make sure you enter the exact same name.)\n";
	
		cin>>dname;
			 Rennaisance->takeOrder(dname);
			 
			 d2=Rennaisance->restuarant.getDish(dname);
			
			Rennaisance->customer[i]->allocateDish(d2);
		
			 if(o==0)
			 {
			 cout<<"\n\n-----------------------------------------------------------------------------------------\n\n";
			 throw Exception(6,"\t\t\tNo such Dish Found");
		}
		
			 }
			 	 goto level3;
			 case 3:
			 	if(!Rennaisance->customer[i]->status)
			 {
				 	cout<<"\n\n-----------------------------------------------------------------------------------\n\n";
				throw Exception(2,"\t\t\tCannot get Invoice Details unless you order a Dish\n");
				}
				
				else 
				{
				cout<<"\n\n-----------------------------------------------------------------\n\n";
				Rennaisance->customer[i]->printCustomer();
				Rennaisance->customer[i]->viewTotalBill();
					cout<<"\n\n-----------------------------------------------------------------\n\n";
			}
				goto level3;
				case 4: 	if(!Rennaisance->customer[i]->status)
			 {
				 	cout<<"\n\n-----------------------------------------------------------------------------------\n\n";
				throw Exception(2,"\t\t\tNo Dish Ordered\n");
				}
				else
				{
					Rennaisance->customer[i]->status=0;
					cout<<"\t\t\tCancelation Successful!\n";
					
				}
				
			case 5:	if(!Rennaisance->customer[i]->status)
			 {
				 	cout<<"\n\n-----------------------------------------------------------------------------------\n\n";
				throw Exception(2,"\t\t\tCannot give feedback unless you order a Dish\n");
				}
				else

				Rennaisance->askFeedback();
				goto level1;
				case 6:
				goto level2;
				
				
			 
		}
		}
		else if(ch==3)
		exit(0);
		else
		{
			cout<<"-----------------------------------------------------------------------------------\n\n";
			throw Exception(5,"\t\t\tINVALID INPUT\n");
			
		}
		goto level2;
		}
	
	catch(Exception eh)
	{
		eh.what();
		cout<<"-----------------------------------------------------------------------------------\n\n";
	}
	}	}
return 0;
}	
