#include <iostream>

class Banner {
//variables are by default private. 
//Can set them pubic or make public mutator functions. (better)
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

//https://stackoverflow.com/questions/28642430/what-is-the-point-of-defining-methods-outside-of-a-class-in-c
void Banner::outside() {
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"; 
};

//https://en.cppreference.com/w/cpp/language/derived_class
class HasDefaults: protected Banner {

public:
    HasDefaults(std::string say_this = "This is my standard message!") {
        message = say_this;
    } 

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
    WrapAgain(std::string real_message)
        :HasDefaults(real_message) {}

    void passThrough() {
        std::cout << "+++++" << message << "+++++\n";
    }
};

//Class with constants
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