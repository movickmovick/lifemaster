#include <stdio.h>
#include <string.h>

// Define constants for ego states
enum EgoState { Parent, Adult, Child };

// Define the TransactionalUnit struct
struct TransactionalUnit {
    char sender[50];
    char receiver[50];
    char message[100];
};

// Define the Person struct representing individuals with ego states
struct Person {
    char name[50];
    enum EgoState egoState;
};

// Function to process a TransactionalUnit
void processTU(struct TransactionalUnit *tu) {
    printf("%s to %s: %s\n", tu->sender, tu->receiver, tu->message);
}

// Function to simulate a person sending a transaction
void sendTransaction(struct Person *sender, struct Person *receiver, const char *message) {
    struct TransactionalUnit tu;
    strcpy(tu.sender, sender->name);
    strcpy(tu.receiver, receiver->name);
    strcpy(tu.message, message);
    processTU(&tu);
}

int main() {
    // Create instances of people with different ego states
    struct Person mom = {"Mom", Parent};
    struct Person john = {"John", Adult};
    struct Person sarah = {"Sarah", Child};

    // Demonstrate communication and ego states
    printf("%s (Parent): Do as I say!\n", mom.name);
    printf("%s (Adult): Let's analyze this logically.\n", john.name);
    printf("%s (Child): I want to play!\n", sarah.name);

    printf("\n");

    // Simulate transactions between individuals
    sendTransaction(&john, &mom, "Can I go out tonight?");
    sendTransaction(&mom, &john, "Sure, but be back by midnight.");
    sendTransaction(&sarah, &john, "Can we play together?");

    return 0;
}
