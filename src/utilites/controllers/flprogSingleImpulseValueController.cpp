#include "flprogSingleImpulseValueController.h"

bool FLProgSingleImpulseValueController::valueUpButtonStatus(bool status)
{
    if (status)
    {
        if (!_oldValueUpStatus)
        {
            _oldValueUpStatus = true;
            return true;
        }
        return false;
    }
    _oldValueUpStatus = false;
    return false;
}

bool FLProgSingleImpulseValueController::valueDownButtonStatus(bool status)
{
    if (status)
    {
        if (!_oldValueDownStatus)
        {
            _oldValueDownStatus = true;
            return true;
        }
        return false;
    }
    _oldValueDownStatus = false;
    return false;
}