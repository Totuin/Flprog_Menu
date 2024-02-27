#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogAbstractValueController.h"


class FLProgAccelerationValueController : public FLProgAbstractValueController
{
public:
    FLProgAccelerationValueController(){};

    virtual bool valueUpButtonStatus(bool status);
    virtual bool valueDownButtonStatus(bool status);
    virtual void setAccelerationTime(uint32_t time) { startAccelerationTime = time; };
    virtual void setAccelerationPeriog(uint32_t time) { updatePeriod = time; };
    virtual void reset();

protected:
    bool checkStatus();
    uint32_t startPressTime;
    uint32_t lastEventTime;
    uint32_t startAccelerationTime;
    uint32_t updatePeriod;
    bool _oldValueUpStatus = false;
    bool _oldValueDownStatus = false;
    bool isCanEvents = false;
};
