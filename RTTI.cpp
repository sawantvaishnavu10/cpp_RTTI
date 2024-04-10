#include<iostream>
#include<typeinfo>
using namespace std;
 namespace fruitbasket{
 
class fruit{
	protected: 
	string colur,name;
	int price;
	public:
		fruit()
		{
			colur="yellow";
			name="fruit";
			price=200;
		}
		fruit(string colur,string name,int price)
		{
			this->colur=colur;
			this->name=name;
			this->price=price;
		}
		virtual void taste()=0;
virtual	 void display(){
			cout<<"NAME "<<name<<"Colour"<<colur<<"Price "<<price;
		}
		
};
class mango:public fruit{
	
	public:
		
		mango(string colur,string name,int price):fruit(colur,name,price){
			
		}
		void pulp(){
			cout<<"\n  mango pulp";
		}
		
		void taste(){
			cout<<"\n  sweet and sour";
		}
		void display(){
			pulp();
			taste();
			cout<<"NAME "<<name<<"Colour"<<colur<<"Price "<<price;
		}
		

};

class apple:public fruit{
	
	public:
		
		apple(string colur,string name,int price):fruit(colur,name,price){
			
		}
		void jam(){
			cout<<"\n apple jaaam";
		}
		
		void taste(){
			cout<<"\n  sweet ";
		}
		
		void display(){
			jam();
			taste();
			cout<<"NAME "<<name<<"Colour"<<colur<<"Price "<<price;
		}

};
class dragon:public fruit{
	
	public:
		
		dragon(string colur,string name,int price):fruit(colur,name,price){
			
		}
		void d1(){
			cout<<"\n cut and eat";
		}
		
		void taste(){
			cout<<"\n  tasteless ";
		}
		 void display(){
			d1();
			taste();
			cout<<"NAME "<<name<<"Colour"<<colur<<"Price "<<price;
		}

};}

int main()
{  
fruitbasket:: fruit *shop[5];
typedef fruitbasket::mango mango;
typedef fruitbasket::apple apple;
typedef fruitbasket::dragon dragon;
int op,i=0,price,c;
string name,colur;

    
do{cout<<"\n  1.add mango\n 2.apple\n 3.dragon\n 4.show basket \n 5.exit \n";
    cin>>op;
	
	switch(op){
		case 1:{
				cout<<"\n entre the name colur price for mango";
			cin>>name>>colur>>price;
			//mango *m=new mango(name,colur,price);

		//	mango m(name,colur,price);
            shop[i]=new	mango (name,colur,price);
           // m.taste();
            // shop[i] =new mango(name,colur,price);
            // cout<<"Mango added";
			if(typeid(*shop[i])==typeid(mango)){
				mango* obj=dynamic_cast<mango*>(shop[i]);
							obj->pulp();

			} 
			i++;
			break;
		}
		
			
		case 2:{cout<<"\n entre the name colur price for mango";
			cin>>name>>colur>>price;
		//	apple a(name,colur,price);
            shop[i]=new	apple (name,colur,price);
           // a.taste();
			if(typeid(*shop[i])==typeid(apple)){
				apple* obj=dynamic_cast<apple*>(shop[i]);
							obj->jam();
			} 
			i++;
			break;
		}
		case 3:{cout<<"\n entre the name colur price for mango";
			cin>>name>>colur>>price;
		
            shop[i]=new dragon (name,colur,price);
         
			if(typeid(*shop[i])==typeid(dragon)){
				dragon* obj=dynamic_cast<dragon*>(shop[i]);
							obj->d1();
			} 
			i++;
			break;
		}
			
			
		case 4:
			
						c=i;
						cout<<"val of c:"<<c;
				for(int j=0;j<c;j++)
				{
					//cout<<shop[j]->display();
					if(typeid(*shop[j])==typeid(mango))
					{
						
					mango* obj=dynamic_cast<mango*>(shop[j]);
					obj->display();
					}
				else if	(typeid(*shop[j])==typeid(apple))
					{
				apple* obj=dynamic_cast<apple*>(shop[i]);
				obj->display();
 					}
 				else 
 				{	dragon* obj=dynamic_cast<dragon*>(shop[i]);
					obj->display();
 				
				 }
					
				}
			break;
       	case 5:{
	cout<<"exit";
	}
}
}while(op!=5) ;   
    

cout<<"";
}
