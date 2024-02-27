#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogAbstractValueController.h"


class FLProgDoubleAccelerationValueController : public FLProgAbstractValueController
{
public:
    FLProgDoubleAccelerationValueController(){};

    virtual bool valueUpButtonStatus(bool status);
    virtual bool valueDownButtonStatus(bool status);
    virtual void setAccelerationTime(uint32_t time) { startAccelerationTime = time; };
    virtual void setAccelerationPeriog(uint32_t time) { updatePeriod = time; };
    virtual void setDoubleAccelerationTime(uint32_t time) { doubleStartAccelerationTime = time; };
    virtual void setDoubleAccelerationPeriog(uint32_t time) { doubleUpdatePeriod = time; };
    virtual void reset();

protected:
    bool checkStatus();
    uint32_t startPressTime;
    uint32_t lastEventTime;
    uint32_t startAccelerationTime;
    uint32_t doubleStartAccelerationTime;
    uint32_t updatePeriod;
    uint32_t doubleUpdatePeriod;
    bool _oldValueUpStatus = false;
    bool _oldValueDownStatus = false;
    bool isCanEvents = false;
    bool isCanDoubleEvents = false;
};
