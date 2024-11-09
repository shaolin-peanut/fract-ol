# Fract-ol
Fract-ol is a fractals explorer, for the mandelbrot and julia set. It is coded in C, and is part of school 42's cursus.  
![image](https://github.com/user-attachments/assets/777a8182-37d6-414a-ab4b-8d0bb352d2ff)
We had to use a minimalist graphic library coded by people from the school, Minilibx. Here's a student made documentation.  
I learned a lot about complex numbers, and how to plot the result of equations pixel by pixel. Fascinating introduction to graphic design, which I hope to do more of. I don't want to code video games, but visualizing math, biology, and nature are things I'm very interested in.
## Usage
1. In any linux or mac terminal, run `git clone this_repo_url`
2. When it's downloaded, go into the folder with `cd fractol`
3. Run `make` to compile the project
4. Run `./fractol` alone to see the options, then rerun it with one of the sets to explore it
- Ex: `./fractol julia`

When running the julia set, the fractal will update as you move the mouse. If you it to stop moving (to zoom more easily for example), press the `SPACE` bar

If you're too lazy to install the program, here's a little demo:
https://www.youtube.com/watch?v=BVqaJY4r1ks (can't embed)

If it's too slow, decrease window height or width (WW and WH in sources/fractol.h)
If julia is doing very fine, you can increase window size and iterations until it slows down, it's worth looking at
