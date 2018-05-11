#!/bin/bash

for file in *.cpp; do
  pygmentize \
    -Ofontfamily=Hasklig,fontsize=31px,ystep=46,style=bw \
    -o $file.svg \
    $file
done
