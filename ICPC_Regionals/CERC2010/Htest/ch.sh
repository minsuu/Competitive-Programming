#!/bin/bash
for ((i=0;i<10;i++)); do
    diff out0$i.txt ans0$i.txt
done
