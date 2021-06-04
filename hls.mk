# HLS using Vitis HLS
# ###################
HLS_SRC ?= hls_top.cpp
HLS_TOP ?= hls_top

###
PART := xc7z020-1clg400

.PHONY: default-hls
default-hls: ip

HLS_IP = hls-proj/s/impl/export.zip
.PHONY: hls ip
hls ip: $(HLS_IP)

$(HLS_IP): hls.tcl hls-proj/hls.app $(HLS_SRC)
	vitis_hls -f $<

hls-proj/hls.app: hls-proj.tcl
	vitis_hls -f $<

hls.tcl:
	@echo open_project hls-proj             > $@
	@echo open_solution s                  >> $@
	@echo csynth_design                    >> $@
	@echo export_design -format ip_catalog >> $@
	@echo exit                             >> $@

hls-proj.tcl:
	@echo open_project -reset hls-proj      > $@
	@echo add_files $(HLS_SRC)             >> $@
	@echo set_top $(HLS_TOP)               >> $@
	@echo open_solution s                  >> $@
	@echo set_part $(PART)                 >> $@
	@echo exit                             >> $@

clean-hls:
	$(RM) vitis_hls.log
	$(RM) -r hls-proj

clean: clean-hls

clean-hls-all: clean-hls
	$(RM) hls{,-proj}.tcl

clean-all: clean-hls-all 
