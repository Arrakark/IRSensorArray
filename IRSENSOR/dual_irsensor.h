#ifndef DUAL_IRARRAY_H
#define DUAL_IRARRAY_H

#include "Arduino.h"
#include <irsensor.h>

class dual_irsensor : public irsensor
{
  public:
    dual_irsensor(irsensor * left_sensor, irsensor * right_sensor);
    void update();
    float max_distance();
    float min_distance();
    float weighted_mean();
    float inverse_weighted_mean();
    float mean();
    int max_position();
    int min_position();
    int adc_readings[16];
    float distance_readings[16];
    
  private:
    irsensor * left_sensor;
    irsensor * right_sensor;
    int SENSOR_COUNT;
};

#endif