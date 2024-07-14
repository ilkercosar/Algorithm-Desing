#include <iostream>
#include <opencv2/opencv.hpp>
#include "sha256.h"

// SHA-256 Hash hesaplamak için yardımcı fonksiyon
std::string calculateSHA256Hash(const cv::Mat& image) {
    SHA256_CTX ctx;
    BYTE buf[SHA256_BLOCK_SIZE];
    sha256_init(&ctx);
    sha256_update(&ctx, (BYTE*)image.data, image.total() * image.elemSize());
    sha256_final(&ctx, buf);

    // Hash değerini string formatına dönüştürme
    std::stringstream ss;
    for (int i = 0; i < SHA256_BLOCK_SIZE; ++i) 
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)buf[i];
    }
    return ss.str();
}

int main() {
    std::string imagePath = "/home/hedef-ubuntu/cpp/sha256-image/image.png";
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);

    if (image.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return EXIT_FAILURE;
    }

    cv::imshow("Display Image", image);
    cv::waitKey(0);

    // SHA-256 hash hesaplama
    std::string hashValue = calculateSHA256Hash(image);
    std::cout << "SHA-256 Hash of the image: " << hashValue << std::endl;

    return EXIT_SUCCESS;
}
