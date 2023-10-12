#!/bin/bash

students_file="Students_one.dat"
sorted_file="Sorted_one.dat"

while true; do
    clear
    echo "Menu:"
    echo "1. Sort records by Roll number (reverse order) and save to $sorted_file"
    echo "2. Replace lowercase letters with uppercase in $sorted_file"
    echo "3. Find unique name records in $sorted_file and append to $students_file"
    echo "4. Display 2nd and 3rd lines from $students_file"
    echo "5. Exit"
    read -p "Enter your choice: " choice

    case $choice in
        1)
            sort -t '|' -k 2 -r "$students_file" > "$sorted_file"
            echo "Records sorted by Roll number in reverse order and saved to $sorted_file"
            read -p "Press Enter to continue..."
            ;;
        2)
            sed -i 's/[a-z]/\U&/g' "$sorted_file"
            echo "Lowercase letters replaced with uppercase in $sorted_file"
            read -p "Press Enter to continue..."
            ;;
        3)
            awk -F '|' '!seen[$1]++' "$sorted_file" >> "$students_file"
            echo "Unique name records appended to $students_file"
            read -p "Press Enter to continue..."
            ;;
        4)
            awk 'NR==2,NR==3' "$students_file"
            read -p "Press Enter to continue..."
            ;;
        5)
            echo "Exit!"
            exit 0
            ;;
        *)
            echo "Invalid choice. Please enter a valid option."
            read -p "Press Enter to continue..."
            ;;
    esac
done
