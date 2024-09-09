#include <iostream>
#include <string>
#include <vector>
#include <memory>



class Shape {
    public:
    std::string name;
    std::string color;
    virtual double area() = 0;
    Shape(std::string name, std::string color) : name(name), color(color) {};
    virtual ~Shape() {}

};

class Circle : public Shape {
    private:
        double radius;
        
    public:
        Circle(double r) : Shape("Circle", "red"), radius(r) {}
        double area() override {
        return 3.14159 * radius * radius;
    }

};

class Rectangle : public Shape {
    private:
        double width, height;
        
    public:
        Rectangle(double w, double h) : Shape("Rectangle", "blue"), width(w), height(h) {}
        double area() override {
            return width * height;
        }
};


int main() {

    std::vector<Shape*> shapes;

    double totalArea = 0.0;

    shapes.push_back(new Circle(10));
    shapes.push_back(new Rectangle(5, 10));

    for (const auto& shape : shapes) {
        std::cout << "Shape: "<< shape->name << " Color: " << shape->color << " Area: " << shape->area() << std::endl;
    }
    
   for (const auto& shape : shapes) {
    totalArea += shape->area();
    }

    std::cout << "Total area: " << totalArea << std::endl;

    for(auto& shape : shapes) {
        delete shape;
    }


    return 0;
}