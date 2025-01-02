#!/bin/bash

while true
do
    echo "Press 1 to display Memory Information"
    echo "Press 2 to display Processor Information"
    echo "Press 3 to Exit"
    read -p "Enter your choice: " data

    case $data in
        1)
            echo "Memory Information"
            echo ""
            free -m
            echo ""
            ;;
        2)
            echo "Processor Information"
            echo ""
            cat /proc/cpuinfo
            echo ""
            ;;
        3)
            echo "Exiting..."
            break
            ;;
        *)
            echo "Invalid option. Please try again."
            ;;
    esac
done
