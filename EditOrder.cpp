#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	
	
ifstream o;
	o.open("product.txt", ios::in);
	
	string line[20];
	string idp[20]; //id product
	string namep[20];// name product
	
	int ki=0;// dem dong` trong file product
	int p=0;// dem san pham
	
///////// PART A- take id and name from product.txt to compare with ID of order file in orther to show the name of matching ID to owner.
	
	cout<<"Get ID, name from product.txt \n"<<endl; 
	while (!o.eof()) // CHAY tu dau den cuoi file product.txt
	{	
		if(ki%5==0){		// neu dong nao trong file product chia het cho 5 (bat dau tu 0 tro di)
			p++;                    // san pham dau tien
			getline(o, line[ki]);	 //lay chuoi tai vi tri tu 0 bo vo array co ten la line // vd lay duoc tai vi tri 0 trong file la ProductId: abc
			
			idp[p]=line[ki].erase(0,11); // h muon lay abc de bo vo id cua san pham ta phai xoa chu "ProductID: ",ta dung ham "chuoi".erase(vi tri bat dau xoa, vi tri ket thuc xoa)
			cout<<idp[p]<<" "; // in ra product id dd tach dc.
			ki++; // nhay xuong dong tiep trong file product
			
			getline(o, line[ki]);// lay gia tri tiep theo trong file // vd: name: def
			
			namep[p]=line[ki].erase(0,6); // muon xoa chu "name: " xoa tu chu n(vi tri 0) den dau cach" "(vi tri so 6), xoa xong phan con lai bo vo name product
			cout<<namep[p]<<endl; //in cai name product ra
			ki++;// nhay dong tiep
			
	}
	    	
		getline(o, line[ki]); // neu ko phai cai can lay thong tin trong file thi cung bo vo mang line
		
		ki++;// nhay dong tiep
	}
	
	
	cout<<endl;

o.close();
	
	
	
	
	
/////---------------------------------------------------------------------------------	
	
	
//////////////PART B-read and show the data on file order.txt
	
	fstream read;
	read.open("order.txt", ios::in); // MO FILE RA DE DOC
	
	int bb=1;// dem san pham dc order
	
	string sp[20]; // BO SAN PHAM DA ORDER VO DAY
	string  ido[20], //id order
			amo[20], // amount order
			pro[20]; //price order
	
	
	
	
	while (!read.eof()) // chay tu dau den cuoi file order
	{
		
	// tách ID, amount, price trong file order ra	//VD: ab-cd-ee
											
		getline(read, ido[bb],'-'); //lay duoc ab
		getline(read, amo[bb],'-'); //lay dc cd
		getline(read, pro[bb],'\n');// lay dc ee
	
		bb++;// dem luong san pham duoc order
	}


	int np=p-1;//number of product id	
	int no=bb-1;// number of orders
	


/////Raw Order


	cout<<"Raw Order \n"<<endl;
	
		for(int z=1;z<=no;z++)// add ordered product in array sp
	{
		sp[z]=ido[z]+"-"+amo[z]+"-"+pro[z];
		
		cout<<"["<<z<<"] "<<sp[z]<<endl;
		
	}

	cout<<endl;

// chuyen doi id trong order sang ten cua san pham co id do de show ra
	cout<<"After turn ID to name \n"<<endl;
		for(int zz=1;zz<=no;zz++)
		{
			
		
			
			for(int vv=1; vv<=np; vv++){
			if(ido[zz]==idp[vv])
			{
				cout<<"["<<zz<<"] "<<namep[vv]<<" amount "<<amo[zz]<<" price "<<pro[zz]<<endl;
				 // if id order equal to id product --> name of matching id product +amount of order +price of order
			}
				
			}
	
	
		}

	cout<<endl;

	read.close();
		
		
//---------------------------------------------------------------------	

///PART C- nguoi chu co quyen edit cai file order ban dau
	
	fstream write ;
	write.open("orderx.txt", ios::out); // mo file do ra de viet vo
	
	string  a, //id neu them
			b,// amount neu them
			c; // price neu them
			
	char xx,// hoi add them nua hay ko
		xxx,// xoa them nua hay ko
		 ans; // bien dung de hoi delete hay la add hay la add
	
	
//For choose ADD or DELETE
	
	cout<<"add or delete the item from order file| A(add) or D(delete)"<<endl;
	cin>>ans;
	cout << endl;
	
///For Add
	
	if(ans=='A' || ans=='a'){ // neu tra loi "a"--> add 
	
	int kk=no+1; // so luong san pham da duoc order truoc do
	
	do
	{
		// nhap thong tin sp moi muon add
	cout << "ProductID: ";
	cin >>a;
	
	  cout << "Amount: ";
    cin >>b;
  
    cout << "Price: ";
    cin >>c;
   	

	sp[kk]=a+"-"+b+"-"+c+"\n";// luu san pham moi tao duoc vo array sp(san pham)

	kk++;// tang luong san pham len 1
	
	//hoi co them san pham nua khong?
    cout <<  "Do you want to add another products in order file? A(add) or N(no))\n";
	cin >> xx;
	cout << endl;
    }
    
	while (xx=='a'| xx=='A'); // neu ko nhap "a" hoac "A" thi het add.
	
	
	//in ra cai order ban dau va cai nguoi ta vua moi add
	cout<<"you had added"<<endl;
	write<<"After Added"<<endl;
	for(int e=1;e<=kk;e++)
		{
			
		
		write<<sp[e]<<endl;
		cout<<"["<<e<<"] "<<sp[e]<<endl;
		
		}
    

	
	
}// het phan cua ADD.




///For Delete 


	else{ // neu khong chon add thi se nhay vo delete
		
	
		int k=bb;// luong san pham ban dau co trong order
	do{
			cout<< "Select the position of item to be deleted (1 or 2 or 3 or 4... ))"<<endl; //muon xoa cho nao?
		int ss,count;
		
		cin>>ss;
		cout<<endl;
	
	for(int ii=1; ii<k; ii++) //chay het file order
	{
		
		if(ss == ii) //neu cai vi tri nguoi ta nhap de xoa bang voi vi tri chay 
		{
			for(int j=ii; j<(k-1); j++)// gia tri cua vi tri duoc chon se lay gia tri cua vi tri tiep theo lap di lap lai cho den cuoi
			{
				sp[j]=sp[j+1];
			}
			count++; // dem len mot lan
			break;// nhay ra khoi vong lap
		}
	}
	
	
	if(count==0)// neu ko dem duoc cai nao thi tuc la vi tri nhap ko co de ma xoa
	{
		cout<<"Element not found..!!";
		
	}
	else // khong thi in ra cai list order moi sau khi xoa cai vi tri duoc chon di
	{
	
		cout<<"Now the new order is :\n";
		write<<"After delete"<<endl;
		
		for(int ii=1; ii<(k-1); ii++)
		{
			write<<sp[ii]<<endl;// ghi voo trong file order
			cout<<"["<<ii<<"] "<<sp[ii]<<endl;// ghi voo man hinh de in ra
		}
		k--;// giam so luong san pham order di 1 vi da xoa 1 cai roi
	}
	
		
	  cout <<  "Do you want to delete another products in order file? D(delete) or N(no))\n"; // hoi muon xoa tiep ko??
	cin >> xxx;
	cout << endl;
    }
	while ((xxx=='d'|| xxx=='D' ) && k!=1);// khong thi thoi.
		
		
	}
	
	
	
	
	
	write.close();
	

 
	

	
}

		
		
	
	

	
	
	

	
	



