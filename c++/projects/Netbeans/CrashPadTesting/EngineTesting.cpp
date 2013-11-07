#include "gmock/gmock.h" 
#include "Engine.h"
#include "CrashPadUtils.h"

using namespace Model;
using namespace testing;

TEST(EngineConsumptionCurve, FullCurveOnPoint) {
    Engine engine;
    
    engine.insert_fuel_curve_point(0, 0.0);
    engine.insert_fuel_curve_point(10, 20.0);
    engine.insert_fuel_curve_point(20, 40.0);
    engine.insert_fuel_curve_point(30, 60.0);
    engine.insert_fuel_curve_point(40, 80.0);
    engine.insert_fuel_curve_point(50, 100.0);
    engine.insert_fuel_curve_point(60, 120.0);
    engine.insert_fuel_curve_point(70, 140.0);
    engine.insert_fuel_curve_point(80, 160.0);
    engine.insert_fuel_curve_point(90, 180.0);
    engine.insert_fuel_curve_point(100, 200.0);
    
    ASSERT_THAT(engine.get_burn_rate(50), 100);
}

TEST(EngineConsumptionCurve, FullCurveBetweenPoint) {
    Engine engine;
    //45000
    engine.insert_fuel_curve_point(0, 0.0);
    engine.insert_fuel_curve_point(10, 20.0);
    engine.insert_fuel_curve_point(20, 40.0);
    engine.insert_fuel_curve_point(30, 60.0);
    engine.insert_fuel_curve_point(40, 80.0);
    engine.insert_fuel_curve_point(50, 100.0);
    engine.insert_fuel_curve_point(60, 120.0);
    engine.insert_fuel_curve_point(70, 140.0);
    engine.insert_fuel_curve_point(80, 160.0);
    engine.insert_fuel_curve_point(90, 180.0);
    engine.insert_fuel_curve_point(100, 200.0);
    
    ASSERT_THAT(engine.get_burn_rate(45), 90);
}

TEST(EngineConsumptionCurve, FullCurveOutsideLowerPoint) {
    Engine engine;
    //45000
    //engine.insert_fuel_curve_point(0, 0.0);
    engine.insert_fuel_curve_point(10, 20.0);
    engine.insert_fuel_curve_point(20, 40.0);
    engine.insert_fuel_curve_point(30, 60.0);
    engine.insert_fuel_curve_point(40, 80.0);
    engine.insert_fuel_curve_point(50, 100.0);
    engine.insert_fuel_curve_point(60, 120.0);
    engine.insert_fuel_curve_point(70, 140.0);
    engine.insert_fuel_curve_point(80, 160.0);
    engine.insert_fuel_curve_point(90, 180.0);
    engine.insert_fuel_curve_point(100, 200.0);
    
    ASSERT_THAT(engine.get_burn_rate(5), 10);
}

TEST(EngineConsumptionCurve, FullCurveOutsideUpperPoint) {
    Engine engine;
    //45000
    engine.insert_fuel_curve_point(0, 0.0);
    engine.insert_fuel_curve_point(10, 20.0);
    engine.insert_fuel_curve_point(20, 40.0);
    engine.insert_fuel_curve_point(30, 60.0);
    engine.insert_fuel_curve_point(40, 80.0);
    engine.insert_fuel_curve_point(50, 100.0);
    engine.insert_fuel_curve_point(60, 120.0);
    engine.insert_fuel_curve_point(70, 140.0);
    engine.insert_fuel_curve_point(80, 160.0);
    engine.insert_fuel_curve_point(90, 180.0);
    //engine.insert_fuel_curve_point(100, 200.0);
    
    ASSERT_THAT(engine.get_burn_rate(100), 200);
}

TEST(EngineThrustCurve, FullCurveOnPoint) {
    Engine engine;
    
    engine.insert_thrust_curve_point(0, 0.0);
    engine.insert_thrust_curve_point(25, 11250);
    engine.insert_thrust_curve_point(50, 22500);
    engine.insert_thrust_curve_point(75, 33750);
    engine.insert_thrust_curve_point(100, 45000);
    
    ASSERT_THAT(engine.get_thrust(50), 22500);
}

TEST(EngineThrustCurve, FullCurveBetweenPoint) {
    Engine engine;
    
    engine.insert_thrust_curve_point(0, 0.0);
    engine.insert_thrust_curve_point(25, 11250);
    engine.insert_thrust_curve_point(50, 22500);
    engine.insert_thrust_curve_point(75, 33750);
    engine.insert_thrust_curve_point(100, 45000);
    
    ASSERT_THAT(engine.get_thrust(37.5), 16875);
}

TEST(EngineThrustCurve, FullCurveOutsideLowerPoint) {
    Engine engine;
    
    engine.insert_thrust_curve_point(50, 22500);
    engine.insert_thrust_curve_point(75, 33750);
    engine.insert_thrust_curve_point(100, 45000);
    
    ASSERT_THAT(engine.get_thrust(25), 11250);
}

TEST(EngineThrustCurve, FullCurveOutsideUpperPoint) {
    Engine engine;
    
    engine.insert_thrust_curve_point(0, 0.0);
    engine.insert_thrust_curve_point(25, 11250);
    engine.insert_thrust_curve_point(50, 22500);
        
    ASSERT_THAT(engine.get_thrust(75), 33750);
}
