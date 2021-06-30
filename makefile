HLS_SRC := pixel.cpp
HLS_TOP := pixel
RTL_TOP := steganography
.DEFAULT_GOAL := default

%.mk:
	wget https://mygit.th-deg.de/gaydos/pynq-code/-/raw/master/$@

include hls.mk rtl.mk

default: $(BITSTREAM) $(SHORTCUTS)
