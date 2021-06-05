#pragma once
#include <exception>
#include <iostream>

class runtime_error : public std::exception {
public:
    explicit runtime_error(const std::string& message);

    explicit runtime_error(const char* message);

};