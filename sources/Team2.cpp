#include "Team2.hpp"
using namespace std;

namespace ariel {

    Team2::Team2(Character* leader):
    Team(leader){
        if (leader == nullptr) throw invalid_argument("Error: Leader is null");
    }

    void Team2::print(){
        return;
    }
}