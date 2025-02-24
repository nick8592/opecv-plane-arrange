#include <iostream>
#include <cstring>
#include <opencv2/opencv.hpp>  // Include OpenCV header

// Define screen dimensions
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

// Define plane sizes
#define PLANE1_WIDTH 1280
#define PLANE1_HEIGHT 720

#define PLANE2_WIDTH 1280
#define PLANE2_HEIGHT 360

#define PLANE3_WIDTH 640
#define PLANE3_HEIGHT 1080

// Define a simple structure for representing an image (plane)
struct Plane {
    int width;
    int height;
    unsigned char* data;
    int offsetX;
    int offsetY;

    Plane(int w, int h) : width(w), height(h), offsetX(0), offsetY(0) {
        // Allocate memory for image data
        data = new unsigned char[width * height * 3]; // RGB color space
    }

    ~Plane() {
        // Free the memory allocated for the image data
        delete[] data;
    }
};

// Function to clear the screen memory (set to white for simplicity)
void clearScreen(unsigned char* screen) {
    std::memset(screen, 255, SCREEN_WIDTH * SCREEN_HEIGHT * 3); // White screen (RGB 255, 255, 255)
}

// Function to copy plane data to the screen at a specific position
void drawPlane(unsigned char* screen, Plane& plane) {
    for (int y = 0; y < plane.height; ++y) {
        for (int x = 0; x < plane.width; ++x) {
            int screenX = plane.offsetX + x;
            int screenY = plane.offsetY + y;

            if (screenX < SCREEN_WIDTH && screenY < SCREEN_HEIGHT) {
                int screenIndex = (screenY * SCREEN_WIDTH + screenX) * 3; // Calculate the index in screen memory
                int planeIndex = (y * plane.width + x) * 3; // Calculate the index in plane data

                // Copy the RGB data from the plane to the screen
                screen[screenIndex] = plane.data[planeIndex];
                screen[screenIndex + 1] = plane.data[planeIndex + 1];
                screen[screenIndex + 2] = plane.data[planeIndex + 2];
            }
        }
    }
}

int main() {
    // Create a screen buffer (1920x1080 resolution with RGB data)
    unsigned char* screen = new unsigned char[SCREEN_WIDTH * SCREEN_HEIGHT * 3];

    // Create planes
    Plane plane1(PLANE1_WIDTH, PLANE1_HEIGHT); // Plane 1 (1280x720)
    Plane plane2(PLANE2_WIDTH, PLANE2_HEIGHT); // Plane 2 (1280x360)
    Plane plane3(PLANE3_WIDTH, PLANE3_HEIGHT); // Plane 3 (640x1080)

    // Set plane positions (offsets)
    plane1.offsetX = 0; // Top-left corner
    plane1.offsetY = 0;

    plane2.offsetX = 0; // Bottom-left corner
    plane2.offsetY = PLANE1_HEIGHT; // Starts just below plane 1

    plane3.offsetX = PLANE1_WIDTH; // Right side
    plane3.offsetY = 0;

    // Fill the planes with some colors (just for illustration)
    std::memset(plane1.data, 255, PLANE1_WIDTH * PLANE1_HEIGHT * 3); // White
    std::memset(plane2.data, 0, PLANE2_WIDTH * PLANE2_HEIGHT * 3);   // Black
    std::memset(plane3.data, 128, PLANE3_WIDTH * PLANE3_HEIGHT * 3); // Gray

    // Clear the screen (set it to white initially)
    clearScreen(screen);

    // Draw each plane to the screen at its respective position
    drawPlane(screen, plane1);
    drawPlane(screen, plane2);
    drawPlane(screen, plane3);

    // Convert the screen buffer to an OpenCV Mat (RGB format)
    cv::Mat mat(SCREEN_HEIGHT, SCREEN_WIDTH, CV_8UC3, screen);

    // Show the result using OpenCV
    cv::imshow("Screen with Planes", mat);
    cv::waitKey(0); // Wait for a key press before closing

    // Clean up
    delete[] screen;

    return 0;
}
