# Developer Manual



---

## 1. Bill of Materials (BOM)

Below is a detailed list of materials required to build the project:

| **Item**               | **Distributor**         | **Price (USD)** | **Quantity** | **Total Cost (USD)** |
|-------------------------|-------------------------|-----------------|--------------|----------------------|
| Arduino ESP32 Microcontroller   | [Amazon](https://www.amazon.com/Arduino-ABX00083-Bluetooth-MicroPython-Compatible/dp/B0C947BHK5/ref=sr_1_1_sspa?crid=3COHWGK5WZQ9U&dib=eyJ2IjoiMSJ9.GzP-GvhsR81ftjmV7C-hRbjjWrFW2CBmv26NMHonZJQv-nwWi-OhyYKh-Rh1E8EfgWLK3dc5m5FXbbUiPsAVjSXQQMuAgego0nvDbNsNn8_qWeBTu20Rv5TiLLKHYEhP_n67cgIEabG6CiT9_aOhkCtU9E_E49QuNMbEbUThG-6eQcQmiDxX-0OXmmGN0q52ArTP3fYWDR4Pxp2sIPNVxi_01EuzspGUnI5MMhfvgVVEjdhXFU4nJyMuRi5U52D6eZzfYvQaem9oKXZdaB9ArKGdEOXjeKYgsSGsgCk0h0Q.B76va3JrfHsjLa_KYDJ9qNMcd1HDARrn1IGtbosZGP4&dib_tag=se&keywords=arduino+esp32&qid=1733417344&s=electronics&sprefix=arduino+esp3%2Celectronics%2C127&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1) | $23          | 1            | $23               |
|BMP390 Precision Barometric Pressure and Altimeter Sensor  | [Adafruit](https://www.adafruit.com/product/4816)  | $10.95           | 1            | $10.95                |
|Premium Male Headers Cable - 150mm Long  | [Adafruit](https://www.adafruit.com/product/4209)  | $0.95          | 1            | $0.95                |
| Push Buttons  | [Amazon](https://www.amazon.com/dp/B07RTZVZ6L?ref=ppx_yo2ov_dt_b_fed_asin_title)   | $7.99           | 1            | $7.99               |
 
**Total Estimated Cost:** $42.89

---

## 2. Implementation Details

### Gestures Captured
- **Blowing:** Captured using a pressure sensor to detect increases or decreases in the internal pressure of the bottle.
- **Button Presses:** Used to trigger specific notes when user press it.
### Sensors Considered
1. **Barometric Pressure Sensor** :
   - **Reason for Selection:** Accurate in capturing environmental pressure, compact and lightweight, and easy to install.
2. **Push Buttons:**
   - **Reason for Selection:** Simple, reliable, and low-cost solution for triggering notes.
3. **Potentiometer Fader:** The potentiometer fader offers precise control, durability, compact design, and versatility for a wide range of applications.
4. Other Sensors For the Future: 
     - Mic Sensor 
     - Ultrasonc Sensor 
     - FSR 
     - Camera Sensor


### Data Processing
- **Raw Data Processing:**
  - Pressure Sensor input: Analyzed environmental pressure.
  - Button presses: Processed as discrete digital inputs.
  - Fader input: Analyzed the location of the fader

### Challenges
- **Pressure sensor Sensitivity:** Initial setups were too sensitive. This was mitigated by adding a software threshold.

