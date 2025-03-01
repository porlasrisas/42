#!/bin/bash

# Colores para la salida
GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

# Función para ejecutar y mostrar los resultados
run_test() {
  echo -e "$1"
  ./push_swap $2
  echo -e "=========================="
}

# Compilar el programa
make

echo -e "${GREEN}=== Pruebas Exhaustivas de Parseo ===${RESET}"

# Test 1: Argumentos válidos y básicos
run_test "Test 1.1: Argumentos válidos" "42 -42 2147483647 -2147483648"
run_test "Test 1.2: Argumentos mezclados y válidos" "4 8 9 1 2"
run_test "Test 1.3: Argumentos en una sola cadena" "'1 2 3 4 5'"

# Test 2: Argumentos no numéricos y casos extremos
run_test "Test 2.1: Argumentos no numéricos" "42 abc 123"
run_test "Test 2.2: Argumentos con caracteres especiales" "42 12.34 56"
run_test "Test 2.3: Argumentos con signos duplicados" "42 --42 56"
run_test "Test 2.4: Argumentos vacíos y espacios" "42  "
run_test "Test 2.5: Argumentos con comillas" '"42" "-42" "0"'

# Test 3: Números fuera de rango y extremadamente largos
run_test "Test 3.1: Fuera de rango positivo" "2147483648"
run_test "Test 3.2: Fuera de rango negativo" "-2147483649"
run_test "Test 3.3: Números extremadamente largos" "12345678987654321111111111111111111111123456"

# Test 4: Duplicados y orden
run_test "Test 4.1: Números duplicados" "42 42"
run_test "Test 4.2: Duplicados con signos diferentes" "+42 42 -42 -42"
run_test "Test 4.3: Orden ascendente" "1 2 3 4 5"
run_test "Test 4.4: Orden descendente" "5 4 3 2 1"
run_test "Test 4.5: Desordenado y mezclado" "9 4 2 8 6 1 7 3 5"

# Test 5: Ceros y ceros a la izquierda
run_test "Test 5.1: Cero" "0"
run_test "Test 5.2: Ceros a la izquierda" "00042 42"
run_test "Test 5.3: Ceros positivos y negativos" "+0 -0 0"

# Test 6: Casos especiales y extremos
run_test "Test 6.1: INT_MAX y INT_MIN" "2147483647 -2147483648"
run_test "Test 6.2: Combinación de todo lo anterior" "42 -42 abc 2147483647 2147483648 00042 42 0"

echo -e "${GREEN}=== Todas las pruebas han finalizado ===${RESET}"

