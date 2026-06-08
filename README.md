# Vision Fundamentals Playground

A hands-on machine vision playground built in C to explore image processing fundamentals from first principles.

The purpose of this project is to develop a deep understanding of how images are represented, manipulated, and analysed at the lowest level.

Rather than relying on pre-exisitng vision frameworks, we will progressively build fundamental image processing algorithms from scratch, including thresholding, connected components, edge detection, shape matching, and feature extraction.

---

# Why This Project Exists

Modern machine vision frameworks make it easy to solve problems quickly.

However, many engineers never develop an intuitive understanding of what is happening beneath the abstraction layers.

This project aims to bridge that gap by exploring machine vision fundamentals from the ground up.

The objective is to understand:

* How images are stored in memory
* How pixels are represented
* How image processing operators work internally
* How machine vision algorithms are built
* How industrial vision systems ultimately make decisions

---

# Learning Roadmap

## Lesson 001 – Images Are Memory

Topics:

* Stack memory
* Heap memory
* Structures
* Pointers
* Image metadata
* Pixel buffers
* Memory layout

Status: In Progress

---

## Lesson 002 – Creating Synthetic Images

Topics:

* Black images
* White images
* Gradients
* Drawing primitives
* Coordinate systems

Status: Planned

---

## Lesson 003 – Thresholding

Topics:

* Binary segmentation
* Pixel classification
* Building HALCON's threshold() operator

Status: Planned

---

## Lesson 004 – Connected Components

Topics:

* Blob analysis
* Flood fill
* Region labelling
* Connected component extraction

Status: Planned

---

## Lesson 005 – Edge Detection

Topics:

* Sobel
* Prewitt
* Gradient magnitude
* Gradient direction

Status: Planned

---

## Lesson 006 – Canny Edge Detection

Topics:

* Gaussian filtering
* Non-maximum suppression
* Double thresholding
* Hysteresis

Status: Planned

---

## Lesson 007 – Shape Matching

Topics:

* Correlation
* Template matching
* Rotation invariance
* Industrial applications

Status: Planned

---

# Lesson 001 – Images Are Memory

## Core Idea

An image is not a picture.

An image is a block of memory together with metadata that describes how that memory should be interpreted.

A grayscale image can be represented by three fundamental pieces of information:

```c
typedef struct
{
    int width;
    int height;
    unsigned char* data;
} Image;
```

Where:

* width = number of pixels per row
* height = number of rows
* data = pointer to the first pixel in memory

---

## Metadata vs Pixel Data

The Image structure stores metadata only.

```text
Image
├── Width
├── Height
└── Data Pointer
```

The actual pixel data is stored elsewhere in memory.

The data pointer simply stores the address of the first pixel.

---

## Stack Memory

Creating an image structure:

```c
Image img;
```

allocates memory on the stack.

Example addresses:

```text
img address        = 0x16fdfef00
img.width address  = 0x16fdfef00
img.height address = 0x16fdfef04
img.data address   = 0x16fdfef08
```

This demonstrates how the structure members are laid out sequentially in memory.

The Image structure itself occupies only a small amount of memory.

It does not contain the actual image pixels.

---

## Heap Memory

Pixel memory is typically allocated on the heap:

```c
img.data = malloc(img.width * img.height);
```

For a 640 × 480 image:

```text
640 × 480 = 307,200 pixels
```

Since each grayscale pixel occupies one byte:

```text
307,200 bytes
```

must be allocated.

The address of the first pixel is then stored in:

```c
img.data
```

---

## Visualising Memory

Before allocation:

```text
Stack

Image
├── width
├── height
└── data = NULL
```

After allocation:

```text
Stack

Image
├── width = 640
├── height = 480
└── data = 0x5000

Heap

0x5000 -> Pixel 0
0x5001 -> Pixel 1
0x5002 -> Pixel 2
...
```

The Image structure stores information about the image.

The heap stores the actual image.

---

## Pixel Addressing

Images are stored as a one-dimensional block of memory.

A pixel coordinate:

```text
x = 100
y = 50
```

is converted to a memory location using:

```c
index = y * width + x;
```

Example:

```c
unsigned char pixel =
    img.data[y * img.width + x];
```

This is how individual pixels are accessed.

---

## What HALCON Does

HALCON hides these implementation details.

When an image is loaded:

```hdevelop
read_image(Image, 'test.png')
```

HALCON internally manages:

* Image metadata
* Memory allocation
* Pixel storage
* Reference counting
* Object lifetime

The HObject acts as a handle to an internal image representation.

---

## Key Takeaway

One of the most important concepts in machine vision is:

> An image is not a picture. An image is a block of memory containing numbers.

Everything else in machine vision — thresholding, blob analysis, edge detection, shape matching, feature extraction, and AI — is built upon this foundation.

Understanding image memory is the first step toward understanding how computer vision systems actually work.
