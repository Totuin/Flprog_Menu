#include "flprogAccelerationValueController.h"

bool FLProgAccelerationValueController::valueUpButtonStatus(bool status)
{
    if (_oldValueDownStatus)
    {
        return false;
    }
    if (status)
    {
        if (!_oldValueUpStatus)
        {
            _oldValueUpStatus = true;
            startPressTime = millis();
            return true;
        }
        return checkStatus();
    }
    _oldValueUpStatus = false;
    isCanEvents = false;
    return false;
}
bool FLProgAccelerationValueController::valueDownButtonStatus(bool status)
{
    if (_oldValueUpStatus)
    {
        return false;
    }
    if (status)
    {
        if (!_oldValueDownStatus)
        {
            _oldValueDownStatus = true;
            startPressTime = millis();
            return true;
        }
        return checkStatus();
    }
    _oldValueDownStatus = false;
    isCanEvents = false;
    return false;
}

bool FLProgAccelerationValueController::checkStatus()
{
    if (isCanEvents)
    {
        if (flprog::isTimer(lastEventTime, updatePeriod))
        {
            lastEventTime = millis();
            return true;
        }
        return false;
    }
    if (flprog::isTimer(startPressTime, startAccelerationTime))
    {
        isCanEvents = true;
        lastEventTime = millis();
        return true;
    }
    return false;
}

void FLProgAccelerationValueController::reset()
{
    _oldValueUpStatus = false;
    _oldValueDownStatus = false;
    isCanEvents = false;
}