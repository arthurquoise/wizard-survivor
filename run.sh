#!/bin/bash

# compile file to wasm
(cd ./src && make PLATFORM=PLATFORM_WEB -B)

# show url
echo -e "\nStarting at: http://0.0.0.0:8080/src/raylib_game.html\n"

# start local web server
python -m http.server 8080
