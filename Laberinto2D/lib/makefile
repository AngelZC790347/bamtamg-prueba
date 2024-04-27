.PHONY	: all clean cleanAll
SUBDIRS := $(shell find . -type d -maxdepth 1 -mindepth 1)

all:
	for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir; \
    done

clean:
	for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir clean; \
    done

cleanAll:
	for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir cleanAll; \
    done