## Getting Started with images
# Demos of:
* reading & writing images
* splitting color channels
* extracting alpha channel - mask
* single pixel & group of pixels manipulation
* merging color channels

# How to run
OpenCV libs, cmake, VS19 (or some version) need to be installed.
To build & run, in root dir:
* mkdir results
* mkdir build
* cd build
* cmake -G "Visual Studio 16 2019" ..
* cmake --build . --config Release
* cd ..
* .\build\Release\GettingStarted.exe

Or if you're lazy, just type "run.bat". ;)

This has been tested in Windows 10 and compiled/linked/ran as of my commit. Although I prefer Linux, it was not tested here.

# Source Code
TestApp is the driver and I started to abstract duplicate functionality / repetitive code into Utilities. It's a work in progress. 