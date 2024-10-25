#ifndef POWER_MANAGEMENT_TASK_H_
#define POWER_MANAGEMENT_TASK_H_

typedef struct
{
    float fan_perc;
    float fan_rpm;
    float chip_temp[6];
    float die_temp1;  // Add for Hashboard Test
    float die_temp2;  // Add for Hashboard Test
    float chip_temp_avg;
    float vr_temp;
    float voltage;
    float frequency_multiplier;
    float frequency_value;
    float power;
    float current;
    bool HAS_POWER_EN;
    bool HAS_PLUG_SENSE;
} PowerManagementModule;

void POWER_MANAGEMENT_task(void * pvParameters);

#endif
