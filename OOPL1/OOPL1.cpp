#include <iostream>
#include <string>

class AirlinePassenger {
private:
    std::string name;
    int age;
    std::string flightNo;
    std::string departureTime;
    std::string source;

public:
    // Constructor
    AirlinePassenger(std::string n, int a, std::string fNo, std::string depTime, std::string src)
        : name(n), age(a), flightNo(fNo), departureTime(depTime), source(src) {}

    // Method to set passenger information
    void setInformation(std::string n, int a, std::string fNo, std::string depTime, std::string src) {
        name = n;
        age = a;
        flightNo = fNo;
        departureTime = depTime;
        source = src;
    }

    // Method to display passenger information
    void displayInformation() const {
        std::cout << "Passenger Information:" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Flight No.: " << flightNo << std::endl;
        std::cout << "Departure Time: " << departureTime << std::endl;
        std::cout << "Source: " << source << std::endl;
    }
};

int main() {
    // Create an instance of AirlinePassenger
    AirlinePassenger passenger1("Bharat Makwana", 33, "ABC123", "2023-07-29 10:00", "New York");

    // Display passenger information
    passenger1.displayInformation();

    // Update passenger information
    passenger1.setInformation("Sandeep Patil", 33, "XYZ789", "2023-07-30 15:30", "Los Angeles");

    // Display updated information
    passenger1.displayInformation();

    return 0;
}

