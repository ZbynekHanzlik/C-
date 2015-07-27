#include "std_lib_facilities.h"
#include "IntArray.h"
using namespace std;
int main()
{
	IntArray cArray(10);
	for (int i = 0; i < 10; i++)
		cArray[i];
	// Resize the array to 8 elements
	cArray.Resize(8);

	// Insert the number 20 before the 5th element
	cArray.InsertBefore(20, 5);

	// Remove the 3rd element
	cArray.Remove(3);

	// Add 30 and 40 to the end and beginning
	cArray.InsertAtEnd(30);
	cArray.InsertAtBeginning(40);

	// Print out all the numbers
	for (int j = 0; j < cArray.GetLength(); j++)
		cout << cArray[j] << " ";

	cout << "Hello\n";
	cout << "My all friends\n\t\n";
	cout << "std_lib_facilities.h is ready" << endl;
	keep_window_open();
	return 0;
}