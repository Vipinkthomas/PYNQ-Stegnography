# RTL using Vivado
# ################
HLS_TOP ?= hls_top
RTL_TOP ?= steganography
HLS_IP ?= hls-proj/s/impl/export.zip

###
PART := xc7z020-1clg400

.PHONY: default-rtl
default-rtl: $(BITSTREAM) $(SHORTCUTS)

send-bitstream: $(HWHANDOFF) $(BITSTREAM)
	scp $^ pynq:jupyter_notebooks

BITSTREAM := rtl-proj/rtl.runs/impl_1/$(RTL_TOP).bit
.PHONY: bitstream
bitstream: $(BITSTREAM)

# TODO the bitstream needs handoff file, not vice versa. the handoff file is generated after block design (after the addresses)
HWHANDOFF := rtl-proj/rtl.gen/sources_1/bd/$(RTL_TOP)/hw_handoff/$(RTL_TOP).hwh
$(HWHANDOFF): $(BITSTREAM)

# convenience shortcuts
.PHONY: shortcuts
SHORTCUTS := $(notdir $(HWHANDOFF) $(BITSTREAM))
$(notdir $(HWHANDOFF)): $(HWHANDOFF)
	ln -s $<

$(notdir $(BITSTREAM)): $(BITSTREAM)
	ln -s $<

RTL_PROJ := rtl-proj/rtl.xpr
.PHONY: rtl-proj
rtl-proj: $(RTL_PROJ)

$(RTL_PROJ): rtl-proj.tcl | $(HLS_IP)
	vivado -mode tcl -source $<

# TODO try with -rtl_kernel
rtl-proj.tcl:
	@echo create_project -part $(PART) rtl.xpr rtl-proj              > $@
	@echo set_property ip_repo_paths hls-proj [current_project]     >> $@
	@echo update_ip_catalog                                         >> $@
	@echo create_bd_design $(RTL_TOP)                               >> $@
	@echo open_bd_design $(RTL_TOP)                                 >> $@
	@echo create_bd_cell -vlnv xilinx.com:ip:processing_system7 ps  >> $@
	@echo create_bd_cell -vlnv xilinx.com:hls:$(HLS_TOP) $(HLS_TOP) >> $@
	@echo save_bd_design >> $@
	@echo set_property top $(RTL_TOP) [current_fileset]  >> $@
	@echo exit >> $@

$(BLOCK_DESIGN): rtl-proj/rtl.srcs/sources_1/bd/$(RTL_TOP)/$(RTL_TOP).bd
$(BITSTREAM): \
	rtl.tcl \
	$(HLS_IP) \
	$(BLOCK_DESIGN) \
	| $(RTL_PROJ)
	vivado -mode tcl -source $<

# run synthesis
## to be able to run after HLS IP update:
## 1. upgrades all IPs 
## 2. resets the last run (impl_1)
rtl.tcl:
	@echo open_project $(RTL_PROJ)                     > $@
	@echo upgrade_ip [get_ips]                        >> $@
	@echo reset_runs impl_1                           >> $@
	@echo launch_runs impl_1 -to_step write_bitstream >> $@
	@echo wait_on_run impl_1                          >> $@
	@echo exit                                        >> $@

clean-rtl:
	$(RM) vivado*.{log,jou}
	$(RM) -r rtl-proj
	$(RM) $(SHORTCUTS)

clean: clean-rtl

clean-rtl-all: clean-rtl
	$(RM) rtl{,-proj,-autoconnect}.tcl

clean-all: clean-rtl-all
