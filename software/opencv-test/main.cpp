#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat hello_mat(640, 480, CV_8UC3);
    cv::putText(hello_mat, "Hello?", cv::Point(300, 200), cv::FONT_HERSHEY_COMPLEX, 1.0, cv::Scalar(255, 127, 0));
    cv::imwrite("hello.png", hello_mat);
    std::cout << "cross-compiled in aarch64 container" << std::endl;
    return 0;
}