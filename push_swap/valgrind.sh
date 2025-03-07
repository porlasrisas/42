#!/bin/bash
# valgrind_tester.sh – Script para comprobar fugas de memoria en push_swap

# Lista de casos de prueba (puedes agregar o modificar según tus necesidades)
TESTS=(
    "4 67 3 87 23"
    "-34 12 9"
    "1 2 3 4 5"
    "5 4 3 2 1"
    "42 -42 2147483647 -2147483648"
)

# Recorre cada test y ejecuta push_swap con Valgrind.
for test in "${TESTS[@]}"
do
    echo "Ejecutando test: $test"
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
      ./push_swap $test > /dev/null 2>&1
    echo "------------------------------------"
done

echo "Pruebas de Valgrind completadas."
