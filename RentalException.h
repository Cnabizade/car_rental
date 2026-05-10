#ifndef RENTALEXCEPTION_H
#define RENTALEXCEPTION_H

#include <exception>
#include <string>

class RentalException : public std::exception {
    std::string message;
public:
    RentalException(const std::string& msg) : message("Rental System Error: " + msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

#endif
