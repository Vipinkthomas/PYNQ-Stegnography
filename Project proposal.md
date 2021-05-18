# Intelluctual Property Identifier for images

> Team Member 1 (Majd Hafiri) ,Team Member 2 (Vipin Koshy Thomas)

## Overview
**Use case 1**: We want to create an IP which can curb Intelluctual property theft using Stegnography alogorithms(LSB - bit manipulation). By this, each images will be having a secret Identifier embedded in it, which can be used to check the ownership.

**Use Case 2**: This can also be used between two parties who want to exchange secret information through images.

## Background
**Use Case 1** : 
Since Intelluctual property theft is becoming a common act in current world scenario, companies or authorities can use this ip to embed secret identifiers in their media productions. So that we can easily identify plagarized images by checking the byte data. Doing small changes to the values for some pixels of one colour image won't be possible for human eyes to see those modified pixels but It is possible to do it on a software. These modified pixels represent a message somehow.

![images_bg1](https://miro.medium.com/max/2006/0*JTnkzopCLv2cRLuY.jpg)
![images_bg2](https://miro.medium.com/max/875/0*XWlQVMlAQra2KHSB.jpg)


image credits: [wikimedia](https://en.wikipedia.org/wiki/Bit_numbering#mediaviewer/File:Least_significant_bit.svg) , [technicalfoundation](https://technical-foundation.blogspot.com/2017/11/steganography-hide-data-in-images-with.html)


**Use Case 2** :In order to 
Doing small changes to the values for some pixels of one colour image won't be possible for human eyes to see those modified pixels but It is possible to do it on a software. These modified pixels represent a message somehow.


## Implementation Strategy

Use Case 1:

Use Case 2: 
In order for both parties to agree on the secret, An algorithm must be implemented. This Algorithm accepts the user message and change some pixels values of an Image. Pixel values modification is based on a specific criteria (not decided yet). For example , If the sender wants to send the number "5" as a secret message , The algorithm could change 5 pixel values in the one color image and in the receiver part , the algorithm will calculate the number of modified pixels.

How it works:



## Tasks
*This section is the most important because it gives us a sense of the scope of your project and forces you to think about the deliverables to which you'll hold yourself.*

Break down your project into a sequence of small tasks that you can feasibly accomplish to incrementally build towards a complete working project.

Include at least three stretch goals. A *stretch goal* is an extension that you think would be really awesome, but would probably be outside the scope of the final project.

What tasks do you think will be easy? What tasks do you think will be hard? Tedious? Trivial? Give us a sense of your current outlook on these project tasks.

Annotate each of the tasks (including stretch goals) with an estimate for how long you believe the task will take you. If you're in a group, also annotate each task with the names of anyone responsible for the task.

If you've already accomplished some of the tasks, make a note of it! If you're incorporating a final project for another class into this final project, you'll be held to a higher standard of quality and quantity, so make a note of that too.

This task list isn't binding - you can change your mind, modify tasks, etc - but it's a good starting point to organize incremental development.


## Resources
*This section is smaller and less vital than the others. If you're not using any external resources, you can leave this blank.*

What external resources will you be working with? If you are working with a dataset, how will you acquire the data set? If you're publishing some project (e.g. web app), how will you host your project? If your project requires hardware, how will you get it? Are there any other resources you need to acquire before starting?
