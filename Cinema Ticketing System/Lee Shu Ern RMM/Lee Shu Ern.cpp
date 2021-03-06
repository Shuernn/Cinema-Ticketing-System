#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>

#define day "Friday" // movie day
#define popcorn 10.00 //Popcorn combo

#define AC0 20.00 //adult class 0
#define AC1 16.00 //adult class 1
#define AC2 18.00 // adult class 2

#define CC0  10.00 //child class 0
#define CC1  6.00 //child class 1
#define CC2  8.00 //child class 2

#define SC0  12.00 //student class 0
#define SC1  8.00 //student class 1
#define SC2  10.00 //student class 2

using namespace std;

void Start_Screen(int &c0, int &c1, int &c2, string &movie, string &date, string &time);
void Input_Class(int &Class, int c0, int c1, int c2);
void Ticket_Selling(int Class, int &numOfAdult, int &numOfChild, int &numOfStudent, int c0, int c1, int c2, int &totalSeatSelected);
void Popcorn(char &RespondAddOn, int &QuantityCombo);

double CalculateForC0(int numOfAdult, int numOfChild, int numOfStudent, double &Adult0, double &Child0, double &Student0);
double CalculateForC1(int numOfAdult, int numOfChild, int numOfStudent, double &Adult1, double &Child1, double &Student1);
double CalculateForC2(int numOfAdult, int numOfChild, int numOfStudent, double &Adult2, double &Child2, double &Student2);
void Calculate_Bill(int c, int numOfAdult, int numOfChild, int numOfStudent, double total, char RespondAddOn, int QuantityCombo);

void Display_TicketC0(int Class, string movie, string date, string time, int numOfAdult, int numOfChild, int numOfStudent, int s0, int &sum0, int c0);
void Display_TicketC1(int Class, string movie, string date, string time, int numOfAdult, int numOfChild, int numOfStudent, int s1, int &sum1, int c1);
void Display_TicketC2(int Class, string movie, string date, string time, int numOfAdult, int numOfChild, int numOfStudent, int s2, int &sum2, int c2);

void Seat_Available(int c0, int c1, int c2);

void Display_Report(string movie, string date, string time);
void ReportForClass(int c0, int c1, int c2);
void ReportForCategory(int SumOfAdult, int SumOfChild, int SumOfStudent, double AmountA0, double AmountA1, double AmountA2, double AmountC0, double AmountC1, double AmountC2, double AmountS0, double AmountS1, double AmountS2);
void RepotForQuantityComboSales(int TotalQuantityCombo);

int main() {

	int c0 = 15, c1 = 15, c2 = 30;
	int s0, s1, s2, sum0 = 0, sum1 = 0, sum2 = 0;// seat
	int totalTicket, totalSeatSelected;
	int SumOfAdult = 0, SumOfChild = 0, SumOfStudent = 0; //sum of seat based on category - adult, child, student
	int Class, numOfAdult, numOfChild, numOfStudent;
	int QuantityCombo, TotalQuantityCombo = 0; //how many popcorn combo customer want to add on, calculate the total sales of popcorn combo
	char RespondNxtCus; // RespondNxtCus = respond
	char RespondAddOn; //Respond whether customer want to add on popcorn combo or not
	char RespondClass; //Respond from customer want to continue or exit when there are not enought seats available
	string  movie, date, time;
	double total;

	//calculate total amount of Adult 
	double AmountA0 = 0, Adult0 = 0;
	double AmountA1 = 0, Adult1 = 0;
	double AmountA2 = 0, Adult2 = 0;

	//calculate total amount of child
	double AmountC0 = 0, Child0 = 0;
	double AmountC1 = 0, Child1 = 0;
	double AmountC2 = 0, Child2 = 0;

	//calculate total amount of student
	double AmountS0 = 0, Student0 = 0;
	double AmountS1 = 0, Student1 = 0;
	double AmountS2 = 0, Student2 = 0;

	Start_Screen(c0, c1, c2, movie, date, time);

	do
	{
		Input_Class(Class, c0, c1, c2);
		Ticket_Selling(Class, numOfAdult, numOfChild, numOfStudent, c0, c1, c2, totalSeatSelected);

		//To ensure that customer will not choose the class that have no more seats available
		//Customer can choose to exit[E] the payment if find out there is not enough seats available
		switch (Class)
		{
		case 0:
			while (totalSeatSelected > c0)
			{
				cout << "Not enough Seat. Only " << c0 << " seat(s) available." << endl;
				cout << "Do you want to continue ? Continue[C] / Exit[E] ";
				cin >> RespondClass;
				RespondClass = toupper(RespondClass);

				if (RespondClass == 'C')
				{
					cout << "Please enter again:" << endl;
					Ticket_Selling(Class, numOfAdult, numOfChild, numOfStudent, c0, c1, c2, totalSeatSelected);
				}
				else if (RespondClass == 'E')
				{
					numOfAdult = 0;
					numOfChild = 0;
					numOfStudent = 0;
					cout << endl;
					cout << "PAYMENT CANCELLED" << endl;
					break;
				}
			}
			break;

		case 1:
			while (totalSeatSelected > c1)
			{
				cout << "Not enough Seat. Only " << c1 << " seat(s) available." << endl;
				cout << "Do you want to continue? Continue[C] / Exit[E] ";
				cin >> RespondClass;
				RespondClass = toupper(RespondClass);

				if (RespondClass == 'C')
				{
					cout << "Please enter again:" << endl;
					Ticket_Selling(Class, numOfAdult, numOfChild, numOfStudent, c0, c1, c2, totalSeatSelected);
				}
				else if (RespondClass == 'E')
				{
					numOfAdult = 0;
					numOfChild = 0;
					numOfStudent = 0;
					cout << endl;
					cout << "PAYMENT CANCELLED" << endl;
					break;
				}
			}
			break;

		case 2:
			while (totalSeatSelected > c2)
			{
				cout << "Not enough Seat. Only " << c2 << " seat(s) available." << endl;
				cout << "Do you want to continue? Continue[C] / Exit[E] ";
				cin >> RespondClass;
				RespondClass = toupper(RespondClass);

				if (RespondClass == 'C')
				{
					cout << "Please enter again:" << endl;
					Ticket_Selling(Class, numOfAdult, numOfChild, numOfStudent, c0, c1, c2, totalSeatSelected);
				}
				else if (RespondClass == 'E')
				{
					numOfAdult = 0;
					numOfChild = 0;
					numOfStudent = 0;
					cout << endl;
					cout << "PAYMENT CANCELLED" << endl;
					break;
				}
			}
		}

		if (numOfAdult == 0 && numOfChild == 0 && numOfStudent == 0)
		{
			RespondAddOn = 'C';
			Popcorn(RespondAddOn, QuantityCombo);
		}
		else
		{
			RespondAddOn = 'Y';
			Popcorn(RespondAddOn, QuantityCombo); //ask user whether want to add on popcorn combo or not
		}

		TotalQuantityCombo += QuantityCombo;

		cout << endl;
		cout << string(60, '-') << endl;
		cout << "Bill Calculation - Class " << Class << endl;
		cout << endl;

		if (Class == 0)
		{
			s0 = 1;
			total = CalculateForC0(numOfAdult, numOfChild, numOfStudent, Adult0, Child0, Student0);
			Calculate_Bill(Class, numOfAdult, numOfChild, numOfStudent, total, RespondAddOn, QuantityCombo);
			cout << string(60, '-') << endl;
			cout << endl;
			Display_TicketC0(Class, movie, date, time, numOfAdult, numOfChild, numOfStudent, s0, sum0, c0);
			s0 = sum0;
			totalTicket = numOfAdult + numOfChild + numOfStudent;
			c0 = c0 - totalTicket;
			AmountA0 = Adult0;
			AmountC0 = Child0;
			AmountS0 = Student0;
		}
		else if (Class == 1)
		{
			s1 = 1;
			total = CalculateForC1(numOfAdult, numOfChild, numOfStudent, Adult1, Child1, Student1);
			Calculate_Bill(Class, numOfAdult, numOfChild, numOfStudent, total, RespondAddOn, QuantityCombo);
			cout << string(60, '-') << endl;
			cout << endl;
			Display_TicketC1(Class, movie, date, time, numOfAdult, numOfChild, numOfStudent, s1, sum1, c1);
			s1 = sum1;
			totalTicket = numOfAdult + numOfChild + numOfStudent;
			c1 = c1 - totalTicket;
			AmountA1 = Adult1;
			AmountC1 = Child1;
			AmountS1 = Student1;
		}
		else if (Class == 2)
		{
			s2 = 1;
			total = CalculateForC2(numOfAdult, numOfChild, numOfStudent, Adult2, Child2, Student2);
			Calculate_Bill(Class, numOfAdult, numOfChild, numOfStudent, total, RespondAddOn, QuantityCombo);
			cout << string(60, '-') << endl;
			cout << endl;
			Display_TicketC2(Class, movie, date, time, numOfAdult, numOfChild, numOfStudent, s2, sum2, c2);
			s2 = sum2;
			totalTicket = numOfAdult + numOfChild + numOfStudent;
			c2 = c2 - totalTicket;
			AmountA2 = Adult2;
			AmountC2 = Child2;
			AmountS2 = Student2;
		}

		//sum of ticket based on category
		SumOfAdult += numOfAdult; //total of adult ticket sold
		SumOfChild += numOfChild; //total of child ticket sold
		SumOfStudent += numOfStudent; //total of student ticket sold

		if (c0 == 0 && c1 == 0 && c2 == 0)
			break;

		do // makesure the customer enter n, N, y, Y
		{
			cout << "Next customer (Y = Yes/ N = No)? ";
			cin >> RespondNxtCus;

		} while (RespondNxtCus != 'Y' && RespondNxtCus != 'y' && RespondNxtCus != 'N' && RespondNxtCus != 'n');

		if (RespondNxtCus == 'N' || RespondNxtCus == 'n')
			break;

		Seat_Available(c0, c1, c2);

	} while (RespondNxtCus != 'N' || RespondNxtCus != 'n');

	cout << endl;

	Display_Report(movie, date, time);
	ReportForClass(c0, c1, c2);
	ReportForCategory(SumOfAdult, SumOfChild, SumOfStudent, AmountA0, AmountA1, AmountA2, AmountC0, AmountC1, AmountC2, AmountS0, AmountS1, AmountS2);
	RepotForQuantityComboSales(TotalQuantityCombo);

	system("pause");
	return 0;

}

//stored value for c0, c1, c2, movie, day, date, time to be display in resit
void Start_Screen(int &c0, int &c1, int &c2, string &movie, string &date, string &time) {

	cout << right << setw(40) << "----------------------------" << endl;
	cout << right << setw(40) << "| TAR Cinemax Ticket System |" << endl;
	cout << right << setw(40) << "----------------------------" << endl;

	cout << "This Friday's movie: ";
	getline(cin, movie);

	cout << "Date(dd-mon-yyyy): ";
	cin >> date;

	cout << "Time: ";
	cin >> time;

	cout << endl;

	cout << "Counter is now open for selling of tickets" << endl;
	cout << endl;
	cout << string(50, '*') << endl;
	cout << right << setw(26) << "Seats Available:" << endl;
	cout << right << setw(8) << "[VIP]" << right << setw(9) << "CLASS 0" << left << setw(4) << " ->" << left << setw(3) << c0 << right << setw(10) << "(Seat No: 001 - 015 )" << endl;
	cout << right << setw(8) << "[Front]" << right << setw(9) << "CLASS 1" << left << setw(4) << " ->" << left << setw(3) << c1 << right << setw(10) << "(Seat No: 101 - 115 )" << endl;
	cout << right << setw(8) << "[Back]" << right << setw(9) << "CLASS 2" << left << setw(4) << " ->" << left << setw(3) << c2 << right << setw(10) << "(Seat No: 201 - 215 )" << endl;
	cout << string(50, '*') << endl;
}

void Input_Class(int &Class, int c0, int c1, int c2) {

	cout << "Class Required (0,1,2)? ";
	cin >> Class;
	while (Class != 0 && Class != 1 && Class != 2)
	{
		cout << "Please enter only 0, 1 or 2. Class Required (0,1,2)? ";
		cin >> Class;
	}


	cout << endl;

}

//select number of seats required 
void Ticket_Selling(int Class, int &numOfAdult, int &numOfChild, int &numOfStudent, int c0, int c1, int c2, int &totalSeatSelected) {

	do
	{
		cout << left << setw(40) << "Number of Adult Seats required" << left << setw(2) << ":";
		cin >> numOfAdult;

		cout << "Number of child seats required" << endl;
		cout << left << setw(40) << "(Must be below 12 years old)" << left << setw(2) << ":";
		cin >> numOfChild;

		cout << "Number of student seats required" << endl;
		cout << left << setw(40) << "(Must show registration card)" << left << setw(2) << ":";
		cin >> numOfStudent;
		cout << endl;
	} while (numOfAdult < 0 || numOfChild < 0 || numOfStudent < 0);

	

	totalSeatSelected = numOfAdult + numOfChild + numOfStudent;


}

double CalculateForC0(int numOfAdult, int numOfChild, int numOfStudent, double &Adult0, double &Child0, double &Student0) {

	double total;
	double TotalAdult0, TotalChild0, TotalStudent0;

	TotalAdult0 = numOfAdult * AC0;
	TotalChild0 = numOfChild * CC0;
	TotalStudent0 = numOfStudent * SC0;

	cout << fixed << setprecision(2);
	cout << left << setw(20) << "Number of Adults" << left << setw(2) << "=" << left << setw(4) << numOfAdult << left << setw(6) << " @ RM " << right << setw(7) << AC0 << left << setw(6) << " = RM " << right << setw(8) << TotalAdult0 << endl;
	cout << left << setw(20) << "Number of Child" << left << setw(2) << "=" << left << setw(4) << numOfChild << left << setw(6) << " @ RM " << right << setw(7) << CC0 << left << setw(6) << " = RM " << right << setw(8) << TotalChild0 << endl;
	cout << left << setw(20) << "Number of Student" << left << setw(2) << "=" << left << setw(4) << numOfStudent << left << setw(6) << " @ RM " << right << setw(7) << SC0 << left << setw(6) << " = RM " << right << setw(8) << TotalStudent0 << endl;
	total = TotalAdult0 + TotalChild0 + TotalStudent0;

	Adult0 += TotalAdult0;
	Child0 += TotalChild0;
	Student0 += TotalStudent0;

	return total;

}

double CalculateForC1(int numOfAdult, int numOfChild, int numOfStudent, double &Adult1, double &Child1, double &Student1) {

	double total;
	double TotalAdult1, TotalChild1, TotalStudent1;

	TotalAdult1 = numOfAdult * AC1;
	TotalChild1 = numOfChild * CC1;
	TotalStudent1 = numOfStudent * SC1;

	cout << fixed << setprecision(2);
	cout << left << setw(20) << "Number of Adults" << left << setw(2) << "=" << left << setw(4) << numOfAdult << left << setw(6) << " @ RM " << right << setw(7) << AC1 << left << setw(6) << " = RM " << right << setw(8) << TotalAdult1 << endl;
	cout << left << setw(20) << "Number of Child" << left << setw(2) << "=" << left << setw(4) << numOfChild << left << setw(6) << " @ RM " << right << setw(7) << CC1 << left << setw(6) << " = RM " << right << setw(8) << TotalChild1 << endl;
	cout << left << setw(20) << "Number of Student" << left << setw(2) << "=" << left << setw(4) << numOfStudent << left << setw(6) << " @ RM " << right << setw(7) << SC1 << left << setw(6) << " = RM " << right << setw(8) << TotalStudent1 << endl;
	total = TotalAdult1 + TotalChild1 + TotalStudent1;

	Adult1 += TotalAdult1;
	Child1 += TotalChild1;
	Student1 += TotalStudent1;

	return total;

}

double CalculateForC2(int numOfAdult, int numOfChild, int numOfStudent, double &Adult2, double &Child2, double &Student2) {

	double total;
	double TotalAdult2, TotalChild2, TotalStudent2;

	TotalAdult2 = numOfAdult * AC2;
	TotalChild2 = numOfChild * CC2;
	TotalStudent2 = numOfStudent * SC2;

	cout << fixed << setprecision(2);
	cout << left << setw(20) << "Number of Adults" << left << setw(2) << "=" << left << setw(4) << numOfAdult << left << setw(6) << " @ RM " << right << setw(7) << AC2 << left << setw(6) << " = RM " << right << setw(8) << TotalAdult2 << endl;
	cout << left << setw(20) << "Number of Child" << left << setw(2) << "=" << left << setw(4) << numOfChild << left << setw(6) << " @ RM " << right << setw(7) << CC2 << left << setw(6) << " = RM " << right << setw(8) << TotalChild2 << endl;
	cout << left << setw(20) << "Number of Student" << left << setw(2) << "=" << left << setw(4) << numOfStudent << left << setw(6) << " @ RM " << right << setw(7) << SC2 << left << setw(6) << " = RM " << right << setw(8) << TotalStudent2 << endl;
	total = numOfAdult * AC2 + numOfChild * CC2 + numOfStudent * SC2;

	Adult2 += TotalAdult2;
	Child2 += TotalChild2;
	Student2 += TotalStudent2;

	return total;

}

void Popcorn(char &RespondAddOn, int &QuantityCombo) {

	if (RespondAddOn == 'C')
		QuantityCombo = 0;
	else
	{
		cout << string(50, '=') << endl;
		cout << "Friday Deal !!!!!!!!!!" << endl;
		cout << "POPCORN COMBO For only RM 10 !!!" << endl;

		cout << "Do you want to add on popcorn combo? Yes[Y]/ No[N] ";
		cin >> RespondAddOn;
		RespondAddOn = toupper(RespondAddOn);

		while (RespondAddOn != 'Y' && RespondAddOn != 'N')
		{
			cout << "Enter Y for Yes or N for No only." << endl;
			cout << "Do you want to add on popcorn combo? Yes[Y]/ No[N] ";
			cin >> RespondAddOn;
			RespondAddOn = toupper(RespondAddOn);
		}


		if (RespondAddOn == 'Y')
		{
			do
			{
				cout << endl;
				cout << "How many popcorn combo want to add on? ";
				cin >> QuantityCombo;
				if (QuantityCombo > 0)
					break;
			} while (QuantityCombo <= 0);
		}
		else
			QuantityCombo = 0;

		cout << string(50, '=') << endl;
	}
}

void Calculate_Bill(int Class, int numOfAdult, int numOfChild, int numOfStudent, double total, char RespondAddOn, int QuantityCombo) {

	char PaymentMethod;
	double payment, change, TotalAmountOfPopcorn, TotalAmount;

	cout << fixed << setprecision(2);

	//Calculate total price for popcorn combo only exist when someone order the  popcorn combo
	if (RespondAddOn == 'Y')
	{
		TotalAmountOfPopcorn = popcorn * QuantityCombo;
		TotalAmount = total + TotalAmountOfPopcorn;

		cout << left << setw(20) << "Popcorn Combo" << left << setw(2) << "=" << left << setw(4) << QuantityCombo << left << setw(6) << " @ RM " << right << setw(7) << popcorn << left << setw(6) << " = RM " << right << setw(8) << TotalAmountOfPopcorn << endl;

	}
	else if (RespondAddOn == 'N')
		TotalAmount = total;
	else if (RespondAddOn == 'C')
		TotalAmount = total;

	cout << right << setw(20) << "TOTAL TO PAY " << left << setw(22) << "=" << left << setw(2) << "RM " << right << setw(8) << TotalAmount << endl;

	if (RespondAddOn != 'C')
	{
		//Select payment method (Cash[C] / Debit card[D])
		cout << "Payment Method-Cash[C]/ Debit Card[D]: ";
		cin >> PaymentMethod;
		PaymentMethod = toupper(PaymentMethod);

		//makesure choose valid payment method
		while(PaymentMethod != 'C' && PaymentMethod != 'D')
		{
			cout << endl;
			cout << "Invalid Payement Method. Please enter again." << endl;
			cout << "Payment Method-Cash[C]/ Debit Card[D]: ";
			cin >> PaymentMethod;
			PaymentMethod = toupper(PaymentMethod);
		}

		//Change the first letter of input of payment method into upper case
		

		cout << right << setw(20) << "PAID " << left << setw(22) << ":" << left << setw(2) << "RM " << right << setw(8);
		cin >> payment;

		//makesure amount paid by customer is more than or equal to the total amount to pay
		while (payment < TotalAmount)
		{
			cout << "Invalid payment amount. Please enter again." << endl;
			cout << right << setw(20) << "PAID " << left << setw(22) << ":" << left << setw(2) << "RM " << right << setw(8);
			cin >> payment;
		}

		if (PaymentMethod == 'C') //cash payment
			cout << right << setw(20) << "CASH PAYMENT " << left << setw(22) << ":" << left << setw(2) << "RM " << right << setw(8) << payment << endl;
		else if (PaymentMethod == 'D') //Debit card
			cout << right << setw(20) << "DEBIT CARD " << left << setw(22) << ":" << left << setw(2) << "RM " << right << setw(8) << payment << endl;

		change = payment - TotalAmount;
		cout << right << setw(20) << "CHANGE DUE " << left << setw(22) << ":" << left << setw(2) << "RM " << right << setw(8) << change << endl;

	}

	cout << endl;

}

void Display_TicketC0(int Class, string movie, string date, string time, int numOfAdult, int numOfChild, int numOfStudent, int s0, int &sum0, int c0) {

	int x, y, z;

	cout << "Here are your ticket: " << endl;

	if (numOfAdult > 0 && numOfAdult <= 15)
	{
		for (x = 1; x <= numOfAdult; x++)
		{
			cout << string(45, '=') << endl;

			cout << left << setw(30) << "TAR Cinemax Ticket";
			cout << "ADULT - " << Class << endl;

			cout << left << setw(10) << "Movie" << left << setw(6) << ":" << movie << endl;
			cout << left << setw(10) << "Date/Time" << left << setw(6) << ":" << day << " " << date << " " << time << endl;
			cout << endl;

			sum0 += s0;
			if (sum0 >= 10)
				cout << left << setw(7) << "Seat No: 0" << sum0;
			else if (sum0 < 10)
				cout << left << setw(7) << "Seat No: 00" << sum0;

			cout << left << setw(9) << " ";
			cout << "Price: RM " << fixed << setprecision(2) << AC0 << endl;

			cout << string(45, '=') << endl;
			cout << endl;
		}
	}

	if (numOfChild > 0 && numOfChild <= 15)
	{
		for (y = 1; y <= numOfChild; y++)
		{
			cout << string(45, '=') << endl;
			cout << left << setw(30) << "TAR Cinemax Ticket";
			cout << "CHILD - " << Class << endl;

			cout << left << setw(10) << "Movie" << left << setw(6) << ":" << movie << endl;
			cout << left << setw(10) << "Date/Time" << left << setw(6) << ":" << day << " " << date << " " << time << endl;
			cout << endl;

			sum0 += s0;
			if (sum0 >= 10)
				cout << left << setw(7) << "Seat No: 0" << sum0;
			else if (sum0 < 10)
				cout << left << setw(7) << "Seat No: 00" << sum0;

			cout << left << setw(9) << " ";
			cout << "Price: RM " << fixed << setprecision(2) << CC0 << endl;

			cout << string(45, '=') << endl;
			cout << endl;
		}
	}

	if (numOfStudent > 0 && numOfStudent <= 15)
	{
		for (z = 1; z <= numOfStudent; z++)
		{
			cout << string(45, '=') << endl;

			cout << left << setw(30) << "TAR Cinemax Ticket";
			cout << "STUDENT - " << Class << endl;

			cout << left << setw(10) << "Movie" << left << setw(6) << ":" << movie << endl;
			cout << left << setw(10) << "Date/Time" << left << setw(6) << ":" << day << " " << date << " " << time << endl;
			cout << endl;

			sum0 += s0;

			if (sum0 >= 10)
				cout << left << setw(7) << "Seat No: 0" << sum0;
			else if (sum0 < 10)
				cout << left << setw(7) << "Seat No: 00" << sum0;

			cout << left << setw(9) << " ";
			cout << "Price: RM " << fixed << setprecision(2) << SC0 << endl;

			cout << string(45, '=') << endl;
			cout << endl;
		}
	}
}

void Display_TicketC1(int Class, string movie, string date, string time, int numOfAdult, int numOfChild, int numOfStudent, int s1, int &sum1, int c1)
{
	int x, y, z; //x-adult, y-child, z-student

	cout << "Here are your ticket: " << endl;

	if (numOfAdult > 0 && numOfAdult <= 15)
	{
		for (x = 1; x <= numOfAdult; x++)
		{
			cout << string(45, '=') << endl;

			cout << left << setw(30) << "TAR Cinemax Ticket";
			cout << "ADULT - " << Class << endl;

			cout << left << setw(10) << "Movie" << left << setw(6) << ":" << movie << endl;
			cout << left << setw(10) << "Date/Time" << left << setw(6) << ":" << day << " " << date << " " << time << endl;
			cout << endl;

			sum1 += s1;

			if (sum1 >= 10)
				cout << left << setw(7) << "Seat No: 1" << sum1;
			else if (sum1 < 10)
				cout << left << setw(7) << "Seat No: 10" << sum1;

			cout << left << setw(9) << " ";
			cout << "Price: RM " << fixed << setprecision(2) << AC1 << endl;

			cout << string(45, '=') << endl;
			cout << endl;
		}
	}


	if (numOfChild > 0 && numOfChild <= 15)
	{
		for (y = 1; y <= numOfChild; y++)
		{
			cout << string(45, '=') << endl;
			cout << left << setw(30) << "TAR Cinemax Ticket";
			cout << "CHILD - " << Class << endl;

			cout << left << setw(10) << "Movie" << left << setw(6) << ":" << movie << endl;
			cout << left << setw(10) << "Date/Time" << left << setw(6) << ":" << day << " " << date << " " << time << endl;
			cout << endl;

			sum1 += s1;

			if (sum1 >= 10)
				cout << left << setw(7) << "Seat No: 1" << sum1;
			else if (sum1 < 10)
				cout << left << setw(7) << "Seat No: 10" << sum1;

			cout << left << setw(9) << " ";
			cout << "Price: RM " << fixed << setprecision(2) << CC1 << endl;

			cout << string(45, '=') << endl;
			cout << endl;
		}
	}

	if (numOfStudent > 0 && numOfStudent <= 15)
	{
		for (z = 1; z <= numOfStudent; z++)
		{
			cout << string(45, '=') << endl;

			cout << left << setw(30) << "TAR Cinemax Ticket";
			cout << "STUDENT - " << Class << endl;

			cout << left << setw(10) << "Movie" << left << setw(6) << ":" << movie << endl;
			cout << left << setw(10) << "Date/Time" << left << setw(6) << ":" << day << " " << date << " " << time << endl;
			cout << endl;

			sum1 += s1;
			if (sum1 >= 10)
				cout << left << setw(7) << "Seat No: 1" << sum1;
			else if (sum1 < 10)
				cout << left << setw(7) << "Seat No: 10" << sum1;

			cout << left << setw(9) << " ";
			cout << "Price: RM " << fixed << setprecision(2) << SC1 << endl;

			cout << string(45, '=') << endl;
			cout << endl;
		}
	}
}

void Display_TicketC2(int Class, string movie, string date, string time, int numOfAdult, int numOfChild, int numOfStudent, int s2, int &sum2, int c2) {
	int x, y, z; //x-adult, y-child, z-student

	cout << "Here are your ticket: " << endl;

	if (numOfAdult > 0 && numOfAdult <= 30)
	{
		for (x = 1; x <= numOfAdult; x++)
		{
			cout << string(45, '=') << endl;

			cout << left << setw(30) << "TAR Cinemax Ticket";
			cout << "ADULT - " << Class << endl;

			cout << left << setw(10) << "Movie" << left << setw(6) << ":" << movie << endl;
			cout << left << setw(10) << "Date/Time" << left << setw(6) << ":" << day << " " << date << " " << time << endl;
			cout << endl;

			sum2 += s2;
			if (sum2 >= 10)
				cout << left << setw(7) << "Seat No: 2" << sum2;
			else if (sum2 < 10)
				cout << left << setw(7) << "Seat No: 20" << sum2;

			cout << left << setw(9) << " ";
			cout << "Price: RM " << fixed << setprecision(2) << AC2 << endl;

			cout << string(45, '=') << endl;
			cout << endl;
		}
	}


	if (numOfChild > 0 && numOfChild <= 30)
	{
		for (y = 1; y <= numOfChild; y++)
		{
			cout << string(45, '=') << endl;
			cout << left << setw(30) << "TAR Cinemax Ticket";
			cout << "CHILD - " << Class << endl;

			cout << left << setw(10) << "Movie" << left << setw(6) << ":" << movie << endl;
			cout << left << setw(10) << "Date/Time" << left << setw(6) << ":" << day << " " << date << " " << time << endl;
			cout << endl;

			sum2 += s2;
			if (sum2 >= 10)
				cout << left << setw(7) << "Seat No: 2" << sum2;
			else if (sum2 < 10)
				cout << left << setw(7) << "Seat No: 20" << sum2;

			cout << left << setw(9) << " ";
			cout << "Price: RM " << fixed << setprecision(2) << CC2 << endl;

			cout << string(45, '=') << endl;
			cout << endl;
		}
	}

	if (numOfStudent > 0 && numOfStudent <= 30)
	{
		for (z = 1; z <= numOfStudent; z++)
		{
			cout << string(45, '=') << endl;

			cout << left << setw(30) << "TAR Cinemax Ticket";
			cout << "STUDENT - " << Class << endl;

			cout << left << setw(10) << "Movie" << left << setw(6) << ":" << movie << endl;
			cout << left << setw(10) << "Date/Time" << left << setw(6) << ":" << day << " " << date << " " << time << endl;
			cout << endl;

			sum2 += s2;
			if (sum2 >= 10)
				cout << left << setw(7) << "Seat No: 2" << sum2;
			else if (sum2 < 10)
				cout << left << setw(7) << "Seat No: 20" << sum2;

			cout << left << setw(9) << " ";
			cout << "Price: RM " << fixed << setprecision(2) << SC2 << endl;

			cout << string(45, '=') << endl;
			cout << endl;
		}
	}
}

void Seat_Available(int c0, int c1, int c2) {

	int totalSeatAvailable, NxtSeatNoC0, NxtSeatNoC1, NxtSeatNoC2;

	totalSeatAvailable = c0 + c1 + c2;
	NxtSeatNoC0 = 15 + 1 - c0;
	NxtSeatNoC1 = 15 + 1 - c1;
	NxtSeatNoC2 = 30 + 1 - c2;

	

	cout << string(50, '*') << endl;
	cout << right << setw(24) << "Seats Available:" << endl;

	//Display seat(s) available for class 0
	cout << right << setw(8) << "[VIP]" << right << setw(9) << "CLASS 0" << left << setw(4) << " ->" << left << setw(3) << c0 << right << setw(10);

	if (NxtSeatNoC0 < 9)
		cout << "(Seat No: 00" << NxtSeatNoC0 << " - " << "015 )" << endl;
	else if (NxtSeatNoC0 >= 9 && NxtSeatNoC0 < 15)
		cout << "(Seat No: 0" << NxtSeatNoC0 << " - " << "015 )" << endl;
	else if (NxtSeatNoC0 == 15)
		cout << "(Seat No: 015)" << endl;
	else
		cout << "No more Seat Available" << endl;

	//Display seat(s) available for class 1
	cout << right << setw(8) << "[Front]" << right << setw(9) << "CLASS 1" << left << setw(4) << " ->" << left << setw(3) << c1 << right << setw(10);

	if (NxtSeatNoC1 < 9)
		cout << "(Seat No: 10" << NxtSeatNoC1 << " - " << "015 )" << endl;
	else if (NxtSeatNoC1 >= 9 && NxtSeatNoC1 < 15)
		cout << "(Seat No: 1" << NxtSeatNoC1 << " - " << "115 )" << endl;
	else if (NxtSeatNoC1 == 15)
		cout << "(Seat No: 115)" << endl;
	else
		cout << "No more Seat Available" << endl;

	//Display seat(s) available for class 2
	cout << right << setw(8) << "[Back]" << right << setw(9) << "CLASS 2" << left << setw(4) << " ->" << left << setw(3) << c2 << right << setw(10);

	if (NxtSeatNoC2 < 9)
		cout << "(Seat No: 20" << NxtSeatNoC2 << " - " << "230 )" << endl;
	else if (NxtSeatNoC2 >= 9 && NxtSeatNoC2 < 30)
		cout << "(Seat No: 2" << NxtSeatNoC2 << " - " << "230 )" << endl;
	else if (NxtSeatNoC2 == 30)
		cout << "(Seat No: 230)" << endl;
	else
		cout << "No more Seat Available" << endl;

	cout << string(50, '*') << endl;

	//Display message to let  customer know that which class has no more seats available
	if (c0 == 0)
		cout << "***No seat available for class 0" << endl;

	if (c1 == 0)
		cout << "***No seat available for class 1" << endl;

	if (c2 == 0)
		cout << "***No seat available for class 2" << endl;

	if (c0 > 0 || c1 > 0 || c2 > 0)
		cout << "Still have " << totalSeatAvailable << " seat(s)" << endl;

	cout << endl;

}

void Display_Report(string movie, string date, string time) {

	cout << string(54, '=') << endl;

	cout << right << setw(32) << "TICKET SALES REPORT" << endl;
	cout << endl;

	cout << left << setw(12) << "Movie Title" << left << setw(8) << ":" << movie << endl;
	cout << left << setw(12) << "Date / Time" << left << setw(8) << ":" << day << " " << date << " " << time << endl;
	cout << endl;

}

void ReportForClass(int c0, int c1, int c2) {

	int QSold0, QSold1, QSold2; // quantity of tickets  sold for each Class

	double PSold0, PSold1, PSold2; //percentage of ticket sold for each Class

	double TotalSold;

	QSold0 = 15 - c0;
	QSold1 = 15 - c1;
	QSold2 = 30 - c2;

	PSold0 = QSold0 / 15.0;
	PSold1 = QSold1 / 15.0;
	PSold2 = QSold2 / 30.0;

	TotalSold = (PSold0 * 100 + PSold1 * 100 + PSold2 * 100) / 300;

	cout << "SEAT OCCUPANCY FOR EACH CLASS: " << endl;
	cout << endl;

	cout << right << setw(23) << "Total Seats" << right << setw(15) << "Quantity Sold" << right << setw(8) << "Sold %" << endl;
	cout << right << setw(10) << "Class 0" << right << setw(8) << "15" << right << setw(14) << QSold0 << right << setw(12) << fixed << setprecision(0) << PSold0 * 100 << endl;
	cout << right << setw(10) << "Class 1" << right << setw(8) << "15" << right << setw(14) << QSold1 << right << setw(12) << fixed << setprecision(0) << PSold1 * 100 << endl;
	cout << right << setw(10) << "Class 2" << right << setw(8) << "30" << right << setw(14) << QSold2 << right << setw(12) << fixed << setprecision(0) << PSold2 * 100 << endl;
	cout << right << setw(20) << string(6, '-') << right << setw(15) << string(6, '-') << right << setw(12) << string(8, '-') << endl;
	cout << right << setw(10) << "OVERALL" << right << setw(8) << "60" << right << setw(14) << QSold0 + QSold1 + QSold2 << right << setw(12) << fixed << setprecision(0) << TotalSold * 100 << endl;
	cout << right << setw(20) << string(6, '-') << right << setw(15) << string(6, '-') << right << setw(12) << string(8, '-') << endl;

	cout << endl;
}

void ReportForCategory(int SumOfAdult, int SumOfChild, int SumOfStudent, double AmountA0, double AmountA1, double AmountA2, double AmountC0, double AmountC1, double AmountC2, double AmountS0, double AmountS1, double AmountS2) {

	double TotalAdult, TotalChild, TotalStudent;

	TotalAdult = AmountA0 + AmountA1 + AmountA2;
	TotalChild = AmountC0 + AmountC1 + AmountC2;
	TotalStudent = AmountS0 + AmountS1 + AmountS2;
	
	cout << "SALES FOR EACH CATEGORY TYPE: " << endl;
	cout << endl;

	cout << right << setw(21) << "Category" << right << setw(12) << "Seats" << right << setw(15) << "Sales (RM)" << endl;
	cout << right << setw(20) << "ADULT" << right << setw(12) << SumOfAdult << right << setw(14) << fixed << setprecision(2) << TotalAdult << endl;
	cout << right << setw(20) << "CHILD" << right << setw(12) << SumOfChild << right << setw(14) << fixed << setprecision(2) << TotalChild << endl;
	cout << right << setw(20) << "STUDENT" << right << setw(12) << SumOfStudent << right << setw(14) << fixed << setprecision(2) << TotalStudent << endl;
	cout << right << setw(33) << string(6, '-') << right << setw(16) << string(10, '-') << endl;
	cout << right << setw(20) << "TOTAL" << right << setw(12) << SumOfAdult + SumOfChild + SumOfStudent << right << setw(14) << fixed << setprecision(2) << TotalAdult + TotalChild + TotalStudent << endl;
	cout << right << setw(33) << string(6, '-') << right << setw(16) << string(10, '-') << endl;

	cout << endl;

}

void RepotForQuantityComboSales(int TotalQuantityCombo) {

	cout << "SALES FOR POPCORN COMBO: " << endl;
	cout << endl;

	cout << right << setw(21) << " " << right << setw(12) << "Quantity" << right << setw(15) << "Sales(RM)" << endl;
	cout << right << setw(20) << "Total Quantity" << right << setw(12) << TotalQuantityCombo << right << setw(14) << fixed << setprecision(2) << TotalQuantityCombo * popcorn << endl;
	
	cout << endl;
	cout << string(54, '=') << endl;  
}