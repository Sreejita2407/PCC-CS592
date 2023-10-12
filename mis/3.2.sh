#!/bin/bash

data_file="personal_details.txt"

while true; do
echo "Menu:"
echo "1) Accept personal details and password"
echo "2) Display personal details"
echo "3) Exit"
read -p "Enter your choice (1/2/3): " choice

case $choice in
1)
read -p "Enter your name: " name
read -p "Enter your email: " email
read -s -p "Enter your password: " password
echo "$name:$email:$password" > "$data_file"
echo "Personal details and password stored."
;;
2)
if [[ -f "$data_file" ]]; then
read -s -p "Enter your password to display details: " input_password
stored_password=$(awk -F':' '{print $3}' "$data_file")
if [[ "$input_password" == "$stored_password" ]]; then
echo "Personal Details:"
cat "$data_file" | awk -F':' '{print "Name:", $1; print "Email:", $2}'
else
echo "Incorrect password. Access denied."
fi
else
echo "No personal details stored yet."
fi
;;
3)
echo "Exiting."
exit 0
;;
*)
echo "Invalid choice. Please select again."
;;
esac
done
