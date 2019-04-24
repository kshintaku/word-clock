# word-clock

GPS Arduino Word Clock

Using an Arduino with GPS module for time, create a word clock with LED strips

Parts list:

1x Arduino Nano
1x NEO-6M GPS Module
90x WS2812B LEDs (60 LEDs per meter)
1x IKEA picture frame (8x10inch)

Questionable Parts:

1x 200-300ohm resistor for data line to LEDs

Directions:

1. Print out word clock template
2. Cut and stick LED strips to photo frame backing
3. Solder LED strips together, mind the direction
4. Upload program to Arduino
5. Magic

Notes:

- Transparency/Tracing paper seems to work okay in absense of cutting out letters
- Be sure to get libraries for FastLED and TinyGPS++ to control components
