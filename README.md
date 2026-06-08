# Vision Fundamentals Playground

A hands-on exploration of machine vision and image processing fundamentals using C.

This repository documents a journey into understanding computer vision from first principles by exploring how images are represented, manipulated, and analysed at the lowest level.

The goal is not to recreate existing vision libraries or production frameworks. Instead, the focus is on developing intuition through experimentation, visualisation, and practical implementation of core concepts.

> An image is not a picture. An image is a block of memory containing numbers.

---

# Why This Project Exists

Modern machine vision tools make it possible to solve complex problems very quickly. While this is extremely powerful, it can sometimes hide the underlying concepts that make those solutions possible.

This project is a personal learning playground designed to explore:

* How images are stored in memory
* How pixels are represented and manipulated
* How image processing algorithms operate
* How features are extracted from images
* How machine vision systems ultimately make decisions

The objective is to develop a deeper understanding of image processing fundamentals through practical experimentation and implementation.

---

# Learning Philosophy

This repository is intentionally focused on learning and curiosity.

The emphasis is on:

* Building intuition
* Understanding fundamentals
* Visualising intermediate results
* Exploring concepts through experimentation
* Documenting lessons learned

The project is not intended to become a production vision framework.

---

# Repository Structure

```text
vision-fundamentals-playground/
│
├── README.md
├── Makefile
│
├── src/
│   ├── main.c
│   ├── image.c
│   ├── image.h
│   ├── pgm.c
│   └── pgm.h
│
├── lessons/
│   └── 001_image_memory/
│       ├── README.md
│       └── lesson_001_image_memory.c
│
├── notes/
│   └── 001_images_are_memory.md
│
├── images/
│
├── output/
│
└── build/
```

---

# Learning Roadmap

## Lesson 001 – Images Are Memory

Topics:

* Structures
* Stack memory
* Heap memory
* Pointers
* Image metadata
* Pixel buffers
* Memory layout

Status: Complete

---

## Lesson 002 – Creating Synthetic Images

Topics:

* Black images
* White images
* Gradients
* Geometric primitives
* Coordinate systems

Status: Planned

---

## Lesson 003 – Thresholding

Topics:

* Binary segmentation
* Pixel classification
* Threshold operations

Status: Planned

---

## Lesson 004 – Connected Components

Topics:

* Flood fill
* Region labelling
* Blob analysis
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

## Lesson 007 – Shape Representation

Topics:

* Contours
* Boundaries
* Moments
* Shape descriptors

Status: Planned

---

## Lesson 008 – Template Matching

Topics:

* Correlation
* Similarity measures
* Search strategies
* Pattern matching

Status: Planned

---

## Lesson 009 – Feature Extraction

Topics:

* Local features
* Texture features
* Shape features
* Statistical descriptors

Status: Planned

---

## Lesson 010 – Foundations of Machine Learning

Topics:

* Feature vectors
* Classification
* Training data
* Decision boundaries

Status: Planned

---
