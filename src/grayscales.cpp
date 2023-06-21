#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;


void grayscales(cv::Mat image)
{
    int rows = image.rows;
    int cols = image.cols;

    for (int i = 0; i < rows; i++)
    {
        // Obtention du pointeur vers la ligne i
        cv::Vec3b* rowPtr = image.ptr<cv::Vec3b>(i);

        for (int j = 0; j < cols; j++)
        {
            cv::Vec3b& pixel = rowPtr[j];

            // Calcul de la moyenne des composantes RVB
            unsigned char grayscale = (pixel[0] + pixel[1] + pixel[2]) / 3;

            // Assignation de la valeur moyenne à chaque composante
            pixel[0] = grayscale;
            pixel[1] = grayscale;
            pixel[2] = grayscale;
        }
    }
}
