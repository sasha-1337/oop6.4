#include <iostream>
#include <math.h>
#include <string>

using namespace std;

template <class T> // T - ���
class vector
{
	T* v; // �������� �����
	int size; // ������� ��������
public:
	vector(int newsize); // ����������� �����������
	vector(vector&); // ����������� ���������
	~vector(); // ����������

	T& operator [] (int index); // ������������
	vector& operator = (const vector&); // ���������
	friend ostream& operator << <>(ostream&, vector&); // ���������
	friend istream& operator >> <>(istream&, vector&); // ��������

	// ������ ������ ������
	int scalar(vector<T>& x, vector<T>& y); // ��������� �������
	friend vector<T> operator + <>(vector<T>& x, int y);
};

template <class T>
vector<T>::vector(int newsize) // ����������� �����������
{
	v = new T[size = newsize]; // ����� �����, �������� ���'�� ��� ��������
	for (int i = 0; i < size; i++) // ��������� �������� ������� ���������
		v[i] = T();
}
template <class T>
vector<T>::vector(vector<T>& x) // ����������� ���������
{
	v = new T[size = x.size]; // ����� �����, �������� ���'�� ��� ��������
	for (int i = 0; i < size; i++) // ��������� ������� ���������
		v[i] = x.v[i];
}
template <class T>
vector<T>::~vector()
{
	delete[] v; // ��������� ���'��
}

template <class T>
T& vector<T>::operator [] (int index)
{
	if (index < 0 || index >= size)
	{
		throw exception("Index out of the range");
	}
	return v[index];
}

template <class T>
vector<T>& vector<T>::operator = (const vector<T>& x)
{
	if (this != &x)
	{
		delete[] v;
		v = new T[size = x.size];
		for (int i = 0; i < size; i++)
			v[i] = x.v[i];
	}
	return *this;
}

template <class T>
ostream& operator << (ostream& os, vector<T>& x)
{
	for (int i = 0; i < x.size; i++)
		os << x.v[i] << ' ';
	os << endl << endl;
	return os;
}

template <class T>
istream& operator >> (istream& is, vector<T>& x)
{
	cout << "Input " << x.size << " elements of vector" << endl;
	for (int i = 0; i < x.size; i++) {
		cout << "element[" << i << "] = ? ";
		is >> x.v[i];
	}
	cout << endl;
	return is;
}

template <class T>
int vector<T>::scalar(vector<T>& x, vector<T>& y) // ��������� ������� 
{
	int X=0, Y=0, Z=0, res=0;
	for (int i = 0; i < x.size; i++)
	{
		X = x.v[i] * y.v[i];
		res = res + X;
	}
	return res;
}

template <class T>
vector<T> operator + (vector<T>& x, int y) // ��������� ����� � �������
{
	vector<T> z(x.size);
	for (int i = 0; i < x.size; i++)
		z.v[i] = x.v[i] + y;
	return z;
}

int main()
{
	try
	{
		vector <int> A(3), B(3), C(3), RES(3);
		cout << "--- Vector A ---" << endl; 
		cin >> A;
		cout << "--- Vector B ---" << endl;
		cin >> B;
		cout << "scalar product (A * B) = " << C.scalar(A, B) << endl << endl;
		cout << "--- Vector C ---" << endl;
		cin >> C;
		int n;
		cout << "Input number to add to the vector C: "; cin >> n;
		RES = C + n;
		cout << "Vector C + " << n << ": " << RES << endl;
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
	}

	system("pause");
	return 0;
}