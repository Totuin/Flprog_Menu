#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEEPROM.h"
#include "../types/flprogBooleanMenuItem.h"

class FLProgEepromBooleanMenuItem : public FLProgBooleanMenuItem
{
public:
    FLProgEepromBooleanMenuItem(String name, FLProgAbstractEEPROM *chip, uint16_t addres, uint8_t bit, bool isBuffered = true, uint8_t aditionalsStringsCount = 0);

    virtual void saveBuffer();
    virtual void setBooleanValue(bool value);
    void initValue();

protected:
    bool _isBuffered;
    FLProgAbstractEEPROM *_chip;
    uint16_t _addres;
    uint8_t _bit;
};
