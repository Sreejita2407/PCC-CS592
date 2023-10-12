is_valid_username() {
	local username="$1"
local pattern="^[a-zA-Z][a-zA-Z0-9_]*$"
if [[ "$username" =~ $pattern ]]; then
	echo " Valid user name: $username"
else
	echo " Invalid user name: $username"
	echo " A valid user name meet the following criteria:"
	echo "- start with a letter"
	echo "- consist of only letters,digits, and underscores"
fi
}
echo -n "Enter a user name: "
read input_username

is_valid_username "$input_username"


