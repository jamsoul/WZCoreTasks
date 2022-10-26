#include <iostream>

int iter = 1000;

using namespace std;

void usage( char * program ) {
    cout << "Usage : " << program << " [number of iterations]  . Example " << program <<  " 1500 (Runs simulation with 1500 iterations" << endl;
}

int main(int argc, char** argv) {
    int countWinStay = 0;
    int countWinSwitch = 0;
    int carDoor = 0;
    int pickedDoor = 0;

    if (argc == 1) {
        usage ( argv[0] );
        return -1;
    } else if (argc == 2) {
        iter = atoi(argv[1]);
        cout << "Running Monty Hall Problem Simulation with " << iter << " iterations : " << endl;
    } else {
        cout << "Too many Arguments. " << endl;
        usage(argv[0]);
        return -1;
    }

    for (int k=0; k<iter; k++) {
        carDoor = rand()%3;
        pickedDoor = rand()%3;

        if (carDoor == pickedDoor) {
            countWinStay++;
        } else {
            countWinSwitch++;
        }
    }

    std::cout << "Stay Chance "   << (float)countWinStay   / (float)iter << std::endl;
    std::cout << "Switch Chance " << (float)countWinSwitch / (float)iter << std::endl;
    return 0;
}

