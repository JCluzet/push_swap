#!/bin/bash

printf "Indiquez le nombre d'arguments a generer : "
read -p " " VALEUR

export ARG=`ruby -e "puts (1..${VALEUR}).to_a.shuffle.join(' ')"`
echo $ARG
