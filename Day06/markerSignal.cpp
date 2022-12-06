#include <iostream>
#include <fstream>

using namespace std;

bool hasDuplicate(char arr[], int size);

int main(int argc, char const *argv[])
{
    char marker[14] = {'0'};

    ifstream file;
    string line;

    file.open("markerSignal.txt");
    if(file.fail())
        cout << "File not found" << endl;

    getline(file, line);
    for(int i = 0; i < line.size(); i++)
    {
        for(int j = 0; j < 14; j++)
            marker[j] = line[j+i];

        if(hasDuplicate(marker, 14))
        {
            cout << i + 14 << endl;
            break;
        }

    }

    return 0;
}

bool hasDuplicate(char arr[], int size)
{
    for(int i = 0; i < size-1; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(arr[i] == arr[j])
            return false;
        }
    }
    return true;
}
