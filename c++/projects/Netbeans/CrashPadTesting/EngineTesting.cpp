#include "gmock/gmock.h" 
#include "Engine.h"
#include "CrashPadUtils.h"

using namespace Model;
using namespace testing;

TEST(EngineConsumptionCurve, FullCurveOnPoint) {
    Engine engine;
    
    engine.insert_thrust_curve_point(0, 0.0);
    engine.insert_thrust_curve_point(10, 20.0);
    engine.insert_thrust_curve_point(20, 40.0);
    engine.insert_thrust_curve_point(30, 60.0);
    engine.insert_thrust_curve_point(40, 80.0);
    engine.insert_thrust_curve_point(50, 100.0);
    engine.insert_thrust_curve_point(60, 120.0);
    engine.insert_thrust_curve_point(70, 140.0);
    engine.insert_thrust_curve_point(80, 160.0);
    engine.insert_thrust_curve_point(90, 180.0);
    engine.insert_thrust_curve_point(100, 200.0);
    
    ASSERT_THAT(engine.get_burn_rate(50), 100);
}

TEST(EngineConsumptionCurve, FullCurveBetweenPoint) {
    Engine engine;
    
    engine.insert_thrust_curve_point(0, 0.0);
    engine.insert_thrust_curve_point(10, 20.0);
    engine.insert_thrust_curve_point(20, 40.0);
    engine.insert_thrust_curve_point(30, 60.0);
    engine.insert_thrust_curve_point(40, 80.0);
    engine.insert_thrust_curve_point(50, 100.0);
    engine.insert_thrust_curve_point(60, 120.0);
    engine.insert_thrust_curve_point(70, 140.0);
    engine.insert_thrust_curve_point(80, 160.0);
    engine.insert_thrust_curve_point(90, 180.0);
    engine.insert_thrust_curve_point(100, 200.0);
    
    ASSERT_THAT(engine.get_burn_rate(45), 90);
}
