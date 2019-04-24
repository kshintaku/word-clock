/*
Author: Keith Shintaku
Date: April 24, 2019
Description: Arduino GPS Word Clock
*/
#include <SoftwareSerial.h>
#include <FastLED.h>
#include <TinyGPS++.h>

#define NUM_LEDS 90
#define LED_PIN 7
#define RX_PIN 3
#define TX_PIN 4
#define TIME_ZONE -7 // Los Angeles(PDT) is -7 from UTC

TinyGPSPlus gps;
SoftwareSerial ss(RX_PIN, TX_PIN);
CRGB leds[NUM_LEDS];
CRGB color;
int gpsMin, gpsHour;

void setup()
{
    Serial.begin(9600);
    ss.begin(9600);
    FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, NUM_LEDS);
    LEDS.setBrightness(50);
    color = CRGB::White; // Color for LEDs
}

int round5(int n)
{
    return (n / 5 + (n % 5 > 2)) * 5;
}

void clearLED()
{
    fill_solid(leds + 3, NUM_LEDS - 8, CRGB::Black);
    FastLED.show();
}
void lightMinutes()
{
    fill_solid(leds + 26, 5, color);
}
void lightTo()
{
    fill_solid(leds + 33, 2, color);
}
void lightPast()
{
    fill_solid(leds + 35, 3, color);
}

void lightQuarter()
{
    fill_solid(leds + 18, 5, color);
}
void lightHalf()
{
    fill_solid(leds + 23, 3, color);
}
void lightFiveTop()
{
    fill_solid(leds + 9, 3, color);
}
void lightTwenty()
{
    fill_solid(leds + 4, 4, color);
}
void lightTenTop()
{
    fill_solid(leds + 16, 3, color);
}

void lightOne()
{
    fill_solid(leds + 39, 2, color);
}
void lightTwo()
{
    fill_solid(leds + 42, 2, color);
}
void lightThree()
{
    fill_solid(leds + 45, 4, color);
}
void lightFour()
{
    fill_solid(leds + 81, 3, color);
}
void lightFiveBot()
{
    fill_solid(leds + 54, 3, color);
}
void lightSix()
{
    fill_solid(leds + 63, 2, color);
}
void lightSeven()
{
    fill_solid(leds + 65, 4, color);
}
void lightEight()
{
    fill_solid(leds + 50, 4, color);
}
void lightNine()
{
    fill_solid(leds + 69, 2, color);
}
void lightTenBot()
{
    fill_solid(leds + 81, 2, color);
}
void lightEleven()
{
    fill_solid(leds + 59, 4, color);
}
void lightTwelve()
{
    fill_solid(leds + 77, 4, color);
}

void loop()
{
    while (ss.available() > 0)
    {
        if (gps.encode(ss.read()))
        {
            gpsMin = round5(gps.time.minute());
            gpsHour = gps.time.hour() + 24; // hour 0-23
            if (gpsMin == 60)
            {
                gpsMin = 0;
                gpsHour = gpsHour + 1;
            }
            gpsHour = gpsHour + TIME_ZONE;
            while (gpsHour > 12)
            {
                gpsHour = gpsHour - 12;
            }

            clearLED();
            leds[0] = color;
            leds[2] = color;
            fill_solid(leds + 85, NUM_LEDS, color);
            switch (gpsMin)
            {
            case 55:
                lightFiveTop();
                lightMinutes();
                lightTo();
            case 50:
                lightTenTop();
                lightMinutes();
                lightTo();
            case 45:
                lightQuarter();
                lightTo();
            case 40:
                lightTwenty();
                lightMinutes();
                lightTo();
            case 35:
                lightTwenty();
                lightFiveTop();
                lightMinutes();
                lightTo();
            case 30:
                lightHalf();
                lightPast();
            case 25:
                lightTwenty();
                lightFiveTop();
                lightMinutes();
                lightPast();
            case 20:
                lightTwenty();
                lightMinutes();
                lightPast();
            case 15:
                lightQuarter();
                lightPast();
            case 10:
                lightTenTop();
                lightMinutes();
                lightPast();
            case 5:
                lightFiveTop();
                lightMinutes();
                lightPast();
            default:
                break;
            }
            switch (gpsHour)
            {
            case 0:
                lightTwelve();
                break;
            case 1:
                lightOne();
                break;
            case 2:
                lightTwo();
                break;
            case 3:
                lightThree();
                break;
            case 4:
                lightFour();
                break;
            case 5:
                lightFiveBot();
                break;
            case 6:
                lightSix();
                break;
            case 7:
                lightSeven();
                break;
            case 8:
                lightEight();
                break;
            case 9:
                lightNine();
                break;
            case 10:
                lightTenBot();
                break;
            case 11:
                lightEleven();
                break;
            default:
                break;
            }
            FastLED.show();
        }
    }
}
