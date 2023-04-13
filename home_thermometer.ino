#define THERMISTOR_PIN A0
#define RESISTANCE_VALUE_MAX 1023.0
#define KILO_UNIT 1000.0
#define VCC_PIN_VALUE 5.0
#define ABSOLUTE_ZERO_IN_KELVIN 273.15
#define A_COEFFICIENT 0.001129148
#define B_COEFFICIENT 0.000234125
#define C_COEFFICIENT 0.0000000876741

void setup() {
    Serial.begin(9600);
}

void loop() {
  int vccResistance = analogRead(THERMISTOR_PIN);

  float voltage = vccResistance * (VCC_PIN_VALUE / RESISTANCE_VALUE_MAX);

  float thermistorResistanceInKiloOhm = (VCC_PIN_VALUE * (10.0 / voltage)) - 10.0;
  float thermistorResistanceInOhm = thermistorResistanceInKiloOhm  * KILO_UNIT;

  float thermistorResistanceLog = log(thermistorResistanceInOhm);

  float divider = A_COEFFICIENT 
    + B_COEFFICIENT * thermistorResistanceLog 
    + C_COEFFICIENT * thermistorResistanceLog*thermistorResistanceLog*thermistorResistanceLog;

  float temperatureInCelsius = (1.0 / divider) - ABSOLUTE_ZERO_IN_KELVIN;

  Serial.print("Temperature: "); 
  Serial.print(temperatureInCelsius);
  Serial.println(" C"); 

  delay(1000);
}