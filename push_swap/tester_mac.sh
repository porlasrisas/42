#!/bin/bash
# full_tester.sh – Prueba exhaustiva de push_swap con numerosos casos de entrada

# Colores para la salida
GREEN="\033[0;32m"
YELLOW="\033[1;33m"
RED="\033[0;31m"
RESET="\033[0m"

# Función para mezclar líneas (compatible con macOS)
shuffle_lines() {
    if command -v shuf >/dev/null 2>&1; then
        shuf
    elif command -v gshuf >/dev/null 2>&1; then
        gshuf
    else
        perl -MList::Util=shuffle -e 'print shuffle(<STDIN>);'
    fi
}

# Función para ejecutar un test fijo.
# Se muestran: descripción, input, salida (no se muestran las operaciones en detalle, solo se cuenta el número de líneas)
run_test() {
    description="$1"
    input="$2"
    echo -e "${YELLOW}${description}${RESET}"
    echo -e "Input: ${input}"
    # Ejecuta push_swap redirigiendo stderr también y guarda la salida en una variable.
    output=$(./push_swap ${input} 2>&1)
    # Cuenta el número de líneas (movimientos o mensaje de error)
    moves=$(echo "$output" | wc -l)
    echo -e "Operaciones: ${moves}"
    echo -e "Salida completa:"
    echo "$output"
    echo -e "------------------------------------\n"
}

# Función para ejecutar un test con números aleatorios.
run_random_test() {
    qty="$1"
    echo -e "${YELLOW}Random Test: ${qty} numbers${RESET}"
    # Genera 'qty' números aleatorios sin duplicados en el rango -1000 a 1000.
    random_numbers=$(seq -1000 1000 | shuffle_lines | head -n "$qty" | tr '\n' ' ')
    echo -e "Input: ${random_numbers}"
    output=$(./push_swap ${random_numbers} 2>&1)
    moves=$(echo "$output" | wc -l)
    echo -e "Operaciones: ${moves}"
    # Se puede omitir la impresión detallada de cada operación.
    echo -e "------------------------------------\n"
}

# Compila el programa (se asume que el Makefile está configurado correctamente)
echo -e "${GREEN}Compilando...${RESET}"
make

echo -e "${GREEN}=== Iniciando pruebas exhaustivas de push_swap ===${RESET}\n"

#########################
# Casos válidos
#########################
run_test "Test 1: Conjunto pequeño ordenado (ascendente)" "1 2 3 4 5"
run_test "Test 2: Conjunto pequeño ordenado (descendente)" "5 4 3 2 1"
run_test "Test 3: Conjunto pequeño desordenado" "3 1 2"
run_test "Test 4: Conjunto medio (5 elementos mezclados)" "4 8 9 1 2"
run_test "Test 5: Argumentos válidos básicos" "42 -42 2147483647 -2147483648"
run_test "Test 6: Argumentos en una sola cadena (con comillas simples)" "'8 2 9 65'"
run_test "Test 7: Conjunto con ceros y ceros a la izquierda" "00042 42 0 -0"
run_test "Test 8: Conjunto con INT_MAX y INT_MIN" "2147483647 -2147483648"

#########################
# Casos de fallo (parseo incorrecto)
#########################
run_test "Test 9: Argumentos no numéricos" "42 abc 123"
run_test "Test 10: Argumentos con caracteres especiales (decimales)" "42 12.34 56"
run_test "Test 11: Argumentos con signos duplicados" "42 --42 56"
run_test "Test 12: Argumentos vacíos y solo espacios" "42   "
run_test "Test 13: Cadena vacía" ""
run_test "Test 14: Argumentos con comillas internas" "\"42\" \"-42\" \"0\""
run_test "Test 15: Argumento raro con dash y comillas" "\"-\"34 9 0 7"
run_test "Test 16: Números duplicados" "42 42"
run_test "Test 17: Duplicados con signos diferentes" "+42 42 -42 -42"
run_test "Test 18: Número fuera de rango positivo" "2147483648"
run_test "Test 19: Número fuera de rango negativo" "-2147483649"
run_test "Test 20: Número extremadamente largo" "12345678987654321111111111111111111111123456"

#########################
# Casos mixtos y extra
#########################
run_test "Test 21: Entrada con espacios y comillas extra" "\"  8 2 9 65 \"" 
run_test "Test 22: Argumentos con signos mezclados" "8 -2 +9 65"
run_test "Test 23: Entrada con argumentos nulos (simulados)" "0 '' 3"   # Nota: El shell no pasa nulos, pero se simula con cadena vacía

#########################
# Tests con conjuntos aleatorios
#########################
run_random_test 100
run_random_test 150
run_random_test 500

echo -e "${GREEN}=== Fin de pruebas exhaustivas ===${RESET}"
