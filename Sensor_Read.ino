
// Reading sensor data and passing to global varaible. Returning reading is success or failure.

bool dhtSensorRead(void) {

  if (dht0.getData()) {

      temp = dht0.getTemperature();
      humidity = dht0.getHumidity();
      return 1;                                 // success getData
     }
  else {
    return 0;
    }                                          // failure getData

}