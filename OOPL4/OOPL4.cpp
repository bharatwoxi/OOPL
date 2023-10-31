#include <iostream>

class Box {
private:
    double length;
    double breadth;
    double height;

public:
    // Default constructor
    Box() : length(0), breadth(0), height(0) {}

    // Overloaded operator '<<' for displaying Box dimensions
    friend std::ostream& operator<<(std::ostream& out, const Box& box) {
        out << "Length: " << box.length << " Breadth: " << box.breadth << " Height: " << box.height;
        return out;
    }

    // Overloaded operator '>>' for reading Box dimensions
    friend std::istream& operator>>(std::istream& in, Box& box) {
        std::cout << "Enter Length: ";
        in >> box.length;
        std::cout << "Enter Breadth: ";
        in >> box.breadth;
        std::cout << "Enter Height: ";
        in >> box.height;
        return in;
    }

    // Member function '+' to add two Box objects
    Box operator+(const Box& other) const {
        Box sum;
        sum.length = this->length + other.length;
        sum.breadth = this->breadth + other.breadth;
        sum.height = this->height + other.height;
        return sum;
    }

    // Friend function to compute the volume of a Box using operator overloading
    friend double computeVolume(const Box& box) {
        return box.length * box.breadth * box.height;
    }
};

int main() {
    Box box1, box2, boxSum;
    std::cout << "Enter dimensions for Box 1:\n";
    std::cin >> box1;
    std::cout << "Enter dimensions for Box 2:\n";
    std::cin >> box2;

    // Adding two Box objects using the '+' member function
    boxSum = box1 + box2;

    std::cout << "\nBox 1: " << box1 << std::endl;
    std::cout << "Box 2: " << box2 << std::endl;
    std::cout << "Sum of Box 1 and Box 2: " << boxSum << std::endl;

    // Calculating and displaying the volume of Box 1 and Box 2 using the friend function
    double volume1 = computeVolume(box1);
    double volume2 = computeVolume(box2);
    std::cout << "\nVolume of Box 1: " << volume1 << std::endl;
    std::cout << "Volume of Box 2: " << volume2 << std::endl;

    return 0;
}
