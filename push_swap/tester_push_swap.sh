#!/bin/bash

# Ejecutable de Push_swap
EXEC="./push_swap"

# Cantidades de números a probar
QUANTITIES=(3 5 10 50 100 200 300 400 500)

# Función para generar números aleatorios sin duplicados
generate_numbers() {
  local qty=$1
  seq -1000 1000 | shuf | head -n $qty
}

# Ejecutar pruebas para diferentes cantidades de números
echo "=== Resultados del Tester Push_swap ==="
for qty in "${QUANTITIES[@]}"
do
  # Generar números aleatorios
  NUMBERS=$(generate_numbers $qty)
  
  # Ejecutar push_swap y medir tiempo
  START=$(date +%s.%N)
  MOVES=$($EXEC $NUMBERS | wc -l)
  END=$(date +%s.%N)
  DURATION=$(echo "$END - $START" | bc)

  # Mostrar resultados
  echo "Cantidad de números: $qty | Movimientos: $MOVES | Tiempo: ${DURATION}s"
done

