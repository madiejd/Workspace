// CS212 Homework tester
// W.P. Iverson
// April 2012

#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "receipts.h"       // With Item defined as an int
using namespace std;

int main() {
	// Main C++ text, chapter 4, page 218, #2d:
	// work project 7 on page 150 (chapter 3) using dynamic array
	BagWithReceipts ages;
	BagWithReceipts small(2);

	small.resize(3);

	// do lots of inserts and removals:
	for (int i = 0; i < 40; i++)
		ages.insert(381 - 17 * i);
	cout << ages.size() << endl; // should be 40 items
	for (int i = 0; i < 40; i++)
		ages.remove(i);
	cout << ages.size() << endl;
	for (int i = 0; i < 4; i++)
		ages.remove_by_receipt(i);
	cout << ages.size() << endl;
	for (int i = 0; i < 4; i++)
		ages.remove_by_receipt(381 - 17 * i);
	cout << ages.size() << endl;

	// make an extra bag and test assignment operator
	BagWithReceipts extra(ages);
	cout << extra.size() << endl;
	cout << small.size() << endl;
	small = extra;
	for (int i = 0; i < 40; i++)
		extra.insert(381 - 17 * i);
	cout << extra.size() << endl;
	cout << small.size() << endl;
	cout << extra.occurrences(381 - 17 * 19) << endl;
	cout << extra.occurrences(24) << endl;
	cout << (extra.using_receipt(18) ? "18" : "N/A") << endl;
	cout << (extra.using_receipt(88) ? "88" : "N/A") << endl;

	// Can we run out of memory?
	int j = 1;
	while (j < 1000) {
		j++;
		cout << "j=" << j << endl;
		BagWithReceipts last(1000000);
	}

	system("pause");
	return (EXIT_SUCCESS);
}
