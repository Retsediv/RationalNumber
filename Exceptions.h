#ifndef RATIONALNUMBER_EXEPTIONS_H
#define RATIONALNUMBER_EXEPTIONS_H

#include <stdexcept>
#include <exception>

using std::runtime_error;

class RationalException : public std::exception {
public:
    const char *what() const throw() {
        return "An error happened with rational number.";
    }
};

class DivideByZeroException : public std::runtime_error {
public:
    DivideByZeroException() : runtime_error("Division by zero(0) happened!") {}

    virtual const char *what() const throw() {
        return runtime_error::what();
    }
};

#endif //RATIONALNUMBER_EXEPTIONS_H
