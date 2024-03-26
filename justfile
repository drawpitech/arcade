build: init
	cmake --build build --config Release

debug: init
	cmake --build build --config Debug

init:
	cmake -S . -B build -G "Ninja Multi-Config"
