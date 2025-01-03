#!/bin/bash

while true
do

    echo "1. create user"
    echo "2. display users"
    echo "2. delete user"
    echo "4. create group"
    echo "5. display group"
    echo "6. delete group"
    echo "7. exit ..."
    echo -n "Enter your choice: "
    read choice

    case $choice in
        1)echo "create user"
        read -p "Enter the username: " name
        sudo useradd $name && echo "user $name created successfully" || echo "error"
        ;;

        2)echo "display users"
        echo ""
        cut -d ':' -f1 /etc/passwd
        ;;

        3)echo "delete user"
        read -p "Enter the username: " name
        sudo userdel $name && echo "user $name deleted successfully" || echo "error"
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