# hw2

(1) how to setup and run your program 
-  git clone https://gitlab.larc-nthu.net/ee2405_2021/4dgl-ulcd-se.git
-  download main.cpp and FFT.py 
-  compile main.cpp: *sudo mbed compile --source . --source ~/ee2405/mbed-os-build/ -m B_L4S5I_IOT01A -t GCC_ARM -f*
-  run FFT.py: *sudo python3 FFT.py*
-  press buttom(Up/Down/choose) to select frequency
-  you can use picoscope to observe the wave form
-  press **User Bottom** to sample wave




(2) what are the results

## Waveform before filter

|10Hz|100Hz|500hz|
|-----|-----|-----|
|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/10hz/before_filter.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/100hz/before_filter.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/500hz/before_filter.png)|
## Waveform after filter

|10Hz|100Hz|500hz|
|-----|-----|-----|
|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/10hz/after_filter.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/100hz/after_filter.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/500hz/after_filter.png)|

## Spectrum
|10Hz|400Hz|500hz|
|-----|-----|-----|
|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/10hz/Figure_1.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/100hz/Figure_1.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/500hz/Figure_1.png)|



