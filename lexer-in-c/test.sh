#!/bin/bash
set -e -o pipefail
make
echo -n "<div><br/></div>" | ./a.out

