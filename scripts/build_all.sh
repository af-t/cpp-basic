#!/usr/bin/env bash
# Compiles every example with warnings enabled and reports which ones fail.
set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
STD="${STD:-c++17}"
OUT="${OUT:-$ROOT/build}"

# CXX may carry arguments (for example "ccache g++"), so split it into words.
read -ra CXX_CMD <<< "${CXX:-g++}"

if ! command -v "${CXX_CMD[0]}" > /dev/null; then
    echo "Compiler not found: ${CXX_CMD[0]}. Set CXX to a working compiler." >&2
    exit 1
fi

mkdir -p "$OUT"

failed=0
total=0

while IFS= read -r src; do
    total=$((total + 1))
    name="$(basename "${src%.cpp}")"
    dir="$(basename "$(dirname "$src")")"
    if ! "${CXX_CMD[@]}" -std="$STD" -Wall -Wextra -o "$OUT/$dir.$name" "$src"; then
        echo "FAIL: $src"
        failed=$((failed + 1))
    fi
done < <(find "$ROOT/vector" "$ROOT/misc" -name '*.cpp' | sort)

echo "Compiled $((total - failed))/$total examples into $OUT"
[ "$failed" -eq 0 ]
