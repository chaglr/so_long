#!/bin/bash

# Game Path
GAME_PATH="./so_long"

# take the maps file name
MAP_FILES=($(ls maps/mandatory/*.ber))

# run the maps
for map_file in "${MAP_FILES[@]}"
do
    # run the game give the argument
    $GAME_PATH "$map_file"

    # Show the mess
    if [ $? -eq 0 ]; then
        echo "$map_file - Prog works"
    else
        echo "$map_file - the error case"
    fi
    echo "Argüman: $map_file"
done
