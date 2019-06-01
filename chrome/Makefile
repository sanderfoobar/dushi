SHELL = /bin/sh

all:
	cp ../dushi.db .
	emcc -I../src --embed-file dushi.db --bind -o src/dushi-em.js ../src/dushi.cpp ../src/dushi-em.cpp
	cp src/dushi-em.js build/dushi-em.js
	sed -i -e 's/\/dushi/\//g' build/dushi-em.js
	sed -i -e 's/var wasmBinaryFile = \x27dushi-em.wasm\x27;/var wasmBinaryFile = chrome.runtime.getURL\(\x27build\/dushi-em.wasm\x27\);/g' build/dushi-em.js
	cp src/inject.js build/inject.js
	cp src/dushi-em.wasm build/dushi-em.wasm
	cat build/dushi-em.js >> build/inject.js
