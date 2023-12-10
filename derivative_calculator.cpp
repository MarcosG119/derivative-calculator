#include "derivative_calculator.h"
#include <iostream>
#include <sstream>
#include <cmath>

std::string DerivativeCalculator::calculateDerivative(const std::string& polynomial) {
    std::vector<Term> terms = parsePolynomial(polynomial);
    std::vector<Term> derivativeTerms;

    for (const auto& term : terms) {
        if (term.exponent > 0) {
            Term derivativeTerm;
            derivativeTerm.coefficient = term.coefficient * term.exponent;
            derivativeTerm.exponent = term.exponent - 1;
            derivativeTerms.push_back(derivativeTerm);
        }
    }

    std::stringstream result;
    for (size_t i = 0; i < derivativeTerms.size(); ++i) {
        result << formatTerm(derivativeTerms[i]);
        if (i < derivativeTerms.size() - 1) {
            result << " + ";
        }
    }

    return result.str();
}

std::vector<DerivativeCalculator::Term> DerivativeCalculator::parsePolynomial(const std::string& polynomial) {
    std::vector<Term> terms;

    std::istringstream termStream(polynomial);
    std::string termStr;

    while (std::getline(termStream, termStr, '+')) {
        Term term;

        std::istringstream termParts(termStr);
        termParts >> term.coefficient;

        if (termParts.peek() == 'x') {
            termParts.ignore(); // ignore 'x'
            termParts.ignore(); // ignore '^'
            termParts >> term.exponent;
        } else {
            term.exponent = 0;
        }

        terms.push_back(term);
    }

    return terms;
}

std::string DerivativeCalculator::formatTerm(const Term& term) {
    // Format the term as a string
    if (term.exponent == 0) {
        return std::to_string(term.coefficient);
    } else if (term.exponent == 1) {
        return std::to_string(term.coefficient) + "x";
    } else {
        return std::to_string(term.coefficient) + "x^" + std::to_string(term.exponent);
    }
}

int main() {
    // Example usage of the DerivativeCalculator
    DerivativeCalculator calculator;
    std::string polynomial;

    // Get user input for the polynomial
    std::cout << "Enter a polynomial: ";
    std::getline(std::cin, polynomial);

    // Calculate and display the derivative
    std::string derivative = calculator.calculateDerivative(polynomial);
    std::cout << "Derivative: " << derivative << std::endl;

    return 0;
}
