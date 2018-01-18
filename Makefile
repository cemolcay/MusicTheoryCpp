###############################################################################
#
# This is a generic Makefile template for Xcode projects. Simply fill out the
# following few variables with information about your project, and you'll be
# good to do. Type "make" to get some pretty help text.
#
# If you have any questions, reach out to:
#   Mike Arpaia
#   mike@arpaia.co
#   @mikearpaia
#
###############################################################################
#
# The "APP" variable represents what you decided to name your Xcode project
# when you first created it. This should be the same as the name of the binary
# that Xcode creates when you build your project. This will also be used in the
# help output
APP=MusicTheory
#
# The "APP_TARGET" variable represents the default "target" of your xcode
# project. This is usually the same as $(APP). This is used to build the
# project.
APP_TARGET=MusicTheory
#
# The "TESTS_TARGET" variable represents the "target" of your xcode project
# that will build and run your unit tests. This is used when you run your unit
# tests via this Makefile.
TESTS_TARGET=Tests
#
# The "PRODUCT" variable is the full title of your product. This is used in the
# help text
PRODUCT=MusicTheory
#
# The "TAGLINE" variable is a brief sentence fragment, perhaps of 35 - 40
# characters
TAGLINE="Music theory library with note, scale and chords."
#
###############################################################################

TOP := $(dir $(lastword $(MAKEFILE_LIST)))
CLEAR=\x1b[0m
GREEN=\x1b[32;01m
RED=\x1b[31;01m
YELLOW=\x1b[33;01m
BLUE=\x1b[34;01m
CYAN=\x1b[36;01m
BOLD=\033[1m
NORMAL=\033[0m

###############################################################################

all:
	@echo
	@echo "  $(BOLD)$(PRODUCT)$(NORMAL) - build tool"
	@echo
	@echo "       $(CYAN)$(TAGLINE)$(CLEAR)"
	@echo
	@echo "    $(BOLD)make$(NORMAL) - show this help message"
	@echo "       aliases: make help"
	@echo "    $(BOLD)make run$(NORMAL) - build and run a debug build of $(APP)"
	@echo "    $(BOLD)make build$(NORMAL) - build a debug build of $(APP)"
	@echo "       aliases: make debug"
	@echo "    $(BOLD)make release$(NORMAL) - build a release build of $(APP)"
	@echo "    $(BOLD)make test$(NORMAL) - run $(APP) unit tests"
	@echo "       aliases: make tests, make t"
	@echo "    $(BOLD)make install$(NORMAL) - install a release build of the $(APP) binary to $(TOP)bin/$(APP)"
	@echo "    $(BOLD)make clean$(NORMAL) - remove all build artifacts and executables"
	@echo

help: all

install: release
	mkdir -p $(TOP)bin
	cp $(TOP)build/Release/$(APP) $(TOP)bin/$(APP) ||:

release:
	xcodebuild -target $(APP_TARGET) -configuration Release

debug:
	xcodebuild -target $(APP_TARGET) -configuration Debug

build: debug

run: debug
	$(TOP)build/Debug/$(APP)

test:
	xcodebuild -target $(TESTS_TARGET) -configuration Debug
	$(TOP)build/Debug/$(TESTS_TARGET)

.PHONY: tests
tests: test
t: test

clean:
	rm -rf $(TOP)build/Release
	rm -rf $(TOP)build/Debug
	rm -rf $(TOP)build/$(APP).build
	rm -f $(TOP)bin/$(APP)
