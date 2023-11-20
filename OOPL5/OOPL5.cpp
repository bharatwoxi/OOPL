#include <iostream>

class Employee {
public:
    Employee(std::string name, int id) : name(name), id(id) {}

    virtual double calculateSalary() const = 0;  // Pure virtual function

    void displayInfo() const {
        std::cout << "Name: " << name << "\nID: " << id << "\n";
    }

private:
    std::string name;
    int id;
};

class Class1_Employee : public Employee {
public:
    Class1_Employee(std::string name, int id, double baseSalary)
        : Employee(name, id), baseSalary(baseSalary) {}

    double calculateSalary() const override {
        // Salary calculation logic for Class1_Employee
        return baseSalary + bonus;
    }

private:
    double baseSalary;
    static const double bonus;
};

const double Class1_Employee::bonus = 500.0;

class Class2_Employee : public Employee {
public:
    Class2_Employee(std::string name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double calculateSalary() const override {
        // Salary calculation logic for Class2_Employee
        return hourlyRate * hoursWorked;
    }

private:
    double hourlyRate;
    int hoursWorked;
};

class Class3_Employee : public Employee {
public:
    Class3_Employee(std::string name, int id, double commission, double sales)
        : Employee(name, id), commission(commission), sales(sales) {}

    double calculateSalary() const override {
        // Salary calculation logic for Class3_Employee
        return commission * sales;
    }

private:
    double commission;
    double sales;
};

int main() {
    Class1_Employee emp1("John Doe", 101, 2000.0);
    Class2_Employee emp2("Jane Smith", 102, 15.0, 40);
    Class3_Employee emp3("Bob Johnson", 103, 0.1, 50000.0);

    emp1.displayInfo();
    std::cout << "Salary: ₹" << emp1.calculateSalary() << "\n\n";

    emp2.displayInfo();
    std::cout << "Salary: ₹" << emp2.calculateSalary() << "\n\n";

    emp3.displayInfo();
    std::cout << "Salary: ₹" << emp3.calculateSalary() << "\n";

    return 0;
}
