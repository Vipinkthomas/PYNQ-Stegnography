# How to Compile and Run


1. Clone the project `git clone 'url'` to joan server 

2. load vitis settings.sh file`. /opt/Xilinx/Vitis_HLS/2020.2/settings64.sh`  and run ` make clean && make`

3. open the RTL file in vivado and connect the pins as mentioned in the stenganography.pdf (optional: make necessary clock frequency changes)

4. (optional load Vivado settings.sh file) run `make`

5. Use Test bench files to do the debugging and add changes before synthesizing new overlay.

6. Use the given Jupyter notebook to test your iP.
