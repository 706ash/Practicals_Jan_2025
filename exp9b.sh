#!/bin/bash

echo "DISPLAYING OPERATING SYSTEM INFORMATION"

while true
do
    echo "1. Display Operating System Name"
    echo "2. Display Operating System Version"
    echo "3. Display Login Name"
    echo "4. Display Hostname"
    echo "5. Exit"
    read -p "Enter your choice: " ch

    case $ch in
        1)
            echo "Operating System Name:"
            uname
            ;;
        2)
            echo "Operating System Version:"
            cat /proc/version
            ;;
        3)
            echo "Login Name:"
            whoami
            ;;
        4)
            echo "Host Name:"
            hostname
            ;;
        5)
            echo "Exiting program."
            exit
            ;;
        *)
            echo "Invalid option. Please try again."
            ;;
    esac
done
