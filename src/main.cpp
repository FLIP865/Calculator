#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>

const std::string colors[] = {
    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[35m",
    "\033[36m",
    "\033[37m",
};

const std::string reset = "\033[0m";

bool isNumber(std::string& ss) {
    std::istringstream iss(ss);
    double num;
    return (iss >> num) and (iss.eof());
}

void PerformOperation(int choice, const std::vector<double>& numbers, int preciscions) {
    switch (choice) {
        case 1: {
                    double AddResult = 0;
                    std::cout << colors[0] << "Adding: " << reset;
                    for (int i = 0; i < numbers.size(); i++) {
                        AddResult += numbers[i];
                        std::cout << numbers[i];
                        if (i < numbers.size() - 1) {
                            std::cout << colors[0] << " + " << reset;
                        }
                    }
                    std::cout << " = " << colors[0] << std::fixed << std::setprecision(preciscions) << AddResult << reset << "\n";
                    break;
                } 
        case 2: {
                    double subResult = numbers[0];
                    std::cout << colors[0] << "Subtraction: " << reset << numbers[0];
                    for (int i = 1; i < numbers.size(); i++)
                    {
                        subResult -= numbers[i];
                        std::cout << colors[0] << " - " << reset << numbers[i];
                    }
                    std::cout << " = " << colors[0] << std::fixed << std::setprecision(preciscions) << subResult << reset << "\n";
                    break;
                }
        case 3: {
                    double multiResult = 1;
                    std::cout << colors[0] << "Multiplication: " << reset;
                    for (int i = 0; i < numbers.size(); i++)
                    {
                        multiResult *= numbers[i];
                        std::cout << numbers[i];
                        if (i < numbers.size() - 1)
                        {
                            std::cout << colors[0] << " * " << reset;
                        }
                    }
                    std::cout << " = " << colors[0] << std::fixed << std::setprecision(preciscions) << multiResult << reset << "\n";
                    break;
                }
        case 4: {
                    double divisionResult = numbers[0];
                    bool divisionByZero = false;
                    std::cout << colors[0] << "Division: " << reset << numbers[0];
                    for (int i = 1; i < numbers.size(); i++)
                    {
                        if (numbers[i] == 0) {
                            divisionByZero = true;
                            break;
                        }
                        divisionResult /= numbers[i];
                        std::cout << colors[0] << " / " << reset << numbers[i];
                    }
                    if (divisionByZero) {
                        std::cout << colors[0] << "You can't divide by zero!\n" << reset;
                    } else {
                        std::cout << " = " << colors[0] << std::fixed << std::setprecision(preciscions) << divisionResult << reset << "\n";
                    }
                    break;
                }
        case 5: {
                    double squareResult = 1.0;
                    std::cout << colors[0] << "Square of the Number: " << reset;
                    for (int i = 0; i < numbers.size(); i++)
                    {
                        squareResult *= numbers[i];
                        std::cout << numbers[i];
                        if (i < numbers.size() - 1) {
                            std::cout << colors[0] << " * " << reset;
                        }
                    }
                    double result = std::pow(squareResult, 1.5);
                    std::cout << " ^1.5 = " << colors[0] << std::fixed << std::setprecision(preciscions) << result << reset << "\n";
                    break;
                }
    }
}

void PerformAllOperation(const std::vector<double>& AddNumber, const std::vector<double>& subNumber, const std::vector<double>& multiNumber, const std::vector<double>& divisionNumber, const std::vector<double>& squareNumber,
                         int preciscions) {
    PerformOperation(1, AddNumber, preciscions);
    PerformOperation(2, subNumber, preciscions);
    PerformOperation(3, multiNumber, preciscions);
    PerformOperation(4, divisionNumber, preciscions);
    PerformOperation(5, squareNumber, preciscions);
}

void InputNumber(std::vector<double>& numbers, int numCount) {
    numbers.clear();
    int enteredCount = 0;

    std::cout << colors[0] << " Enter: " << numCount << " numbers: " << reset;
    while (enteredCount < numCount) {
        std::string input;
        std::cin >> input;
        if (isNumber(input)) {
            numbers.push_back(std::stod(input));
            enteredCount++;
        } else {
            std::cout << colors[0] << "Invalid input. " << "Please input number no letters! " << reset;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    if (std::cin.peek() != '\n') {
        std::cout << "Invalid input. Please re-entered value is " << colors[0] << numCount << reset << "\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        InputNumber(numbers, numCount);
    }
}

int main() {
    int p, numCount, preciscions, operation;
    std::string ExitChoice;

        
            std::cout << "1-Calculator:\n2-Exit:\n";

            while (true)
            {
            std::string input;
            std::cin >> input;
            if (isNumber(input))
            {
                p = std::stoi(input);
                if (p == 1) 
                {
                    break;
                }
                else if (p == 2)
                {
                    return 0;
                }
            }
            else 
            {
                std::cout << "Invalid choice. " << colors[1] << "Enter 1 to continue " << "or " << colors[0] << "2 to exit " << reset;
            }
        }
    
    while (true) 
    {
        std::cout << "Select the value " << colors[0] << "you want to work on: " << reset;
        
        while (true) 
        {
            std::string input;
            std::cin >> input;
            if (isNumber(input)) 
            {
                numCount = std::stoi(input);
                if (numCount > 1) {
                    break;
                } else {
                    std::cout << "Invalid input, enter a number greater than one. ";
                }
            } else {
                std::cout << "Incorrect input, enter numbers " << colors[0] << "or letters is not possible: " << reset;
            }
        }

        std::vector<double> AddNumber, subNumber, multiNumber, divisionNumber, squareNumber;

        std::cout << "Enter the numbers to Adding:\n";
        InputNumber(AddNumber, numCount);

        std::cout << "Enter the numbers to Subtraction:\n";
        InputNumber(subNumber, numCount);

        std::cout << "Enter the number to Multiply:\n";
        InputNumber(multiNumber, numCount);

        std::cout << "Enter the number to Division:\n";
        InputNumber(divisionNumber, numCount);

        std::cout << "Enter the number for the square of the numbers:\n";
        InputNumber(squareNumber, numCount);

        std::cout << "Enter the numbers " << colors[0] << "after the (decimal point) " << reset;
        while (true) {
            std::string input;
            std::cin >> input;
            if (isNumber(input)) 
            {
                preciscions = std::stoi(input);
                if (preciscions >= 0) 
                {
                    break;
                }
                else 
                {
                    std::cout << "Invalid input. Please enter numbers " << colors[0] << "after the (decimal point) " << reset;
                } 
            }
            else 
            {
                std::cout << "Incorrect input, enter numbers " << colors[0] << "or letters is not possible! " << reset;
            }
        }

        std::cout << colors[0] << "Select Operation:\n" << reset;
        std::cout << colors[1] << "1.Adding:\n" << reset;
        std::cout << colors[2] << "2.Subtraction:\n" << reset;
        std::cout << colors[3] << "3.Multiplication:\n" << reset;
        std::cout << colors[4] << "4.Division:\n" << reset;
        std::cout << colors[5] << "5.Square of Number:\n" << reset;
        std::cout << colors[6] << "6.All operation:\n" << reset;

        while (true) 
        {
            std::string input;
            std::cin >> input;
            if (isNumber(input))
            {
                operation = std::stoi(input);
                if (operation >= 1 and operation <= 6)
                {
                    break;
                }
                else 
                {
                    std::cout << "Invalid input select operationb from " << colors[0] << "one to six " << reset;
                }
            }
            else 
            {
                std::cout << "Incorrect input, enter numbers " << colors[0] << "or letters is not possible! " << reset;
            }
        }

        if (operation == 6)
        {
            PerformAllOperation(AddNumber, subNumber, multiNumber, divisionNumber, squareNumber, preciscions);
        }
        else
        {
            switch (operation)
            {
                case 1:
                    PerformOperation(1, AddNumber, preciscions);
                    break;
                case 2:
                    PerformOperation(2, subNumber, preciscions);
                    break;
                case 3:
                    PerformOperation(3, multiNumber, preciscions);
                    break;
                case 4:
                    PerformOperation(4, divisionNumber, preciscions);
                    break;
                case 5:
                    PerformOperation(5, squareNumber, preciscions);
            }
        }
        
        while (true)
        {

            std::cout << "Do you want to Exit the program? " << colors[0] << "Yes or No. " << reset;
            std::cin >> ExitChoice;
            if (ExitChoice == "y" or ExitChoice == "Y")
            {
                return 0;
            }
            else if (ExitChoice == "n" or ExitChoice == "N")
            {
                break;
            }
            else
            {
                std::cout << "Invalid input. Please input " << colors[2] << "y/Y/n/N! " << reset;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    return 0;
}
