# Embedding information in images

> Team Member 1 (Majd Hafiri) ,Team Member 2 (Vipin Koshy Thomas)

## Overview
**Use case 1**: We want to create an IP which can curb Intelluctual property theft using Stegnography alogorithms(LSB - bit manipulation). By this, each images will be having a secret Identifier embedded in it, which can be used to check the ownership.

**Use Case 2**: This can also be used between two parties who want to exchange secret information through images by changing pixel values.

## Background
**Use Case 1** : 
Since Intelluctual property theft is becoming a common act in current world scenario, companies or authorities can use this ip to embed secret identifiers in their media productions. So that we can easily identify plagarized images by checking the byte data. Doing small changes to the values for some pixels of one colour image won't be possible for human eyes to see those modified pixels but It is possible to do it on a software. These modified pixels represent a message somehow.


**Use Case 2** : 
Doing small changes to the values for some pixels of an image won't be possible for human eyes to see those modified pixels but It is possible to do it on a software. These modified pixels represent a message somehow.


## Implementation Strategy

Use Case 1: 

Use Case 1: once decided on the area for embedding information we can use follow bit manipulation technique 

![images_bg1](https://miro.medium.com/max/2006/0*JTnkzopCLv2cRLuY.jpg)
![images_bg2](https://miro.medium.com/max/875/0*XWlQVMlAQra2KHSB.jpg)


image credits: [wikimedia](https://en.wikipedia.org/wiki/Bit_numbering#mediaviewer/File:Least_significant_bit.svg) , [technicalfoundation](https://technical-foundation.blogspot.com/2017/11/steganography-hide-data-in-images-with.html)


Use Case 2: 
In order for both parties to agree on the secret, An algorithm must be implemented. This Algorithm accepts the user message and change some pixels values of an Image. Pixel values modification is based on a specific criteria (not decided yet). For example , If the sender wants to send the number "5" as a secret message , The algorithm could change 5 pixel values in the image which makes these 5 pixels have a unique value. and in the receiver part , the algorithm will calculate the number of modified pixels and identify the sender message.




## Tasks
*This section is the most important because it gives us a sense of the scope of your project and forces you to think about the deliverables to which you'll hold yourself.*

1. Setting the pixel area for embedding the secret identifier through register map.
2. Sending the images bytes as stream
3. udpating or manipulating the pixels



## Resources
PYNQ-Z2 

Jupyter Notebook

Xlinix Documention
