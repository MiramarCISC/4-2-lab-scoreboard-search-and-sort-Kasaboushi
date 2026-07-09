#include "scoreboard.hpp"
#include <iostream>

using namespace std;

int calculateTotal(const int scores[], int size) {
    if(scores == nullptr || !isValidSize(size))
    {
        return 0;
    }
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        total += scores[i];
    }

    return total;
}

double calculateAverage(const int scores[], int size) {
    if(scores == nullptr || !isValidSize(size))
    {
        return 0;
    }
    return static_cast<double>(calculateTotal(scores,size)) / size;
}

int findLowest(const int scores[], int size) {
    if(scores == nullptr || !isValidSize(size))
    {
        return 0;
    }
    int lowest = scores[0];

    for(int i = 1; i < size; i++)
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
    return -1;
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
