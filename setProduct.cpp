#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;
 
int main()
{
	string ID,p,s;
	string n;
	char a;
	
	//open product.txt and write data
	
	fstream write ;
	write.open("product.txt", ios::out);
	
	do
	{
	cout << "ProductID: ";
	cin >> ID;
	
	cout << "Name: ";
    cin >> n;
  
    cout << "Price: ";
    cin >> p;
   
    cout << "In-store: ";
    cin >> s;
    

    
	write << "ProductID: "<< ID<<endl;  
	write << "Name: "<< n<<endl ;
	write << "Price: "<< p<<endl ;
	write << "In-store: "<< s<<endl;
	write <<endl;
	
    cout <<  "Do you want to enter the information of another products? Y/N\n";
	cin >> a;
	cout << endl;
    }
	while (a=='Y'| a=='y');
	write.close();
	
	//read and show the data on file product.txt
	
	fstream read;
	read.open("product.txt", ios::in);
	
	cout << endl;
	
	string line;
	while (!read.eof())
	{
		getline(read, line);
		cout << line<<endl;
	}

	read.close();
 
	return 0;
}
