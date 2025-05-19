
## 🛠️ Hardware Requirements
- ESP32 board  
- Piezo buzzer (connected to GPIO 23)  
- Tact switch (connected to GPIO 17)  
- Optional LED (GPIO 16 if needed)

## 💡 Features
- Plays the melody only when the button is pressed
- Uses ESP32's `ledcWriteNote()` for accurate tone playback
- Octave and rhythm defined per note

## 🧠 How it Works
- Each note and its octave are stored in arrays
- Duration is calculated using the note value (whole, half, 1/4, etc.)
- The buzzer outputs the melody when the switch is pressed

## 🔄 License
MIT
![image](https://github.com/user-attachments/assets/d229d402-e3a5-467d-9417-7b367f5a936b)


