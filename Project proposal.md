# Embedding information in images

> Team Member 1 (Majd Hafiri) ,Team Member 2 (Vipin Koshy Thomas)

## Overview
We want to create an IP which can curb Intelluctual property theft using Stegnography alogorithms(LSB - bit manipulation). By this, each image will be having a secret Identifier embedded in it which is not visible to human eyes, which can be used to check the ownership.


## Background

Since Intelluctual property theft is becoming a common act in current world scenario, companies or authorities can use this ip to embbed secret identifiers in their media productions. So that they can easily identify plagarized images by checking the byte data. Doing small changes to the values for some pixels of the image won't be possible for human eyes to see those modified pixels but It is possible to do it on a software and hardware. These modified pixels represent a message somehow.


## Implementation Strategy

First of all, After passing the image to the FPGA , the FPGA will change some pixel values at some positions(will be specified by the user or randomly). The values of the chosen pixels (Least significant bit ) will be changed by some kind of mathematical operation. Then the modified image will be pushed back to the software in order to be sent or saved. Another overlay should be created which represents the the receiving part which verifies the ownership. This is done by passing the copy righted image to the FPGA as streams of pixels and calculate the number of modified pixels.

once decided on the pixel positions for embedding information we can use the following bit manipulation technique:

![images_bg1](https://miro.medium.com/max/2006/0*JTnkzopCLv2cRLuY.jpg)
![images_bg2](https://miro.medium.com/max/875/0*XWlQVMlAQra2KHSB.jpg)


image credits: [wikimedia](https://en.wikipedia.org/wiki/Bit_numbering#mediaviewer/File:Least_significant_bit.svg) , [technicalfoundation](https://technical-foundation.blogspot.com/2017/11/steganography-hide-data-in-images-with.html)




## Tasks

1. Setting the pixel area for embedding the secret identifier through register map.
2. Sending the images bytes as stream
3. udpating or manipulating the pixels using LSB manipulation alogorithms

## Time Distribution

Brainstorming : 10hrs

Alogorithm : 12 hrs

Overlay Synthesis : 6 hrs

Optimization : 6 hrs

Python : 8 hrs

Documention : 5hrs

## Resources
PYNQ-Z2 

Jupyter Notebook

Xlinix Documention

Image Libraries
