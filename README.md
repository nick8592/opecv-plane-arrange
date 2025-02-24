# OpenCV Plane Arrange Example

This program demonstrates the basic concept of combining multiple image "planes" into a single screen. It simulates a system where multiple layers of images (planes) are drawn onto a screen buffer. Each plane is positioned at specific coordinates, and the screen buffer is updated by copying pixel data from the planes. The program uses OpenCV to visualize the combined result.

### Key Concepts
- **Plane**: Represents an image with defined width, height, and pixel data. Each plane can be placed at specific screen coordinates (offsets).
- **Screen**: A large image buffer (1920x1080) where planes are drawn at specific positions.
- **OpenCV**: Used to display the final result of the combined planes.

## Requirements

To compile and run this program, you need the following:

1. **C++ Compiler** (e.g., g++).
2. **OpenCV**: A computer vision library used for handling images and displaying results. Install OpenCV on your machine before building the program.

To install OpenCV on Ubuntu:
```bash
sudo apt-get update
sudo apt-get install libopencv-dev
```

## Code Explanation

### Constants

- **SCREEN_WIDTH** and **SCREEN_HEIGHT** define the resolution of the screen buffer (1920x1080).
- **PLANE1_WIDTH**, **PLANE1_HEIGHT**, **PLANE2_WIDTH**, **PLANE2_HEIGHT**, **PLANE3_WIDTH**, and **PLANE3_HEIGHT** define the sizes of the three image planes.

### `Plane` Structure

This structure defines the properties of a plane:
- `width`, `height`: Dimensions of the plane.
- `data`: A dynamically allocated array holding the pixel data (RGB format).
- `offsetX`, `offsetY`: The top-left coordinates where the plane will be drawn on the screen.

The constructor allocates memory for the plane's pixel data, and the destructor frees that memory when the plane is no longer needed.

### `clearScreen` Function

This function clears the screen by filling it with a white color (RGB: 255, 255, 255).

### `drawPlane` Function

This function draws the contents of a plane onto the screen at the plane's specified `offsetX` and `offsetY`. It iterates through each pixel of the plane and copies the corresponding pixel values to the screen buffer.

### `main` Function

- **Screen Buffer**: A `unsigned char` array is used to represent the screen.
- **Planes**: Three planes are created with different sizes and colors (white, black, and gray).
- **Offsets**: The positions of the planes are set so that they don't overlap on the screen.
- **Plane Data**: The plane data is initialized with simple colors using `std::memset`.
- **Drawing**: Each plane is drawn to the screen using `drawPlane`.
- **OpenCV Visualization**: The screen buffer is converted to an OpenCV `Mat` object for display, and the final image is shown in a window using OpenCV's `imshow`.

After displaying the window, the program waits for a key press before closing the window.

### Clean Up

The dynamically allocated memory for the screen and planes is freed before the program exits.

## How to Compile

1. Clone this repository.

```bash
git clone https://github.com/nick8592/opecv_plane_arrange.git
```
2. Navigate to the directory.

```bash
cd opecv-plane-arrange
```
3. To compile the code, use the following command:

```bash
g++ -o display_planes display_planes.cpp `pkg-config --cflags --libs opencv4`
```

This command compiles the C++ code and links it with OpenCV libraries.

4. Run the compiled program:

```bash
./display_planes
```

You should see a window with the combined planes drawn on the screen.

## Results

Once the program is run, the OpenCV window will display the screen with the three planes drawn at their specified offsets:
- Plane 1 (White) will appear at the top-left of the screen.
- Plane 2 (Black) will appear below Plane 1.
- Plane 3 (Gray) will appear to the right of Plane 1.

![planes_img.png](planes_img.png)
