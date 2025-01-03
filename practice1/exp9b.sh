#!/bin/bash

while true
do

    echo "1. Operating system name"
    echo "2. OS version"
    echo "2. login name"
    echo "4. hostname"
    echo "5. Exit"
    echo -n "Enter your choice: "
    read choice

    case $choice in
        1)echo "Operating system name"
        echo ""
        uname
        ;;

        2)echo "Operating system version"
        echo ""
        cat /proc/version
        ;;

        3)echo "login name"
        echo ""
        whoami
        ;;

        4)echo "login name"
        echo ""
        hostname
        ;;

        5)echo "Exiting ..."
        break
        ;;

        *)echo "Wrong choice..."
        ;;

    esac
done