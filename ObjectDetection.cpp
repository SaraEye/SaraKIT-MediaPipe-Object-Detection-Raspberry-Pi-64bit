#include <iostream>
#include <signal.h>
#include <stdio.h>
#include <math.h>
#include <arm_neon.h>
#include "unistd.h"

#include "struct.hpp"
#include "lib/viewer/viewer.hpp"
#include "lib/mediapipe/Mediapipe.hpp"

using namespace std;
 
cv::Mat frame0, frame0Gray, frame0GrayHalf, frame0GrayHalfEdge; // cam0
cv::Mat frame1, frame1Gray, frame1GrayHalf, frame1GrayHalfEdge; // cam1
cv::Mat imgProcessed;

ViewerStatus viewStatus;

//ctrl-c 
void ctrlc_handler(sig_atomic_t s){
    printf("\nCaught signal %d\n",s);
    control_c=true;
    exit(1);
}

int main(int argc, char** argv){
    signal(SIGINT,ctrlc_handler);
	
	camwidth=640;
	camheight=480;

    imgProcessed=cv::Mat(camheight, camwidth, CV_8UC3);

    init_camera(0, camwidth, camheight, false, false, true, true, true);
    //init_camera(1, camwidth, camheight, false, false, true, true, true);
    sleepms(200);

    //init_viewer(ViewMode::Camera0, ViewMode::Camera1, 1, false, true);
    init_viewer(ViewMode::Camera0,ViewMode::Processed);

    std::vector<mpobject::Object> objects;

    MediapipeObject mo;
    FrameResultSynchroniser objectSync(200);

    printf("Start Loop\n");
    do {
        // Get frame to frame,frameGray,frameGrayHalf
        if (GetFrame()==0) { //GetFrame()==1 (new frame from cam0 ==1, ==2 from cam1, ==3 from cam0 & cam 1)

            //here you have time to do anything

            sleepms(1);
            continue;
        }

        objects.clear();
        objectSync.pushFrame(mo.pushFrame(frame0),frame0);
        int reso=objectSync.getFrameFromId(mo.getObjects(objects),imgProcessed);

        if (reso&&objects.size()) {
            mo.drawObjectsRects(imgProcessed,objects);
            tick2on=true;
        }

        viewStatus = viewer_refresh();
    } while (viewStatus != ViewerStatus::Exit && control_c != true);
    closing_function(0);
    return 1;
}
