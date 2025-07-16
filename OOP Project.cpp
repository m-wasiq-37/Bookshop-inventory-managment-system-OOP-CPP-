//BookShop Inventory Managment System.
//Group members:
//M.Wasiq   082
//M.Zeeshan 084
//M.Zain    115

#include <iostream>

#include <string>

#include <iomanip>

#include <fstream>

#include <conio.h>

using namespace std;

class Admin {
        private: 
		string psw;
        string admin;

        public: 
		Admin() {
                ifstream Ad;
                Ad.open("Admin.txt");
                for (int j = 1; j <= 2; j++) {
                        switch (j) {
                        case 1:
                                getline(Ad, admin);
                                break;

                        case 2:
                                getline(Ad, psw);
                                break;
                        }
                }
                // Closing The Files.
                Ad.close();
                if(psw==""){
                	psw = "1111";
                	admin = "ADMIN";
				}

        }

        void setpassword(string p) {
                ofstream Ad;
                Ad.open("Admin.txt");
                Ad << left << admin << "\n" << p << endl;
                Ad.close();
        }

        string getpassword() {
        	ifstream Ad;
                Ad.open("Admin.txt");
                for (int j = 1; j <= 2; j++) {
                        switch (j) {
                        case 1:
                                getline(Ad, admin);
                                break;

                        case 2:
                                getline(Ad, psw);
                                break;
                        }
                }
                // Closing The Files.
                Ad.close();
                return psw;
        }

        string getadmin() {
                return admin;
        }
        ~Admin() {
                ofstream Ad;
                Ad.open("Admin.txt");
                Ad << left << admin << "\n" << psw << endl;
                Ad.close();
        }
};

class Books {
        private: string Bookname;
        int Bookquantity;

        public:

                Books() {
                        Bookname = " ";
                        Bookquantity = 0;
                }

        void setBookname(string n) {
                Bookname = n;
        }

        void setBookquantity(int q) {
                Bookquantity = q;
        }

        string getBookname() {
                return Bookname;
        }

        int getBookquantity() {
                return Bookquantity;
        }
}
arr[10];

class Author {
        private: string Authorname;
        float Bookprice;

        public: Author() {
                Authorname = " ";
                Bookprice = 0;
        }

        void setAuthorname(string n) {
                Authorname = n;
        }

        string getAuthorname() {
                return Authorname;
        }

        void setBookprice(float p) {
                Bookprice = p;
        }

        float getBookprice() {
                return Bookprice;
        }
}
arr1[10];

class VClass {

        public: 
		void Update_file() {
                system("cls");

                //Opening Files.

                ofstream Books;
                Books.open("Books.txt");

                ofstream st;
                st.open("Status.txt");

                for (int i = 0; i <= 9; i++) {
                        Books << left << arr[i].getBookname() << "\n" << arr1[i].getAuthorname() << endl;
                        st << arr[i].getBookquantity() << "\n" << arr1[i].getBookprice() << endl;
                }

                //Closing Files.

                Books.close();

                st.close();

                system("cls");
        }
        virtual void Buy_Book() {}
        virtual void User_Window() {}
        virtual void Add_Newbookfile() {}
        virtual void New_Book() {}
        virtual void Admin_Menu() {}
        virtual void Main_Menu() {}
        virtual void Open_File() {}
        virtual void Edit_File() {}
};

class Functions: public VClass {
        private: Admin admin;
        float price = 0;
        string name, Aname;
        int quantity = 0;

        public:

        void Open_File() override {
                        // Opening The Files.
                        ifstream st;
                        st.open("Status.txt");

                        ifstream Book;
                        Book.open("Books.txt");

                        double digit = 0;
                        //Saving Data From File

                        for (int i = 0; i <= 9; i++) {
                                for (int j = 1; j <= 2; j++) {
                                        getline(Book, name);
                                        st >> digit;
                                        switch (j) {
                                        case 1:
                                                arr[i].setBookname(name);
                                                arr[i].setBookquantity(digit);
                                                break;

                                        case 2:
                                                arr1[i].setAuthorname(name);
                                                arr1[i].setBookprice(digit);
                                                break;
                                        }
                                }
                        }
                        // Closing The Files.
                        Book.close();
                        st.close();
                        Main_Menu();
                }
        //Main menu for the Program
        void Main_Menu() override {
                int b = 0;
                for (char choice = '0'; choice != '3';) {
                        cout << " \t\t\t1. For Admin \t\t\t2. For Buyer\t\t\t3. For Exit" << endl;
                        cout << setw(120) << setfill('_') << "\t" << endl;
                        cout << "Enter Your Choice:";
                        cin >> choice;
                        system("cls");
                        switch (choice) {
                        case '1':
                                for (int i = 1; i <= 3; i++) {
                                        string password = "";
										cout << endl << "Enter a 4 Digit Code:";
										    char ch;
										    while ((ch = _getch()) != '\r') {
										        if (ch == '\b') {
										            if (!password.empty()) {
										                cout << "\b \b";
										                password.pop_back();
										            }
										        } 
												else {
										            cout << "*";
										            password += ch;
										        }
										    }
										    if (password == admin.getpassword()) {
										        system("cls");
										        cout << endl << "\t\t\t\t\t\t:- Welcome " << admin.getadmin() << " -:" << endl << endl << endl << endl;
										        Admin_Menu();
										        break;
										    } 
											else {
										        cout << endl << "\tAccess Denied" << endl;
										    }
                                }
                                break;
                        case '2':
                                User_Window();
                                break;
                        case '3':
                                //Exiting the Program Here.
                                Update_file();
                                cout << "\n\n\n\n";
                                cout << "\t\t\t\t\t\t---------------\n";
                                cout << "\t\t\t\t\t\t:- Thank You -:\n";
                                cout << "\t\t\t\t\t\t---------------\n";
                                cout << "\n\n\n\n";
                                exit(0);
                                break;
                        default:
                                cout << "\t---------" << endl;
                                cout << "\tTry Again" << endl;
                                cout << "\t---------" << endl;
                        }
                }
        }

        //This Is Admin Menu.
        void Admin_Menu() override {
                int v, a = 0;
                string b;
                for (char x = '0'; x != '5';) {
                        cout << setw(120) << setfill('_') << "\t" << endl;
                        cout << " 1. To Enter New Book  " << endl;
                        cout << " 2. To Check Stocks  " << endl;
                        cout << " 3. To Change Password  " << endl;
                        cout << " 4. To Update Data " << endl;
                        cout << " 5. To Logout " << endl;
                        cout << setw(120) << setfill('_') << "\t" << endl;
                        cout << "Enter Your Choice:";
                        cin >> x;
                        system("cls");
                        cout << setw(120) << setfill('_') << "\t" << endl;

                        switch (x) {
                        case '1':
                                New_Book();
                                break;

                        case '2':
                                //Displaying the Books here.
                                cout << setw(120) << setfill('_') << "\t" << endl;

                                for (int i = 0; i <= 9; i++) {
                                        if (arr[i].getBookquantity() != 0) {
                                                cout << endl;
                                                cout << "Book Name: '" << arr[i].getBookname() << "' " << endl << "Author Name: '" << arr1[i].getAuthorname() << "' " << endl << "In Stock:" << arr[i].getBookquantity() << endl;
                                        }

                                        a = arr[i].getBookquantity() + a;
                                }

                                cout << endl;
                                cout << "There Are Total " << a << " Books In Stock." << endl;
                                cout << setw(120) << setfill('_') << "\t" << endl;
                                system("pause");
                                system("cls");
                                break;

                        case '3':
                                //Updating passcode here.
                                for (int i = 1; i <= 3; i++) {
                                	system("cls");
                                        cout << endl << "Enter Previous 4 Digit Code:";
                                        cin >> b;
		                                        if (b == admin.getpassword()) {
		                                        	for(int j = 0 ; j<=2 ; j++) {
		                                        		system("cls");
		                                                cout << endl << "Enter a New 4 Digit Code:";
		                                                cin >> b;
		                                                if(b!=admin.getpassword()) {
				                                                admin.setpassword(b);
				                                                cout << "Password Changed Successfully " << endl;
				                                                break;
		                                            	}
		                                            	else {
		                                    				cout<<"\n Password Cannot Be Same\n\n\tTry again\n\n";
		                                    				system("pause");
														}
													}
		                                        break;
												} 
												else {
		                                                cout << endl << endl << "    :- Access Denied-:" << endl;
		                                        }
		                                    }
                                break;

                        case '4':
                                //Editing the books Here.
                                        cout << endl << "Enter the name of Book You Want To edit: ";
                                        cin.ignore();
                                        getline(cin, name);
                                        for (int i = 0; i <= 9; i++) {
                                                if (arr[i].getBookquantity() != 0) {
                                                        if (arr[i].getBookname() == name) {
                                                                name = arr[i].getBookname();
                                                                Aname = arr1[i].getAuthorname();
                                                                quantity = arr[i].getBookquantity();
                                                                price = arr1[i].getBookprice();
                                                                cout << endl;
                                                                cout << "Book Name: '" << arr[i].getBookname() << "' " << endl << "Author Name: '" << arr1[i].getAuthorname() << "' " << endl << "In Stock:" << arr[i].getBookquantity() << endl << "Price:" << arr1[i].getBookprice() << endl;
                                                                cout << " Enter New Total Stock: ";
                                                                cin >> quantity;
                                                                arr[i].setBookquantity(quantity);
                                                                cout << " Enter New Price: ";
                                                                cin >> price;
                                                                arr1[i].setBookprice(price);
                                                                system("cls");
                                                                cout << "\n\n :- Data Updated Successfully -: \n\n\n";
                                                                system("pause");
                                                                break;
                                                        } 
                                                }
                                                else if(i==9) {
                                                        cout << "\n :- Name Not Found -: \n\n   :- Try Again -: \n\n";
                                                        system("pause");
                                                }
                                        }
                                system("cls");
                                break;

                        case '5':
                                cout << endl;
                                break;

                        default:
                                cout << endl << "\tTry Again" << endl;

                        }
                }
        }
        //Adding new Books in the program.
        void New_Book() override {
                int a = 0;

                //Opening Books.
                ofstream Books;
                Books.open("Books.txt", ios::app);

                ofstream st;
                st.open("Status.txt", ios::app);

                for (int i = 0; i <= 9; i++) {
                        if (arr[i].getBookquantity() == 0) {
                                cout << endl;

                                cout << "Enter The Name of Book: ";
                                cin.ignore();
                                getline(cin, name);
                                arr[i].setBookname(name);

                                cout << "Enter The Name of Author: ";
                                getline(cin, Aname);
                                arr1[i].setAuthorname(Aname);

                                cout << "Enter The Number of Copies: ";
                                cin >> quantity;
                                arr[i].setBookquantity(quantity);

                                cout << "Enter The Price Per Book: ";
                                cin >> price;
                                arr1[i].setBookprice(price);

                                cout << endl;
                                cout << endl << "Press 1 To Continue" << endl;
                                cout << "Enter Your Choice:";
                                cin >> a;
                                system("cls");
                                if (a >= 2) {
                                        cout << endl;
                                        break;
                                }
                        }

                }
                //Closing Files.
                Books.close();
                st.close();
                Add_Newbookfile();
        }
        //Adding neew books on the file.
        void Add_Newbookfile() override {
                //Oppening file
                ofstream Books;
                Books.open("Books.txt");

                ofstream st;
                st.open("Status.txt");

                for (int i = 0; i <= 9; i++) {
                        Books << left << arr[i].getBookname() << "\n" << arr1[i].getAuthorname() << endl;
                        st << arr[i].getBookquantity() << "\n" << arr1[i].getBookprice() << endl;
                }

                //Closing Files.
                Books.close();
                st.close();
        }

        //Displaying Avaliable books here.
        void User_Window() override {
                cout << setw(120) << setfill('*') << "\t" << endl;
                cout << "Avaliable Books: " << endl;

                for (int i = 0; i <= 9; i++) {
                        if (arr[i].getBookquantity() != 0) {
                                cout << endl << "-------------------------------------" << endl;
                                cout << "   Book Name:" << arr[i].getBookname() << endl << "     Author:" << arr1[i].getAuthorname() << endl << "   " << arr[i].getBookquantity() << " Copies Are Avaliable " << endl << "   Cost per Book:" << arr1[i].getBookprice() << " Rs" << endl;
                                cout << endl << "-------------------------------------" << endl;

                        }
                }

                cout << endl << setw(120) << setfill('*') << "\t" << endl;

                Buy_Book();
        }
		//User Buys the Books Here
        void Buy_Book() override {

                double price = 0;
                char p = '1';
                int e = 1;
                for (char y = '1'; y != 'y' || y != 'Y';) {
                        cout << endl;

                        cout << "Enter The Name Of Book:";
                        name.clear();
                        cin.ignore();

                        getline(cin, name);
                        Aname.clear();

                        cout << "Enter Author Name:";

                        getline(cin, Aname);

                        for (int i = 0; i <= 9; i++) {
                                if (name == arr[i].getBookname() && Aname == arr1[i].getAuthorname()) {
                                        cout << "Enter The Number Of Copies You Want To Buy:";

                                        cin >> quantity;

                                        if (quantity <= arr[i].getBookquantity()) {
                                                e = 0;
                                                price = arr1[i].getBookprice() * quantity;
                                                cout << endl;
                                                system("cls");
                                                cout << "\t You Have Selected <" << quantity << "> Copies of The Book <" << arr[i].getBookname() << "> Written By <" << arr1[i].getAuthorname() << ">" << endl;
                                                cout << "\t\t\t The Total Will Be " << fixed << setprecision(3) << price << " Rs" << endl;
                                                cout << "\t\t\t Press Y/N To Confirm Payment: ";
                                                cin >> y;
                                                if (y == 'y' || y == 'Y') {
                                                        arr[i].setBookquantity(arr[i].getBookquantity() - quantity);
                                                        system("cls");
                                                        cout << "\n\n\n\n";
                                                        cout << "\t\t\t\t\t---------------------------------\n";
                                                        cout << "\t\t\t\t\t:- Thank You For Your Purchase -:\n";
                                                        cout << "\t\t\t\t\t---------------------------------\n";
                                                        cout << "\n\n\n\n";
                                                        system("pause");
                                                        system("cls");
                                                        break;
                                                } 
												else {
                                                        system("cls");
                                                        cout << "\n\n\n\n";
                                                        cout << "\t\t\t\t\t---------------------\n";
                                                        cout << "\t\t\t\t\t:- Order Cancelled -:\n";
                                                        cout << "\t\t\t\t\t---------------------\n";
                                                        cout << "\n\n\n\n";
                                                        system("pause");
                                                        system("cls");
                                                        break;
                                                }
                                        } 
										else {
                                                e = 0;
                                                cout << endl;
                                                cout << "Sorry Only " << arr[i].getBookquantity() << " Copies Are Avaliable." << endl;
                                                cout << "\tTry Again" << endl;
                                                break;
                                        }
                                } else {
                                        e = 1;
                                }
                        }
                        //					*Exception Handeling*
                        try {
                                if (e == 1) {
                                        throw e;
                                }
                        } catch (int ppp) {
                                cout << "This Book is Not Avaliable." << endl;
                        }

                        cout << "\n\nDo you Want To Exit Y/N: ";
                        cin >> p;
                        system("cls");
                        if (p == 'Y' || p == 'y') {
                                break;
                                system("cls");
                        }
                }
                Update_file();
        }

};

int main() {
        cout << "\n\nGroup members:\n\t\tM.Wasiq   082\n\t\tM.Zeeshan 084\n\t\tM.Zain    115\n\n\n\n\n\n";
        system("pause");
        system("cls");
        cout << "\t\t\t\t\t----------------------------------------\n";
        cout << "\t\t\t\t\t:- BookShop Inventory Manament System -:\n";
        cout << "\t\t\t\t\t----------------------------------------\n";
        //Type casting Here.
        VClass * V;
        Functions function;
        V = & function;
        V -> Open_File();
        return 1;
}