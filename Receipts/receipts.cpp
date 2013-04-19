// FILE: receipts.h
// CLASS PROVIDED: BagWithReceipts
// This is from Project 2d in Chapter 4 of
// "Data Structures and Other Objects Using C++"
//
// TYPEDEF and MEMBER CONSTANTS for the Bag class:
//   static const size_t DEFAULT_CAPACITY = _____
//     BagWithReceipts::DEFAULT_CAPACITY is the initial capacity of a
//     BagWithReceipts that is created by the default constructor.
//
//   typedef _____ Item
//     BagWithReceipts::Item is the data type of the items in the
//     BagWithReceipts. It may be any of the C++ built-in types
//     (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
// CONSTRUCTOR for the BagWithReceipts class:
//   BagWithReceipts(size_t initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The BagWithReceipts is empty with an initial capacity
//     given by the parameter. The insert function will work efficiently
//     (without allocating new memory) until this capacity is reached.
//
// MODIFICATION MEMBER FUNCTIONS for the BagWithReceipts class:
//   void resize(size_t new_capacity)
//     Postcondition: The BagWithReceipts's current capacity is changed to the
//     new_capacity (but not less than the number of items already in the
//     BagWithReceipts). The insert function will work efficiently (without
//     allocating new memory) until the new capacity is reached.
//
//   int insert(const Item& entry)
//     Postcondition: A new copy of entry has been inserted into the
//     BagWithReceipts.  The return value is an integer called the "receipt."
//     The receipt can later be used to retrieve the entry.
//
//   void remove(const Item& target)
//     Postcondition: If target was in the BagWithReceipts, then one copy of
//     target has been removed from the BagWithReceipts; otherwise the
//     BagWithReceipts is unchanged.
//
//   void remove_by_receipt(int receipt)
//     Postcondition: If there is an entry with the specified receipt in
//     the BagWithReceipts, then that entry is removed (and later the receipt
//     may be reused for some other entry). Otherwise the
//     BagWithReceipts is unchanged.
//
// CONSTANT MEMBER FUNCTIONS for the BagWithReceipts class:
//   size_t size( ) const
//     Postcondition: Return value is the total number of items in the
//     BagWithReceipts.
//
//   size_t occurrences(const Item& target) const
//     Postcondition: Return value is number of times target is in the
//     BagWithReceipts .
//
//   bool using_receipt(int receipt) const
//     Postcondition: Return value is true if this bag currently has an item
//     with the specified receipt.
//
//   Item retrieve(int receipt) const
//     Precondition: using _receipt(receipt)
//     Postcondition: The return value is the item that has the specified
//     receipt.
//
// VALUE SEMANTICS for the BagWithReceipts class:
//   Assignments and the copy constructor may be used with BagWithReceipts
//   objects.
//
// DYNAMIC MEMORY USAGE by the BagWithReceipts:
//   If there is insufficient dynamic memory, then the following functions call
//   new_handler: The constructors, resize, insert, operator += ,
//   operator +, and the assignment operator.

#ifndef RECEIPTS_H
#define RECEIPTS_H
#include <stdlib.h>  // Provides size_t

using namespace std;
    class BagWithReceipts
    {
    public:
        // TYPEDEF and MEMBER CONSTANTS
        enum { DEFAULT_CAPACITY = 30 }; // Or: static const size_t DEFAULT_CAPACITY = 30;
        typedef int Item;
        // CONSTRUCTORS and DESTRUCTOR
        BagWithReceipts(size_t initial_capacity = DEFAULT_CAPACITY);
        BagWithReceipts(const BagWithReceipts& source);
        ~BagWithReceipts( );
        // MODIFICATION MEMBER FUNCTIONS
        void resize(size_t new_capacity);
        int insert(const Item& entry);
        void remove(const Item& target);
        void remove_by_receipt(int receipt);
        void operator =(const BagWithReceipts& source);
        // CONSTANT MEMBER FUNCTIONS
        size_t size( ) const { return used; }
        size_t occurrences(const Item& target) const;
        bool using_receipt(int receipt) const;
        Item retrieve(int receipt) const;
    private:
        Item *data;       // Pointer to partially filled dynamic array
        bool *in_use;     // in_use[i] is true if data[i] is being used now.
        size_t used;      // Number of items currently in this BagWithReceipts
        size_t capacity;  // Current capacity of the BagWithReceipts
    };

#endif
