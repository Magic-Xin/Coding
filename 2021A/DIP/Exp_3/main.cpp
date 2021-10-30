#include "opencv2/opencv.hpp"
#include <iostream>
#include <random>

cv::Mat SaltNoise(cv::Mat srcImg, int noise_num) {
    if (!srcImg.data) return srcImg;
    std::default_random_engine e(time(nullptr));
    std::uniform_real_distribution<double> u(0.0f, 1.0f);
    for (int i = 0 ; i < noise_num ; i++) {
        int x = u(e) * srcImg.rows;
        int y = u(e) * srcImg.cols;
        srcImg.at<cv::Vec3b>(x, y)[0] = 255;
        srcImg.at<cv::Vec3b>(x, y)[1] = 255;
        srcImg.at<cv::Vec3b>(x, y)[2] = 255;
    }
    return srcImg;
}

int main() {
    cv::Mat srcImg = cv::imread("../img.jpeg");

    if (!srcImg.data) {
        std::cout << "Read image failed!" << std::endl;
        return -1;
    }

    cv::Mat dstImg = SaltNoise(srcImg, 5000);
    cv::imshow("salt noise", dstImg);
    cv::waitKey(0);
    return 0;
}
