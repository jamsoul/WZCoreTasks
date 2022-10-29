#include <iostream>

using namespace std;

#define MontyHallDoors 3

void printUsage( char * program ) {
    cout << "Usage : " << program << " [number of iterations]  . Example " << program <<  " 1500 (Runs simulation with 1500 iterations)" << endl;
}

int main(int argc, char** argv) {
    int iterations = 0;
    int countWinStay = 0;
    int countWinSwitch = 0;
    int carDoor = 0;
    int pickedDoor = 0;
    auto commandName = argv[0];

    if (argc == 1) {
        printUsage(commandName);
        return -1;
    } else if (argc == 2) {
        iterations = atoi(argv[1]);
        cout << "Running Monty Hall Problem Simulation with " << iterations << " iterations : " << endl;
    } else {
        cout << "Too many Arguments. " << endl;
        printUsage(commandName);
        return -1;
    }

    for (int k=0; k<iterations; k++) {
        carDoor = rand()%MontyHallDoors;
        pickedDoor = rand()%MontyHallDoors;

        if (carDoor == pickedDoor) {
            countWinStay++;
        } else {
            countWinSwitch++;
        }
    }

    std::cout << "Stay Chance   " << 100.0 * (float)countWinStay   / (float)iterations << "%" << std::endl;
    std::cout << "Switch Chance " << 100.0 * (float)countWinSwitch / (float)iterations << "%" << std::endl;
    return 0;
}

