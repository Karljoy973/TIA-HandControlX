/* -----------------------------------------------------*/
/* Fichier  : DisplayVide.cpp                           */
/* Role     : Acquisition Video d'Images                */
/* Auteur   : Karl JOYEUX, (repris de la doc)           */
/*          : Projet : HandControllerX                  */
/* -----------------------------------------------------*/
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
//#include "grayscales.h"

using namespace std;
using namespace cv;

void displayVideo()
{
    int gen = 9; // Change this value to adjust the blur matrix size
    cv::Mat frame, g_frame, b_frame;
    cv::VideoCapture cap(0); // 0 for the PC or PICAM camera, 1 for USB

    if (!cap.isOpened())
    {
        std::cout << "Erreur lors de l'ouverture de la capture vidéo." << std::endl;
        return;
    }

    cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("blured_Image", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("gray_image", cv::WINDOW_AUTOSIZE);

    for (;;)
    {
        cap >> frame; // Get an image from the camera
        cv::imshow("Image", frame);

        // Image RGB to grayscale
        cvtColor(frame,g_frame, cv::COLOR_RGB2GRAY);
        imshow("gray_image", g_frame);

        // Add Gaussian blur
        cv::medianBlur(g_frame, b_frame, gen);

        cv::imshow("blured_Image", b_frame);
        // Perform other operations (e.g., OTU, Kirsch, convex envelope detection)

        if (cv::waitKey(1) >= 0)
            break;
    }

    cv::waitKey(0);
}
