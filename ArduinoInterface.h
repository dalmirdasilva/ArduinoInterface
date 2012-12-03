#define A0          14
#define A1          15
#define A2          16
#define A3          17
#define A4          18
#define A5          19

class ArduinoRemoteIO {
        
    enum Mode {
        INPUT = 0,
        OUTPUT = 1
    };
    
    enum AnalogReference {
        DEFAULT,
        INTERNAL,
        INTERNAL1V1,
        INTERNAL2V56,
        EXTERNAL
    };
    
    enum BitOrder {
        MSBFIRST,
        LSBFIRST
    };

    /**
     * Configures the specified pin to behave either as an input or an 
     * output. See the description of digital pins for details.
     * 
     * @param pin       The number of the pin whose mode you wish to set
     * @param mode      Either INPUT or OUTPUT
     */
    void pinMode(unsigned char pin, Mode mode);

    /**
     * Write a HIGH or a LOW value to a digital pin.
     * If the pin has been configured as an OUTPUT with pinMode(), its 
     * voltage will be set to the corresponding value: 5V (or 3.3V on 
     * 3.3V boards) for HIGH, 0V (ground) for LOW.
     * 
     * If the pin is configured as an INPUT, writing a HIGH value with 
     * digitalWrite() will enable an internal 20K pullup resistor (see 
     * the tutorial on digital pins). Writing LOW will disable the 
     * pullup. The pullup resistor is enough to light an LED dimly, so 
     * if LEDs appear to work, but very dimly, this is a likely cause. 
     * The remedy is to set the pin to an output with the pinMode() 
     * function.
     * 
     * NOTE: Digital pin 13 is harder to use as a digital input than the
     * other digital pins because it has an LED and resistor attached to
     * it that's soldered to the board on most boards. If you enable its
     * internal 20k pull-up resistor, it will hang at around 1.7 V 
     * instead of the expected 5V because the onboard LED and series 
     * resistor pull the voltage level down, meaning it always returns 
     * LOW. If you must use pin 13 as a digital input, use an external 
     * pull down resistor.
     * 
     * @param pin       The pin number.
     * @param value     LOW or HIGH.
     */
    void digitalWrite(unsigned char pin, bool value);

    /**
     * 
     */
    bool digitalRead(unsigned char pin);

    /**
     * 
     */
    void analogReference(AnalogReference reference);
    
    /**
     * 
     */
    int analogRead(unsigned char pin);
    
    /**
     * 
     */
    void analogWrite(unsigned char pin, unsigned char value);
    
    /**
     * 
     */
    void tone(unsigned char pin, unsigned int frequency);
    
    /**
     * 
     */
    void tone(unsigned char pin, unsigned int frequency, unsigned long duration);
    
    /**
     * 
     */
    void noTone(unsigned char pin);
    
    /**
     * 
     */
    void shiftOut(unsigned char dataPin, unsigned char clockPin, BitOrder order, unsigned char b);
    
    /**
     * 
     */
    unsigned char shiftIn(unsigned char dataPin, unsigned char clockPin, BitOrder order);

    /**
     * 
     */
    unsigned long pulseIn(unsigned char pin, unsigned char value);
    
    /**
     * 
     */
    unsigned long pulseIn(unsigned char pin, unsigned char value, unsigned long timeout);    
};
