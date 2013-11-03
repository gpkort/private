#include "gmock/gmock.h" 
#include "FuelTank.h"
#include "CrashPadUtils.h"

using namespace Model;
using namespace testing;

TEST(FuelMassTest, ConstructorTest) {
    /*
     (std::string name, unsigned int id, double mass, float cost,
                   int points, double capacity, double currentAmount, 
                   FUEL_TYPE fuelType, double fuelDensity)
     */
    FuelTank myTank("TestTank", 1, 50, 500.00f, 100, 25, 1.0, LIQUID, 1);
    double mass = 50 + 25.0 * 1 * 1.0;
    double omass = myTank.get_object_mass();
    
    ASSERT_THAT(myTank.get_object_mass(), Eq(mass));
    /*
     FuelTank::FuelTank(std::string name, unsigned int id, double mass, int points,
                   double capacity, double currentAmount, FUEL_TYPE fuelType,
                   double fuelDensity)
     */
}
