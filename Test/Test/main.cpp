//#include <iostream>
//
//using namespace std;
//
////class Base
////{
////public:
////	virtual void fun()
////	{
////		cout << "Base" << endl;
////	}
////};
////
////class Child1 :public Base
////{
////public:
////	void fun()
////	{
////		cout << "Child1" << endl;
////	}
////};
////
////class Child2 :public Base
////{
////public:
////	void fun()
////	{
////		cout << "Child2" << endl;
////	}
////};
////
////int main()
////{
////	Base* ptr;
////	Child1 ch1;
////	Child2 ch2;
////	ptr = &ch1;
////	ptr->fun();
////	ptr = &ch2;
////	ptr->fun();
////	return 0;
////}
//
//
////class Base
////{
////public:
////	Base()
////	{
////		cout << "Base" << endl;
////	}
////};
////
////class Child1:virtual public Base
////{
////public:
////	Child1()
////	{
////		cout << "Child1" << endl;
////	}
////};
////
////class Child2 :virtual public Base
////{
////public:
////	Child2()
////	{
////		cout << "Child2" << endl;
////	}
////};
////
////class Child3 :public Base
////{
////public:
////	Child3()
////	{
////		cout << "Child3" << endl;
////	}
////};
////
////class grChild :public Child1, public Child2, public Child3
////{
////public:
////	grChild()
////	{
////		cout << "grChild" << endl;
////	}
////};
////
////int main()
////{
////	grChild g;
////	return 0;
////}
//
////class Sample
////{
////	int n;
////public:
////	Sample(int i = 0)
////	{
////		n = i;
////	}
////
////	Sample& operator=(Sample &s)
////	{
////		Sample::n = s.n++;
////		return *this;
////	}
////
////	void display()
////	{
////		cout << n << endl;
////	}
////};
////
////int main()
////{
////	Sample s1(10), s2;
////	s2 = s1;
////	s1.display();
////	s2.display();
////	return 0;
////}
//
////class ins
////{
////public:
////	void play() const
////	{
////		cout << "ins::play" << endl;
////	}
////};
////
////class wind :public ins
////{
////public:
////	void play() const
////	{
////		cout << "wind::play" << endl;
////	}
////};
////
////void tune(ins& i)
////{
////	i.play();
////}
////
////int main()
////{
////	wind flu;
////	tune(flu);
////	return 0;
////}
//
//#include <random>
//
//class A
//{
//public:
//	A()
//	{
//		cout << "A" << endl;
//	}
//};
//
//int main()
//{
//	default_random_engine e;
//	random_device r;
//	e.seed(r());
//	uniform_real_distribution<double> u(-10, 10);
//	cout << u(e) << endl;
//	A a[2], b[3];
//	return 0;
//}

#include <iostream>
#include <cmath>
using namespace std;

class Rational {
public:
	Rational(int num = 1, int denomi = 1) { //���캯������Ĭ�ϲ���
		numerator = num;
		denominator = denomi;
		normalize();
	}
	Rational operator + (Rational& s); //���ؼӷ�����
	Rational operator - (Rational& s); //���ؼ�������
	Rational operator * (Rational& s); //���س˷�����
	Rational operator / (Rational& s); //���س�������


	bool operator == (Rational& s);//����"=="�����
	bool operator != (Rational& s);

	friend istream& operator >>(istream&, Rational&);
	friend ostream& operator <<(ostream&, Rational&); //������������

	double transformToDuoble(Rational& s);

	int gcd(int a, int b) {
		return b ? gcd(b, a % b) : a;
	}
	void normalize(); //��������Ϊ���ʽ����
private:
	int numerator; //����
	int denominator; //��ĸ
};


void Rational::normalize() {
	if (denominator < 0) { //��֤��ĸ����0
		numerator *= -1;
		denominator *= -1;
	}
	int a = abs(numerator);
	int b = abs(denominator);
	int gcd_ab = gcd(a, b); //����ӡ���ĸ�����Լ��

	//���ӡ���ĸ�ֱ�������Լ�����õ����ʽ
	numerator /= gcd_ab;
	denominator /= gcd_ab;
}

Rational Rational:: operator + (Rational& s) {
	Rational t;
	t.numerator = numerator * s.denominator + denominator * s.numerator;
	t.denominator = denominator * s.denominator;
	return Rational(t.numerator, t.denominator);
}

Rational Rational::operator - (Rational& s) {
	Rational t;
	t.numerator = numerator * s.denominator - denominator * s.numerator;
	t.denominator = denominator * s.denominator;
	return Rational(t.numerator, t.denominator);
}

Rational Rational::operator * (Rational& s) {
	Rational t;
	t.numerator = numerator * s.numerator;
	t.denominator = denominator * s.denominator;
	return Rational(t.numerator, t.denominator);
}

Rational Rational::operator / (Rational& s) {
	Rational t;
	t.numerator = numerator * s.denominator;
	t.denominator = denominator * s.numerator;
	return Rational(t.numerator, t.denominator);
}
bool Rational::operator == (Rational& s) {
	if (numerator * s.denominator - denominator * s.numerator == 0)
		return true;
	else
		return false;
}
bool Rational::operator != (Rational& s) {
	if (numerator * s.denominator - denominator * s.numerator != 0)
		return true;
	else
		return false;
}

double Rational::transformToDuoble(Rational& s)
{
	return 1.0 * s.numerator / s.denominator;
}

istream& operator >> (istream& in, Rational& obj) {
	cout << "������ӣ�";
	in >> obj.numerator;
	cout << "�����ĸ��";
	in >> obj.denominator;
	return in;
}
ostream& operator << (ostream& out, Rational& obj) {
	if (obj.numerator == 0)
		out << obj.numerator;
	if (obj.denominator == 1)
		out << obj.numerator;
	else
		out << obj.numerator << '/' << obj.denominator;
	return out;
}

int main() {
	Rational r1, r2;
	cout << "����r1��" << endl;
	cin >> r1;
	cout << "r1 = " << r1 << endl;
	cout << "����r2��" << endl;
	cin >> r2;
	cout << "r2 = " << r2 << endl;

	//�����������������
	Rational r3 = r1 + r2;
	Rational r4 = r1 - r2;
	Rational r5 = r1 * r2;
	Rational r6 = r1 / r2;
	cout << "r1 + r2 = " << r3 << endl;
	cout << "r1 - r2 = " << r4 << endl;
	cout << "r1 * r2 = " << r5 << endl;
	cout << "r1 / r2 = " << r6 << endl;

	cout << r3.transformToDuoble(r3) << endl;
	cout << r4.transformToDuoble(r4) << endl;
	cout << r5.transformToDuoble(r5) << endl;
	cout << r6.transformToDuoble(r6) << endl;
	//���ԱȽ������

	if (r1 == r2) cout << "r1����r2" << endl;
	if (r1 != r2)cout << "r1������r2" << endl;

	cout << "OK" <<endl;
	return 0;
}

