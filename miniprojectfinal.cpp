#include <iostream>
#include <fstream>
using namespace std;
class covidcase
{
  protected:
  int n,count1=0,count2=0,i;
  int p=0;
  int count;
  string symp;
  public:
   void patients();
   void positive();
   void female();
    void male();
    void total();
    void negative();
    virtual void symptoms();
    void display();
};
void covidcase::patients()
{
    ofstream file_obj;
	file_obj.open("patients.txt", ios::app);
	covidcase obj;
    cout<<"Number of people who took covidtest:"<<endl;
    cin>>count;
    obj.count;
    file_obj.write((char*)&obj, sizeof(obj));

}
void covidcase::female()
  { 
       ofstream file_obj;
	file_obj.open("female.txt", ios::app);
	covidcase obj;
    cout <<"The number of female covid positive patients are:"  << endl;
    cin >>count1 ;
    obj.count1;
    file_obj.write((char*)&obj, sizeof(obj));
  }
 void covidcase::male()
  {
      ofstream file_obj;
	file_obj.open("male.txt", ios::app);
	covidcase obj;
    cout<<"The number of male covid positive patients are: "<<endl;
   cin >>count2 ;
   obj.count2;
    file_obj.write((char*)&obj, sizeof(obj));
  }
 void covidcase:: total()
  { 
      ofstream file_obj;
	file_obj.open("total.txt", ios::app);
	covidcase obj;
    n = count1 + count2;
    cout <<"The total number of cases are:"  << n <<endl;
    obj.n;
    file_obj.write((char*)&obj, sizeof(obj));
  }
  void covidcase::positive()
{   
    ofstream file_obj;
	file_obj.open("positive.txt", ios::app);
	covidcase obj;
   p =n;
   if(p>count)
   {
   	cout<<"Analysis is wrong"<<endl;
   	exit(1);
   }
   else
   {
    cout<<"The number of covid positive patients:"<<p<<endl;
}
    obj.p;
    file_obj.write((char*)&obj, sizeof(obj));
}
void covidcase::negative()
  {
      ofstream file_obj;
	file_obj.open("negative.txt", ios::app);
	covidcase obj;
    i = count - n;  
    cout<<"Number of covid negative patients :"<<i<<endl;
    obj.i;
    file_obj.write((char*)&obj, sizeof(obj));
  }
void covidcase::symptoms()//polymorphism
{
     ofstream file_obj;
	file_obj.open("symptoms.txt", ios::app);
	covidcase obj;
      cout<<"Enter the common symptoms that are seen in the patients who have tested positive:"<<endl;
      cin>>symp;
file_obj.write((char*)&obj, sizeof(obj));
}
void covidcase::display()
    {
         ofstream file_obj;
	file_obj.open("display.txt", ios::app);
	covidcase obj;
      cout<<"***************\n"<<endl;
      cout<<"             ASTER HOSPITAL            \n"<<endl;
      cout<<"Covid report analysis is as follows:"<<endl;
      cout<<"Number of people who took covidtest:"<<count<<endl;
      cout<<"Number of covid positive pateints : "<<n<<endl;
      cout<<"Number of covid negative pateints :"<<i<<endl;
      cout<<"The number of female covid pateints are:"<<count1<<endl;
      cout<<"The number of male covid patients are: "<<count2<<endl;
      cout<<"The symptoms which are commonly seen in the patients who tested positive:"<<symp<<endl;
      cout<<"The number of  family members to be quartined:"<<3*n<<endl;
      cout<<"Please get the covid test done and follow the safety measures"<<endl;
      file_obj.write((char*)&obj, sizeof(obj));
    }
class covidpositive:public covidcase//inheritance
{   protected:
    int f;
    public:
    void family()
    {
         ofstream file_obj;
	file_obj.open("family.txt", ios::app);
	covidpositive obj;
        //assuming that number of family members are 3 and one in each family is covid positive
        f =3*n;
        obj.f;
         file_obj.write((char*)&obj, sizeof(obj));
    }
    void show()
    {
        ofstream file_obj;
	file_obj.open("show.txt", ios::app);
	covidpositive obj;
        cout<<"The number of members of the families to be quartined:"<<f<<endl;
        obj.f;
         file_obj.write((char*)&obj, sizeof(obj));
    }
};

int main()
{
    covidcase object;
    object.patients();
    object.female();
    object.male();
    object.total();
    object.positive();
    object.negative();
    object.symptoms();
    object.display();
    covidpositive obj1;
    obj1.family();
    return 0;
  covidcase c1;
  c1.patients();
  c1.female();
  c1.male();
  c1.total();
  c1.positive();
  c1.negative();
  c1.symptoms();
  covidpositive c2;
  c2.family();
  c2.show();
  c1.display();
}