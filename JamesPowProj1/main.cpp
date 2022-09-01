/* This program requires the student to write 3 functions described in
 * Program project 4 (Page 535) and Program Project 6 (Page 536).
 * The student also need to add a print function to print out an array.
 * The student may watch video notes on MyProgrammingLab to get the idea
 * on how to write the main function and three of these four functions
 *
 * Author: Your Name
 * Version: The date
 */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void reverse(char* front, char* rear);
// Precondition: The front and rear are pointing to the front
//               and rear of a C-string, respectively
// Postcondition: The C-string is reversed

string* addEntry(string* dynamiccArray, int& size, string newEntry);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array

void print(const string* dynamicArray, int size);
// Precondition: dynamicArray point to a array of strings with give size,
// Postcondition: The elements in dynamic array will be print out. One
//                element per line forllowed by its index

int main()
{   
    // START of driver program for reverse()
    //cout << "This program takes a string and reverses it.\n";

    //const int SIZE = 100;
    //char user_string[SIZE];
    //cout << "Please enter the string you'd like reversed: ";
    //cin.getline(user_string, SIZE);

    //// initializes pointers to first index of string and to the last used index
    //char* string_head = nullptr, * string_rear = nullptr;
    //string_head = user_string;
     //string_rear = user_string + strlen(user_string) - 1;

    //reverse(string_head, string_rear);

    //// prints result of reverse() function call
    //cout << "The reversed string is: " << string_head << endl;
    // END of reverse() driver program
   

    // START of driver program to test addEntry() and deleteEntry()
    int arrSize = 5;
    string* strArray = new string[arrSize];
    strArray[0] = "Hamza";
    strArray[1] = "Gertrude";
    strArray[2] = "Milton";
    strArray[3] = "Misha";
    strArray[4] = "Ryan";

    string entry = "Khalid";
    strArray = addEntry(strArray, arrSize, entry);
    print(strArray, arrSize);

    entry = "Jordan";
    strArray = addEntry(strArray, arrSize, entry);
    print(strArray, arrSize);

    entry = "Eva";
    strArray = addEntry(strArray, arrSize, entry);
    print(strArray, arrSize);

    string target = "Jordan";
    strArray = deleteEntry(strArray, arrSize, target);
    print(strArray, arrSize);

    target = "James";
    strArray = deleteEntry(strArray, arrSize, target);
    print(strArray, arrSize);

    entry = "Wasif";
    strArray = addEntry(strArray, arrSize, entry);
    print(strArray, arrSize);

    target = "Hamza";
    strArray = deleteEntry(strArray, arrSize, target);
    print(strArray, arrSize);

    target = "Jordan";
    strArray = deleteEntry(strArray, arrSize, target);
    print(strArray, arrSize);

    cin.get();
    return 0;
}

void reverse(char* front, char* rear) {

    int str_length = strlen(front);
    int i = 0;
    if (str_length % 2 == 0) {
        // this branch of if statement for even-length strings
        while (i < str_length / 2) {
            char temp = *front;
            *front = *rear;
            *rear = temp;
            front++;
            rear--;
            i++;
        }
    } else {
        // this branch of if statement for odd-length strings
        while (i < (str_length / 2) + 1) {
            char temp = *front;
            *front = *rear;
            *rear = temp;
            front++;
            rear--;
            i++;
        }
    }
}

string* addEntry(string* dynamicArray, int& size, string newEntry) {

    cout << "Adding " << newEntry << " to array at index " << size << "..." << endl << endl;

    string* dynamicArray2 = new string[size + 1];

    for (int i = 0; i < size; i++) {
        dynamicArray2[i] = dynamicArray[i];
    }
    
    dynamicArray2[size] = newEntry;

    delete [] dynamicArray;

    size++;

    return dynamicArray2;
}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete) {

    cout << "Searching for " << entryToDelete << "..." << endl;

    for (int i = 0; i < size; i++) {
        if (dynamicArray[i] == entryToDelete) { // if searched-for element is found

            std::cout << "Found " << entryToDelete << " at index " << i << endl;
            std::cout << "Deleting " << entryToDelete << " from array..." << endl;
            std::cout << "And returning updated array " << endl << endl;

            string* smallerArray = new string[--size];
            for (int j = 0; j < size; j++) {
                if (i == 0) { // branch to deal with deletion of name from index [0]
                    smallerArray[j] = dynamicArray[j + 1];
                }
                else if (j == i) { // this skips array to be deleted at index [j] 
                    smallerArray[j] = dynamicArray[j + 1]; // and grabs value from next position
                }
                else {
                    smallerArray[j] = dynamicArray[j];
                }
            }
            delete[] dynamicArray;
            return smallerArray;
        }
    }
    // if entryToDelete is not found
    std::cout << "name not found" << endl << "returning unchanged array\n\n";
    return dynamicArray;
}

void print(const string* dynamicArray, int size){

    for (int i = 0; i < size; i++) {
        cout << *dynamicArray << " at index: " << i << endl;
        dynamicArray++;
    }
    cout << endl;
}