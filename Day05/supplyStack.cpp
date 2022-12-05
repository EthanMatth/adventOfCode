#include <iostream>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>

using namespace std;

int getNumToMove(string line);
int getFrom(string line, int i);
int getTo(string line, int i);

int main(int argc, char const *argv[])
{
    int numOfStacks;
    int stackIndex;
    ifstream file;
    string line;

    vector<vector<char>> stacks;

    file.open("supplyStack.txt");
    if(file.fail())
        cout << "File not found" << endl;

    getline(file, line);
    numOfStacks = (line.size() + 1) / 4;
    
    vector<char> crates;
    for(int i = 0; i < numOfStacks; i++)
        stacks.push_back(crates);

    // Fills in the 2D vector with crate information
    do{
        stackIndex = 0;
        for(int i = 1; i < line.size(); i += 4)
        {
            
            if(isalpha(line[i]))
            {
                stacks[stackIndex].push_back(line[i]);
            }
            stackIndex++;
        }
        getline(file, line);
    }while(line != "");
    
    // Reverses the order of the crates. Top crate is at the end
    for(int i = 0; i < numOfStacks; i++)
        reverse(stacks[i].begin(), stacks[i].end());

    
    while(true)
    {
        getline(file, line);
        if(file.fail())
            break;

        int num = getNumToMove(line);
        int from = getFrom(line, (num / 10 == 0) ? 0 : 1) - 1;
        int to = getTo(line, (num / 10 == 0) ? 0 : 1) - 1;

        for(int i = 0; i < num; i++)
        {
            char crate = stacks[from][stacks[from].size() - num + i];
            stacks[to].push_back(crate);
        }
        for(int i = 0; i < num; i++)
            stacks[from].pop_back();
    }
    
    cout << "The top crates in each crate are ";
    for(int i = 0; i < numOfStacks; i++)
    {
        cout << stacks[i].back();
    }
    cout << endl;

    return 0;
}

int getNumToMove(string line)
{
    int number = 0;
    number += (int)line[5] - 48;
    if(isdigit(line[6]))
        number = number * 10 + (int)line[6] - 48;

    return number;
}

int getFrom(string line, int i)
{
    return (int)line[12 + i] - 48;
}

int getTo(string line, int i)
{
    return (int)line[17 + i] - 48;
}