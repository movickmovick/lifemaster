#include <iostream>
#include <string>

using namespace std;

// Define the EgoState enum to represent the Parent, Adult, and Child ego states
enum class EgoState { Parent, Adult, Child };

// Define the TransactionalUnit class
class TransactionalUnit {
private:
    string sender;
    string receiver;
    string message;
public:
    TransactionalUnit(const string& sender, const string& receiver, const string& message)
        : sender(sender), receiver(receiver), message(message) {}

    void process() {
        cout << sender << " to " << receiver << ": " << message << endl;
    }
};

// Define the Person class representing individuals with ego states
class Person {
protected:
    string name;
    EgoState egoState;

public:
    Person(const string& name, EgoState egoState)
        : name(name), egoState(egoState) {}

    void sendTransaction(Person& other, const string& message) {
        TransactionalUnit tu(name, other.name, message);
        tu.process();
    }

    virtual void talk() = 0; // Virtual function to be overridden by derived classes
};

// Define derived classes representing different ego states
class Parent : public Person {
public:
    Parent(const string& name) : Person(name, EgoState::Parent) {}

    void talk() override {
        cout << name << " (Parent): Do as I say!" << endl;
    }
};

class Adult : public Person {
public:
    Adult(const string& name) : Person(name, EgoState::Adult) {}

    void talk() override {
        cout << name << " (Adult): Let's analyze this logically." << endl;
    }
};

class Child : public Person {
public:
    Child(const string& name) : Person(name, EgoState::Child) {}

    void talk() override {
        cout << name << " (Child): I want to play!" << endl;
    }
};

int main() {
    // Create instances of people with different ego states
    Parent mom("Mom");
    Adult john("John");
    Child sarah("Sarah");

    // Demonstrate communication and ego states
    mom.talk();
    john.talk();
    sarah.talk();

    cout << endl;

    // Simulate transactions between individuals
    john.sendTransaction(mom, "Can I go out tonight?");
    mom.sendTransaction(john, "Sure, but be back by midnight.");
    sarah.sendTransaction(john, "Can we play together?");

    return 0;
}
