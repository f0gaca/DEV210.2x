// Mod4Samples.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>// For std::stringstream


class point
{
public:
	int x, y;

	point() {}
	point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	// Plus other members, as appropriate.
};

// overload << and >>
std::istream & operator >> (std::istream & is, point & p)
{
	is >> p.x >> p.y;
	return is;
}

std::ostream & operator << (std::ostream & os, const point & p)
{
	os << "[" << p.x << "," << p.y << "]";
	return os;
}

void openCloseFilesExplicitly()
{
	// Declare file stream objects (files aren't opened yet).
	std::ofstream ofile;
	std::ifstream ifile;
	std::fstream  iofile;

	// Open the files.
	ofile.open("file1.dat");    // Opens file1.dat for writing.
	ifile.open("file2.dat");    // Opens file2.dat for reading.
	iofile.open("file3.dat");   // Opens file3.dat for reading/writing.

	// Use the files...

	// Close the files.
	ofile.close();
	ifile.close();
	iofile.close();
}

void openCloseFilesImplicitly()
{
	// Declare file stream objects (files opened implicitly by constructors).
	std::ofstream ofile("file1.dat");
	std::ifstream ifile("file2.dat");
	std::fstream  iofile("file3.dat");

	// Use the files...

}   // Files closed implicitly by destructors.

// FILE OPEN MODES
//-std::ios_base::in
//- Specifies the file will be opened for input operations.This is the default mode for std::ifstream objects.
//- std::ios_base::out
//- Specifies the file will be opened for output operations.This is the default mode for std::ofstream objects.
//- std::ios_base::binary
// Specifies the file will be opened in binary mode, i.e.no formatting will be applied to values when they are
// read or written.For example, the double value 3.14 will be written as an 8 - byte double value.The default is
// text mode, whereby values will be formatted as text when they are read or written.For example, the double
// value 3.14 will be written as the four characters '3', '.', '1', and '4'.
//- std::ios_base::ate
//- Specifies the initial position for read / write operations is at the end of the file.The default initial
// position for read / write operations is at the start of the file.
//- std::ios_base::app
//- Specifies that all output operations will occur at the end of the file, thereby preserving the existing
// content in the file.
//- std::ios_base::trunc
// If you open an existing file for output operations, this flag causes the existing content to be deleted and
// replaced with the new content that you write in your application.

class tempStat
{
public:
	// Data members.
	double minimum, maximum;

	// Constructor.
	tempStat(double min = 0.0, double max = 0.0)
		: minimum(min), maximum(max)
	{}

	// Helper method, to write a tempStat object to a file in binary format.
	void write(std::ostream & os)
	{
		os.write((char*)&minimum, sizeof(double));
		os.write((char*)&maximum, sizeof(double));
	}

	// Helper method, to read a tempStat object from a file in binary format.
	void read(std::istream & is)
	{
		is.read((char*)&minimum, sizeof(double));
		is.read((char*)&maximum, sizeof(double));
	}

	// Plus other members, as appropriate.
};

std::istream& operator >> (std::istream& is, tempStat & ts)
{
	is >> ts.minimum >> ts.maximum;
	return is;
}

std::ostream& operator << (std::ostream & os, const tempStat & ts)
{
	os << ts.minimum << "," << ts.maximum << std::endl;
	return os;
}

int main()
{
	//double unitPrice;
	//int quantity;

	//std::cout << "What is the unit price? ";
	//std::cin >> unitPrice;

	//std::cout << "How many do you want? ";
	//std::cin >> quantity;

	//std::cout << "Total cost is " << unitPrice * quantity << std::endl;

	//// only captures the first word of a line
	//std::string s;
	//std::cout << "Enter a line of text: ";
	//std::cin >> s;
	//std::cout << "Your string is " << s << std::endl;

	//// get entire line
	//std::string name;
	//std::cout << "Full name: ";
	//std::getline(std::cin, name);

	//std::string address;
	//std::cout << "Full address: ";
	//std::getline(std::cin, address);

	//std::cout
	//	<< name << std::endl
	//	<< address << std::endl;

	//// overloading << ad >>
	//point p1(3, 5);
	//std::cout << "Enter x and y integers separated by a space: ";
	//std::cin >> p1;    // Compiler error, no operator >> function for point if not overloaded.
	//std::cout << p1 << std::endl;   // Compiler error, no operator << function for point if not overloaded.

	//// iomanip manipulators
	//int x = 9;
	//std::cout << "Here is a debug message, the value of x is " << x << std::endl << std::flush;

	//std::cout << std::setw(10) << -123.45 << std::endl;
	//const char * message = "wibble";
	//std::cout << "[" << std::setw(10) << message << "]" << std::endl;
	//std::cout << std::left << std::setw(10) << "hello" << "world" << std::endl;
	//std::cout << std::right << std::setw(10) << "hello" << "world" << std::endl;
	//std::cout << std::internal << std::setw(10) << -123.45 << std::endl;

	//double pi = 3.14159265358979;
	//std::cout << pi << std::endl;
	//std::cout << std::fixed << pi << std::endl;
	//std::cout << std::scientific << pi << std::endl;
	//std::cout << pi << std::endl; // still scientific
	//std::cout.unsetf(std::ios::fixed | std::ios::scientific); // reset to general
	//std::cout << pi << std::endl;

	//int y = 5;
	//int z = -9;
	//std::cout << std::showpos;
	//std::cout << x << " " << y << " " << z << std::endl;
	//std::cout << std::noshowpos;
	//std::cout << x << " " << y << " " << z << std::endl;

	//std::cout << std::showbase;
	//std::cout << 64 << std::endl;
	//std::cout << std::oct << 64 << std::endl;
	//std::cout << std::hex << 64 << std::endl;
	//std::cout << std::noshowbase;

	//std::cout << std::hex;
	//std::cout << 123456789 << std::endl;
	//std::cout << std::uppercase << 123456789 << std::endl;
	//std::cout << std::nouppercase << 123456789 << std::endl;

	//// FILE STREAMS
	//// Default file mode applies here, i.e. std::ios_base::in | std::ios_base::out.  
	//std::fstream iofile1("iofile1.dat");

	//// File mode is just std::ios_base::binary.  
	//std::fstream iofile2("iofile2.dat", std::ios_base::binary);

	//// File mode is just std::ios_base::binary | std::ios_base::in | std::ios_base::out.  
	//std::fstream iofile3("iofile3.dat", std::ios_base::binary | std::ios_base::in | std::ios_base::out);

	//// After you've opened a file, you can call the is_open() method to determine if the file has been opened
	//// successfully. Here's a simple example :
	//std::fstream somefile("file1.dat");
	//if (somefile.is_open())
	//{
	//	// File opened OK, so use it…

	//	// Close the file when we're done.
	//	somefile.close();
	//}
	//else
	//{
	//	std::cerr << "Couldn't open file" << std::endl;
	//}

	//std::ofstream ofile("file1.txt");
	//if (ofile.is_open())
	//{
	//	ofile << "Here is line 1." << std::endl;
	//	ofile << "Here is line 2." << std::endl;
	//	ofile << "Here is line 3." << std::endl;
	//	ofile.close();

	//	std::cout << "Finished writing text to file1.txt." << std::endl;
	//}
	//else
	//{
	//	std::cerr << "Couldn't open file1.txt for writing." << std::endl;
	//}

	//std::ifstream ifile("file1.txt");
	//if (ifile.is_open())
	//{
	//	std::string line;
	//	while (std::getline(ifile, line))
	//	{
	//		std::cout << line << std::endl;
	//	}

	//	ifile.close();

	//	std::cout << "Finished reading text from file1.txt." << std::endl;
	//}
	//else
	//{
	//	std::cerr << "Couldn't open file1.txt for reading." << std::endl;
	//}

	//// FORMATTED TEXT DATA
	//std::ofstream outfile("peopleFile.txt");
	//if (outfile.is_open())
	//{
	//	outfile << "John" << " " << 42 << " " << 1.67 << std::endl;
	//	outfile << "Jane" << " " << 41 << " " << 1.54 << std::endl;
	//	outfile << "Bill" << " " << 35 << " " << 1.82;

	//	outfile.close();

	//	std::cout << "Finished writing text to peopleFile.txt." << std::endl;
	//}
	//else
	//{
	//	std::cerr << "Couldn't open peopleFile.txt for writing." << std::endl;
	//}

	//// BINARY DATA
	//std::ofstream obfile("tempStats.bin", std::ios_base::binary);
	//if (obfile.is_open())
	//{
	//	tempStat(-2.5, 7.5).write(obfile);
	//	tempStat(0, 9.9).write(obfile);
	//	tempStat(2.5, 11.0).write(obfile);
	//	tempStat(5.5, 14.5).write(obfile);
	//	tempStat(7.0, 17.7).write(obfile);
	//	tempStat(10.5, 23.7).write(obfile);
	//	tempStat(11.7, 29.5).write(obfile);
	//	tempStat(7.6, 22.9).write(obfile);
	//	tempStat(7.2, 21.5).write(obfile);
	//	tempStat(2.0, 16.0).write(obfile);
	//	tempStat(-4.7, 12.5).write(obfile);
	//	tempStat(-1.9, 8.5).write(obfile);

	//	obfile.close();

	//	std::cout << "Finished writing binary data to tempStats.bin." << std::endl;
	//}
	//else
	//{
	//	std::cerr << "Couldn't open tempStats.bin for writing." << std::endl;
	//}

	//std::ifstream ibfile("tempStats.bin", std::ios_base::binary);
	//if (ibfile.is_open())
	//{
	//	while (!ibfile.eof())
	//	{
	//		tempStat ts;
	//		ts.read(ibfile);

	//		if (ibfile.gcount() == 0)
	//		{
	//			break;  // If no bytes read, we're done.
	//		}

	//		std::cout << "Read temperature stats: " << ts << std::endl;
	//	}
	//	ibfile.close();

	//	std::cout << "Finished reading binary data from tempStats.bin." << std::endl;
	//}
	//else
	//{
	//	std::cerr << "Couldn't open tempStats.bin for reading." << std::endl;
	//}

	// STREAM POSITION
	// -istream and ifstream objects keep track of the current "get" position.You can obtain the current get
	// position by calling the tellg() method, and you can modify the current get position by calling the seekg() method.
	// - ostream and ofstream objects keep track of the current "put" position.You can obtain the current put
	// position by calling the tellp() method, and you can modify the current put position by calling the seekp() method.
	// - iostream and fstream objects keep track of both the current "get" and "put" positions.You can obtain
	// the current get and put positions by calling the tellg() and tellp() methods, and you can modify the
	// current get and put positions by calling the seekg() and seekp() methods.

	//The tellg() and tellp() methods return a std::streampos value :

	//std::streampos tellg();
	//std::streampos tellp();

	//The seekg() and seekp() methods are overloaded.The first version of these methods takes a std::streampos
	//parameter, specifying the seek position from the start of the stream :

	//std::istream& seekg(std::streampos pos);
	//std::ostream& seekp(std::streampos pos);

	//The second version of the seekg() and seekp() methods takes two parameters :

	//-An std::streamoff parameter, specifying a relative offset.
	//- An std::ios_base::seekdir parameter, specifying the offset direction(allowable values are
	//std::ios_base::beg, std::ios_base::cur, and std::ios_base::end) :

	//std::istream& seekg(std::streamoff off, std::ios_base::seekdir way);
	//std::ostream& seekp(std::streamoff off, std::ios_base::seekdir way);

	// Create a stringstream object.
	std::stringstream stream;

	// Set the string content for a stringstream.
	stream.str("Jane 42 15000");

	// Get the content from a stringstream.
	std::cout << "Content of string stream: " << stream.str() << std::endl;

	// We can still use the stringstream as stream of formatted data.
	std::string name;
	int age;
	double salary;
	stream >> name >> age >> salary;

	std::cout
		<< "Name: " << name << std::endl
		<< "Age: " << age << std::endl
		<< "Salary:" << salary << std::endl;

	// Create a stringstream object to write to an existing string.
	std::string str = "********************";
	std::stringstream stream2(str);

	// Do some output.
	stream2 << "Jane" << " " << 42 << " " << 15000;

	// See the effect.
	std::cout << stream2.str() << std::endl;

	// Create a stringstream object to read from an existing string.
	std::string str2 = "Jane 42 15000";
	std::stringstream stream3(str2);

	// Read formatted data from stringstream.
	stream3 >> name >> age >> salary;

	std::cout
		<< "Name: " << name << std::endl
		<< "Age: " << age << std::endl
		<< "Salary:" << salary << std::endl;

	//Write-Only and Read-Only String Streams
	//-std::ostringstream
	//- Output characters to a string.
	//- std::istringstream
	//- Input characters from a string.

	//Wide Characters and wchar_t
	//-std::wstring represents a string of wide characters.
	//- std::wistream, std::wostream, and std::wstream allow you to input and output wide characters.std::wcin
	//and std::wcout are predefined instances of std::wistream and std::wostream respectively.
	//- std::wistringstream, std::wostringstream, and std::wstringstream allow you to input and output wide
	//characters to/from a string.

    return 0;
}

