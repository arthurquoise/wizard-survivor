cmake -S . -B build -G "Unix Makefiles" &
cmake --build build &
move .\build\compile_commands.json .\compile_commands.json &
.\build\wizard-survivor\wizard-survivor.exe