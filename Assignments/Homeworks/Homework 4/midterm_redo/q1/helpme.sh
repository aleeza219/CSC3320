#Name: Aleeza Iftikhar
#Email: aiftikhar2@student.gsu.edu
#Program: To display user manual of entered commands

readFrom="mandatabase.txt" #txt file contains 10 commands
echo -n "Enter a command: "
read userInput
userInput=$(echo "$userInput" | tr a-z A-Z)
declare line_no=($(sed -n "/$userInput(1)/=" $readFrom))

if [ ${#line_no[@]} -eq 2 ] #check and store line no. if command is found in txt file
then
sed -n "${line_no[0]},${line_no[1]} p" $readFrom #print user manual for that command
else
echo "Sorry, I can't help you" #if command not found in txt file
fi
