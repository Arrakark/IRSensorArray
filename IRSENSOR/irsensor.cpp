/*
 *  IR Sensor Library
 *  How to use:
 *  Create new irsensor object:
 *      irsensor main_sensor = irsensor(0x49, lookup_table);
 *      the 0x49 is the address for the sensor (see sensor inventory in gdrive)
 *      the lookup_table is a calibration table for the sensor.
 *      See the example ir_distance_sensing.ino
 *      More calibration data is availible on gdrive
 *  Enable wire library:
 *      Wire.begin();
 *  Get new data from the sensor:  
 *      main_sensor.update();
 *  Acccess the methods of the sensor:
 *      main_sensor.max_position(); //returns the integer position of the max distance
 *      main_sensor.adc_readings[x]; //returns the x-positioned adc reading
 *      main_sensor.distance_readings[x] //returns the distance that a certain ir sensor sees
 *  
 *  TODO:
 *      currently the max # of sensors is 4 on each I2C line
 *      we will need 2 I2C lines to support 5 sensors
 *      need to implement selection of I2C bus
 */

#include "irsensor.h"

//create new irsensor array
irsensor::irsensor(unsigned char _adress, int _lookup_table[ROW][COL]) : adc(_adress)
{
    //adc.init(); do not call this function; call it in setup
    lookup_table = _lookup_table;
    SENSOR_COUNT = 8;
}

//default const do not use
irsensor::irsensor() : adc()
{
}

//get new readings from the sensor
void irsensor::update()
{
    // Serial.println("Updating ir sensor readings......");
    for (int x = 0; x < SENSOR_COUNT; x++)
    {
        adc_readings[x] = adc.read(x, SD);
    }
    // Serial.println("Starting get distance");
    get_distance();
}

//returns the position (0-7) of the maximum value
int irsensor::max_position()
{
    float max_value = MIN_VALUE;
    int max_position = 0;
    for (int x = 0; x < SENSOR_COUNT; x++)
    {
        if (distance_readings[x] > max_value)
        {
            max_value = distance_readings[x];
            max_position = x;
        }
    }
    return max_position;
}

//returns the position (0-7) of the minimum value
int irsensor::min_position()
{
    float min_value = MAX_VALUE;
    int min_position = 0;
    for (int x = 0; x < SENSOR_COUNT; x++)
    {
        if (distance_readings[x] < min_value)
        {
            min_value = distance_readings[x];
            min_position = x;
        }
    }
    return min_position;
}

//returns the max distance measured (MIN_VALUE-MAX_VALUE) in cm
float irsensor::max_distance()
{
    float max = MIN_VALUE;
    for (int x = 0; x < SENSOR_COUNT; x++)
    {
        if (distance_readings[x] > max)
        {
            max = distance_readings[x];
        }
    }
    return max;
}

//returns the min distance measured (MIN_VALUE-MAX_VALUE) in cm
float irsensor::min_distance()
{
    float min = MAX_VALUE;
    for (int x = 0; x < SENSOR_COUNT; x++)
    {
        if (distance_readings[x] < min)
        {
            min = distance_readings[x];
        }
    }
    return min;
}

//returns the weighted mean of values; to be used w/line following
float irsensor::weighted_mean()
{
    float t_sum = 0;
    float b_sum = 0;

    for (int x = 0; x < SENSOR_COUNT; x++)
    {
        t_sum = t_sum + distance_readings[x] * (x + 1);
        b_sum = b_sum + distance_readings[x];
    }

    if (b_sum > 0.1)
    {
        return t_sum / b_sum;
    }
    return 4.5;
}

//returns the inverse weighted mean; this means it takes the difference from the max value
//and uses that to compute the weighted mean
//to be used with ewok detection
float irsensor::inverse_weighted_mean()
{
    float t_sum = 0;
    float b_sum = 0;
    for (int x = 0; x < SENSOR_COUNT; x++)
    {
        t_sum = t_sum + (MAX_VALUE - distance_readings[x]) * (x + 1);
        b_sum = b_sum + (MAX_VALUE - distance_readings[x]);
    }
    if (b_sum > 0.1)
    {
        return t_sum / b_sum;
    }
    return 4.5;
}

//returns the mean (average)
//can be used for detecting cliffs
float irsensor::mean()
{
    float t_sum = 0;
    for (int x = 0; x < SENSOR_COUNT; x++)
    {
        t_sum += distance_readings[x];
    }
    return t_sum / SENSOR_COUNT;
}

void irsensor::info()
{
    update();
    for (int i = 0; i < 8; i++)
    {
        Serial.print(distance_readings[i]);
        Serial.print(" ");
    }
    Serial.println();
}

//private function for calculating the distance from the raw values
void irsensor::get_distance()
{
    int ind;  //indices in data array
    int flag; //boolean used for calculating distance

    int i, j;

    //calculating distances measured in sensor array
    for (i = 0; i < SENSOR_COUNT; i++)
    {

        flag = 0;
        ind = 0;

        //find corresponding indices in data array
        for (j = 0; j < ROW; j++)
        {
            if (lookup_table[j][i + 1] >= adc_readings[i])
            {
                ind = j;
                flag = 1;
                break;
            }
        }

        //calculate distance

        if (!flag)
        {
            //if sensor measured distance is greater than values in data array, let sensor distance = 100
            distance_readings[i] = MAX_VALUE;
        }

        else
        {
            if (ind > 0 && i > -1 && ind < ROW && i < 8)
            {
                //calculating slope and y-intercpet : y = mx + b
                int x2 = lookup_table[ind][i + 1];

                int y2 = lookup_table[ind][0];

                int x1 = lookup_table[ind - 1][i + 1];
                int y1 = lookup_table[ind - 1][0];
                if (x2 - x1 == 0)
                {
                    return;
                }

                float m = ((float)(y2 - y1)) / (x2 - x1);
                float b = y2 - m * x2;

                distance_readings[i] = (int)(m * adc_readings[i] + b);

                //set negative distances to zero
                if (distance_readings[i] < MIN_VALUE)
                    distance_readings[i] = MIN_VALUE;
                else if (distance_readings[i] > MAX_VALUE)
                    distance_readings[i] = MAX_VALUE;
            }

            else
            {
                distance_readings[i] = MIN_VALUE;
            }
        }
    }
}