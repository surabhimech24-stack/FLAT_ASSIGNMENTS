#include <fst/fstlib.h>
#include <iostream>
#include <map>
#include <string>

using namespace fst;

int main() {
    
    std::map<char, std::string> morse = {
        {'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},  {'E', "."},
        {'F', "..-."}, {'G', "--."},  {'H', "...."}, {'I', ".."},   {'J', ".---"},
        {'K', "-.-"},  {'L', ".-.."}, {'M', "--"},   {'N', "-."},   {'O', "---"},
        {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},  {'S', "..."},  {'T', "-"},
        {'U', "..-"},  {'V', "...-"}, {'W', ".--"},  {'X', "-..-"}, {'Y', "-.--"},
        {'Z', "--.."}
    };

    
    StdVectorFst fst;

    
    auto start = fst.AddState();
    fst.SetStart(start);

    
    for (auto &p : morse) {
        char letter = p.first;
        std::string code = p.second;

        auto state = start;

        
        for (char c : code) {
            auto next = fst.AddState();
            int output = (c == '.') ? 1 : 2; // map '.'=1, '-'=2
            fst.AddArc(state, StdArc(letter, output, TropicalWeight::One(), next));
            state = next;
        }

        
        fst.SetFinal(state, TropicalWeight::One());
    }

    
    fst.Write("morse_translator.fst");

    std::cout << "Morse code FST created and saved as morse_translator.fst" << std::endl;

    return 0;
}