# FreeRTOS Activity
Implementation of a program in FreeRTOS intended for medical equipment that must measure heart rate, oxygen saturation and fever;

Context: To help combat the Covid-19 Pandemic, the medical equipment research center is inviting you to help develop a monitor for patients' vital data. The monitor must record the patient's heartbeat (consider between 20 and 140 heartbeats - below 50 a high heartbeat message, above 90 a high heartbeat message), oxygen saturation level (consider oxygenation between 80% and 100% - below 90% low saturation message) in blood and temperature (consider a temperature of 34° to 41° - below 35° present a hypothermia message, above 37.5° a fever message).

1. Three tasks must be created, one to monitor each of the vital data;
2. The creation of the three tasks must be carried out in main_;
3. To simulate the patient's vital data, random functions must be used to generate each of the vital data;
4. Vital (random) data must be generated within each task;
5. All created tasks must have the same priority;
6. Pass parameters for each task (being “Beat:”,” Saturation:” and “Temperature:”);
7. Provide vital data in the console output (heart rate, temperature, saturation) – use the vPrintStringAndNuber() function;
8. Tasks must generate alerts when patients' vital data changes (message on the console).
9. Use the vTaskDelay() function, setting a time of one second for each task.
10. All tasks must define their explicit deletion using the vTaskDelete() task;
11. The code must be documented, using comments throughout the entire program.
