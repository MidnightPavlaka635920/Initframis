# Initframis
<img width="1000" alt="image" src="https://github.com/user-attachments/assets/6260894b-5f74-4fea-a48d-abd5eb2271a9" />

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
g++ initframis.cpp -o initframis -I/usr/local/include/opencv4 -L/usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lva -lva-drm -lva-x11
```


## Usage
To use this, run 


```./initframis input.mp4 80 output.full h```



from your initframis binary directory unless you installed it to the `$PATH`which you can check by running `echo $PATH`.
Of course, you will need to specify input video file. Output is saved to current directory if not specified.
After the program is done, it will show height of output, and that can be used in `grr.sh` to display video, with addition to audio.
### Arguments
- `input.mp4` Input video file. Can be any valid video file, needs read permissions.
- `80` Width you want output to be, in characters, can be any normal number. Just make sure that height would fit in your terminal.
- `output.full` Output/result file, I am using full file type. Can be any valid file, needs write permission.
- `h` Type of output characters. Can be ONLY `h` or `f`. H gives double the vertical resolution, uses upper-half characters. F gives full characters, so smaller vertical resolution.
## Output structure
In 1.1, I changed output structure in order to use this with ansitovideo. This is new file structure:

```
FPS:30.00
H:71
W:80
^[[38;2;167;129;173mM-bM-^VM-^H^[[38;2;166;127;172mM-bM-^VM-^H^[[38;2;151;111;156mM-bM-^VM-^H^[[38;2;151;111;157mM-bM-^VM-^H^[[38;2;153;114;162mM-bM-^VM-^H^[[38;2;221;202;59mM-bM-^VM-^H^[[38;2;210;198;23mM-bM-^VM-^H^[[38;2;192;180;23mM-bM-^VM-^H^[[38;2;192;180;23mM-bM-^VM-^H^[[38;2;215;202;23mM-bM-^VM-^H^[[38;2;240;226;21mM-bM-^VM-^H^[[38;2;241;226;21mM-bM-^VM-^H^[[38;2;195;183;22mM-bM-^VM-^H^[[38;2;229;217;21mM-bM-^VM-^H^[[38;2;240;226;21mM-bM-^VM-^H^[[38;2;228;215;23mM-bM-^VM-^H^[[38;2;191;180;22mM-bM-^VM-^H^[[38;2;191;180;23mM-bM-^VM-^H^[[38;2;214;202;23mM-bM-^VM-^H^[[38;2;240;226;22mM-bM-^VM-^H^[[38;2;210;196;24mM-bM-^VM-^H^[[38;2;191;179;22mM-bM-^VM-^H^[[38;2;194;182;22mM-bM-^VM-^H^[[38;2;229;215;22mM-bM-^VM-^H^[[38;2;241;227;22mM-bM-^VM-^H^[[38;2;240;226;21mM-bM-^VM-^H^[[38;2;224;211;22mM-bM-^VM-^H^[[38;2;202;190;22mM-bM-^VM-^H^[[38;2;240;225;21mM-bM-^VM-^H^[[38;2;230;216;22mM-bM-^VM-^H^[[38;2;192;180;22mM-bM-^VM-^H^[[38;2;189;178;19mM-bM-^VM-^H^[[38;2;189;177;18mM-bM-^VM-^H^[[38;2;203;191;17mM-bM-^VM-^H^[[38;2;228;215;18mM-bM-^VM-^H^[[38;2;189;177;18mM-bM-^VM-^H^[[38;2;196;184;19mM-bM-^VM-^H^[[38;2;237;223;16mM-bM-^VM-^H^[[38;2;237;223;16mM-bM-^VM-^H^[[38;2;238;223;17mM-bM-^VM-^H^[[38;2;237;223;15mM-bM-^VM-^H^[[38;2;145;135;18mM-bM-^VM-^H^[[38;2;106;98;16mM-bM-^VM-^H^[[38;2;203;193;18mM-bM-^VM-^H^[[38;2;223;211;16mM-bM-^VM-^H^[[38;2;188;177;18mM-bM-^VM-^H^[[38;2;200;189;18mM-bM-^VM-^H^[[38;2;231;218;17mM-bM-^VM-^H^[[38;2;188;177;18mM-bM-^VM-^H^[[38;2;200;188;18mM-bM-^VM-^H^[[38;2;205;193;19mM-bM-^VM-^H^[[38;2;188;177;18mM-bM-^VM-^H^[[38;2;235;222;16mM-bM-^VM-^H^[[38;2;236;223;16mM-bM-^VM-^H^[[38;2;208;196;17mM-bM-^VM-^H^[[38;2;209;196;16mM-bM-^VM-^H^[[38;2;236;223;16mM-bM-^VM-^H^[[38;2;236;222;16mM-bM-^VM-^H^[[38;2;236;222;16mM-bM-^VM-^H^[[38;2;239;225;18mM-bM-^VM-^H^[[38;2;196;185;18mM-bM-^VM-^H^[[38;2;114;108;19mM-bM-^VM-^H^[[38;2;120;113;19mM-bM-^VM-^H^[[38;2;218;206;19mM-bM-^VM-^H^[[38;2;222;210;19mM-bM-^VM-^H^[[38;2;189;178;18mM-bM-^VM-^H^[[38;2;203;192;20mM-bM-^VM-^H^[[38;2;228;215;16mM-bM-^VM-^H^[[38;2;188;178;18mM-bM-^VM-^H^[[38;2;202;191;17mM-bM-^VM-^H^[[38;2;202;191;17mM-bM-^VM-^H^[[38;2;191;181;20mM-bM-^VM-^H^[[38;2;227;215;17mM-bM-^VM-^H^[[38;2;189;178;18mM-bM-^VM-^H^[[38;2;198;187;18mM-bM-^VM-^H^[[38;2;204;193;18mM-bM-^VM-^H^[[38;2;189;178;18mM-bM-^VM-^H^[[38;2;181;167;29mM-bM-^VM-^H^[[38;2;22;5;52mM-bM-^VM-^H^[[38;2;22;5;51mM-bM-^VM-^H^[[0m

```
