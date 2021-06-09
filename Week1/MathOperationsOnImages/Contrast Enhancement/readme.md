## Contrast Enhancement
# Demos of:
* contrast enhance --> I (output) = alpha * I (input) - simplest way is scaling

Contrast is the intensity difference of the brightest & darkest regions of which the max difference is called dynamic range.

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
* .\build\Release\ContrastEnhance.exe

Or just type "run.bat".

**Shell**

* mkdir results
* mkdir build
* cd build
* cmake -G "Visual Studio 16 2019" ..
* cmake --build . --config Release
* cd ..
./build/Release/ContrastEnhance.exe

Or just type "sh run.sh".

This has been tested in Windows 10 and compiled/linked/ran as of my commit using both the above methods. Although I prefer Linux, it was not tested here.

# Source Code
TestApp is the driver and I started to abstract duplicate functionality / repetitive code into Utilities. It's a work in progress. 


# Sample output
This shows an example of adding 30% contrast to original image.

![Original](boy.jpg "Original")
![Added Contrast](highContrast.png "Added contrast")
