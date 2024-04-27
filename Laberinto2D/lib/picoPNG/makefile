###########################
###		MACROS			###
###########################
#()


define COMPILE
$(2) : $(3) $(4) 
	$(1) -c -o $(2) $(3) $(5)
endef

define COPY
$(1) : $(2) $(INCSUBDIRS)
	$(CP) $(2) $(1)
endef

define C2O
$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(patsubst $(SRC)%,$(OBJ)%,$(1))))
endef
define C2H
$(patsubst %.c,%.h,$(patsubst %.cpp,%.hpp,$(1)))
endef


APP		:= libpicopng.a
CCFLAGS := -Wall -pedantic -std=c++20
CC 		:= g++
C 		:= gcc
CFLAGS 	:= -Wall -pedantic
MKDIR	:= mkdir -p
CP 		:= cp
SRC		:= src
OBJ		:= obj
LIBDIR	:= lib
DLYB	:= -dynamiclib
AR		:= ar
INCDIR 	:= include
ARFLAGS	:= -crs
RANLIB	:= ranlib
RLFLAGS	:= -no_warning_for_no_symbols
ifdef DEBUG
	CCFLAGS += -g
else
	CCFLAGS += -O3
endif

SUBDIRS 	:= $(shell find $(SRC) -type d)
OBJSUBDIRS	:= $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))
INCSUBDIRS	:= $(patsubst $(SRC)%,$(INCDIR)%,$(SUBDIRS))
ALLCPPS		:= $(shell find $(SRC) -type f -iname '*.cpp')
ALLCS		:= $(shell find $(SRC) -type f -iname '*.c')
ALLHPPS		:= $(shell find $(SRC) -type f -iname '*.hpp')
ALLHS		:= $(shell find $(SRC) -type f -iname '*.h')
# ALLCSOBJ	:= $(foreach F,$(ALLCS),$(call C2O,$(F)))
# ALLCPPSOBJ	:=  $(foreach F,$(ALLCPPS),$(call C2O,$(F)))
ALLOBJS		:= $(foreach F,$(ALLCPPS) $(ALLCS),$(call C2O,$(F)))
ALLHSINC 	:= $(patsubst $(SRC)%,$(INCDIR)%,$(ALLHPPS) $(ALLHS))

.PHONY: info

$(APP)	: $(OBJSUBDIRS) $(ALLOBJS) $(ALLHSINC)
	$(AR) $(ARFLAGS) $(APP) $(ALLOBJS)
	$(RANLIB) $(RLFLAGS) $(APP)


$(foreach F,$(ALLCPPS),$(eval $(call COMPILE, $(CC),$(call C2O,$(F)),$(F),$(call C2H,$(F)),$(CCFLAGS))))
$(foreach F,$(ALLCS),$(eval $(call COMPILE, $(C),$(call C2O,$(F)),$(F),$(call C2H,$(F)),$(CFLAGS))))
$(foreach F,$(ALLHPPS) $(ALLHS),$(eval $(call COPY, $(patsubst $(SRC)%,$(INCDIR)%, $(F)),$(F))))

# $(OBJ)%.o 	: $(SRC)%.c
# 	$(C) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CFLAGS)

# $(OBJ)%.o 	: $(SRC)%.cpp
# 	$(CC) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CCFLAGS)

info:
# # 	 $(call COMPILE,$(CC),$(call C2O,$(F)))
	$(info $(INCSUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(ALLHSINC))
# # 	$(info $(ALLCS))
# 	$(info $(ALLCPPSOBJ))
# 	$(info $(ALLCSOBJ))

$(OBJSUBDIRS):
	$(MKDIR) $(OBJSUBDIRS)

$(INCSUBDIRS):
	$(MKDIR) $(INCSUBDIRS)


clean:
	$(RM) -rf "./$(OBJ)"

cleanAll:
	make clean
	$(RM) "./$(APP)"
