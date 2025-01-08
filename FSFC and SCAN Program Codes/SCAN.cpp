#include <iostream>
#include <string>
using namespace std;

void scanLeft(int& headPos, int request[], int numRequests, int& numCompletedRequests, int& totalSeekTime){
  for(int i = headPos; i > 0; i--){
    for(int j = 0; j < numRequests; j++){
      if(request[j] == i){
        request[j] = -999;  // To indicate request has been serviced
        cout << "\n" << i;
        numCompletedRequests++;
        totalSeekTime += headPos - i;
        headPos = i;
      }
    }
  }
  if(numCompletedRequests == numRequests)
    return;
  cout << "\n0";
  totalSeekTime += headPos;
  headPos = 0;
}

void scanRight(int& headPos, int totalCylinders, int request[], int numRequests, int& numCompletedRequests, int& totalSeekTime){
  for(int i = headPos; i < (totalCylinders - 1); i++){
    for(int j = 0; j < numRequests; j++){
      if(request[j] == i){
        request[j] = -999;  // To indicate request has been serviced
        cout << "\n" << i;
        numCompletedRequests++;
        totalSeekTime += abs(headPos - i);
        headPos = i;
      }
    }
  }
  if(numCompletedRequests == numRequests)
    return;
  cout << "\n199";
  totalSeekTime += abs(headPos - (totalCylinders - 1));
  headPos = totalCylinders - 1;
}

void SCAN(int& headPos, int totalCylinders, int request[], int numRequests, string direction){
  int numCompletedRequests = 0;
  int totalSeekTime = 0;

  cout << "\n\nThe order of the processed requests is: ";
  if(direction == "left"){
    cout << "\nThe direction of SCAN is now: left";
    scanLeft(headPos, request, numRequests, numCompletedRequests, totalSeekTime);
    if(numCompletedRequests != numRequests){
      cout << "\nThe direction of SCAN is now: right";
      scanRight(headPos, totalCylinders, request, numRequests, numCompletedRequests, totalSeekTime);
    }
  }
  else if(direction == "right"){
    cout << "\nThe direction of SCAN is now: right";
    scanRight(headPos, totalCylinders, request, numRequests, numCompletedRequests, totalSeekTime);
    if(numCompletedRequests != numRequests){
      cout << "\nThe direction of SCAN is now: left";
      scanLeft(headPos, request, numRequests, numCompletedRequests, totalSeekTime);
    }
  }

  cout << "\n\nTotal seek time: " << totalSeekTime << "ms";
}

int main(){
  //Variable declaration
  int headPos;
  int totalCylinders;
  int numRequests;
  string direction;

  // Inputs from user
  cout << "Enter the total number of cylinders: ";
  cin >> totalCylinders;
  cout << "Enter the head's initial position: ";
  cin >> headPos;
  cout << "Enter the number of I/O requests: ";
  cin >> numRequests;
  int request[numRequests];
  cout << "Please enter the requests seperated by space: ";
  for(int i = 0; i < numRequests; i++){
    cin >> request[i];
    if(request[i] > totalCylinders - 1 || request[i] < 0){
      cout << "\nPlease enter a valid cylinder number of 0 to " << totalCylinders << ".";
      i--;
    }
  }
  cout << "Enter the intial scan direction (left or right): ";
  cin >> direction;

  SCAN(headPos, totalCylinders, request, numRequests, direction);

  return 0;
}