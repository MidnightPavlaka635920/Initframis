# Initframis
## About
Initframis is a program that transfers videos to ASCII full or half characters in an ANSI text file.
I got the idea from rickroll in terminal.
Sadly, this doesn't work on Windows CMD. I don't know about powershell, or any other consoles, but it works on Linux.
## Dependencies
-This is a C++ project, so you will need g++ for compiling in Linux or something else on Windows.
-OpenCV is core of this project. It handles video loading, Pixel reading, etc.
-ffmpeg cause ooenCV should be compiled with ffmpeg.
## Compiling
To compile initframis, run `g++ main.cpp -o main -I/usr/local/include/opencv4 -L/usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs`
## Usage
To use this, run `initframis input.mp4 80 output.full h`
Of course, you will need to specify input video file. Output is saved to current directory if not specified.