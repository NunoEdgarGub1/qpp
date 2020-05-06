// Used for testing, do not use it as an example
#include <iostream>

#include "qpp.h"
#include "experimental/experimental.h"

int main() {
    /////////// testing ///////////
    using namespace qpp;
    try {
        QCircuit q_circuit{4, 5};
        q_circuit.cCTRL(gt.X, {1, 3}, 1);
        q_circuit.CTRL(gt.Z, 1, 3);
        std::cout << q_circuit << "\n\n";
        std::cout << disp(q_circuit.get_clean_dits(), ", ") << "\n\n";

        std::cout << q_circuit.compress(true) << "\n";
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
