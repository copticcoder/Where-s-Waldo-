/**
  * File:    waldoDetector.h
  *
  * Author:  Andrew R. (CopticCoder)
  * Date:    2024
  *
  * Summary of File:
  *   This file contains the declaration of the code which detects the well known visual riddle of "Where's Waldo?"
  *   The class waldoDetector has a private member variable waldoTemplate of type cv::Mat to store the Waldo template
  *   image.
  *
  */

#ifndef WHEREISWALDO_WALDODETECTOR_H
#define WHEREISWALDO_WALDODETECTOR_H
#include <opencv2/opencv.hpp>

class waldoDetector {
public:
    waldoDetector(const std::string& templatePath);

    void detectWaldo(const std::string& inputImagePath, const std::string& outputImagePath);

private:
    cv::Mat waldoTemplate;
};

#endif //WHEREISWALDO_WALDODETECTOR_H
