#include "scoreboard.hpp"
#include <iostream>

using namespace std;

int calculateTotal(const int scores[], int size) {
    int total = 0;
    if(!(scores == nullptr || !isValidSize(size)))
    {
        for (int i = 0; i < size; i++)
        {
            total += scores[i];
        }
    }
    return total;
    // tqassar: I'm going to compress these two statements. It makes it a bit more complicated, but this way, there's only one return statement.
    // also, variables are usually declared first if there's no reason to not. C++ reads top to bottom so this might cause problems if not done.
}

double calculateAverage(const int scores[], int size) {
    if(scores == nullptr || !isValidSize(size))
    {
        return 0;
    }
    return static_cast<double>(calculateTotal(scores,size)) / size; // it's really a bit awkward to do it like this, but I guess it works.
}

int findLowest(const int scores[], int size) {
    if(scores == nullptr || !isValidSize(size))
    {
        return 0; // in the future, consider adding a function that does this.
    }
    int lowest = scores[0];

    for(int i = 1; i < size; i++) //no need to move the bracket down a line.
    {
        if(scores[i] < lowest)
        {
            lowest = scores[i];
        }
    }
    return lowest;
}

int findHighest(const int scores[], int size) {
    if(scores == nullptr || !isValidSize(size))
    {
        return 0;
    }
    int highest = scores[0];

    for(int i = 1; i < size; i++)
    {
        if(scores[i] > highest)
        {
            highest = scores[i];
        }
    }
    return highest;
}

int findScore(const int scores[], int size, int target) {
    if (scores == nullptr || !isValidSize(size)) 
    {
        return -1;
    }

    for(int i = 0; i < size; i++)
    {
        if(scores[i] == target)
        {
            return i;
        }
    }
    return -1; //instead of early returns, consider setting a variable to -1 and only updating it off the loop.
}

void sortScores(int scores[], int size) {
    for( int i = 0; i < size-1; i++)
    {
        int minIndex = i;

        for(int j = i+1; j < size; j++)
        {
            if(scores[j] < scores[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = scores[i];
        scores[i] = scores[minIndex];
        scores[minIndex] = temp;
    }
}

void printScores(const int scores[], int size) {
    if (scores == nullptr || !isValidSize(size)) {
        cout << "No scores to print." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << scores[i];

        if (i < size - 1) {
            cout << " ";
        }
    }

    cout << endl;
}

bool isValidSize(int size) {
    return size > 0;
}
