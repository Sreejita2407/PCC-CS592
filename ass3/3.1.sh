#!/bin/bash

show_permissions() {
path=$1
if [ -e "$path" ]; then
permissions=$(stat -c %a "$path")
echo "Permissions of '$path': $permissions"
else
echo "'$path' not found."
fi
}

count_files_and_directories() {
path=$1
if [ -d "$path" ]; then
files_count=$(find "$path" -type f | wc -l)
directories_count=$(find "$path" -type d | wc -l)
echo "Files count: $files_count"
echo "Directories count: $directories_count"
else
echo "'$path' not found."
fi
}

show_last_modification_time() {
path=$1
if [ -e "$path" ]; then
modification_time=$(stat -c %Y "$path")
formatted_time=$(date -d @"$modification_time" "+%Y-%m-%d %H:%M:%S")
echo "Last modification time of '$path': $formatted_time"
else
echo "'$path' not found."
fi
}

while true; do
echo ""
echo "Menu:"
echo "1. Show permissions of a file or directory"
echo "2. Show number of files and directories under current directory"
echo "3. Show last modification time of a file in current directory"
echo "4. Exit"

read -p "Enter your choice (1/2/3/4): " choice

case $choice in
1)
read -p "Enter file or directory path: " path
show_permissions "$path"
;;
2)
path=$(pwd)
count_files_and_directories "$path"
;;
3)
read -p "Enter file path: " path
show_last_modification_time "$path"
;;
4)
echo "Exiting the menu."
break
;;
*)
echo "Invalid choice. Please choose again."
;;
esac
done
