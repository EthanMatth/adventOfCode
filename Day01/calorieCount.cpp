/*-----Advent of Code Day 01-----*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    //Variables to use
    ifstream file;
    string line;
    int sum = 0;
    vector<int> calories;

    // Opens the file to look at
    file.open("calories.txt");
    if(file.fail())
        cout << "File not found" << endl;

    // Loops through the calories from the text file
    while(true)
    {
        getline(file, line);
        if(file.fail()) break;

        if(line == "")
        {
            calories.push_back(sum);
            sum = 0;
            continue;
        }

        sum += stoi(line);
    }
    
    
    // Sorting vector
    for(int i = 0; i < 3; i++)
    {
        int largest = calories[i];
        for(int j = i + 1; j < calories.size(); j++)
        {
            if(calories[j] > largest)
            {
                int temp = calories[i];
                calories[i] = calories[j];
                calories[j] = temp;
                largest = calories[i];
            }
        } 
    }
        
    cout << "The elf carrying the most calories is carrying " << calories[0] << " calories." << endl;
    cout << "The top 3 elfs carry " << calories[0] << " " << calories[1] << " " << calories[2] << " calories." << endl;
    cout << "The top 3 elfs carry a combined " << calories[0] + calories[1] + calories[2] << " calories." << endl;
    return 0;
}
