#include <iostream>
#include <fstream>

using namespace std;

class CProduct 
{
private:
	//наименование (до 20 символа), 
	char name[21];
	//идентификационен код(до 10 десетични цифри),
	long id;
	//тегло в килограми(с дробна част),
	float kg;
	//три габаритни размера в сантиметри(цели).
	unsigned int w, h, d;
public:
	CProduct(
		char name[], 
		long id,
		float kg,
		unsigned w,
		unsigned d,
		unsigned h);
	CProduct(const CProduct & other);
	CProduct & operator=(const CProduct & other);
	~CProduct();

	//set
	//get

	//публични функции за извеждане на текстовото им представяне в изходен поток
	std::ostream & inserter(std::ostream & out) const;

	//и за въвеждането им от входен поток
	std::istream & extractor(std::istream & in);
};

std::ostream & operator<<(std::ostream & out, const CProduct & obj);
std::istream & operator>>(std::istream & in, CProduct & obj);

CProduct::CProduct(
	char name[] = (char*)"", 
	long id = 0, 
	float kg = 0,
	unsigned w = 0, 
	unsigned h = 0,
	unsigned d = 0) :
	id(id), kg(kg), w(w), h(h), d(d) 
{
	if (name != NULL)
	{
		strcpy_s(this->name, strlen(name) + 1, name);
	}
}

CProduct::CProduct(const CProduct& other) :
	id(other.id), kg(other.id), w(other.w), h(other.h), d(other.d) 
{
	if (other.name != NULL)
	{
		strcpy_s(name, strlen(other.name) + 1, other.name);
	}
}

CProduct & CProduct::operator=(const CProduct & other)
{
	if (this != &other) 
	{
		if (other.name != NULL)
		{
			strcpy_s(name, strlen(other.name) + 1, other.name);
		}

		id = other.id;
		kg = other.kg;
		w = other.w;
		h = other.h;
		d = other.d;
	}
	return *this;
}

CProduct::~CProduct() {}

//set
//get

//публични функции за извеждане на текстовото им представяне в изходен поток
std::ostream & CProduct::inserter(std::ostream & out) const 
{
	return out 
		<< "name: " << name << std::endl 
		<< "id: " << id << std::endl
		<< "kg: " << kg << std::endl
		<< "w: " << w << std::endl
		<< "h: " << h << std::endl
		<< "d: " << d;
}

//и за въвеждането им от входен поток
std::istream & CProduct::extractor(std::istream & in) 
{
	in.getline(name, 20);
	in >> id >> kg >> w >> h >> d;
	in.ignore();
	return in;
}

std::ostream & operator<<(std::ostream & out, const CProduct & obj) 
{
	return obj.inserter(out);
}

std::istream & operator>>(std::istream & in, CProduct & obj) 
{
	return obj.extractor(in);
}

class MyException : public exception
{
public:
	const char * what() const
	{
		return "my custom exception ";
	}
};

int main()
{
	/*CProduct test;
	cin >> test;

	fstream out("test.txt");
	out << test;
	out.close();

	fstream in("test.txt");
	in >> test;
	cout << "from file: " << endl << test;
	in.close();

	CProduct test2;

	ofstream fout("test.bin", ios::binary);
	fout.write(reinterpret_cast<char *>(&test2), sizeof(CProduct));
	fout.close();

	ifstream fin("test.bin", ios::binary);
	fin.read(reinterpret_cast<char *>(&test), sizeof(CProduct));
	fin.close();

	cout << endl << "from bin: " << endl << test << endl;*/

	try
	{
		throw MyException();
	}
	catch (const MyException & e)
	{
		cout << e.what() << endl << typeid(e).name() << endl;
	}

	return 0;
}