## DISCLAIMER:
This code is built to work on linux and was only tested on Debian

# Prerequisites:

1.  clone 42 minilibx into main directory
```sh
git clone https://github.com/42Paris/minilibx-linux.git 
 ```
2.  compile minilibx
```sh
cd minilibx-linux
./configure
cd ..
```
4.  install the following packages: xorg, x11, zlib, libxext-dev, zlib1g-dev
```sh
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
4.  compile
```sh
make && ./fil-de-fer maps/test_maps/10-2.fdf
```
# Controls:
## start the model
  enter
## translate using 
  w - a - s - d
## rotate using                    
  o - p - k - l
## zoom in and out                     
  m - n
## reset model to isometric view         
  r
## semi-autonomous rotation              
  t
## close program           
  x-button - esc

# pdf_new
