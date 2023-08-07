#include <iostream>

class Banner {
    // variables are by default private.
    // Can set them pubic or make public mutator functions.
public:
    std::string message;

    void wave() {
        std::cout
            << "********************************************************\n";
        std::cout << message << "\n";
        std::cout
            << "********************************************************\n";
    }

    // example of declaring method without implementing it, i.e. for header
    // files.
    void outside();
};

void Banner::outside() {
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
};

// https://en.cppreference.com/w/cpp/language/derived_class
// https://learn.microsoft.com/en-us/cpp/cpp/member-access-control-cpp
class HasDefaults : protected Banner {
public:
    HasDefaults(std::string say_this = "This is my standard message!") {
        message = say_this;
    }

    // base class is protected, but can be accessed via mutator functions.
    void update(std::string new_message) { message = new_message; }

    // Allows access to protected base class function, but is not an override
    void passThrough() { wave(); }
    // Destructor
    ~HasDefaults() { std::cout << "Nothing more to do\n"; }
};

// Third time a charm
class WrapAgain : public HasDefaults {
public:
    // Treats parent initializer as member initializer list.
    WrapAgain(std::string real_message) : HasDefaults(real_message) {}

    // no override keyword (keyword: polymorphism)
    void passThrough() { std::cout << "+++++" << message << "+++++\n"; }
};

// A class with constants needs to have "member initializer list"
// https://en.cppreference.com/w/cpp/language/constructor
class HousePlant {
private:
    const std::string genus;
    const int year_acquired;

public:
    HousePlant() : genus("Crassula"), year_acquired(2004) {}
};

//----------------------------------------------------------------------- main()
int main() {

    Banner end_of_message;
    end_of_message.message = "Thats all they wrote!";

    end_of_message.wave();
    end_of_message.outside();

    HasDefaults example;
    example.passThrough();
    example.update("But I can say something new!");
    example.passThrough();

    WrapAgain slimmessage("keep it clean");
    slimmessage.passThrough();

    return 0;
}