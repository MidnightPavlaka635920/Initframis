# Initframis
## About
Initframis is a program that transfers videos to ASCII full or half characters in an ANSI text file.
I got the idea from rickroll in terminal.
Sadly, this doesn't work on Windows CMD. I don't know about powershell, or any other consoles, but it works on Linux.
## Dependencies
- This is a C++ project, so you will need g++ for compiling in Linux or something else on Windows.
- OpenCV is core of this project. It handles video loading, Pixel reading, etc.
- ffmpeg cause openCV should be compiled with ffmpeg.
## Compiling
To compile initframis, run 

```bash
g++ main.cpp -o main -I/usr/local/include/opencv4 \
-L/usr/local/lib \
-lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs
```


## Usage
To use this, run `initframis input.mp4 80 output.full h`
Of course, you will need to specify input video file. Output is saved to current directory if not specified.
### Arguments
- `input.mp4` Input video file. Can be any valid video file, needs read permissions.
- `80` Width you want output to be, in characters, can be any normal number. Just make sure that height would fit in your terminal.
- `output.full` Output/result file, I am using full file type. Can be any valid file, needs write permission.
- `h` Type of output characters. Can be ONLY `h` or `f`. H gives double the vertical resolution, uses upper-half characters. F gives full characters, so smaller vertical resolution.