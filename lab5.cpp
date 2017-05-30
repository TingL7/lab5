#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class HugeInt{
	friend ostream &operator << (ostream&, HugeInt&);
	friend istream &operator >> (istream &, HugeInt &);
public:
	HugeInt(){}
	HugeInt(double x){
		d = x;
	}
	HugeInt(const string &x){
		stringstream stream;
		stream << x;
		stream >> d;
	}
	double getd(){return d;}
	HugeInt operator + (HugeInt x){return d+x.getd();}
	HugeInt operator - (HugeInt x){return d-x.getd();}
	HugeInt operator = (HugeInt x){
		d = x.getd();
		return d;
	}
																					
private:
	double d;
};

ostream &operator << (ostream &out, HugeInt &x){
	out << x.getd();
	return out;
}

istream &operator >> (istream &in, HugeInt &x){
	in >> x.d;
	return in;
}


int main()
{
	HugeInt x;
	HugeInt y(28825252);
	HugeInt z("314159265358979323846");
	HugeInt result;
	cin >> x;
	result = x+y;
	cout << x << "+" << y << " = " << result << endl;
	result = z - x;
	cout << result << endl;
	return 0;
}

