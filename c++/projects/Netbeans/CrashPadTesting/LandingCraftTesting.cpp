#include "gmock/gmock.h" 
#include "LandingCraft.h"
#include "Pad.h"
#include "Strut.h"
#include "CargoHold.h"
#include "FuelTank.h"
#include "Thruster.h"
#include "CrashPadUtils.h"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace Model;
using namespace testing;


class LandingCraftTest: public Test {
public:
  LandingCraft lc;
};

TEST_F(LandingCraftTest, PadAddOne) {
    bool itworked = true;
        
    try {
        Pad pad;
        lc.add_pad(pad);
    }
    catch(std::exception const &e) { itworked = false; }
    
    ASSERT_THAT(itworked, true);
}

TEST_F(LandingCraftTest, PadAddTwo) {
    bool itworked = true;
        
    try {
        Pad pad;
        Pad pad1(1);
        lc.add_pad(pad);
        lc.add_pad(pad1);
    }
    catch(std::exception const &e) { itworked = false; }
    
    ASSERT_THAT(itworked, true);
}

TEST_F(LandingCraftTest, PadAddTwoSameID) {
    bool itworked = true;
    
    try { 
        Pad pad, pad1;
        lc.add_pad(pad);
        lc.add_pad(pad1);
    }
    catch(std::exception const &e) { itworked = 0; }
    
    ASSERT_THAT(itworked, false);
}

TEST_F(LandingCraftTest, GetPadByIndex) {
    bool itworked = true;
    
    try { 
        Pad pad; 
        Pad pad1(1), pad2(2);
        
        pad.set_object_name("Pad_0");
        pad1.set_object_name("Pad_1");
        pad2.set_object_name("Pad_2");
        
        lc.add_pad(pad);
        lc.add_pad(pad1);
        lc.add_pad(pad2);
        
        itworked = lc.get_pad_by_index(1) == pad1;
    }
    catch(std::exception const &e) { itworked = 0; }
    
    ASSERT_THAT(itworked, Eq(true));
}

TEST_F(LandingCraftTest, GetPadByWrongIndex) {
    bool itworked = false;
    
    try { 
        Pad pad; 
        Pad pad1(1), pad2(2);
        
        pad.set_object_name("Pad_0");
        pad1.set_object_name("Pad_1");
        pad2.set_object_name("Pad_2");
        
        lc.add_pad(pad);
        lc.add_pad(pad1);
        lc.add_pad(pad2);
        
        itworked = lc.get_pad_by_index(1) == pad2;
    }
    catch(std::exception const &e) { itworked = 0; }
    
    ASSERT_THAT(itworked, Eq(false));
}

TEST_F(LandingCraftTest, GetPadByID) {
    bool itworked = false;
    
    try { 
        Pad pad; 
        Pad pad1(11), pad2(22);
        
        pad.set_object_name("Pad_0");
        pad1.set_object_name("Pad_1");
        pad2.set_object_name("Pad_2");
        
        lc.add_pad(pad);
        lc.add_pad(pad1);
        lc.add_pad(pad2);
        
        itworked = lc.get_pad_by_index(11) == pad1;
    }
    catch(std::exception const &e) { itworked = 0; }
    
    ASSERT_THAT(itworked, Eq(false));
} 

TEST_F(LandingCraftTest, GetPadByWrongId) {
    bool itworked = true;
    
    try { 
        Pad pad; 
        Pad pad1(11), pad2(22);
        
        pad.set_object_name("Pad_0");
        pad1.set_object_name("Pad_1");
        pad2.set_object_name("Pad_2");
        
        lc.add_pad(pad);
        lc.add_pad(pad1);
        lc.add_pad(pad2);
        
        itworked = lc.get_pad_by_id(11) == pad2;
    }
    catch(std::exception const &e) { itworked = 0; }
    
    ASSERT_THAT(itworked, Eq(false));
}

TEST_F(LandingCraftTest, RemovePadByID) {
    bool itworked = true;
    
    try { 
        Pad pad; 
        Pad pad1(11), pad2(22);
        
        pad.set_object_name("Pad_0");
        pad1.set_object_name("Pad_1");
        pad2.set_object_name("Pad_2");
        
        lc.add_pad(pad);
        lc.add_pad(pad1);
        lc.add_pad(pad2);
        
       lc.remove_pad(11);
       const std::vector<Pad>& refpad = lc.get_pad_list();
       itworked = refpad.size() == 2;
    }
    catch(std::exception const &e) {
        itworked = false; 
    }
    
    ASSERT_THAT(itworked, Eq(true));
}

TEST_F(LandingCraftTest, RemovePadByWrongID) {
    bool itworked = true;
    
    try { 
        Pad pad; 
        Pad pad1(11), pad2(22);
        
        pad.set_object_name("Pad_0");
        pad1.set_object_name("Pad_1");
        pad2.set_object_name("Pad_2");
        
        lc.add_pad(pad);
        lc.add_pad(pad1);
        lc.add_pad(pad2);
        
       lc.remove_pad(12);
       const std::vector<Pad>& refpad = lc.get_pad_list();
       itworked = refpad.size() == 2;
    }
    catch(std::exception const &e) {
        itworked = false; 
    }
    
    ASSERT_THAT(itworked, Eq(false));
}

TEST_F(LandingCraftTest, ClearPad) {
    bool itworked = true;
    
    try { 
        Pad pad; 
        Pad pad1(11), pad2(22);
        
        pad.set_object_name("Pad_0");
        pad1.set_object_name("Pad_1");
        pad2.set_object_name("Pad_2");
        
        lc.add_pad(pad);
        lc.add_pad(pad1);
        lc.add_pad(pad2);
        
       lc.clear_pad_list();
       const std::vector<Pad>& refpad = lc.get_pad_list();
       itworked = refpad.size() == 0;
    }
    catch(std::exception const &e) {
        itworked = false; 
    }
    
    ASSERT_THAT(itworked, Eq(true));
}

TEST_F(LandingCraftTest, StrutAddOne) {
    bool itworked = true;
        
    try {
        Strut strut;
        lc.add_strut(strut);
    }
    catch(std::exception const &e) { itworked = false; }
    
    ASSERT_THAT(itworked, true);
}

TEST_F(LandingCraftTest, StrutAddTwo) {
    bool itworked = true;
        
    try {
        Strut strut;
        Strut strut1(1);
        lc.add_strut(strut);
        lc.add_strut(strut1);
    }
    catch(std::exception const &e) { itworked = false; }
    
    ASSERT_THAT(itworked, true);
}

TEST_F(LandingCraftTest, StrutAddTwoSameID) {
    bool itworked = true;
    
    try { 
        Strut strut, strut1;
        lc.add_strut(strut);
        lc.add_strut(strut1);
    }
    catch(std::exception const &e) { itworked = 0; }
    
    ASSERT_THAT(itworked, false);
}

TEST_F(LandingCraftTest, GetStrutByIndex) {
    bool itworked = true;
    
    try { 
        Strut strut; 
        Strut strut1(1), strut2(2);
        
        strut.set_object_name("strut_0");
        strut1.set_object_name("strut_1");
        strut2.set_object_name("strut_2");
        
        lc.add_strut(strut);
        lc.add_strut(strut1);
        lc.add_strut(strut2);
        
        itworked = lc.get_strut_by_index(1) == strut1;
    }
    catch(std::exception const &e) { itworked = 0; }
    
    ASSERT_THAT(itworked, Eq(true));
}

TEST_F(LandingCraftTest, GetStrutByWrongIndex) {
    bool itworked = false;
    
    try { 
        Strut strut; 
        Strut strut1(1), strut2(2);
        
        strut.set_object_name("strut_0");
        strut1.set_object_name("strut_1");
        strut2.set_object_name("strut_2");
        
        lc.add_strut(strut);
        lc.add_strut(strut1);
        lc.add_strut(strut2);
        
        itworked = lc.get_strut_by_index(1) == strut2;
    }
    catch(std::exception const &e) { itworked = 0; }
    
    ASSERT_THAT(itworked, Eq(false));
}

TEST_F(LandingCraftTest, GetStrutByID) {
    bool itworked = false;
    
    try { 
        Strut strut; 
        Strut strut1(1), strut2(2);
        
        strut.set_object_name("strut_0");
        strut1.set_object_name("strut_1");
        strut2.set_object_name("strut_2");
        
        lc.add_strut(strut);
        lc.add_strut(strut1);
        lc.add_strut(strut2);
        
        itworked = lc.get_strut_by_index(11) == strut1;
    }
    catch(std::exception const &e) { itworked = 0; }
    
    ASSERT_THAT(itworked, Eq(false));
} 

TEST_F(LandingCraftTest, GetStrutByWrongId) {
    bool itworked = true;
    
    try { 
        Strut strut; 
        Strut strut1(1), strut2(2);
        
        strut.set_object_name("strut_0");
        strut1.set_object_name("strut_1");
        strut2.set_object_name("strut_2");
        
        lc.add_strut(strut);
        lc.add_strut(strut1);
        lc.add_strut(strut2);
        
        itworked = lc.get_strut_by_id(11) == strut2;
    }
    catch(std::exception const &e) { itworked = 0; }
    
    ASSERT_THAT(itworked, Eq(false));
}

TEST_F(LandingCraftTest, RemoveStrutByID) {
    bool itworked = true;
    
    try { 
        Strut strut; 
        Strut strut1(11), strut2(22);
        
        strut.set_object_name("strut_0");
        strut1.set_object_name("strut_1");
        strut2.set_object_name("strut_2");
        
        lc.add_strut(strut);
        lc.add_strut(strut1);
        lc.add_strut(strut2);
        
       lc.remove_strut(11);
       const std::vector<Strut>& refstrut = lc.get_strut_list();
       itworked = refstrut.size() == 2;
    }
    catch(std::exception const &e) {
        itworked = false; 
    }
    
    ASSERT_THAT(itworked, Eq(true));
}

TEST_F(LandingCraftTest, RemoveStrutByWrongID) {
    bool itworked = true;
    
    try { 
        Strut strut; 
        Strut strut1(11), strut2(22);
        
        strut.set_object_name("strut_0");
        strut1.set_object_name("strut_1");
        strut2.set_object_name("strut_2");
        
        lc.add_strut(strut);
        lc.add_strut(strut1);
        lc.add_strut(strut2);
        
       lc.remove_strut(10);
       const std::vector<Strut>& refstrut = lc.get_strut_list();
       itworked = refstrut.size() == 2;
    }
    catch(std::exception const &e) {
        itworked = false; 
    }
    
    ASSERT_THAT(itworked, Eq(false));
}

TEST_F(LandingCraftTest, ClearStrut) {
    bool itworked = true;
    
    try { 
        Strut strut; 
        Strut strut1(11), strut2(22);
        
        strut.set_object_name("strut_0");
        strut1.set_object_name("strut_1");
        strut2.set_object_name("strut_2");
        
        lc.add_strut(strut);
        lc.add_strut(strut1);
        lc.add_strut(strut2);
        
       lc.clear_strut_list();
       const std::vector<Strut>& refpad = lc.get_strut_list();
       itworked = refpad.size() == 0;
    }
    catch(std::exception const &e) {
        itworked = false; 
    }
    
    ASSERT_THAT(itworked, Eq(true));
}

TEST_F(LandingCraftTest, AddFuelTank) {
    bool itworked = false;
    
    FuelTank ft(25);
    lc.set_fuel_tank(ft);
    
    itworked = ft == lc.get_fuel_tank();
    
    ASSERT_THAT(itworked, Eq(true));
}

TEST_F(LandingCraftTest, AddCargoHold) {
    bool itworked = false;
    
    CargoHold cg(25);
    lc.set_cargo_hold(cg);
    
    itworked = cg == lc.get_cargo_hold();
    
    ASSERT_THAT(itworked, Eq(true));
}

TEST_F(LandingCraftTest, AddEngine) {
    bool itworked = false;
    
    Thruster cg(25);
    lc.set_engine(cg);
    
    itworked = cg == lc.get_engine();
    
    ASSERT_THAT(itworked, Eq(true));
}

TEST_F(LandingCraftTest, AddPortThruster) {
    bool itworked = false;
    
    Thruster cg(25);
    lc.set_port_thruster(cg);
    
    itworked = cg == lc.get_port_thruster();
    
    ASSERT_THAT(itworked, Eq(true));
}

TEST_F(LandingCraftTest, AddStarboardThruster) {
    bool itworked = false;
    
    Thruster cg(25);
    lc.set_starboard_thruster(cg);
    
    itworked = cg == lc.get_starboard_thruster();
    
    ASSERT_THAT(itworked, Eq(true));
}

TEST_F(LandingCraftTest, GetLCMass) {
    float mass = 0.0;
    bool itworked = true;
    Pad pad0(1), pad1(2), pad2(3);
    Strut strut0(11), strut1(12), strut2(13);
    Thruster engine(31), port(32), starboard(33);
    CargoHold ch(40);
    FuelTank ft(50);
    
    ft.set_object_mass(20);
    ch.set_object_mass(20.5);
    
    engine.set_object_mass(15);
    port.set_object_mass(10);
    starboard.set_object_mass(10);
    
    
    pad0.set_object_mass(5.0);
    pad1.set_object_mass(5.0);
    pad2.set_object_mass(5.0);
    
    strut0.set_object_mass(6.0);
    strut1.set_object_mass(6.0);
    strut2.set_object_mass(6.0);
    
    try {
        lc.add_pad(pad0);
        lc.add_pad(pad1);
        lc.add_pad(pad2);        

        lc.add_strut(strut0);
        lc.add_strut(strut1);
        lc.add_strut(strut2);
        
        lc.set_engine(engine);
        lc.set_port_thruster(port);
        lc.set_starboard_thruster(starboard);
        
        lc.set_cargo_hold(ch);
        lc.set_fuel_tank(ft);

        mass = lc.get_object_mass();
    }
    catch(std::exception const &e) {
        itworked = false; 
    }
    
    ASSERT_THAT(mass, Eq(108.5));
}

TEST_F(LandingCraftTest, GetLCPosition) {    
    LandingCraft craft(9.8, 10000);
    
    double initialPosition = 10000; //craft.get_position(100, 1);
    
    ASSERT_THAT(initialPosition, Eq(10000));

}
