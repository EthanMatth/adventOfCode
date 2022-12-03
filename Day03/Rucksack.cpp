/*-----Advent of Code Day 03-----*/

#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    string compOne;
    string compTwo;

    int sum = 0;

    bool inLineOne = false;
    bool inLineTwo = false;
    bool inLineThree = false;

    ifstream file;
    string lineOne;
    string lineTwo;
    string lineThree;

    // Opens the file to read from
    file.open("Rucksack.txt");
    if (file.fail())
        cout << "File not found" << endl;

    // Loops through each line of the file
    while (true)
    {
        getline(file, lineOne);
        getline(file, lineTwo);
        getline(file, lineThree);
        if (file.fail())
            break;

        

        // Loops through each letter
        for(char i = 'a'; i <= 'z'; i++)
        {
            inLineOne = false;
            inLineTwo = false;
            inLineThree = false;
            if(lineOne.find(i) != string::npos) inLineOne = true;
            if(lineTwo.find(i) != string::npos) inLineTwo = true;
            if(lineThree.find(i) != string::npos) inLineThree = true;

            if(inLineOne && inLineTwo && inLineThree)
            {
                sum += (int)i - 96;
                continue;
            }
        }
        for(char i = 'A'; i <= 'Z'; i++)
        {
            inLineOne = false;
            inLineTwo = false;
            inLineThree = false;
            if(lineOne.find(i) != string::npos) inLineOne = true;
            if(lineTwo.find(i) != string::npos) inLineTwo = true;
            if(lineThree.find(i) != string::npos) inLineThree = true;

            if(inLineOne && inLineTwo && inLineThree)
            {
                sum += (int)i - 38;
                continue;
            }
        }
    }

    cout << "The sum of priority items is: " << sum << endl;

    
    return 0;
}
