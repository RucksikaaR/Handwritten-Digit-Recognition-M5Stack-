#include <M5GFX.h>
#include "neuton.h"
M5GFX display;
int val;
int iteration;
const int Buffer_Size = "Your estimation of the number of pixels that are included when you draw a digit";
float* Buffer = (float*) calloc(Buffer_Size, sizeof(float)); //According to the README file, you are supposed to create input_t* type input variable so I have used float*

void setup(void)
{
  Serial.begin(115200);
  display.init();
  display.setFont(&fonts::Font4);
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
      if ((tp[i].y*320 + tp[i].x) != val && iteration<Buffer_Size)  //Doing this can prevent duplication of data
      {
        Buffer[iteration] = tp[i].y*320 + tp[i].x; //320 is the display width
        val=Buffer[iteration];
        iteration++;
      }
    }
    display.display();

    display.setColor(display.isEPD() ? TFT_BLACK : TFT_WHITE); // Setting the foreground and background colour of the touch points
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
  else if (drawed) //Implements after you finish drawing the digit
  {
    drawed = false;
    display.waitDisplay();
    display.clear();
    display.display();
    if (neuton_model_set_inputs(Buffer)==0){ 
      uint16_t index;
      float* outputs;
      if (neuton_model_run_inference(&index, &outputs) == 0){ //Classifying the prediction result. Take a look at the multi_target_dict in target_values directory
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
   iteration = val = 0; //Reset iteration and val variables
   neuton_model_reset_inputs();
   free(Buffer); //Clear buffer to allocate memory for the digits drawn again
   Buffer = (float*) calloc(Buffer_Size, sizeof(float));
  }
  vTaskDelay(1);
}
