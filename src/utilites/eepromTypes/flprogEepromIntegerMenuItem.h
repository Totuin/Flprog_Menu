#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEEPROM.h"
#include "../types/flprogIntegerMenuItem.h"

class FLProgEepromIntegerMenuItem : public FLProgIntegerMenuItem
{
public:
    FLProgEepromIntegerMenuItem(String name, FLProgAbstractEEPROM *chip, uint16_t addres, bool isBuffered = true, uint8_t aditionalsStringsCount = 0);

    virtual void saveBuffer();
    virtual void setIntegerValue(int16_t value);
    void initValue();

    virtual void setIntegeMinValue(int16_t value);

protected:
    bool _isBuffered;
    FLProgAbstractEEPROM *_chip;
    uint16_t _addres;
};


