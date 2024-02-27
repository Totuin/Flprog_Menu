#include "flprogDoubleAccelerationValueController.h"

bool FLProgDoubleAccelerationValueController::valueUpButtonStatus(bool status)
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
bool FLProgDoubleAccelerationValueController::valueDownButtonStatus(bool status)
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
    isCanDoubleEvents = false;
    return false;
}

bool FLProgDoubleAccelerationValueController::checkStatus()
{
    if (isCanDoubleEvents)
    {
        if (flprog::isTimer(lastEventTime, doubleUpdatePeriod))
        {
            lastEventTime = millis();
            return true;
        }
        return false;
    }

    if (isCanEvents)
    {
        if (flprog::isTimer(startPressTime, doubleStartAccelerationTime))
        {
            isCanDoubleEvents = true;
        }
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
        startPressTime = millis();
        lastEventTime = millis();
        return true;
    }
    return false;
}

void FLProgDoubleAccelerationValueController::reset()
{
    _oldValueUpStatus = false;
    _oldValueDownStatus = false;
    isCanEvents = false;
    isCanDoubleEvents = false;
}
