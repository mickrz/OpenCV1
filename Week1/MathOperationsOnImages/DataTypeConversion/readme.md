## Datatype Conversion
# Demos of:
* datatype conversion - necessary for multiply/divide ops - convert array type to float (pixel - 16/32/64 bits - more bits contain more info, but not usually necessary - 16 bits should suffice) to prevent overflow errors.

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
* .\build\Release\DatatypeConvert.exe

Or just type "run.bat".

**Shell**

* mkdir results
* mkdir build
* cd build
* cmake -G "Visual Studio 16 2019" ..
* cmake --build . --config Release
* cd ..
./build/Release/DatatypeConvert.exe

Or just type "sh run.sh".

This has been tested in Windows 10 and compiled/linked/ran as of my commit using both the above methods. Although I prefer Linux, it was not tested here.

# Source Code
TestApp is the driver and I started to abstract duplicate functionality / repetitive code into Utilities. It's a work in progress. 