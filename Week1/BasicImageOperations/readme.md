## Basic Image Operations
# Demos of:
* creating new images
* cropping an image section
* copying a region to another
* resizing
* creating an image mask

# How to run
OpenCV libs, cmake, VS19 (or some version) need to be installed.
To build & run in root dir either at:
**Command prompt**
* mkdir results
* mkdir build
* cd build
* cmake -G "Visual Studio 16 2019" ..
* cmake --build . --config Release
* cd ..
* .\build\Release\BasicImageOps.exe

Or just type "run.bat".

**Shell**
mkdir results
mkdir build
cd build
cmake -G "Visual Studio 16 2019" ..
cmake --build . --config Release
cd ..
./build/Release/BasicImageOps.exe

Or just type "sh run.sh".

This has been tested in Windows 10 and compiled/linked/ran as of my commit using both the above methods. Although I prefer Linux, it was not tested here.

# Source Code
TestApp is the driver and I started to abstract duplicate functionality / repetitive code into Utilities. It's a work in progress. 

# Sample output
This shows an example of cropping, copying a region of interest and creting a mask.

![Cropped image](crop.png cropped image)
![ROI copied](copiedRegions.png region of interest copied)
![Creating a mask](mask2.png creating a mask)