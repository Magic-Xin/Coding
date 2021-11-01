#include "opencv2/opencv.hpp"
#include <iostream>
#include <random>

#define NOISE 0

#define FILTER unsigned int
#define AVG_FILTER 0
#define MID_FILTER 1

int Average(cv::Mat srcImg, int x, int y, int n) {
    return (srcImg.at<cv::Vec3b>(x - 1, y + 1)[n] + srcImg.at<cv::Vec3b>(x, y + 1)[n] + srcImg.at<cv::Vec3b>(x + 1, y + 1)[n] +
            srcImg.at<cv::Vec3b>(x - 1, y)[n] + srcImg.at<cv::Vec3b>(x, y)[n] + srcImg.at<cv::Vec3b>(x + 1, y)[n] +
            srcImg.at<cv::Vec3b>(x - 1, y - 1)[n] + srcImg.at<cv::Vec3b>(x, y - 1)[n] + srcImg.at<cv::Vec3b>(x + 1, y - 1)[n]) / 9;
}

int KNNAverage(cv::Mat srcImg, int x, int y, int n, int knn) {
    int _pixel[8] = {srcImg.at<cv::Vec3b>(x - 1, y + 1)[n], srcImg.at<cv::Vec3b>(x, y + 1)[n], srcImg.at<cv::Vec3b>(x + 1, y + 1)[n],
                     srcImg.at<cv::Vec3b>(x - 1, y)[n], srcImg.at<cv::Vec3b>(x + 1, y)[n],
                     srcImg.at<cv::Vec3b>(x - 1, y - 1)[n], srcImg.at<cv::Vec3b>(x, y - 1)[n], srcImg.at<cv::Vec3b>(x + 1, y - 1)[n]};
    for (int i = 0; i < 8; i++)
        _pixel[i] -= srcImg.at<cv::Vec3b>(x, y)[n];
    std::sort(_pixel, _pixel + 8,
              [](int a, int b){return abs(a) < abs(b);});
    int _res = 0;
    for (int i = 0; i < knn; i++)
        _res += _pixel[i] + srcImg.at<cv::Vec3b>(x, y)[n];
    return _res / knn;
}

int Median(cv::Mat srcImg, int x, int y ,int n) {
    int _pixel[9] = {srcImg.at<cv::Vec3b>(x - 1, y + 1)[n], srcImg.at<cv::Vec3b>(x, y + 1)[n], srcImg.at<cv::Vec3b>(x + 1, y + 1)[n],
                     srcImg.at<cv::Vec3b>(x - 1, y)[n], srcImg.at<cv::Vec3b>(x, y)[n], srcImg.at<cv::Vec3b>(x + 1, y)[n],
                     srcImg.at<cv::Vec3b>(x - 1, y - 1)[n], srcImg.at<cv::Vec3b>(x, y - 1)[n], srcImg.at<cv::Vec3b>(x + 1, y - 1)[n]};
    std::sort(_pixel, _pixel + 9);
    return _pixel[4];
}

int KNNMedian(cv::Mat srcImg, int x, int y, int n, int knn) {
    int _pixel[8] = {srcImg.at<cv::Vec3b>(x - 1, y + 1)[n], srcImg.at<cv::Vec3b>(x, y + 1)[n], srcImg.at<cv::Vec3b>(x + 1, y + 1)[n],
                     srcImg.at<cv::Vec3b>(x - 1, y)[n], srcImg.at<cv::Vec3b>(x + 1, y)[n],
                     srcImg.at<cv::Vec3b>(x - 1, y - 1)[n], srcImg.at<cv::Vec3b>(x, y - 1)[n], srcImg.at<cv::Vec3b>(x + 1, y - 1)[n]};
    for (int i = 0; i < 8; i++)
        _pixel[i] -= srcImg.at<cv::Vec3b>(x, y)[n];
    std::sort(_pixel, _pixel + 8,
              [](int a, int b){return abs(a) < abs(b);});
    return _pixel[knn/2] + srcImg.at<cv::Vec3b>(x, y)[n];
}

cv::Mat KNNFilter(cv::Mat srcImg, int knn, FILTER filter) {
    if (!srcImg.data) return srcImg;
    cv::Mat dstImg = srcImg.clone();
    for (int y = 1; y < srcImg.rows ; y++) {
        for(int x = 1; x < srcImg.cols; x++) {
            if (x < srcImg.cols - 1 && y < srcImg.rows - 1) {
                switch (filter) {
                    case AVG_FILTER:
                        for (int n = 0; n < 3; n++)
                            dstImg.at<cv::Vec3b>(x, y)[n] = KNNAverage(srcImg, x, y, n, knn);
                        break;
                    case MID_FILTER:
                        for (int n = 0; n < 3; n++)
                            dstImg.at<cv::Vec3b>(x, y)[n] = KNNMedian(srcImg, x, y, n, knn);
                        break;
                }
            }
            else {
                for (int n = 0; n < 3; n++)
                    dstImg.at<cv::Vec3b>(x, y)[n] = srcImg.at<cv::Vec3b>(x, y)[n];
            }
        }
    }
    return dstImg;
}

cv::Mat Filter(cv::Mat srcImg, FILTER filter) {
    if (!srcImg.data) return srcImg;
    cv::Mat dstImg = srcImg.clone();
    for (int y = 1; y < srcImg.rows ; y++) {
        for(int x = 1; x < srcImg.cols; x++) {
            if (x < srcImg.cols - 1 && y < srcImg.rows - 1) {
                switch (filter) {
                    case AVG_FILTER:
                        for (int n = 0; n < 3; n++)
                            dstImg.at<cv::Vec3b>(x, y)[n] = Average(srcImg, x, y, n);
                        break;
                    case MID_FILTER:
                        for (int n = 0; n < 3; n++)
                            dstImg.at<cv::Vec3b>(x, y)[n] = Median(srcImg, x, y, n);
                        break;
                }
            }
            else {
                for (int n = 0; n < 3; n++)
                    dstImg.at<cv::Vec3b>(x, y)[n] = srcImg.at<cv::Vec3b>(x, y)[n];
            }
        }
    }
    return dstImg;
}

cv::Mat GauseNoise(cv::Mat srcImg, double sigma) {
    if (!srcImg.data) return srcImg;
    cv::Mat dstImg = srcImg.clone();

    std::default_random_engine e(time(nullptr));
    double r1, r2;

    for (int y = 0; y < srcImg.rows; y++) {
        for (int x = 0; x < srcImg.cols; x++) {
            do {
                r1 = e() * (1.0f / RAND_MAX);
                r2 = e() * (1.0f / RAND_MAX);
            } while (r1 <= std::numeric_limits<double>::min());

            double z = sigma * cos(2 * CV_PI * r2) * sqrt(-2 * log(r1));

            for (int n = 0; n < 2; n++) {
                double _pixel = srcImg.at<cv::Vec3b>(x, y)[n] + z;
                if (_pixel < 0)
                    dstImg.at<cv::Vec3b>(x, y)[n] = 0;
                else if (_pixel > 255)
                    dstImg.at<cv::Vec3b>(x, y)[n] = 255;
                else
                    dstImg.at<cv::Vec3b>(x, y)[n] = static_cast<uchar>(_pixel);
            }
        }
    }
    return dstImg;
}

cv::Mat SaltNoise(cv::Mat srcImg, int noise_num) {
    if (!srcImg.data) return srcImg;
    std::default_random_engine e(time(nullptr));
    std::uniform_real_distribution<double> u(0.0f, 1.0f);
    for (int i = 0 ; i < noise_num ; i++) {
        int x = u(e) * srcImg.cols;
        int y = u(e) * srcImg.rows;
        srcImg.at<cv::Vec3b>(x, y)[0] = 255;
        srcImg.at<cv::Vec3b>(x, y)[1] = 255;
        srcImg.at<cv::Vec3b>(x, y)[2] = 255;
    }
    return srcImg;
}

int main() {
    cv::Mat srcImg = cv::imread("../img.jpg");

    if (!srcImg.data) {
        std::cout << "Read image failed!" << std::endl;
        return -1;
    }
    cv::imshow("original image", srcImg);
    cv::Mat dstImg;

    if (NOISE) {
        dstImg = SaltNoise(srcImg, 5000);
        cv::imshow("salt noise", dstImg);
    }
    else {
        dstImg = GauseNoise(srcImg, 32.0f);
        cv::imshow("gause noise", dstImg);
    }
    cv::waitKey(0);
    cv::destroyAllWindows();

    cv::Mat avgImg = Filter(dstImg, AVG_FILTER);
    cv::imshow("average filter", avgImg);

    cv::Mat midImg = Filter(dstImg, MID_FILTER);
    cv::imshow("median filter", midImg);

    cv::Mat knn_avgImg = KNNFilter(dstImg, 5, AVG_FILTER);
    cv::imshow("KNN average filter", knn_avgImg);

    cv::Mat knn_midImg = KNNFilter(dstImg, 5, MID_FILTER);
    cv::imshow("KNN median filter", knn_midImg);
    cv::waitKey(0);
    return 0;
}
