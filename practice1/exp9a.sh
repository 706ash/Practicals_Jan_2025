#!/bin/bash

while true
do

    echo "1. Display Memory information"
    echo "2. Display Processor information"
    echo "3. Exit"
    echo -n "Enter your choice: "
    read choice

    case $choice in
        1)echo "Memory information"
        echo ""
        free -m
        ;;

        2)echo "Processor information"
        echo ""
        cat /proc/cpuinfo
        ;;

        3)echo "Exiting ..."
        break
        ;;

        *)echo "Wrong choice..."
        ;;

    esac
done