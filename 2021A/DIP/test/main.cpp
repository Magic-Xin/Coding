#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img;
    img = cv::imread("../img.jpg");
    if (img.empty())
    {
        std::cout << "file not find!" << std::endl;
        return -1;
    }
    cv::imshow("waifu!", img);
    cv::waitKey(0);
    return 0;
}
