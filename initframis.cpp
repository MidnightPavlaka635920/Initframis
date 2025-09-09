/*#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string.h>

int TH = 0; // terminal height in rows

void processFrameBlock(cv::Mat &frame, int bx, int by, int blockWidth, int blockHeight, FILE *out, const char* tOP) {
    // Each terminal row encodes 2 vertical pixel blocks
    int yTopStart = by * blockHeight * 2;
    int yBottomStart = yTopStart + blockHeight;

    unsigned int rTop=0, gTop=0, bTop=0;
    unsigned int rBottom=0, gBottom=0, bBottom=0;
    unsigned int countTop=0, countBottom=0;

    // Top half
    for(int y = yTopStart; y < yTopStart + blockHeight && y < frame.rows; y++) {
        for(int x = bx*blockWidth; x < (bx+1)*blockWidth && x < frame.cols; x++) {
            cv::Vec3b color = frame.at<cv::Vec3b>(y,x);
            bTop += color[0]; gTop += color[1]; rTop += color[2];
            countTop++;
        }
    }

    // Bottom half
    for(int y = yBottomStart; y < yBottomStart + blockHeight && y < frame.rows; y++) {
        for(int x = bx*blockWidth; x < (bx+1)*blockWidth && x < frame.cols; x++) {
            cv::Vec3b color = frame.at<cv::Vec3b>(y,x);
            bBottom += color[0]; gBottom += color[1]; rBottom += color[2];
            countBottom++;
        }
    }

    // Compute averages
    if(countTop>0) { rTop/=countTop; gTop/=countTop; bTop/=countTop; }
    if(countBottom>0) { rBottom/=countBottom; gBottom/=countBottom; bBottom/=countBottom; }

    if(strcmp(tOP, "h") == 0){
        // Half-block mode: top = foreground, bottom = background
        fprintf(out, "\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm▀",
                rTop, gTop, bTop, rBottom, gBottom, bBottom);
    } else if(strcmp(tOP, "f") == 0){
        // Full-block mode: use average of top+bottom
        unsigned int rC = (rTop + rBottom)/2;
        unsigned int gC = (gTop + gBottom)/2;
        unsigned int bC = (bTop + bBottom)/2;
        fprintf(out, "\033[38;2;%d;%d;%dm█", rC, gC, bC);
    }
}

int main(int argc, char **argv) {
    if(argc < 5) {
        printf("Usage: %s <video_file> <desiredWidth> <output.full> <mode: h|f>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    int desiredWidth = atoi(argv[2]);
    const char* outFileName = argv[3];
    const char* typeOfPixels = argv[4];

    cv::VideoCapture cap(filename);
    if(!cap.isOpened()) { printf("Cannot open video %s\n", filename); return 1; }

    FILE *out = fopen(outFileName,"w");
    if(!out) { printf("Cannot open output %s\n", outFileName); return 1; }

    cv::Mat frame;
    int totalFrames = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_COUNT));
    int frameCount = 0;

    while(true) {
        cap >> frame;
        if(frame.empty()) break;

        int videoWidth  = frame.cols;
        int videoHeight = frame.rows;
        float aspectRatio = static_cast<float>(videoWidth)/videoHeight;

        int blockWidth = videoWidth / desiredWidth;
        int termHeight = static_cast<int>(desiredWidth / aspectRatio /2);
        int blockHeight = videoHeight / (termHeight * 2); // half-block mode

        TH = termHeight;

        // Loop over terminal rows
        for(int by=0; by<termHeight; by++) {
            for(int bx=0; bx<desiredWidth; bx++) {
                processFrameBlock(frame, bx, by, blockWidth, blockHeight, out, typeOfPixels);
            }
            fprintf(out, "\033[0m\n"); // reset colors + newline
        }

        printf("\033[H\033[J"); // clear console
        printf("Processing frame %d of %d\n", frameCount+1, totalFrames);
        frameCount++;
    }

    printf("Video Height: %d\n", TH);
    fclose(out);
    return 0;
}
*/
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>

int TH = 0; // terminal height in rows

void showHelp(const char* progName) {
    std::cout << "Usage: " << progName << " <video_file> <desiredWidth> <output.full> <mode: h|f>\n\n"
              << "Options:\n"
              << "  -h, --help        Show this help message and exit\n"
              << "  -v, --version     Show program version and exit\n\n"
              << "Arguments:\n"
              << "  video_file        Input video file to process\n"
              << "  desiredWidth      Width (in terminal characters)\n"
              << "  output.full       Output file (text with ANSI colors)\n"
              << "  mode              'h' = half-blocks (▀), 'f' = full-blocks (█)\n\n"
              << "Example:\n"
              << "  " << progName << " demo.mp4 80 output.txt h\n";
}

void showVersion() {
    std::cout << "initframis 1.0 (Video to ANSI renderer)\n";
}

void processFrameBlock(cv::Mat &frame, int bx, int by, int blockWidth, int blockHeight, FILE *out, const char* tOP) {
    int yTopStart = by * blockHeight * 2;
    int yBottomStart = yTopStart + blockHeight;

    unsigned int rTop=0, gTop=0, bTop=0;
    unsigned int rBottom=0, gBottom=0, bBottom=0;
    unsigned int countTop=0, countBottom=0;

    // Top half
    for(int y = yTopStart; y < yTopStart + blockHeight && y < frame.rows; y++) {
        for(int x = bx*blockWidth; x < (bx+1)*blockWidth && x < frame.cols; x++) {
            cv::Vec3b color = frame.at<cv::Vec3b>(y,x);
            bTop += color[0]; gTop += color[1]; rTop += color[2];
            countTop++;
        }
    }

    // Bottom half
    for(int y = yBottomStart; y < yBottomStart + blockHeight && y < frame.rows; y++) {
        for(int x = bx*blockWidth; x < (bx+1)*blockWidth && x < frame.cols; x++) {
            cv::Vec3b color = frame.at<cv::Vec3b>(y,x);
            bBottom += color[0]; gBottom += color[1]; rBottom += color[2];
            countBottom++;
        }
    }

    // Compute averages
    if(countTop>0) { rTop/=countTop; gTop/=countTop; bTop/=countTop; }
    if(countBottom>0) { rBottom/=countBottom; gBottom/=countBottom; bBottom/=countBottom; }

    if(strcmp(tOP, "h") == 0){
        fprintf(out, "\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm▀",
                rTop, gTop, bTop, rBottom, gBottom, bBottom);
    } else if(strcmp(tOP, "f") == 0){
        unsigned int rC = (rTop + rBottom)/2;
        unsigned int gC = (gTop + gBottom)/2;
        unsigned int bC = (bTop + bBottom)/2;
        fprintf(out, "\033[38;2;%d;%d;%dm█", rC, gC, bC);
    }
}

int main(int argc, char **argv) {
    // Handle help/version first
    if(argc > 1) {
        if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            showHelp(argv[0]);
            return 0;
        }
        if(strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
            showVersion();
            return 0;
        }
    }

    if(argc < 5) {
        showHelp(argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    int desiredWidth = atoi(argv[2]);
    const char* outFileName = argv[3];
    const char* typeOfPixels = argv[4];

    cv::VideoCapture cap(filename);
    if(!cap.isOpened()) { printf("Cannot open video %s\n", filename); return 1; }

    FILE *out = fopen(outFileName,"w");
    if(!out) { printf("Cannot open output %s\n", outFileName); return 1; }

    cv::Mat frame;
    int totalFrames = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_COUNT));
    int frameCount = 0;

    while(true) {
        cap >> frame;
        if(frame.empty()) break;

        int videoWidth  = frame.cols;
        int videoHeight = frame.rows;
        float aspectRatio = static_cast<float>(videoWidth)/videoHeight;

        int blockWidth = videoWidth / desiredWidth;
        int termHeight = static_cast<int>(desiredWidth / aspectRatio /2);
        int blockHeight = videoHeight / (termHeight * 2);

        TH = termHeight;

        for(int by=0; by<termHeight; by++) {
            for(int bx=0; bx<desiredWidth; bx++) {
                processFrameBlock(frame, bx, by, blockWidth, blockHeight, out, typeOfPixels);
            }
            fprintf(out, "\033[0m\n");
        }

        //printf("\033[H\033[J"); // clear console
        //printf("Processing frame %d of %d\n", frameCount+1, totalFrames);
        std::cout << "Processed frame " << frameCount << "\r" << std::flush;
        frameCount++;
    }

    printf("Video Height: %d\n", TH);
    fclose(out);
    return 0;
}
