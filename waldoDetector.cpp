/**
  * File:    waldoDetector.cpp
  *
  * Author:  Andrew R. (CopticCoder)
  * Date:    2024
  *
  * Summary of File:
  *   This file contains code which detects the well known visual riddle of "Where's Waldo?"
  *
  *   Functions:
  *   "waldoDetector": It loads the Waldo template image from the specified path using
  *   OpenCV's imread function.
  *   "detectWaldo": It loads the input image, performs template matching using OpenCV's "matchTemplate" function, and
  *   draws a red rectangle around the location of Waldo.
  *
  */

#include "waldoDetector.h"
using namespace cv;
using namespace std;

waldoDetector::waldoDetector(const string& templatePath) {
    waldoTemplate = imread(templatePath, IMREAD_COLOR);
    if (waldoTemplate.empty()) {
        cerr << "Error: Unable to load Waldo template image." << endl;
    }
}

void waldoDetector::detectWaldo(const string& inputImagePath, const string& outputImagePath) {
    Mat inputImage = imread(inputImagePath);
    if (inputImage.empty()) {
        cerr << "Error: Unable to load input image." << endl;
        return;
    }

    Mat result;
    matchTemplate(inputImage, waldoTemplate, result, TM_CCOEFF_NORMED);

    double threshold = 0.7;
    while (true) {
        double minVal, maxVal;
        Point minLoc, maxLoc;
        minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

        if (maxVal >= threshold) {
            Point topLeft = maxLoc;
            Point bottomRight(topLeft.x + waldoTemplate.cols, topLeft.y + waldoTemplate.rows);
            rectangle(inputImage, topLeft, bottomRight, Scalar(0, 0, 255), 2);
            rectangle(result, maxLoc, Point(maxLoc.x + waldoTemplate.cols, maxLoc.y + waldoTemplate.rows), Scalar(0), -1);
        } else {
            break;
        }
    }

    imwrite(outputImagePath, inputImage);
    cout << "Waldo detected, proof is located in: " << outputImagePath << " ;)" << endl;
}
