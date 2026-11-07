all: build

build:
	@rm -rf build
	@mkdir build
	@cd build && cmake ..

flash:
	@cd build && sudo make upload

.PHONY: all build flash
