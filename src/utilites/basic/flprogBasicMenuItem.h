#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogAbstractMenuItem.h"

class FLProgBasicMenuItem : public FLProgAbstractMenuItem
{
public:
    virtual void setStep(double value) { _step = value; };
    virtual void setConverType(uint8_t value) { _convertType = value; };
    virtual uint8_t convertType() { return _convertType; };

protected:
    void privatePressSymbolButton(char value);
    void privatePressBacspaceButton();
    double _step = 1;
    uint16_t _convertType = FLPROG_MENU_DEC_CONVERT_TYPE;
};
