#ifndef IRSENSOR_H
#define IRSENSOR_H

#include "Arduino.h"
#include <ADS7828.h> // Include ADS7828.h for TI ADS7828 functions

#define ROW 20
#define COL 9
#define MAX_VALUE 30
#define MIN_VALUE 0

class irsensor
{
  public:
    irsensor();
    irsensor(unsigned char, int lookup_table[ROW][COL]);
    void update();
    virtual float max_distance();
    virtual float min_distance();
    virtual float weighted_mean();
    virtual float inverse_weighted_mean();
    virtual float mean();
    virtual int max_position();
    virtual int min_position();
    int adc_readings[8];
    float distance_readings[8];
    virtual void info();
    
  private:
    ADS7828 adc;
    void get_distance();
    int (*lookup_table)[COL];
    int SENSOR_COUNT;
};

#endif