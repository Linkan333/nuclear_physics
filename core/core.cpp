#include <iostream>
#include <cmath>
#include <unordered_map>
#include <iomanip>
#include <math.h>
#include <stdio.h>

void atomicMap(std::unordered_map<std::string, double>& atomicList) {
    atomicList = {
        {"Electron", 9.10932e-31},
        {"Proton", 1.672622e-27},
        {"Neutron", 1.674927e-27},
        {"Elementar", 1.602176634e-19},
        {"Nucleon", 1.6726e-27},
        {"u", 1.660539e-27}, // Atomic mass
        {"eV", 1.602e-19}
    };
}

//void electronVolt() {
    // eV (Electron Volt) i am going to describe the charge for one Electron
    // We also define it with the prefix J at the end since this is so much it defines as Joule instead.
    // The electorn volt is the amount of energy gained or lost by a single electron when it moves through an electric potential difference of one volt. Hence it has a value of one volt which is 1 J/C (Joule/Coloumb) multiplied by the elementary charge as described above in the unordered_map 

//}

void energyConsumption() {
    double kW;
    float time;
    // For example if a moter uses 50 kW for 2 hours Energy = 50 x 2 = 100 kWh we can make a simple calculator by using this math:
    std::cout << "Enter the motor use amount: " << std::endl;
    std::cin >> kW;
    std::cout << "Enter the amount of time: " << std::endl;
    std::cin >> time;
    int energy = kW * time;
    std::cout << energy << " kWh" << std::endl;
}

void radioactiveDecay() {
    // Radioactive decay over a certain time span
    // Formula: (N = N0e-λt)
    double N_0; // Radioactive cores ex: uran-235 (92 protons and 143 neutrons wich we can use the atomics neuclon algorithm for)
    double t = 1.0e9; // Over t (time) this example has 1*10^9 wich is 1 billion years
 
    double T_half = 7.038e8; // Half-life of uranium-235 in years (~703.8 million years)
    double lambda = log(2.0) / T_half;
    double N;

    // Calculating remaining nucleons using N = N_0 * e^(-lambda * t)
    N = N_0 * exp(-lambda * t);
    
    std::cout << "Initial nuclei (N_0): \n" << N_0 << std::endl;
    std::cout << "Time elapsed (t): " << t << " years\n" << std::endl;
    std::cout << "Half-life (T_1/2): " << T_half  << " years\n" << std::endl;
    std::cout << "Decay constant (lambda): " << lambda << " per year\n" << std::endl;
    std::cout << "Remainign nucleon (N)\n" << N << std::endl;
}

int main() {
    std::unordered_map<std::string, double> atomicList;
    atomicMap(atomicList);

    // Print all items with formatted output
    std::cout << std::scientific << std::setprecision(3);
    for (const auto& pair : atomicList) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }


    // Demo for atomics neutron count. 
    int N;
    int Z;
    
    std::cout << "Enter the amount of Neutrons: " << std::endl;
    std::cin >> N;
    std::cout << "Enter the amount of Protons: " << std::endl;
    std::cin >> Z;

    // For helium example:
    int A = N + Z;
    std::cout << "\nCount of Nucleons: " << A << std::endl;

    
    radioactiveDecay();
    energyConsumption();
    return 0;
}
