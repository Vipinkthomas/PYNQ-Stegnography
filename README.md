# How to Run


1. Clone the project to a PYNQ-Z2 board `git clone https://mygit.th-deg.de/vt16684/embedded-acceleration.git` and run the jupyter notebook and install the git project with `pip install git+https://mygit.th-deg.de/vt16684/embedded-acceleration.git` to get all the required python packages before running the jupyter notebook. We are using `pynq package version 2.6.0`(that have not been included in the setup.py). 

# How to synthesize using Linux terminal

1. Clone the project `git clone https://mygit.th-deg.de/vt16684/embedded-acceleration.git`

2. load vitis settings.sh file`. /opt/Xilinx/Vitis_HLS/2020.2/settings64.sh`  and run ` make clean && make`

3. open the RTL file in vivado and connect the pins as mentioned in the stenganography.pdf (optional: make necessary clock frequency changes ... Click on ZYNQ7 Processing system -> Clock configuration)

4. (optional load Vivado settings.sh file) run `make`

5. Use Test bench files to do the debugging and add changes before synthesizing new overlay.

6. Use the given Jupyter notebook to test your IP.(NOTE: Speed ups graphs cannot be displayed on Gitlab)


