#include <iostream>
#include "cstring"
#include "opencv2/opencv.hpp"

int main() {
    cv::VideoCapture cam(0);
    std::string name;
    int i = 0;
    while (true) {
        cv::Mat image;
        cam >> image;
        cv::imshow("test", image);
        if (cv::waitKey(20) >= 0) {
            break;
        }
        if (i % 10 == 0) {
            name = "../image/" + std::to_string(i) + ".jpg";
            cv::imwrite(name, image);
        }
        i++;
    }
    cam.release();
    return 0;
}
