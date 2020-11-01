#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

long int hashedTable[262144][19];
long int nodeIDs[2000];

int main(int argc, char *argv[]){

  long int inputVal = atol(argv[1]); //input value

  //input file
  int m = 18;
  ifstream input;
  string line;
  long int userInput, nodeNumber, emp, succ;
  int temp = 0, i = 0, j = 0, k = 0;
  long double first = 0, second = 0;
  int found = 0;

  ifstream  file("nodeIDs.txt");

  while(getline(file,line)){
      nodeIDs[i] = stoi(line);
      i++;
  }
  temp = i;

  for(i = 0; i < temp; i++){
    for(k = 1; k < m+1; k++){
      nodeNumber = nodeIDs[i];
      succ = (long int)fmodl((long double)(nodeNumber+pow(2,(k-1)))
             ,(long double)(pow(2,m)));
      for(j = 0; j<temp; j++){
        if(succ <= nodeIDs[j]){
          hashedTable[nodeNumber][k]=nodeIDs[j];
          found = 1;
          break;
        }
      }
      if(found == 0){ hashedTable[nodeNumber][k]=nodeIDs[0]; }
      else { found = 0;}

    }

  }
  string spacing;
  while(true){
    // cout << "Enter the Node ID or 0 to exit... \n::";
    // cin >> userInput;
    // if(userInput == 0){ cout << "Exiting..." << endl; break;}
    for(i = 1; i < m+1; i++){
      if(i >= 10){ spacing = "    ";}
      else{ spacing = "     ";}
      cout << i << spacing << hashedTable[inputVal][i] << endl;
    }
    break;
  }





}
