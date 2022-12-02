/*-----Advent of Code Day 02-----*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> elfMoves;
    vector<int> myMoves;

    int myScore = 0;
    int elfScore = 0;

    ifstream file;
    string line;

    // Opens the file to read from
    file.open("moves.txt");
    if (file.fail())
        std::cout << "You suck" << endl;

    // Gets the data from the file and puts into vectors
    while (true)
    {
        getline(file, line);
        if (file.fail())
            break;
        
        if(line[0] == 'A') elfMoves.push_back(1);
        if(line[0] == 'B') elfMoves.push_back(2);
        if(line[0] == 'C') elfMoves.push_back(3);

        if(line[2] == 'X') myMoves.push_back(1);
        if(line[2] == 'Y') myMoves.push_back(2);
        if(line[2] == 'Z') myMoves.push_back(3);
    }

    // Loops through vectors to determin points
    for (int i = 0; i < elfMoves.size(); i++)
    {
        /*
        if(myMoves[i] == elfMoves[i])
        {
            myScore += myMoves[i] + 3;
            elfScore += elfMoves[i] + 3;
            continue;
        }
        if(((myMoves[i] + 1) == 4 ? 1 : myMoves[i] + 1) == elfMoves[i])
        {
            myScore += myMoves[i];
            elfScore += elfMoves[i] + 6;
            continue;
        }
        else
        {
            myScore += myMoves[i] + 6;
            elfScore += elfMoves[i];
            continue;
        }
        */
       if(myMoves[i] == 1) // I need a lose
       {
            myScore += (elfMoves[i] - 1 == 0 ? 3 : elfMoves[i] - 1);
            continue;
       }
       if(myMoves[i] == 2) // I need a tie
       {
            myScore += elfMoves[i] + 3;
            continue;
       }
       if(myMoves[i] == 3) // I need a win
       {
            myScore += (elfMoves[i] + 1 == 4 ? 1 : elfMoves[i] + 1) + 6;
            continue;
       }
    }

    std::cout << "My final score is: " << myScore << endl;

    return 0;
}
