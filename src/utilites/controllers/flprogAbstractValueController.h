#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

#define FLPROG_MENU_NO_VALUE_CONTROLLER 0
#define FLPROG_MENU_SINGLE_IMPULSE_VALUE_CONTROLLER 1
#define FLPROG_MENU_ACCELERATION_VALUE_CONTROLLER 2
#define FLPROG_MENU_DOUBLE_ACCELERATION_VALUE_CONTROLLER 3

class FLProgAbstractValueController
{
public:
    virtual bool valueUpButtonStatus(bool status) = 0;
    virtual bool valueDownButtonStatus(bool status) = 0;
    virtual void reset() = 0;

    virtual void setAccelerationTime(uint32_t time) { (void)time; };
    virtual void setAccelerationPeriog(uint32_t time) { (void)time; };
    virtual void setDoubleAccelerationTime(uint32_t time) { (void)time; };
    virtual void setDoubleAccelerationPeriog(uint32_t time) { (void)time; };
};