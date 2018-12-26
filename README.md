# Kinect-Point-Cloud-Example
A sample project that shows how to get point cloud data and depth image from kinect. It uses the OpenFrameworks ofxKinect library.

How to get OpenFrameWorks and ofxKinect working on windows:
1. Download OpenFrameWorks from the main website:
    https://openframeworks.cc/download/
2. Download Zadig (version 2.0.1) from:
    https://zadig.akeo.ie/
3. Using the Zadig software, and clicking the drop down menu, you should see:
    Xbox NUI Camera, Xbox NUI Motor, and Kinect USB Audio.
    Install the driver "libusbK (v3.0.7.0)" on all 3 parts listed above.
4. That should be it for all installation. 
    Now you can create a OpenFrameworks project by going to and lauching
    of_vX.XX.X_vs20XX_release/projectGenerator-vs/projectGenerator.exe
    Make sure to include ofxKinect and OpenCV under addons.
