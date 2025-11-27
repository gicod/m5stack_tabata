#include <M5Stack.h>
void test_font()
{
    for (int i = 0; i <= 7; i++)
    {            
        M5.Lcd.setTextSize(i);
        M5.Lcd.setCursor(10, 10);        
        M5.Lcd.printf("Size:%d", i);
        M5.Lcd.setCursor(10, 100);        
        M5.Lcd.println("ABC 012");
        delay(2000);
    }
    for (int i = 0; i <= 10; i++)
    {
        M5.Lcd.fillScreen(BLACK);
        for (int k = 0; k <= 10; k++)
        {
            // M5.Lcd.setTextSize(i);
            // M5.Lcd.setCursor(10, 10);        
            // M5.Lcd.printf("i:%d k:%d", i, k);

            // M5.Lcd.setCursor(10, 10, i);        
            // M5.Lcd.setTextSize(k);
            // M5.Lcd.printf("i:%d k:%d", i, k);

            // M5.Lcd.setTextSize(i);
            // M5.Lcd.setCursor(10, 40);        
            // M5.Lcd.println("ABC 012");
            
            // M5.Lcd.setCursor(10, 100, i);        
            // M5.Lcd.setTextSize(k);
            // M5.Lcd.println("ABC 345");

            // M5.Lcd.setCursor(10, 160, i);        
            // M5.Lcd.setTextSize(k);
            // M5.Lcd.printf("ABC 678");
            delay(2000);
        }
    }
}

void test_rawAxes()
{
    int width = 320;  //ширина X
    int height = 240;   //высота Y
    int k = 80;
    for (int x = k; x < width; x+=k) M5.Lcd.drawLine(x, 0, x, height, DARKGREY);
    k = 60;
    for (int y = k; y < height; y+=k) M5.Lcd.drawLine(0, y, width, y, DARKCYAN);
}

void test_rawAxes2()
{
    int width = 320;    //ширина X
    int height = 240;   //высота Y
    // int linesX[] = {20, 160, 300};
    int linesX[] = {106, 213};
    int linesY[] = {20, 120, 220};
    for (int i = 0; i < sizeof(linesX)/sizeof(linesX[0]); i++) 
        M5.Lcd.drawLine(linesX[i], 0, linesX[i], height, DARKGREY);
    for (auto y : linesY) 
        M5.Lcd.drawLine(0, y, width, y, DARKGREEN);
}