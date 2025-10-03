#include <Arduino.h>
#include <lvgl.h>
#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <stdbool.h>
#include "FT6236.h"
#include "ui.h"
#include <Wire.h>
#include <Adafruit_PN532.h>
#include <HTTPClient.h>
#include <EEPROM.h>

/*
   If you want to use the LVGL examples,
  make sure to install the lv_examples Arduino library
  and uncomment the following line.
*/
// #include <examples/lv_examples.h>
// #include <demos/lv_demos.h>
const int i2c_touch_addr = TOUCH_I2C_ADD;

#define EEPROM_SIZE 256  // Define EEPROM size (must be enough for both strings)
#define SSID_ADDR 0      // Start address for the SSID
#define PWD_ADDR 128     // Start address for the Password (avoiding overlap)
#define MAX_STR_LEN 64   // Max length of stored strings

String serverPath = "https://aarvitechno.com/basepanels/cpanelapi/rfid_card.php?card_id=";


const byte AuthCard1[4] = { 0x25, 0x33, 0x16, 0x05
 };
const byte AuthCard2[4] = { 0xD3, 0x2B, 0xE1, 0xF7 };
const byte AuthCard3[4] = { 0xF2, 0xCA, 0x8B, 0x19 };
const byte AuthCard4[4] = { 0x01, 0xC1, 0x23, 0x26 };

#define LCD_MOSI 13
#define LCD_MISO 14  // 12
#define LCD_SCK 12
#define LCD_CS 3
#define LCD_RST -1  // 26
#define LCD_DC 42   // 33
#define LCD_BL 46

#define BUZZER_PIN 45

bool isScanning = false;

#define SDA_FT6236 2
#define SCL_FT6236 1

#define C7 2093

#define Relay_Pin 11

#define PN532_IRQ (19)
#define PN532_RESET (20)

class LGFX : public lgfx::LGFX_Device {
  lgfx::Panel_ILI9488 _panel_instance;
  lgfx::Bus_SPI _bus_instance;

public:
  LGFX(void) {
    {
      auto cfg = _bus_instance.config();
      cfg.spi_host = SPI3_HOST;
      cfg.spi_mode = 0;
      cfg.freq_write = 60000000;
      cfg.freq_read = 16000000;
      cfg.spi_3wire = false;
      cfg.use_lock = true;
      cfg.dma_channel = 1;
      cfg.pin_sclk = LCD_SCK;
      cfg.pin_mosi = LCD_MOSI;
      cfg.pin_miso = LCD_MISO;
      cfg.pin_dc = LCD_DC;
      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }

    {
      auto cfg = _panel_instance.config();

      cfg.pin_cs = LCD_CS;
      cfg.pin_rst = LCD_RST;
      cfg.pin_busy = -1;
      cfg.memory_width = 320;
      cfg.memory_height = 480;
      cfg.panel_width = 320;
      cfg.panel_height = 480;
      cfg.offset_x = 0;
      cfg.offset_y = 0;
      cfg.offset_rotation = 0;
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits = 1;
      cfg.readable = true;
      cfg.invert = false;
      cfg.rgb_order = false;
      cfg.dlen_16bit = false;
      cfg.bus_shared = true;
      _panel_instance.config(cfg);
    }

    setPanel(&_panel_instance);
  }
};

Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

LGFX tft;
/*Change to your screen resolution*/
static const uint16_t screenWidth = 480;
static const uint16_t screenHeight = 320;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight / 5];

void writeStringToEEPROM(int addr, const char *data) {
  int len = strlen(data);
  if (len >= MAX_STR_LEN) len = MAX_STR_LEN - 1;  // Ensure it fits
  for (int i = 0; i < len; i++) {
    EEPROM.write(addr + i, data[i]);
  }
  EEPROM.write(addr + len, '\0');  // Null terminator
  EEPROM.commit();
  Serial.print("Written to EEPROM at address ");
  Serial.print(addr);
  Serial.print(": ");
  Serial.println(data);
}

char eepromBuffer[MAX_STR_LEN];  // Global buffer to hold read data

const char *readStringFromEEPROM(int addr) {
  memset(eepromBuffer, 0, MAX_STR_LEN);  // Clear buffer

  int i = 0;
  while (i < MAX_STR_LEN - 1) {
    char readChar = EEPROM.read(addr + i);
    if (readChar == '\0' || readChar == 0xFF) break;  // Stop if null or uninitialized
    eepromBuffer[i] = readChar;
    i++;
  }
  eepromBuffer[i] = '\0';  // Null termination
  return eepromBuffer;
}



/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.writePixels((lgfx::rgb565_t *)&color_p->full, w * h);
  tft.endWrite();

  lv_disp_flush_ready(disp);
}

void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
  int pos[2] = { 0, 0 };
  ft6236_pos(pos);
  if (pos[0] > 0 && pos[1] > 0) {
    data->state = LV_INDEV_STATE_PR;
    data->point.x = tft.width() - pos[1];
    data->point.y = pos[0];
    Serial.printf("x:%d,y:%d\n", data->point.x, data->point.y);
  } else {
    data->state = LV_INDEV_STATE_REL;
  }
}

void touch_init() {
  // I2C init

  byte error, address;

  Wire.beginTransmission(i2c_touch_addr);
  error = Wire.endTransmission();

  if (error == 0) {
    Serial.print("I2C device found at address 0x");
    Serial.print(i2c_touch_addr, HEX);
    Serial.println("  !");
  } else if (error == 4) {
    Serial.print("Unknown error at address 0x");
    Serial.println(i2c_touch_addr, HEX);
  }
}



void setup() {
  Serial.begin(115200);
  EEPROM.begin(EEPROM_SIZE);
  pinMode(BUZZER_PIN, OUTPUT);
  ledcSetup(4, 10000, 8);
  pinMode(Relay_Pin, OUTPUT);
  digitalWrite(Relay_Pin, LOW);
  ledcAttachPin(BUZZER_PIN, 4);
  Wire.begin(2, 1);
  tft.begin();        /* TFT init */
  tft.setRotation(3); /* Landscape orientation, flipped */
  tft.fillScreen(TFT_BLACK);
  delay(500);
  pinMode(LCD_BL, OUTPUT);
  digitalWrite(LCD_BL, HIGH);
  touch_init();


  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / 5);

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  /*Initialize the (dummy) input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);
#if 0
  /* Create simple label */
  lv_example_get_started_4();

#else
/* Try an example from the lv_examples Arduino library
     make sure to include it as written above.
  */
// uncomment one of these demos
//lv_demo_widgets();// OK
#endif
  ui_init();
  Serial.println("Setup done");


  lv_timer_handler();
  lv_obj_add_event_cb(ui_RFIDSCREEN, ui_event_RFIDSCREEN, LV_EVENT_ALL, NULL);
}

void loop() {
  lv_timer_handler();
  
  delay(5);

  _ui_label_set_property(ui_RFIDINSTRUCT, _UI_LABEL_PROPERTY_TEXT, "SCAN YOUR CARD\nOR RFID TAG");

  char storedSSID[MAX_STR_LEN];
  strncpy(storedSSID, readStringFromEEPROM(SSID_ADDR), MAX_STR_LEN);
  char storedPWD[MAX_STR_LEN];
  strncpy(storedPWD, readStringFromEEPROM(PWD_ADDR), MAX_STR_LEN);

  if (isScanning && WiFi.status() == WL_CONNECTED) {
    uint8_t uid[7];
    uint8_t uidLength;

    if (nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength, 500)) {
      Serial.println("A new card has been detected.");
      nfc.PrintHexChar(uid, uidLength);

      String val;
      if (memcmp(uid, AuthCard1, 4) == 0) {
        val = "11111";
      } else if (memcmp(uid, AuthCard2, 4) == 0) {
        val = "22222";
      } else if (memcmp(uid, AuthCard3, 4) == 0) {
        val = "33333";
      } else if (memcmp(uid, AuthCard4, 4) == 0) {
        val = "44444";
      } else {
        val = "null";
      }

      HTTPClient http;
      Serial.println(serverPath + val);
      http.begin(serverPath + val);
      int httpCode = http.GET();

      if (httpCode > 0) {
        String payload = http.getString();
        Serial.println("HTTP Response: " + payload);

        if (payload == "1") {
          Serial.println("ACCESS GRANTED");
          _ui_label_set_property(ui_RFIDINSTRUCT, _UI_LABEL_PROPERTY_TEXT, "ACCESS GRANTED");
          lv_timer_handler();
          isScanning = false;
          for (char i = 0; i < 3; i++) {
            ledcWriteTone(4, C7);  // Turn on buzzer
            delay(100);
            ledcWrite(4, 0);  // Turn off buzzer
            delay(100);
          }
          digitalWrite(Relay_Pin,HIGH);
          delay(3000);
          digitalWrite(Relay_Pin,LOW);
        } else if (payload == "0") {
          Serial.println("ACCESS DENIED");
          _ui_label_set_property(ui_RFIDINSTRUCT, _UI_LABEL_PROPERTY_TEXT, "ACCESS DENIED");
          lv_timer_handler();
          isScanning = false;
          for (char i = 0; i < 3; i++) {
            ledcWriteTone(4, C7);  // Turn on buzzer
            delay(250);
            ledcWrite(4, 0);  // Turn off buzzer
            delay(250);
          }
        }
      } else {
        Serial.println("HTTP GET request failed");
      }
      http.end();
      isScanning = true;
    }
  } else if (isScanning && WiFi.status() != WL_CONNECTED) {
    WiFi.begin(storedSSID, storedPWD);

    for (char i = 0; i < 5; i++) {
      ledcWriteTone(4, C7);  // Turn on buzzer
      delay(50);
      ledcWrite(4, 0);  // Turn off buzzer
      delay(50);
    }
    Serial.println("Connecting...");
    _ui_label_set_property(ui_RFIDINSTRUCT, _UI_LABEL_PROPERTY_TEXT, "Wifi Not Connected :(");
    delay(1000);
    isScanning = true;
  }
}



static void btn_event_cb(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *btn = lv_event_get_target(e);
  if (code == LV_EVENT_CLICKED) {
    static uint8_t cnt = 0;
    cnt++;

    /*Get the first child of the button which is the label and change its text*/
    lv_obj_t *label = lv_obj_get_child(btn, 0);
    lv_label_set_text_fmt(label, "Button: %d", cnt);
  }
}

/**
   Create a button with a label and react on click event.
*/
void lv_example_get_started_4(void) {
  lv_obj_t *btn = lv_btn_create(lv_scr_act()); /*Add a button the current screen*/
  lv_obj_set_size(btn, 120, 50);               /*Set its size*/
  lv_obj_align(btn, LV_ALIGN_CENTER, 0, 0);
  lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL); /*Assign a callback to the button*/

  lv_obj_t *label = lv_label_create(btn); /*Add a label to the button*/
  lv_label_set_text(label, "Button");     /*Set the labels text*/
  lv_obj_center(label);
}

void ui_event_RFIDSCREEN(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);

  char storedSSID[MAX_STR_LEN];
  strncpy(storedSSID, readStringFromEEPROM(SSID_ADDR), MAX_STR_LEN);
  char storedPWD[MAX_STR_LEN];
  strncpy(storedPWD, readStringFromEEPROM(PWD_ADDR), MAX_STR_LEN);

  if (event_code == LV_EVENT_SCREEN_LOADED) {
    Serial.println(storedSSID);
    Serial.println(storedPWD);
    lv_timer_handler();
    delay(2000);
    WiFi.begin(storedSSID, storedPWD);

    if (!isScanning) {
      Serial.println("RFID Screen Loaded");

      uint32_t versiondata = nfc.getFirmwareVersion();
      if (!versiondata) {
        Serial.println("Didn't find PN53x board");
        isScanning = false;
        return;  // Exit to avoid blocking the UI
      }

      Serial.print("Found chip PN5");
      Serial.println((versiondata >> 24) & 0xFF, HEX);
      Serial.print("Firmware ver. ");
      Serial.print((versiondata >> 16) & 0xFF, DEC);
      Serial.print('.');
      Serial.println((versiondata >> 8) & 0xFF, DEC);

      nfc.SAMConfig();
      Serial.println("Waiting for an ISO14443A Card...");
      isScanning = true;
      return;
    }
  } else if (event_code == LV_EVENT_SCREEN_UNLOADED) {
    Serial.println("RFID Screen Unloaded");
    WiFi.disconnect();
    isScanning = false;  // Stop scanning
    nfc.reset();
  }
}

void ui_event_RFIDSCREENBACKBUTTON(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  nfc.reset();
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    _ui_screen_change(&ui_HOME, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_HOME_screen_init);
    isScanning = false;
    WiFi.disconnect();
  }
}

void ui_event_WiFiScreen(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_SCREEN_LOADED) {
    _ui_label_set_property(ui_ACKNOWLEDGEMENT, _UI_LABEL_PROPERTY_TEXT, "");
  }
}

void ui_event_DONEBUTTON(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);
  if (event_code == LV_EVENT_CLICKED) {
    _ui_label_set_property(ui_ACKNOWLEDGEMENT, _UI_LABEL_PROPERTY_TEXT, "WiFi Credentials Changed Successfully!");
    if ((strlen(lv_textarea_get_text(ui_SSID_BOX)) > 0) && (strlen(lv_textarea_get_text(ui_PWDBOX)) > 0)) {
      const char *ssid = lv_textarea_get_text(ui_SSID_BOX);
      const char *pwd = lv_textarea_get_text(ui_PWDBOX);
      writeStringToEEPROM(SSID_ADDR, ssid);
      writeStringToEEPROM(PWD_ADDR, pwd);

    } else {
      _ui_label_set_property(ui_ACKNOWLEDGEMENT, _UI_LABEL_PROPERTY_TEXT, "Incorect Credentials");
      lv_timer_handler();
      for (char i = 0; i < 2; i++) {
        ledcWriteTone(4, C7);  // Turn on buzzer
        delay(50);
        ledcWrite(4, 0);  // Turn off buzzer
        delay(50);
      }
      delay(2000);
      _ui_label_set_property(ui_ACKNOWLEDGEMENT, _UI_LABEL_PROPERTY_TEXT, "Incorect Credentials");
      lv_timer_handler();
    }
  }
}
