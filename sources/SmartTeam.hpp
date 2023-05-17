#include "Team.hpp"
using namespace std;
     
namespace ariel {

    class SmartTeam : public Team {

        public:
            SmartTeam(Character* leader);
            void print() override;
            
    };
}