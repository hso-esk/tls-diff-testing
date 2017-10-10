export PROF

export TOOLS_ROOT=$(shell pwd)

all: bitman cryptoman middleman generator stimulator

.PHONY: bitman cryptoman middleman clean generator stimulator

bitman:
	@echo "\033[01;32m==> Building 'bitman'\033[00;00m"
	$(MAKE) -C bitman

cryptoman: bitman
	@echo "\033[01;32m==> Building 'cryptoman'\033[00;00m"
	$(MAKE) -C cryptoman

middleman: bitman cryptoman
	@echo "\033[01;32m==> Building 'middleman'\033[00;00m"
	$(MAKE) -C middleman

generator: bitman cryptoman middleman
	@echo "\033[01;32m==> Building 'generator'\033[00;00m"
	$(MAKE) -C generator

stimulator: bitman cryptoman middleman
	@echo "\033[01;32m==> Building 'stimulator'\033[00;00m"
	$(MAKE) -C apps/stimulator

clean:
	@echo "\033[01;31m==> Cleaning directories:\033[00;00m"
	$(MAKE) -C bitman clean
	$(MAKE) -C cryptoman clean
	$(MAKE) -C middleman clean
	$(MAKE) -C generator clean
	$(MAKE) -C apps/stimulator clean
	@echo ""

