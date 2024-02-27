#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogAbstractValueController.h"


class FLProgSingleImpulseValueController : public FLProgAbstractValueController
{
public:
    FLProgSingleImpulseValueController(){};

    virtual bool valueUpButtonStatus(bool status);
    virtual bool valueDownButtonStatus(bool status);
    virtual void reset(){};

protected:
    bool _oldValueUpStatus = false;
    bool _oldValueDownStatus = false;
};