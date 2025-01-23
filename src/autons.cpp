#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/adi.h"
#include "pros/rtos.hpp"

//Assets
ASSET(SkillsP1_txt)
ASSET(SkillsP2_txt)

void moveRelative(float distance, float maxSpeed, int timeout) {
    double headingRadians = chassis.getPose(true).theta;
    double startingX = chassis.getPose().x;
    double startingY = chassis.getPose().y;
    double deltaX = distance * sin(headingRadians);
    double deltaY = distance * cos(headingRadians);
    double newX = startingX + deltaX;
    double newY = startingY + deltaY;
    if (distance > 0) {
        chassis.moveToPoint(newX, newY, timeout, {.forwards=true, .maxSpeed=maxSpeed});
    }
    else if (distance < 0) {
        chassis.moveToPoint(newX, newY, timeout, {.forwards=false, .maxSpeed=maxSpeed});
    }
};

void redSoloWP(){
    Clamp.set_value(LOW);
    chassis.setPose(0, 0, 323);
    chassis.moveToPose(-7.5, 9.5, 323, 2000, {.maxSpeed = 110, .minSpeed = 60});
    chassis.waitUntil(7);
    currState = 3;
    target = states[currState];
    pros::delay(1250);
    currState = 0;
    target = states[currState];
    chassis.moveToPose(20, -21, 323, 2500, {.forwards=false, .maxSpeed = 90, .minSpeed = 60}, false);
    pros::delay(750);
    Clamp.set_value(HIGH);
    pros::delay(250);
    intake.move(-127);
    chassis.turnToPoint(40, -25.5, 1000);
    chassis.moveToPose(40, -25.5, 110, 1500, {.maxSpeed = 110, .minSpeed = 60});
    pros::delay(750);
    chassis.turnToPoint(44, -35, 1000);
    chassis.moveToPoint(44, -35, 1500, {.maxSpeed = 110, .minSpeed = 60});
    pros::delay(750);
    chassis.moveToPose(45, -30, 90, 2000, {.forwards=false, .maxSpeed = 110, .minSpeed = 60});
    chassis.moveToPose(-10, -30, 90, 4000, {.maxSpeed = 60, .minSpeed = 50});
}

void blueSoloWP(){
    Clamp.set_value(LOW);
    chassis.setPose(0, 0, 37);
    chassis.moveToPose(7.5, 9.5, 37, 2000, {.maxSpeed = 110, .minSpeed = 60});
    chassis.waitUntil(7);
    currState = 3;
    target = states[currState];
    pros::delay(1250);
    currState = 0;
    target = states[currState];
    chassis.moveToPose(-20, -21, 37, 2500, {.forwards=false, .maxSpeed = 90, .minSpeed = 60}, false);
    pros::delay(750);
    Clamp.set_value(HIGH);
    pros::delay(250);
    intake.move(-127);
    chassis.turnToPoint(-40, -25.5, 1000);
    chassis.moveToPose(-40, -25.5, 110, 1500, {.maxSpeed = 110, .minSpeed = 60});
    pros::delay(750);
    chassis.turnToPoint(-44, -35, 1000);
    chassis.moveToPoint(-44, -35, 1500, {.maxSpeed = 110, .minSpeed = 60});
    pros::delay(750);
    chassis.moveToPose(-45, -30, 90, 2000, {.forwards=false, .maxSpeed = 110, .minSpeed = 60});
    chassis.moveToPose(10, -30, 90, 4000, {.maxSpeed = 60, .minSpeed = 50});
}

void redGoalRush(){
    chassis.setPose(-58.367, -32.377,90);
    preroller.move(-127);
    chassis.moveToPoint(-9.629, -51.226, 1500, {.maxSpeed=100, .minSpeed=60});
    inLift.set_value(HIGH);
    pros::delay(750);
    chassis.moveToPose(-23.092, -41.801, 180, 1500, {.forwards=false, .maxSpeed=100, .minSpeed=60}, false);
    inLift.set_value(LOW);
    chassis.moveToPoint(-23.631, -23.491, 1500, {.forwards=false, .maxSpeed=85, .minSpeed=60}, false);
    Clamp.set_value(HIGH);
    pros::delay(1500);
    intake.move(-127);
}

void blueGoalRush(){
    chassis.setPose(58.765, -59.842,270);
    preroller.move(-127);
    chassis.moveToPoint(10.028, -45.571, 1500, {.maxSpeed=100, .minSpeed=60});
    inLift.set_value(HIGH);
    pros::delay(750);
    chassis.moveToPose(25.376, -40.186, 180, 1500, {.forwards=false, .maxSpeed=100, .minSpeed=60}, false);
    inLift.set_value(LOW);
    chassis.moveToPoint(23.491, -24.299, 1500, {.forwards=false, .maxSpeed=85, .minSpeed=60}, false);
    Clamp.set_value(HIGH);
    pros::delay(1500);
    intake.move(-127);
}

void disruptRed(){
    chassis.setPose(-46.489,31.313,70);
    inLift.set_value(HIGH);
    chassis.moveToPoint(-6, 46, 2000, {.maxSpeed = 100});
    chassis.moveToPoint(-23.5, 47, 1500, {.forwards = false, .maxSpeed = 60}, false);
    chassis.turnToPoint(-23.5, 23.5, 1000, {.forwards = false});
    chassis.moveToPoint(-23.5, 23.5, 1250, {.forwards = false, .maxSpeed = 60}, false);
    Clamp.set_value(HIGH);
    chassis.moveToPoint(-23.5, 23.5, 750, {.forwards = false, .maxSpeed = 70}, false);
    intake.move(127);
    inLift.set_value(LOW);
    pros::delay(200);
    chassis.moveToPoint(-19.341, 41.123, 1000);
    chassis.swingToHeading(180, lemlib::DriveSide::LEFT, 1250, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .maxSpeed = 60});
    chassis.turnToPoint(-48.191, 19.983, 1500);
    chassis.moveToPoint(-48.191, 19.983, 1500);
}

void disruptBlue(){
    chassis.setPose(46.489,31.313,290);
    inLift.set_value(HIGH);
    chassis.moveToPoint(6, 46, 2000, {.maxSpeed = 100});
    chassis.moveToPoint(23.5, 47, 1500, {.forwards = false, .maxSpeed = 60}, false);
    chassis.turnToPoint(23.5, 23.5, 1000, {.forwards = false});
    chassis.moveToPoint(23.5, 23.5, 1250, {.forwards = false, .maxSpeed = 60}, false);
    Clamp.set_value(HIGH);
    chassis.moveToPoint(23.5, 23.5, 750, {.forwards = false, .maxSpeed = 70}, false);
    intake.move(127);
    inLift.set_value(LOW);
    pros::delay(200);
    chassis.moveToPoint(19.341, 41.123, 1000);
    chassis.swingToHeading(180, lemlib::DriveSide::RIGHT, 1250, {.direction = AngularDirection::CW_CLOCKWISE, .maxSpeed = 60});
    chassis.turnToPoint(48.191, 19.983, 1500);
    chassis.moveToPoint(48.191, 19.983, 1500);
}

void rushRed(){
    chassis.setPose(51, -60,90);
    chassis.moveToPoint(15, -60, 1250, {.forwards = false});
    chassis.turnToPoint(8.61, -53.904, 1000);
    chassis.moveToPoint(8.61, -53.904, 1000);
}

void rushBlue(){
    chassis.setPose(51, -60,90);
    chassis.moveToPoint(15, -60, 1100, {.forwards = false});
    chassis.turnToPoint(8.61, -55, 650, {.forwards = false});
    chassis.moveToPoint(6, -53, 1000, {.forwards = false, .maxSpeed = 80}, false);
    // Clamp.set_value(HIGH);
    // intake.move(127);
    // pros::delay(100);
    // chassis.swingToPoint(25.42, -41.763, lemlib::DriveSide::LEFT, 1000);
}

void skills(){
    chassis.setPose(0, 0,30);
    currState = 3;
    target = states[currState];
    pros::delay(750);
    currState = 2;
    target = states[currState];
    chassis.moveToPoint(-16, -12, 1100, {.forwards = false, .maxSpeed=50}, false);
    pros::delay(250);
    Clamp.set_value(HIGH);
    pros::delay(250);
    chassis.turnToPoint(-20, -36, 1000);
    intake.move(-127);
    chassis.moveToPoint(-20, -34, 1250, {.maxSpeed=80, .minSpeed=70});
    // chassis.turnToPoint(-46, -86, 1500, {.maxSpeed=80, .minSpeed=70});
    // chassis.moveToPoint(-40, -86, 1500, {.maxSpeed=80, .minSpeed=70}, false);
    //pros::delay(1750);
    //chassis.moveToPoint(-46, -109, 1000, {.maxSpeed=80, .minSpeed=70}, false);

    //wall stake
    // currState = 1;
    // target = states[currState];
    // pros::delay(500);
    // chassis.moveToPoint(-40, -70, 1500, {.forwards=false, .maxSpeed=70, .minSpeed=60}, false);
    chassis.turnToPoint(-82, -84, 1000);
    chassis.moveToPoint(-82, -84, 1000, {.maxSpeed=80}, false);
    // intake.move(0);
    // currState = 3;
    // target = states[currState];
    // pros::delay(1000);
    // intake.move(-127);
    // currState = 2;
    // target = states[currState];
    // pros::delay(750);

    //other four
    //chassis.moveToPoint(-47, -70, 1500, {.forwards=false, .maxSpeed=80, .minSpeed=60}, false);
    chassis.turnToPoint(-44, -20, 1000);
    chassis.moveToPoint(-44, 0, 1500, {.maxSpeed=65, .minSpeed=50}, false);
    chassis.moveToPoint(-30, -12, 1500, {.forwards=false, .maxSpeed=80});
    chassis.moveToPoint(-53, -12, 1500, {.maxSpeed=80});
    chassis.turnToPoint(0, -100, 1000);
    chassis.moveToPoint(-60, 0, 1000, {.forwards=false, .maxSpeed=90});
    Clamp.set_value(LOW);
    currState = 0;
    target = states[currState];
    intake.move(0);
    chassis.moveToPoint(-53, -20, 1000, {.maxSpeed=90});
    
    //second goal
    chassis.moveToPoint(20, -5, 2500, {.forwards=false, .maxSpeed=60}, false);
    pros::delay(250);
    Clamp.set_value(HIGH);
    intake.move(-127);

    //first second donut
    chassis.turnToPoint(30, -28, 1000);
    chassis.moveToPoint(30, -28, 1500, {.maxSpeed=85});

    //second second
    chassis.turnToPoint(63, -50, 1000);
    chassis.moveToPoint(63, -50, 1000, {.maxSpeed=85});

    //other four
    chassis.turnToPoint(49, -30, 1000);
    chassis.moveToPoint(49, -30, 1500, {.maxSpeed=85});
    chassis.turnToPoint(49, 0, 1000);
    chassis.moveToPoint(49, 0, 1500, {.maxSpeed=65});
    chassis.moveToPoint(35, -2, 1000, {.forwards=false, .maxSpeed=85});
    chassis.moveToPoint(60, -2, 1500,{.maxSpeed=85});
    chassis.turnToPoint(0, -100, 1000);
    chassis.moveToPoint(65, 8, 1000, {.forwards=false, .maxSpeed=85});
    Clamp.set_value(LOW);
    chassis.moveToPoint(-38, -99, 3500, {.maxSpeed=90});
    chassis.waitUntil(80);
    intake.move(0);
    chassis.turnToPoint(-82, -84, 1000);
    chassis.moveToPoint(65, -115, 5000, {.forwards=false, .maxSpeed=85}, false);
    chassis.moveToPoint(-65, -115, 5000);
    // Clamp.set_value(HIGH);
    // chassis.moveToPoint(-40, -120, 1500, {.maxSpeed=85});
    // intake.move(-127);
}
