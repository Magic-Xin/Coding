#include "opencv2/opencv.hpp"
#include <iostream>

#define FILTER int
#define X_FILTER 0
#define Y_FILTER 1
#define XY_FILTER 2

struct {
    int kernel_x[9] = {-1, 0, 1,
                       -2, 0, 2,
                       -1, 0, 1};

    int kernel_y[9] = {-1, -2, -1,
                        0,  0,  0,
                        1,  2,  1};
}SobelStruct;

struct {
    int kernel[9] = {0,  1, 0,
                     1, -4, 1,
                     0,  1, 0};
}LaplacianStruct;

short algorithm(const int* _kernel, cv::Mat srcImg, int x, int y) {
    return srcImg.at<uchar>(x - 1, y + 1) * _kernel[0] + srcImg.at<uchar>(x, y + 1) * _kernel[1] + srcImg.at<uchar>(x + 1, y + 1) * _kernel[2] +
           srcImg.at<uchar>(x - 1, y) * _kernel[3] + srcImg.at<uchar>(x, y) * _kernel[4] + srcImg.at<uchar>(x + 1, y) * _kernel[5] +
           srcImg.at<uchar>(x - 1, y - 1) * _kernel[6] + srcImg.at<uchar>(x, y - 1) * _kernel[7] + srcImg.at<uchar>(x + 1, y - 1) * _kernel[8];
}

cv::Mat thresholdEffect(cv::Mat srcImg) {
    cv::Mat dstImg;
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(1, 1));
    cv::morphologyEx(srcImg, dstImg, cv::MORPH_TOPHAT, kernel);
    cv::threshold(dstImg, dstImg, 100, 255, cv::THRESH_TOZERO_INV);
    cv::threshold(dstImg, dstImg, 20, 90, cv::THRESH_BINARY);
    return dstImg;
}

cv::Mat laplacianEdgeDetection(cv::Mat srcImg) {
    if (!srcImg.data) return srcImg;

    cv::Mat dstImg = cv::Mat::zeros(srcImg.rows, srcImg.cols, CV_16S);
    int* _laplacian = LaplacianStruct.kernel;
    for(int y = 0 ; y < srcImg.rows ; y++) {
        for (int x = 0; x < srcImg.cols; x++) {
            if (x && y && x < srcImg.cols - 1 && y < srcImg.rows - 1) {
                dstImg.at<short>(x, y) = algorithm(_laplacian, srcImg, x, y) * 3;
            }
        }
    }
    cv::convertScaleAbs(dstImg, dstImg);
    return dstImg;
}

cv::Mat sobelEdgeDetection(cv::Mat srcImg, FILTER filter){
    if (!srcImg.data) return srcImg;

    cv::Mat dstImg = cv::Mat::zeros(srcImg.rows, srcImg.cols, CV_16S);
    int* _sobel;

    for(int y = 0 ; y < srcImg.rows ; y++) {
        for(int x = 0 ; x < srcImg.cols ; x++) {
            if (x && y && x < srcImg.cols - 1 && y < srcImg.rows - 1) {
                switch (filter) {
                    case X_FILTER:
                        _sobel = SobelStruct.kernel_x;
                        dstImg.at<short>(x, y) = algorithm(_sobel, srcImg, x, y);
                        break;
                    case Y_FILTER:
                        _sobel = SobelStruct.kernel_y;
                        dstImg.at<short>(x, y) = algorithm(_sobel, srcImg, x, y);
                        break;
                    case XY_FILTER:
                        _sobel = SobelStruct.kernel_x;
                        dstImg.at<short>(x, y) = algorithm(_sobel, srcImg, x, y);
                        _sobel = SobelStruct.kernel_y;
                        dstImg.at<short>(x, y) += algorithm(_sobel, srcImg, x, y);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    cv::convertScaleAbs(dstImg, dstImg);
    return dstImg;
}

cv::Mat robertEdgeDetection(cv::Mat srcImg, FILTER filter) {
    if (!srcImg.data) return srcImg;

    cv::Mat dstImg = cv::Mat::zeros(srcImg.rows, srcImg.cols, CV_16S);

    for(int y = 0 ; y < srcImg.rows ; y++) {
        for(int x = 0 ; x < srcImg.cols ; x++) {
            if (x && y && x < srcImg.cols - 1 && y < srcImg.rows - 1) {
                switch (filter) {
                    case X_FILTER:
                        dstImg.at<short>(x, y) = (srcImg.at<uchar>(x + 1, y + 1) - srcImg.at<uchar>(x, y)) * 2;
                        break;
                    case Y_FILTER:
                        dstImg.at<short>(x, y) = (srcImg.at<uchar>(x, y + 1) - srcImg.at<uchar>(x + 1, y)) * 2;
                        break;
                    case XY_FILTER:
                        dstImg.at<short>(x, y) = sqrt(
                                        pow((srcImg.at<uchar>(x + 1, y + 1) - srcImg.at<uchar>(x, y)) * 2, 2) +
                                        pow((srcImg.at<uchar>(x, y + 1) - srcImg.at<uchar>(x + 1, y)) * 2, 2));
                        break;
                    default:
                        break;
                }
            }
        }
    }
    cv::convertScaleAbs(dstImg, dstImg);
    return dstImg;
}

cv::Mat Gray(cv::Mat srcImg) {
    if(!srcImg.data) return srcImg;
    cv::Mat dstImg = cv::Mat::zeros(srcImg.rows, srcImg.cols, CV_8U);
    for(int y = 0 ; y < srcImg.rows ; y++) {
        for(int x = 0 ; x < srcImg.cols ; x++) {
            dstImg.at<uchar>(x, y) = static_cast<uchar>(srcImg.at<cv::Vec3b>(x, y)[0] * 0.0722 +
                    srcImg.at<cv::Vec3b>(x, y)[1] * 0.7152 + srcImg.at<cv::Vec3b>(x, y)[2] * 0.2126);
        }
    }
    return dstImg;
}

int main() {
    cv::Mat srcImg = cv::imread("../img.jpg");
    if (!srcImg.data) {
        std::cout << "Read image failed!" << std::endl;
        return -1;
    }
    cv::imshow("original image", srcImg);

    cv::Mat gaussianImg;
    cv::GaussianBlur(srcImg, gaussianImg, cv::Size(5, 5), 0, 0);
    cv::Mat grayImg = Gray(gaussianImg);
    cv::imshow("gaussian gray image", grayImg);
    cv::waitKey(0);
    cv::destroyAllWindows();

    cv::Mat robertImgX = thresholdEffect(robertEdgeDetection(grayImg, X_FILTER));
    cv::Mat robertImgY = thresholdEffect(robertEdgeDetection(grayImg, Y_FILTER));
    cv::Mat robertImgXY = thresholdEffect(robertEdgeDetection(grayImg, XY_FILTER));
    cv::imshow("threshold robert x filter image", robertImgX);
    cv::imshow("threshold robert y filter image", robertImgY);
    cv::imshow("threshold robert xy filter image", robertImgXY);
    cv::waitKey(0);
    cv::destroyAllWindows();

    cv::Mat sobelImgX = thresholdEffect(sobelEdgeDetection(grayImg, X_FILTER));
    cv::Mat sobelImgY = thresholdEffect(sobelEdgeDetection(grayImg, Y_FILTER));
    cv::Mat sobelImgXY = thresholdEffect(sobelEdgeDetection(grayImg, XY_FILTER));
    cv::imshow("threshold sobel x filter image", sobelImgX);
    cv::imshow("threshold sobel y filter image", sobelImgY);
    cv::imshow("threshold sobel xy filter image", sobelImgXY);
    cv::waitKey(0);
    cv::destroyAllWindows();

    cv::Mat laplacianImg = thresholdEffect(laplacianEdgeDetection(grayImg));
    cv::imshow("threshold laplace filter image", laplacianImg);
    cv::waitKey(0);

    return 0;
}
