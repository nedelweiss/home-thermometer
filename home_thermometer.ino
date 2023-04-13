#define RT0 10000
#define B 3977
#define VCC 5
#define R 10000

float T0;

void setup() {
    Serial.begin(9600);
    T0 = 25 + 273.15; // from Celsius to Kelvin conversion
}

void loop() {
    float VRT = analogRead(A0); // acquisition analog value of VRT
    VRT  = (5.00 / 1023.00) * VRT; // conversion to voltage
    
    float VR = VCC - VRT;
    float RT = VRT / (VR / R); // resistance of RT
    float ln = log(RT / RT0);

    float temperature = (1 / ((ln / B) + (1 / T0)));

    Serial.print("Temperature: ");
    Serial.print(temperature - 273.15);
    Serial.print(" C\n");

    delay(500);
}
