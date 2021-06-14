## Brightness Enhancement
# Demos of:
* brightness enhance --> I (output) = I (input) + beta - simplest way is adding some offset (assume there are 256 levels (0 - 255)

Brightness is how much light is introduced (seems obvious?).

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
* .\build\Release\BrightnessEnhance.exe

Or just type "run.bat".

**Shell**

* mkdir results
* mkdir build
* cd build
* cmake -G "Visual Studio 16 2019" ..
* cmake --build . --config Release
* cd ..
./build/Release/BrightnessEnhance.exe

Or just type "sh run.sh".

This has been tested in Windows 10 and compiled/linked/ran as of my commit using both the above methods. Although I prefer Linux, it was not tested here.

# Source Code
TestApp is the driver and I started to abstract duplicate functionality / repetitive code into Utilities. It's a work in progress. 

# Sample output
This shows an example of adding 50% brightness to original image.

![Original](boy.jpg "Original")
![Added Brightness](highBrightness.png "Added brightness")