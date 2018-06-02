#include <iostream>
#include <string>
using namespace std;
//===================================================================
// Definition
//
class Time 
{
  private:
    double s;  // total time in seconds
  public:
    Time(int hours, int min, double sec);
    Time(double hours);
    int getHours();
    int getMinutes();
    double getSeconds(); 

    void setTime(int hours, int min, double sec);
	void setTime(Time &t);
    void setTime(double hours);	
	
  
    Time& operator++()
    {
        ++s;
        return *this;
    }

    Time operator++(int)
    {
        Time tmp(*this);// copy
        operator++();   // pre-increment
        return tmp;     // return old value
    }
    friend Time operator+(double sec, Time rhs);	
	friend Time operator*(double n, Time rhs);
	friend Time operator*(Time lhs, double n);
    friend Time operator+(Time lhs, Time rhs);   // add two times
    friend Time operator+(Time lhs, double sec);    // add int seconds to time
    friend bool operator<(Time lhs, Time rhs);   // relational operators
    friend bool operator>(Time lhs, Time rhs);
    friend bool operator<=(Time lhs, Time rhs);
    friend bool operator>=(Time lhs, Time rhs);
    friend bool operator==(Time lhs, Time rhs);
    friend bool operator!=(Time lhs, Time rhs);
    friend ostream & operator << (ostream &out, const Time &c);
    friend istream & operator >> (istream &in,  Time &c);
};
Time::Time(int hours, int min, double sec)
{
	
	this->s = (hours*3600)+(min*60)+sec;

}

Time::Time(double hours){
    this->s = hours * 60 * 60;
}
void Time::setTime(int hours, int min, double sec)
{
  this->s = (hours*3600)+(min*60)+sec;
}

void Time::setTime(Time &t){
    this->s = t.s;
}

void Time::setTime(double hours){
    this->s = hours * 60 * 60;
}
int Time::getHours()
{
	int hrs = this->s/3600;
	if(hrs>=24)
	{
		hrs=hrs%24;
	}
	return hrs;
}



int Time::getMinutes()
{
    int hrs = this->s/3600;
	int min = ((this->s)-(hrs*3600))/60;
    return min;
}


double Time::getSeconds()
{
    int hrs = this->s/3600;
    int min = ((this->s)-(hrs*3600))/60;
	double sec = (this->s)-(hrs*3600)-(min*60);
    return sec;
}


Time operator+(Time lhs, Time rhs)   // add two times
{
	int t1_secs = lhs.s;
	int t2_secs = rhs.s;

	int final_secs = t1_secs+t2_secs;
	if(final_secs>=86400)
		final_secs = final_secs - 86400;
	int hours = final_secs/3600;
	int mins = ((final_secs)-(hours*3600))/60;
 	double secs = (final_secs)-(hours*3600)-(mins*60);
	Time t3(hours,mins,secs);
  return t3;
}

Time operator+(Time lhs, double sec)   // add two times
{
	double t1_secs = lhs.s;
	

	double final_secs = t1_secs+sec;
	if(final_secs>=86400)
		final_secs = final_secs - 86400;

	int hours = final_secs/3600;
	int mins = ((final_secs)-(hours*3600))/60;
  	double secs = (final_secs)-(hours*3600)-(mins*60);
	Time t3(hours,mins,secs);
  return t3;
}

Time operator*(Time lhs, double n){
    double final_seconds = lhs.s * n;
	if(final_seconds>=86400)
	{
		int val = final_seconds/86400;
		val = val*86400;
		final_seconds = final_seconds-val;
	}
    Time temp(0,0,0);
    temp.s = final_seconds;
    return temp;
}


Time operator*(double n, Time rhs){
    double final_seconds = rhs.s * n;
	if(final_seconds>=86400)
	{
		int val = final_seconds/86400;
		val = val*86400;
		final_seconds = final_seconds-val;
	}
    Time temp(0,0,0);
    temp.s = final_seconds;
    return temp;
}

Time operator+(double sec,Time rhs)   // add two times
{
	double t1_secs = rhs.s;
	

	double final_secs = t1_secs+sec;
	if(final_secs>=86400)
		final_secs = final_secs - 86400;

	int hours = final_secs/3600;
	int mins = ((final_secs)-(hours*3600))/60;
  	double secs = (final_secs)-(hours*3600)-(mins*60);
	Time t3(hours,mins,secs);
  return t3;
}

bool operator<(Time lhs, Time rhs)
{
  double t1_secs = lhs.s;
  double t2_secs = rhs.s;
  if(t1_secs<t2_secs)
  {
      return true;
  }
  return false;
}

bool operator>(Time lhs, Time rhs)
{
  double t1_secs = lhs.s;
  double t2_secs = rhs.s;
  if(t1_secs>t2_secs)
  {
      return true;
  }
  return false;
}

bool operator<=(Time lhs, Time rhs)
{
  double t1_secs = lhs.s;
  double t2_secs = rhs.s;
  if(t1_secs<=t2_secs)
  {
      return true;
  }
  return false;
}

bool operator>=(Time lhs, Time rhs)
{
  double t1_secs = lhs.s;
  double t2_secs = rhs.s;
  if(t1_secs>=t2_secs)
  {
      return true;
  }
  return false;
}

bool operator==(Time lhs, Time rhs)
{
  double t1_secs = lhs.s;
  double t2_secs = rhs.s;
  if(t1_secs==t2_secs)
  {
      return true;
  }
  return false;
}

bool operator!=(Time lhs, Time rhs)
{
  double t1_secs = lhs.s;
  double t2_secs = rhs.s;
  if(t1_secs!=t2_secs)
  {
      return true;
  }
  return false;
}




ostream & operator << (ostream &out, const Time &t)
{
    int hrs = t.s/3600;
    int min = ((t.s)-(hrs*3600))/60;
	double sec = (t.s)-(hrs*3600)-(min*60);
    out <<hrs;
    out << ":" << min;
	out <<":"<<sec<<endl;
    return out;
}
istream & operator >> (istream &in,  Time &t)
{
    cout << "Enter hours in 24 hours format ";
	int hours=0,minutes=0;
	double seconds = 0;	
    in>>hours;
    cout << "Enter minutes "<<endl;
    in >> minutes;
	cout<<"Enter seconds"<<endl;
	in>>seconds;
	if(hours>=24)
	{
		cout<<"Wrong time entered by you! seting user defined time T2 to 0:0:0"<<endl;
	}
	else if(minutes>=60)
	{
		cout<<"Wrong time entered by you! seting user defined time T2 to 0:0:0"<<endl;
	}
	else if(seconds>=60)
	{
		cout<<"Wrong time entered by you! seting user defined time T2 to 0:0:0"<<endl;
	}
	else
	{
		t.setTime(hours,minutes,seconds);
	}
    return in;
}
int main()
{
	
	Time t1 (23,59,33);
	Time T2(0,0,0);
	cout<<"Enter Second Time T2"<<endl;
	cin>>T2;
	cout<<T2<<endl;
	Time T_double(12.4);
	cout<<"Time T1 hardcoded with constructor Time(int hours,int mins,double secs)="<<t1<<endl;
	cout<<"Time T2 set by user ="<<T2<<endl;
	cout<<"Time T_double hardcoded with contructor Time(double hours) ="<<T_double<<endl;
	cout<<"T1++ : "<<t1++<<endl;
	cout<<"T1 in new line ... since post increment operator : "<<t1<<endl;
	cout<<"++T1 : "<<++t1<<endl;
	cout<<"So now the Hardcoded Time is set to: "<<t1<<endl;	
	cout<<"T1+T2 = "<<t1+T2<<endl;
    cout << "add Time with double t1 + 1.2 : " << t1 + 1.2 << endl;
    cout << "add double with Time 2.1 + t1 : " << 2.1 + t1 << endl;	
    cout << "add Time with int t1 + 10 : " << t1 + 10 << endl;
    cout << "add int with Time 12 + t1 : " << 12 + t1 << endl;
    cout << "multiply Time with double t1 * 1.5 : " << t1 * 1.5 << endl;
    cout << "multiply double with Time 4.3 * t1 : " << 4.3 * t1 << endl;
    cout << "Comparision of Hardcoded time with user defined time: " << endl;
    cout << "T2 < T1 : " << ((T2 < t1) ? "True" : "False") << endl;
    cout << "T2 <= T1 : " << ((T2 <= t1) ? "True" : "False") << endl;
    cout << "T2 > T1 : " << ((T2 > t1) ? "True" : "False") << endl;
    cout << "T2 >= T1 : " << ((T2 >= t1) ? "True" : "False") << endl;
    cout << "T2 == T1 : " << ((T2 == t1) ? "True" : "False") << endl;
    cout << "T2 != T1 : " << ((T2 != t1) ? "True" : "False") << endl;
    cout << "set time using double hours : 14.3 : " << endl;
    T_double.setTime(14.3);
    cout << "T_double = " << T_double << endl;
    cout << "set time using time : T2.setTime(T_double) : " << endl;
    T2.setTime(T_double);
    cout << "T2 = " << T2 << endl;
	return 0;
}









