# Lesson 001 – Images Are Memory

## Objective

Understand how images are represented in computer memory and develop an intuition for the relationship between image data structures, memory allocation, and pixel storage.

---

## Core Idea

An image is not a picture.

An image is a block of memory together with metadata that describes how that memory should be interpreted.

Before exploring image processing algorithms, it is important to understand how image data is stored and accessed.

---

## Representing an Image

A simple grayscale image can be represented using a structure:

```c
typedef struct
{
    int width;
    int height;
    unsigned char* data;
} Image;
```

Where:

* `width` = number of pixels per row
* `height` = number of rows
* `data` = pointer to the first pixel

The structure stores information about the image.

The actual pixel data is stored elsewhere in memory.

---

## Metadata vs Pixel Data

The image structure contains metadata:

```text
Image
├── Width
├── Height
└── Data Pointer
```

The image pixels themselves are stored separately.

The data pointer stores the memory address of the first pixel.

---

## Stack Memory

Creating an image structure:

```c
Image img;
```

allocates memory on the stack.

Example:

```text
img address        = 0x16fdfef00
img.width address  = 0x16fdfef00
img.height address = 0x16fdfef04
img.data address   = 0x16fdfef08
```

This demonstrates how the structure members are arranged sequentially in memory.

---

## Structure Layout

On a 64-bit machine:

```text
Offset    Member

0         width
4         height
8         data pointer
```

Visual representation:

```text
0x16fdfef00    width
0x16fdfef04    height
0x16fdfef08    data pointer
```

The structure itself occupies only a small amount of memory.

---

## The Data Pointer

The following declaration:

```c
unsigned char* data;
```

creates a pointer variable.

It does not create image memory.

At this point:

```text
data
```

can only store an address.

No pixels exist yet.

---

## Memory Allocation

Pixel memory is allocated separately:

```c
img.data = malloc(img.width * img.height);
```

For a 640 × 480 image:

```text
640 × 480 = 307,200 pixels
```

A grayscale image stores one byte per pixel:

```text
307,200 bytes
```

must therefore be allocated.

The returned address is stored inside:

```c
img.data
```

---

## Stack vs Heap

After allocation:

```text
Stack

Image
├── width = 640
├── height = 480
└── data = 0x5000
```

```text
Heap

0x5000 -> Pixel 0
0x5001 -> Pixel 1
0x5002 -> Pixel 2
...
```

The stack contains image information.

The heap contains the image itself.

---

## Pixels as Numbers

A grayscale image stores intensity values:

```text
0     = Black
128   = Grey
255   = White
```

Example:

```c
img.data[0] = 0;
img.data[1] = 128;
img.data[2] = 255;
```

---

## One-Dimensional Memory

Images are often thought of as two-dimensional objects.

However, in memory they are stored as a one-dimensional array.

Example:

```text
Width = 4
Height = 3
```

Memory:

```text
10 20 30 40
50 60 70 80
90 100 110 120
```

is actually stored as:

```text
10 20 30 40 50 60 70 80 90 100 110 120
```

---

## Pixel Addressing

A pixel coordinate:

```text
x = 100
y = 50
```

can be converted to a memory index using:

```c
index = y * width + x;
```

Accessing the pixel:

```c
unsigned char pixel =
    img.data[index];
```

or

```c
unsigned char pixel =
    img.data[y * img.width + x];
```

---

## Key Observations

1. The image structure is not the image.
2. The image structure contains metadata.
3. Pixel memory must be allocated separately.
4. Images are stored as a one-dimensional block of memory.
5. Pixel coordinates are converted into memory indices.
6. All image processing algorithms ultimately operate on numbers stored in memory.

---

## Practical Exercise

1. Create an Image structure.
2. Print the address of the structure.
3. Print the address of each member.
4. Allocate pixel memory.
5. Print the address stored in `img.data`.
6. Fill the image with zeros.
7. Save or display the result.
8. Change selected pixels and observe the output.

---

## Lesson Summary

The most important concept introduced in this lesson is:

> An image is not a picture. An image is a block of memory containing numbers.

Understanding this concept provides the foundation for every image processing and machine vision algorithm that follows.
