# Generator for Simple Zeckendorf Sequences
<p>
Tony Bai </br>
<i>July 14, 2019</i>
</p>

# Inspiration
Annie asked me to help her develop an algorithm to generate Simple Zeckendorf Sequences in 2 dimensions. The definition for such sequences can be found in a mathematical paper from Williams College titled [Gaussian Behavior In Zeckendorf Decompositions From Lattices](https://web.williams.edu/Mathematics/sjmiller/public_html/math/papers/Zeckendorf2DComboDecompv70.pdf "math paper") by Chen et al. The following image is taken from the paper, and shows the first 45 entries of the two-dimensional sequence.

<img src="https://github.com/tonyb7/zeckendorf-sequences/blob/master/sequence.png?raw=true" width="400">

# How to Run This Program
1. Download this repository and navigate to it in terminal
2. Compile the C++ file with `g++ zeckendorf.cpp -std=c++11 -o bin/zeckendorf`
3. Run the executable with `./zeckendorf`
4. Follow the prompts

Example:

<img src="https://github.com/tonyb7/zeckendorf-sequences/blob/master/terminal_output.png?raw=true" width="600">

# Issues & Limitations
It seems like the program can only execute reasonably fast (under 20 seconds) on my computer for up to about 23 rows as of now.

# Extensions
If you want to implement this algorithm for higher dimensions or optimize it, feel free to read & edit `zeckendorf.cpp`. It should be clear how to implement this algorithm for 3 or more dimensions -- it would involve more nested vectors, but the idea behind the algorithm is the same.

