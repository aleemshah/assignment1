#include <iostream>
using namespace std;

class StringBuffer {

	//private:
public:
	char* _strbuf;                                   //buffer to store the original string.
	int _length;                                       //length of the string.
	bool is_Owner;


public:
	StringBuffer();  //default constructor.
	StringBuffer(char*, int);   //constructor to convert a char* to StringBuffer.
	char charAt(int) const;   //returns the character at the passed index.
	int length() const;                            //returns the length of the buffer.
	void reserve(int);                             //allocates memory for the string, according to the passed character length.
	void append(char);                          //appends a single character at the end.


	StringBuffer& operator=(StringBuffer&n_String)
	{
		delete[] this->_strbuf;
		this->_length = n_String._length;
		this->_strbuf = n_String._strbuf;
		this->is_Owner = 1;
		return *this;
	}

	StringBuffer(const StringBuffer&n_String){
		delete[] this->_strbuf;
		this->_length = n_String._length;
		this->_strbuf = n_String._strbuf;
		this->is_Owner = 1;
	}
	//destructor; would delete the allocated buffer.
	StringBuffer::~StringBuffer() {
		if (this->is_Owner){
			delete[] this->_strbuf;
		}
		else{
			cout << "Invalid pointer used.";

		}

	}
};

StringBuffer::StringBuffer() {
	_strbuf = new char();
	_length = 0;
	is_Owner = 0;
}
//allocates memory for the string, according to the passed character length.
void StringBuffer::reserve(int length) {
	char* temp_String = new char[length];

	delete[] _strbuf;
	_strbuf = new char[length];
	_length = length;
	for (int i = 0; i < _length; i++)
	{
		_strbuf[i] = temp_String[i];
	}
	delete[] temp_String;

}
//appends a single character at the end.
void StringBuffer::append(char newChar) {

	char* temp_String = new char[_length + 1];
	for (int i = 0; i < _length; i++)
	{
		temp_String[i] = _strbuf[i];
	}
	temp_String[_length] = newChar;
	delete[] _strbuf;
	_strbuf = new char[_length + 1];
	_length++;
	for (int i = 0; i < _length; i++)
	{
		_strbuf[i] = temp_String[i];
	}
	delete[] temp_String;

}
//returns the character at the passed index.
char StringBuffer::charAt(int index) const {
	if (_length == 0 || index >= _length || index < 0) {
		std::cout << "Trying to access invalid index." << std::endl;
		return ' ';
	}
	else
		return _strbuf[index];

}
//constructor to convert a char* to StringBuffer.
StringBuffer::StringBuffer(char* w_String, int length) {
	this->_strbuf = w_String;
	this->_length = length;
}
//returns the length of the buffer.
int StringBuffer::length() const {
	return _length;
}

int main() {

	StringBuffer *s = new StringBuffer();
	s->append('1');
	s->append('2');
	s->append('3');
   
	cout << s->charAt(0);
    cout<<"\n";
	cout << s->charAt(1);
    cout<<"\n";
	cout << s->charAt(2);
cout<<"\n";

	std::cout << s->_length << std::endl;
cout<<"\n";
	StringBuffer *x = new StringBuffer(*s);
    
    
	cout << x->charAt(0);
    cout<<"\n";
	cout << x->charAt(1);
    cout<<"\n";
    cout << x->charAt(2);
	delete x;

	return 0;
}
