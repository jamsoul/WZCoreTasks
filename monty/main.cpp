#include <iostream>

using namespace std;

#define MontyHallDoors 3

void printUsage( char * program ) {
    cout << "Usage : " << program << " [number of iterations]  . Example " << program <<  " 1500 (Runs simulation with 1500 iterations)" << endl;
}

int main(int argc, char** argv) {
    // Ugly Var Declaration
    int iterations     = 0;
    int countWinStay   = 0;
    int countWinSwitch = 0;
    int carDoor        = 0;
    int pickedDoor     = 0;
    auto commandName   = argv[0];


    // Check arguments
    if (argc == 2) {
        iterations = strtol(argv[1], (char**)NULL, 10);
        if (iterations > 0) {
            cout << "Running Monty Hall Problem Simulation with " << iterations << " iterations : " << endl;
        }
    } else {
        printUsage(commandName);
        return -1;
    }


    // Run sim
    for (int k = 0; k < iterations; k++) {
        carDoor    = rand() % MontyHallDoors;
        pickedDoor = rand() % MontyHallDoors;

        if (carDoor == pickedDoor) {
            countWinStay++;
        } else {
            countWinSwitch++;
        }
    }


    // Output results
    std::cout << "Stay Chance   " << 100.0 * (float)countWinStay   / (float)iterations << "%" << std::endl;
    std::cout << "Switch Chance " << 100.0 * (float)countWinSwitch / (float)iterations << "%" << std::endl;

    return 0;
}

