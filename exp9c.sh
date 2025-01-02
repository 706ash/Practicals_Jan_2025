#!/bin/bash

while true
do
    echo "========== User and Group Management =========="
    echo "1. Create User"
    echo "2. Display Users"
    echo "3. Delete User"
    echo "4. Create Group"
    echo "5. Display Groups"
    echo "6. Delete Group"
    echo "7. Exit"
    echo -n "Enter your choice: "
    read choice

    case $choice in
        1)  # Create User
            echo -n "Enter username to create: "
            read username
            sudo useradd $username && echo "User '$username' created." || echo "Error creating user '$username'."
            ;;
        2)  # Display Users
            echo "All Users:"
            cut -d':' -f1 /etc/passwd
            ;;
        3)  # Delete User
            echo -n "Enter username to delete: "
            read username
            sudo userdel $username && echo "User '$username' deleted." || echo "Error deleting user '$username'."
            ;;
        4)  # Create Group
            echo -n "Enter group name to create: "
            read groupname
            sudo groupadd $groupname && echo "Group '$groupname' created." || echo "Error creating group '$groupname'."
            ;;
        5)  # Display Groups
            echo "All Groups:"
            cut -d':' -f1 /etc/group
            ;;
        6)  # Delete Group
            echo -n "Enter group name to delete: "
            read groupname
            sudo groupdel $groupname && echo "Group '$groupname' deleted." || echo "Error deleting group '$groupname'."
            ;;
        7)  # Exit
            echo "Goodbye!"
            exit
            ;;
        *)  # Invalid Option
            echo "Invalid choice. Try again."
            ;;
    esac
done
