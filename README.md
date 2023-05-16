# SaraKIT Object Detection for Raspberry Pi 4 CM4

SaraKIT is an easy-to-use object detection solution for Raspberry Pi 4 CM4, powered by state-of-the-art algorithms based on MediaPipe from Google, specifically optimized for the Raspberry Pi 64-bit platform.

## MediaPipe Object Detection
The MediaPipe Object Detector task lets you detect the presence and location of multiple classes of objects within images or videos. For example, an object detector can locate dogs within in an image.
Each detection result represents an object that appears within the image or video.


To utilize SaraKIT for object detection, follow these steps:

1. Compile the code by running the command `make`.
2. Execute the program using `./ObjectDetection`.
3. The program captures frames from the camera, processes them, and sends the output.
4. Preview the operation in your web browser by accessing the Raspberry Pi's IP address followed by port 7777 (e.g., http://192.168.1.16:7777).
5. The browser preview displays one or two images side by side, where the content of each image can be customized. By default, the left image shows the camera preview, while the right image displays the detected face along with face landmarks. Refer to the video below for a similar visualization.

Both the standard Raspberry Pi MMAL functions and OpenCV functions can be used to capture frames from the camera.

For instructions on how to install MediaPipe on Raspberry Pi, please refer to our separate repository dedicated to this topic.

![SaraKIT_Face](https://github.com/SaraEye/SaraKIT-MediaPipe-Object-Detection-Raspberry-Pi-64bit/assets/35704910/a7f9ec06-85cd-49a9-b0d6-db02ec404794)
