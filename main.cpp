/**
  * File:    main.cpp
  *
  * Author:  Andrew R. (CopticCoder)
  * Date:    2024
  *
  * Summary of File:
  *    main checks if the input arguments are provided. main then creates a WaldoDetector object by passing the path
  *    to the Waldo template image to the constructor. Then calls the detectWaldo function of the WaldoDetector object,
  *    passing the path to the original puzzle and the detected Waldo puzzle path.
  *
  */

#include <iostream>
#include "waldoDetector.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Use format: ./find_waldo <Waldo> <Waldo Puzzle>" << endl;
        return -1;
    }

    waldoDetector detector(argv[1]);
    detector.detectWaldo(argv[2], "waldo_detected.jpg");

    return 0;
}

