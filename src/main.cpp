#include<stdio.h>
#include <opencv2/opencv.hpp>
#include "displayVideo.h"
#include "future"

using namespace std;

int main(void){
	
    //future<void> video = async( launch::async, displayVideo); // future permet de dire qu'une tâche est à effectuer de façon asynchrone
    //video.wait(); //attend la fin de video
    displayVideo();
	return 0;
}
