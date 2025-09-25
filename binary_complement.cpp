#include <fst/fstlib.h>
#include <iostream>

using namespace fst;

int main() {
    
    StdVectorFst fst;

   
    auto start = fst.AddState();   // state 0
    auto final = fst.AddState();   // state 1

    
    fst.SetStart(start);
    fst.SetFinal(final, TropicalWeight::One());

    
    fst.AddArc(start, StdArc(0, 1, TropicalWeight::One(), final));

    
    fst.AddArc(start, StdArc(1, 0, TropicalWeight::One(), final));

    
    fst.Write("binary_complement.fst");

    std::cout << "Binary complement FST created and saved as binary_complement.fst" << std::endl;

    return 0;
}
