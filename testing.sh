#!/bin/bash


test_dir="./Tests"
output_dir="./outputs"


mkdir -p "$output_dir"


for test_file in "$test_dir"/*.c; do
   
    test_filename=$(basename "$test_file")

    output_file="$output_dir/${test_filename%.c}.out"

    # Exécuter le programme frontend avec le fichier de test en entrée
    echo "Testing $test_filename..."
    ./frontend "$test_file" "$output_file"

    # Vérifier si l'exécution a réussi
    if [ $? -eq 0 ]; then
        echo "Test $test_filename passed."
    else
        echo "Test $test_filename failed."
    fi
done
