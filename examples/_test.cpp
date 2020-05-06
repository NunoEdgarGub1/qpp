// Used for testing, do not use it as an example
#include <iostream>

#include "qpp.h"
#include "experimental/experimental.h"

int main() {
    /////////// testing ///////////
    using namespace qpp;
    try {
        QCircuit q_circuit{4, 15};
        q_circuit.cCTRL(gt.X, {1, 3}, 1);
        q_circuit.CTRL(gt.H, 1, 3);
        q_circuit.measureZ(3, 2);
        std::cout << q_circuit << "\n\n";

        std::cout << disp(q_circuit.get_clean_dits(), ", ") << '\n';

        std::cout << q_circuit.compress(true) << "\n\n";

        QEngine q_engine{q_circuit};
        q_engine.set_dit(0, 3);
        q_engine.set_dit(2, 3);
        q_engine.execute(1024);
        std::cout << q_engine << "\n\n";

    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
