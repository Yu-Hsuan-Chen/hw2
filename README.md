# hw2

(1) how to setup and run your program 
-  git clone https://gitlab.larc-nthu.net/ee2405_2021/4dgl-ulcd-se.git
-  download main.cpp and FFT.py 
-  compile main.cpp: *sudo mbed compile --source . --source ~/ee2405/mbed-os-build/ -m B_L4S5I_IOT01A -t GCC_ARM -f*
-  run FFT.py: *sudo python3 FFT.py*
-  press buttom(Up/Down/choose) to select frequency
-  you can use picoscope to observe the wave form
-  press User Bottom to sample wave




(2) what are the results

## Waveform

|#sample|200Hz|400Hz|500hz|1000hz|
|-------|-----|-----|-----|-----|
|   20  |![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/20samples/200hz_20.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/20samples/400hz_20.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/20samples/500hz_20.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/20samples/1000hz_20.png)|
|   40  |![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/40samples/200hz_40.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/40samples/400hz_40.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/40samples/500hz_40.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/40samples/1000hz_40.png)|
|   60  |![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/60samples/200hz_60.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/60samples/400hz_60.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/60samples/500hz_60.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/60samples/1000hz_60.png)|
|   80  |![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/80samples/200hz_80.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/80samples/400hz_80.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/80samples/500hz_80.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/80samples/1000hz_80.png)||
|   100 |![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/100samples/200hz_100.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/100samples/400hz_100.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/100samples/500hz_100.png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/100samples/1000hz_100.png)||




## Spectrum

|#sample|200Hz|400Hz|500hz|1000hz|
|-------|-----|-----|-----|-----|
|   20  |![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/20samples/200hz(20sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/20samples/400hz(20sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/20samples/500hz(20sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/20samples/1000hz(20sample).png)|
|   40  |![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/40samples/200hz(40sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/40samples/400hz(40sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/40samples/500hz(40sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/40samples/1000hz(40sample).png)|
|   60  |![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/60samples/200hz(60sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/60samples/400hz(60sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/60samples/500hz(60sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/60samples/1000hz(60sample).png)|
|   80  |![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/80samples/200hz(80sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/80samples/400hz(80sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/80samples/500hz(80sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/80samples/1000hz(80sample).png)||
|   100 |![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/100samples/200hz(100sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/100samples/400hz(100sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/100samples/500hz(100sample).png)|![](https://github.com/Yu-Hsuan-Chen/hw2/blob/master/100samples/1000hz(100sample).png)||




