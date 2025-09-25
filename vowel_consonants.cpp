#include <fst/fstlib.h>
#include <iostream>
#include <string>

int main() {
    using namespace fst;

    
    StdVectorFst fst;

    
    auto start = fst.AddState();  // state 0
    auto final = fst.AddState();  // state 1
    fst.SetStart(start);
    fst.SetFinal(final, 0.0);

    
    fst.AddArc(start, StdArc('a', 'v', 0.0, final));
    fst.AddArc(start, StdArc('e', 'v', 0.0, final));
    fst.AddArc(start, StdArc('i', 'v', 0.0, final));
    fst.AddArc(start, StdArc('o', 'v', 0.0, final));
    fst.AddArc(start, StdArc('u', 'v', 0.0, final));
    
    
    fst.AddArc(start, StdArc('b', 'c', 0.0, final));
    fst.AddArc(start, StdArc('x', 'c', 0.0, final));

    
    fst.Write("vowel_consonant.fst");

    std::cout << "FST created and saved as vowel_consonant.fst" << std::endl;

    return 0;
}

