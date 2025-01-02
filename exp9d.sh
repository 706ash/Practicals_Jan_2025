#!/bin/bash

while true
do
    echo "========== File Operations =========="
    echo "1. Create a File"
    echo "2. Insert Data into a File"
    echo "3. Rename a File"
    echo "4. Display File Contents"
    echo "5. Delete a File"
    echo "6. Exit"
    echo -n "Enter your choice: "
    read choice

    case $choice in
        1)  # Create a File
            echo -n "Enter the file name to create: "
            read filename
            if [ -f "$filename" ]; then
                echo "File '$filename' already exists."
            else
                touch "$filename"
                echo "File '$filename' created successfully."
            fi
            ;;
        2)  # Insert Data into a File
            echo -n "Enter the file name to insert data into: "
            read filename
            if [ -f "$filename" ]; then
                echo "Enter the data (Ctrl+D to stop):"
                cat >> "$filename"
                echo "Data inserted into '$filename'."
            else
                echo "File '$filename' does not exist."
            fi
            ;;
        3)  # Rename a File
            echo -n "Enter the current file name: "
            read oldfile
            echo -n "Enter the new file name: "
            read newfile
            if [ -f "$oldfile" ]; then
                mv "$oldfile" "$newfile"
                echo "File renamed to '$newfile'."
            else
                echo "File '$oldfile' does not exist."
            fi
            ;;
        4)  # Display File Contents
            echo -n "Enter the file name to display: "
            read filename
            if [ -f "$filename" ]; then
                echo "Contents of '$filename':"
                cat "$filename"
            else
                echo "File '$filename' does not exist."
            fi
            ;;
        5)  # Delete a File
            echo -n "Enter the file name to delete: "
            read filename
            if [ -f "$filename" ]; then
                rm -f "$filename"
                echo "File '$filename' deleted."
            else
                echo "File '$filename' does not exist."
            fi
            ;;
        6)  # Exit
            echo "Goodbye!"
            exit
            ;;
        *)  # Invalid Option
            echo "Invalid option. Please try again."
            ;;
    esac
done
