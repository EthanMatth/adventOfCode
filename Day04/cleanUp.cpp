#include <iostream>
#include <string.h>
#include <cctype>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream file;
    string line;

    vector<int> range;
    int contained = 0;

    file.open("cleanUp.txt");
    if(file.fail())
        cout << "File not found" << endl;

    while(true)
    {
        getline(file, line);
        if(file.fail())
            break;

        int value = 0;
        for(int i = 0; i < line.size(); i++)
        {
            if(isdigit(line[i]))
            {
                value = value * 10 + (int)line[i] - 48;
            }
            else
            {
                range.push_back(value);
                value = 0;
            }
        }
        range.push_back(value);

        if(range[1] >= range[2] && range[0] <= range[3])
            contained++;

        range.clear();
    }

    cout << contained << endl;
    return 0;
}
