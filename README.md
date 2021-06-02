## fract'ol

"fract'ol" is simple fractal explorer.
You can see the [subject](https://github.com/adandres/fractol/blob/main/fract_ol.pdf) here.
Before cloning the repository, you'll need to insall Minilibx

## Installation of Minilibx on Mac OsX

First you need to Download [Xquartz](https://www.xquartz.org/)

Then clone the Minilibx git repository
```bash
git clone https://github.com/42Paris/minilibx-linux.git Minilibx
```
Once cloned, run these commands.
```bash
 cd Minilibx && ./configure
 sudo cp mlx.h /usr/X11/include
 sudo cp libmlx.a /usr/X11/lib
```

## Installation of Minilibx on Linux

Make sure you have the correct requirements
```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```
Then clone the Minilibx git repository
```bash
git clone https://github.com/42Paris/minilibx-linux.git Minilibx
```
Once cloned, run these commands.
```bash
 cd Minilibx && ./configure
 sudo cp mlx.h /usr/X11/include
 sudo cp libmlx.a /usr/X11/lib
```

## Installation of fract'ol

To clone and compile the project, run:
```bash
 git clone https://github.com/adandres/fractol.git fractol && cd fractol && make
```
fractol builds with gcc.

## Usage

To launch the program type:
```bash
./fractol Mandel
```
## Note
25/20
