#include <iostream>


class Banner {
//variables are by default private. 
//Can set them pubic or make public mutator functions.
public:
    std::string message;

    void wave() {
        std::cout << "********************************************************\n";
        std::cout << message << "\n";
        std::cout << "********************************************************\n";
    }

    //example of declaring method without implementing it, i.e. for header files.
    void outside();
};

void Banner::outside() {
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"; 
};

//https://en.cppreference.com/w/cpp/language/derived_class
//https://learn.microsoft.com/en-us/cpp/cpp/member-access-control-cpp
class HasDefaults: protected Banner {
public:
    HasDefaults(std::string say_this = "This is my standard message!") {
        message = say_this;
    } 

    //base class is protected, but can be accessed via mutator functions.
    void update(std::string new_message) {
        message  = new_message;
    }

    void passThrough() {
        wave();
    }
      // Destructor
    ~HasDefaults() {
        std::cout << "Nothing more to do\n";
    }
};

class WrapAgain: public HasDefaults {
public:
    //Treats parent initializer as member initializer list. 
    WrapAgain(std::string real_message)
        :HasDefaults(real_message) {}

    //no override keyword (keyword: polymorphism)
    void passThrough() {
        std::cout << "+++++" << message << "+++++\n";
    }
};

//A class with constants needs to have 
class Book {
private:
  const std::string title;
  const int pages;
public:
  Book() 
    : title("Diary"), pages(100) {} // Member initializer list
};




 
int main(int argc, char* argv[]) {

  Banner end_of_message;
  end_of_message.message = "Thats all they wrote!";

  for(int i = 0; i < argc; i++) {
    std::cout << "arg " << i << ": " << argv[i] << "\n";
  }

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