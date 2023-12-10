#ifndef DERIVATIVE_CALCULATOR_H
#define DERIVATIVE_CALCULATOR_H

#include <string>
#include <vector>

class DerivativeCalculator {
public:

    /*
    Default Constructor

    ~unnecessary
    */
    DerivativeCalculator();


    /*
    calculatorDerivative - calculates the derivative of each 
                            individual term for the polynomial

    @param polynomial  is the string term that is going to be differentiated
    @return a string that is the derivative of the polynomial
    */
    std::string calculateDerivative(const std::string& polynomial);

private:

    struct Term {
        int coefficient;
        int exponent;
    };


    /*
    parsePolynomial - a function that reads each term of the polynomial
    
    @param polynomial entered by the user where each term is then separated into a vector
    @return the vector with all of the terms of the polynomail
    */
    std::vector<Term> parsePolynomial(const std::string& polynomial);

    /*
    formatTerm - puts all the terms back into a string

    @param term - is the term of that is held by polynomial
    @return string with the polynomial that has been differentiated
    */
    std::string formatTerm(const Term& term);
};

#endif // DERIVATIVE_CALCULATOR_H
