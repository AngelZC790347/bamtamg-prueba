###########################
###		MACROS			###
###########################
define COMPILE
$(2) : $(3) $(4) $(ALLINCS)
	$(1) -c -o $(2) $(3) $(5)
endef
define CPINC
$(2): $(1)
	$(MKDIR) $(2)
	cp -r $(1)/ $(2)
endef
define C2O
$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(patsubst $(SRC)%,$(OBJ)%,$(1))))
endef
define C2H
$(patsubst %.c,%.h,$(patsubst %.cpp,%.hpp,$(1)))
endef

APP		:= app
CCFLAGS := -Wall -pedantic -std=c++20
CC 		:= g++
C 		:= gcc
CFLAGS 	:= -Wall -pedantic
LIBDIR	:= lib
LIBS	:= $(shell find $(LIBDIR) -type f -iname '*.a') -framework OpenGL -framework GLUT
MKDIR	:= mkdir -p
RM		:= rm
SRC		:= src
OBJ		:= obj
INCDIR 	:= include
INC	:= -I$(SRC) -I$(INCDIR)

ifdef DEBUG
	CCFLAGS += -g
else
	CCFLAGS += -O3
endif

SUBDIRS 	:= $(shell find $(SRC) -type d)
LIBSUBDIRS	:= $(shell find $(LIBDIR) -type d -maxdepth 1 -mindepth 1)
INCSUBDIRS	:= $(shell find $(LIBDIR) -type d -iname include)
ALLINCS		:= $(foreach D,$(INCSUBDIRS),$(subst $(LIBDIR),$(INCDIR),$(dir $(D))))
OBJSUBDIRS	:= $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))
ALLCPPS		:= $(shell find $(SRC) -type f -iname '*.cpp')
ALLCS		:= $(shell find $(SRC) -type f -iname '*.c')
# ALLCSOBJ	:= $(foreach F,$(ALLCS),$(call C2O,$(F)))
# ALLCPPSOBJ	:=  $(foreach F,$(ALLCPPS),$(call C2O,$(F)))
ALLOBJS		:= $(foreach F,$(ALLCPPS) $(ALLCS),$(call C2O,$(F)))
APPDIR		:= dist


.PHONY: info lib lib-clean lib-cleanALl

$(APP)	: $(OBJSUBDIRS) $(ALLOBJS) $(APPDIR)
	$(CC) -o $(APPDIR)/$(APP) $(ALLOBJS) $(LIBS)


$(foreach F,$(ALLCPPS),$(eval $(call COMPILE, $(CC),$(call C2O,$(F)),$(F),$(call C2H,$(F)),$(CCFLAGS) $(INC))))
$(foreach F,$(ALLCS),$(eval $(call COMPILE, $(C),$(call C2O,$(F)),$(F),$(call C2H,$(F)),$(CFLAGS) $(INC))))
$(foreach F,$(INCSUBDIRS),$(eval $(call CPINC , $(F),$(subst $(LIBDIR),$(INCDIR),$(dir $(F))))))

# $(OBJ)%.o 	: $(SRC)%.c
# 	$(C) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CFLAGS)

# $(OBJ)%.o 	: $(SRC)%.cpp
# 	$(CC) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CCFLAGS)

info:
	$(info $(INCSUBDIRS))
	$(info $(ALLINCS))

$(OBJSUBDIRS):
	$(MKDIR) $(OBJSUBDIRS)

$(APPDIR):
	$(MKDIR) $(APPDIR)

clean:
	$(RM) -rf "./$(OBJ)"
	$(RM) -rf "./$(INCDIR)"

cleanAll:
	make clean
	$(RM) -rf "$(APPDIR)"

# Libs Rules
lib:
	$(MAKE) -C $(LIBDIR)

lib-clean:
	$(MAKE) -C $(LIBDIR) clean

lib-cleanALl:
	$(MAKE) -C $(LIBDIR) cleanAll
	