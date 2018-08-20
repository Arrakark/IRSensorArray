#include <dual_irsensor.h>

dual_irsensor::dual_irsensor(irsensor *_left_sensor, irsensor *_right_sensor) : irsensor()
{
    left_sensor = _left_sensor;
    right_sensor = _right_sensor;
    SENSOR_COUNT = 16;
}

void dual_irsensor::update()
{
    //update individual arrays
    left_sensor->update();
    right_sensor->update();

    //concatenate the readings
    for (int i = 0; i < 8; i++)
    {
        adc_readings[i] = left_sensor->adc_readings[i];
    }
    for (int i = 8; i < 16; i++)
    {
        adc_readings[i] = right_sensor->adc_readings[i - 8];
    }

    //concatenate distances
    for (int i = 0; i < 8; i++)
    {
        distance_readings[i] = left_sensor->distance_readings[i];
    }
    for (int i = 8; i < 16; i++)
    {
        distance_readings[i] = right_sensor->distance_readings[i - 8];
    }
}

//returns the position (0-15) of the maximum value
int dual_irsensor::max_position()
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

//returns the position (0-15) of the minimum value
int dual_irsensor::min_position()
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
float dual_irsensor::max_distance()
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
float dual_irsensor::min_distance()
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
float dual_irsensor::weighted_mean()
{
    float t_sum = 0;
    float b_sum = 0;
    for (int x = 0; x < SENSOR_COUNT; x++)
    {
        t_sum = t_sum + distance_readings[x] * (x + 1);
        b_sum = b_sum + distance_readings[x];
    }
    if (b_sum != 0)
    {
        return t_sum / b_sum;
    }
    return 8.5;
}

//returns the inverse weighted mean; this means it takes the difference from the max value
//and uses that to compute the weighted mean
//to be used with ewok detection
float dual_irsensor::inverse_weighted_mean()
{
    float t_sum = 0;
    float b_sum = 0;
    for (int x = 0; x < SENSOR_COUNT; x++)
    {
        t_sum = t_sum + (MAX_VALUE - distance_readings[x]) * (x + 1);
        b_sum = b_sum + (MAX_VALUE - distance_readings[x]);
    }
    if (b_sum != 0)
    {
        return t_sum / b_sum;
    }
    return 8.5;
}

//returns the mean (average)
//can be used for detecting cliffs
float dual_irsensor::mean()
{
    float t_sum = 0;
    for (int x = 0; x < SENSOR_COUNT; x++)
    {
        t_sum += distance_readings[x];
    }
    return t_sum / SENSOR_COUNT;
}