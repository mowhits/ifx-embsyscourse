APPLICATION_NAME = BareMetal
BIN_DIR = bin

# The subdirectories to process
SUBDIRS = application_source dsp_source
SRC = 
include $(patsubst %, %/subdir.mk, $(SUBDIRS))

# Determine object files
OBJ = $(patsubst %.c, %.o, $(filter %.c, $(SRC)))

# Compiler/Linker setup for Infineon's PSoC4 (Cortex-M0+)
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
LSCRIPT = ./linker_script.ld

CPPFLAGS = $(patsubst %, -I%, $(SUBDIRS))
DFLAGS = -mcpu=cortex-m0plus -mthumb -msoft-float -fdata-sections -ffunction-sections
LFLAGS = $(DFLAGS) -T $(LSCRIPT) -nostartfiles --specs=nano.specs -specs=nosys.specs -Wl,--gc-sections # -Wl,--print-gc-sections

HEX = $(BIN_DIR)/$(APPLICATION_NAME).hex
ELF = $(BIN_DIR)/$(APPLICATION_NAME).elf

.PHONY: all clean compile linker_step

all: $(OBJ) linker_step

$(OBJ): %.o: %.c
	$(CC) -mcpu=cortex-m0plus -mthumb $(CPPFLAGS) -c $< -o $@

# Step 2: Take the accumulated OBJ_LIST and build the final bare-metal binary
linker_step: $(ELF) $(HEX)

$(ELF): $(OBJ)
	@echo "--------------------------------------------------------"
	@echo "DEBUG: OBJ contains: [ $(OBJ) ]"
	@echo "--------------------------------------------------------"
	@echo "Invoking: ARM-GCC C Linker..."
	@mkdir -p $(dir $@)
	$(LD) $(LFLAGS) $(OBJ) -o $(ELF)

$(HEX): $(ELF)
	arm-none-eabi-objcopy -O ihex $(ELF) $(HEX)

clean:
	rm -rf $(BIN_DIR) $(OBJ)
#	@for dir in $(SUBDIRS); do $(MAKE) -C $$dir clean; done
