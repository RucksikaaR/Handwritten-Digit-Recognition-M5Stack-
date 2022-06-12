#include <M5GFX.h>
#include "neuton.h"
M5GFX display;
int val;
int iteration;
const int Buffer_Size = 255;
float* Buffer = (float*) calloc(Buffer_Size, sizeof(float));   // allocate memory for pixel buffer with 0s

void setup(void)
{
  Serial.begin(115200);
  display.init();
  display.setFont(&fonts::Font4);
  if(!Buffer){
    Serial.println("Failed to allocate memory");
  }

  if (!display.touch())
  {
    display.setTextDatum(textdatum_t::middle_center);
    display.drawString("Touch not found.", display.width() / 2, display.height() / 2);
  }

  display.setEpdMode(epd_mode_t::epd_fastest);
  display.startWrite();
  
}

void loop(void)
{
  static bool drawed = false;
  lgfx::touch_point_t tp[3];

  int nums = display.getTouchRaw(tp, 3);
  if (nums)
  {
    display.convertRawXY(tp, nums);

    for (int i = 0; i < nums; ++i)
    {
      if ((tp[i].y*320 + tp[i].x) != val && iteration<Buffer_Size)
      {
        Buffer[iteration] = tp[i].y*320 + tp[i].x;
        val=Buffer[iteration];
        iteration++;
      }
    }
    display.display();

    display.setColor(display.isEPD() ? TFT_BLACK : TFT_WHITE);
    for (int i = 0; i < nums; ++i)
    {
      int s = tp[i].size + 3;
      switch (tp[i].id)
      {
      case 0:
        display.fillCircle(tp[i].x, tp[i].y, s);
        break;
      case 1:
        display.drawLine(tp[i].x-s, tp[i].y-s, tp[i].x+s, tp[i].y+s);
        display.drawLine(tp[i].x-s, tp[i].y+s, tp[i].x+s, tp[i].y-s);
        break;
      default:
        display.fillTriangle(tp[i].x-s, tp[i].y +s, tp[i].x+s, tp[i].y+s, tp[i].x, tp[i].y-s);
        break;
      }
      display.display();
    }
    drawed = true;
  }
  else if (drawed)
  {
    drawed = false;
    display.waitDisplay();
    display.clear();
    display.display();
    if (neuton_model_set_inputs(Buffer)==0){
      uint16_t index;
      float* outputs;
      if (neuton_model_run_inference(&index, &outputs) == 0){
        switch(index){
          case 0:
          Serial.println("one");
          break;
          case 1:
          Serial.println("two");
          break;
          case 2:
          Serial.println("three");
          break;
          case 3:
          Serial.println("four");
          break;
          case 4:
          Serial.println("five");
          break;
          case 5:
          Serial.println("six");
          break;
          case 6:
          Serial.println("seven");
          break;
          case 7:
          Serial.println("eight");
          break;
          case 8:
          Serial.println("nine");
          break;
          default:
          Serial.println("Not detected");
          break;
      }
    }
   }
   iteration = val = 0;
   neuton_model_reset_inputs();
   free(Buffer);
   Buffer = (float*) calloc(Buffer_Size, sizeof(float));
   if (!Buffer)
    {
      Serial.println("Failed to allocate memory");
    }
  }
  vTaskDelay(1);
}
