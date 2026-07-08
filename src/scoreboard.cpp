#include "scoreboard.hpp"
#include <iostream>

using namespace std;



bool isNullOrInvalid(const int scores[], int size) { //because we have to check this for multiple functions, let's just put it here.
    // returns true if size is invalid, or if the array is null
    if (scores == nullptr) {
        return true;
    }
    if (!isValidSize(size)) {
        //cout << "ValidSize passed";
        /*
        if ((long unsigned int) size >= (sizeof(scores) / sizeof(scores[0]))) {
            cout << "Invalid Size";
            cout << sizeof(scores) << '\n';
            cout << sizeof(scores[0]);
            return true;
        }
        else {
            cout << "Valid Size";
            return false;
        }
        */
       return true;
    }
    return false;
    
    // check if the size is valid: if not, return true
    // check if the array is null: if it is, return true
    // otherwise, return false
}



int calculateTotal(const int scores[], int size) {
    // TODO:
    // If the array is null or the size is invalid, return 0.
    // Otherwise, return the sum of all scores.
    if (isNullOrInvalid(scores,size)) {
        return 0.0;
    }
    double total = 0;
    for (int i = 0; i < size; i++) {
        //cout << scores[i];
        total += scores[i];
    }
    return total;

}

double calculateAverage(const int scores[], int size) {
    // TODO:
    // If the array is null or the size is invalid, return 0.0.
    // Otherwise, return the total divided by size.
    double total = calculateTotal(scores, size);
    return total / size;
}

int findLowest(const int scores[], int size) {
    // TODO:
    // If the array is null or the size is invalid, return 0.
    // Otherwise, return the smallest score.
    if (isNullOrInvalid(scores,size)) {
        return 0;
    }
    int lowestSoFar = scores[0];
    for (int i = 0; i < size; i++) {
        if (scores[i] < lowestSoFar) {
            lowestSoFar = scores[i];
        }
    }
    return lowestSoFar;
}

int findHighest(const int scores[], int size) {
    // TODO:
    // If the array is null or the size is invalid, return 0.
    // Otherwise, return the largest score.
    if (isNullOrInvalid(scores, size)) {
        return 0;
    }
    int largestSoFar = scores[0];
    for (int i = 0; i < size; i++) {
        if (scores[i] > largestSoFar) {
            largestSoFar = scores[i];
        }
    }
    return largestSoFar;
}

int findScore(const int scores[], int size, int target) {
    // TODO:
    // Search the array from left to right.
    // Return the index where target is found.
    // Return -1 when target is not found.
    for (int i = 0; i < size; i++) {
        if (scores[i] == target) {
            return i;
        }
    }
    return -1;
}

void sortScores(int scores[], int size) {
    // TODO:
    // Sort the array from lowest to highest.
    // A selection sort works well for this lab.
    for (int i = 0; i < size; i++) {
        int lowestInRange = scores[i];
        int lowIndex = i;
        for (int j = i; j < size; j ++) {
            if (scores[j] < lowestInRange) {
                lowestInRange = scores[j];
                lowIndex = j;
            }
        }
        int tempVal = scores[i];
        scores[i] = lowestInRange;
        scores[lowIndex] = tempVal;
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
    // TODO: Return true when size is greater than 0.
    if (size > 0) {
        return true;
    }
    return false;
}
