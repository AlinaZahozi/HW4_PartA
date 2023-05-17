#include "SmartTeam.hpp"

namespace ariel {

    SmartTeam::SmartTeam(Character* leader):
    Team(leader){
        if (leader == nullptr) throw invalid_argument("Error: Leader is null");
    }

    void SmartTeam::print(){
        return;
    }
}