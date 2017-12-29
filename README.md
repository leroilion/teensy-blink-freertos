# Blink and serial with freeRTOS

## Init repo

```
git clone git@github.com:leroilion/teensy-blink-freertos.git
cd teensy-blink-freertos
mkdir subprojects
git clone git@github.com:leroilion/teensy-core.git subprojects/teensy-core
cd subprojects/teensy-core
git checkout -b v1.35 origin/v1.35
cd -
meson build --cross-file subprojects/teensy-core/teensy-3.5-cross.txt
cd build
meson configure -D teensy-core:freertos=true
ninja
ninja flash
```
