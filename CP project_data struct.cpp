#include<iostream>
using namespace std;

struct all_data{		//data structure
	string sku[20];
	float sell_price[20];	//Arrays declared
	float cost_price[20];
	float weight[20];
	float No_stock[20];
	float tax[20];
};
	
int total = 0;
float tax = 0;

all_data sku;
all_data sp;
all_data cp;
all_data wt;
all_data tx;
all_data nos;

void enter(){		//enter function

	int Total_no_of_data=0;

	cout<<"How many New products do you want to enter? "<<endl;
	cin>>Total_no_of_data;
	
	
if(total==0){
	total=Total_no_of_data+total;
	for(int i=0;i<Total_no_of_data;i++){
		cout<<"\nEnter the Data of that PRODUCT! "<<i+1<<endl<<endl;
		cout<<"Enter SKU: ";
		cin>>sku.sku[i];
		cout<<"Enter Weight: ";
		cin>>wt.weight[i];
		cout<<"Enter Number of stocks available: ";
		cin>>nos.No_stock[i];
		cout<<"Enter Cost Price: ";
		cin>>cp.cost_price[i];
		cout<<"Enter Selling Price: ";
		cin>>sp.sell_price[i];
	}
}

else{
	for(int i=total;i<Total_no_of_data+total;i++){
		
		cout<<"\nEnter the Data of Product: "<<i+1<<endl<<endl;
		cout<<"Enter SKU: ";
		cin>>sku.sku[i];
		cout<<"Enter Weight: ";
		cin>>wt.weight[i];
		cout<<"Enter Number of stocks available: ";
		cin>>nos.No_stock[i];
		cout<<"Enter Cost Price: ";
		cin>>cp.cost_price[i];
		cout<<"Enter Selling Price: ";
		cin>>sp.sell_price[i];
		
		
	}
	total=Total_no_of_data+total;
}
}

void show(){	//show all product function
	
	
	if(total==0){
		cout<<"No data is entered!"<<endl;
	}
	else{
		for(int i=0;i<total;i++){
			
			tax = (cp.cost_price[i])*(0.15);//calculates Tax
			
			cout<<"\n\t Data of Product: "<<i+1<<endl<<endl;
			cout<<"\t SKU: "<<sku.sku[i]<<endl;
			cout<<"\t Weight: "<<wt.weight[i]<<endl;
			cout<<"\t No. of Stocks Available: "<<nos.No_stock[i]<<endl;
			cout<<"\t Cost Price: "<<cp.cost_price[i]<<endl;
			cout<<"\t Tax: "<<tax<<endl;
			
			float final_cp=(cp.cost_price[i]+tax);	 //cost price + tax
			
			cout<<"\t Cost Price after tax: "<<final_cp<<endl;
			cout<<"\t Selling Price: "<<sp.sell_price[i]<<endl;
			
			float profit = sp.sell_price[i]-final_cp; //calculates Profit
			
			cout<<"\t Profit: "<<profit<<endl;
			
			float Total_profit = profit * nos.No_stock[i]; 
			//the above code calculates the whole profit
			cout<<"Total Profit from all the Stocks: "<<Total_profit<<endl;
			
			cout<<"**********************************************"<<endl<<endl;
			
		}
	}
}

void search(){	//search product function

	if(total==0){
		cout<<"No data is entered"<<endl;
	}

	else{
		string sku_no;
		cout<<"Enter the SKU You want to Search: "<<endl; 
		cin>>sku_no;
		
			for(int i=0;i<total;i++){
				
				if(sku_no==sku.sku[i]){
					tax = (cp.cost_price[i])*(0.15);
			
					cout<<"\nData of Product "<<i+1<<endl<<endl;
					cout<<"SKU: "<<sku.sku[i]<<endl;
					cout<<"Weight: "<<wt.weight[i]<<endl;
					cout<<"No. of Stocks Available: "<<nos.No_stock[i]<<endl;
					cout<<"Cost Price: "<<cp.cost_price[i]<<endl;
					cout<<"Tax: "<<tax<<endl;
			
					float final_cp=(cp.cost_price[i]+tax);
			
					cout<<"Cost Price after tax: "<<final_cp<<endl;
					cout<<"Selling Price: "<<sp.sell_price[i]<<endl;
					
					float profit = sp.sell_price[i]-final_cp; //calculates Profit
					
					cout<<"\t Profit: "<<profit<<endl;
			
					float Total_profit = profit * nos.No_stock[i];
					//the above code calculates the whole profit
					cout<<"Total Profit from all the Stocks: "<<Total_profit<<endl;
				}
				else if (sku_no!=sku.sku[i]){
					cout<<"Invalid SKU: "<<endl;
					cout<<"Please enter the SKU You want to Search: "<<endl;
				}
			}
	}

}
void update(){		//updating list function
	if(total==0){
		cout<<"No data is entered"<<endl;
	}
	else{
		string sku_no;
		cout<<" Enter the SKU of product which you want to update"<<endl;
		cin>>sku_no;
		for(int i=0;i<total;i++){
			if(sku_no == sku.sku[i]){
				cout<<"\n\t Previous Product data: "<<endl<<endl;
				cout<<"\t Data of Product "<<i+1<<endl;
				cout<<"\t SKU "<<sku.sku[i]<<endl;
				cout<<"\t Weight "<<wt.weight[i]<<endl;
				cout<<"\t No. of Stocks Available: "<<nos.No_stock[i]<<endl;
				cout<<"\t Cost Price "<<cp.cost_price[i]<<endl;
				cout<<"\t Selling Price "<<sp.sell_price[i]<<endl;
				
				
				cout<<"\n\t Enter new data: "<<endl<<endl;
				cout<<"\t Enter SKU: ";
				cin>>sku.sku[i];
				cout<<"Enter Weight: ";
				cin>>wt.weight[i];
				cout<<"Enter New No. of Stocks: ";
				cin>>nos.No_stock[i];
				cout<<"Enter Cost Price: ";
				cin>>cp.cost_price[i];
				cout<<"Enter Selling Price: ";
				cin>>sp.sell_price[i];
				
				
			}
		}
	}
}


void deleterecord(){	//delete a record or all the products function
	if(total==0){
		cout<<"No data of Product is entered"<<endl;
	}
	else{
		int option;
		cout<<"Press 1 to delete all data of the Products: "<<endl;
		cout<<"Press 2 to delete specific Product: "<<endl;
		cin>>option;
	if(option==1){
		total=0;
		cout<<"All Data is deleted..!!"<<endl;
	}
	else if(option==2){
		string sku_no;
		cout<<"Enter the SKU of product which you wanted to delete"<<endl;
		cin>>sku_no;
			for(int i=0;i<total;i++){
				if(sku_no==sku.sku[i]){
					for(int j=i;j<total;j++){
						sku.sku[j]=sku.sku[j+1];
						wt.weight[j]=wt.weight[j+1];
						nos.No_stock[j]=nos.No_stock[j+1];
						cp.cost_price[j]=cp.cost_price[j+1];
						sp.sell_price[j]=sp.sell_price[j+1];
					}
				total--;
				cout<<"Your required Product is deleted"<<endl;
				}
			}
	}
	else{
		cout<<"Invalid input";
	}

}
}

main(){		//where the main function starts from!
int value;

    for(int i=7;i>=1;i--){		//design pattern
    	int j=i;
    	while(j>=1){
    		cout<<"*"; j--;
		}
		cout<<endl;
	}
	
	cout<<"\t \t         Welcome to My CP project!"<<endl;
    cout<<"\t \t This program allows you to handle your stocks! \n"<<endl;
    cout<<"!***************************************************************************!"<<endl;
    cout<<"!***************************************************************************!"<<endl;
	while(true){
		cout<<"\n \t \t Press 1 to Enter a new Product: "<<endl;
		cout<<"\t \t Press 2 to Show All the Products Entered: "<<endl;
		cout<<"\t \t Press 3 to search a Product: "<<endl;
		cout<<"\t \t Press 4 to update Product List:"<<endl;
		cout<<"\t \t Press 5 to delete a Product: "<<endl;
		cout<<"\t \t Press 6 to exit the Program: \n"<<endl;
		cout<<"!***************************************************************************!"<<endl;
		cout<<"!***************************************************************************!"<<endl;
		cout<<endl<<"Enter Value here: "; cin>>value;

	switch(value){		//functions are used with switches
		case 1:
			enter();
			break;
		case 2:
			show();
			break;
		case 3:
			search();
			break;
		case 4:
			update();
			break;
		case 5:
			deleterecord();
			break;
	 	case 6:
			exit(0);
			break;
		default:

	cout<<"Invalid input"<<endl; break;
		}
	}
return 0;}