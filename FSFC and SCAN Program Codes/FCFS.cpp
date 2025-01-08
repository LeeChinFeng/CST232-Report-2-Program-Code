#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the total seek time for FCFS algorithm
int fcfsDiskScheduling(int initialHeadPosition, int requests[], int numRequests) {
    int seekTime = 0;
    int currentPosition = initialHeadPosition;

    cout << "\nOrder of requests processed: ";
    for (int i = 0; i < numRequests; i++) {
        cout << requests[i] << " ";
        seekTime += abs(requests[i] - currentPosition);
        currentPosition = requests[i];
    }

    return seekTime;
}

int main() {
    int initialHeadPosition;
    int totalCylinders;
    int numRequests;

    // Input: Initial head position
    cout << "Enter the initial head position: ";
    cin >> initialHeadPosition;

    // Input: Total number of cylinders
    cout << "Enter the total number of cylinders on the disk: ";
    cin >> totalCylinders;

    // Input: Number of I/O requests
    cout << "Enter the number of I/O requests: ";
    cin >> numRequests;

    // Input: I/O request sequence
    int requests[numRequests];
    cout << "Enter the sequence of I/O requests (cylinder numbers): \n";
    for (int i = 0; i < numRequests; i++) {
        cin >> requests[i];
        // Validate cylinder numbers
        if (requests[i] < 0 || requests[i] >= totalCylinders) {
            cerr << "Error: Request " << requests[i] << " is out of range.\n";
            return 1;
        }
    }

    // Perform FCFS Disk Scheduling
    int totalSeekTime = fcfsDiskScheduling(initialHeadPosition, requests, numRequests);

    // Output the total seek time
    cout << "\nTotal seek time: " << totalSeekTime << "ms\n";

    return 0;
}
